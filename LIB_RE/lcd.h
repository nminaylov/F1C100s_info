/*********************************************************************************
  *Copyright(C),2010-2025,JINGXING
  *FileName: LCD.H
  *Author:  David
  *Version:  A0
  *Date:  2018.01.23
  *Description:  LCD的驱动文件
                使用此文件必须包含定义下列函数
								vpostLCMInit
								vpostAllocVABufferFromAP
  *Others:  //其他内容说明
  *Function List:
  *History:
   **********************************************************************************/
#ifndef __LCD_H
#define __LCD_H
/**************************************************************************************/
/**************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/**************************************************************************************/
/**************************************************************************************/
#include <stdint.h>
#include "typedef.h"
/**************************************************************************************/

#define COLOR_BYTE           (sizeof(COLOR_T))


#define VARMSIZE LCD.u32VramSize


/**************************************************************************************/
typedef struct {
	u8 u8LcdID;
	char *pcLCDName;
	u16 u16LCDCode;
	u16 u16WHA;
	u8 u8HPW;
	u8 u8HBP;
	u8 u8HFP;
	u16 u16WVA;
	u8 u8VPW;
	u8 u8VBP;
	u8 u8VFP;
	u16 u16LCDSize;
	u32 u32LCDFreq;
	u8  u8LcdMode;
} LCDINFO_STRUCT, *pLCDINFO_STRUCT;

typedef struct {
	const u8 *Module;
	void (* Initialize)(const u8, void *, void *);
	void (* DispVramSwap)(void);
	void (* DrawFore)(void);
	void (* DrawBack)(void);
	u8   (* GetVramSet)(void); //当前Vram标记 0写的是背景 1写的是前景
	u16 u16LcdHor;
	u16 u16LcdVer;
	u16 u16LcdSize;
	u16 u16LcdCode;
	u32 u32VramSize;
	u8 *pcLcdName;
	COLOR_T *pLcdVram0;
	COLOR_T *pLcdVram1;

} LCD_DEV_STRUCT;

extern LCD_DEV_STRUCT LCD;

#define LCD_XMAX LCD.u16LcdHor
#define LCD_YMAX LCD.u16LcdVer
#define pVramBkp LCD.pLcdVram1

#ifdef __cplusplus
}
#endif
/**************************************************************************************/
/**************************************************************************************/
#endif //__LCD_H

