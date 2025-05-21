#ifndef __APP_FATFS_H_
#define __APP_FATFS_H_

#include "fatfs.h"


/* ��������ļ������ļ������� */
#define MAX_FILES 31
#define MAX_NAME_LEN 256

/* �ļ���Ϣ�ṹ�� */
typedef struct {
    char name[MAX_NAME_LEN];
} FileInfo;

extern char file_name_to_rtc[15]; //��ǰʱ���ļ���
extern FileInfo file_list[MAX_FILES];
extern uint16_t file_count;
extern uint16_t file_index;


FRESULT read_root_directory(void);
FRESULT write_to_timestamp_file(char *filename,const char* data, uint32_t len);
/**
  * @brief  ��ȡ�ļ����ݵ�����
  * @param  filename: Ҫ��ȡ���ļ���
  * @param  buffer: �洢���ݵĻ�����
  * @param  buffer_size: ��������С
  * @retval FRESULT: FatFs�������
  */
FRESULT read_file_to_array(const char* filename, 
                          char* buffer, 
                          uint32_t buffer_size);

void serial_data_save_to_file(void);


#endif


 

