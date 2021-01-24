#ifndef __LCDINFO_H
#define __LCDINFO_H

#include "lcd.h"

#ifdef __cplusplus
extern "C" {
#endif
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*+++++++++++++++++++++++++++++++++++ Table LCD Size / Code ++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*+ Size + 320x240 + 480x272 + 640x480 + 800x480 + 800x600 + 1024x576 + 1024x600 + 1024x768 ++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*+ Code +   Q(0)  +   F(1)  +   V(2)  +   Y(3)  +   S(4)  +   N(5)   +   L(6)   +   X(7)   ++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*+ Size + 1280x800 + 1280x1024 + 1366x768 + 1600x900 + 1600x1200 + 1680x1050 | 1920x1080 ++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*+ Code +   I(8)   +    E(9)   +   B(A)   +   O(B)   +    U(C)   +    Z(D)   +   H/J(E)  ++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*+ Size + 2048x1536 + 2560x1440 | 2560x2048 + 3840x2160 + 4096x2560 +++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*+ Code +   R(F)    +   K(G)    +   T(H)    +   D(I)    +    M(J)   +++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/**********************************************************************************************/
#define HV_MODE      (0x80)
#define DE_MODE      (0x00)

#define VS_ACTIVE_H   (0x00)
#define VS_ACTIVE_L    (0x08)

#define HS_ACTIVE_H   (0x00)
#define HS_ACTIVE_L    (0x04)

#define DE_ACTIVE_H   (0x00)
#define DE_ACTIVE_L    (0x02)

#define DCLK_RISING    (0x01)
#define DCLK_FALLING   (0x00)


const LCDINFO_STRUCT LcdTable[] = {
	/*LcdID      LCDName       LCDCode  tWHA   tHPW  tHBP  tHFP  tWVA  tVPW  tVBP  tVFP  LCDSize LCDFreq             LcdMode              */
#ifndef __ADSTAR__
	{0x20, (u8 *)" 320xRGBx240",  'Q',    320,    4,   66,   18,  240,   2,   13,    9,   35,    12000,    HV_MODE | VS_ACTIVE_L | HS_ACTIVE_L | DE_ACTIVE_H | DCLK_RISING},
	{0x30, (u8 *)" 320xRGBx240",  'Q',    320,    4,   66,   18,  240,   2,   13,    9,   28,    24000,    HV_MODE | VS_ACTIVE_L | HS_ACTIVE_L | DE_ACTIVE_H | DCLK_RISING},
#endif
	{0x21, (u8 *)" 480xRGBx272",  'F',    480,    2,   40,   51,  272,   3,    8,   40,   43,    15000,    HV_MODE | VS_ACTIVE_L | HS_ACTIVE_L | DE_ACTIVE_H | DCLK_RISING},
	//	{0x22, (u8 *)" 480xRGBx272",  'F',    480,    2,   40,   51,  272,   3,    8,   40,   43,    15000,    HV_MODE | VS_ACTIVE_L | HS_ACTIVE_L | DE_ACTIVE_H | DCLK_FALLING},
	{0x22, (u8 *)" 480xRGBx272",  'F',    480,    2,   38,   53,  272,   3,    7,   41,   43,    15000,    HV_MODE | VS_ACTIVE_L | HS_ACTIVE_L | DE_ACTIVE_H | DCLK_FALLING},
#ifndef __ADSTAR__
	{0x01, (u8 *)" 640xRGBx480",  'V',    640,   48,   40,   40,  480,   3,   29,   13,   56,    25000,    HV_MODE | VS_ACTIVE_L | HS_ACTIVE_L | DE_ACTIVE_H | DCLK_RISING},
#endif
	{0x02, (u8 *)" 800xRGBx480",  'Y',    800,   48,   40,   40,  480,   3,   29,   13,   70,    34000,    DE_MODE | VS_ACTIVE_L | HS_ACTIVE_L | DE_ACTIVE_H | DCLK_FALLING},
#ifndef __ADSTAR__
	{0x03, (u8 *)" 800xRGBx600",  'S',    800,   48,   40,   40,  600,   3,   29,   13,   80,    32000,    DE_MODE | VS_ACTIVE_L | HS_ACTIVE_L | DE_ACTIVE_H | DCLK_FALLING},
	{0x13, (u8 *)" 800xRGBx600",  'S',    800,   48,   40,   40,  600,   3,   29,   13,  121,    37000,    DE_MODE | VS_ACTIVE_L | HS_ACTIVE_L | DE_ACTIVE_H | DCLK_FALLING},
	{0x08, (u8 *)"1024xRGBx768",  'X',   1024,   48,   80,  240,  768,   5,   29,   13,  150,    70000,    DE_MODE | VS_ACTIVE_L | HS_ACTIVE_L | DE_ACTIVE_H | DCLK_FALLING},
	{0x09, (u8 *)"1024xRGBx768",  'X',   1024,   48,   80,  240,  768,   5,   29,   13,   97,    70000,    DE_MODE | VS_ACTIVE_L | HS_ACTIVE_L | DE_ACTIVE_H | DCLK_FALLING},
	{0x0A, (u8 *)"1024xRGBx600",  'L',   1024,   48,   80,  240,  600,   5,   29,   13,  101,    60000,    DE_MODE | VS_ACTIVE_L | HS_ACTIVE_L | DE_ACTIVE_H | DCLK_RISING},
	{0x0B, (u8 *)"1024xRGBx600",  'L',   1024,   48,   80,  240,  600,   5,   29,   13,   70,    60000,    DE_MODE | VS_ACTIVE_L | HS_ACTIVE_L | DE_ACTIVE_H | DCLK_FALLING},
	{0x0C, (u8 *)"1280xRGBx800",  'W',   1280,   48,   80,  240,  800,   5,   29,   13,   121,   60000,    DE_MODE | VS_ACTIVE_L | HS_ACTIVE_L | DE_ACTIVE_H | DCLK_FALLING},
	{0x12, (u8 *)" 800xRGBx480",  'Y',    800,   48,   88,   40,  480,   3,   16,   13,   70,    34000,    DE_MODE | VS_ACTIVE_L | HS_ACTIVE_L | DE_ACTIVE_H | DCLK_FALLING},
#endif
};

#ifdef __cplusplus
}
#endif

#endif //__LCDINFO_H

