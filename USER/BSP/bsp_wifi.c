#include "bsp_wifi.h"
#include "stm32h7xx_hal.h"


#include <string.h>
#include <stdio.h>
#include "usart.h"
#include "cmsis_os.h"


#define wifi_delay_ms(x) osDelay(x)

uint8_t wifi_rx_buffer[WIFI_RX_BUFFER_SIZE];  // 接收缓冲区
uint8_t wifi_rx_dat;
uint8_t wifi_rx_len;
uint8_t e103_w11_cntPre = 0;
uint8_t g_wifi_connect_status; //WiFi连接状态

uint8_t ssid[32] = "crs";
uint8_t password[32] = "88888888";
uint8_t ip_addr[15];

//QueueHandle_t mutex_lock_uart3;

//==========================================================
//	函数名称：	wifi_receive_start
//
//	函数功能：	启动中断接收
//
//	入口参数：	无
//
//	返回参数：	无
//
//	说明：
//==========================================================
void wifi_receive_start(uint8_t *buffer, uint16_t len)
{
    HAL_UART_Receive_IT(&WIFI_UART, buffer, len);
}

//==========================================================
//	函数名称：	e103_w11_Clear
//
//	函数功能：	清空缓存
//
//	入口参数：	无
//
//	返回参数：	无
//
//	说明：
//==========================================================
void e103_w11_clear(void)
{

    memset(wifi_rx_buffer, 0, 256);
    wifi_rx_len = 0;

}

//==========================================================
//	函数名称：	e103_w11_WaitRecive
//
//	函数功能：	等待接收完成
//
//	入口参数：	无
//
//	返回参数：	REV_OK-接收完成		REV_WAIT-接收超时未完成
//
//	说明：		循环调用检测是否接收完成
//==========================================================
_Bool e103_w11_wait_recive(void)
{

    if(wifi_rx_len == 0) 							//如果接收计数为0 则说明没有处于接收数据中，所以直接跳出，结束函数
        return REV_WAIT;

    if(wifi_rx_len == e103_w11_cntPre)				//如果上一次的值和这次相同，则说明接收完毕
    {
        wifi_rx_len = 0;							//清0接收计数

        return REV_OK;								//返回接收完成标志
    }

    e103_w11_cntPre = wifi_rx_len;					//置为相同

    return REV_WAIT;								//返回接收未完成标志

}

//==========================================================
//	函数名称：	ssart_send_string
//
//	函数功能：	发送数据
//
//	入口参数：	无
//
//	返回参数：	REV_OK-接收完成		REV_WAIT-接收超时未完成
//
//	说明：		循环调用检测是否接收完成
//==========================================================
void usart_send_string(unsigned char *str, unsigned short len)
{

    HAL_UART_Transmit(&WIFI_UART, (uint8_t*)str,len, 100);

}

//==========================================================
//	函数名称：	e103_w11_SendCmd
//
//	函数功能：	发送命令
//
//	入口参数：	cmd：命令
//				res：需要检查的返回指令
//
//	返回参数：	0-成功	1-失败
//
//	说明：
//==========================================================
_Bool e103_w11_send_cmd(char *cmd, char *res,uint8_t mode,uint8_t timeOut)
{


    usart_send_string((unsigned char *)cmd, strlen((const char *)cmd));

    if(mode)
    {
        while(timeOut--)
        {
            if(e103_w11_wait_recive() == REV_OK)							//如果收到数据
            {
                if(strstr((const char *)wifi_rx_buffer, res) != NULL)		//如果检索到关键词
                {
                    e103_w11_clear();									//清空缓存

                    return 0;
                }
            }

            wifi_delay_ms(500);
        }
    }


    e103_w11_clear();

    return 1;

}



//==========================================================
//	函数名称：	e103_w11_GetIPD
//
//	函数功能：	获取平台返回的数据
//
//	入口参数：	等待的时间(乘以10ms)
//
//	返回参数：	平台返回的原始数据
//
//	说明：		不同网络设备返回的格式不同，需要去调试
//				如e103_w11的返回格式为	"+IPD,x:yyy"	x代表数据长度，yyy是数据内容
//==========================================================
unsigned char *e103_w11_GetIPD(unsigned short timeOut)
{

    char *ptrIPD = NULL;

    do
    {
        if(e103_w11_wait_recive() == REV_OK)								//如果接收完成
        {
            ptrIPD = strstr((char *)wifi_rx_buffer, "IPD,");				//搜索“IPD”头
            if(ptrIPD == NULL)											//如果没找到，可能是IPD头的延迟，还是需要等待一会，但不会超过设定的时间
            {
                //UsartPrintf(USART_DEBUG, "\"IPD\" not found\r\n");
            }
            else
            {
                ptrIPD = strchr(ptrIPD, ':');							//找到':'
                if(ptrIPD != NULL)
                {
                    ptrIPD++;
                    return (unsigned char *)(ptrIPD);
                }
                else
                    return NULL;

            }
        }

        wifi_delay_ms(5);													//延时等待
    } while(timeOut--);

    return NULL;														//超时还未找到，返回空指针

}

