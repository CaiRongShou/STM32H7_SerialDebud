#ifndef __BSP_INIT_H_
#define __BSP_INIT_H_

#include "stm32h7xx_hal.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sys.h" 
#include "delay.h" 


#define ENABLE_INT()	__set_PRIMASK(0)	/* 使能全局中断 */
#define DISABLE_INT()	__set_PRIMASK(1)	/* 禁止全局中断 */

#define M_ON_Pin GPIO_PIN_8
#define M_ON_GPIO_Port GPIOB
#define PWR_ON_Pin GPIO_PIN_9
#define PWR_ON_GPIO_Port GPIOB


#include "bsp_qspi_flash.h"
#include "bsp_ctp_ft6336.h"
#include "bsp_lcd.h"
#include "bsp_usb_cdc_acm.h"
#include "bsp_sd.h"
#include "bsp_sw.h"
#include "bsp_wifi.h"
#include "bsp_battery.h"
#include "bsp_uart.h"
#include "bsp_rtc.h"


#include "usart.h"
#include "rtc.h"
#include "adc.h"



void bsp_init(void);
void Error_Handler(void);


#endif


 

