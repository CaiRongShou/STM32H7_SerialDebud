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



void setup_scr_wifi(lv_ui *ui)
{
	//Write codes wifi
	ui->wifi = lv_obj_create(NULL);
	ui->g_kb_wifi = lv_keyboard_create(ui->wifi);
	lv_obj_add_event_cb(ui->g_kb_wifi, kb_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(ui->g_kb_wifi, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_text_font(ui->g_kb_wifi, &lv_font_Source_Han_Serif_SC_Light_Light_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_size(ui->wifi, 320, 480);
	lv_obj_set_scrollbar_mode(ui->wifi, LV_SCROLLBAR_MODE_OFF);

	//Write style for wifi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->wifi, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->wifi, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifi_ta_wifi_name
	ui->wifi_ta_wifi_name = lv_textarea_create(ui->wifi);
	lv_textarea_set_text(ui->wifi_ta_wifi_name, "");
	lv_textarea_set_placeholder_text(ui->wifi_ta_wifi_name, "");
	lv_textarea_set_password_bullet(ui->wifi_ta_wifi_name, "*");
	lv_textarea_set_password_mode(ui->wifi_ta_wifi_name, false);
	lv_textarea_set_one_line(ui->wifi_ta_wifi_name, false);
	lv_textarea_set_accepted_chars(ui->wifi_ta_wifi_name, "");
	lv_textarea_set_max_length(ui->wifi_ta_wifi_name, 32);
	#if LV_USE_KEYBOARD != 0 || LV_USE_ZH_KEYBOARD != 0
		lv_obj_add_event_cb(ui->wifi_ta_wifi_name, ta_event_cb, LV_EVENT_ALL, ui->g_kb_wifi);
	#endif
	lv_obj_set_pos(ui->wifi_ta_wifi_name, 111, 97);
	lv_obj_set_size(ui->wifi_ta_wifi_name, 200, 35);

	//Write style for wifi_ta_wifi_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->wifi_ta_wifi_name, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->wifi_ta_wifi_name, &lv_font_Source_Han_Serif_SC_Light_Light_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->wifi_ta_wifi_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->wifi_ta_wifi_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->wifi_ta_wifi_name, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->wifi_ta_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->wifi_ta_wifi_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->wifi_ta_wifi_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->wifi_ta_wifi_name, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->wifi_ta_wifi_name, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->wifi_ta_wifi_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->wifi_ta_wifi_name, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->wifi_ta_wifi_name, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->wifi_ta_wifi_name, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifi_ta_wifi_name, 5, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for wifi_ta_wifi_name, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->wifi_ta_wifi_name, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->wifi_ta_wifi_name, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->wifi_ta_wifi_name, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifi_ta_wifi_name, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes wifi_ta_wifi_password
	ui->wifi_ta_wifi_password = lv_textarea_create(ui->wifi);
	lv_textarea_set_text(ui->wifi_ta_wifi_password, "");
	lv_textarea_set_placeholder_text(ui->wifi_ta_wifi_password, "");
	lv_textarea_set_password_bullet(ui->wifi_ta_wifi_password, "*");
	lv_textarea_set_password_mode(ui->wifi_ta_wifi_password, false);
	lv_textarea_set_one_line(ui->wifi_ta_wifi_password, false);
	lv_textarea_set_accepted_chars(ui->wifi_ta_wifi_password, "");
	lv_textarea_set_max_length(ui->wifi_ta_wifi_password, 32);
	#if LV_USE_KEYBOARD != 0 || LV_USE_ZH_KEYBOARD != 0
		lv_obj_add_event_cb(ui->wifi_ta_wifi_password, ta_event_cb, LV_EVENT_ALL, ui->g_kb_wifi);
	#endif
	lv_obj_set_pos(ui->wifi_ta_wifi_password, 111, 142);
	lv_obj_set_size(ui->wifi_ta_wifi_password, 200, 35);

	//Write style for wifi_ta_wifi_password, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->wifi_ta_wifi_password, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->wifi_ta_wifi_password, &lv_font_Source_Han_Serif_SC_Light_Light_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->wifi_ta_wifi_password, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->wifi_ta_wifi_password, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->wifi_ta_wifi_password, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->wifi_ta_wifi_password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->wifi_ta_wifi_password, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->wifi_ta_wifi_password, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->wifi_ta_wifi_password, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->wifi_ta_wifi_password, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->wifi_ta_wifi_password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->wifi_ta_wifi_password, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->wifi_ta_wifi_password, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->wifi_ta_wifi_password, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifi_ta_wifi_password, 5, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for wifi_ta_wifi_password, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->wifi_ta_wifi_password, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->wifi_ta_wifi_password, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->wifi_ta_wifi_password, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifi_ta_wifi_password, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes wifi_btn_enter
	ui->wifi_btn_enter = lv_btn_create(ui->wifi);
	ui->wifi_btn_enter_label = lv_label_create(ui->wifi_btn_enter);
	lv_label_set_text(ui->wifi_btn_enter_label, "连接");
	lv_label_set_long_mode(ui->wifi_btn_enter_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->wifi_btn_enter_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->wifi_btn_enter, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->wifi_btn_enter_label, LV_PCT(100));
	lv_obj_set_pos(ui->wifi_btn_enter, 239, 192);
	lv_obj_set_size(ui->wifi_btn_enter, 55, 35);

	//Write style for wifi_btn_enter, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->wifi_btn_enter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->wifi_btn_enter, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->wifi_btn_enter, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->wifi_btn_enter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifi_btn_enter, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->wifi_btn_enter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->wifi_btn_enter, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->wifi_btn_enter, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->wifi_btn_enter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->wifi_btn_enter, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for wifi_btn_enter, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_bg_opa(ui->wifi_btn_enter, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_color(ui->wifi_btn_enter, lv_color_hex(0xD01FBB), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_grad_dir(ui->wifi_btn_enter, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_border_width(ui->wifi_btn_enter, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_radius(ui->wifi_btn_enter, 5, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->wifi_btn_enter, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->wifi_btn_enter, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->wifi_btn_enter, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->wifi_btn_enter, 255, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write codes wifi_list_en
	ui->wifi_list_en = lv_dropdown_create(ui->wifi);
	lv_dropdown_set_options(ui->wifi_list_en, "关闭\n开启");
	lv_obj_set_pos(ui->wifi_list_en, 25, 192);
	lv_obj_set_size(ui->wifi_list_en, 130, 30);

	//Write style for wifi_list_en, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->wifi_list_en, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->wifi_list_en, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->wifi_list_en, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->wifi_list_en, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->wifi_list_en, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->wifi_list_en, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->wifi_list_en, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->wifi_list_en, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->wifi_list_en, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->wifi_list_en, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifi_list_en, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->wifi_list_en, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->wifi_list_en, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->wifi_list_en, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->wifi_list_en, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for &style_wifi_list_en_extra_list_selected_checked
	static lv_style_t style_wifi_list_en_extra_list_selected_checked;
	ui_init_style(&style_wifi_list_en_extra_list_selected_checked);
	
	lv_style_set_border_width(&style_wifi_list_en_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_wifi_list_en_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_wifi_list_en_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_wifi_list_en_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_wifi_list_en_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_wifi_list_en_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_wifi_list_en_extra_list_selected_checked, lv_color_hex(0x00a1b5));
	lv_style_set_bg_grad_dir(&style_wifi_list_en_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->wifi_list_en), &style_wifi_list_en_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_wifi_list_en_extra_list_main_default
	static lv_style_t style_wifi_list_en_extra_list_main_default;
	ui_init_style(&style_wifi_list_en_extra_list_main_default);
	
	lv_style_set_max_height(&style_wifi_list_en_extra_list_main_default, 90);
	lv_style_set_text_color(&style_wifi_list_en_extra_list_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_wifi_list_en_extra_list_main_default, &lv_font_Source_Han_Serif_SC_Light_Light_16);
	lv_style_set_text_opa(&style_wifi_list_en_extra_list_main_default, 255);
	lv_style_set_border_width(&style_wifi_list_en_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_wifi_list_en_extra_list_main_default, 255);
	lv_style_set_border_color(&style_wifi_list_en_extra_list_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_wifi_list_en_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_wifi_list_en_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_wifi_list_en_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_wifi_list_en_extra_list_main_default, lv_color_hex(0x2FDAAE));
	lv_style_set_bg_grad_dir(&style_wifi_list_en_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->wifi_list_en), &style_wifi_list_en_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_wifi_list_en_extra_list_scrollbar_default
	static lv_style_t style_wifi_list_en_extra_list_scrollbar_default;
	ui_init_style(&style_wifi_list_en_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_wifi_list_en_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_wifi_list_en_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_wifi_list_en_extra_list_scrollbar_default, lv_color_hex(0xD01FBB));
	lv_style_set_bg_grad_dir(&style_wifi_list_en_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->wifi_list_en), &style_wifi_list_en_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes wifi_label_1
	ui->wifi_label_1 = lv_label_create(ui->wifi);
	lv_label_set_text(ui->wifi_label_1, "Wi-Fi名称:");
	lv_label_set_long_mode(ui->wifi_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->wifi_label_1, 6, 97);
	lv_obj_set_size(ui->wifi_label_1, 100, 30);

	//Write style for wifi_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->wifi_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifi_label_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->wifi_label_1, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->wifi_label_1, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->wifi_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->wifi_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->wifi_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->wifi_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->wifi_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->wifi_label_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->wifi_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->wifi_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->wifi_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->wifi_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifi_label_2
	ui->wifi_label_2 = lv_label_create(ui->wifi);
	lv_label_set_text(ui->wifi_label_2, "密码:");
	lv_label_set_long_mode(ui->wifi_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->wifi_label_2, 32, 142);
	lv_obj_set_size(ui->wifi_label_2, 48, 28);

	//Write style for wifi_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->wifi_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifi_label_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->wifi_label_2, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->wifi_label_2, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->wifi_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->wifi_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->wifi_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->wifi_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->wifi_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->wifi_label_2, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->wifi_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->wifi_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->wifi_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->wifi_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifi_label_3
	ui->wifi_label_3 = lv_label_create(ui->wifi);
	lv_label_set_text(ui->wifi_label_3, "");
	lv_label_set_long_mode(ui->wifi_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->wifi_label_3, 135, 241);
	lv_obj_set_size(ui->wifi_label_3, 175, 30);

	//Write style for wifi_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->wifi_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->wifi_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->wifi_label_3, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->wifi_label_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifi_label_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->wifi_label_3, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->wifi_label_3, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->wifi_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->wifi_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->wifi_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->wifi_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->wifi_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->wifi_label_3, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->wifi_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->wifi_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->wifi_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->wifi_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifi_label_4
	ui->wifi_label_4 = lv_label_create(ui->wifi);
	lv_label_set_text(ui->wifi_label_4, "当前Wi-Fi IP:");
	lv_label_set_long_mode(ui->wifi_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->wifi_label_4, 5, 241);
	lv_obj_set_size(ui->wifi_label_4, 128, 26);

	//Write style for wifi_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifi_label_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->wifi_label_4, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->wifi_label_4, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->wifi_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->wifi_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->wifi_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->wifi_label_4, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->wifi_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifi_label_5
	ui->wifi_label_5 = lv_label_create(ui->wifi);
	lv_label_set_text(ui->wifi_label_5, "8888");
	lv_label_set_long_mode(ui->wifi_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->wifi_label_5, 135, 280);
	lv_obj_set_size(ui->wifi_label_5, 175, 30);

	//Write style for wifi_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->wifi_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->wifi_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->wifi_label_5, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->wifi_label_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifi_label_5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->wifi_label_5, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->wifi_label_5, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->wifi_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->wifi_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->wifi_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->wifi_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->wifi_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->wifi_label_5, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->wifi_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->wifi_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->wifi_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->wifi_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifi_label_6
	ui->wifi_label_6 = lv_label_create(ui->wifi);
	lv_label_set_text(ui->wifi_label_6, "端口号:");
	lv_label_set_long_mode(ui->wifi_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->wifi_label_6, 36, 278);
	lv_obj_set_size(ui->wifi_label_6, 67, 28);

	//Write style for wifi_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->wifi_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifi_label_6, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->wifi_label_6, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->wifi_label_6, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->wifi_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->wifi_label_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->wifi_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->wifi_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->wifi_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->wifi_label_6, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->wifi_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->wifi_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->wifi_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->wifi_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifi_line_1
	ui->wifi_line_1 = lv_line_create(ui->wifi);
	static lv_point_t wifi_line_1[] ={{320, 0},{0, 0},};
	lv_line_set_points(ui->wifi_line_1, wifi_line_1, 2);
	lv_obj_set_pos(ui->wifi_line_1, 0, 40);
	lv_obj_set_size(ui->wifi_line_1, 320, 2);

	//Write style for wifi_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->wifi_line_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->wifi_line_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->wifi_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->wifi_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifi_label_7
	ui->wifi_label_7 = lv_label_create(ui->wifi);
	lv_label_set_text(ui->wifi_label_7, "Wi-Fi连接设置");
	lv_label_set_long_mode(ui->wifi_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->wifi_label_7, 96, 16);
	lv_obj_set_size(ui->wifi_label_7, 129, 15);

	//Write style for wifi_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->wifi_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifi_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->wifi_label_7, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->wifi_label_7, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->wifi_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->wifi_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->wifi_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->wifi_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->wifi_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->wifi_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->wifi_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->wifi_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->wifi_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->wifi_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifi_label_8
	ui->wifi_label_8 = lv_label_create(ui->wifi);
	lv_label_set_text(ui->wifi_label_8, "当前未连接Wi-Fi");
	lv_label_set_long_mode(ui->wifi_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->wifi_label_8, 10, 45);
	lv_obj_set_size(ui->wifi_label_8, 300, 30);

	//Write style for wifi_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->wifi_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->wifi_label_8, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->wifi_label_8, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->wifi_label_8, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->wifi_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->wifi_label_8, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->wifi_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->wifi_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->wifi_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->wifi_label_8, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->wifi_label_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->wifi_label_8, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->wifi_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->wifi_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->wifi_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->wifi_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of wifi.
	void ui_battery_init(lv_ui *ui,lv_obj_t *obj);
	ui_battery_init(ui,ui->wifi);

	//Update current screen layout.
	lv_obj_update_layout(ui->wifi);

	//Init events for screen.
	events_init_wifi(ui);
}
