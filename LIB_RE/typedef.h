/*********************************************************************************
  *Copyright(C),2010-2025,JINGXING 
  *FileName: Typedef.h
  *Author:  David
  *Version:  A0
  *Date:  2018.01.23
  *Description:  定义所用的数据类型
  *Others:  //其他内容说明
  *Function List:  
  *History:  
 **********************************************************************************/

#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

#include <stdint.h>
#ifdef TRUE
#undef TRUE
#endif
#define TRUE 1

#ifdef FALSE
#undef FALSE
#endif
#define FALSE 0

#ifdef true
#undef true
#endif
#define true 1

#ifdef false
#undef false
#endif
#define false 0

//#if defined(BOOL)
//#else
//typedef int BOOL;
//#endif
//#if defined(bool)
//#else
//#ifndef __GNUG__
//typedef int bool;
//#endif//__GNUG___
//#endif

typedef int8_t	s8;
typedef int16_t	s16;
typedef int32_t	s32;
typedef int64_t	s64;

typedef uint8_t	    u8;
typedef uint16_t	u16;
typedef uint32_t	u32;
typedef uint64_t	u64;

typedef volatile uint8_t    vu8;
typedef volatile uint16_t	vu16;
typedef volatile uint32_t   vu32;
typedef volatile uint64_t	vu64;

typedef int8_t	* ps8;
typedef int16_t	* ps16;
typedef int32_t	* ps32;
typedef int64_t	* ps64;
typedef  uint8_t  *  pu8;
typedef  uint16_t *	 pu16;
typedef  uint32_t *  pu32;
typedef  uint64_t *	 pu64;


typedef    volatile u32   *RP32;
typedef    volatile u16   *RP16;
typedef    volatile u8    *RP8;

typedef u8	BYTE;
typedef u16	WORD;
typedef unsigned long	DWORD;

typedef u8	uchar;
typedef u16	ushort;
typedef unsigned long	ulong;

typedef u32 COLOR_T;

#define     __O     volatile                  /*!< defines 'write only' permissions     */
#define     __IO    volatile                  /*!< defines 'read / write' permissions   */
	    /* Defaine : Picture Color type */

#define KILOBYTES            (1024)
#define MEGABITES            (KILOBYTES * KILOBYTES)
#define GIGABITS             (MEGABITES * KILOBYTES)

#define ALIGN4  __attribute__((__aligned__(4)))

#endif

