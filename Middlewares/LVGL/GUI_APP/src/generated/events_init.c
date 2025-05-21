/*
* Copyright 2025 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h" 
#include "app_define.h"


#include "bsp_rtc.h"
#include "bsp_wifi.h"

#if LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

extern EventGroupHandle_t eventgroup_handle;

static void serial_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_RIGHT:
			{
				serial_event_flag.serial_ret_flag = 1;
				xEventGroupSetBits(eventgroup_handle,SERIAL_RET_EVENT);
				xEventGroupClearBits(eventgroup_handle,SERIAL_UI_EVENT);
				lv_indev_wait_release(lv_indev_get_act());
				ui_load_scr_animation(&guider_ui, &guider_ui.menu, guider_ui.menu_del, &guider_ui.Serial_del, setup_scr_menu, LV_SCR_LOAD_ANIM_NONE, 0, 200, false, true);
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}

static void setting_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_RIGHT:
			{
				xEventGroupSetBits(eventgroup_handle,SETTING_SAVE_EVENT);
				lv_indev_wait_release(lv_indev_get_act());
				ui_load_scr_animation(&guider_ui, &guider_ui.menu, guider_ui.menu_del, &guider_ui.setting_del, setup_scr_menu, LV_SCR_LOAD_ANIM_NONE, 0, 200, false, true);
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}


static void wifi_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_RIGHT:
			{
				xEventGroupSetBits(eventgroup_handle,SETTING_WIFI_SAVE_EVENT); //
				xEventGroupClearBits(eventgroup_handle,WIFI_UI_EVENT);
				lv_indev_wait_release(lv_indev_get_act());
				ui_load_scr_animation(&guider_ui, &guider_ui.menu, guider_ui.menu_del, &guider_ui.wifi_del, setup_scr_menu, LV_SCR_LOAD_ANIM_NONE, 0, 200, false, true);
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}

static void histroy_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_RIGHT:
			{
				lv_indev_wait_release(lv_indev_get_act());
				ui_load_scr_animation(&guider_ui, &guider_ui.menu, guider_ui.menu_del, &guider_ui.histroy_del, setup_scr_menu, LV_SCR_LOAD_ANIM_NONE, 0, 200, false, true);
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}

static void file_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_RIGHT:
			{
				ui_load_scr_animation(&guider_ui, &guider_ui.histroy, guider_ui.histroy_del, &guider_ui.file_del, setup_scr_histroy, LV_SCR_LOAD_ANIM_NONE, 0, 200, false, true);
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}

void events_init_file(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->file, file_event_handler, LV_EVENT_GESTURE, ui);
}

static void Serial_cb_hex_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
		case LV_EVENT_PRESSED:
			serial_event_flag.serial_cb_hex_flag = 1; 
			break;
	default: 
		break;
	}
}
static void Serial_cb_set_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	static uint8_t send_asiic_hex = 0;
	switch (code) {
		case LV_EVENT_PRESSED:
			
			if(send_asiic_hex == 0)
			{
				lv_keyboard_set_textarea(guider_ui.g_kb_Serial, guider_ui.Serial_ta_1);
				lv_textarea_set_text(guider_ui.Serial_ta_1, "");
				lv_textarea_set_accepted_chars(guider_ui.Serial_ta_1,"0123456789abcdefABCDEF"); 
				send_asiic_hex = 1;
			}
			else
			{
				lv_keyboard_set_textarea(guider_ui.g_kb_Serial, guider_ui.Serial_ta_1);
				lv_textarea_set_text(guider_ui.Serial_ta_1, "");
				lv_textarea_set_accepted_chars(guider_ui.Serial_ta_1,""); 
				send_asiic_hex = 0;
			} 
			
			serial_event_flag.serial_cb_sned_flag = 1;
		
			break;
	default:
		break;
	}
}

static void Serial_btn_send_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
		case LV_EVENT_PRESSED:
			xEventGroupSetBits(eventgroup_handle,SERIAL_SEND_EVENT);
			break;
	default:
		break;
	}
}

static void Serial_btn_clr_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
		case LV_EVENT_PRESSED:
			lv_keyboard_set_textarea(guider_ui.g_kb_Serial, guider_ui.Serial_ta_1);
			lv_textarea_set_text(guider_ui.Serial_ta_1, "");
			xEventGroupSetBits(eventgroup_handle,SERIAL_CLR_EVENT);
			break;
	default:
		break;
	}
}

static void Serial_btn_new_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
		case LV_EVENT_PRESSED:
				xEventGroupSetBits(eventgroup_handle,SERIAL_NEW_EVENT);
			break;
	default:
		break;
	}
}

static void Serial_btn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
		case LV_EVENT_PRESSED:
			usart3_init();
			break;
	default:
		break;
	}
}

void events_init_Serial(lv_ui *ui)
{
	usart3_init();
	get_rtc_time(&rtcTime);
	xEventGroupSetBits(eventgroup_handle,SERIAL_UI_EVENT);
	lv_label_set_text_fmt(ui->Serial_label_7, "%d",g_uart3_baud);
	lv_label_set_text_fmt(ui->Serial_label_rtc,"%02d/%02d:%02d",rtcTime.date,rtcTime.hour,rtcTime.min);
	lv_obj_add_event_cb(ui->Serial, serial_event_handler, LV_EVENT_GESTURE, ui);
	lv_obj_add_event_cb(ui->Serial_cb_hex, Serial_cb_hex_event_handler, LV_EVENT_PRESSED, ui);
	lv_obj_add_event_cb(ui->Serial_cb_set, Serial_cb_set_event_handler, LV_EVENT_PRESSED, ui);
	lv_obj_add_event_cb(ui->Serial_btn_send, Serial_btn_send_event_handler, LV_EVENT_PRESSED, ui);
	lv_obj_add_event_cb(ui->Serial_btn_clr, Serial_btn_clr_event_handler, LV_EVENT_PRESSED, ui);
	lv_obj_add_event_cb(ui->Serial_btn_new, Serial_btn_new_event_handler, LV_EVENT_PRESSED, ui);
}

static void setting_list_day_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
		case LV_EVENT_CLICKED:
		{
			rtcTime.date      =  lv_dropdown_get_selected(guider_ui.setting_list_day);
			break;
		}
	default:
		break;
	}
}
static void setting_list_hour_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
		case LV_EVENT_CLICKED:
		{
			rtcTime.hour      =  lv_dropdown_get_selected(guider_ui.setting_list_hour);
			break;
		}
	default:
		break;
	}
}
static void setting_list_min_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
		case LV_EVENT_CLICKED:
		{
			rtcTime.min      =  lv_dropdown_get_selected(guider_ui.setting_list_min);
			break;
		}
	default:
		break;
	}
}
static void setting_list_serial_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
		case LV_EVENT_CLICKED:
		{
			/* Get the index of the selected option */
			ui_set_data.serial_sw      =  lv_dropdown_get_selected(guider_ui.setting_list_serial);
			break;
		}
	default:
		break;
	}
}
static void setting_list_baud_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code) {
		case LV_EVENT_CLICKED:
		{
			
			/* Get the index of the selected option */
			ui_set_data.serial_baud    =  lv_dropdown_get_selected(guider_ui.setting_list_baud);
			break;
		}
	default:
		break;
	}
}
static void setting_list_analy_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
		case LV_EVENT_CLICKED:
		{
			/* Get the index of the selected option */
			ui_set_data.adaptive_port     =  lv_dropdown_get_selected(guider_ui.setting_list_analy);
			break;
		}
	default:
		break;
	}
}
static void setting_list_baud_star_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
		case LV_EVENT_CLICKED:
		{
			/* Get the index of the selected option */
			ui_set_data.adaptive_baud  =  lv_dropdown_get_selected(guider_ui.setting_list_baud_star);
			break;
		}
	default:
		break;
	}
}

