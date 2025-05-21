#ifndef __APP_SETTING_H_
#define __APP_SETTING_H_

#include <stdint.h>
#include <stdbool.h>


#define SETTING_SAVE_EVENT (1 << 5)
#define SETTING_WIFI_SAVE_EVENT (1 << 6)

typedef struct {
	uint8_t serial_sw; //串口协议选择
	uint8_t serial_baud; //波特率索引
	uint8_t adaptive_port; //分析仪接口选择
	uint8_t	adaptive_baud; //自适应波特率是否开启
	uint8_t	wifi_status; //自适应波特率是否开启
	uint8_t ssid[32];
	uint8_t password[32];
}ui_setting_t;


//typedef struct {
//	bool setting_save_flag;
//	bool setting_wifi_save_flag;
//}setting_event_flag_t;




extern ui_setting_t ui_set_data;
//extern setting_event_flag_t setting_event_flag;
extern uint8_t 	g_serial_sw; //通信协议 TTL 232 475
extern uint32_t g_uart3_baud; //波特率
extern uint8_t 	g_adaptive_port; //逻辑分析接口
extern uint8_t	g_adaptive_baud; //自适应波特率


void usart3_init(void);
void setting_data_init(void);
void setting_pro(void);


#endif


 

