#include "bsp_lcd.h"
#include "lvgl.h"


SPI_HandleTypeDef hspi1;
DMA_HandleTypeDef hdma_spi1_tx;

void lcd_gpio_init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  HAL_GPIO_WritePin(GPIOC, LCD_RST_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOA, LCD_CS_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOB, LCD_BL_Pin, GPIO_PIN_RESET);

  GPIO_InitStruct.Pin = LCD_RST_Pin|LCD_DC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LCD_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LCD_BL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}


void MX_LCD_SPI1_Init(void)
{
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_1LINE;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspi1.Init.CLKPhase = SPI_PHASE_2EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 0x0;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
  hspi1.Init.NSSPolarity = SPI_NSS_POLARITY_LOW;
  hspi1.Init.FifoThreshold = SPI_FIFO_THRESHOLD_01DATA;
  hspi1.Init.TxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
  hspi1.Init.RxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
  hspi1.Init.MasterSSIdleness = SPI_MASTER_SS_IDLENESS_00CYCLE;
  hspi1.Init.MasterInterDataIdleness = SPI_MASTER_INTERDATA_IDLENESS_00CYCLE;
  hspi1.Init.MasterReceiverAutoSusp = SPI_MASTER_RX_AUTOSUSP_DISABLE;
  hspi1.Init.MasterKeepIOState = SPI_MASTER_KEEP_IO_STATE_ENABLE;
  hspi1.Init.IOSwap = SPI_IO_SWAP_DISABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    
  }
}



void HAL_SPI_MspInit(SPI_HandleTypeDef* spiHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(spiHandle->Instance==SPI1)
  {
  /* USER CODE BEGIN SPI1_MspInit 0 */

  /* USER CODE END SPI1_MspInit 0 */
    /* SPI1 clock enable */
    __HAL_RCC_SPI1_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
    /**SPI1 GPIO Configuration
    PA5     ------> SPI1_SCK
    PA7     ------> SPI1_MOSI
    */
    GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* SPI1 DMA Init */
    /* SPI1_TX Init */
    hdma_spi1_tx.Instance = DMA1_Stream0;
    hdma_spi1_tx.Init.Request = DMA_REQUEST_SPI1_TX;
    hdma_spi1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_spi1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_spi1_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_spi1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
    hdma_spi1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
    hdma_spi1_tx.Init.Mode = DMA_NORMAL;
    hdma_spi1_tx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_spi1_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_spi1_tx) != HAL_OK)
    {
      //Error_Handler();
    }

    __HAL_LINKDMA(spiHandle,hdmatx,hdma_spi1_tx);

    /* SPI1 interrupt Init */
    HAL_NVIC_SetPriority(SPI1_IRQn, 12, 0);
    HAL_NVIC_EnableIRQ(SPI1_IRQn);

	
  /* USER CODE BEGIN SPI1_MspInit 1 */

  /* USER CODE END SPI1_MspInit 1 */
  }
}

void HAL_SPI_MspDeInit(SPI_HandleTypeDef* spiHandle)
{

  if(spiHandle->Instance==SPI1)
  {
  /* USER CODE BEGIN SPI1_MspDeInit 0 */

  /* USER CODE END SPI1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_SPI1_CLK_DISABLE();

    /**SPI1 GPIO Configuration
    PA5     ------> SPI1_SCK
    PA7     ------> SPI1_MOSI
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_5|GPIO_PIN_7);

    /* SPI1 DMA DeInit */
    HAL_DMA_DeInit(spiHandle->hdmatx);

    /* SPI1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(SPI1_IRQn);
  /* USER CODE BEGIN SPI1_MspDeInit 1 */

  /* USER CODE END SPI1_MspDeInit 1 */
  }
}

void MX_LCD_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Stream0_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream0_IRQn, 12, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream0_IRQn);

}

//LCD的画笔颜色和背景色
u16 POINT_COLOR=0x0000;	//画笔颜色
u16 BACK_COLOR=0xFFFF;  //背景色


void LCD_Writ_Bus(u8 dat) 
{	
	
    SPI_CS(0);// = 0;
	
	#ifdef SPI_SOFTWARE 
	u8 i;

    for(i=0; i<8; i++)
	{
		if (dat & 0x80)
		 SPI_SDI(1);// = 1;
		else
		 SPI_SDI(0);// = 0;
		
		dat <<= 1;		 
		SPI_SCK(0);// = 0;		  
		SPI_SCK(1);// = 1;
	}
	#else
	HAL_SPI_Transmit(&hspi1, &dat, 1, 10); 
	#endif
    SPI_CS(1);//=1;
}


