#include "app_define.h"

#include "usart.h"
#include "string.h"
#include <stdio.h>


#include "bsp_rtc.h"


__attribute__((section(".serial_buffer"))) serial_data_t serial_data;
serial_data_event_t serial_data_event; 



serial_event_flag_t serial_event_flag;
uint32_t serial_rx_cnt,serial_tx_cnt;

uint32_t ui_clear_date_size = 1000; //显示数据限制 1000 清屏

extern EventGroupHandle_t eventgroup_handle;


/* 二进制信号量句柄 */
extern SemaphoreHandle_t sendSemaphore; 
extern SemaphoreHandle_t uiSemaphore;


void AutoBaudRate_Print(void) 
{
    // 2. 获取USART时钟频率（PCLK2）
    uint32_t pclk2_freq = HAL_RCC_GetPCLK2Freq(); // 例如 200 MHz

    // 3. 读取BRR寄存器并计算波特率
    uint32_t brr = USART3->BRR;
    uint16_t div_mantissa = (brr >> 4) & 0xFFF;
    uint8_t div_fraction = brr & 0xF;
    uint8_t over8 = (USART3->CR1 & USART_CR1_OVER8) ? 1 : 0;

    float baud_rate;
    if (over8) {
        baud_rate = (float)pclk2_freq / (8 * (div_mantissa + (div_fraction / 16.0)));
    } else {
        baud_rate = (float)pclk2_freq / (16 * (div_mantissa + (div_fraction / 16.0)));
    }
	g_uart3_baud = baud_rate;
	
    // 4. 打印波特率
//    char msg[50];
//    sprintf(msg, "Auto-detected Baud Rate: %.0f bps\r\n", baud_rate);
//    HAL_UART_Transmit(&huart3, (uint8_t*)msg, strlen(msg), 100);
}



void string_to_hex(const char *input, unsigned char *output, uint32_t *output_length) {
    int len = strlen(input);
    char temp_input[128]; // 假设输入字符串不会超过256字节

	strcpy(temp_input, input); // 直接复制原字符串
    // 如果字符串长度是奇数，在前面补一个 '0'
    if (len % 2 != 0) 
	{
        temp_input[len] = '0'; // 补一个 '0'
        len++; // 更新长度
	}
    *output_length = len / 2; // 计算输出的16进制数据长度

    for (int i = 0; i < *output_length; i++) {
        // 每两个字符转换为一个16进制字节
        sscanf(temp_input + 2 * i, "%2hhx", &output[i]);
    }
}



// 将接收或发送的数据添加标识
void serial_add_data(uint8_t *out_data,uint32_t *in_len,uint8_t *in_data,uint32_t data_len,uint8_t mode)
{
	uint32_t str_size = 0;
	
	if (!in_data || !out_data || !data_len) return;

	if(mode)
	{
		if ( (data_len + 7) > ( (SERIAL_DATA_SIZE * 3) - (*in_len) ) ) {
			// 如果数据超过可用空间，清空队列
			*in_len = 0;
			memset(out_data,0,SERIAL_DATA_SIZE);
		}
	}
	else
	{
		if ( (data_len + 7) > ( SERIAL_DATA_SIZE - (*in_len) ) ) {
			// 如果数据超过可用空间，清空队列
			*in_len = 0;
			memset(out_data,0,SERIAL_DATA_SIZE);
		}
	}
    
	
	if(serial_data_event.is_rec_send == 1)
	{
		str_size = strlen( "[TX]: ");
		memcpy(out_data + (*in_len), "[TX]: ",str_size );
		*in_len += str_size;
	}
	else if(serial_data_event.is_rec_send == 0) 
	{
		str_size = strlen( "[RX]: ");
		memcpy(out_data + (*in_len), "[RX]: ",str_size );
		*in_len += str_size;
	}			 


	memcpy(out_data + (*in_len), in_data, data_len);
	*in_len += data_len;
		

	str_size = strlen("\n");
	memcpy(out_data + (*in_len),"\n",str_size);
	*in_len += str_size;
}

// 将 ASCII 字符串转换为 HEX
void ascii_to_formatted_hex(const uint8_t *data, uint32_t length, char *output)
{
    if (!data || !output || length == 0) return;

    for (uint32_t i = 0; i < length; i++) {
        snprintf(output + i * 3, 6, "%02X ", data[i]);
    }
}


void serial_app_init(void)
{
	memset(&serial_data,0,sizeof(serial_data_t));
	memset(&serial_data_event,0,sizeof(serial_data_event_t));
	memset(&serial_event_flag,0,sizeof(serial_event_flag));
	
	serial_data_event.is_rec_send = 2;
}

