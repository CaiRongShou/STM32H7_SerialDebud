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


void history_flie_display(lv_ui *ui);

void setup_scr_file(lv_ui *ui)
{
	//Write codes file
	ui->file = lv_obj_create(NULL);
	lv_obj_set_size(ui->file, 320, 480);
	lv_obj_set_scrollbar_mode(ui->file, LV_SCROLLBAR_MODE_OFF);

	//Write style for file, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->file, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->file, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->file, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	
	//Write codes file_file_ta
	ui->file_file_ta = lv_textarea_create(ui->file);
	lv_textarea_set_text(ui->file_file_ta, "");

	lv_obj_set_pos(ui->file_file_ta, 2, 5);
	lv_obj_set_size(ui->file_file_ta, 314, 470);

	//Write style for file_file_ta, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->file_file_ta, lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->file_file_ta, &lv_font_Source_Han_Serif_SC_Light_Light_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->file_file_ta, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->file_file_ta, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->file_file_ta, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->file_file_ta, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->file_file_ta, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->file_file_ta, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->file_file_ta, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->file_file_ta, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->file_file_ta, lv_color_hex(0x2F92DA), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->file_file_ta, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->file_file_ta, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->file_file_ta, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->file_file_ta, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->file_file_ta, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->file_file_ta, 10, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for file_file_ta, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->file_file_ta, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->file_file_ta, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->file_file_ta, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->file_file_ta, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	
	//The custom code of file.
	void ui_battery_init(lv_ui *ui,lv_obj_t *obj);
	ui_battery_init(ui,ui->file);

	
	//Update current screen layout.
	lv_obj_update_layout(ui->file);
	
	events_init_file(ui);
	
	history_flie_display(ui);
}
