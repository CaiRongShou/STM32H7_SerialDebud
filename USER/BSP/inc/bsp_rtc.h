#ifndef __BSP_RTC_H_
#define __BSP_RTC_H_



#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "bsp_init.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern RTC_HandleTypeDef hrtc;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_RTC_Init(void);

/* USER CODE BEGIN Prototypes */
typedef struct 
{
    uint8_t hour;
    uint8_t min;
    uint8_t sec;            
    uint16_t year;
    uint8_t  month;
    uint8_t  date;
    uint8_t  week;     
}__rtcTime;  

extern __rtcTime rtcTime;

void set_rtc_time(__rtcTime *rtcTime);
void get_rtc_time(__rtcTime *rtcTime);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif


#endif


 

