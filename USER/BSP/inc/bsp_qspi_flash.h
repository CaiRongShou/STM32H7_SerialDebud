#ifndef _BSP_QSPI_W25Q256_H
#define _BSP_QSPI_W25Q256_H


#include "bsp_init.h"


#define CMD_ENABLE_RESET	0x66
#define CMD_RESET			0x99


#define	CMD_GET_ID			0x9F
#define CMD_GET_UID			0x4B

#define CMD_WRITE_ENABLE	0x06

#define CMD_READ			0xEB
#define CMD_WRITE			0x32
#define CMD_ERASE_SECTOR	0x20
#define CMD_ERASE_BLOCK		0xD8
#define CMD_ERASE_CHIP		0xC7

#define CMD_GET_REG1		0x05
#define CMD_GET_REG2		0x35
#define CMD_GET_REG3		0x15

#define CMD_SET_REG1		0x01
#define CMD_SET_REG2		0x31
#define CMD_SET_REG3		0x11
/***********************************************************************************
  									函数声明
***********************************************************************************/
extern uint8_t bsp_w25qxx_Init();
void bsp_w25qxx_reload(void);
extern uint8_t bsp_w25qxx_Read(uint32_t addr , uint8_t*buff , uint32_t len);
extern uint8_t bsp_w25qxx_EraseSector(uint32_t addr);
extern uint8_t bsp_w25qxx_EraseBlock(uint32_t addr);
extern uint8_t bsp_w25qxx_EraseChip();
extern uint8_t bsp_w25qxx_Write(uint32_t addr , uint8_t*buff , uint32_t len);
extern uint8_t bsp_w25qxx_MemoryMapedEnter();
uint8_t QSPI_QuitMemoryMapped(void);
void bsp_w25qxx_test(void);

#endif

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
