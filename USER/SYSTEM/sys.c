#include "sys.h" 






/**********************************************************************
 * 函数名称： Disable_TickIRQ
 * 功能描述： 禁止tick中断
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 无
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2024/07/05	     V1.0	  韦东山	      创建
 ***********************************************************************/
void Disable_TickIRQ(void)
{
    //HAL_NVIC_DisableIRQ(TIM4_IRQn);
}

/**********************************************************************
 * 函数名称： Enable_TickIRQ
 * 功能描述： 使能tick中断
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 无
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2024/07/05	     V1.0	  韦东山	      创建
 ***********************************************************************/
void Enable_TickIRQ(void)
{
    //HAL_NVIC_EnableIRQ(TIM4_IRQn);
}

