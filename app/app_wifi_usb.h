#ifndef __APP_WIFI_USB_H_
#define __APP_WIFI_USB_H_

#include "cmsis_os.h"
#include "usart.h"
#include "gui_guider.h"
#include "events_init.h"

#define 	WIFI_ENTER_EVENT 		(1<<7)
#define 	WIFI_UI_EVENT 			(1<<9)



typedef struct{
	uint8_t wifi_enter_flag;
	uint8_t wifi_en_status;
}wifi_usb_event_t;


extern wifi_usb_event_t wifi_usb_event_status;

void set_wifi_connect_status(void);
void wifi_and_usb_send_data(void);
void wifi_data_display(void);

#endif


 

