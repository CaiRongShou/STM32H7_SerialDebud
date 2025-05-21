#include "app_define.h"

#include <string.h>
#include "bsp_sd.h"

#include "bsp_rtc.h"


char file_name_to_rtc[]; //当前时间文件名
FileInfo file_list[MAX_FILES];
uint16_t file_count;
uint16_t file_index;

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




FRESULT read_root_directory(void)
{
    FRESULT res;
    DIR dir;
    FILINFO fno;

	file_count = 0;
    
	/* 挂载文件系统 */
    FATFS fs;
    res = f_mount(&fs, "", 1);
    if (res != FR_OK) {
        return res;
    }
		

    /* 打开根目录 */
    res = f_opendir(&dir, "/");
    if (res != FR_OK) {
        f_mount(NULL, "", 0);  // 卸载文件系统
        return res;
    }

    /* 循环读取目录项 */
    for(;;) {
        res = f_readdir(&dir, &fno);
        if (res != FR_OK || fno.fname[0] == 0) break;

        /* 跳过系统文件和空项 */
        if (fno.fname[0] == '.') continue;

        /* 存储文件信息 */
        if (file_count < MAX_FILES) {
            /* 处理长文件名 */
            strncpy(file_list[file_count].name, fno.fname, MAX_NAME_LEN-1);

            file_list[file_count].name[MAX_NAME_LEN-1] = '\0';  // 确保终止符
            file_count++;
        } else {
            break;  // 达到最大文件数限制
        }
    }

    /* 关闭目录*/
    f_closedir(&dir);
    f_mount(NULL, "", 0);

    return FR_OK;
}


/**
  * @brief  以当前时间创建/追加TXT文件
  * @param  data: 要写入的数据缓冲区
  * @param  len: 数据长度（字节）
  * @retval FRESULT: FatFs操作结果
  */
FRESULT write_to_timestamp_file(char *filename,const char* data, uint32_t len)
{
    FRESULT res;
    FIL fil;
    
	/* 挂载文件系统 */
    FATFS fs;
    res = f_mount(&fs, "", 1);
    if (res != FR_OK) {
        return res;
    }
	
    // 打开文件（存在则追加，不存在则创建）
    res = f_open(&fil, filename, FA_WRITE | FA_OPEN_APPEND);
    if(res != FR_OK)
    {
        // 如果文件不存在，尝试创建新文件
        if(res == FR_NO_FILE)
        {
            res = f_open(&fil, filename, FA_WRITE | FA_CREATE_NEW);
        }
        
        if(res != FR_OK)
        {
            return res;
        }
    }

    // 移动文件指针到末尾（确保追加模式）
    res = f_lseek(&fil, f_size(&fil));
    if(res != FR_OK)
    {
        f_close(&fil);
        return res;
    }

    // 写入数据
    UINT bytes_written;
    res = f_write(&fil, data, len, &bytes_written);
    if(res != FR_OK || bytes_written != len)
    {
        f_close(&fil);
        return (res != FR_OK) ? res : FR_DISK_ERR;
    }

    // 关闭文件
    res = f_close(&fil);
    f_mount(NULL, "", 0);
	
    return res;
}

/**
  * @brief  读取文件内容到数组
  * @param  filename: 要读取的文件名
  * @param  buffer: 存储数据的缓冲区
  * @param  buffer_size: 缓冲区大小
  * @retval FRESULT: FatFs操作结果
  */
FRESULT read_file_to_array(const char* filename, 
                          char* buffer, 
                          uint32_t buffer_size)
{
    FRESULT res;
    FIL fil;
    UINT br;
    
	/* 挂载文件系统 */
    FATFS fs;
    res = f_mount(&fs, "", 1);
    if (res != FR_OK) {
        return res;
    }
	
    // 打开文件（只读模式）
    res = f_open(&fil, filename, FA_READ);
    if(res != FR_OK) {
        return res;
    }

    // 获取文件大小
    FSIZE_t file_size = f_size(&fil);

    // 检查缓冲区是否足够
    if(file_size >= buffer_size) {
        f_close(&fil);
        return FR_NOT_ENOUGH_CORE;  // 缓冲区不足
    }

    // 读取文件内容
    res = f_read(&fil, buffer, file_size, &br);
    if(res != FR_OK || br != file_size) {
        f_close(&fil);
        return (res != FR_OK) ? res : FR_DISK_ERR;
    }

    // 添加字符串终止符
    buffer[br] = '\0';

    // 关闭文件
    res = f_close(&fil);
    f_mount(NULL, "", 0);
	
    return res;
}