void serial_buff_atcion(void)
{
	uint8_t temp_buff[1024];
	uint8_t len = 0;
	
	if(xEventGroupWaitBits(eventgroup_handle,SERIAL_REC_EVENT,pdTRUE,pdTRUE,0) & SERIAL_REC_EVENT)
	{
		serial_data_event.is_rec_send = 0; //是接收数据
		if(g_adaptive_baud)
		{
			AutoBaudRate_Print(); //获取当前波特率
			usart3_init();
		}
		
		serial_rx_cnt += serial_data_event.uart_rx_len;
		serial_add_data(serial_data.asiic_buffer,&serial_data_event.asiic_len,serial_data.uart_rx_buffer,serial_data_event.uart_rx_len,0); //拷贝接收到的数据，并添加标识
		
		//转为hex 储存在hexbuff中
		ascii_to_formatted_hex(serial_data.uart_rx_buffer,serial_data_event.uart_rx_len,(char *)temp_buff);
		serial_add_data(serial_data.hex_buffer,&serial_data_event.hex_len,temp_buff,serial_data_event.uart_rx_len * 3,1); //拷贝接收到的数据，并添加标识
		
		//数据上传拷贝
		memset(serial_data.wifi_and_usb_send_buffer,0,sizeof(serial_data.wifi_and_usb_send_buffer));
		serial_add_data(serial_data.wifi_and_usb_send_buffer,&len,serial_data.uart_rx_buffer,serial_data_event.uart_rx_len,0); //拷贝接收到的数据，并添加标识
		xSemaphoreGive(sendSemaphore);//通知usb and wifi 上传数据
		
		xSemaphoreGive(uiSemaphore);//通知ui更新显示
		
		serial_data_event.uart_rx_len = 0;
	}
	
	if(xEventGroupWaitBits(eventgroup_handle,SERIAL_SEND_EVENT,pdTRUE,pdTRUE,0) & SERIAL_SEND_EVENT)//发送数据
	{
		serial_data_event.is_rec_send = 1;  //是发送数据
		
		const char *pt = lv_textarea_get_text(guider_ui.Serial_ta_1); //获取键盘字符

		serial_data_event.uart_tx_len = strlen(pt);
		RS485_DE_SEND();//
		if(serial_data_event.send_asiic_hex == 1) //hex发送
		{
			string_to_hex(pt,serial_data.uart_tx_buffer,&serial_data_event.uart_tx_len);
			serial_tx_cnt += serial_data_event.uart_tx_len;
			serial_add_data(serial_data.asiic_buffer,&serial_data_event.asiic_len,serial_data.uart_tx_buffer,serial_data_event.uart_tx_len,0);
			
			//转为字符hex 储存在hexbuff中
			ascii_to_formatted_hex(serial_data.uart_tx_buffer,serial_data_event.uart_tx_len,(char *)temp_buff);
			serial_add_data(serial_data.hex_buffer,&serial_data_event.hex_len,temp_buff,serial_data_event.uart_tx_len * 3,1); //拷贝发送的数据，并添加标识
			
			HAL_UART_Transmit_IT(&huart3,serial_data.uart_tx_buffer,serial_data_event.uart_tx_len);
			
			//数据上传拷贝
			memset(serial_data.wifi_and_usb_send_buffer,0,sizeof(serial_data.wifi_and_usb_send_buffer));
			serial_add_data(serial_data.wifi_and_usb_send_buffer,&len,serial_data.uart_tx_buffer,serial_data_event.uart_tx_len,0); //拷贝接收到的数据，并添加标识
			xSemaphoreGive(sendSemaphore);//通知usb and wifi 上传数据
			
			xSemaphoreGive(uiSemaphore);//通知ui更新显示
		}
		else
		{
			serial_tx_cnt += serial_data_event.uart_tx_len;
			memcpy(serial_data.uart_tx_buffer, pt, serial_data_event.uart_tx_len); //拷贝到发送buff
			serial_add_data(serial_data.asiic_buffer,&serial_data_event.asiic_len,serial_data.uart_tx_buffer,serial_data_event.uart_tx_len,0);
			
			//转为字符hex 储存在hexbuff中
			ascii_to_formatted_hex(serial_data.uart_tx_buffer,serial_data_event.uart_tx_len,(char *)temp_buff);
			serial_add_data(serial_data.hex_buffer,&serial_data_event.hex_len,temp_buff,serial_data_event.uart_tx_len * 3,1); //拷贝发送的数据，并添加标识
			
			HAL_UART_Transmit_IT(&huart3,serial_data.uart_tx_buffer,serial_data_event.uart_tx_len);
			
			//数据上传拷贝
			memset(serial_data.wifi_and_usb_send_buffer,0,sizeof(serial_data.wifi_and_usb_send_buffer));
			serial_add_data(serial_data.wifi_and_usb_send_buffer,&len,serial_data.uart_tx_buffer,serial_data_event.uart_tx_len,0); //拷贝接收到的数据，并添加标识
			xSemaphoreGive(sendSemaphore); //通知usb and wifi 上传数据
			
			xSemaphoreGive(uiSemaphore);//通知ui更新显示
		}
		
		serial_data_event.uart_tx_len = 0;
	}
	
	if(xEventGroupWaitBits(eventgroup_handle,SERIAL_CLR_EVENT,pdTRUE,pdTRUE,0) & SERIAL_CLR_EVENT)//清除屏幕显示
	{
		serial_rx_cnt = 0;
		serial_tx_cnt = 0;
		
		memset(serial_data.asiic_buffer,0,SERIAL_DATA_SIZE);
		memset(serial_data.hex_buffer,0,SERIAL_DATA_SIZE);
		
		serial_data_event.asiic_len = 0;
		serial_data_event.hex_len = 0;
		
		xSemaphoreGive(uiSemaphore);//通知ui更新显示
	}
	
	if(serial_event_flag.serial_cb_hex_flag == 1) // hex显示还是字符显示
	{
		serial_event_flag.serial_cb_hex_flag = 0;
		if(serial_data_event.is_asiic_hex == 0)
		{			
			serial_data_event.is_asiic_hex = 1;
		}
		else
		{
			serial_data_event.is_asiic_hex = 0;
		}
		xSemaphoreGive(uiSemaphore); //通知ui更新显示
	}
	if(serial_event_flag.serial_cb_sned_flag == 1) //hex发送还是字符发送
	{
		serial_event_flag.serial_cb_sned_flag = 0;
		if(serial_data_event.send_asiic_hex == 0)
		{
			serial_data_event.send_asiic_hex = 1;
		}
		else
		{
			serial_data_event.send_asiic_hex = 0;
		} 

	}
	if(xEventGroupWaitBits(eventgroup_handle,SERIAL_RET_EVENT,pdTRUE,pdTRUE,0) & SERIAL_RET_EVENT)
	{
		serial_rx_cnt = 0;
		serial_tx_cnt = 0;
		ui_clear_date_size = 1000;
		memset(&serial_data,0,sizeof(serial_data_t));
		memset(&serial_data_event,0,sizeof(serial_data_event_t));
		memset(&serial_event_flag,0,sizeof(serial_event_flag_t));
	}
}

