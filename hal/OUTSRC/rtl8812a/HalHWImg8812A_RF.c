/******************************************************************************
*
* Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of version 2 of the GNU General Public License as
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along with
* this program; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
*
*
******************************************************************************/


#include "../odm_precomp.h"
#include "../../../rtl8821au/table.h"

#define READ_NEXT_PAIR(array_table, v1, v2, i) \
	do { \
		i += 2; \
		v1 = array_table[i]; \
		v2 = array_table[i+1]; \
	} while (0)

#if (RTL8812A_SUPPORT == 1)
static BOOLEAN CheckCondition(const uint32_t Condition, const uint32_t Hex)
{
	uint32_t _board     = (Hex & 0x000000FF);
	uint32_t _interface = (Hex & 0x0000FF00) >> 8;
	uint32_t _platform  = (Hex & 0x00FF0000) >> 16;
	uint32_t cond = Condition;

	if (Condition == 0xCDCDCDCD)
		return TRUE;

	cond = Condition & 0x000000FF;
	if ((_board != cond) && (cond != 0xFF))
		return FALSE;

	cond = Condition & 0x0000FF00;
	cond = cond >> 8;
	if (((_interface & cond) == 0) && (cond != 0x07))
		return FALSE;

	cond = Condition & 0x00FF0000;
	cond = cond >> 16;
	if (((_platform & cond) == 0) && (cond != 0x0F))
		return FALSE;

	return TRUE;
}


/******************************************************************************
*                           RadioA.TXT
******************************************************************************/

void ODM_ReadAndConfig_MP_8812A_RadioA(PDM_ODM_T pDM_Odm)
{
	uint32_t     	hex         = 0;
	uint32_t     	i           = 0;
	uint16_t     	count       = 0;
	uint32_t    	*ptr_array   = NULL;
	u1Byte		platform    = pDM_Odm->SupportPlatform;
	u1Byte     	_interface   = pDM_Odm->SupportInterface;
	u1Byte     	board       = pDM_Odm->BoardType;
	uint32_t     	ArrayLen    =  RTL8812AU_RADIOA_1TARRAYLEN;
	uint32_t    	*Array       = RTL8812AU_RADIOA_ARRAY;


	hex += board;
	hex += _interface << 8;
	hex += platform << 16;
	hex += 0xFF000000;
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ReadAndConfig_MP_8812A_RadioA, hex = 0x%X\n", hex));

	for (i = 0; i < ArrayLen; i += 2) {
		uint32_t v1 = Array[i];
		uint32_t v2 = Array[i+1];

		/* This (offset, data) pair meets the condition. */
		if (v1 < 0xCDCDCDCD) {
			odm_ConfigRF_RadioA_8812A(pDM_Odm, v1, v2);
			continue;
		} else { /* This line is the start line of branch. */
			if (!CheckCondition(Array[i], hex)) {
				/* Discard the following (offset, data) pairs. */
				READ_NEXT_PAIR(Array, v1, v2, i);
				while (v2 != 0xDEAD &&
				    v2 != 0xCDEF &&
				    v2 != 0xCDCD && i < ArrayLen-2) {
					READ_NEXT_PAIR(Array, v1, v2, i);
				}
				i -= 2; /* prevent from for-loop += 2 */
			} else {
				/* Configure matched pairs and skip to end of if-else. */
				READ_NEXT_PAIR(Array, v1, v2, i);
				while (v2 != 0xDEAD &&
				    v2 != 0xCDEF &&
				    v2 != 0xCDCD && i < ArrayLen-2) {
					odm_ConfigRF_RadioA_8812A(pDM_Odm, v1, v2);
					READ_NEXT_PAIR(Array, v1, v2, i);
				}

				while (v2 != 0xDEAD && i < ArrayLen-2) {
					READ_NEXT_PAIR(Array, v1, v2, i);
				}
			}
		}
	}

}

/******************************************************************************
*                           RadioB.TXT
******************************************************************************/