void wifi_gpio_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOD_CLK_ENABLE();

    GPIO_InitStruct.Pin = GPIO_PIN_14;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
}
//==========================================================
//	函数名称：	e103_w11_Init
//
//	函数功能：	初始化e103_w11
//
//	入口参数：	无
//
//	返回参数：	无
//
//	说明：
//==========================================================
void e103_w11_init(void)
{

    char str[52];

    wifi_gpio_init();

    wifi_receive_start(&wifi_rx_dat,1);

    e103_w11_clear();

    e103_w11_send_cmd("AT+RESTORE\r\n", "OK",1,5);

    e103_w11_send_cmd("AT+RST\r\n", "OK",1,5);


    e103_w11_send_cmd("ATE0\r\n", "OK",1,5);

    e103_w11_send_cmd("AT+CWMODE=1,\"s.y\"\r\n", "OK",1,5);

//	e103_w11_send_cmd("AT+CIPSTA=\"192.168.137.150\",\"192.168.137.1\",\"255.255.255.0\",\"s.y\"\r\n", "OK",1,5);

    e103_w11_send_cmd("AT+CWDHCP=1,1,\"s.y\"\r\n", "OK",1,5);

    e103_w11_send_cmd("AT+CWAUTOCONN=1\r\n", "OK",1,5);

    //AT+CIPMUX=1 //设置为多连接。
    e103_w11_send_cmd("AT+CIPMUX=1\r\n", "OK",1,5);


    sprintf(str,"AT+CWJAP=\"%s\",\"%s\",\"s.y\"\r\n",ssid,password);
    e103_w11_send_cmd(str, "OK",1,20);

    wifi_delay_ms(100);
    //AT+CIPSERVER=1,8694,“TCP”
    uint8_t ret = wifi_inquire_stetus();
    if(ret == '2')
    {
        wifi_rec_ip_addr();
        wifi_delay_ms(100);
        e103_w11_send_cmd("AT+CIPSERVER=1,8888,\"TCP\"\r\n", "OK",1,20);
        g_wifi_connect_status = 1;
    }
}

void wifi_star_tcp_server(void)
{
    e103_w11_send_cmd("AT+CIPSERVER=1,8888,\"TCP\"\r\n", "OK",1,5);
}

uint8_t wifi_connect(void)
{
    char str[52];

    sprintf(str,"AT+CWJAP=\"%s\",\"%s\",\"s.y\"\r\n",ssid,password);
    e103_w11_send_cmd(str, "OK",1,10);

    return 1;
}


//查询wifi连接状态
uint8_t wifi_inquire_stetus(void)
{
    uint8_t timeOut = 100;
    char *ptr = NULL;

    e103_w11_clear();

    usart_send_string("AT+CIPSTATUS\r\n",strlen("AT+CIPSTATUS\r\n"));

    do
    {
        if(e103_w11_wait_recive() == REV_OK)								//如果接收完成
        {
            ptr = strstr((char *)wifi_rx_buffer, "STATUS");
            if(ptr == NULL)
            {
                //return
            }
            else
            {
                ptr = strchr(ptr, ':');							//找到':'
                if(ptr != NULL)
                {
                    ptr++;
                    return *ptr;
                }
                else
                    return 0;

            }
        }

        wifi_delay_ms(5);													//延时等待
    } while(timeOut--);

    return 0;
}



void wifi_waker_up(void)
{
    WIFI_WKUP_CLR();
    wifi_delay_ms(10);
    WIFI_WKUP_SET();
}


void wifi_enter_sleep(void)
{
    //AT+SLEEP
    e103_w11_send_cmd("AT+SLEEP=2\r\n", "OK",1,5);
}

void wifi_rec_ip_addr(void)
{
    uint8_t i = 0,timeOut = 100;
    char *ptr = NULL;

    e103_w11_clear();
    memset(ip_addr,0,15);
    usart_send_string("AT+CIPSTA?\r\n",strlen("AT+CIPSTA?\r\n"));

    do
    {
        if(e103_w11_wait_recive() == REV_OK)								//如果接收完成
        {
            ptr = strstr((char *)wifi_rx_buffer, "+CIPSTA");
            if(ptr == NULL)
            {
                //return;
            }
            else
            {
                ptr = strchr(ptr, ':');
                if(ptr != NULL)
                {
                    ptr += 2;

                    while(1)
                    {
                        ip_addr[i] = *ptr;
                        i ++;
                        ptr++;
                        if(*ptr == '"') return;
                    }
                }
                else
                    return;
            }
        }

        wifi_delay_ms(5);
    } while(timeOut--);


}

//==========================================================
//	函数名称：	e103_w11_SendData
//
//	函数功能：	发送数据
//
//	入口参数：	data：数据
//				len：长度
//
//	返回参数：	无
//
//	说明：
//==========================================================
void e103_w11_send_data(unsigned char *data, unsigned short len)
{

    char cmdBuf[32];
    uint8_t timeOut = 20;
    int i =0;
    for(i =0; i < 5; i++)
    {
        e103_w11_clear();
        sprintf(cmdBuf, "AT+CIPSEND=%d,%d\r\n", i, len);		//发送命令
        usart_send_string((uint8_t *)cmdBuf,strlen(cmdBuf));

        while(timeOut--)
        {
            if(e103_w11_wait_recive() == REV_OK)							//如果收到数据
            {
                if(strstr((const char *)wifi_rx_buffer,">") != NULL)		//如果检索到关键词
                {
                    e103_w11_clear();									//清空缓存
                    usart_send_string(data, len);		//发送设备连接请求数据
                }
            }

            wifi_delay_ms(1);
        }

    }

}



void wifi_rec_data(void)
{
    wifi_rx_buffer[wifi_rx_len++] = wifi_rx_dat;

    HAL_UART_Receive_IT(&WIFI_UART,&wifi_rx_dat,1);
    if(wifi_rx_len > WIFI_RX_BUFFER_SIZE - 1) //防止串口被刷爆
        wifi_rx_len = 0;
}





