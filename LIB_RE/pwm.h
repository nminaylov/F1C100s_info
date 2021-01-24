
#ifndef __PWM_H
#define __PWM_H
/**************************************************************************************/
/**************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "typedef.h"

#ifdef __ADSTAR__
#define BACKLIGHT_PWM_FREQ_HZ 500
#else
#define BACKLIGHT_PWM_FREQ_HZ 11000//500
#endif
#define BUZZER_PWM_FREQ_HZ 1000//1080//2500	

typedef struct {
	const u8 *Module;

	void (* Initialize)(u32 u32Hz);

	void (* On)(void);
	void (* Off)(void);
	void (* SetLM)(u8 );
} BACKLIGHT_DEV_STRUCT;

extern const BACKLIGHT_DEV_STRUCT Backlight;

typedef struct {
	const u8 *Module;

	void (* Initialize)(u32 u32Hz);

	void (* On)(void);
	void (* Off)(void);
} BUZZER_DEV_STRUCT;

extern const BUZZER_DEV_STRUCT Buzzer;
/**************************************************************************************/
/**************************************************************************************/
#ifdef __cplusplus
}
#endif
/**************************************************************************************/
/**************************************************************************************/
#endif //__PWM_H
