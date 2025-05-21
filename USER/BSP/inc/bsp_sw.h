/**
  ************************************* Copyright ******************************   
  *                 (C) Copyright 2024,crs,China, GCU.
  *                            All Rights Reserved
  *                              
  *                     By(电子创新实验室)
  *      
  * FileName   : dev_sw.h   
  * Version    : v1.0		
  * Author     : crs		
  * Date       : 2024-12-12         
  * Description:    
  * Function List:  
  	1. ....
  	   <version>: 		
  <modify staff>:
  		  <data>:
   <description>:  
  	2. ...
  ******************************************************************************
 */



#ifndef __DEV_SW_H_
#define __DEV_SW_H_

#include "main.h"

#define TTL         0
#define RS485       1
#define RS232       2


#define SW_A_Pin GPIO_PIN_13
#define SW_A_GPIO_Port GPIOB
#define SW_B_Pin GPIO_PIN_14
#define SW_B_GPIO_Port GPIOB

#define TTL_SW_ENABLE()         HAL_GPIO_WritePin(SW_A_GPIO_Port,SW_A_Pin,GPIO_PIN_SET);\
                                HAL_GPIO_WritePin(SW_B_GPIO_Port,SW_B_Pin,GPIO_PIN_RESET);\

#define RS232_SW_ENABLE()       HAL_GPIO_WritePin(SW_A_GPIO_Port,SW_A_Pin,GPIO_PIN_RESET);\
                                HAL_GPIO_WritePin(SW_B_GPIO_Port,SW_B_Pin,GPIO_PIN_SET);

#define RS485_SW_ENABLE()       HAL_GPIO_WritePin(SW_A_GPIO_Port,SW_A_Pin,GPIO_PIN_SET);\
                                HAL_GPIO_WritePin(SW_B_GPIO_Port,SW_B_Pin,GPIO_PIN_SET);

void serial_sw_mode(uint8_t mode);
void sw_gpio_init(void);


#endif


 

