#ifndef __APP_FATFS_H_
#define __APP_FATFS_H_

#include "fatfs.h"


/* 定义最大文件数和文件名长度 */
#define MAX_FILES 31
#define MAX_NAME_LEN 256

/* 文件信息结构体 */
typedef struct {
    char name[MAX_NAME_LEN];
} FileInfo;

extern char file_name_to_rtc[15]; //当前时间文件名
extern FileInfo file_list[MAX_FILES];
extern uint16_t file_count;
extern uint16_t file_index;


FRESULT read_root_directory(void);
FRESULT write_to_timestamp_file(char *filename,const char* data, uint32_t len);
/**
  * @brief  读取文件内容到数组
  * @param  filename: 要读取的文件名
  * @param  buffer: 存储数据的缓冲区
  * @param  buffer_size: 缓冲区大小
  * @retval FRESULT: FatFs操作结果
  */
FRESULT read_file_to_array(const char* filename, 
                          char* buffer, 
                          uint32_t buffer_size);

void serial_data_save_to_file(void);


#endif


 

