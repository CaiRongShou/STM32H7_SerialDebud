#include "bsp_rtc.h"

RTC_HandleTypeDef hrtc;

/* RTC init function */
void MX_RTC_Init(void)
{

    /* USER CODE BEGIN RTC_Init 0 */

    /* USER CODE END RTC_Init 0 */

    RTC_TimeTypeDef sTime = {0};
    RTC_DateTypeDef sDate = {0};

    /* USER CODE BEGIN RTC_Init 1 */

    /* USER CODE END RTC_Init 1 */

    /** Initialize RTC Only
    */
    hrtc.Instance = RTC;
    hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
    hrtc.Init.AsynchPrediv = 127;
    hrtc.Init.SynchPrediv = 255;
    hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
    hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
    hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
    hrtc.Init.OutPutRemap = RTC_OUTPUT_REMAP_NONE;
    if (HAL_RTC_Init(&hrtc) != HAL_OK)
    {
        Error_Handler();
    }

    /* USER CODE BEGIN Check_RTC_BKUP */

    /* USER CODE END Check_RTC_BKUP */

}

void HAL_RTC_MspInit(RTC_HandleTypeDef* rtcHandle)
{

    RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
    if(rtcHandle->Instance==RTC)
    {
        /* USER CODE BEGIN RTC_MspInit 0 */

        /* USER CODE END RTC_MspInit 0 */

        /** Initializes the peripherals clock
        */
        PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
        PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
        if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
        {
            Error_Handler();
        }

        /* RTC clock enable */
        __HAL_RCC_RTC_ENABLE();
        /* USER CODE BEGIN RTC_MspInit 1 */


        /* USER CODE END RTC_MspInit 1 */
    }
}

void HAL_RTC_MspDeInit(RTC_HandleTypeDef* rtcHandle)
{

    if(rtcHandle->Instance==RTC)
    {
        /* USER CODE BEGIN RTC_MspDeInit 0 */

        /* USER CODE END RTC_MspDeInit 0 */
        /* Peripheral clock disable */
        __HAL_RCC_RTC_DISABLE();
        /* USER CODE BEGIN RTC_MspDeInit 1 */

        /* USER CODE END RTC_MspDeInit 1 */
    }
}

__rtcTime rtcTime;




void set_rtc_time(__rtcTime *rtcTime)
{
    RTC_TimeTypeDef sTime;
    RTC_DateTypeDef sDate;
    sTime.Hours     = rtcTime->hour;
    sTime.Minutes   = rtcTime->min;
    sTime.Seconds   = rtcTime->sec;
    sDate.Date 		= rtcTime->date;
    sDate.Month     = rtcTime->month;
    sDate.WeekDay   = rtcTime->week;
    sDate.Year      = rtcTime->year;

    HAL_RTC_SetTime(&hrtc,&sTime,FORMAT_BIN);
    HAL_RTC_SetDate(&hrtc,&sDate,FORMAT_BIN);
}

void get_rtc_time(__rtcTime *rtcTime)
{
    RTC_TimeTypeDef sTime;
    RTC_DateTypeDef sDate;

    HAL_RTC_GetTime(&hrtc,&sTime,FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc,&sDate,FORMAT_BIN);

    rtcTime->hour   = sTime.Hours;
    rtcTime->min = sTime.Minutes;
    rtcTime->sec  = sTime.Seconds ;
    rtcTime->date = sDate.Date;
    rtcTime->month = sDate.Month;
    rtcTime->week = sDate.WeekDay;
    rtcTime->year = sDate.Year;
}
