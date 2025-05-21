#include "bsp_wifi.h"
#include "stm32h7xx_hal.h"


#include <string.h>
#include <stdio.h>
#include "usart.h"
#include "cmsis_os.h"


#define wifi_delay_ms(x) osDelay(x)

uint8_t wifi_rx_buffer[WIFI_RX_BUFFER_SIZE];  // ���ջ�����
uint8_t wifi_rx_dat;
uint8_t wifi_rx_len;
uint8_t e103_w11_cntPre = 0;
uint8_t g_wifi_connect_status; //WiFi����״̬

uint8_t ssid[32] = "crs";
uint8_t password[32] = "88888888";
uint8_t ip_addr[15];

//QueueHandle_t mutex_lock_uart3;

//==========================================================
//	�������ƣ�	wifi_receive_start
//
//	�������ܣ�	�����жϽ���
//
//	��ڲ�����	��
//
//	���ز�����	��
//
//	˵����
//==========================================================
void wifi_receive_start(uint8_t *buffer, uint16_t len)
{
    HAL_UART_Receive_IT(&WIFI_UART, buffer, len);
}

//==========================================================
//	�������ƣ�	e103_w11_Clear
//
//	�������ܣ�	��ջ���
//
//	��ڲ�����	��
//
//	���ز�����	��
//
//	˵����
//==========================================================
void e103_w11_clear(void)
{

    memset(wifi_rx_buffer, 0, 256);
    wifi_rx_len = 0;

}

//==========================================================
//	�������ƣ�	e103_w11_WaitRecive
//
//	�������ܣ�	�ȴ��������
//
//	��ڲ�����	��
//
//	���ز�����	REV_OK-�������		REV_WAIT-���ճ�ʱδ���
//
//	˵����		ѭ�����ü���Ƿ�������
//==========================================================
_Bool e103_w11_wait_recive(void)
{

    if(wifi_rx_len == 0) 							//������ռ���Ϊ0 ��˵��û�д��ڽ��������У�����ֱ����������������
        return REV_WAIT;

    if(wifi_rx_len == e103_w11_cntPre)				//�����һ�ε�ֵ�������ͬ����˵���������
    {
        wifi_rx_len = 0;							//��0���ռ���

        return REV_OK;								//���ؽ�����ɱ�־
    }

    e103_w11_cntPre = wifi_rx_len;					//��Ϊ��ͬ

    return REV_WAIT;								//���ؽ���δ��ɱ�־

}

//==========================================================
//	�������ƣ�	ssart_send_string
//
//	�������ܣ�	��������
//
//	��ڲ�����	��
//
//	���ز�����	REV_OK-�������		REV_WAIT-���ճ�ʱδ���
//
//	˵����		ѭ�����ü���Ƿ�������
//==========================================================
void usart_send_string(unsigned char *str, unsigned short len)
{

    HAL_UART_Transmit(&WIFI_UART, (uint8_t*)str,len, 100);

}

