
#ifndef __UART_H
#define __UART_H
/**************************************************************************************/
/**************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
#include "typedef.h"
	
	
typedef struct {
	const char *Module;
	void (* Initialize)(const u8 mode, const u32 BaudRate);
	void (* Enable)(void);
	void (* Disable)(void);
	u32 (* Read)(u8 *, u32 );
	u32 (* VosRead)(u8 *, u32 );
	void (* Write)(u8 *, u32 );
	void (* WriteByte)(u8 );
	void (* WriteWord)(u16 );
	void (* WriteString)(char * );
	void (* ResetRxBuf)(void);
	void (* ResetTxBuf)(void);
	void (* ResetUartBuf)(void);
	u32 (* UartRxLength)(void);
	u8  (* RxOverFow)(void);
	void (* printf)(char *fmt, ...);
} UART_DEV_STRUCT;

extern const UART_DEV_STRUCT Uart;

#define printk Uart.printf

#ifdef __cplusplus
}
#endif
/**************************************************************************************/
/**************************************************************************************/
#endif //__UART_H
/**************************************************************************************/
/************************************** END *******************************************/
/**************************************************************************************/
