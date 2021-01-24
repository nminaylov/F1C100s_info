
#ifndef _CRC_H_
#define _CRC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "typedef.h"
    typedef enum
    {
        CRC_POLY_CRCCCITT = 0,			/** CRC CCITT polynomial */
        CRC_POLY_CRC16,					/** CRC-16 polynomial */
        CRC_POLY_CRC32					/** CRC-32 polynomial */
    }
    CRC_Type;

    typedef struct
    {
        char *Module;
        void (* Initial)(CRC_Type );
        u16 (* Check16)(u16 , u8 * , u32 );
        u16 (* Crc16Xmode)(u16 , u8 * , u32 );
    } CRC_STRUCT;

    extern const CRC_STRUCT DriCrc;

    u16 CRC16(u16 BraekPoint, u8 *Buffer, u32 Length);

#ifdef __cplusplus
}
#endif

#endif
