#ifndef __SYSINIT_H
#define __SYSINIT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct
    {
        char *Module;
        void (* Initial)(void);
        void (* ReLCD)(const u8 );
        void (* ReUart)(const u8 );
        void (* SetLM)(u8 );
        u32 (* rSysTick)(void);
        void (* ClrTimeCoReg)(void);
    } SYSINIT_STRUCT;

    extern const SYSINIT_STRUCT SysInit;

#ifdef __cplusplus
}
#endif

#endif /*__SYSINIT_H */