void setting_list_set_selected(void)
{
	
	lv_dropdown_set_selected(guider_ui.setting_list_day,rtcTime.date);
	lv_dropdown_set_selected(guider_ui.setting_list_hour,rtcTime.hour);
	lv_dropdown_set_selected(guider_ui.setting_list_min,rtcTime.min);
	lv_dropdown_set_selected(guider_ui.setting_list_serial,ui_set_data.serial_sw);
	lv_dropdown_set_selected(guider_ui.setting_list_baud,ui_set_data.serial_baud);
	lv_dropdown_set_selected(guider_ui.setting_list_analy,ui_set_data.adaptive_port);
	lv_dropdown_set_selected(guider_ui.setting_list_baud_star,ui_set_data.adaptive_baud);
}

void events_init_setting(lv_ui *ui)
{
	setting_list_set_selected();
	
	lv_obj_add_event_cb(ui->setting, setting_event_handler, LV_EVENT_GESTURE, ui);
	lv_obj_add_event_cb(lv_dropdown_get_list(ui->setting_list_hour), setting_list_hour_event_handler, LV_EVENT_CLICKED, ui);
	lv_obj_add_event_cb(lv_dropdown_get_list(ui->setting_list_min), setting_list_min_event_handler, LV_EVENT_CLICKED, ui);
	lv_obj_add_event_cb(lv_dropdown_get_list(ui->setting_list_day), setting_list_day_event_handler, LV_EVENT_CLICKED, ui);
	lv_obj_add_event_cb(lv_dropdown_get_list(ui->setting_list_serial), setting_list_serial_event_handler, LV_EVENT_CLICKED, ui);
	lv_obj_add_event_cb(lv_dropdown_get_list(ui->setting_list_baud), setting_list_baud_event_handler, LV_EVENT_CLICKED, ui);
	lv_obj_add_event_cb(lv_dropdown_get_list(ui->setting_list_analy), setting_list_analy_event_handler, LV_EVENT_CLICKED, ui);
	lv_obj_add_event_cb(lv_dropdown_get_list(ui->setting_list_baud_star), setting_list_baud_star_event_handler, LV_EVENT_CLICKED, ui);
}
static void menu_btn_menu_serial_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Serial, guider_ui.Serial_del, &guider_ui.menu_del, setup_scr_Serial, LV_SCR_LOAD_ANIM_NONE, 0, 200, false, true);
		break;
	}
	default:
		break;
	}
}

