#ifndef __APP_SERIAL_H_
#define __APP_SERIAL_H_


#include <stdint.h>
#include <stdbool.h>

#define 	SERIAL_DATA_SIZE 30720
#define 	UART_DATA_SIZE 1024 
#define 	SERIAL_BUAD_TAB_MAX		sizeof(serial_buad_tab)/sizeof(&serial_buad_tab[1])

#define 	SERIAL_REC_EVENT 		(1<<0)
#define 	SERIAL_SEND_EVENT 		(1<<1)
#define 	SERIAL_CLR_EVENT 		(1<<2)
#define 	SERIAL_RET_EVENT 		(1<<3)
#define 	SERIAL_NEW_EVENT 		(1<<4)

#define 	SERIAL_UI_EVENT 		(1<<8)

#define RS485_DE_SEND() 	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_8,GPIO_PIN_SET);
#define RS485_DE_REC()		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_8,GPIO_PIN_RESET);

typedef struct {
    uint8_t asiic_buffer[SERIAL_DATA_SIZE];  // 
	uint8_t hex_buffer[SERIAL_DATA_SIZE * 3];  // 
	uint8_t uart_rx_buffer[UART_DATA_SIZE];
	uint8_t uart_tx_buffer[UART_DATA_SIZE]; 
	uint8_t wifi_and_usb_send_buffer[UART_DATA_SIZE*2];
}serial_data_t;

typedef struct {
	uint16_t asiic_len;  // 
	uint32_t hex_len;  // 
	uint8_t is_rec_send; //发送还是接收 0:接收 1:发送
	uint8_t is_asiic_hex; //发送还是接收 0:asiic 1:hex
	uint8_t send_asiic_hex;
	uint8_t data_temp;
	uint16_t uart_tx_len;
	uint16_t uart_rx_len;
}serial_data_event_t; 

 
typedef struct {
//	bool serial_btn_send_flag;
//	bool serial_btn_clr_flag;
//	bool serial_btn_new_flag;
	bool serial_cb_hex_flag;
	bool serial_cb_sned_flag;
	bool serial_ret_flag;
}serial_event_flag_t;

extern serial_event_flag_t serial_event_flag;
extern serial_data_t serial_data;
extern serial_data_event_t serial_data_event; 
extern uint32_t serial_rx_cnt,serial_tx_cnt;

void serial_buff_atcion(void);
void serial_app_init(void);
void serial_update_display(void);
void serial_update_display(void);//更新显示串口数据到屏幕上


#endif


 