void ODM_ReadAndConfig_MP_8812A_RadioB(PDM_ODM_T pDM_Odm)
{
	uint32_t	hex         = 0;
	uint32_t	i           = 0;
	uint16_t	count       = 0;
	uint32_t	*ptr_array   = NULL;
	u1Byte		platform    = pDM_Odm->SupportPlatform;
	u1Byte		_interface   = pDM_Odm->SupportInterface;
	u1Byte		board       = pDM_Odm->BoardType;
	uint32_t	ArrayLen    = RTL8812AU_RADIOB_1TARRAYLEN;
	uint32_t	*Array       = RTL8812AU_RADIOB_ARRAY;

	hex += board;
	hex += _interface << 8;
	hex += platform << 16;
	hex += 0xFF000000;
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ReadAndConfig_MP_8812A_RadioB, hex = 0x%X\n", hex));

	for (i = 0; i < ArrayLen; i += 2) {
		uint32_t v1 = Array[i];
		uint32_t v2 = Array[i+1];

		/* This (offset, data) pair meets the condition. */
		if (v1 < 0xCDCDCDCD) {
			odm_ConfigRF_RadioB_8812A(pDM_Odm, v1, v2);
			continue;
		} else {
			/* This line is the start line of branch. */
			if (!CheckCondition(Array[i], hex)) {
				/* Discard the following (offset, data) pairs. */
				READ_NEXT_PAIR(Array, v1, v2, i);
				while (v2 != 0xDEAD &&
				    v2 != 0xCDEF &&
				    v2 != 0xCDCD && i < ArrayLen-2) {
					READ_NEXT_PAIR(Array, v1, v2, i);
				}
				i -= 2; /* prevent from for-loop += 2 */
			} else {
				/* Configure matched pairs and skip to end of if-else. */
				READ_NEXT_PAIR(Array, v1, v2, i);
				while (v2 != 0xDEAD &&
				    v2 != 0xCDEF &&
				    v2 != 0xCDCD && i < ArrayLen-2) {
					odm_ConfigRF_RadioB_8812A(pDM_Odm, v1, v2);
					READ_NEXT_PAIR(Array, v1, v2, i);
				}

				while (v2 != 0xDEAD && i < ArrayLen-2) {
					READ_NEXT_PAIR(Array, v1, v2, i);
				}
			}
		}
	}

}

/******************************************************************************
*                           TxPowerTrack_USB.TXT
******************************************************************************/

u1Byte gDeltaSwingTableIdx_MP_5GB_N_TxPowerTrack_USB_8812A[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 2, 3, 4, 5, 6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 14, 14, 14, 14},
	{0, 1, 1, 2, 3, 3, 4, 5, 5,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 1, 2, 3, 3, 4, 5, 6,  7,  7,  8,  8,  9,  9, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
};
u1Byte gDeltaSwingTableIdx_MP_5GB_P_TxPowerTrack_USB_8812A[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 2, 3, 3, 4, 5,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 1, 2, 3, 3, 4, 5, 5,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 1, 2, 3, 3, 4, 5, 6,  7,  7,  8,  8,  9,  9, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
};
u1Byte gDeltaSwingTableIdx_MP_5GA_N_TxPowerTrack_USB_8812A[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 2, 3, 4, 5, 6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 15, 15, 15, 15, 15},
	{0, 1, 1, 2, 2, 3, 4, 5, 6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 15, 15, 15, 15, 15},
	{0, 1, 1, 2, 2, 3, 4, 5, 6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 15, 15, 15, 15, 15},
};
u1Byte gDeltaSwingTableIdx_MP_5GA_P_TxPowerTrack_USB_8812A[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 2, 3, 4, 5, 6,  7,  7,  8,  8,  9, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 1, 2, 3, 3, 4, 5, 6,  7,  7,  8,  8,  9, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 1, 2, 3, 3, 4, 5, 6,  7,  7,  8,  8,  9, 10, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
};
u1Byte gDeltaSwingTableIdx_MP_2GB_N_TxPowerTrack_USB_8812A[]    = {0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  5,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 11, 11, 11, 11};
u1Byte gDeltaSwingTableIdx_MP_2GB_P_TxPowerTrack_USB_8812A[]    = {0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  4,  5,  5,  5,  6,  6,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7};
u1Byte gDeltaSwingTableIdx_MP_2GA_N_TxPowerTrack_USB_8812A[]    = {0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  4,  5,  5,  5,  6,  6,  6,  7,  7,  7,  8,  8,  9, 10, 10, 10, 10, 10, 10};
u1Byte gDeltaSwingTableIdx_MP_2GA_P_TxPowerTrack_USB_8812A[]    = {0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  4,  5,  5,  5,  6,  6,  6,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7};
u1Byte gDeltaSwingTableIdx_MP_2GCCKB_N_TxPowerTrack_USB_8812A[] = {0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  5,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 11, 11, 11, 11};
u1Byte gDeltaSwingTableIdx_MP_2GCCKB_P_TxPowerTrack_USB_8812A[] = {0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  4,  5,  5,  5,  6,  6,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7};
u1Byte gDeltaSwingTableIdx_MP_2GCCKA_N_TxPowerTrack_USB_8812A[] = {0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  4,  5,  5,  5,  6,  6,  6,  7,  7,  7,  8,  8,  9, 10, 10, 10, 10, 10, 10};
u1Byte gDeltaSwingTableIdx_MP_2GCCKA_P_TxPowerTrack_USB_8812A[] = {0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  4,  5,  5,  5,  6,  6,  6,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7};

