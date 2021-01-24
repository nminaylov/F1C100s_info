#ifndef __DEVICEINFO_H
#define __DEVICEINFO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "usertype.h"
#include "lcd.h"
#include "rtc.h"
#include "systick.h"
#include "pwm.h"
#include "flash.h"
#include "raminfo.h"
#include "reginfo.h"
#include "index.h"
	
	
	
#ifdef DISPLAY_TRANSFORMATION
#define HORZONTAL                 ((ORIENTATION_VER) ? LCD.u16LcdVer : LCD.u16LcdHor)
#define VERTIACAL                 ((ORIENTATION_VER) ? LCD.u16LcdHor : LCD.u16LcdVer)

#define IncHor_H                  ((ORIENTATION_VER) ? LCD.u16LcdHor : 1)
#define IncHor_V                  ((ORIENTATION_VER) ? 1 : LCD.u16LcdHor)
#else
#define HORZONTAL                  LCD.u16LcdHor
#define VERTIACAL                  LCD.u16LcdVer
#endif

#define VRAMAREA0                    LCD.pLcdVram0
#define VRAMAREA1                    LCD.pLcdVram1
#define VRAMAREA2                    ((COLOR_T *)VRAM_AREA_BASE_ADDR2)
#define VRAMAREA3                    ((COLOR_T *)VRAM_AREA_BASE_ADDR3)

#define VARMSIZE                     LCD.u32VramSize
#define LcdDisplay()                 LCD.Display()
#define LcdForeDisplay(A)            LCD.ForeDisplay(A)
#define DRAWFORE()                   LCD.DrawFore()
#define DRAWBACK()                   LCD.DrawBack()

#define SysRtcSet(A)                 RTC.Set(A)
#define SysRtcGet(A)                 RTC.Read(A)
#define SysRtcReNew()                RTC.ReNew()

#define SysTickC                     Tick.Read()
#define SYSTEM_RUN_SEC               (Tick.Read() / 100)
#define SECONDS_NUM                  (60)
#define MINUTES_NUM                  (60)
#define SECONDS_PER_HOUR             (SECONDS_NUM * MINUTES_NUM)
#define SYSTEM_RUN_TIME              (((SYSTEM_RUN_SEC / SECONDS_PER_HOUR)               << 16) | \
	                                    ((SYSTEM_RUN_SEC % SECONDS_PER_HOUR / MINUTES_NUM) <<  8) | \
	                                    ((SYSTEM_RUN_SEC % SECONDS_PER_HOUR % SECONDS_NUM) <<  0) )
#define SysTimeC                     Tick.Read4ms()

#define BackLightLm(A)               PWM4LCD.SetLM(A)
#define BACKLIGHT_LM_MAX             (0x3F)
#define BackLightOn()                PWM4LCD.On()
#define BackLightOff()               PWM4LCD.Off()

#define BeepOn()                     PWM4Buzzer.On()
#define BeepOff()                    PWM4Buzzer.Off()

#define HORZONTAL_MAX                (1024)
#define VERTIACAL_MAX                (768)

#define REFRESH_TIME3                ( 8)
#define REFRESH_TIME2                (12)
#define REFRESH_TIME1                (16)
#define REFRESH_TIME0                (20)
#define REFRESH_ENABLE               (SYSTEM_INFO->SysConfig & 0x03)
#define REFRESH_TIME                ((0 == REFRESH_ENABLE) ? REFRESH_TIME0 : \
	                                  ((1 == REFRESH_ENABLE) ? REFRESH_TIME1 : \
	                                  ((2 == REFRESH_ENABLE) ? REFRESH_TIME2 : REFRESH_TIME3)))

#ifdef DISPLAY_TRANSFORMATION
#define ORIENTATION_VALUE         (SYSTEM_INFO->SysConfig & 0xC0)
#define ORIENTATION_VER           (0x80 == (SYSTEM_INFO->SysConfig & 0x80))
#define ORIENTATION_0             (0x00 == ORIENTATION_VALUE)
#define ORIENTATION_90            (0x80 == ORIENTATION_VALUE)
#define ORIENTATION_180           (0x40 == ORIENTATION_VALUE)
#define ORIENTATION_270           (0xC0 == ORIENTATION_VALUE)

