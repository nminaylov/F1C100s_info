/*************************************************************************************************************************************/
#ifndef __GDI_H
#define __GDI_H

#include "userstruct.h"

#ifdef __cplusplus
extern "C" {
#endif

void GDI_Init(void);

/* Calculate the Amount of Cheap */
u32 ComputeOffset(u16 x, u16 y);

/* Parameter Cross-Border Handling Mechanism */
JX_STATUS CrossPicID(u16 *a);
JX_STATUS CrossBorder(u16 *x, u16 *y);
JX_STATUS CrossBound(const u16 a, u16 *b, const u32 c);

/* Reading Pixel Values */
COLOR_T GDI_rPixelColor(u16 x, u16 y);
COLOR_T GDI_rBoundColor(u16 x, u16 y);

/* Pixel Operation */
COLOR_T    GDI_RePixel(u16 x, u16 y);
JX_STATUS GDI_DraPixel(u16 x, u16 y, COLOR_T Color);
JX_STATUS GDI_DraNePixel(u16 x, u16 y);
JX_STATUS GDI_NePixel(u16 x, u16 y, COLOR_T Color);

/* Line Operation */
JX_STATUS GDI_DraHor(u16 x, u16 y, u16 w, COLOR_T Color);
JX_STATUS GDI_DraNeHor(u16 x, u16 y, u16 w);
JX_STATUS GDI_NeHor(u16 x, u16 y, u16 w, COLOR_T Color);

JX_STATUS GDI_DraVer(u16 x, u16 y, u16 h, COLOR_T Color);
JX_STATUS GDI_DraNeVer(u16 x, u16 y, u16 h);
JX_STATUS GDI_NeVer(u16 x, u16 y, u16 h, COLOR_T Color);

JX_STATUS GDI_DrawLine(u16 x0, u16 y0, u16 x1, u16 y1, COLOR_T Color);
JX_STATUS GDI_DrawNeLine(u16 x0, u16 y0, u16 x1, u16 y1);
JX_STATUS GDI_NeLine(u16 x0, u16 y0, u16 x1, u16 y1, COLOR_T Color);
JX_STATUS GDI_BoldDrawLine(u16 x0, u16 y0, u16 x1, u16 y1, u16 Thick, COLOR_T Color);

/* Rectangle Operation */
JX_STATUS GDI_DraRect(u16 x, u16 y, u16 w, u16 h, COLOR_T Color);
JX_STATUS GDI_DraNeRect(u16 x, u16 y, u16 w, u16 h);
JX_STATUS GDI_NeRect(u16 x, u16 y, u16 w, u16 h, COLOR_T Color);

JX_STATUS GDI_DraFulRect(u16 x, u16 y, u32 w, u32 h, COLOR_T Color);
JX_STATUS GDI_DraFulRect2(u16 x, u16 y, u32 w, u32 h, COLOR_T Color);
JX_STATUS GDI_DraFulNeRect(u16 x, u16 y, u16 w, u16 h);
JX_STATUS GDI_FulNeRect(u16 x, u16 y, u16 w, u16 h, COLOR_T Color);

/* Circle Operation */
JX_STATUS GDI_DraCir(u16 x0, u16 y0, u16 r, COLOR_T Color);
JX_STATUS GDI_DraNeCir(u16 x0, u16 y0, u16 r);
JX_STATUS GDI_DraFulCir(u16 x0, u16 y0, u16 r, COLOR_T Color);
JX_STATUS GDI_DraFulNeCir(u16 x0, u16 y0, u16 r);

/* Sector Operation */
JX_STATUS GDI_DraSec(u16 x0, u16 y0, u16 r, u16 a0, u16 a1, COLOR_T Color);
JX_STATUS GDI_DraFulSec(u16 x0, u16 y0, u16 r, u16 a0, u16 a1, COLOR_T Color);

/* Pie chart Operation */
JX_STATUS GDI_DraArc(u16 x0, u16 y0, u16 r, s16 a0, s16 a1, COLOR_T Color);

/* Ellipse Operation */
JX_STATUS GDI_DraOval(u16 x0, u16 y0, u16 a, u16 b, COLOR_T Color);
JX_STATUS GDI_DraNeOval(u16 x0, u16 y0, u16 a, u16 b);
JX_STATUS GDI_DraFulOval(u16 x0, u16 y0, u16 a, u16 b, COLOR_T Color);
JX_STATUS GDI_DraNeFulOval(u16 x0, u16 y0, u16 a, u16 b);

/* Polygon Fill Operation */
JX_STATUS GDI_StufPol(u16 x, u16 y, COLOR_T FillColor);

/* Picture Cut Operation */
JX_STATUS GDI_CutPic(u16 ID, u16 Xs, u16 Ys, u16 Xe, u16 Ye, u16 Xd, u16 Yd);
JX_STATUS GDI_CutHyaPic(u16 ID, u16 Xs, u16 Ys, u16 Xe, u16 Ye, u16 Xd, u16 Yd);

/* Show\Save\Clean Sreen TFT-LCD */
void GDI_ClrPicID(void);
JX_STATUS GDI_ShowSreen(u16 ID);
u16 GDI_CurrentPictureIndex(void);
u16 GDI_PicCheck(const u16 id);
JX_STATUS GDI_PicBuffer(const u16 ID);
JX_STATUS GDI_ForcSreen(VRAM_FLOW VramFlow);
JX_STATUS GDI_SavScreen(u16 ID);
JX_STATUS GDI_ClrScreen(COLOR_T color);

/* Show Icons on LCD */
u16 GDI_GetIconWidth(u8 fID, u16 iID);
u16 GDI_GetIconHeigh(u8 fID, u16 iID);
JX_STATUS GDI_GetIconInfo(u8 *ExWidth, u8 *ExHeigh, u8 fID, u16 iID);
JX_STATUS GDI_ShowIcon(u8 fID, u16 iID, COORD_STRUCT Coord, const u8 Mode);
JX_STATUS GDI_RotIcon(u8 fID, u16 iID, const u8 Mode, u16 Angle, COORD_STRUCT *Coord, COORD_STRUCT *Center);

/* Show Icl on LCD */
u16 GDI_GetIclWidth(u8 fID, u16 iID);
u16 GDI_GetIclHeigh(u8 fID, u16 iID);
JX_STATUS GDI_ShowIcl(u8 fID, u16 iID, COORD_STRUCT Coord, const u8 Mode);
JX_STATUS GDI_RotIcl(u8 fID, u16 iID, const u8 Mode, u16 Angle, COORD_STRUCT *Coord, COORD_STRUCT *Center);

/* Progress Bar Set and Execution */
JX_STATUS GDI_ProBarBox(u16 x0, u16 y0, u16 x1, u16 y1, COLOR_T b, COLOR_T s);
JX_STATUS GDI_ProBar(u16 x, u16 y, u16 w, u16 h, u32 ProN, u32 ProL, COLOR_T c);

#ifdef __cplusplus
}
#endif

#endif /*__GDI_H */
/*************************************************************************************************************************************/

