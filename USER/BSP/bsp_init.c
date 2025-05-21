#include "bsp_init.h"



/*����ΪNormal��cache������Ϊ write-back����������cache��
 *�ں��ʵ�ʱ��(��cache���Ծ����������ǿ�Ƹ���)�����ݸ��µ���Ӧ��SRAM�ռ�
 *�ر�ע�⣺���Ҫ�����������£�д֮��ҪSCB_CleanDCache��������ʱҪSCB_InvalidateDCache
 */
#define MPU_Normal_WB        0x00


/*����ΪNormal��cache������Ϊ write-back����������cache��
 *�ں��ʵ�ʱ��(��cache���Ծ����������ǿ�Ƹ���)�����ݸ��µ���Ӧ��SRAM�ռ�
 *�ر�ע�⣺���Ҫ�����������£�д֮��ҪSCB_CleanDCache��������ʱҪSCB_InvalidateDCache
 */
#define MPU_Normal_WBWARA    0x01  //�ⲿ���ڲ�д����д�����


/*����Ϊ normal��cache������Ϊ Write-through��������cache��ͬʱ��
 *������ͬʱд����Ӧ�������ַ�ռ�
 *�ر�ע�⣺���Ҫ�����������£�����ֱ�����ڴ�д���ݣ���������ʱҪSCB_InvalidateDCache
 */
#define MPU_Normal_WT         0x02


/*����Ϊ normal�����ù���,���û���
 */
#define MPU_Normal_NonCache   0x03


/*����Ϊ Device������������Ч�����ù���,���û���
 */
#define MPU_Device_NonCache   0x04

/**
  * @brief  ����MPU�������Ժʹ�С�Ĵ���ֵ
    * @param  Region            MPU��������ȡֵ��Χ��0��7��
    * @param  AccessPermission  ���ݷ���Ȩ�ޣ�ȡֵ��Χ��MPU_NO_ACCESS��MPU_PRIV_RO_URO��
    * @param  TypeExtField      �������� Cache ���ԣ�����ȡֵ��0��1��2����һ��ֻ��0��1
    *
  * @param  Address             MPU�����������ַ���ر�ע�����õ�Address��Ҫ��Size����
  * @param  Size                MPU���������С,����ȡֵ��MPU_1KB��MPU_4KB ...MPU_512MB��
    * @param  IsShareable       �����Ĵ洢�ռ��Ƿ���Թ���1=������0=��ֹ����
  * @param  IsCacheable         �����Ĵ洢�ռ��Ƿ���Ի��棬1=�����棬0=��ֹ���档
  * @param  IsBufferable        ʹ��Cache֮�󣬲�����write-through����write-back(bufferable)
    *                           1=�����壬����д��write-back����0=��ֹ���壬��ֱд��write-through����
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

    /* ����MPU */
    HAL_MPU_Disable();

    /* ����MPU����*/
    MPU_InitStruct.Enable = MPU_REGION_ENABLE;
    MPU_InitStruct.BaseAddress = Address;                      //�������ַ��
    MPU_InitStruct.Size = Size;                                //Ҫ���õ�����������С��
    MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;  //���ݷ���Ȩ�������������û�����Ȩģʽ�Ķ�/д����Ȩ�ޡ�
    MPU_InitStruct.IsBufferable = IsBufferable;                //�����ǿɻ���ģ���ʹ�û�д���档 �ɻ��浫���ɻ��������ʹ��ֱд���ԡ�WB
    MPU_InitStruct.IsCacheable = IsCacheable;                  //�����Ƿ�ɻ���ģ�����ֵ�Ƿ���Ա����ڻ����С�//M7 �ں�ֻҪ������ Cache��read allocate ���ǿ�����
    MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;     //�����Ƿ�����ڶ������������֮�乲��H7 ��Ӧ�ñʼǶ���������ǿ������������ͬ�ڹر� Cache
    MPU_InitStruct.Number = Number;                            //����š�
    MPU_InitStruct.TypeExtField = TypeExtField;                //������չ�ֶΣ������������ڴ�������͡�
    MPU_InitStruct.SubRegionDisable = 0x00;                    //����������ֶΡ�
    MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;//ָ����ʽ���λ��0=����ָ����ʣ�1=��ָֹ�����

    HAL_MPU_ConfigRegion(&MPU_InitStruct);
    /* ����MPU */
    HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT); //��ʾ��ֹ�˱������������κ�δʹ�� MPU �������������ڴ��쳣 MemFault


}

static void cpu_mpu_config(uint8_t Region, uint8_t Mode, uint32_t Address, uint32_t Size)
{
    switch (Mode)
    {
    case MPU_Normal_WB:
        /*write back,no write allocate */
        /* �����ڴ�ΪNormal����,���ù���, ��дģʽ����д���ȡ����*/
        BSP_MPU_ConfigRegion(Region, MPU_TEX_LEVEL0, Address, Size, MPU_ACCESS_BUFFERABLE, MPU_ACCESS_CACHEABLE);
        break;

    case MPU_Normal_WBWARA:
        /*write back,write and read allocate */
        /* �����ڴ�ΪNormal����,���ù���, ��дģʽ��д���ȡ����*/
        BSP_MPU_ConfigRegion(Region, MPU_TEX_LEVEL1, Address, Size, MPU_ACCESS_BUFFERABLE, MPU_ACCESS_CACHEABLE);
        break;

    case MPU_Normal_WT:
        /*write through,no write allocate */
        /* �����ڴ�ΪNormal����,���ù���, ֱдģʽ*/
        BSP_MPU_ConfigRegion(Region, MPU_TEX_LEVEL0, Address, Size, MPU_ACCESS_NOT_BUFFERABLE, MPU_ACCESS_CACHEABLE);
        break;

    case MPU_Normal_NonCache:
        /* �����ڴ�ΪNormal����,���ù������û���ģʽ*/
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
	/*�ڴ�����*/
    cpu_mpu_config(0, MPU_Normal_WT, 0x24000000, MPU_REGION_SIZE_512KB);
    cpu_mpu_config(1, MPU_Normal_WT,       0x30000000, MPU_REGION_SIZE_128KB);
    cpu_mpu_config(2, MPU_Normal_NonCache, 0x24080000-0x800, MPU_REGION_SIZE_64KB);
	/*����cache*/
    CPU_CACHE_Enable();

    HAL_Init();//tick��ʼ��

    SystemClock_Config(); //ϵͳʱ�ӳ�ʼ��

    PeriphCommonClock_Config(); //����ʱ�ӳ�ʼ��

    cdc_acm_init(0, USB_OTG_FS_PERIPH_BASE);//USB��ʼ��

    pwr_gpio_init(); 

    wifi_gpio_init();

    bsp_w25qxx_Init();

    sw_gpio_init();

    ft6336u_init();//������ʼ��

    lcd_init();//lcd��ʾ����ʼ��

    sd_init();

	/*���������ʼ��*/
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