#define likely(A)                 (A)
#define unlikely(A)               (!A)
#endif

//=============================================================================================================
//
//                        Flash 内存空间分配
//
//=============================================================================================================
    /* System Base Info */
#define SYSTEM_INFO_AMOUNT           (2)
#define SYSTEM_INFO_BY_FLASH_BLOCK   (1)
#define SYSTEM_INFO_BLOCK_AMOUT      (SYSTEM_INFO_BY_FLASH_BLOCK * SYSTEM_INFO_AMOUNT)

    /* System Config Info */
#define SYSTEM_INFO_SIZE             (2048)
    extern  char sys_cfg_info[SYSTEM_INFO_SIZE];
#define SYSTEM_INFO_ADDR            ((u32)sys_cfg_info)
#define SYSTEM_INFO                 ((DEVINFO_STRUCT *)SYSTEM_INFO_ADDR)
#define BOOTVERSION                (*(const u32 *)(0x02F0))

    /* memory: System Register */
extern  SYS_REGISTER_STRUCT           sys_cfg_reg;
#define SYS_REGISTER_SIZE             (sizeof(SYS_REGISTER_STRUCT))
#define SYS_REGISTER_ADDR            ((u32)&sys_cfg_reg)
#define REGISTER                     ((SYS_REGISTER_STRUCT *)SYS_REGISTER_ADDR)

    /* Font Library Info */
#define FONT_LIBRARY_AMOUNT          (128)
#define FONT_LIBRARY_SIZE            (256 * KILOBYTES)   /* 256KB per font library */
#define FONT_LIBRARY_BYTE            (FONT_LIBRARY_SIZE) /* 0x04 00 00 */
#define FONT_LIBRARY_WORD            (FONT_LIBRARY_SIZE / 2)
#define FONT_LIBRARY_BY_FLASH_PAGE  ((FONT_LIBRARY_SIZE + USER_PAGE_SIZE - 1) / USER_PAGE_SIZE)
#define FONT_LIBRARY_PAGE_AMOUT      (FONT_LIBRARY_BY_FLASH_PAGE * FONT_LIBRARY_AMOUNT)


    /* Picture Basic Info */
#define PICTURE_SIZE                 (VARMSIZE) //1024*768*2
#define MEMORY_PAGE_PER_PICTURE      ((PICTURE_SIZE + USER_PAGE_SIZE - 1) / USER_PAGE_SIZE) //375
#define MEMORY_BLOCK_PER_PICTURE     ((MEMORY_PAGE_PER_PICTURE + FLASH_PAGE_BY_BLOCK - 1) / FLASH_PAGE_BY_BLOCK) //6
#define SPACE_PER_PICTURE            (MEMORY_BLOCK_PER_PICTURE * FLASH_PAGE_BY_BLOCK)//384
#define PICTURE_PAGE_AMOUNT          (((USER_BLOCK_NUM - FLASH_BAD_BLOCK_AMOUT - SYSTEM_INFO_BLOCK_AMOUT) * FLASH_PAGE_BY_BLOCK) - FONT_LIBRARY_PAGE_AMOUT)
#define PICTURE_AMOUNT               (PICTURE_PAGE_AMOUNT / SPACE_PER_PICTURE)

    /* DataBase Basic info */
#define DATABASE_SIZE                (64 * MEGABITES)
#define DATABASE_PAGE                ((DATABASE_SIZE + USER_PAGE_SIZE - 1) / USER_PAGE_SIZE)


/* Audio Basic info */
#define WAV_AUDIO_SIZES              (8 * MEGABITES)
#define WAV_AUDIO_NUMS               (128)
#define WAV_AUDIO_SIZES_BY_NUM      ((WAV_AUDIO_SIZES + WAV_AUDIO_NUMS - 1) / WAV_AUDIO_NUMS)    /* 64KB/段 */
#define MEMORY_PAGE_PER_WAV         ((WAV_AUDIO_SIZES_BY_NUM + USER_PAGE_SIZE) / USER_PAGE_SIZE) /* 32(16)页/段 */
#define WAV_AUDIO_PAGE_AMOUNT       ((WAV_AUDIO_SIZES + USER_PAGE_SIZE - 1) / USER_PAGE_SIZE)    /* 4096(2048)页/128段 */

