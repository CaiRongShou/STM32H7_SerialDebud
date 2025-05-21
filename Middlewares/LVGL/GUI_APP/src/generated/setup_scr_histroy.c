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

void ui_file_init(lv_ui *ui);


void setup_scr_histroy(lv_ui *ui)
{
	//Write codes histroy
	ui->histroy = lv_obj_create(NULL);
	lv_obj_set_size(ui->histroy, 320, 480);
	lv_obj_set_scrollbar_mode(ui->histroy, LV_SCROLLBAR_MODE_OFF);

	//Write style for histroy, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->histroy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->histroy, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->histroy, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes histroy_label_1
	ui->histroy_label_1 = lv_label_create(ui->histroy);
	lv_label_set_text(ui->histroy_label_1, "历史记录");
	lv_label_set_long_mode(ui->histroy_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->histroy_label_1, 96, 16);
	lv_obj_set_size(ui->histroy_label_1, 129, 15);

	//Write style for histroy_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->histroy_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->histroy_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->histroy_label_1, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->histroy_label_1, &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->histroy_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->histroy_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->histroy_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->histroy_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->histroy_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->histroy_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->histroy_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->histroy_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->histroy_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->histroy_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes histroy_line_1
	ui->histroy_line_1 = lv_line_create(ui->histroy);
	static lv_point_t histroy_line_1[] ={{320, 0},{0, 0},};
	lv_line_set_points(ui->histroy_line_1, histroy_line_1, 2);
	lv_obj_set_pos(ui->histroy_line_1, 0, 40);
	lv_obj_set_size(ui->histroy_line_1, 320, 2);

	//Write style for histroy_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_line_width(ui->histroy_line_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_color(ui->histroy_line_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_opa(ui->histroy_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_line_rounded(ui->histroy_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

	ui_file_init(ui);
	//The custom code of histroy.
	void ui_battery_init(lv_ui *ui,lv_obj_t *obj);
	ui_battery_init(ui,ui->histroy);


	//Update current screen layout.
	lv_obj_update_layout(ui->histroy);

	//Init events for screen.
	events_init_histroy(ui);
}
