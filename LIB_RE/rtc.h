
#ifndef __RTC_H
#define __RTC_H
/**************************************************************************************/
/**************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#include "bsp.h"

typedef struct {
	const u8 *Module;
	void (* Initialize)(void);
	u8 (* ReNew)(void);
	u8 (* Read)(RTC_TIME_Type * );
	u8 (* Set)(RTC_TIME_Type * );
	time_t (* Rtc_MakeTime)(const RTC_TIME_Type );
	RTC_TIME_Type (* Rtc_LocalTime)(const time_t * );
	u16 rtc_ye;
	u16 rtc_mo;
	u16 rtc_dm;
	u16 rtc_dw;
	u16 rtc_ho;
	u16 rtc_mi;
	u16 rtc_se;
} RTC_DEV_STRUCT;


extern volatile RTC_DEV_STRUCT RTC;

/**************************************************************************************/
/**************************************************************************************/
#ifdef __cplusplus
}
#endif
/**************************************************************************************/
/**************************************************************************************/
#endif //__RTC_H

