/*
 * File						: Font.h
 * Description		: This file is iBoard Font header.
 * Author					: XiaomaGee@Gmail.com
 * Copyright			:
 *
 * History
 *----------------
 * Rev						: 0.00
 * Date						: 07/29/2012
 *
 * create.
 *----------------
 */


#ifndef __font_h__
#define __font_h__

#include "typedef.h"
//---------------- Include Files ------------------------//


//----------------- Define ------------------------------//
#define	LANGUAGE_EN	0
#define	LANGUAGE_CN	1

#define	DIRECTION_H	0
#define	DIRECTION_V	1

#define	FONT_UNREGISTERED	99

#define	EFFECT_NONE	0
#define	EFFECT_INVERSE	1

#ifndef max
#define max(a,b)	(a>b?a:b)
#endif

#ifndef min
#define	min(a,b)	(a>b?b:a)
#endif

//----------------- Data Struct -------------------------//
typedef struct _FONT_MATRIX {
	unsigned char character[2];	//字体编码数组
	char direction;							 	//点阵显示方向
	unsigned short height;									 	//点阵高度
	unsigned short width;									 	//点阵宽度
	char const *dat;					 	//点阵信息在字库中的首地址
} FONT_MATRIX_T;				 				 	//定义字体点阵类型变量

typedef	struct	_SINGLE_BYTE_FONT {
	char *name;				 						//单字节字体类型的名称
	char id;				 	  //字体在单字节字体链表内的偏移量
	unsigned short	height;
	unsigned short width; //width!=0 is monospaced Font, width==0 is proportional Font
	char first_char;
	void *dat;
	short (*get_matrix)(FONT_MATRIX_T *);//字体点阵是点阵结构体类型
	//点阵信息在字库中的首地址

} SINGLE_BYTE_FONT_T;							 //定义单字节字体类型变量

typedef struct _DOUBLE_BYTE_FONT {
	char *name;			 							  //双字节字体类型的名称
	char id;
	enum {
		ASCII = 0,
		GB2312,
		GBK,
		BIG5,
		SJIS,
		UNICODE
	} encode;
	unsigned short height;
	unsigned short width;
	void *dat;
	short (*get_matrix)(FONT_MATRIX_T *);
} DOUBLE_BYTE_FONT_T;			 				 //定义双字节字体类型变量


typedef struct {
	int  (* initialize)(void);
	int  (* printf)(const char *, ...); //输出函数
	int  (* putbytes)(const char *, unsigned short ); //输出函数
	int  (* _putbytes)(int, const char *, const int );
	int  (* printf16)(int, int, const char *, ...);   //输出函数
	int  (* printf24)(int, int, const char *, ...);   //输出函数
	char (* check_word_byte)(int *, int *, char, const char *);

	SINGLE_BYTE_FONT_T *single_byte; //指定* single_byte是单字节字体
	DOUBLE_BYTE_FONT_T *double_byte; //指定* double_byte是双字节字体

	short x;													//lcd光标x的地址
	short y;													//lcd光标y的地址
	COLOR_T ForeColor;
	COLOR_T BackColor;

	struct {
		int word;											//字间距
		int line;											//行间距
	} space;
	struct {
		int x0;
		int y0;
		int x1;
		int y1;
	} region ;            //显示区域

	unsigned char mode;
} FONT_T;												//定义字体类型变量

//---------------- Extern Resource ----------------------//
extern char font_buffer[];
extern volatile FONT_T Font;

extern SINGLE_BYTE_FONT_T tahoma8;
extern DOUBLE_BYTE_FONT_T FontHZK_Ext;
extern SINGLE_BYTE_FONT_T FontASC_Ext;

#ifdef _CLIBRARY_ENABLE
int FONT_AscPrintf(char Mode, COLOR_T color, char Dot, int x, int y, const char *fmt, ...);
int FONT_Printf(char FontID, char Mode, COLOR_T color, char Dot, int x, int y, const char *fmt, ...);
#endif

#endif //__font_h__

