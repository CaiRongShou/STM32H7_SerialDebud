#include "bsp_init.h"



/*属性为Normal，cache的属性为 write-back，即仅更新cache，
 *在合适的时候(由cache策略决定或者软件强制更新)将数据更新到相应的SRAM空间
 *特别注意：如果要数据立即更新，写之后要SCB_CleanDCache，读数据时要SCB_InvalidateDCache
 */
#define MPU_Normal_WB        0x00


/*属性为Normal，cache的属性为 write-back，即仅更新cache，
 *在合适的时候(由cache策略决定或者软件强制更新)将数据更新到相应的SRAM空间
 *特别注意：如果要数据立即更新，写之后要SCB_CleanDCache，读数据时要SCB_InvalidateDCache
 */
#define MPU_Normal_WBWARA    0x01  //外部和内部写入无写入分配


/*属性为 normal，cache的属性为 Write-through，即更新cache的同时，
 *将数据同时写入相应的物理地址空间
 *特别注意：如果要数据立即更新，可以直接往内存写数据，但读数据时要SCB_InvalidateDCache
 */
#define MPU_Normal_WT         0x02


/*属性为 normal，禁用共享,禁用缓存
 */
#define MPU_Normal_NonCache   0x03


/*属性为 Device，共享设置无效，禁用共享,禁用缓存
 */
#define MPU_Device_NonCache   0x04

/**
  * @brief  配置MPU区域属性和大小寄存器值
    * @param  Region            MPU保护区域，取值范围（0—7）
    * @param  AccessPermission  数据访问权限，取值范围（MPU_NO_ACCESS—MPU_PRIV_RO_URO）
    * @param  TypeExtField      用于配置 Cache 策略，可以取值（0，1，2），一般只用0和1
    *
  * @param  Address             MPU保护区域基地址，特别注意配置的Address需要被Size整除
  * @param  Size                MPU保护区域大小,可以取值（MPU_1KB，MPU_4KB ...MPU_512MB）
    * @param  IsShareable       保护的存储空间是否可以共享，1=允许共享，0=禁止共享。
  * @param  IsCacheable         保护的存储空间是否可以缓存，1=允许缓存，0=禁止缓存。
  * @param  IsBufferable        使能Cache之后，策略是write-through还是write-back(bufferable)
    *                           1=允许缓冲，即回写（write-back），0=禁止缓冲，即直写（write-through）。
  * @retval None
  */
static void BSP_MPU_ConfigRegion(uint8_t    Number,
                                 uint8_t    TypeExtField,
                                 uint32_t   Address,
                                 uint32_t   Size,
                                 uint8_t    IsBufferable,
                                 uint8_t    IsCacheable)
{
    MPU_Region_InitTypeDef MPU_InitStruct;

    /* 禁用MPU */
    HAL_MPU_Disable();

    /* 配置MPU属性*/
    MPU_InitStruct.Enable = MPU_REGION_ENABLE;
    MPU_InitStruct.BaseAddress = Address;                      //区域基地址。
    MPU_InitStruct.Size = Size;                                //要配置的区域的区域大小。
    MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;  //数据访问权限允许您配置用户和特权模式的读/写访问权限。
    MPU_InitStruct.IsBufferable = IsBufferable;                //区域是可缓冲的，即使用回写缓存。 可缓存但不可缓冲的区域使用直写策略。WB
    MPU_InitStruct.IsCacheable = IsCacheable;                  //区域是否可缓存的，即其值是否可以保存在缓存中。//M7 内核只要开启了 Cache，read allocate 就是开启的
    MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;     //区域是否可以在多个总线主控器之间共享。H7 的应用笔记对齐的描述是开启共享基本等同于关闭 Cache
    MPU_InitStruct.Number = Number;                            //区域号。
    MPU_InitStruct.TypeExtField = TypeExtField;                //键入扩展字段，允许您配置内存访问类型。
    MPU_InitStruct.SubRegionDisable = 0x00;                    //子区域禁用字段。
    MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;//指令访问禁用位，0=允许指令访问，1=禁止指令访问

    HAL_MPU_ConfigRegion(&MPU_InitStruct);
    /* 启用MPU */
    HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT); //表示禁止了背景区，访问任何未使能 MPU 的区域均会造成内存异常 MemFault


}

static void cpu_mpu_config(uint8_t Region, uint8_t Mode, uint32_t Address, uint32_t Size)
{
    switch (Mode)
    {
    case MPU_Normal_WB:
        /*write back,no write allocate */
        /* 设置内存为Normal类型,禁用共享, 回写模式不带写入读取分配*/
        BSP_MPU_ConfigRegion(Region, MPU_TEX_LEVEL0, Address, Size, MPU_ACCESS_BUFFERABLE, MPU_ACCESS_CACHEABLE);
        break;

    case MPU_Normal_WBWARA:
        /*write back,write and read allocate */
        /* 设置内存为Normal类型,禁用共享, 回写模式带写入读取分配*/
        BSP_MPU_ConfigRegion(Region, MPU_TEX_LEVEL1, Address, Size, MPU_ACCESS_BUFFERABLE, MPU_ACCESS_CACHEABLE);
        break;

    case MPU_Normal_WT:
        /*write through,no write allocate */
        /* 设置内存为Normal类型,禁用共享, 直写模式*/
        BSP_MPU_ConfigRegion(Region, MPU_TEX_LEVEL0, Address, Size, MPU_ACCESS_NOT_BUFFERABLE, MPU_ACCESS_CACHEABLE);
        break;

    case MPU_Normal_NonCache:
        /* 设置内存为Normal类型,禁用共享，禁用缓存模式*/
        BSP_MPU_ConfigRegion(Region, MPU_TEX_LEVEL1, Address, Size, MPU_ACCESS_NOT_BUFFERABLE, MPU_ACCESS_NOT_CACHEABLE);
        break;
    }
}

