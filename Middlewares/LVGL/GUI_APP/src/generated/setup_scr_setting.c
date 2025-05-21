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



void setup_scr_setting(lv_ui *ui)
{
	//Write codes setting
	ui->setting = lv_obj_create(NULL);
	lv_obj_set_size(ui->setting, 320, 480);
	lv_obj_set_scrollbar_mode(ui->setting, LV_SCROLLBAR_MODE_OFF);

	//Write style for setting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->setting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->setting, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->setting, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes setting_label_1
	ui->setting_label_1 = lv_label_create(ui->setting);
	lv_label_set_text(ui->setting_label_1, "设置");
	lv_label_set_long_mode(ui->setting_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->setting_label_1, 96, 16);
	lv_obj_set_size(ui->setting_label_1, 129, 15);

	//Write style for setting_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->setting_label_1, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->setting_label_1, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->setting_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->setting_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->setting_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes setting_line_1
	ui->setting_line_1 = lv_line_create(ui->setting);
	static lv_point_t setting_line_1[] ={{320, 0},{0, 0},};
	lv_line_set_points(ui->setting_line_1, setting_line_1, 2);
	lv_obj_set_pos(ui->setting_line_1, 0, 40);
	lv_obj_set_size(ui->setting_line_1, 320, 2);

	//Write style for setting_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->setting_line_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->setting_line_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->setting_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->setting_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes setting_label_2
	ui->setting_label_2 = lv_label_create(ui->setting);
	lv_label_set_text(ui->setting_label_2, "时间校准:       日       时       分");
	lv_label_set_long_mode(ui->setting_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->setting_label_2, 10, 50);
	lv_obj_set_size(ui->setting_label_2, 300, 36);

	//Write style for setting_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->setting_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->setting_label_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->setting_label_2, lv_color_hex(0xFFFF00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->setting_label_2, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->setting_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->setting_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->setting_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->setting_label_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->setting_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->setting_label_2, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->setting_label_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->setting_label_2, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->setting_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->setting_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->setting_label_2, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->setting_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes setting_list_day
	ui->setting_list_day = lv_dropdown_create(ui->setting);
	lv_dropdown_set_options(ui->setting_list_day, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31");
	lv_dropdown_set_symbol(ui->setting_list_day, NULL);
	lv_obj_set_pos(ui->setting_list_day, 96, 53);
	lv_obj_set_size(ui->setting_list_day, 40, 30);

	//Write style for setting_list_day, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->setting_list_day, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->setting_list_day, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->setting_list_day, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->setting_list_day, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->setting_list_day, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->setting_list_day, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->setting_list_day, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->setting_list_day, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->setting_list_day, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->setting_list_day, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->setting_list_day, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->setting_list_day, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->setting_list_day, lv_color_hex(0xD01FBB), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->setting_list_day, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->setting_list_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for &style_setting_list_day_extra_list_selected_checked
	static lv_style_t style_setting_list_day_extra_list_selected_checked;
	ui_init_style(&style_setting_list_day_extra_list_selected_checked);
	
	lv_style_set_border_width(&style_setting_list_day_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_setting_list_day_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_setting_list_day_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_setting_list_day_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_setting_list_day_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_setting_list_day_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_setting_list_day_extra_list_selected_checked, lv_color_hex(0x00a1b5));
	lv_style_set_bg_grad_dir(&style_setting_list_day_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_day), &style_setting_list_day_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_setting_list_day_extra_list_main_default
	static lv_style_t style_setting_list_day_extra_list_main_default;
	ui_init_style(&style_setting_list_day_extra_list_main_default);
	
	lv_style_set_max_height(&style_setting_list_day_extra_list_main_default, 90);
	lv_style_set_text_color(&style_setting_list_day_extra_list_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_setting_list_day_extra_list_main_default, &lv_font_Source_Han_Serif_SC_Light_Light_16);
	lv_style_set_text_opa(&style_setting_list_day_extra_list_main_default, 255);
	lv_style_set_border_width(&style_setting_list_day_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_setting_list_day_extra_list_main_default, 255);
	lv_style_set_border_color(&style_setting_list_day_extra_list_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_setting_list_day_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_setting_list_day_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_setting_list_day_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_setting_list_day_extra_list_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_setting_list_day_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_day), &style_setting_list_day_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_setting_list_day_extra_list_scrollbar_default
	static lv_style_t style_setting_list_day_extra_list_scrollbar_default;
	ui_init_style(&style_setting_list_day_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_setting_list_day_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_setting_list_day_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_setting_list_day_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
	lv_style_set_bg_grad_dir(&style_setting_list_day_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_day), &style_setting_list_day_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes setting_list_hour
	ui->setting_list_hour = lv_dropdown_create(ui->setting);
	lv_dropdown_set_options(ui->setting_list_hour, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23");
	lv_dropdown_set_symbol(ui->setting_list_hour, NULL);
	lv_obj_set_pos(ui->setting_list_hour, 157, 53);
	lv_obj_set_size(ui->setting_list_hour, 40, 30);

	//Write style for setting_list_hour, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->setting_list_hour, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->setting_list_hour, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->setting_list_hour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->setting_list_hour, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->setting_list_hour, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->setting_list_hour, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->setting_list_hour, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->setting_list_hour, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->setting_list_hour, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->setting_list_hour, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->setting_list_hour, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->setting_list_hour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->setting_list_hour, lv_color_hex(0xD01FBB), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->setting_list_hour, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->setting_list_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for &style_setting_list_hour_extra_list_selected_checked
	static lv_style_t style_setting_list_hour_extra_list_selected_checked;
	ui_init_style(&style_setting_list_hour_extra_list_selected_checked);
	
	lv_style_set_border_width(&style_setting_list_hour_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_setting_list_hour_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_setting_list_hour_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_setting_list_hour_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_setting_list_hour_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_setting_list_hour_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_setting_list_hour_extra_list_selected_checked, lv_color_hex(0x00a1b5));
	lv_style_set_bg_grad_dir(&style_setting_list_hour_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_hour), &style_setting_list_hour_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_setting_list_hour_extra_list_main_default
	static lv_style_t style_setting_list_hour_extra_list_main_default;
	ui_init_style(&style_setting_list_hour_extra_list_main_default);
	
	lv_style_set_max_height(&style_setting_list_hour_extra_list_main_default, 90);
	lv_style_set_text_color(&style_setting_list_hour_extra_list_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_setting_list_hour_extra_list_main_default, &lv_font_Source_Han_Serif_SC_Light_Light_16);
	lv_style_set_text_opa(&style_setting_list_hour_extra_list_main_default, 255);
	lv_style_set_border_width(&style_setting_list_hour_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_setting_list_hour_extra_list_main_default, 255);
	lv_style_set_border_color(&style_setting_list_hour_extra_list_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_setting_list_hour_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_setting_list_hour_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_setting_list_hour_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_setting_list_hour_extra_list_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_setting_list_hour_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_hour), &style_setting_list_hour_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_setting_list_hour_extra_list_scrollbar_default
	static lv_style_t style_setting_list_hour_extra_list_scrollbar_default;
	ui_init_style(&style_setting_list_hour_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_setting_list_hour_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_setting_list_hour_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_setting_list_hour_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
	lv_style_set_bg_grad_dir(&style_setting_list_hour_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_hour), &style_setting_list_hour_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes setting_list_min
	ui->setting_list_min = lv_dropdown_create(ui->setting);
	lv_dropdown_set_options(ui->setting_list_min, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39\n40\n41\n42\n43\n44\n45\n46\n47\n48\n49\n50\n51\n52\n53\n54\n55\n56\n57\n58\n59");
	lv_dropdown_set_symbol(ui->setting_list_min, NULL);
	lv_obj_set_pos(ui->setting_list_min, 218, 53);
	lv_obj_set_size(ui->setting_list_min, 40, 30);

	//Write style for setting_list_min, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->setting_list_min, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->setting_list_min, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->setting_list_min, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->setting_list_min, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->setting_list_min, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->setting_list_min, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->setting_list_min, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->setting_list_min, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->setting_list_min, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->setting_list_min, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->setting_list_min, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->setting_list_min, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->setting_list_min, lv_color_hex(0xD01FBB), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->setting_list_min, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->setting_list_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for &style_setting_list_min_extra_list_selected_checked
	static lv_style_t style_setting_list_min_extra_list_selected_checked;
	ui_init_style(&style_setting_list_min_extra_list_selected_checked);
	
	lv_style_set_border_width(&style_setting_list_min_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_setting_list_min_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_setting_list_min_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_setting_list_min_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_setting_list_min_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_setting_list_min_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_setting_list_min_extra_list_selected_checked, lv_color_hex(0x00a1b5));
	lv_style_set_bg_grad_dir(&style_setting_list_min_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_min), &style_setting_list_min_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_setting_list_min_extra_list_main_default
	static lv_style_t style_setting_list_min_extra_list_main_default;
	ui_init_style(&style_setting_list_min_extra_list_main_default);
	
	lv_style_set_max_height(&style_setting_list_min_extra_list_main_default, 90);
	lv_style_set_text_color(&style_setting_list_min_extra_list_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_setting_list_min_extra_list_main_default, &lv_font_Source_Han_Serif_SC_Light_Light_16);
	lv_style_set_text_opa(&style_setting_list_min_extra_list_main_default, 255);
	lv_style_set_border_width(&style_setting_list_min_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_setting_list_min_extra_list_main_default, 255);
	lv_style_set_border_color(&style_setting_list_min_extra_list_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_setting_list_min_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_setting_list_min_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_setting_list_min_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_setting_list_min_extra_list_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_setting_list_min_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_min), &style_setting_list_min_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_setting_list_min_extra_list_scrollbar_default
	static lv_style_t style_setting_list_min_extra_list_scrollbar_default;
	ui_init_style(&style_setting_list_min_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_setting_list_min_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_setting_list_min_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_setting_list_min_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
	lv_style_set_bg_grad_dir(&style_setting_list_min_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_min), &style_setting_list_min_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes setting_label_3
	ui->setting_label_3 = lv_label_create(ui->setting);
	lv_label_set_text(ui->setting_label_3, "通信协议：");
	lv_label_set_long_mode(ui->setting_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->setting_label_3, 10, 101);
	lv_obj_set_size(ui->setting_label_3, 300, 36);

	//Write style for setting_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->setting_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->setting_label_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->setting_label_3, lv_color_hex(0xFFFF00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->setting_label_3, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->setting_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->setting_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->setting_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->setting_label_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->setting_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->setting_label_3, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->setting_label_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->setting_label_3, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->setting_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->setting_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->setting_label_3, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->setting_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes setting_list_serial
	ui->setting_list_serial = lv_dropdown_create(ui->setting);
	lv_dropdown_set_options(ui->setting_list_serial, "TTL\nRS-232\nRS-485");
	lv_dropdown_set_symbol(ui->setting_list_serial, NULL);
	lv_obj_set_pos(ui->setting_list_serial, 139, 104);
	lv_obj_set_size(ui->setting_list_serial, 108, 30);

	//Write style for setting_list_serial, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->setting_list_serial, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->setting_list_serial, &lv_font_Source_Han_Serif_SC_Light_Light_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->setting_list_serial, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->setting_list_serial, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->setting_list_serial, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->setting_list_serial, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->setting_list_serial, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->setting_list_serial, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->setting_list_serial, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->setting_list_serial, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->setting_list_serial, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->setting_list_serial, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->setting_list_serial, lv_color_hex(0xD01FBB), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->setting_list_serial, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->setting_list_serial, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for &style_setting_list_serial_extra_list_selected_checked
	static lv_style_t style_setting_list_serial_extra_list_selected_checked;
	ui_init_style(&style_setting_list_serial_extra_list_selected_checked);
	
	lv_style_set_border_width(&style_setting_list_serial_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_setting_list_serial_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_setting_list_serial_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_setting_list_serial_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_setting_list_serial_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_setting_list_serial_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_setting_list_serial_extra_list_selected_checked, lv_color_hex(0x00a1b5));
	lv_style_set_bg_grad_dir(&style_setting_list_serial_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_serial), &style_setting_list_serial_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_setting_list_serial_extra_list_main_default
	static lv_style_t style_setting_list_serial_extra_list_main_default;
	ui_init_style(&style_setting_list_serial_extra_list_main_default);
	
	lv_style_set_max_height(&style_setting_list_serial_extra_list_main_default, 90);
	lv_style_set_text_color(&style_setting_list_serial_extra_list_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_setting_list_serial_extra_list_main_default, &lv_font_Source_Han_Serif_SC_Light_Light_16);
	lv_style_set_text_opa(&style_setting_list_serial_extra_list_main_default, 255);
	lv_style_set_border_width(&style_setting_list_serial_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_setting_list_serial_extra_list_main_default, 255);
	lv_style_set_border_color(&style_setting_list_serial_extra_list_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_setting_list_serial_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_setting_list_serial_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_setting_list_serial_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_setting_list_serial_extra_list_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_setting_list_serial_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_serial), &style_setting_list_serial_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_setting_list_serial_extra_list_scrollbar_default
	static lv_style_t style_setting_list_serial_extra_list_scrollbar_default;
	ui_init_style(&style_setting_list_serial_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_setting_list_serial_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_setting_list_serial_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_setting_list_serial_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
	lv_style_set_bg_grad_dir(&style_setting_list_serial_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_serial), &style_setting_list_serial_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes setting_label_4
	ui->setting_label_4 = lv_label_create(ui->setting);
	lv_label_set_text(ui->setting_label_4, "默认波特率：");
	lv_label_set_long_mode(ui->setting_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->setting_label_4, 10, 152);
	lv_obj_set_size(ui->setting_label_4, 300, 36);

	//Write style for setting_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->setting_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->setting_label_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->setting_label_4, lv_color_hex(0xFFFF00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->setting_label_4, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->setting_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->setting_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->setting_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->setting_label_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->setting_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->setting_label_4, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->setting_label_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->setting_label_4, 9, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->setting_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->setting_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->setting_label_4, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->setting_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes setting_list_baud
	ui->setting_list_baud = lv_dropdown_create(ui->setting);
	lv_dropdown_set_options(ui->setting_list_baud, "1200\n2400\n4800\n9600\n14400\n19200\n38400\n57600\n115200\n128000\n230400\n256000\n460800\n500000\n512000\n600000\n750000\n921600\n1000000\n1500000\n2000000");
	lv_dropdown_set_symbol(ui->setting_list_baud, NULL);
	lv_obj_set_pos(ui->setting_list_baud, 139, 155);
	lv_obj_set_size(ui->setting_list_baud, 108, 30);

	//Write style for setting_list_baud, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->setting_list_baud, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->setting_list_baud, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->setting_list_baud, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->setting_list_baud, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->setting_list_baud, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->setting_list_baud, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->setting_list_baud, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->setting_list_baud, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->setting_list_baud, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->setting_list_baud, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->setting_list_baud, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->setting_list_baud, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->setting_list_baud, lv_color_hex(0xD01FBB), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->setting_list_baud, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->setting_list_baud, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for &style_setting_list_baud_extra_list_selected_checked
	static lv_style_t style_setting_list_baud_extra_list_selected_checked;
	ui_init_style(&style_setting_list_baud_extra_list_selected_checked);
	
	lv_style_set_border_width(&style_setting_list_baud_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_setting_list_baud_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_setting_list_baud_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_setting_list_baud_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_setting_list_baud_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_setting_list_baud_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_setting_list_baud_extra_list_selected_checked, lv_color_hex(0x00a1b5));
	lv_style_set_bg_grad_dir(&style_setting_list_baud_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_baud), &style_setting_list_baud_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_setting_list_baud_extra_list_main_default
	static lv_style_t style_setting_list_baud_extra_list_main_default;
	ui_init_style(&style_setting_list_baud_extra_list_main_default);
	
	lv_style_set_max_height(&style_setting_list_baud_extra_list_main_default, 90);
	lv_style_set_text_color(&style_setting_list_baud_extra_list_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_setting_list_baud_extra_list_main_default, &lv_font_Source_Han_Serif_SC_Light_Light_16);
	lv_style_set_text_opa(&style_setting_list_baud_extra_list_main_default, 255);
	lv_style_set_border_width(&style_setting_list_baud_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_setting_list_baud_extra_list_main_default, 255);
	lv_style_set_border_color(&style_setting_list_baud_extra_list_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_setting_list_baud_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_setting_list_baud_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_setting_list_baud_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_setting_list_baud_extra_list_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_setting_list_baud_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_baud), &style_setting_list_baud_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_setting_list_baud_extra_list_scrollbar_default
	static lv_style_t style_setting_list_baud_extra_list_scrollbar_default;
	ui_init_style(&style_setting_list_baud_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_setting_list_baud_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_setting_list_baud_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_setting_list_baud_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
	lv_style_set_bg_grad_dir(&style_setting_list_baud_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_baud), &style_setting_list_baud_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes setting_label_5
	ui->setting_label_5 = lv_label_create(ui->setting);
	lv_label_set_text(ui->setting_label_5, "自适应波特率模式：");
	lv_label_set_long_mode(ui->setting_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->setting_label_5, 10, 203);
	lv_obj_set_size(ui->setting_label_5, 300, 36);

	//Write style for setting_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->setting_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->setting_label_5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->setting_label_5, lv_color_hex(0xFFFF00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->setting_label_5, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->setting_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->setting_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->setting_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->setting_label_5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->setting_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->setting_label_5, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->setting_label_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->setting_label_5, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->setting_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->setting_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->setting_label_5, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->setting_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes setting_list_analy
	ui->setting_list_analy = lv_dropdown_create(ui->setting);
	lv_dropdown_set_options(ui->setting_list_analy, "模式0\n模式1\n模式2\n模式3");
	lv_dropdown_set_symbol(ui->setting_list_analy, NULL);
	lv_obj_set_pos(ui->setting_list_analy, 170, 206);
	lv_obj_set_size(ui->setting_list_analy, 108, 30);

	//Write style for setting_list_analy, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->setting_list_analy, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->setting_list_analy, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->setting_list_analy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->setting_list_analy, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->setting_list_analy, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->setting_list_analy, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->setting_list_analy, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->setting_list_analy, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->setting_list_analy, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->setting_list_analy, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->setting_list_analy, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->setting_list_analy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->setting_list_analy, lv_color_hex(0xD01FBB), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->setting_list_analy, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->setting_list_analy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for &style_setting_list_analy_extra_list_selected_checked
	static lv_style_t style_setting_list_analy_extra_list_selected_checked;
	ui_init_style(&style_setting_list_analy_extra_list_selected_checked);
	
	lv_style_set_border_width(&style_setting_list_analy_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_setting_list_analy_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_setting_list_analy_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_setting_list_analy_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_setting_list_analy_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_setting_list_analy_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_setting_list_analy_extra_list_selected_checked, lv_color_hex(0x00a1b5));
	lv_style_set_bg_grad_dir(&style_setting_list_analy_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_analy), &style_setting_list_analy_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_setting_list_analy_extra_list_main_default
	static lv_style_t style_setting_list_analy_extra_list_main_default;
	ui_init_style(&style_setting_list_analy_extra_list_main_default);
	
	lv_style_set_max_height(&style_setting_list_analy_extra_list_main_default, 90);
	lv_style_set_text_color(&style_setting_list_analy_extra_list_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_setting_list_analy_extra_list_main_default, &lv_font_Source_Han_Serif_SC_Light_Light_16);
	lv_style_set_text_opa(&style_setting_list_analy_extra_list_main_default, 255);
	lv_style_set_border_width(&style_setting_list_analy_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_setting_list_analy_extra_list_main_default, 255);
	lv_style_set_border_color(&style_setting_list_analy_extra_list_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_setting_list_analy_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_setting_list_analy_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_setting_list_analy_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_setting_list_analy_extra_list_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_setting_list_analy_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_analy), &style_setting_list_analy_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_setting_list_analy_extra_list_scrollbar_default
	static lv_style_t style_setting_list_analy_extra_list_scrollbar_default;
	ui_init_style(&style_setting_list_analy_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_setting_list_analy_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_setting_list_analy_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_setting_list_analy_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
	lv_style_set_bg_grad_dir(&style_setting_list_analy_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_analy), &style_setting_list_analy_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes setting_label_6
	ui->setting_label_6 = lv_label_create(ui->setting);
	lv_label_set_text(ui->setting_label_6, "自适应波特率：");
	lv_label_set_long_mode(ui->setting_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->setting_label_6, 10, 254);
	lv_obj_set_size(ui->setting_label_6, 300, 36);

	//Write style for setting_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->setting_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->setting_label_6, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->setting_label_6, lv_color_hex(0xFFFF00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->setting_label_6, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->setting_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->setting_label_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->setting_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->setting_label_6, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->setting_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->setting_label_6, lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->setting_label_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->setting_label_6, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->setting_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->setting_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->setting_label_6, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->setting_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes setting_list_baud_star
	ui->setting_list_baud_star = lv_dropdown_create(ui->setting);
	lv_dropdown_set_options(ui->setting_list_baud_star, "关闭\n开启");
	lv_dropdown_set_symbol(ui->setting_list_baud_star, NULL);
	lv_obj_set_pos(ui->setting_list_baud_star, 139, 257);
	lv_obj_set_size(ui->setting_list_baud_star, 108, 30);

	//Write style for setting_list_baud_star, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->setting_list_baud_star, lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->setting_list_baud_star, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->setting_list_baud_star, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->setting_list_baud_star, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->setting_list_baud_star, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->setting_list_baud_star, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->setting_list_baud_star, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->setting_list_baud_star, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->setting_list_baud_star, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->setting_list_baud_star, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->setting_list_baud_star, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->setting_list_baud_star, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->setting_list_baud_star, lv_color_hex(0xD01FBB), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->setting_list_baud_star, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->setting_list_baud_star, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for &style_setting_list_baud_star_extra_list_selected_checked
	static lv_style_t style_setting_list_baud_star_extra_list_selected_checked;
	ui_init_style(&style_setting_list_baud_star_extra_list_selected_checked);
	
	lv_style_set_border_width(&style_setting_list_baud_star_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_setting_list_baud_star_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_setting_list_baud_star_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_setting_list_baud_star_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_setting_list_baud_star_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_setting_list_baud_star_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_setting_list_baud_star_extra_list_selected_checked, lv_color_hex(0x00a1b5));
	lv_style_set_bg_grad_dir(&style_setting_list_baud_star_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_baud_star), &style_setting_list_baud_star_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_setting_list_baud_star_extra_list_main_default
	static lv_style_t style_setting_list_baud_star_extra_list_main_default;
	ui_init_style(&style_setting_list_baud_star_extra_list_main_default);
	
	lv_style_set_max_height(&style_setting_list_baud_star_extra_list_main_default, 90);
	lv_style_set_text_color(&style_setting_list_baud_star_extra_list_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_setting_list_baud_star_extra_list_main_default, &lv_font_Source_Han_Serif_SC_Light_Light_16);
	lv_style_set_text_opa(&style_setting_list_baud_star_extra_list_main_default, 255);
	lv_style_set_border_width(&style_setting_list_baud_star_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_setting_list_baud_star_extra_list_main_default, 255);
	lv_style_set_border_color(&style_setting_list_baud_star_extra_list_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_setting_list_baud_star_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_setting_list_baud_star_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_setting_list_baud_star_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_setting_list_baud_star_extra_list_main_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_setting_list_baud_star_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_baud_star), &style_setting_list_baud_star_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_setting_list_baud_star_extra_list_scrollbar_default
	static lv_style_t style_setting_list_baud_star_extra_list_scrollbar_default;
	ui_init_style(&style_setting_list_baud_star_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_setting_list_baud_star_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_setting_list_baud_star_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_setting_list_baud_star_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
	lv_style_set_bg_grad_dir(&style_setting_list_baud_star_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->setting_list_baud_star), &style_setting_list_baud_star_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//The custom code of setting.
	void ui_battery_init(lv_ui *ui,lv_obj_t *obj);
	ui_battery_init(ui,ui->setting);


	//Update current screen layout.
	lv_obj_update_layout(ui->setting);

	//Init events for screen.
	events_init_setting(ui);
}