#define DATABASE_BASE_ADDR           ((32+64) * MEGABITES/*(64 * MEGABITES / USER_PAGE_SIZE) * FLASH_PAGE_SIZE*/)
#define DATABASE_PAGE_ADDR           (DATABASE_BASE_ADDR / FLASH_PAGE_ADDR)     /* 32768 0x8000 */
#define DATABASEBLOCK_ADDR           (DATABASE_PAGE_ADDR / FLASH_PAGE_BY_BLOCK) /* 512   0x200  */
#define DATABASE_BASE_SIZE           (0x3D00000 /* 61MB * FLASH_DEVICES */)//(0x1E000000/* 480MB */)
#define DATABASE_INDEX_SIZE          (DATABASE_BLOCK)
#define DATABASE_INDEX_PAGE          (DATABASE_INDEX_SIZE / USER_PAGE_SIZE)
#define DATABASE_INDEX_NUM           (DATABASE_BASE_SIZE / DATABASE_INDEX_SIZE)


    /* Define : Flash Space Addr */
#define FLASH_BAD_BLOCK_START_PAGE   (FLASH_START_PAGE) /* 128 */
#define SYSTEM_INFO_START_PAGE       (FLASH_BAD_BLOCK_START_PAGE + FLASH_BAD_BLOCK_AMOUT * FLASH_PAGE_BY_BLOCK) /* 256 */
#define FONT_LIBRARY_START_PAGE      (SYSTEM_INFO_START_PAGE + SYSTEM_INFO_BLOCK_AMOUT * FLASH_PAGE_BY_BLOCK) /* 320 */
#define PICTURE_START_PAGE           (FONT_LIBRARY_START_PAGE + FONT_LIBRARY_PAGE_AMOUT) /* 16704 (8512)*/
#define DATABASE_START_PAGE          (USER_BLOCK_NUM * FLASH_PAGE_BY_BLOCK - DATABASE_PAGE)
#define WAV_START_PAGE         (USER_BLOCK_NUM * FLASH_PAGE_BY_BLOCK - WAV_AUDIO_PAGE_AMOUNT)  

//=============================================================================================================
//
//                        SDRAM 内存空间分配
//
//=============================================================================================================
#define FLOOR_SPACE_SIZE             (32) //定义各块之间的间隔字节数
    /* memory : base address allocation */
#define SCREEN_SIZE_MAXVALUE         (1024*768*2) /* 0x180000 */
#define VRAM_AREA_FLOOR_NUM          (4)
#define VRAM_AREA_BASE_ADDR0         (EXTERNAL_MEMORY_ADDR0) /* 0x0010 0000 */
#define VRAM_AREA_BASE_ADDR1         (VRAM_AREA_BASE_ADDR0  + SCREEN_SIZE_MAXVALUE) /* 0x0028 0000 */
#define VRAM_AREA_BASE_ADDR2         (VRAM_AREA_BASE_ADDR1  + SCREEN_SIZE_MAXVALUE) /* 0x0040 0000 */
#define VRAM_AREA_BASE_ADDR3         (VRAM_AREA_BASE_ADDR2  + SCREEN_SIZE_MAXVALUE) /* 0X0058 0000 */

    /* memory : Variable Space */
#ifdef _USER_V28KW
    #define VARIABLE_SIZE              ( 56 * KILOBYTES)
#elif _USER_V64KW
    #define VARIABLE_SIZE              (128 * KILOBYTES)    
#else
    #error "Plesae set Variable space size : 28K word[_USER_V28KW] or 64K word[_USER_V64KW]!"
#endif

#define VARIABLE_SIZE_BYTE           (VARIABLE_SIZE) /* 0x0002 0000 */
#define VARIABLE_SIZE_WORD           (VARIABLE_SIZE_BYTE / 2) /*0x0001 0000 */
#define VARIABLE_SPACE_ADDR          (VRAM_AREA_BASE_ADDR0 + SCREEN_SIZE_MAXVALUE * VRAM_AREA_FLOOR_NUM) /* 0X0070 0000 */

    /* memory : Curve data buffer */