void serial_update_display(void)//更新显示串口数据到屏幕上
{
	static uint16_t cnt_1_min = 0;
	
	if(xEventGroupWaitBits(eventgroup_handle,SERIAL_UI_EVENT,pdFAIL,pdTRUE,0) & SERIAL_UI_EVENT)
	{
		if(xSemaphoreTake(uiSemaphore,10) == pdTRUE)
		{
			if( (serial_rx_cnt + serial_tx_cnt) >= ui_clear_date_size)
			{
				ui_clear_date_size += 1000;
				lv_textarea_set_text(guider_ui.Serial_ta_2, "");
			}
			
			if(serial_data_event.is_asiic_hex == 1)
			{

				lv_textarea_set_text(guider_ui.Serial_ta_2, (char*)&serial_data.hex_buffer[(ui_clear_date_size-1000) * 3]);
			}
			else
			{
				lv_textarea_set_text(guider_ui.Serial_ta_2, (char*)&serial_data.asiic_buffer[ui_clear_date_size-1000]);
			}
			
			lv_label_set_text_fmt(guider_ui.Serial_label_rx_num,"%d",serial_rx_cnt);
			lv_label_set_text_fmt(guider_ui.Serial_label_tx_num,"%d",serial_tx_cnt);
			lv_label_set_text_fmt(guider_ui.Serial_label_7, "%d",g_uart3_baud);
		}
		
		if(++cnt_1_min == 12000)
		{
			cnt_1_min = 0;
			get_rtc_time(&rtcTime);
			lv_label_set_text_fmt(guider_ui.Serial_label_rtc,"%02d/%02d:%02d",rtcTime.date,rtcTime.hour,rtcTime.min);
		}
	}

}

void HAL_UART_IdleCallback(UART_HandleTypeDef *huart)
{
	BaseType_t ret;
	if(__HAL_UART_GET_FLAG(huart,UART_FLAG_IDLE)!= RESET)//如果接受到了一帧数据
	{ 
		__HAL_UART_CLEAR_IDLEFLAG(huart);//清除标志位
		xEventGroupSetBitsFromISR(eventgroup_handle,SERIAL_REC_EVENT,&ret);
	}	
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART3)
	{
		
		if(serial_data_event.uart_rx_len > (UART_DATA_SIZE - 1))
			serial_data_event.uart_rx_len = 0;
		
		serial_data.uart_rx_buffer[serial_data_event.uart_rx_len++] = serial_data_event.data_temp;
		HAL_UART_Receive_IT(huart, &serial_data_event.data_temp,1);

	}
	if(huart->Instance == USART6)
	{
		void wifi_rec_data(void);
		wifi_rec_data(); 
	}
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART3)
	{
		RS485_DE_REC();//
	}
}









