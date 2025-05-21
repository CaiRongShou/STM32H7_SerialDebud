#include "app_wifi_usb.h"
#include "dev_wifi.h"
#include "gui_guider.h"
#include "app_setting.h"
#include "app_serial.h"
#include "dev_usb_cdc_acm.h"


wifi_usb_event_t wifi_usb_event_status; //WiFi事件标志


extern SemaphoreHandle_t sendSemaphore; 
extern EventGroupHandle_t eventgroup_handle;


void set_wifi_connect_status(void)
{
	static uint8_t cnt_1s = 0;
	uint8_t ret = 0;
	
	if(wifi_usb_event_status.wifi_en_status)
	{
		if(xEventGroupWaitBits(eventgroup_handle,WIFI_ENTER_EVENT,pdTRUE,pdTRUE,0) & WIFI_ENTER_EVENT)//发送数据
		{				
			wifi_usb_event_status.wifi_enter_flag = 0;
			
			memset(ssid,0,32);
			memset(password,0,32);
			
			g_wifi_connect_status = 0;
			const char *pt = lv_textarea_get_text(guider_ui.wifi_ta_wifi_name); 
			uint8_t len = strlen(pt);
			memcpy(ssid, pt, len);
			memcpy(ui_set_data.ssid, ssid, 32);
			pt = lv_textarea_get_text(guider_ui.wifi_ta_wifi_password); 
			len = strlen(pt);
			memcpy(password, pt, len);
			memcpy(ui_set_data.password, password, 32);
			
			wifi_connect();
		}
		
		if(!g_wifi_connect_status)
		{
			if(++cnt_1s >= 150)
			{
				cnt_1s = 0;
				ret = wifi_inquire_stetus();
				if(ret == '2')
				{
					wifi_star_tcp_server();
					osDelay(100);
					wifi_rec_ip_addr();
					
					g_wifi_connect_status = 1;
				}
			}
		}				
	}
	else
		g_wifi_connect_status = 0;

}


void wifi_and_usb_send_data(void)
{
	if(xSemaphoreTake(sendSemaphore,10) == pdTRUE)
	{
		usb_send_data(serial_data.wifi_and_usb_send_buffer,strlen((char *)serial_data.wifi_and_usb_send_buffer));
		if(g_wifi_connect_status)
		{
			e103_w11_send_data(serial_data.wifi_and_usb_send_buffer,strlen((char *)serial_data.wifi_and_usb_send_buffer));
		}
	}

}

void wifi_data_display(void)
{
	static uint8_t cnt_1s = 0;
	if(xEventGroupWaitBits(eventgroup_handle,WIFI_UI_EVENT,pdFAIL,pdTRUE,0) & WIFI_UI_EVENT)
	{
		if(++cnt_1s >= 100)
		{
			cnt_1s = 0;
			if(g_wifi_connect_status)
			{
				g_wifi_connect_status = 2;
				lv_textarea_set_text(guider_ui.wifi_ta_wifi_name, (char *)ssid);
				lv_textarea_set_text(guider_ui.wifi_ta_wifi_password, (char *)password);
				lv_label_set_text(guider_ui.wifi_label_3, (char *)ip_addr);
				lv_label_set_text(guider_ui.wifi_label_8, "当前已连接Wi-Fi");
			}
			else
			{
				lv_label_set_text(guider_ui.wifi_label_8, "当前未连接Wi-Fi");
				lv_label_set_text(guider_ui.wifi_label_3, "");
			}
		}
	}
}