static void menu_btn_menu_set_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.setting, guider_ui.setting_del, &guider_ui.menu_del, setup_scr_setting, LV_SCR_LOAD_ANIM_NONE, 0, 200, false, true);
		break;
	}
	default:
		break;
	}
}
static void menu_btn_menu_histroy_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.histroy, guider_ui.histroy_del, &guider_ui.menu_del, setup_scr_histroy, LV_SCR_LOAD_ANIM_NONE, 0, 200, false, true);
		break;
	}
	default:
		break;
	}
}
static void menu_btn_wifi_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_PRESSED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.wifi, guider_ui.wifi_del, &guider_ui.menu_del, setup_scr_wifi, LV_SCR_LOAD_ANIM_NONE, 0, 200, false, true);
		break;
	}
	default:
		break;
	}
}
void events_init_menu(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->menu_btn_menu_serial, menu_btn_menu_serial_event_handler, LV_EVENT_PRESSED, ui);
	lv_obj_add_event_cb(ui->menu_btn_menu_set, menu_btn_menu_set_event_handler, LV_EVENT_PRESSED, ui);
	lv_obj_add_event_cb(ui->menu_btn_menu_histroy, menu_btn_menu_histroy_event_handler, LV_EVENT_PRESSED, ui);
	lv_obj_add_event_cb(ui->menu_btn_wifi, menu_btn_wifi_event_handler, LV_EVENT_PRESSED, ui);
}
static void wifi_list_en_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
		case LV_EVENT_CLICKED:
		{
			/* Get the index of the selected option */
			wifi_usb_event_status.wifi_en_status  =  lv_dropdown_get_selected(guider_ui.wifi_list_en);
			
			/* Get the index of the selected option */
			ui_set_data.wifi_status     		  =  lv_dropdown_get_selected(guider_ui.wifi_list_en);
			
			if(wifi_usb_event_status.wifi_en_status)
				wifi_waker_up();
			else
				wifi_enter_sleep();
			break;
		}
	default:
		break;
	}
}

static void wifi_enter_en_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
		case LV_EVENT_PRESSED:
		{
			xEventGroupSetBits(eventgroup_handle,WIFI_ENTER_EVENT);
			break;
		}
		default:
			break;
	}
}

void events_init_wifi(lv_ui *ui)
{
	xEventGroupSetBits(eventgroup_handle,WIFI_UI_EVENT);
	lv_textarea_set_text(guider_ui.wifi_ta_wifi_name, (char *)ui_set_data.ssid);
	lv_textarea_set_text(guider_ui.wifi_ta_wifi_password, (char *)ui_set_data.password);
	
	lv_dropdown_set_selected(guider_ui.wifi_list_en,ui_set_data.wifi_status);
	lv_obj_add_event_cb(ui->wifi, wifi_event_handler, LV_EVENT_GESTURE, ui);
	lv_obj_add_event_cb(ui->wifi_btn_enter, wifi_enter_en_event_handler, LV_EVENT_PRESSED, ui);
	lv_obj_add_event_cb(lv_dropdown_get_list(ui->wifi_list_en), wifi_list_en_event_handler, LV_EVENT_CLICKED, ui);
}

void events_init_histroy(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->histroy, histroy_event_handler, LV_EVENT_GESTURE, ui);
}

void events_init(lv_ui *ui)
{

}