/**
* @brief  CPU L1-Cache enable.
* @param  None
* @retval None
*/
static void CPU_CACHE_Enable(void)
{
    /* Enable I-Cache */
    SCB_EnableICache();
    /* Enable D-Cache */
    SCB_EnableDCache();
}



/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /** Supply configuration update enable
    */
    HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

    /** Configure the main internal regulator output voltage
    */
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

    /** Configure LSE Drive Capability
    */
    HAL_PWR_EnableBkUpAccess();
    __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

    /** Initializes the RCC Oscillators according to the specified parameters
    * in the RCC_OscInitTypeDef structure.
    */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.LSEState = RCC_LSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 5;
    RCC_OscInitStruct.PLL.PLLN = 160;
    RCC_OscInitStruct.PLL.PLLP = 2;
    RCC_OscInitStruct.PLL.PLLQ = 8;
    RCC_OscInitStruct.PLL.PLLR = 8;
    RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
    RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
    RCC_OscInitStruct.PLL.PLLFRACN = 0;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        //Error_Handler();
    }

    /** Initializes the CPU, AHB and APB buses clocks
    */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                                  |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                                  |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
    RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
    {
        //Error_Handler();
    }
}

/**
  * @brief Peripherals Common Clock Configuration
  * @retval None
  */
void PeriphCommonClock_Config(void)
{
    RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

    /** Initializes the peripherals clock
    */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USB|RCC_PERIPHCLK_ADC
            |RCC_PERIPHCLK_SDMMC|RCC_PERIPHCLK_SPI1;
    PeriphClkInitStruct.PLL2.PLL2M = 5;
    PeriphClkInitStruct.PLL2.PLL2N = 120;
    PeriphClkInitStruct.PLL2.PLL2P = 10;
    PeriphClkInitStruct.PLL2.PLL2Q = 8;
    PeriphClkInitStruct.PLL2.PLL2R = 6;
    PeriphClkInitStruct.PLL2.PLL2RGE = RCC_PLL2VCIRANGE_2;
    PeriphClkInitStruct.PLL2.PLL2VCOSEL = RCC_PLL2VCOWIDE;
    PeriphClkInitStruct.PLL2.PLL2FRACN = 0;
    PeriphClkInitStruct.PLL3.PLL3M = 5;
    PeriphClkInitStruct.PLL3.PLL3N = 96;
    PeriphClkInitStruct.PLL3.PLL3P = 4;
    PeriphClkInitStruct.PLL3.PLL3Q = 10;
    PeriphClkInitStruct.PLL3.PLL3R = 4;
    PeriphClkInitStruct.PLL3.PLL3RGE = RCC_PLL3VCIRANGE_2;
    PeriphClkInitStruct.PLL3.PLL3VCOSEL = RCC_PLL3VCOWIDE;
    PeriphClkInitStruct.PLL3.PLL3FRACN = 0;
    PeriphClkInitStruct.SdmmcClockSelection = RCC_SDMMCCLKSOURCE_PLL2;
    PeriphClkInitStruct.Spi123ClockSelection = RCC_SPI123CLKSOURCE_PLL3;
    PeriphClkInitStruct.UsbClockSelection = RCC_USBCLKSOURCE_PLL3;
    PeriphClkInitStruct.AdcClockSelection = RCC_ADCCLKSOURCE_PLL2;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
        //Error_Handler();
    }
}



void pwr_gpio_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	
    HAL_GPIO_WritePin(GPIOB, PWR_ON_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_8,GPIO_PIN_RESET);

    GPIO_InitStruct.Pin = PWR_ON_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	 GPIO_InitStruct.Pin = GPIO_PIN_8;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

void bsp_init(void)
{
#ifdef DEBUG_FLAG
    SCB->VTOR = 0x08020000;
#endif
	/*内存设置*/
    cpu_mpu_config(0, MPU_Normal_WT, 0x24000000, MPU_REGION_SIZE_512KB);
    cpu_mpu_config(1, MPU_Normal_WT,       0x30000000, MPU_REGION_SIZE_128KB);
    cpu_mpu_config(2, MPU_Normal_NonCache, 0x24080000-0x800, MPU_REGION_SIZE_64KB);
	/*开启cache*/
    CPU_CACHE_Enable();

    HAL_Init();//tick初始化

    SystemClock_Config(); //系统时钟初始化

    PeriphCommonClock_Config(); //外设时钟初始化

    cdc_acm_init(0, USB_OTG_FS_PERIPH_BASE);//USB初始化

    pwr_gpio_init(); 

    wifi_gpio_init();

    bsp_w25qxx_Init();

    sw_gpio_init();

    ft6336u_init();//触摸初始化

    lcd_init();//lcd显示屏初始化

    sd_init();

	/*串口外设初始化*/
    MX_USART1_UART_Init();
    MX_USART3_UART_Init();
    MX_USART6_UART_Init();

    MX_ADC2_Init();

    MX_RTC_Init();
}


/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1)
    {
    }
    /* USER CODE END Error_Handler_Debug */
}
