#ifndef __LIB_API_H
#define __LIB_API_H

#ifdef __cplusplus
extern "C" {
#endif

#include "uart.h"
#include "font.h"
#include "lcd.h"
#include "userstruct.h"

unsigned short  picture_idx_rd(void);
void  picture_idx_wr(unsigned short idx);
void reg_wr(unsigned char add, unsigned char val);
unsigned char reg_rd(unsigned char add);
unsigned short vp_rdword(unsigned short add);
unsigned char vp_rdbyte(unsigned short add);
unsigned char vp_rdbyteL(unsigned short add);
unsigned char vp_rdbyteH(unsigned short add);
void vp_wrword(unsigned short add, unsigned short val) ;
void vp_wrbyte(unsigned short add, unsigned char val);
void vp_wrbyteL(unsigned short add, unsigned char val);
void vp_wrbyteH(unsigned short add, unsigned char val);
//¶ÁÈ¡×Ö¿â
void fontLib_read(unsigned short ID, unsigned int offset, unsigned int length, unsigned char *buf);
void fontlib_to_vp(unsigned char font_id, unsigned int font_add, unsigned int length, unsigned int vp_add);
void vp_to_fontlib(unsigned char font_id, unsigned int font_add, unsigned int length, unsigned int vp_add);

void wwdt_feed(void);
JX_STATUS commandTask_agus(void);
int touch_event_hander(const unsigned short code, const unsigned short VPaddr, const unsigned short length ); //´¥¿ØÊÂ¼þ
#ifdef __cplusplus
}
#endif

#endif /*__TOUCH_H */

