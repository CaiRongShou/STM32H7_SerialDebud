#include "app_define.h"

#include "bsp_qspi_flash.h"
#include "bsp_sw.h"
#include "bsp_wifi.h"

#include "quadspi.h"
#include "bsp_rtc.h"
#define PARA_FLASH_AREA 0x90400000
#define FLASH_SAVE_ADDR	0x400000

static uint8_t setting_save_data(void);

const uint32_t serial_buad_tab[] = {
    1200, 2400, 4800, 9600, 14400, 19200, 38400, 
    57600, 115200, 128000, 230400, 256000, 460800, 500000, 
    512000, 600000, 750000, 921600, 1000000, 1500000, 2000000
};

ui_setting_t ui_set_data; //flag保存参数

//setting_event_flag_t setting_event_flag; //保存事件标志

uint8_t g_serial_sw; //通信协议 TTL 232 485
uint32_t g_uart3_baud; //波特率
uint8_t g_adaptive_port; //自适应波特率算法选择
uint8_t	g_adaptive_baud; //自适应波特率


extern EventGroupHandle_t eventgroup_handle;



void setting_data_init(void)
{
	memset(&ui_set_data,0,sizeof(ui_setting_t));
	
	bsp_w25qxx_Read(FLASH_SAVE_ADDR , (uint8_t *)&ui_set_data , sizeof(ui_setting_t));
	get_rtc_time(&rtcTime);
	
	if(ui_set_data.serial_baud > 21) //波特率索引
		ui_set_data.serial_baud = 8;
	g_uart3_baud = serial_buad_tab[ui_set_data.serial_baud];

	
	if(ui_set_data.adaptive_port > 3) //自适应波特率模式
		ui_set_data.adaptive_port = 0;
	g_adaptive_port = ui_set_data.adaptive_port;
	
	if(ui_set_data.adaptive_baud > 1) //自适应波特率开启/关闭
		ui_set_data.adaptive_baud = 0;
	g_adaptive_baud = ui_set_data.adaptive_baud;

	if(ui_set_data.serial_sw > 2) //通信协议
		ui_set_data.serial_sw = 0;
	g_serial_sw = ui_set_data.serial_sw;
	
	serial_sw_mode(g_serial_sw);
	
	if(ui_set_data.wifi_status > 1) //WiFi开启/关闭
		ui_set_data.wifi_status = 0;
	wifi_usb_event_status.wifi_en_status = ui_set_data.wifi_status;

	if(ui_set_data.ssid[0] == 0xFF) //WiFi名称
		memcpy(ui_set_data.ssid,ssid,32);
	memcpy(ssid,ui_set_data.ssid,32);
	
	if(ui_set_data.password[0] == 0xFF) //WiFi密码
		memcpy(ui_set_data.password,password,32);
	memcpy(password,ui_set_data.password,32);
}


extern osThreadId_t lvglTaskHandle;

uint8_t setting_save_data(void)
{
	volatile uint8_t ret = 0;
	vTaskSuspend(lvglTaskHandle);
	
	bsp_w25qxx_reload();
	
	ret = bsp_w25qxx_EraseSector(FLASH_SAVE_ADDR);
	
	ret = bsp_w25qxx_Write(FLASH_SAVE_ADDR , (uint8_t *)&ui_set_data , sizeof(ui_setting_t));

	ret = bsp_w25qxx_Read(FLASH_SAVE_ADDR , (uint8_t *)&ui_set_data , sizeof(ui_setting_t));
	
	ret = bsp_w25qxx_MemoryMapedEnter();
	vTaskResume(lvglTaskHandle);

	return ret;
}



void setting_pro(void)
{
	if(xEventGroupWaitBits(eventgroup_handle,SETTING_SAVE_EVENT,pdTRUE,pdTRUE,0) & SETTING_SAVE_EVENT)
	{
		
		setting_save_data();
		
		set_rtc_time(&rtcTime);

		g_uart3_baud = serial_buad_tab[ui_set_data.serial_baud];

		g_adaptive_port = ui_set_data.adaptive_port;
		
		g_adaptive_baud = ui_set_data.adaptive_baud;

		g_serial_sw = ui_set_data.serial_sw;
		serial_sw_mode(g_serial_sw);
		
		usart3_init();
	}

	if(xEventGroupWaitBits(eventgroup_handle,SETTING_WIFI_SAVE_EVENT,pdTRUE,pdTRUE,0) & SETTING_WIFI_SAVE_EVENT)
	{
		setting_save_data();
	}		
	
}


void usart3_init(void)
{
	if (HAL_UART_DeInit(&huart3) != HAL_OK)
	{
		Error_Handler();
	}
	
	huart3.Init.BaudRate = g_uart3_baud;
	if(g_adaptive_baud)
	{
		huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_AUTOBAUDRATE_INIT;
		huart3.AdvancedInit.AutoBaudRateEnable = UART_ADVFEATURE_AUTOBAUDRATE_ENABLE;
		switch(g_adaptive_port)
		{
			case 0:
				huart3.AdvancedInit.AutoBaudRateMode = UART_ADVFEATURE_AUTOBAUDRATE_ONSTARTBIT;
				break;
			case 1:
				huart3.AdvancedInit.AutoBaudRateMode = UART_ADVFEATURE_AUTOBAUDRATE_ONFALLINGEDGE;
				break;
			case 2:
				huart3.AdvancedInit.AutoBaudRateMode = UART_ADVFEATURE_AUTOBAUDRATE_ON0X7FFRAME;
				break;
			case 3:
				huart3.AdvancedInit.AutoBaudRateMode = UART_ADVFEATURE_AUTOBAUDRATE_ON0X55FRAME;
				break;
			default:
				huart3.AdvancedInit.AutoBaudRateMode = UART_ADVFEATURE_AUTOBAUDRATE_ONSTARTBIT;
				break;
		}
	}
	else
	{
		huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
		huart3.AdvancedInit.AutoBaudRateEnable = UART_ADVFEATURE_AUTOBAUDRATE_DISABLE;
	}
	if (HAL_UART_Init(&huart3) != HAL_OK)
	{
		Error_Handler();
	}
	if (HAL_UARTEx_SetTxFifoThreshold(&huart3, UART_TXFIFO_THRESHOLD_1_2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart3, UART_RXFIFO_THRESHOLD_1_2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_EnableFifoMode(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
	HAL_UART_Receive_IT(&huart3, &serial_data_event.data_temp,1);
}


