
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"


#include "bsp_sd.h"
#include "bsp_lcd.h"
#include "bsp_sw.h"
#include "bsp_qspi_flash.h"
#include "delay.h"
#include "bsp_usb_cdc_acm.h"
#include "bsp_wifi.h"

#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "gui_guider.h"
#include "events_init.h"

#include "usart.h"
#include "bsp_rtc.h"

#include "usbd_core.h"
#include "usbd_cdc.h"

#include "app_define.h"


void lvglTask(void *argument);
void transferTask(void *argument);
void userTask(void *argument);
void fileTask(void *argument);


#define START_TASK_PRIO	1
#define START_STK_SZIE	128
TaskHandle_t defaultTaskHandle;

#define USER_TASK_PRIO	4
#define USER_STACK_SIZE	1024
TaskHandle_t userTaskHandle;

#define LVGL_TASK_PRIO	2
#define LVGL_STACK_SIZE	1024
TaskHandle_t lvglTaskHandle;

#define TRANSFER_TASK_PRIO	3
#define TRANSFER_STACK_SIZE	1024
TaskHandle_t transferTaskHandle;

#define FILE_TASK_PRIO	3
#define FILE_STACK_SIZE	1024
TaskHandle_t fileTaskHandle;

SemaphoreHandle_t sendSemaphore;
SemaphoreHandle_t uiSemaphore;

EventGroupHandle_t eventgroup_handle;

lv_ui guider_ui;

int fputc(int ch, FILE *f)
{
	USART1->TDR = ch;
	
	/* µÈ´ý·¢ËÍ½áÊø */
	while((USART1->ISR & USART_ISR_TC) == 0)
	{}
	
	return ch;
}

void StartDefaultTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

__weak void PreSleepProcessing(uint32_t ulExpectedIdleTime)
{
    /* place for user code */
}

__weak void PostSleepProcessing(uint32_t ulExpectedIdleTime)
{
    /* place for user code */
}

void MX_FREERTOS_Init(void)
{
  /* USER CODE BEGIN Init */
	setting_data_init();
	delay_ms(100);
	bsp_w25qxx_MemoryMapedEnter();
  /* USER CODE END Init */

  /* Create the thread(s) */
  /* creation of defaultTask */
	xTaskCreate(StartDefaultTask,"StartDefaultTask",START_STK_SZIE,NULL,START_TASK_PRIO,&defaultTaskHandle);
  /* USER CODE BEGIN RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
	taskENTER_CRITICAL();
	
	sendSemaphore = xSemaphoreCreateBinary();
	
	uiSemaphore   = xSemaphoreCreateBinary();
	
	eventgroup_handle = xEventGroupCreate();
	
    xTaskCreate(transferTask,"transferTask",TRANSFER_STACK_SIZE,NULL,TRANSFER_TASK_PRIO,&transferTaskHandle);
	
    xTaskCreate(userTask,"userTask",USER_STACK_SIZE,NULL,USER_TASK_PRIO,&userTaskHandle);
	
	xTaskCreate(lvglTask,"lvglTask",LVGL_STACK_SIZE,NULL,LVGL_TASK_PRIO,&lvglTaskHandle);
	
	xTaskCreate(fileTask,"fileTask",FILE_STACK_SIZE,NULL,FILE_TASK_PRIO,&fileTaskHandle);
	
	taskEXIT_CRITICAL(); 
	
	vTaskDelete(NULL);
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void userTask(void *argument)
{
	usart3_init();
    serial_app_init();
    /* Infinite loop */
    for(;;)
    {
		setting_pro();
		serial_buff_atcion();
        osDelay(10); 
    }
    vTaskDelete(NULL);
    /* USER CODE END StartDefaultTask */
}

void transferTask(void *argument)
{
	
	e103_w11_init();
    for(;;)
    {
		wifi_and_usb_send_data();
		set_wifi_connect_status();
		osDelay(10);
    }
    vTaskDelete(NULL);
}



void lvglTask(void *argument)
{
	lv_init();
    lv_port_disp_init();
    lv_port_indev_init();
	osDelay(100);
	setup_ui(&guider_ui);
    LCD_LED(1);
    
    for(;;)
    {
		ui_battery_display();
		serial_update_display();
		wifi_data_display();
        lv_task_handler();
        osDelay(5);
    }
    vTaskDelete(NULL);
}


void fileTask(void *argument)
{
	for(;;)
    {
		serial_data_save_to_file();
		osDelay(10); 
	}
}

/* USER CODE END Application */

