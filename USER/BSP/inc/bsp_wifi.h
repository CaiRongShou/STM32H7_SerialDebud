#ifndef __DEV_WIFI_H_
#define __DEV_WIFI_H_

#include <stdint.h>


#define WIFI_WKUP_PIN  GPIO_PIN_14
#define WIFI_WKUP_PORT GPIOD

#define WIFI_WKUP_SET()		HAL_GPIO_WritePin(WIFI_WKUP_PORT,WIFI_WKUP_PIN,GPIO_PIN_SET);
#define WIFI_WKUP_CLR()		HAL_GPIO_WritePin(WIFI_WKUP_PORT,WIFI_WKUP_PIN,GPIO_PIN_RESET);




#define REV_OK		0	//接收完成标志
#define REV_WAIT	1	//接收未完成标志
#define WIFI_UART        huart6  // Wi-Fi 模块使用 UART1
#define WIFI_RX_BUFFER_SIZE  256


extern uint8_t ssid[32];
extern uint8_t password[32];
extern uint8_t ip_addr[15];
extern uint8_t g_wifi_connect_status; //WiFi连接状态

void e103_w11_init(void);
void e103_w11_clear(void);
_Bool e103_w11_send_cmd(char *cmd, char *res,uint8_t mode,uint8_t timeOut);
void e103_w11_send_data(unsigned char *data, unsigned short len);
unsigned char *e103_w11_GetIPD(unsigned short timeOut);

void wifi_gpio_init(void);
void e103_w11_init(void);
uint8_t wifi_connect(void);
uint8_t wifi_inquire_stetus(void) ;
void wifi_waker_up(void);
void wifi_enter_sleep(void);
void wifi_rec_ip_addr(void);
void wifi_star_tcp_server(void);

#endif /*__DEV_WIFI_H_*/


 

