#include "main.h"
#include "cmsis_os.h"
#include "bsp_init.h"

void MX_FREERTOS_Init(void);

int main(void)
{
	bsp_init(); //系统时钟、外设等初始化

	osKernelInitialize(); //rtos初始化

	MX_FREERTOS_Init(); //驱动初始化

	osKernelStart(); //启动任务调度

    while (1)
    {

    }

}


//系统tick初始化回调
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

  if (htim->Instance == TIM4) {
    HAL_IncTick();
  }

}


