#ifndef __RAMINFO_H
#define __RAMINFO_H

#ifdef __cplusplus
extern "C" {
#endif

/* SDRAM Base Info */
#if   defined(__N3290x__)
#define EXTERNAL_MEMORY_ADDR0		(0x00100000)
#define EXTERNAL_MEMORY_SIZE0		(0x00700000)
#elif   defined(__ADSTAR__)
#define EXTERNAL_MEMORY_ADDR0		(0x20200000)
#define EXTERNAL_MEMORY_SIZE0		(0x00400000)
#elif   defined(__F1C100S__)
#define EXTERNAL_MEMORY_ADDR0		(0x80a00000)
#define EXTERNAL_MEMORY_SIZE0		(0x82000000-EXTERNAL_MEMORY_ADDR0)
#else
#error "Please Define RAM Size!!!"	
#endif

extern __align(1024) unsigned char vram_buffer0[];
extern __align(1024) unsigned char vram_buffer1[];
extern __align(1024) unsigned char vram_buffer2[];
extern __align(1024) unsigned char vram_buffer3[];
extern __align(1024) unsigned char vram_buffer4[];

extern __align(1024) unsigned char variable[];
extern __align(1024) unsigned char curve_buffer[];

extern __align(1024) unsigned char variable_info_buffer[];
extern __align(1024) unsigned char touch_file_buffer[];

extern __align(1024) unsigned char method_index_buffer[];
extern __align(1024) unsigned char database_buffer[];

extern __align(1024) unsigned char vos_buffer[];

#ifdef __cplusplus
}
#endif

#endif /* __RAMINFO_H */

