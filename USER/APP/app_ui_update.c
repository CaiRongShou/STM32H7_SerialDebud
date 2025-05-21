#include "app_define.h"

#include "bsp_rtc.h"
#include "bsp_wifi.h"



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





