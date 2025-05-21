#include "bsp_sw.h"


void sw_gpio_init(void)
{
    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /*Configure GPIO pins :  SW_A_Pin SW_B_Pin */
    GPIO_InitStruct.Pin = SW_A_Pin|SW_B_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    HAL_GPIO_WritePin(GPIOB, SW_A_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, SW_B_Pin, GPIO_PIN_RESET);
}


void serial_sw_mode(uint8_t mode)
{
    switch (mode)
    {
    case TTL:
        TTL_SW_ENABLE();
        break;
    case RS485:
        RS232_SW_ENABLE();
        break;
    case RS232:
        RS485_SW_ENABLE();
        break;
    default:
        TTL_SW_ENABLE();
        break;
    }
}


