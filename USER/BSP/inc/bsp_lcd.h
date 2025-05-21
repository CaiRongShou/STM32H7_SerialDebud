#ifndef __LCD_H
#define __LCD_H

#include "bsp_init.h"



/////////////////////////////////////用户配置区///////////////////////////////////
//支持横竖屏快速定义切换
#define USE_HORIZONTAL 0  //设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏
//#define SPI_SOFTWARE		//使用软件SPI下开启此宏

//#define SPI_SOFTWARE
#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 320
#define LCD_H 480 

#else
#define LCD_W 480
#define LCD_H 320
#endif

////////////////////////////////////////////////////////////////////
//-----------------LCD端口定义----------------//

#define LCD_CS_Pin GPIO_PIN_6
#define LCD_CS_GPIO_Port GPIOA
#define LCD_RST_Pin GPIO_PIN_4
#define LCD_RST_GPIO_Port GPIOC
#define LCD_DC_Pin GPIO_PIN_5
#define LCD_DC_GPIO_Port GPIOC
#define LCD_BL_Pin GPIO_PIN_0
#define LCD_BL_GPIO_Port GPIOB

#define SPI_CS(n)  HAL_GPIO_WritePin(LCD_CS_GPIO_Port,LCD_CS_Pin,(GPIO_PinState)n)			//片选端口											PA12

#define SPI_SDI(n)  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,(GPIO_PinState)n)		//数据输入											PC13

//#define SPI_SDI_RD PCin(13)		//SDA单通道时候 作为数据输出		PC13

//#define SPI_SDO PAin(11)			//数据输出									  	PA11

#define SPI_RST(n)  HAL_GPIO_WritePin(LCD_RST_GPIO_Port,LCD_RST_Pin,(GPIO_PinState)n)			//复位  	    		 							PC15

#define SPI_SCK(n)  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,(GPIO_PinState)n)			//时钟													PC14

#define SPI_DC(n)  HAL_GPIO_WritePin(LCD_DC_GPIO_Port,LCD_DC_Pin,(GPIO_PinState)n)			//数据/命令      								PA15   

#define	LCD_LED(n)  HAL_GPIO_WritePin(LCD_BL_GPIO_Port,LCD_BL_Pin,(GPIO_PinState)n) 			//背光 开关                     PA2


//画笔颜色
//画笔颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE           	 0x001F  
#define BRED             0XF81F
#define GRED 			       0XFFE0
#define GBLUE			       0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			     0XBC40 //棕色
#define BRRED 			     0XFC07 //棕红色
#define GRAY  			     0X8430 //灰色
#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色
#define LIGHTGREEN     	 0X841F //浅绿色
#define LGRAY 			     0XC618 //浅灰色(PANNEL),窗体背景色
#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)

/////////////////////////////////////用户配置区///////////////////////////////////
//支持横竖屏快速定义切换
#define USE_TP_TYPE   	CTP 	//定义触摸类型  CTP = 电容模式 , RTP = 电阻模式

#define CTP 0X80		//电容模式
#define RTP 0X00		//电阻模式

//LCD重要参数集
typedef struct
{
    u16 width;			//LCD 宽度
    u16 height;			//LCD 高度
    u16 id;				//LCD ID
    u8  dir;			//横屏还是竖屏控制：0，竖屏；1，横屏。
    u16	wramcmd;		//开始写gram指令
    u16 setxcmd;		//设置x坐标指令
    u16  setycmd;		//设置y坐标指令
} _lcd_dev;

//LCD参数
extern _lcd_dev lcddev;	//管理LCD重要参数
//LCD的画笔颜色和背景色
extern u16  POINT_COLOR;//默认红色
extern u16  BACK_COLOR; //背景颜色.默认为白色

void lcd_init(void);
void LCD_DisplayOn(void);
void LCD_DisplayOff(void);
void LCD_Display_Dir(u8 dir);
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2);
void LCD_Color_Fill(uint16_t xsta, uint16_t ysta, uint16_t xend, uint16_t yend, uint16_t color_p);
//void LCD_Color_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color);
/******************************************************************************
      函数说明：在指定区域填充颜色
      入口数据：xsta,ysta   起始坐标
                xend,yend   终止坐标
								color       要填充的颜色
      返回值：  无
******************************************************************************/
void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color);


#endif  /*__LCD_H*/