#define FF_MAX_SS		4096

//	函数：FatFs_GetVolume
//	功能：计算设备的容量，包括总容量和剩余容量

void FatFs_GetVolume(void)	// 计算设备容量
{
	FATFS *fs;		//定义结构体指针
	uint32_t SD_CardCapacity = 0;		//SD卡的总容量
	uint32_t SD_FreeCapacity = 0;		//SD卡空闲容量
	DWORD fre_clust, fre_sect, tot_sect; 	//空闲簇，空闲扇区数，总扇区数

	f_getfree("0:",&fre_clust,&fs);			//获取SD卡剩余的簇

	tot_sect = (fs->n_fatent-2) * fs->csize;	//总扇区数量 = 总的簇 * 每个簇包含的扇区数
	fre_sect = fre_clust * fs->csize;			//计算剩余的可用扇区数	   

	SD_CardCapacity = tot_sect / 2040 / 1024 ;	// SD卡总容量 = 总扇区数 * 512( 每扇区的字节数 ) / 1048576(换算成MB)
	SD_FreeCapacity = fre_sect / 2040 / 1024  ;	//计算剩余的容量，单位为GB
	printf("-------------------获取设备容量信息-----------------\r\n");		
	printf("SD容量: %dGB\r\n",SD_CardCapacity);	
	printf("SD剩余: %dGB\r\n",SD_FreeCapacity);
}

//	函数：FatFs_FileTest
//	功能：进行文件写入和读取测试
//
uint8_t  FatFs_FileTest(void)	//文件创建和写入测试
{
	uint8_t i = 0;
	uint16_t BufferSize = 0;	
	FIL	MyFile;			// 文件对象
	UINT 	MyFile_Num;		//	数据长度
	BYTE 	MyFile_WriteBuffer[] = "STM32H7B0 SD卡 文件系统测试";	//要写入的数据
	BYTE 	MyFile_ReadBuffer[1024];	//要读出的数据
	uint8_t MyFile_Res;    /* Return value for SD */
	
	printf("-------------FatFs 文件创建和写入测试---------------\r\n");
	
	MyFile_Res = f_open(&MyFile,"0:FatFs Test.txt",FA_CREATE_ALWAYS | FA_WRITE);	//打开文件，若不存在则创建该文件
	if(MyFile_Res == FR_OK)
	{
		printf("文件打开/创建成功，准备写入数据...\r\n");
		
		MyFile_Res = f_write(&MyFile,MyFile_WriteBuffer,sizeof(MyFile_WriteBuffer),&MyFile_Num);	//向文件写入数据
		if (MyFile_Res == FR_OK)	
		{
			printf("写入成功，写入内容为：\r\n");
			printf("%s\r\n",MyFile_WriteBuffer);
		}
		else
		{
			printf("文件写入失败，请检查SD卡或重新格式化!\r\n");
			f_close(&MyFile);	  //关闭文件	
			return ERROR;			
		}
		f_close(&MyFile);	  //关闭文件			
	}
	else
	{
		printf("无法打开/创建文件，请检查SD卡或重新格式化!\r\n");
		f_close(&MyFile);	  //关闭文件	
		return ERROR;		
	}
	
	printf("-------------FatFs 文件读取测试---------------\r\n");	
	
	BufferSize = sizeof(MyFile_WriteBuffer)/sizeof(BYTE);									// 计算写入的数据长度
	MyFile_Res = f_open(&MyFile,"0:FatFs Test.txt",FA_OPEN_EXISTING | FA_READ);	//打开文件，若不存在则创建该文件
	MyFile_Res = f_read(&MyFile,MyFile_ReadBuffer,BufferSize,&MyFile_Num);			// 读取文件
	if(MyFile_Res == FR_OK)
	{
		printf("文件读取成功，正在校验数据...\r\n");
		
		for(i=0;i<BufferSize;i++)
		{
			if(MyFile_WriteBuffer[i] != MyFile_ReadBuffer[i])		// 校验数据
			{
				printf("校验失败，请检查SD卡或重新格式化!\r\n");
				f_close(&MyFile);	  //关闭文件	
				return ERROR;
			}
		}
		printf("校验成功，读出的数据为：\r\n");
		printf("%s\r\n",MyFile_ReadBuffer);
	}	
	else
	{
		printf("无法读取文件，请检查SD卡或重新格式化!\r\n");
		f_close(&MyFile);	  //关闭文件	
		return ERROR;		
	}	
	
	f_close(&MyFile);	  //关闭文件	
	return SUCCESS;
}