void ODM_ReadAndConfig_MP_8812A_TxPowerTrack_USB(PDM_ODM_T pDM_Odm)
{
	PODM_RF_CAL_T  pRFCalibrateInfo = &(pDM_Odm->RFCalibrateInfo);

	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ReadAndConfig_MP_MP_8812A\n"));

	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_2GA_P, gDeltaSwingTableIdx_MP_2GA_P_TxPowerTrack_USB_8812A, DELTA_SWINGIDX_SIZE);
	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_2GA_N, gDeltaSwingTableIdx_MP_2GA_N_TxPowerTrack_USB_8812A, DELTA_SWINGIDX_SIZE);
	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_2GB_P, gDeltaSwingTableIdx_MP_2GB_P_TxPowerTrack_USB_8812A, DELTA_SWINGIDX_SIZE);
	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_2GB_N, gDeltaSwingTableIdx_MP_2GB_N_TxPowerTrack_USB_8812A, DELTA_SWINGIDX_SIZE);

	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKA_P, gDeltaSwingTableIdx_MP_2GCCKA_P_TxPowerTrack_USB_8812A, DELTA_SWINGIDX_SIZE);
	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKA_N, gDeltaSwingTableIdx_MP_2GCCKA_N_TxPowerTrack_USB_8812A, DELTA_SWINGIDX_SIZE);
	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKB_P, gDeltaSwingTableIdx_MP_2GCCKB_P_TxPowerTrack_USB_8812A, DELTA_SWINGIDX_SIZE);
	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKB_N, gDeltaSwingTableIdx_MP_2GCCKB_N_TxPowerTrack_USB_8812A, DELTA_SWINGIDX_SIZE);

	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_5GA_P, gDeltaSwingTableIdx_MP_5GA_P_TxPowerTrack_USB_8812A, DELTA_SWINGIDX_SIZE*3);
	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_5GA_N, gDeltaSwingTableIdx_MP_5GA_N_TxPowerTrack_USB_8812A, DELTA_SWINGIDX_SIZE*3);
	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_5GB_P, gDeltaSwingTableIdx_MP_5GB_P_TxPowerTrack_USB_8812A, DELTA_SWINGIDX_SIZE*3);
	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_5GB_N, gDeltaSwingTableIdx_MP_5GB_N_TxPowerTrack_USB_8812A, DELTA_SWINGIDX_SIZE*3);
}

/******************************************************************************
*                           TxPowerTrack_USB_RFE3.TXT
******************************************************************************/

u1Byte gDeltaSwingTableIdx_MP_5GB_N_TxPowerTrack_USB_RFE3_8812A[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 3, 3, 4, 5, 5,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 12, 13, 13, 14, 15, 16, 16, 17, 17, 18, 18},
	{0, 1, 1, 2, 2, 3, 3, 4, 4,  5,  6,  7,  8,  8,  9,  9, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 1, 2, 2, 3, 3, 4, 4,  5,  6,  6,  7,  7,  8,  9, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
};
u1Byte gDeltaSwingTableIdx_MP_5GB_P_TxPowerTrack_USB_RFE3_8812A[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 3, 3, 4, 5, 6,  7,  7,  8,  9,  9, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 1, 2, 2, 3, 3, 4, 4,  5,  6,  7,  8,  8,  9,  9, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 1, 2, 2, 3, 3, 4, 4,  5,  6,  6,  7,  7,  8,  9, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
};
u1Byte gDeltaSwingTableIdx_MP_5GA_N_TxPowerTrack_USB_RFE3_8812A[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 3, 3, 4, 5, 5,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 12, 13, 14, 15, 16, 16, 17, 17, 18, 18},
	{0, 1, 1, 2, 3, 3, 4, 4, 5,  6,  6,  7,  7,  8,  9,  9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 15, 16, 16, 17, 17},
	{0, 1, 1, 2, 3, 3, 4, 4, 5,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 12, 13, 13, 14, 14, 15, 15, 16, 17, 18, 18},
};
u1Byte gDeltaSwingTableIdx_MP_5GA_P_TxPowerTrack_USB_RFE3_8812A[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 2, 3, 4, 5, 6,  7,  7,  8,  9,  9, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 2, 3, 4, 4, 5, 5, 6,  7,  7,  8,  9,  9, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 2, 3, 4, 4, 5, 5, 6,  7,  7,  8,  9,  9, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
};
u1Byte gDeltaSwingTableIdx_MP_2GB_N_TxPowerTrack_USB_RFE3_8812A[]    = {0, 1, 1, 2, 2, 3, 3, 4, 4,  4,  5,  5,  6,  6,  6,  7,  7,  7,  8,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15};
u1Byte gDeltaSwingTableIdx_MP_2GB_P_TxPowerTrack_USB_RFE3_8812A[]    = {0, 1, 1, 2, 2, 2, 2, 3, 3,  3,  4,  4,  5,  5,  5,  6,  6,  7,  7,  8,  9, 10, 10, 10, 10, 11, 11, 11, 11, 11};
u1Byte gDeltaSwingTableIdx_MP_2GA_N_TxPowerTrack_USB_RFE3_8812A[]    = {0, 1, 1, 2, 2, 3, 4, 5, 6,  6,  6,  7,  7,  8,  8,  9, 10, 10, 11, 11, 12, 12, 13, 13, 13, 13, 14, 14, 15, 15};
u1Byte gDeltaSwingTableIdx_MP_2GA_P_TxPowerTrack_USB_RFE3_8812A[]    = {0, 0, 1, 1, 1, 2, 2, 3, 3,  4,  4,  4,  5,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 11, 11, 11};
u1Byte gDeltaSwingTableIdx_MP_2GCCKB_N_TxPowerTrack_USB_RFE3_8812A[] = {0, 1, 1, 2, 2, 3, 3, 4, 4,  4,  5,  5,  6,  6,  6,  7,  7,  7,  8,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15};
u1Byte gDeltaSwingTableIdx_MP_2GCCKB_P_TxPowerTrack_USB_RFE3_8812A[] = {0, 1, 1, 2, 2, 2, 2, 3, 3,  3,  4,  4,  5,  5,  5,  6,  6,  7,  7,  8,  9, 10, 10, 10, 10, 11, 11, 11, 11, 11};
u1Byte gDeltaSwingTableIdx_MP_2GCCKA_N_TxPowerTrack_USB_RFE3_8812A[] = {0, 1, 1, 2, 2, 3, 4, 5, 6,  6,  6,  7,  7,  8,  8,  9, 10, 10, 11, 11, 12, 12, 13, 13, 13, 13, 14, 14, 15, 15};
u1Byte gDeltaSwingTableIdx_MP_2GCCKA_P_TxPowerTrack_USB_RFE3_8812A[] = {0, 0, 1, 1, 1, 2, 2, 3, 3,  4,  4,  4,  5,  5,  5,  6,  6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 11, 11, 11};

