#ifndef __DEBUG_H
#define __DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "uart.h"

//#define _APPLICATION
//#define _DRIVERS
//	
#define UartPrintf 	sysprintf

#ifdef _DRIVERS
#define DRIVERS_DEBUG(cmd, avg...)    UartPrintf("[D:Dri][%s(%d)]: " cmd, __FILE__, __LINE__, ## avg);
#define DRIVERS_WARIN(cmd, avg...)    UartPrintf("[W:Dri][%s(%d)]: " cmd, __FILE__, __LINE__, ## avg);
#else
#define DRIVERS_DEBUG(cmd, avg...)
#define DRIVERS_WARIN(cmd, avg...)
#endif

#ifdef _APPLICATION
#define APPLICA_DEBUG(cmd, avg...)    UartPrintf("[D:App][%s(%d)]: " cmd, __FILE__, __LINE__, ## avg);
#define APPLICA_WARIN(cmd, avg...)    UartPrintf("[W:App][%s(%d)]: " cmd, __FILE__, __LINE__, ## avg);
#else
#define APPLICA_DEBUG(cmd, avg...)
#define APPLICA_WARIN(cmd, avg...)
#endif


#define ReceiveReady()                Uart.WriteString("OK");

#ifdef __cplusplus
}
#endif

#endif /*__DEBUG_H */
