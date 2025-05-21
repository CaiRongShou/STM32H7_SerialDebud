/*
* Copyright 2025 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *Serial;
	bool Serial_del;
	lv_obj_t *g_kb_Serial;
	lv_obj_t *Serial_cb_hex;
	lv_obj_t *Serial_cb_set;
	lv_obj_t *Serial_label_rtc;
	lv_obj_t *Serial_label_tx_num;
	lv_obj_t *Serial_label_rx_num;
	lv_obj_t *Serial_ta_1;
	lv_obj_t *Serial_label_1;
	lv_obj_t *Serial_label_2;
	lv_obj_t *Serial_label_3;
	lv_obj_t *Serial_label_4;
	lv_obj_t *Serial_label_5;
	lv_obj_t *Serial_btn_send;
	lv_obj_t *Serial_btn_send_label;
	lv_obj_t *Serial_btn_clr;
	lv_obj_t *Serial_btn_clr_label;
	lv_obj_t *Serial_btn_new;
	lv_obj_t *Serial_btn_new_label;
	lv_obj_t *Serial_ta_2;
	lv_obj_t *Serial_img_1;
	lv_obj_t *Serial_line_1;
	lv_obj_t *Serial_label_6;
	lv_obj_t *Serial_label_7;
	lv_obj_t *setting;
	bool setting_del;
	lv_obj_t *setting_label_1;
	lv_obj_t *setting_line_1;
	lv_obj_t *setting_label_2;
	lv_obj_t *setting_list_day;
	lv_obj_t *setting_list_hour;
	lv_obj_t *setting_list_min;
	lv_obj_t *setting_label_3;
	lv_obj_t *setting_list_serial;
	lv_obj_t *setting_label_4;
	lv_obj_t *setting_list_baud;
	lv_obj_t *setting_label_5;
	lv_obj_t *setting_list_analy;
	lv_obj_t *setting_label_6;
	lv_obj_t *setting_list_baud_star;
	lv_obj_t *menu;
	bool menu_del;
	lv_obj_t *menu_label_1;
	lv_obj_t *menu_btn_menu_serial;
	lv_obj_t *menu_btn_menu_serial_label;
	lv_obj_t *menu_btn_menu_set;
	lv_obj_t *menu_btn_menu_set_label;
	lv_obj_t *menu_btn_menu_histroy;
	lv_obj_t *menu_btn_menu_histroy_label;
	lv_obj_t *menu_line_1;
	lv_obj_t *menu_btn_wifi;
	lv_obj_t *menu_btn_wifi_label;
	lv_obj_t *histroy;
	bool histroy_del;
	lv_obj_t *histroy_label_1;
	lv_obj_t *histroy_line_1;
	lv_obj_t *histroy_btn_1[31];
	lv_obj_t *histroy_btn_1_label[31];
	lv_obj_t *wifi;
	bool wifi_del;
	lv_obj_t *g_kb_wifi;
	lv_obj_t *wifi_ta_wifi_name;
	lv_obj_t *wifi_ta_wifi_password;
	lv_obj_t *wifi_btn_enter;
	lv_obj_t *wifi_btn_enter_label;
	lv_obj_t *wifi_list_en;
	lv_obj_t *wifi_label_1;
	lv_obj_t *wifi_label_2;
	lv_obj_t *wifi_label_3;
	lv_obj_t *wifi_label_4;
	lv_obj_t *wifi_label_5;
	lv_obj_t *wifi_label_6;
	lv_obj_t *wifi_line_1;
	lv_obj_t *wifi_label_7;
	lv_obj_t *wifi_label_8;
	lv_obj_t *file;
	bool file_del;
	lv_obj_t * file_file_ta;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_move_animation(void * var, int32_t duration, int32_t delay, int32_t x_end, int32_t y_end, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_scale_animation(void * var, int32_t duration, int32_t delay, int32_t width, int32_t height, lv_anim_path_cb_t path_cb,
                        uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                        lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_zoom_animation(void * var, int32_t duration, int32_t delay, int32_t zoom, lv_anim_path_cb_t path_cb,
                           uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                           lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_rotate_animation(void * var, int32_t duration, int32_t delay, lv_coord_t x, lv_coord_t y, int32_t rotate,
                   lv_anim_path_cb_t path_cb, uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time,
                   uint32_t playback_delay, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_Serial(lv_ui *ui);
void setup_scr_setting(lv_ui *ui);
void setup_scr_menu(lv_ui *ui);
void setup_scr_histroy(lv_ui *ui);
void setup_scr_wifi(lv_ui *ui);
void setup_scr_file(lv_ui *ui);

LV_FONT_DECLARE(lv_font_Source_Han_Serif_SC_Light_Light_10)
LV_FONT_DECLARE(lv_font_Source_Han_Serif_SC_Light_Light_14)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_16)
LV_FONT_DECLARE(lv_font_Source_Han_Serif_SC_Light_Light_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_12)
LV_IMG_DECLARE(_00_alpha_16x16);
LV_IMG_DECLARE(_11_alpha_16x16);
LV_IMG_DECLARE(_22_alpha_16x16);
LV_IMG_DECLARE(_33_alpha_16x16);
LV_IMG_DECLARE(_xx_alpha_16x16);


#ifdef __cplusplus
}
#endif
#endif