void ODM_ReadAndConfig_MP_8812A_TxPowerTrack_USB_RFE3(PDM_ODM_T pDM_Odm)
{
	PODM_RF_CAL_T  pRFCalibrateInfo = &(pDM_Odm->RFCalibrateInfo);

	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ReadAndConfig_MP_MP_8812A\n"));

	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_2GA_P, gDeltaSwingTableIdx_MP_2GA_P_TxPowerTrack_USB_RFE3_8812A, DELTA_SWINGIDX_SIZE);
	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_2GA_N, gDeltaSwingTableIdx_MP_2GA_N_TxPowerTrack_USB_RFE3_8812A, DELTA_SWINGIDX_SIZE);
	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_2GB_P, gDeltaSwingTableIdx_MP_2GB_P_TxPowerTrack_USB_RFE3_8812A, DELTA_SWINGIDX_SIZE);
	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_2GB_N, gDeltaSwingTableIdx_MP_2GB_N_TxPowerTrack_USB_RFE3_8812A, DELTA_SWINGIDX_SIZE);

	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKA_P, gDeltaSwingTableIdx_MP_2GCCKA_P_TxPowerTrack_USB_RFE3_8812A, DELTA_SWINGIDX_SIZE);
	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKA_N, gDeltaSwingTableIdx_MP_2GCCKA_N_TxPowerTrack_USB_RFE3_8812A, DELTA_SWINGIDX_SIZE);
	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKB_P, gDeltaSwingTableIdx_MP_2GCCKB_P_TxPowerTrack_USB_RFE3_8812A, DELTA_SWINGIDX_SIZE);
	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_2GCCKB_N, gDeltaSwingTableIdx_MP_2GCCKB_N_TxPowerTrack_USB_RFE3_8812A, DELTA_SWINGIDX_SIZE);

	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_5GA_P, gDeltaSwingTableIdx_MP_5GA_P_TxPowerTrack_USB_RFE3_8812A, DELTA_SWINGIDX_SIZE*3);
	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_5GA_N, gDeltaSwingTableIdx_MP_5GA_N_TxPowerTrack_USB_RFE3_8812A, DELTA_SWINGIDX_SIZE*3);
	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_5GB_P, gDeltaSwingTableIdx_MP_5GB_P_TxPowerTrack_USB_RFE3_8812A, DELTA_SWINGIDX_SIZE*3);
	memcpy(pRFCalibrateInfo->DeltaSwingTableIdx_5GB_N, gDeltaSwingTableIdx_MP_5GB_N_TxPowerTrack_USB_RFE3_8812A, DELTA_SWINGIDX_SIZE*3);
}

/******************************************************************************
*                           TXPWR_LMT.TXT
******************************************************************************/


#endif

