#ifndef __APP_BATTERY_H_
#define __APP_BATTERY_H_

#include <stdint.h>
#include "stm32h7xx_hal.h"


#define BATTERY_PIN_STATUE	HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_2)


#define BATTERY_CHARGING 	GPIO_PIN_RESET

void ui_battery_display(void);



#endif


 

