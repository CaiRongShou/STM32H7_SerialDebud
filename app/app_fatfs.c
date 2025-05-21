#include "app_fatfs.h"
#include "app_serial.h"
#include <string.h>
#include "gui_guider.h"
#include "dev_sd.h"

#include "rtc.h"

extern EventGroupHandle_t eventgroup_handle;




// 公共事件回调函数
static void common_event_handler(lv_event_t *e) {
    lv_obj_t *target = lv_event_get_target(e);
	
    file_index = (uint32_t)(intptr_t)lv_obj_get_user_data(target);
	
	ui_load_scr_animation(&guider_ui, &guider_ui.file, guider_ui.file_del, &guider_ui.histroy_del, setup_scr_file, LV_SCR_LOAD_ANIM_NONE, 0, 200, false, true);
} 


void ui_file_init(lv_ui *ui)
{
	FRESULT res = read_root_directory();
	if(res == FR_OK)
	{		
		for( int i = 1; i < file_count; i++)
		{
			ui->histroy_btn_1[i] = lv_btn_create(ui->histroy);
			ui->histroy_btn_1_label[i] = lv_label_create(ui->histroy_btn_1[i]);
			lv_label_set_text(ui->histroy_btn_1_label[i], file_list[i].name);
			lv_label_set_long_mode(ui->histroy_btn_1_label[i], LV_LABEL_LONG_WRAP);
			lv_obj_align(ui->histroy_btn_1_label[i], LV_ALIGN_CENTER, 0, 0);
			lv_obj_set_style_pad_all(ui->histroy_btn_1[i], 0, LV_STATE_DEFAULT);
			lv_obj_set_width(ui->histroy_btn_1_label[i], LV_PCT(100));
			lv_obj_set_pos(ui->histroy_btn_1[i], 5, 45 * i + 5);
			lv_obj_set_size(ui->histroy_btn_1[i], 310, 30);

			//Write style for histroy_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
			lv_obj_set_style_bg_opa(ui->histroy_btn_1[i], 255, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_bg_color(ui->histroy_btn_1[i], lv_color_hex(0x2FCADA), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_bg_grad_dir(ui->histroy_btn_1[i], LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_border_width(ui->histroy_btn_1[i], 0, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_radius(ui->histroy_btn_1[i], 5, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_shadow_width(ui->histroy_btn_1[i], 0, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_color(ui->histroy_btn_1[i], lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_font(ui->histroy_btn_1[i], &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_opa(ui->histroy_btn_1[i], 255, LV_PART_MAIN|LV_STATE_DEFAULT);
			lv_obj_set_style_text_align(ui->histroy_btn_1[i], LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

			//Write style for histroy_btn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
			lv_obj_set_style_bg_opa(ui->histroy_btn_1[i], 255, LV_PART_MAIN|LV_STATE_PRESSED);
			lv_obj_set_style_bg_color(ui->histroy_btn_1[i], lv_color_hex(0x2FDA64), LV_PART_MAIN|LV_STATE_PRESSED);
			lv_obj_set_style_bg_grad_dir(ui->histroy_btn_1[i], LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
			lv_obj_set_style_border_width(ui->histroy_btn_1[i], 0, LV_PART_MAIN|LV_STATE_PRESSED);
			lv_obj_set_style_radius(ui->histroy_btn_1[i], 5, LV_PART_MAIN|LV_STATE_PRESSED);
			lv_obj_set_style_shadow_width(ui->histroy_btn_1[i], 0, LV_PART_MAIN|LV_STATE_PRESSED);
			lv_obj_set_style_text_color(ui->histroy_btn_1[i], lv_color_hex(0xffff00), LV_PART_MAIN|LV_STATE_PRESSED);
			lv_obj_set_style_text_font(ui->histroy_btn_1[i], &lv_font_Source_Han_Serif_SC_Light_Light_16, LV_PART_MAIN|LV_STATE_PRESSED);
			lv_obj_set_style_text_opa(ui->histroy_btn_1[i], 255, LV_PART_MAIN|LV_STATE_PRESSED);
			
			// 设置用户数据
			lv_obj_set_user_data(ui->histroy_btn_1[i], (void*)(intptr_t)i);
        
			// 绑定事件
			lv_obj_add_event_cb(ui->histroy_btn_1[i], common_event_handler, LV_EVENT_CLICKED, NULL);
		}
	}
}



void serial_data_save_to_file(void)
{
	//if(serial_event_flag.serial_btn_new_flag == 1) //新建保存的txt文件
	if(xEventGroupWaitBits(eventgroup_handle,SERIAL_NEW_EVENT,pdTRUE,pdTRUE,0) & SERIAL_NEW_EVENT)//发送数据
	{
		//serial_event_flag.serial_btn_new_flag = 0;
		get_rtc_time(&rtcTime);
		sprintf(file_name_to_rtc,"0:%02d_%02d-%02d.txt",rtcTime.date,rtcTime.hour,rtcTime.min);
		write_to_timestamp_file(file_name_to_rtc,(char *)serial_data.asiic_buffer,serial_data_event.asiic_len);
	}
}



void history_flie_display(lv_ui *ui)
{
	read_file_to_array(file_list[file_index].name,(char *)serial_data.asiic_buffer,SERIAL_DATA_SIZE);
	lv_textarea_set_text(ui->file_file_ta,(char *)serial_data.asiic_buffer);
	memset((char *)serial_data.asiic_buffer,0,SERIAL_DATA_SIZE);
}