/******************************************************************************
      函数说明：LCD写入数据
      入口数据：dat 写入的数据
      返回值：  无
******************************************************************************/
void LCD_WR_DATA8(u8 dat)
{
	LCD_Writ_Bus(dat);
}


/******************************************************************************
      函数说明：LCD写入数据
      入口数据：dat 写入的数据
      返回值：  无
******************************************************************************/
void LCD_WR_DATA(u16 dat)
{
	LCD_Writ_Bus(dat>>8);
	LCD_Writ_Bus(dat);
}


/******************************************************************************
      函数说明：LCD写入命令
      入口数据：dat 写入的命令
      返回值：  无
******************************************************************************/
void LCD_WR_REG(u8 dat)
{
	SPI_DC(0);//写命令
	LCD_Writ_Bus(dat);
	SPI_DC(1);//写数据
}


/******************************************************************************
      函数说明：设置起始和结束地址
      入口数据：x1,x2 设置列的起始和结束地址
                y1,y2 设置行的起始和结束地址
      返回值：  无
******************************************************************************/
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2)
{
		LCD_WR_REG(0x2a);//列地址设置
		LCD_WR_DATA(x1);
		LCD_WR_DATA(x2);
		LCD_WR_REG(0x2b);//行地址设置
		LCD_WR_DATA(y1);
		LCD_WR_DATA(y2);
		LCD_WR_REG(0x2c);//储存器写
}


//初始化lcd
void lcd_init(void)
{
	MX_LCD_DMA_Init();
	
	lcd_gpio_init();
	
	MX_LCD_SPI1_Init();
	
	
	
    SPI_RST(1);
    delay_ms(1);
    SPI_RST(0);
    delay_ms(10);
    SPI_RST(1);
    delay_ms(10);

//************* Start Initial Sequence **********//
	LCD_WR_REG(0x11); //Sleep out 
	delay_ms(120);    //Delay 120ms 
	//************* Start Initial Sequence **********// 
	LCD_WR_REG(0Xf0);
	LCD_WR_DATA8(0xc3);
	LCD_WR_REG(0Xf0);
	LCD_WR_DATA8(0x96);
	LCD_WR_REG(0x36);    // Memory Access Control 
	if(USE_HORIZONTAL==0)LCD_WR_DATA8(0x48);
	else if(USE_HORIZONTAL==1)LCD_WR_DATA8(0x88);
	else if(USE_HORIZONTAL==2)LCD_WR_DATA8(0x28);
	else LCD_WR_DATA8(0xE8);
	
	LCD_WR_REG(0x3A);
	LCD_WR_DATA8(0x05);
	
	LCD_WR_REG(0Xe8);
	LCD_WR_DATA8(0x40);
	LCD_WR_DATA8(0x82);
	LCD_WR_DATA8(0x07);
	LCD_WR_DATA8(0x18);
	LCD_WR_DATA8(0x27);
	LCD_WR_DATA8(0x0a);
	LCD_WR_DATA8(0xb6);
	LCD_WR_DATA8(0x33);
	
	LCD_WR_REG(0Xc5);
	LCD_WR_DATA8(0x27);
	
	LCD_WR_REG(0Xc6);
	LCD_WR_DATA8(0x1f);
	
	LCD_WR_REG(0Xc2);
	LCD_WR_DATA8(0xa7);
	
	LCD_WR_REG(0Xe0);
	LCD_WR_DATA8(0xf0);
	LCD_WR_DATA8(0x01);
	LCD_WR_DATA8(0x06);
	LCD_WR_DATA8(0x0f);
	LCD_WR_DATA8(0x12);
	LCD_WR_DATA8(0x1d);
	LCD_WR_DATA8(0x36);
	LCD_WR_DATA8(0x54);
	LCD_WR_DATA8(0x44);
	LCD_WR_DATA8(0x0c);
	LCD_WR_DATA8(0x18);
	LCD_WR_DATA8(0x16);
	LCD_WR_DATA8(0x13);
	LCD_WR_DATA8(0x15);
	
	LCD_WR_REG(0Xe1);
	LCD_WR_DATA8(0xf0);
	LCD_WR_DATA8(0x01);
	LCD_WR_DATA8(0x05);
	LCD_WR_DATA8(0x0a);
	LCD_WR_DATA8(0x0b);
	LCD_WR_DATA8(0x07);
	LCD_WR_DATA8(0x32);
	LCD_WR_DATA8(0x44);
	LCD_WR_DATA8(0x44);
	LCD_WR_DATA8(0x0c);
	LCD_WR_DATA8(0x18);
	LCD_WR_DATA8(0x17);
	LCD_WR_DATA8(0x13);
	LCD_WR_DATA8(0x16);
	
	LCD_WR_REG(0Xf0);
	LCD_WR_DATA8(0x3c);
	
	LCD_WR_REG(0Xf0);
	LCD_WR_DATA8(0x69);
	LCD_WR_REG(0x21); //控制反转颜色
	LCD_WR_REG(0X29);
	
}


