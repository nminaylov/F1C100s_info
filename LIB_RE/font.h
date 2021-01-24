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
	unsigned char character[2];	//�����������
	char direction;							 	//������ʾ����
	unsigned short height;									 	//����߶�
	unsigned short width;									 	//������
	char const *dat;					 	//������Ϣ���ֿ��е��׵�ַ
} FONT_MATRIX_T;				 				 	//��������������ͱ���

typedef	struct	_SINGLE_BYTE_FONT {
	char *name;				 						//���ֽ��������͵�����
	char id;				 	  //�����ڵ��ֽ����������ڵ�ƫ����
	unsigned short	height;
	unsigned short width; //width!=0 is monospaced Font, width==0 is proportional Font
	char first_char;
	void *dat;
	short (*get_matrix)(FONT_MATRIX_T *);//��������ǵ���ṹ������
	//������Ϣ���ֿ��е��׵�ַ

} SINGLE_BYTE_FONT_T;							 //���嵥�ֽ��������ͱ���

typedef struct _DOUBLE_BYTE_FONT {
	char *name;			 							  //˫�ֽ��������͵�����
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
} DOUBLE_BYTE_FONT_T;			 				 //����˫�ֽ��������ͱ���


typedef struct {
	int  (* initialize)(void);
	int  (* printf)(const char *, ...); //�������
	int  (* putbytes)(const char *, unsigned short ); //�������
	int  (* _putbytes)(int, const char *, const int );
	int  (* printf16)(int, int, const char *, ...);   //�������
	int  (* printf24)(int, int, const char *, ...);   //�������
	char (* check_word_byte)(int *, int *, char, const char *);

	SINGLE_BYTE_FONT_T *single_byte; //ָ��* single_byte�ǵ��ֽ�����
	DOUBLE_BYTE_FONT_T *double_byte; //ָ��* double_byte��˫�ֽ�����

	short x;													//lcd���x�ĵ�ַ
	short y;													//lcd���y�ĵ�ַ
	COLOR_T ForeColor;
	COLOR_T BackColor;

	struct {
		int word;											//�ּ��
		int line;											//�м��
	} space;
	struct {
		int x0;
		int y0;
		int x1;
		int y1;
	} region ;            //��ʾ����

	unsigned char mode;
} FONT_T;												//�����������ͱ���

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

