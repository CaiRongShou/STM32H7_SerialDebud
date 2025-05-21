/* USER CODE BEGIN Header */
/**
******************************************************************************
* File Name            : ft6336.c
* Description          : I2C drive based on STM32F4
* STM32 HAL library ver: STM32Cube_FW_F4_V1.27.1
*
******************************************************************************
* @attention
*
* Copyright (c) 2024~2029 mingfei.tang
* All rights reserved.
*
*************************************************************************
*/
/* USER CODE END Header */
#include "bsp_ctp_ft6336.h"

_m_tp_dev tp_dev =
{
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

void ctp_gpio_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOA, FT_RST_Pin|FT_SDA_Pin|FT_SCL_Pin, GPIO_PIN_SET);

    /*Configure GPIO pins : FT_INT_Pin  */
    GPIO_InitStruct.Pin = FT_INT_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pins : FT_RST_Pin  */
    GPIO_InitStruct.Pin = FT_RST_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pins : FT_SDA_Pin FT_SCL_Pin */
    GPIO_InitStruct.Pin = FT_SCL_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pins : FT_SDA_Pin FT_SCL_Pin */
    GPIO_InitStruct.Pin = FT_SDA_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}
//IIC初始化
void IIC_Init(void)
{
    ctp_gpio_init();
}