//==========================================================
//	�������ƣ�	e103_w11_SendCmd
//
//	�������ܣ�	��������
//
//	��ڲ�����	cmd������
//				res����Ҫ���ķ���ָ��
//
//	���ز�����	0-�ɹ�	1-ʧ��
//
//	˵����
//==========================================================
_Bool e103_w11_send_cmd(char *cmd, char *res,uint8_t mode,uint8_t timeOut)
{


    usart_send_string((unsigned char *)cmd, strlen((const char *)cmd));

    if(mode)
    {
        while(timeOut--)
        {
            if(e103_w11_wait_recive() == REV_OK)							//����յ�����
            {
                if(strstr((const char *)wifi_rx_buffer, res) != NULL)		//����������ؼ���
                {
                    e103_w11_clear();									//��ջ���

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
//	�������ƣ�	e103_w11_GetIPD
//
//	�������ܣ�	��ȡƽ̨���ص�����
//
//	��ڲ�����	�ȴ���ʱ��(����10ms)
//
//	���ز�����	ƽ̨���ص�ԭʼ����
//
//	˵����		��ͬ�����豸���صĸ�ʽ��ͬ����Ҫȥ����
//				��e103_w11�ķ��ظ�ʽΪ	"+IPD,x:yyy"	x�������ݳ��ȣ�yyy����������
//==========================================================
unsigned char *e103_w11_GetIPD(unsigned short timeOut)
{

    char *ptrIPD = NULL;

    do
    {
        if(e103_w11_wait_recive() == REV_OK)								//����������
        {
            ptrIPD = strstr((char *)wifi_rx_buffer, "IPD,");				//������IPD��ͷ
            if(ptrIPD == NULL)											//���û�ҵ���������IPDͷ���ӳ٣�������Ҫ�ȴ�һ�ᣬ�����ᳬ���趨��ʱ��
            {
                //UsartPrintf(USART_DEBUG, "\"IPD\" not found\r\n");
            }
            else
            {
                ptrIPD = strchr(ptrIPD, ':');							//�ҵ�':'
                if(ptrIPD != NULL)
                {
                    ptrIPD++;
                    return (unsigned char *)(ptrIPD);
                }
                else
                    return NULL;

            }
        }

        wifi_delay_ms(5);													//��ʱ�ȴ�
    } while(timeOut--);

    return NULL;														//��ʱ��δ�ҵ������ؿ�ָ��

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
//	�������ƣ�	e103_w11_Init
//
//	�������ܣ�	��ʼ��e103_w11
//
//	��ڲ�����	��
//
//	���ز�����	��
//
//	˵����
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

    //AT+CIPMUX=1 //����Ϊ�����ӡ�
    e103_w11_send_cmd("AT+CIPMUX=1\r\n", "OK",1,5);


    sprintf(str,"AT+CWJAP=\"%s\",\"%s\",\"s.y\"\r\n",ssid,password);
    e103_w11_send_cmd(str, "OK",1,20);

    wifi_delay_ms(100);
    //AT+CIPSERVER=1,8694,��TCP��
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


//��ѯwifi����״̬
uint8_t wifi_inquire_stetus(void)
{
    uint8_t timeOut = 100;
    char *ptr = NULL;

    e103_w11_clear();

    usart_send_string("AT+CIPSTATUS\r\n",strlen("AT+CIPSTATUS\r\n"));

    do
    {
        if(e103_w11_wait_recive() == REV_OK)								//����������
        {
            ptr = strstr((char *)wifi_rx_buffer, "STATUS");
            if(ptr == NULL)
            {
                //return
            }
            else
            {
                ptr = strchr(ptr, ':');							//�ҵ�':'
                if(ptr != NULL)
                {
                    ptr++;
                    return *ptr;
                }
                else
                    return 0;

            }
        }

        wifi_delay_ms(5);													//��ʱ�ȴ�
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
        if(e103_w11_wait_recive() == REV_OK)								//����������
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
//	�������ƣ�	e103_w11_SendData
//
//	�������ܣ�	��������
//
//	��ڲ�����	data������
//				len������
//
//	���ز�����	��
//
//	˵����
//==========================================================
void e103_w11_send_data(unsigned char *data, unsigned short len)
{

    char cmdBuf[32];
    uint8_t timeOut = 20;
    int i =0;
    for(i =0; i < 5; i++)
    {
        e103_w11_clear();
        sprintf(cmdBuf, "AT+CIPSEND=%d,%d\r\n", i, len);		//��������
        usart_send_string((uint8_t *)cmdBuf,strlen(cmdBuf));

        while(timeOut--)
        {
            if(e103_w11_wait_recive() == REV_OK)							//����յ�����
            {
                if(strstr((const char *)wifi_rx_buffer,">") != NULL)		//����������ؼ���
                {
                    e103_w11_clear();									//��ջ���
                    usart_send_string(data, len);		//�����豸������������
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
    if(wifi_rx_len > WIFI_RX_BUFFER_SIZE - 1) //��ֹ���ڱ�ˢ��
        wifi_rx_len = 0;
}





