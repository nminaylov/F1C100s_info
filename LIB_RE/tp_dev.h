
#ifndef __TP_DEV_H
#define __TP_DEV_H

#ifdef __cplusplus
extern "C" {
#endif

#include "bsp.h"




extern TP_DEV_STRUCT  *TP_dev;
#define TP       (*TP_dev)

void TP_Init(uint8_t num);

#ifdef __cplusplus
}
#endif

#endif //__TP_DEV_H

