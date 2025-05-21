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



void setup_scr_Serial(lv_ui *ui)
{
	//Write codes Serial
	ui->Serial = lv_obj_create(NULL);
	ui->g_kb_Serial = lv_keyboard_create(ui->Serial);
	lv_obj_add_event_cb(ui->g_kb_Serial, kb_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(ui->g_kb_Serial, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_text_font(ui->g_kb_Serial, &lv_font_Source_Han_Serif_SC_Light_Light_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_size(ui->Serial, 320, 480);
	lv_obj_set_scrollbar_mode(ui->Serial, LV_SCROLLBAR_MODE_OFF);

	//Write style for Serial, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Serial, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Serial, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Serial, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Serial_cb_hex
	ui->Serial_cb_hex = lv_checkbox_create(ui->Serial);
	lv_checkbox_set_text(ui->Serial_cb_hex, "16进制显示");
	lv_obj_set_pos(ui->Serial_cb_hex, 242, 438);

	//Write style for Serial_cb_hex, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->Serial_cb_hex, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Serial_cb_hex, &lv_font_Source_Han_Serif_SC_Light_Light_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Serial_cb_hex, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Serial_cb_hex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Serial_cb_hex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_cb_hex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Serial_cb_hex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Serial_cb_hex, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Serial_cb_hex, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Serial_cb_hex, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_cb_hex, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Serial_cb_hex, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Serial_cb_hex, lv_color_hex(0x000000), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Serial_cb_hex, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes Serial_cb_set
	ui->Serial_cb_set = lv_checkbox_create(ui->Serial);
	lv_checkbox_set_text(ui->Serial_cb_set, "16进制发送");
	lv_obj_set_pos(ui->Serial_cb_set, 242, 459);

	//Write style for Serial_cb_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->Serial_cb_set, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Serial_cb_set, &lv_font_Source_Han_Serif_SC_Light_Light_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Serial_cb_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Serial_cb_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Serial_cb_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_cb_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Serial_cb_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Serial_cb_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Serial_cb_set, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Serial_cb_set, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_cb_set, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Serial_cb_set, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Serial_cb_set, lv_color_hex(0x000000), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Serial_cb_set, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes Serial_label_rtc
	ui->Serial_label_rtc = lv_label_create(ui->Serial);
	lv_label_set_text(ui->Serial_label_rtc, "11/11:00");
	lv_label_set_long_mode(ui->Serial_label_rtc, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Serial_label_rtc, 234, 14);
	lv_obj_set_size(ui->Serial_label_rtc, 42, 12);

	//Write style for Serial_label_rtc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Serial_label_rtc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_label_rtc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Serial_label_rtc, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Serial_label_rtc, &lv_font_Source_Han_Serif_SC_Light_Light_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Serial_label_rtc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Serial_label_rtc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Serial_label_rtc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Serial_label_rtc, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Serial_label_rtc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Serial_label_rtc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Serial_label_rtc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Serial_label_rtc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Serial_label_rtc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Serial_label_rtc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Serial_label_tx_num
	ui->Serial_label_tx_num = lv_label_create(ui->Serial);
	lv_label_set_text(ui->Serial_label_tx_num, "0");
	lv_label_set_long_mode(ui->Serial_label_tx_num, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Serial_label_tx_num, 34, 3);
	lv_obj_set_size(ui->Serial_label_tx_num, 42, 12);

	//Write style for Serial_label_tx_num, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Serial_label_tx_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_label_tx_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Serial_label_tx_num, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Serial_label_tx_num, &lv_font_Source_Han_Serif_SC_Light_Light_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Serial_label_tx_num, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Serial_label_tx_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Serial_label_tx_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Serial_label_tx_num, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Serial_label_tx_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Serial_label_tx_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Serial_label_tx_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Serial_label_tx_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Serial_label_tx_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Serial_label_tx_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Serial_label_rx_num
	ui->Serial_label_rx_num = lv_label_create(ui->Serial);
	lv_label_set_text(ui->Serial_label_rx_num, "0");
	lv_label_set_long_mode(ui->Serial_label_rx_num, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Serial_label_rx_num, 34, 18);
	lv_obj_set_size(ui->Serial_label_rx_num, 42, 12);

	//Write style for Serial_label_rx_num, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Serial_label_rx_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_label_rx_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Serial_label_rx_num, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Serial_label_rx_num, &lv_font_Source_Han_Serif_SC_Light_Light_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Serial_label_rx_num, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Serial_label_rx_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Serial_label_rx_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Serial_label_rx_num, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Serial_label_rx_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Serial_label_rx_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Serial_label_rx_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Serial_label_rx_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Serial_label_rx_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Serial_label_rx_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Serial_ta_1
	ui->Serial_ta_1 = lv_textarea_create(ui->Serial);
	lv_textarea_set_text(ui->Serial_ta_1, "");
	lv_textarea_set_placeholder_text(ui->Serial_ta_1, "");
	lv_textarea_set_password_bullet(ui->Serial_ta_1, "*");
	lv_textarea_set_password_mode(ui->Serial_ta_1, false);
	lv_textarea_set_one_line(ui->Serial_ta_1, false);
	lv_textarea_set_accepted_chars(ui->Serial_ta_1, "");
//	lv_textarea_set_max_length(ui->Serial_ta_1, 128);
	#if LV_USE_KEYBOARD != 0 || LV_USE_ZH_KEYBOARD != 0
		lv_obj_add_event_cb(ui->Serial_ta_1, ta_event_cb, LV_EVENT_ALL, ui->g_kb_Serial);
	#endif
	lv_obj_set_pos(ui->Serial_ta_1, 4, 395);
	lv_obj_set_size(ui->Serial_ta_1, 316, 35);

	//Write style for Serial_ta_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->Serial_ta_1, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Serial_ta_1, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Serial_ta_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Serial_ta_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Serial_ta_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Serial_ta_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Serial_ta_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->Serial_ta_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->Serial_ta_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->Serial_ta_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Serial_ta_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Serial_ta_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Serial_ta_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Serial_ta_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_ta_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Serial_ta_1, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Serial_ta_1, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Serial_ta_1, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Serial_ta_1, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_ta_1, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes Serial_label_1
	ui->Serial_label_1 = lv_label_create(ui->Serial);
	lv_label_set_text(ui->Serial_label_1, "T: ");
	lv_label_set_long_mode(ui->Serial_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Serial_label_1, 5, 4);
	lv_obj_set_size(ui->Serial_label_1, 42, 12);

	//Write style for Serial_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Serial_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Serial_label_1, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Serial_label_1, &lv_font_Source_Han_Serif_SC_Light_Light_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Serial_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Serial_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Serial_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Serial_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Serial_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Serial_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Serial_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Serial_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Serial_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Serial_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Serial_label_2
	ui->Serial_label_2 = lv_label_create(ui->Serial);
	lv_label_set_text(ui->Serial_label_2, "R: ");
	lv_label_set_long_mode(ui->Serial_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Serial_label_2, 5, 18);
	lv_obj_set_size(ui->Serial_label_2, 42, 12);

	//Write style for Serial_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Serial_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Serial_label_2, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Serial_label_2, &lv_font_Source_Han_Serif_SC_Light_Light_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Serial_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Serial_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Serial_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Serial_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Serial_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Serial_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Serial_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Serial_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Serial_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Serial_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Serial_label_3
	ui->Serial_label_3 = lv_label_create(ui->Serial);
	lv_label_set_text(ui->Serial_label_3, "多功能串口调试仪");
	lv_label_set_long_mode(ui->Serial_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Serial_label_3, 101, 8);
	lv_obj_set_size(ui->Serial_label_3, 129, 15);

	//Write style for Serial_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Serial_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Serial_label_3, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Serial_label_3, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Serial_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Serial_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Serial_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Serial_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Serial_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Serial_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Serial_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Serial_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Serial_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Serial_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Serial_label_4
	ui->Serial_label_4 = lv_label_create(ui->Serial);
	lv_label_set_text(ui->Serial_label_4, "");
	lv_label_set_long_mode(ui->Serial_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Serial_label_4, 242, 440);
	lv_obj_set_size(ui->Serial_label_4, 14, 15);

	//Write style for Serial_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Serial_label_4, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->Serial_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->Serial_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->Serial_label_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Serial_label_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Serial_label_4, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Serial_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Serial_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Serial_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Serial_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Serial_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Serial_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Serial_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Serial_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Serial_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Serial_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Serial_label_5
	ui->Serial_label_5 = lv_label_create(ui->Serial);
	lv_label_set_text(ui->Serial_label_5, "");
	lv_label_set_long_mode(ui->Serial_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Serial_label_5, 242, 459);
	lv_obj_set_size(ui->Serial_label_5, 14, 15);

	//Write style for Serial_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Serial_label_5, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->Serial_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->Serial_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->Serial_label_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Serial_label_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Serial_label_5, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Serial_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Serial_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Serial_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Serial_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Serial_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Serial_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Serial_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Serial_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Serial_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Serial_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Serial_btn_send
	ui->Serial_btn_send = lv_btn_create(ui->Serial);
	ui->Serial_btn_send_label = lv_label_create(ui->Serial_btn_send);
	lv_label_set_text(ui->Serial_btn_send_label, "发送");
	lv_label_set_long_mode(ui->Serial_btn_send_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Serial_btn_send_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Serial_btn_send, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Serial_btn_send_label, LV_PCT(100));
	lv_obj_set_pos(ui->Serial_btn_send, 20, 437);
	lv_obj_set_size(ui->Serial_btn_send, 45, 35);

	//Write style for Serial_btn_send, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Serial_btn_send, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Serial_btn_send, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Serial_btn_send, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Serial_btn_send, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_btn_send, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Serial_btn_send, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Serial_btn_send, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Serial_btn_send, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Serial_btn_send, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Serial_btn_send, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Serial_btn_send, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_bg_opa(ui->Serial_btn_send, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_color(ui->Serial_btn_send, lv_color_hex(0xff95f6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_grad_dir(ui->Serial_btn_send, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_border_width(ui->Serial_btn_send, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_radius(ui->Serial_btn_send, 5, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->Serial_btn_send, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->Serial_btn_send, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->Serial_btn_send, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->Serial_btn_send, 255, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write codes Serial_btn_clr
	ui->Serial_btn_clr = lv_btn_create(ui->Serial);
	ui->Serial_btn_clr_label = lv_label_create(ui->Serial_btn_clr);
	lv_label_set_text(ui->Serial_btn_clr_label, "清空");
	lv_label_set_long_mode(ui->Serial_btn_clr_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Serial_btn_clr_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Serial_btn_clr, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Serial_btn_clr_label, LV_PCT(100));
	lv_obj_set_pos(ui->Serial_btn_clr, 105, 437);
	lv_obj_set_size(ui->Serial_btn_clr, 45, 35);

	//Write style for Serial_btn_clr, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Serial_btn_clr, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Serial_btn_clr, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Serial_btn_clr, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Serial_btn_clr, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_btn_clr, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Serial_btn_clr, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Serial_btn_clr, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Serial_btn_clr, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Serial_btn_clr, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Serial_btn_clr, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Serial_btn_clr, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_bg_opa(ui->Serial_btn_clr, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_color(ui->Serial_btn_clr, lv_color_hex(0xff95f6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_grad_dir(ui->Serial_btn_clr, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_border_width(ui->Serial_btn_clr, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_radius(ui->Serial_btn_clr, 5, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->Serial_btn_clr, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->Serial_btn_clr, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->Serial_btn_clr, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->Serial_btn_clr, 255, LV_PART_MAIN|LV_STATE_PRESSED);


	//Write codes Serial_btn_new
	ui->Serial_btn_new = lv_btn_create(ui->Serial);
	ui->Serial_btn_new_label = lv_label_create(ui->Serial_btn_new);
	lv_label_set_text(ui->Serial_btn_new_label, "保存");
	lv_label_set_long_mode(ui->Serial_btn_new_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Serial_btn_new_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Serial_btn_new, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Serial_btn_new_label, LV_PCT(100));
	lv_obj_set_pos(ui->Serial_btn_new, 185, 437);
	lv_obj_set_size(ui->Serial_btn_new, 45, 35);

	//Write style for Serial_btn_new, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Serial_btn_new, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Serial_btn_new, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Serial_btn_new, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Serial_btn_new, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_btn_new, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Serial_btn_new, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Serial_btn_new, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Serial_btn_new, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Serial_btn_new, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Serial_btn_new, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Serial_btn_new, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_bg_opa(ui->Serial_btn_new, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_color(ui->Serial_btn_new, lv_color_hex(0xff95f6), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_bg_grad_dir(ui->Serial_btn_new, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_border_width(ui->Serial_btn_new, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_radius(ui->Serial_btn_new, 5, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->Serial_btn_new, 0, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->Serial_btn_new, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->Serial_btn_new, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->Serial_btn_new, 255, LV_PART_MAIN|LV_STATE_PRESSED);

//Write codes Serial_ta_2
	ui->Serial_ta_2 = lv_textarea_create(ui->Serial);
	lv_textarea_set_text(ui->Serial_ta_2, "");

	lv_obj_set_pos(ui->Serial_ta_2, 2, 49);
	lv_obj_set_size(ui->Serial_ta_2, 316, 341);

	//Write style for Serial_ta_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->Serial_ta_2, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Serial_ta_2, &lv_font_Source_Han_Serif_SC_Light_Light_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Serial_ta_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Serial_ta_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Serial_ta_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Serial_ta_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Serial_ta_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Serial_ta_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Serial_ta_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->Serial_ta_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->Serial_ta_2, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->Serial_ta_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Serial_ta_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Serial_ta_2, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Serial_ta_2, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Serial_ta_2, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_ta_2, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Serial_ta_2, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Serial_ta_2, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Serial_ta_2, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Serial_ta_2, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_ta_2, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	
	//Write codes Serial_line_1
	ui->Serial_line_1 = lv_line_create(ui->Serial);
	static lv_point_t Serial_line_1[] ={{320, 0},{0, 0},};
	lv_line_set_points(ui->Serial_line_1, Serial_line_1, 2);
	lv_obj_set_pos(ui->Serial_line_1, 0, 29);
	lv_obj_set_size(ui->Serial_line_1, 320, 2);

	//Write style for Serial_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->Serial_line_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->Serial_line_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->Serial_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->Serial_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Serial_label_6
	ui->Serial_label_6 = lv_label_create(ui->Serial);
	lv_label_set_text(ui->Serial_label_6, "波特率:");
	lv_label_set_long_mode(ui->Serial_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Serial_label_6, 4, 34);
	lv_obj_set_size(ui->Serial_label_6, 61, 15);

	//Write style for Serial_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Serial_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Serial_label_6, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Serial_label_6, &lv_font_Source_Han_Serif_SC_Light_Light_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Serial_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Serial_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Serial_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Serial_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Serial_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Serial_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Serial_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Serial_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Serial_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Serial_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Serial_label_7
	ui->Serial_label_7 = lv_label_create(ui->Serial);
	lv_label_set_text(ui->Serial_label_7, "115200");
	lv_label_set_long_mode(ui->Serial_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Serial_label_7, 62, 34);
	lv_obj_set_size(ui->Serial_label_7, 75, 15);

	//Write style for Serial_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Serial_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Serial_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Serial_label_7, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Serial_label_7, &lv_font_Source_Han_Serif_SC_Light_Light_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Serial_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Serial_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Serial_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Serial_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Serial_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Serial_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Serial_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Serial_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Serial_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Serial_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

//	//Write codes Serial_btn_1
//	ui->Serial_btn_1 = lv_btn_create(ui->Serial);
//	ui->Serial_btn_1_label = lv_label_create(ui->Serial_btn_1);
//	lv_label_set_text(ui->Serial_btn_1_label, "自动获取波特率");
//	lv_label_set_long_mode(ui->Serial_btn_1_label, LV_LABEL_LONG_WRAP);
//	lv_obj_align(ui->Serial_btn_1_label, LV_ALIGN_CENTER, 0, 0);
//	lv_obj_set_style_pad_all(ui->Serial_btn_1, 0, LV_STATE_DEFAULT);
//	lv_obj_set_width(ui->Serial_btn_1_label, LV_PCT(100));
//	lv_obj_set_pos(ui->Serial_btn_1, 202, 31);
//	lv_obj_set_size(ui->Serial_btn_1, 107, 16);

//	//Write style for Serial_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
//	lv_obj_set_style_bg_opa(ui->Serial_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_set_style_bg_color(ui->Serial_btn_1, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_set_style_bg_grad_dir(ui->Serial_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_set_style_border_width(ui->Serial_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_set_style_radius(ui->Serial_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_set_style_shadow_width(ui->Serial_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_set_style_text_color(ui->Serial_btn_1, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_set_style_text_font(ui->Serial_btn_1, &lv_font_Source_Han_Serif_SC_Light_Light_14, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_set_style_text_opa(ui->Serial_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
//	lv_obj_set_style_text_align(ui->Serial_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

//	//Write style for Serial_btn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
//	lv_obj_set_style_bg_opa(ui->Serial_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
//	lv_obj_set_style_bg_color(ui->Serial_btn_1, lv_color_hex(0xff95f6), LV_PART_MAIN|LV_STATE_PRESSED);
//	lv_obj_set_style_bg_grad_dir(ui->Serial_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
//	lv_obj_set_style_border_width(ui->Serial_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
//	lv_obj_set_style_radius(ui->Serial_btn_1, 5, LV_PART_MAIN|LV_STATE_PRESSED);
//	lv_obj_set_style_shadow_width(ui->Serial_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
//	lv_obj_set_style_text_color(ui->Serial_btn_1, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_PRESSED);
//	lv_obj_set_style_text_font(ui->Serial_btn_1, &lv_font_Source_Han_Serif_SC_Light_Light_14, LV_PART_MAIN|LV_STATE_PRESSED);
//	lv_obj_set_style_text_opa(ui->Serial_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	
	//The custom code of Serial.
	void ui_battery_init(lv_ui *ui,lv_obj_t *obj);
	ui_battery_init(ui,ui->Serial);

	//Update current screen layout.
	lv_obj_update_layout(ui->Serial);

	//Init events for screen.
	events_init_Serial(ui);
}
