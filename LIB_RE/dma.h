/*****************************************************************************
 *   dma.h:  Header file for NXP LPC177x_8x Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.26  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/
#ifndef __DMA_H
#define __DMA_H

//#define DMA_SRC			0x20004000		/* This is the area original data is stored
//										or data to be written to the SD/MMC card. */
//#define DMA_DST			0x20005000		/* This is the area, after writing to the SD/MMC,
//										data read from the SD/MMC card. */
//#define DMA_MCIFIFO		0x400C0080
//#define DMA_SIZE		BLOCK_LENGTH	/* DMA_SIZE is the same BLOCK_LENGTH defined in mci.h */

/* DMA mode */
//#define M2M				0x00
//#define M2P				0x01
//#define P2M				0x02
//#define P2P				0x03
#include <stdint.h>
//void DMA_IRQHandler( void );
void DMA_M2M(u32 dst, u32 src, u32 cnt);
void _memcpy(void *dst, void *src, u32 cnt);


#endif /* end __DMA_H */
/****************************************************************************
**                            End Of File
****************************************************************************/

