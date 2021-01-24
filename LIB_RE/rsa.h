
#ifndef __RSA_H
#define __RSA_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct
    {
        const u8 *Module;
        void (* Initial)(void);
        void (* rMCUID)(u32 * , u32 * , u16 * );
        int8_t (* Receive)(u8 *, u16 );
        int8_t (* Erase)(u8 *, u16 );
        int8_t (* isExpired)(void);
    } LICENCE_STRUCT;

    extern const LICENCE_STRUCT Permit;

#ifdef __cplusplus
}
#endif

#endif
