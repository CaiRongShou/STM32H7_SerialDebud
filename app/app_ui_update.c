#include "app_ui_update.h"
#include "app_serial.h"
#include "wifi_usb_app.h"
#include "app_fatfs.h"


#include "gui_guider.h"
#include "events_init.h"
#include "rtc.h"
#include "dev_wifi.h"



uint8_t ui_display_page = 0;


extern SemaphoreHandle_t uiSemaphore;







void ui_update_display(void)
{
	switch(ui_display_page)
	{
		case serial_page:
			serial_update_display();
			break;
		case menu_page:
			break;
		case setting_page:
			break;
		case wifi_page:
			break;
		case histroy_page:
			break;
	}
}





