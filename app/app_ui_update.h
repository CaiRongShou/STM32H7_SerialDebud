#ifndef __APP_UI_UPDATE_H_
#define __APP_UI_UPDATE_H_

#include <stdint.h>

typedef enum {
	serial_page = 0,
	menu_page,
	setting_page,
	wifi_page,
	histroy_page
}ui_page;

extern uint8_t ui_display_page;

void ui_update_display(void);


#endif


 

