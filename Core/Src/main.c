#include "main.h"
#include "cmsis_os.h"
#include "bsp_init.h"

void MX_FREERTOS_Init(void);

int main(void)
{
	bsp_init(); //ϵͳʱ�ӡ�����ȳ�ʼ��

	osKernelInitialize(); //rtos��ʼ��

	MX_FREERTOS_Init(); //������ʼ��

	osKernelStart(); //�����������

    while (1)
    {

    }

}


//ϵͳtick��ʼ���ص�
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

  if (htim->Instance == TIM4) {
    HAL_IncTick();
  }

}


