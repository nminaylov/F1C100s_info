
#ifndef __SYSTICK_H
#define __SYSTICK_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include "typedef.h"

    void Delay10Ms(u32 DelayValue);

#define SYSTIMES_MAX    (0x6fffffff)

    typedef struct
    {
        u8 *Module;
        void     (* Initialize)(void);
        volatile u64 (* Read)(void);
        void     (* ClrCoReg)(void);
			  volatile u64 (* Read1ms)(void);
			  volatile u64 (* Read4ms)(void);
			  volatile u64 (* Read10ms)(void);
			  u8  (* SetTimerTask)(u64 ,void *); //设置一个定时任务, 任务时间间隔最小4ms
			  void (* Delay10ms)(u32);
			  void (* Delayms)(u32);
    } TIME_STRUCT;


    extern const TIME_STRUCT Tick;

extern volatile u64 SysTick10ms;

#ifdef _CLIBRARY_ENABLE
    void _use_10mshandler(void); /* working in the System tick handler : 10ms */
#endif

  

#ifdef __cplusplus
}
#endif

#endif //__SYSTICK_H