void lvgl_dma_config(uint8_t *buffer, uint16_t size)
{
	HAL_SPI_Transmit_DMA(&hspi1, buffer, size);
}
/******************************************************************************
      函数说明：在指定区域填充颜色
      入口数据：xsta,ysta   起始坐标
                xend,yend   终止坐标
                color       要填充的颜色
      返回值：  无
******************************************************************************/
//extern DMA_HandleTypeDef hdma_spi1_tx;

/******************************************************************************
      函数说明：在指定区域填充颜色
      入口数据：xsta,ysta   起始坐标
                xend,yend   终止坐标
								color       要填充的颜色
      返回值：  无
******************************************************************************/

void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color)
{          
	u16 i,j; 
	LCD_Address_Set(xsta,ysta,xend-1,yend-1);//设置显示范围
	for(i=ysta;i<yend;i++)
	{													   	 	
		for(j=xsta;j<xend;j++)
		{
			LCD_WR_DATA(color);
		}
	} 					  	    
}

//void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color) //DMA  内存地址需要设置不递增
//{          
//	u16 color1[1],t=1;
//	u32 num,num1;
//	color1[0]=color;
//	num=(xend-xsta)*(yend-ysta);
//	 // 设置指定区域
//    LCD_Address_Set(xsta, ysta, xend, yend);
//	
//	
//    // 设置SPI数据大小为16位
//    hspi1.Init.DataSize = SPI_DATASIZE_16BIT;
//    HAL_SPI_Init(&hspi1);  // 重新初始化SPI以应用新的数据大小
//    SPI_CS(0);
//	while(t)
//	{
//		if(num>65534)
//		{
//			num-=65534;
//			num1=65534;
//		}
//		else
//		{
//			t=0;
//			num1=num;
//		}
////		// 使用DMA传输数据
//    HAL_SPI_Transmit_DMA(&hspi1,&color, num1);
//	while(__HAL_DMA_GET_COUNTER(&hdma_spi1_tx)!=0);
//		delay_us(10);
//  }
//	// 等待DMA传输完成
//    
//    SPI_CS(1);
//    // 恢复SPI数据大小为8位
//    hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
//    HAL_SPI_Init(&hspi1);  // 重新初始化SPI以应用新的数据大小
//}

/******************************************************************************
      函数说明：在指定区域填充颜色
      入口数据：xsta,ysta   起始坐标
                xend,yend   终止坐标
                color       要填充的颜色
      返回值：  无
******************************************************************************/
void LVGL_Color_Fill(uint16_t xsta, uint16_t ysta, uint16_t xend, uint16_t yend, uint16_t *color_p)
{
    uint16_t width, height;
    width = xend - xsta + 1;
    height = yend - ysta + 1;
    uint32_t size = width * height ;  // 数据总长度（字节数）

    // 设置指定区域
    LCD_Address_Set(xsta, ysta, xend, yend);
	
	
    // 设置SPI数据大小为16位
    hspi1.Init.DataSize = SPI_DATASIZE_16BIT;
    HAL_SPI_Init(&hspi1);  // 重新初始化SPI以应用新的数据大小
    SPI_CS(0);
    // 使用DMA传输数据
    HAL_SPI_Transmit_DMA(&hspi1,(uint8_t *)color_p, size);

}
extern lv_disp_drv_t *disp_drv1;
void LV_ATTRIBUTE_FLUSH_READY lv_disp_flush_ready(lv_disp_drv_t * disp_drv);

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
	lv_disp_flush_ready(disp_drv1);
	
	SPI_CS(1);
	 /* SPIx CFG1 Configuration */
  
	hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
    HAL_SPI_Init(&hspi1);  // 重新初始化SPI以应用新的数据大小
}