//数据端口配置为输出模式
void SDA_OUT(void)
{
//	GPIO_InitTypeDef GPIO_InitStruct = {0};
//	GPIO_InitStruct.Pin = FT_SDA_Pin;
//	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//	GPIO_InitStruct.Pull = GPIO_PULLUP;
//	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}
//数据端口配置为输入模式
void SDA_IN(void)
{
//	GPIO_InitTypeDef GPIO_InitStruct = {0};
//	GPIO_InitStruct.Pin = FT_SDA_Pin;
//	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//	GPIO_InitStruct.Pull = GPIO_PULLUP;
//	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}
//iic延时使用
static void IIC_delay(void)
{
    volatile int i = 100;
    while (i)
        i--;
}
//起始信号
void IIC_Start(void)
{
    SDA_OUT();
    SCL_HIGH;
    SDA_HIGH;
    IIC_delay();
    SDA_LOW;
    IIC_delay();
}
//停止信号
void IIC_Stop(void)
{
    SDA_OUT();
    SCL_LOW;
    IIC_delay();
    SDA_LOW;
    IIC_delay();
    SCL_HIGH;
    IIC_delay();
    SDA_HIGH;
    IIC_delay();
}
/* 等待从机应答信号          */
/* 返回值： 0：接收应答失败  */
/*          1：接收应答成功  */
unsigned char IIC_Slave_Ack(void)
{
    SDA_OUT();
    SCL_LOW;
    IIC_delay();
    SDA_HIGH;

    SDA_IN();
    IIC_delay();
    SCL_HIGH;

    IIC_delay();

    if(SDA_READ)
    {
        SCL_LOW;
        return 0;
    }
    SCL_LOW;
    IIC_delay();
    return 1;
}

//发送一个字节
void IIC_Send_Byte(unsigned char byte)
{
    unsigned char i = 8;
    SDA_OUT();
    while (i--)
    {
        SCL_LOW;                //拉低时钟开始数据传输
        IIC_delay();
        if (byte & 0x80)
            SDA_HIGH;
        else
            SDA_LOW;
        byte <<= 1;
        IIC_delay();
        SCL_HIGH;
        IIC_delay();
    }
    SCL_LOW;
    if(IIC_Slave_Ack()==0)
    {
        return ;
    }
}
/* 读取一个字节数据   */
/* 返回值：读取的数据 */
unsigned char IIC_Read_Byte(void)
{
    unsigned char i;
    unsigned char dat = 0;
    SDA_IN();
    for (i=0; i<8; i++)
    {
        dat <<= 1;
        SCL_HIGH;
        IIC_delay();
        dat |= SDA_READ;
        SCL_LOW;
        IIC_delay();
    }
    return dat;
}

/* 向寄存器写一个字节数据       */
/* SlaveAddress：从机地址       */
/* REG_Address：寄存器地址      */
/* REG_data：向寄存器写入的数据 */
void IIC_Write_One_Byte(unsigned char SlaveAddress,unsigned char REG_Address,unsigned char REG_data)
{
    IIC_Start();
    IIC_Send_Byte(SlaveAddress);
    IIC_Send_Byte(REG_Address);
    IIC_Send_Byte(REG_data);
    IIC_Stop();
}

//* 从寄存器读取一个字节数据 */
//* SlaveAddress：从机地址   */
//* REG_Address： 寄存器地址 */
//* 返回值：读取的数据       */
unsigned char IIC_Read_One_Byte(unsigned char SlaveAddress,unsigned char REG_Address)
{
    unsigned char REG_data;

    IIC_Start();
    IIC_Send_Byte(SlaveAddress);
    IIC_Send_Byte(REG_Address);
    IIC_Start();
    IIC_Send_Byte(SlaveAddress+1);
    REG_data = IIC_Read_Byte();
    IIC_Slave_Ack();
    IIC_Stop();
    return REG_data;
}
//连续读取两个字节数据
unsigned short int IIC_Read_Two_Bytes(unsigned char SlaveAddress,unsigned char REG_Address)
{
    unsigned char H, L;
    H = IIC_Read_One_Byte(SlaveAddress,REG_Address);
    L = IIC_Read_One_Byte(SlaveAddress,REG_Address+1);
    return ( ((unsigned short int)H) << 8 | L) ;
}

//初始化相关io和必要配置
void ft6336u_init() {
    IIC_Init();
}


void ft6336_info(void)
{
    FT6336U_IC_INFO info;
    ft6336u_read_ic_info(&info);            //读取芯片信
    printf(" CIPHER : 0x%lx , LIB_VERSION : 0x%x , FIRMWARE_VERSION : 0x%x , VENDOR_ID : 0x%x\r\n",
           info.CPIPHER,info.LIB_VERSION,info.FIRMWARE_VERSION,info.VENDOR_ID);  //打印芯片信息
}


//复位芯片
void ft6336u_reset() {
    HAL_GPIO_WritePin(FT_RST_GPIO_Port,FT_RST_Pin,GPIO_PIN_RESET);
    IIC_delay();
    IIC_delay();
    IIC_delay();
    IIC_delay();
    IIC_delay();
    IIC_delay();
    IIC_delay();
    IIC_delay();
    IIC_delay();
    IIC_delay();
    HAL_GPIO_WritePin(FT_RST_GPIO_Port,FT_RST_Pin,GPIO_PIN_SET);
}

//读取芯片信息
void ft6336u_read_ic_info(FT6336U_IC_INFO *info) {
    uint8_t CIPHER_HIGH = IIC_Read_One_Byte(FT6336U_Slave_Addr,ID_G_CIPHER_HIGH);
    uint8_t CIPHER_MIDE = IIC_Read_One_Byte(FT6336U_Slave_Addr,ID_G_CIPHER_MIDE);
    uint8_t CIPHER_LOW = IIC_Read_One_Byte(FT6336U_Slave_Addr,ID_G_CIPHER_LOW);

    info->CPIPHER = (CIPHER_HIGH << 16) + (CIPHER_MIDE << 8) + CIPHER_LOW;

    uint8_t LIB_VERSION_H = IIC_Read_One_Byte(FT6336U_Slave_Addr,ID_G_LIB_VERSION_H);
    uint8_t LIB_VERSION_L = IIC_Read_One_Byte(FT6336U_Slave_Addr,ID_G_LIB_VERSION_L);

    info->LIB_VERSION = (LIB_VERSION_H << 8) + LIB_VERSION_L;

    uint8_t FIRMID = IIC_Read_One_Byte(FT6336U_Slave_Addr,ID_G_FIRMID);
    info->FIRMWARE_VERSION = FIRMID;

    uint8_t FOCALTECH_ID = IIC_Read_One_Byte(FT6336U_Slave_Addr,ID_G_FOCALTECH_ID);
    info->VENDOR_ID = FOCALTECH_ID;
}


//写入近距离感应使能
void ft6336u_face_dec_enable(uint8_t enable) {
    IIC_Write_One_Byte(FT6336U_Slave_Addr,ID_G_FACE_DEC_MODE,enable);
}
//读取触摸数据
void ft6336u_read_touch_pos(FT6336U_TOUCH_POS *touch_pos) {

    //读取第一个点的数据
    uint8_t P1_XH_P = IIC_Read_One_Byte(FT6336U_Slave_Addr,P1_XH);
    uint8_t P1_XL_P = IIC_Read_One_Byte(FT6336U_Slave_Addr,P1_XL);
    uint8_t P1_YH_P = IIC_Read_One_Byte(FT6336U_Slave_Addr,P1_YH);
    uint8_t P1_YL_P = IIC_Read_One_Byte(FT6336U_Slave_Addr,P1_YL);
    //读取第二个点的数据
    uint8_t P2_XH_P = IIC_Read_One_Byte(FT6336U_Slave_Addr,P2_XH);
    uint8_t P2_XL_P = IIC_Read_One_Byte(FT6336U_Slave_Addr,P2_XL);
    uint8_t P2_YH_P = IIC_Read_One_Byte(FT6336U_Slave_Addr,P2_YH);
    uint8_t P2_YL_P = IIC_Read_One_Byte(FT6336U_Slave_Addr,P2_YL);
    //读取有效点的个数
    uint8_t tp_status = IIC_Read_One_Byte(FT6336U_Slave_Addr,TD_STATUS);

    touch_pos->touch_num = tp_status;
    touch_pos->touch0_x = ((P1_XH_P & 0x0F) << 8) + P1_XL_P;
    touch_pos->touch0_y = ((P1_YH_P & 0x0F) << 8) + P1_YL_P;
    touch_pos->touch1_x = ((P2_XH_P & 0x0F) << 8) + P2_XL_P;
    touch_pos->touch1_y = ((P2_YH_P & 0x0F) << 8) + P2_YL_P;
}

//写入功耗模式
void ft6336u_write_power_mode(POWER_MODE mode) {
    IIC_Write_One_Byte(FT6336U_Slave_Addr,ID_G_PMODE,mode);
}
//读取功耗模式
uint8_t ft6336u_read_power_mode() {
    return IIC_Read_One_Byte(FT6336U_Slave_Addr,ID_G_PMODE);
}

//写入中断模式使能
void ft6336u_write_int_mode_enable(uint8_t enable) {
    IIC_Write_One_Byte(FT6336U_Slave_Addr,ID_G_MODE,enable);
}

//写入工作模式
void ft6336u_write_work_mode(POWER_MODE mode) {
    IIC_Write_One_Byte(FT6336U_Slave_Addr,ID_G_STATE,mode);
}


//写入特殊姿势识别模式使能
void ft6336u_write_spec_gesture_enable(uint8_t enable) {
    IIC_Write_One_Byte(FT6336U_Slave_Addr,ID_G_SPEC_GESTURE_ENABLE,enable);
}
//读取识别到的手势ID
void ft6336u_read_spec_gesture_id(uint8_t *id) {
    *id =  IIC_Read_One_Byte(FT6336U_Slave_Addr,ID_G_SPEC_GESTURE_ID);
}

//轮询读取
void test1(void)
{

    FT6336U_TOUCH_POS touch;

    ft6336u_read_touch_pos(&touch); //读取触摸数据
    printf("touch_num : %d \r\n",touch.touch_num);
    if(touch.touch_num == 1)
        printf("x1: %d , y1 : %d\r\n",touch.touch0_x,touch.touch0_y);
    else if(touch.touch_num == 2)
        printf("x1: %d , y1 : %d , x2: %d , y2 : %d\r\n",touch.touch0_x,touch.touch0_y,touch.touch1_x,touch.touch1_y);

}

//特殊手势识别
void test2() {
    ft6336u_write_spec_gesture_enable(FT_ENABLE);  //开启特殊手势使能

    while(1) {
        uint8_t  id;
        ft6336u_read_spec_gesture_id(&id);
        printf("touch_num : %d \r\n",id);
    }
}


////中断模式读取
//uint8_t touch_flag = 0;

////中断服务程序
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
//    //有触摸
//    if(HAL_GPIO_ReadPin(FT_INT_GPIO_Port,FT_INT_Pin) == 0)
//        touch_flag = 1;
//}


//void test3() {
//	FT6336U_TOUCH_POS touch;

//    ft6336u_write_int_mode_enable(FT_ENABLE); // 使能中断模式
//    ft6336u_face_dec_enable(FT_ENABLE);  //开启近距离感应测试
//    while(1) {
//        if( touch_flag == 1) {
//            ft6336u_read_touch_pos(&touch); //读取触摸数据
//            printf("touch_num : %d \r\n", touch.touch_num);
//            if (touch.touch_num == 1)
//                printf( "x1: %d , y1 : %d\r\n", touch.touch0_x, touch.touch0_y);
//            else if (touch.touch_num == 2)
//                printf("x1: %d , y1 : %d , x2: %d , y2 : %d\r\n", touch.touch0_x, touch.touch0_y, touch.touch1_x,
//                       touch.touch1_y);
//            touch_flag = 0;
//            HAL_Delay(1);
//        }

//    }
//}

//中断模式特殊手势识别
//void test4() {


//    ft6336u_write_int_mode_enable(FT_ENABLE); // 使能中断模式
//    ft6336u_write_spec_gesture_enable(FT_ENABLE);  //开启特殊手势使能
//    while(1) {
//        uint8_t  id;
//        if( touch_flag == 1) {
//            ft6336u_read_spec_gesture_id(&id);
//            printf("touch_num : %d\r\n ",id);
//            touch_flag = 0;
//        }
//    }
//}

uint8_t ft6336_scan(void)
{
    uint8_t i = 0;
    uint8_t res = 0;
    uint16_t temp;
    uint16_t tempsta;
    FT6336U_TOUCH_POS touch;

    static uint8_t t = 0;   /* 控制查询间隔,从而降低CPU占用率 */


    t++;
    if ((t % 10) == 0 || t < 10)   /* 空闲时,每进入10次CTP_Scan函数才检测1次,从而节省CPU使用率 */
    {
        ft6336u_read_touch_pos(&touch); //读取触摸数据
        if((touch.touch_num & 0x0f) && ((touch.touch_num & 0x0f) < 6))
        {
            temp = 0XFFFF << (touch.touch_num & 0XF);  /* 将点的个数转换为1的位数,匹配tp_dev.sta定义 */
            tempsta =tp_dev.sta;           /* 保存当前的tp_dev.sta值 */
            tp_dev.sta = (~temp) | TP_PRES_DOWN | TP_CATH_PRES;
            tp_dev.x[1] = tp_dev.x[0];  /* 保存触点0的数据,保存在最后一个上 */
            tp_dev.y[1] = tp_dev.y[0];
            if (tp_dev.sta & (1 << i))  /* 触摸有效? */
            {
                tp_dev.y[0] = touch.touch0_y;
                tp_dev.x[0] = touch.touch0_x + 0;

                tp_dev.y[1] = touch.touch1_y;
                tp_dev.x[1] = touch.touch1_x + 0;
            }

            res = 1;

            if (tp_dev.x[0] > LCD_W || tp_dev.y[0] > LCD_H)  /* 非法数据(坐标超出了) */
            {
                if ((touch.touch_num & 0XF) > 1)   /* 有其他点有数据,则复第二个触点的数据到第一个触点. */
                {
                    tp_dev.x[0] = tp_dev.x[1];
                    tp_dev.y[0] = tp_dev.y[1];
                    t = 0;  /* 触发一次,则会最少连续监测10次,从而提高命中率 */
                }
                else        /* 非法数据,则忽略此次数据(还原原来的) */
                {
                    tp_dev.x[0] = tp_dev.x[1];
                    tp_dev.y[0] = tp_dev.y[1];
                    touch.touch_num = 0X80;
                    tp_dev.sta = tempsta;   /* 恢复tp_dev.sta */
                }
            }
            else
            {
                t = 0;      /* 触发一次,则会最少连续监测10次,从而提高命中率 */
            }
        }
        // printf("x1: %d , y1 : %d\r\n",touch.touch0_x,touch.touch0_y);
    }

    if (touch.touch_num  == 0)  /* 无触摸点按下 */
    {
        if (tp_dev.sta & TP_PRES_DOWN)      /* 之前是被按下的 */
        {
            tp_dev.sta &= ~TP_PRES_DOWN;    /* 标记按键松开 */
        }
        else    /* 之前就没有被按下 */
        {
            tp_dev.x[0] = 0xffff;
            tp_dev.y[0] = 0xffff;
            tp_dev.sta &= 0XE000;           /* 清除点有效标记 */
        }
    }

    if (t > 240)t = 10; /* 重新从10开始计数 */

    return res;
}















/* End of this file */
