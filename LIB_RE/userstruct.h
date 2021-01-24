#ifndef __USERSTRUCT_H
#define __USERSTRUCT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdio.h>

#include "typedef.h"



#ifdef __N3290x__
#define inline
#endif
typedef enum __StatusType {
	ST_SUCCESS = 0,			// success
	ST_FAILE = -1,			// Faile
	ST_DATAINVALID = -2,	// The Data has been Invalid
	ST_CMDINVALID = -3,		// The command No. has been invalid
	ST_TIMEOUT = -4, 		// Time out
	ST_OVERFLOW = -5,		// Over flow
	ST_LENGTH = -6,			// Too shot or long
	ST_FLAG = -7,			// Flag Error
	ST_FINISH = -8			// Finish Flag
} StatusType, *pStatusType;

typedef enum {ERROR = 0, SUCCESS = !ERROR} Status;
/* */
typedef enum {
	VRAM_01 = 0x00, /* VRAM Flow : VRAM-Area(0)    to Buffer-Area(1)  */
	VRAM_02,        /* VRAM Flow : VRAM-Area(0)    to Operate-Area(2) */
	VRAM_03,        /* VRAM Flow : VRAM-Area(0)    to Picture-Area(3) */
	VRAM_10,        /* VRAM Flow : Buffer-Area(1)  to VRAM-Area(0)    */
	VRAM_12,        /* VRAM Flow : Buffer-Area(1)  to Operate-Area(2) */
	VRAM_13,        /* VRAM Flow : Buffer-Area(1)  to Picture-Area(3) */
	VRAM_20,        /* VRAM Flow : Operate-Area(2) to VRAM-Area(0)    */
	VRAM_21,        /* VRAM Flow : Operate-Area(2) to Buffer-Area(1)  */
	VRAM_23,        /* VRAM Flow : Operate-Area(2) to Picture-Area(3) */
	VRAM_30,        /* VRAM Flow : Picture-Area(3) to VRAM-Area(0)    */
	VRAM_31,        /* VRAM Flow : Picture-Area(3) to Buffer-Area(1)  */
	VRAM_32         /* VRAM Flow : Picture-Area(3) to Operate-Area(2) */
} VRAM_FLOW;

/* KG-System Working Status type definition */
typedef enum {
	WORK_NON = 0x00,
	WORK_STA,
	WORK_END,
	WORK_ON
} WORKING_STATUS;

/* Status type definition */
typedef enum {
	JX_SUCCESS = 0,  // success
	JX_FAILE  = -1,  // Faile
	JX_DATNUL = -2,  // The Data has been Invalid
	JX_CMDNUL = -3,	 // The command No. has been invalid
	JX_TIMOUT = -4,  // Time out
	JX_OVER   = -5,	 // Over flow
	JX_LENGTH = -6,  // Too shot or long
	JX_FLAG   = -7,  // Flag Error
	JX_FINISH = -8,  // Finish Flag
	JX_CHECK  = -9,  // Check Error
	JX_PRESS  = -10, // Touching
	JX_NULL   = -11,
	JX_WAIT   = -12
} JX_STATUS;

typedef struct {
	u16 Xs;
	u16 Ys;
	u16 Xe;
	u16 Ye;
} WINDOW_STRUCT;

typedef struct {
	u16 x;
	u16 y;
} COORD_STRUCT;

typedef struct {
	u16 min;
	u16 max;
} LIMIT_STRUCT;

typedef struct {
	u16 Word;
	u16 Line;
} SPACE_STRUCT;

//#pragma pack(1)
typedef struct {
	u16 ActX[5];
	u16 ActY[5];
	u16 MapX[5];
	u16 MapY[5];
	s32 AdjV[7];
} CALIBRATION_STRUCT;

typedef struct {
	u8 LcdID0;     /* R0 */
	u8 BaudID;     /* R1 */
	u8 SysConfig;  /* R2 */
	u8 FisFra0;    /* R3 */
	u8 LcdID1;     /* R4 */
	u8 HigBaud;    /* R5 */
	u8 OnLedLM;    /* R6 */
	u8 OffLedLM;   /* R7 */
	u8 OnLMTime;   /* R8 */
	u8 LowBaud;    /* R9 */
	u8 FisFra1;    /* RA */
	u8 Reserved0;  /* RB */
	u8 AuxConfig;  /* RC */
	u8 Reserved1;  /* RD */
	u8 Reserved2;  /* RE */
	u8 Reserved3;  /* RF */
	CALIBRATION_STRUCT CalibInfo;
	u32 times;
	u16 CrcCheck;
} SYSTEM_CFG_STRUCT, *pSYSTEM_CFG_STRUCT;

typedef struct {
	u32 TxLen;
	u32 RxLen;
} CURLINE_STRUCT;

#ifdef __cplusplus
}
#endif

#endif /* __XRDTYPES_H */

