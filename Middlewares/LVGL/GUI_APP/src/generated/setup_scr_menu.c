/*
* Copyright 2025 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_menu(lv_ui *ui)
{
	//Write codes menu
	ui->menu = lv_obj_create(NULL);
	lv_obj_set_size(ui->menu, 320, 480);
	lv_obj_set_scrollbar_mode(ui->menu, LV_SCROLLBAR_MODE_OFF);

	//Write style for menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->menu, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->menu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menu_label_1
	ui->menu_label_1 = lv_label_create(ui->menu);
	lv_label_set_text(ui->menu_label_1, "主菜单");
	lv_label_set_long_mode(ui->menu_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->menu_label_1, 30, 14);
	lv_obj_set_size(ui->menu_label_1, 260, 22);

	//Write style for menu_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menu_label_1, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menu_label_1, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->menu_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->menu_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menu_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->menu_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menu_btn_menu_serial
	ui->menu_btn_menu_serial = lv_btn_create(ui->menu);
	ui->menu_btn_menu_serial_label = lv_label_create(ui->menu_btn_menu_serial);
	lv_label_set_text(ui->menu_btn_menu_serial_label, "串口调试");
	lv_label_set_long_mode(ui->menu_btn_menu_serial_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->menu_btn_menu_serial_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->menu_btn_menu_serial, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->menu_btn_menu_serial_label, LV_PCT(100));
	lv_obj_set_pos(ui->menu_btn_menu_serial, 30, 80);
	lv_obj_set_size(ui->menu_btn_menu_serial, 260, 50);

	//Write style for menu_btn_menu_serial, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->menu_btn_menu_serial, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->menu_btn_menu_serial, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->menu_btn_menu_serial, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->menu_btn_menu_serial, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menu_btn_menu_serial, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menu_btn_menu_serial, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menu_btn_menu_serial, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menu_btn_menu_serial, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->menu_btn_menu_serial, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menu_btn_menu_serial, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for menu_btn_menu_serial, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_bg_opa(ui->menu_btn_menu_serial, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_color(ui->menu_btn_menu_serial, lv_color_hex(0xff95f6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_grad_dir(ui->menu_btn_menu_serial, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_border_width(ui->menu_btn_menu_serial, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_radius(ui->menu_btn_menu_serial, 5, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->menu_btn_menu_serial, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->menu_btn_menu_serial, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->menu_btn_menu_serial, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->menu_btn_menu_serial, 255, LV_PART_MAIN|LV_STATE_PRESSED);


	//Write codes menu_btn_menu_set
	ui->menu_btn_menu_set = lv_btn_create(ui->menu);
	ui->menu_btn_menu_set_label = lv_label_create(ui->menu_btn_menu_set);
	lv_label_set_text(ui->menu_btn_menu_set_label, "参数设置");
	lv_label_set_long_mode(ui->menu_btn_menu_set_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->menu_btn_menu_set_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->menu_btn_menu_set, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->menu_btn_menu_set_label, LV_PCT(100));
	lv_obj_set_pos(ui->menu_btn_menu_set, 30, 160);
	lv_obj_set_size(ui->menu_btn_menu_set, 260, 50);

	//Write style for menu_btn_menu_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->menu_btn_menu_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->menu_btn_menu_set, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->menu_btn_menu_set, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->menu_btn_menu_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menu_btn_menu_set, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menu_btn_menu_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menu_btn_menu_set, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menu_btn_menu_set, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->menu_btn_menu_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menu_btn_menu_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for menu_btn_menu_set, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_bg_opa(ui->menu_btn_menu_set, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_color(ui->menu_btn_menu_set, lv_color_hex(0xff95f6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_grad_dir(ui->menu_btn_menu_set, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_border_width(ui->menu_btn_menu_set, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_radius(ui->menu_btn_menu_set, 5, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->menu_btn_menu_set, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->menu_btn_menu_set, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->menu_btn_menu_set, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->menu_btn_menu_set, 255, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write codes menu_btn_menu_histroy
	ui->menu_btn_menu_histroy = lv_btn_create(ui->menu);
	ui->menu_btn_menu_histroy_label = lv_label_create(ui->menu_btn_menu_histroy);
	lv_label_set_text(ui->menu_btn_menu_histroy_label, "历史记录");
	lv_label_set_long_mode(ui->menu_btn_menu_histroy_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->menu_btn_menu_histroy_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->menu_btn_menu_histroy, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->menu_btn_menu_histroy_label, LV_PCT(100));
	lv_obj_set_pos(ui->menu_btn_menu_histroy, 30, 240);
	lv_obj_set_size(ui->menu_btn_menu_histroy, 260, 50);

	//Write style for menu_btn_menu_histroy, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->menu_btn_menu_histroy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->menu_btn_menu_histroy, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->menu_btn_menu_histroy, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->menu_btn_menu_histroy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menu_btn_menu_histroy, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menu_btn_menu_histroy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menu_btn_menu_histroy, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menu_btn_menu_histroy, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->menu_btn_menu_histroy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menu_btn_menu_histroy, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for menu_btn_menu_histroy, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_bg_opa(ui->menu_btn_menu_histroy, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_color(ui->menu_btn_menu_histroy, lv_color_hex(0xff95f6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_grad_dir(ui->menu_btn_menu_histroy, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_border_width(ui->menu_btn_menu_histroy, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_radius(ui->menu_btn_menu_histroy, 5, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->menu_btn_menu_histroy, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->menu_btn_menu_histroy, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->menu_btn_menu_histroy, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->menu_btn_menu_histroy, 255, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write codes menu_line_1
	ui->menu_line_1 = lv_line_create(ui->menu);
	static lv_point_t menu_line_1[] ={{320, 0},{0, 0},};
	lv_line_set_points(ui->menu_line_1, menu_line_1, 2);
	lv_obj_set_pos(ui->menu_line_1, 0, 40);
	lv_obj_set_size(ui->menu_line_1, 320, 2);

	//Write style for menu_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->menu_line_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->menu_line_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->menu_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->menu_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes menu_btn_wifi
	ui->menu_btn_wifi = lv_btn_create(ui->menu);
	ui->menu_btn_wifi_label = lv_label_create(ui->menu_btn_wifi);
	lv_label_set_text(ui->menu_btn_wifi_label, "Wi-Fi设置");
	lv_label_set_long_mode(ui->menu_btn_wifi_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->menu_btn_wifi_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->menu_btn_wifi, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->menu_btn_wifi_label, LV_PCT(100));
	lv_obj_set_pos(ui->menu_btn_wifi, 28, 320);
	lv_obj_set_size(ui->menu_btn_wifi, 260, 50);

	//Write style for menu_btn_wifi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->menu_btn_wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->menu_btn_wifi, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->menu_btn_wifi, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->menu_btn_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->menu_btn_wifi, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->menu_btn_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->menu_btn_wifi, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->menu_btn_wifi, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->menu_btn_wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->menu_btn_wifi, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for menu_btn_wifi, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_bg_opa(ui->menu_btn_wifi, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_color(ui->menu_btn_wifi, lv_color_hex(0xff95f6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_grad_dir(ui->menu_btn_wifi, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_border_width(ui->menu_btn_wifi, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_radius(ui->menu_btn_wifi, 5, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->menu_btn_wifi, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->menu_btn_wifi, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->menu_btn_wifi, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->menu_btn_wifi, 255, LV_PART_MAIN|LV_STATE_PRESSED);

	//The custom code of menu.
	void ui_battery_init(lv_ui *ui,lv_obj_t *obj);
	ui_battery_init(ui,ui->menu);


	//Update current screen layout.
	lv_obj_update_layout(ui->menu);

	//Init events for screen.
	events_init_menu(ui);
}