#define CURVE_CHANNEL_NUM            (8)
#define CURVE_BUFFER_SIZE            (16 * KILOBYTES) /* 0x0000 4000 */
#define CURVE_CHANEL_SIZE            (CURVE_BUFFER_SIZE / CURVE_CHANNEL_NUM) /* 0x800 */
#define CURVE_BUFFER_ADDR            (VARIABLE_SPACE_ADDR + (128 * KILOBYTES) + FLOOR_SPACE_SIZE) /* 0x0072 0000*/

    /* memory : Variable Opreation Info */
#define VARIABLE_INFO_SIZE           (4 * KILOBYTES) /* 0x0000 1000 */
#define VARIABLE_INFO_ADDR           (CURVE_BUFFER_ADDR + CURVE_BUFFER_SIZE + FLOOR_SPACE_SIZE) /*0x0072 4000 */

    /* memory : Touch Opreation Info */
#define TOUCH_OPINFO_SIZE            (256 * KILOBYTES) /* 0x0004 0000 */
#define TOUCH_OPINFO_ADDR            (VARIABLE_INFO_ADDR + VARIABLE_INFO_SIZE + FLOOR_SPACE_SIZE) /* 0x0072 5000 */

    /* memory : the WordBank of GBK-Method */
#define METHOD_INDEX_SIZE            (IEXICON_FILE_SIZE) /* 0x0004 0000 */
#define METHOD_INDEX_ADDR            (TOUCH_OPINFO_ADDR + TOUCH_OPINFO_SIZE + FLOOR_SPACE_SIZE) /* 0x0076 5000  */

//#define VOS_BASE_ADDR                (METHOD_INDEX_ADDR + IEXICON_FILE_SIZE + FLOOR_SPACE_SIZE) /* 0x007A 5000 */

    /* memory : Database Opreation */
#define DATABASE_BLOCK               (FLASH_PAGE_BY_BLOCK * USER_PAGE_SIZE)
#define DATABASE_SIZES               (FLASH_PAGE_BY_BLOCK * FLASH_PAGE_SIZE * 2) /* 0x0004 0000 */
//  #define DATABASE_BUFFER_ADDR         (EXTERNAL_MEMORY_ADDR0 + EXTERNAL_MEMORY_SIZE0 - DATABASE_SIZES) /* 0x007C 0000*/
#define DATABASE_BUFFER_ADDR           (METHOD_INDEX_ADDR + METHOD_INDEX_SIZE + FLOOR_SPACE_SIZE) /* 0x0076 5000  */

#if(DATABASE_BUFFER_ADDR +  DATABASE_SIZES > 0x800000)
  #error "SDRAM  overflow!!!"
#endif

//注意此处的cache功能分配地址与第三显存重叠，只能在读取SD卡文件时使用CACHE读写功能，并立即flushCache
#define BLOCK_SIZE                   (FLASH_PAGE_BY_BLOCK * USER_PAGE_SIZE)
#define R_CACHE_BY_BLOCK             (1)
#define RW_CACHE_BY_BLOCK            (4)
#define NAND_CACHE_SIZE             ((RW_CACHE_BY_BLOCK + R_CACHE_BY_BLOCK) * DATABASE_SIZES/*USER_BLOCK_SIZE*/)
#define NAND_CACHE_ADDR             (VRAM_AREA_BASE_ADDR3) /*(DATABASE_BUFFER_ADDR - NAND_CACHE_SIZE)*/

// #ifdef _CLIBRARY_ENABLE
// 			/* memory : User memory area 0 */
// 	#define USER_MEMORY_ADDR0          (METHOD_INDEX_ADDR + METHOD_INDEX_SIZE + FLOOR_SPACE_SIZE)
// 	#define USER_MEMORY_SZIE0          (FONT_ASCII_ADDR - USER_MEMORY_ADDR0 - FLOOR_SPACE_SIZE)

// 	#include "font_config.h"
// 			/* memory : User memory area 1 */
// 	#define USER_MEMORY_ADDR1          (SYSTEM_RUN_ADDR + SYSTEM_RUN_SIZE + FLOOR_SPACE_SIZE)
// 	#define USER_MEMORY_SZIE1          (DATABASE_BUFFER_ADDR - USER_MEMORY_ADDR1)
// #endif


#ifdef __cplusplus
}

#endif

#endif /* __DEVICEINFO_H */
