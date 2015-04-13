#include "dm.h"
#include "phy.h"
#include <odm_precomp.h>

u8 CCKSwingTable_Ch1_Ch13_New[CCK_TABLE_SIZE][8] = {
	{0x09, 0x08, 0x07, 0x06, 0x04, 0x03, 0x01, 0x01},	/*  0, -16.0dB */
	{0x09, 0x09, 0x08, 0x06, 0x05, 0x03, 0x01, 0x01},	/*  1, -15.5dB */
	{0x0a, 0x09, 0x08, 0x07, 0x05, 0x03, 0x02, 0x01},	/*  2, -15.0dB */
	{0x0a, 0x0a, 0x09, 0x07, 0x05, 0x03, 0x02, 0x01},	/*  3, -14.5dB */
	{0x0b, 0x0a, 0x09, 0x08, 0x06, 0x04, 0x02, 0x01},	/*  4, -14.0dB */
	{0x0b, 0x0b, 0x0a, 0x08, 0x06, 0x04, 0x02, 0x01},	/*  5, -13.5dB */
	{0x0c, 0x0c, 0x0a, 0x09, 0x06, 0x04, 0x02, 0x01},	/*  6, -13.0dB */
	{0x0d, 0x0c, 0x0b, 0x09, 0x07, 0x04, 0x02, 0x01},	/*  7, -12.5dB */
	{0x0d, 0x0d, 0x0c, 0x0a, 0x07, 0x05, 0x02, 0x01},	/*  8, -12.0dB */
	{0x0e, 0x0e, 0x0c, 0x0a, 0x08, 0x05, 0x02, 0x01},	/*  9, -11.5dB */
	{0x0f, 0x0f, 0x0d, 0x0b, 0x08, 0x05, 0x03, 0x01},	/* 10, -11.0dB */
	{0x10, 0x10, 0x0e, 0x0b, 0x08, 0x05, 0x03, 0x01},	/* 11, -10.5dB */
	{0x11, 0x11, 0x0f, 0x0c, 0x09, 0x06, 0x03, 0x01},	/* 12, -10.0dB */
	{0x12, 0x12, 0x0f, 0x0c, 0x09, 0x06, 0x03, 0x01},	/* 13, -9.5dB */
	{0x13, 0x13, 0x10, 0x0d, 0x0a, 0x06, 0x03, 0x01},	/* 14, -9.0dB */
	{0x14, 0x14, 0x11, 0x0e, 0x0b, 0x07, 0x03, 0x02},	/* 15, -8.5dB */
	{0x16, 0x15, 0x12, 0x0f, 0x0b, 0x07, 0x04, 0x01},	/* 16, -8.0dB */
	{0x17, 0x16, 0x13, 0x10, 0x0c, 0x08, 0x04, 0x02},	/* 17, -7.5dB */
	{0x18, 0x17, 0x15, 0x11, 0x0c, 0x08, 0x04, 0x02},	/* 18, -7.0dB */
	{0x1a, 0x19, 0x16, 0x12, 0x0d, 0x09, 0x04, 0x02},	/* 19, -6.5dB */
	{0x1b, 0x1a, 0x17, 0x13, 0x0e, 0x09, 0x04, 0x02},	/* 20, -6.0dB */
	{0x1d, 0x1c, 0x18, 0x14, 0x0f, 0x0a, 0x05, 0x02},	/* 21, -5.5dB */
	{0x1f, 0x1e, 0x1a, 0x15, 0x10, 0x0a, 0x05, 0x02},	/* 22, -5.0dB */
	{0x20, 0x20, 0x1b, 0x16, 0x11, 0x08, 0x05, 0x02},	/* 23, -4.5dB */
	{0x22, 0x21, 0x1d, 0x18, 0x11, 0x0b, 0x06, 0x02},	/* 24, -4.0dB */
	{0x24, 0x23, 0x1f, 0x19, 0x13, 0x0c, 0x06, 0x03},	/* 25, -3.5dB */
	{0x26, 0x25, 0x21, 0x1b, 0x14, 0x0d, 0x06, 0x03},	/* 26, -3.0dB */
	{0x28, 0x28, 0x22, 0x1c, 0x15, 0x0d, 0x07, 0x03},	/* 27, -2.5dB */
	{0x2b, 0x2a, 0x25, 0x1e, 0x16, 0x0e, 0x07, 0x03},	/* 28, -2.0dB */
	{0x2d, 0x2d, 0x27, 0x1f, 0x18, 0x0f, 0x08, 0x03},	/* 29, -1.5dB */
	{0x30, 0x2f, 0x29, 0x21, 0x19, 0x10, 0x08, 0x03},	/* 30, -1.0dB */
	{0x33, 0x32, 0x2b, 0x23, 0x1a, 0x11, 0x08, 0x04},	/* 31, -0.5dB */
	{0x36, 0x35, 0x2e, 0x25, 0x1c, 0x12, 0x09, 0x04} 	/* 32, +0dB */
};

u8 CCKSwingTable_Ch14_New[CCK_TABLE_SIZE][8] = {
	{0x09, 0x08, 0x07, 0x04, 0x00, 0x00, 0x00, 0x00},	/*  0, -16.0dB */
	{0x09, 0x09, 0x08, 0x05, 0x00, 0x00, 0x00, 0x00},	/*  1, -15.5dB */
	{0x0a, 0x09, 0x08, 0x05, 0x00, 0x00, 0x00, 0x00},	/*  2, -15.0dB */
	{0x0a, 0x0a, 0x09, 0x05, 0x00, 0x00, 0x00, 0x00},	/*  3, -14.5dB */
	{0x0b, 0x0a, 0x09, 0x05, 0x00, 0x00, 0x00, 0x00},	/*  4, -14.0dB */
	{0x0b, 0x0b, 0x0a, 0x06, 0x00, 0x00, 0x00, 0x00},	/*  5, -13.5dB */
	{0x0c, 0x0c, 0x0a, 0x06, 0x00, 0x00, 0x00, 0x00},	/*  6, -13.0dB */
	{0x0d, 0x0c, 0x0b, 0x06, 0x00, 0x00, 0x00, 0x00},	/*  7, -12.5dB */
	{0x0d, 0x0d, 0x0c, 0x07, 0x00, 0x00, 0x00, 0x00},	/*  8, -12.0dB */
	{0x0e, 0x0e, 0x0c, 0x07, 0x00, 0x00, 0x00, 0x00},	/*  9, -11.5dB */
	{0x0f, 0x0f, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00},	/* 10, -11.0dB */
	{0x10, 0x10, 0x0e, 0x08, 0x00, 0x00, 0x00, 0x00},	/* 11, -10.5dB */
	{0x11, 0x11, 0x0f, 0x09, 0x00, 0x00, 0x00, 0x00},	/* 12, -10.0dB */
	{0x12, 0x12, 0x0f, 0x09, 0x00, 0x00, 0x00, 0x00},	/* 13, -9.5dB */
	{0x13, 0x13, 0x10, 0x0a, 0x00, 0x00, 0x00, 0x00},	/* 14, -9.0dB */
	{0x14, 0x14, 0x11, 0x0a, 0x00, 0x00, 0x00, 0x00},	/* 15, -8.5dB */
	{0x16, 0x15, 0x12, 0x0b, 0x00, 0x00, 0x00, 0x00},	/* 16, -8.0dB */
	{0x17, 0x16, 0x13, 0x0b, 0x00, 0x00, 0x00, 0x00},	/* 17, -7.5dB */
	{0x18, 0x17, 0x15, 0x0c, 0x00, 0x00, 0x00, 0x00},	/* 18, -7.0dB */
	{0x1a, 0x19, 0x16, 0x0d, 0x00, 0x00, 0x00, 0x00},	/* 19, -6.5dB */
	{0x1b, 0x1a, 0x17, 0x0e, 0x00, 0x00, 0x00, 0x00},	/* 20, -6.0dB */
	{0x1d, 0x1c, 0x18, 0x0e, 0x00, 0x00, 0x00, 0x00},	/* 21, -5.5dB */
	{0x1f, 0x1e, 0x1a, 0x0f, 0x00, 0x00, 0x00, 0x00},	/* 22, -5.0dB */
	{0x20, 0x20, 0x1b, 0x10, 0x00, 0x00, 0x00, 0x00},	/* 23, -4.5dB */
	{0x22, 0x21, 0x1d, 0x11, 0x00, 0x00, 0x00, 0x00},	/* 24, -4.0dB */
	{0x24, 0x23, 0x1f, 0x12, 0x00, 0x00, 0x00, 0x00},	/* 25, -3.5dB */
	{0x26, 0x25, 0x21, 0x13, 0x00, 0x00, 0x00, 0x00},	/* 26, -3.0dB */
	{0x28, 0x28, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00},	/* 27, -2.5dB */
	{0x2b, 0x2a, 0x25, 0x15, 0x00, 0x00, 0x00, 0x00},	/* 28, -2.0dB */
	{0x2d, 0x2d, 0x17, 0x17, 0x00, 0x00, 0x00, 0x00},	/* 29, -1.5dB */
	{0x30, 0x2f, 0x29, 0x18, 0x00, 0x00, 0x00, 0x00},	/* 30, -1.0dB */
	{0x33, 0x32, 0x2b, 0x19, 0x00, 0x00, 0x00, 0x00},	/* 31, -0.5dB */
	{0x36, 0x35, 0x2e, 0x1b, 0x00, 0x00, 0x00, 0x00} 	/* 32, +0dB */
};


u8	CCKSwingTable_Ch1_Ch13[CCK_TABLE_SIZE][8] = {
	{0x36, 0x35, 0x2e, 0x25, 0x1c, 0x12, 0x09, 0x04},	/* 0, +0dB */
	{0x33, 0x32, 0x2b, 0x23, 0x1a, 0x11, 0x08, 0x04},	/* 1, -0.5dB */
	{0x30, 0x2f, 0x29, 0x21, 0x19, 0x10, 0x08, 0x03},	/* 2, -1.0dB */
	{0x2d, 0x2d, 0x27, 0x1f, 0x18, 0x0f, 0x08, 0x03},	/* 3, -1.5dB */
	{0x2b, 0x2a, 0x25, 0x1e, 0x16, 0x0e, 0x07, 0x03},	/* 4, -2.0dB */
	{0x28, 0x28, 0x22, 0x1c, 0x15, 0x0d, 0x07, 0x03},	/* 5, -2.5dB */
	{0x26, 0x25, 0x21, 0x1b, 0x14, 0x0d, 0x06, 0x03},	/* 6, -3.0dB */
	{0x24, 0x23, 0x1f, 0x19, 0x13, 0x0c, 0x06, 0x03},	/* 7, -3.5dB */
	{0x22, 0x21, 0x1d, 0x18, 0x11, 0x0b, 0x06, 0x02},	/* 8, -4.0dB */
	{0x20, 0x20, 0x1b, 0x16, 0x11, 0x08, 0x05, 0x02},	/* 9, -4.5dB */
	{0x1f, 0x1e, 0x1a, 0x15, 0x10, 0x0a, 0x05, 0x02},	/* 10, -5.0dB */
	{0x1d, 0x1c, 0x18, 0x14, 0x0f, 0x0a, 0x05, 0x02},	/* 11, -5.5dB */
	{0x1b, 0x1a, 0x17, 0x13, 0x0e, 0x09, 0x04, 0x02},	/* 12, -6.0dB <== default */
	{0x1a, 0x19, 0x16, 0x12, 0x0d, 0x09, 0x04, 0x02},	/* 13, -6.5dB */
	{0x18, 0x17, 0x15, 0x11, 0x0c, 0x08, 0x04, 0x02},	/* 14, -7.0dB */
	{0x17, 0x16, 0x13, 0x10, 0x0c, 0x08, 0x04, 0x02},	/* 15, -7.5dB */
	{0x16, 0x15, 0x12, 0x0f, 0x0b, 0x07, 0x04, 0x01},	/* 16, -8.0dB */
	{0x14, 0x14, 0x11, 0x0e, 0x0b, 0x07, 0x03, 0x02},	/* 17, -8.5dB */
	{0x13, 0x13, 0x10, 0x0d, 0x0a, 0x06, 0x03, 0x01},	/* 18, -9.0dB */
	{0x12, 0x12, 0x0f, 0x0c, 0x09, 0x06, 0x03, 0x01},	/* 19, -9.5dB */
	{0x11, 0x11, 0x0f, 0x0c, 0x09, 0x06, 0x03, 0x01},	/* 20, -10.0dB */
	{0x10, 0x10, 0x0e, 0x0b, 0x08, 0x05, 0x03, 0x01},	/* 21, -10.5dB */
	{0x0f, 0x0f, 0x0d, 0x0b, 0x08, 0x05, 0x03, 0x01},	/* 22, -11.0dB */
	{0x0e, 0x0e, 0x0c, 0x0a, 0x08, 0x05, 0x02, 0x01},	/* 23, -11.5dB */
	{0x0d, 0x0d, 0x0c, 0x0a, 0x07, 0x05, 0x02, 0x01},	/* 24, -12.0dB */
	{0x0d, 0x0c, 0x0b, 0x09, 0x07, 0x04, 0x02, 0x01},	/* 25, -12.5dB */
	{0x0c, 0x0c, 0x0a, 0x09, 0x06, 0x04, 0x02, 0x01},	/* 26, -13.0dB */
	{0x0b, 0x0b, 0x0a, 0x08, 0x06, 0x04, 0x02, 0x01},	/* 27, -13.5dB */
	{0x0b, 0x0a, 0x09, 0x08, 0x06, 0x04, 0x02, 0x01},	/* 28, -14.0dB */
	{0x0a, 0x0a, 0x09, 0x07, 0x05, 0x03, 0x02, 0x01},	/* 29, -14.5dB */
	{0x0a, 0x09, 0x08, 0x07, 0x05, 0x03, 0x02, 0x01},	/* 30, -15.0dB */
	{0x09, 0x09, 0x08, 0x06, 0x05, 0x03, 0x01, 0x01},	/* 31, -15.5dB */
	{0x09, 0x08, 0x07, 0x06, 0x04, 0x03, 0x01, 0x01}	/* 32, -16.0dB */
};


u8	CCKSwingTable_Ch14[CCK_TABLE_SIZE][8] = {
	{0x36, 0x35, 0x2e, 0x1b, 0x00, 0x00, 0x00, 0x00},	/* 0, +0dB */
	{0x33, 0x32, 0x2b, 0x19, 0x00, 0x00, 0x00, 0x00},	/* 1, -0.5dB */
	{0x30, 0x2f, 0x29, 0x18, 0x00, 0x00, 0x00, 0x00},	/* 2, -1.0dB */
	{0x2d, 0x2d, 0x17, 0x17, 0x00, 0x00, 0x00, 0x00},	/* 3, -1.5dB */
	{0x2b, 0x2a, 0x25, 0x15, 0x00, 0x00, 0x00, 0x00},	/* 4, -2.0dB */
	{0x28, 0x28, 0x24, 0x14, 0x00, 0x00, 0x00, 0x00},	/* 5, -2.5dB */
	{0x26, 0x25, 0x21, 0x13, 0x00, 0x00, 0x00, 0x00},	/* 6, -3.0dB */
	{0x24, 0x23, 0x1f, 0x12, 0x00, 0x00, 0x00, 0x00},	/* 7, -3.5dB */
	{0x22, 0x21, 0x1d, 0x11, 0x00, 0x00, 0x00, 0x00},	/* 8, -4.0dB */
	{0x20, 0x20, 0x1b, 0x10, 0x00, 0x00, 0x00, 0x00},	/* 9, -4.5dB */
	{0x1f, 0x1e, 0x1a, 0x0f, 0x00, 0x00, 0x00, 0x00},	/* 10, -5.0dB */
	{0x1d, 0x1c, 0x18, 0x0e, 0x00, 0x00, 0x00, 0x00},	/* 11, -5.5dB */
	{0x1b, 0x1a, 0x17, 0x0e, 0x00, 0x00, 0x00, 0x00},	/* 12, -6.0dB  <== default */
	{0x1a, 0x19, 0x16, 0x0d, 0x00, 0x00, 0x00, 0x00},	/* 13, -6.5dB */
	{0x18, 0x17, 0x15, 0x0c, 0x00, 0x00, 0x00, 0x00},	/* 14, -7.0dB */
	{0x17, 0x16, 0x13, 0x0b, 0x00, 0x00, 0x00, 0x00},	/* 15, -7.5dB */
	{0x16, 0x15, 0x12, 0x0b, 0x00, 0x00, 0x00, 0x00},	/* 16, -8.0dB */
	{0x14, 0x14, 0x11, 0x0a, 0x00, 0x00, 0x00, 0x00},	/* 17, -8.5dB */
	{0x13, 0x13, 0x10, 0x0a, 0x00, 0x00, 0x00, 0x00},	/* 18, -9.0dB */
	{0x12, 0x12, 0x0f, 0x09, 0x00, 0x00, 0x00, 0x00},	/* 19, -9.5dB */
	{0x11, 0x11, 0x0f, 0x09, 0x00, 0x00, 0x00, 0x00},	/* 20, -10.0dB */
	{0x10, 0x10, 0x0e, 0x08, 0x00, 0x00, 0x00, 0x00},	/* 21, -10.5dB */
	{0x0f, 0x0f, 0x0d, 0x08, 0x00, 0x00, 0x00, 0x00},	/* 22, -11.0dB */
	{0x0e, 0x0e, 0x0c, 0x07, 0x00, 0x00, 0x00, 0x00},	/* 23, -11.5dB */
	{0x0d, 0x0d, 0x0c, 0x07, 0x00, 0x00, 0x00, 0x00},	/* 24, -12.0dB */
	{0x0d, 0x0c, 0x0b, 0x06, 0x00, 0x00, 0x00, 0x00},	/* 25, -12.5dB */
	{0x0c, 0x0c, 0x0a, 0x06, 0x00, 0x00, 0x00, 0x00},	/* 26, -13.0dB */
	{0x0b, 0x0b, 0x0a, 0x06, 0x00, 0x00, 0x00, 0x00},	/* 27, -13.5dB */
	{0x0b, 0x0a, 0x09, 0x05, 0x00, 0x00, 0x00, 0x00},	/* 28, -14.0dB */
	{0x0a, 0x0a, 0x09, 0x05, 0x00, 0x00, 0x00, 0x00},	/* 29, -14.5dB */
	{0x0a, 0x09, 0x08, 0x05, 0x00, 0x00, 0x00, 0x00},	/* 30, -15.0dB */
	{0x09, 0x09, 0x08, 0x05, 0x00, 0x00, 0x00, 0x00},	/* 31, -15.5dB */
	{0x09, 0x08, 0x07, 0x04, 0x00, 0x00, 0x00, 0x00}	/* 32, -16.0dB */
};

/*
 * 2011/09/21 MH Add to describe different team necessary resource allocate??
 */

static void odm_CommonInfoSelfInit(struct _rtw_dm *pDM_Odm)
{
	pDM_Odm->bCckHighPower = (BOOLEAN) rtl_get_bbreg(pDM_Odm->rtlpriv, ODM_REG(CCK_RPT_FORMAT, pDM_Odm), ODM_BIT(CCK_RPT_FORMAT, pDM_Odm));
	pDM_Odm->RFPathRxEnable = (u8) rtl_get_bbreg(pDM_Odm->rtlpriv, ODM_REG(BB_RX_PATH, pDM_Odm), ODM_BIT(BB_RX_PATH, pDM_Odm));
	pDM_Odm->pbNet_closed = &pDM_Odm->BOOLEAN_temp;


	pDM_Odm->TxRate = 0xFF;
	ODM_InitDebugSetting(pDM_Odm);
}

static void odm_DIGInit(struct _rtw_dm *pDM_Odm)
{
	struct rtl_hal	*rtlhal = rtl_hal(pDM_Odm->rtlpriv);
	
	pDIG_T	pDM_DigTable = &pDM_Odm->DM_DigTable;

	/* pDM_DigTable->Dig_Enable_Flag = TRUE; */
	/* pDM_DigTable->Dig_Ext_Port_Stage = DIG_EXT_PORT_STAGE_MAX; */
	pDM_DigTable->CurIGValue = (u8) rtl_get_bbreg(pDM_Odm->rtlpriv, ODM_REG(IGI_A, pDM_Odm), ODM_BIT(IGI, pDM_Odm));
	/* pDM_DigTable->PreIGValue = 0x0; */
	/* pDM_DigTable->CurSTAConnectState = pDM_DigTable->PreSTAConnectState = DIG_STA_DISCONNECT; */
	/* pDM_DigTable->CurMultiSTAConnectState = DIG_MultiSTA_DISCONNECT; */
	pDM_DigTable->RssiLowThresh 	= DM_DIG_THRESH_LOW;
	pDM_DigTable->RssiHighThresh 	= DM_DIG_THRESH_HIGH;
	pDM_DigTable->FALowThresh	= DM_FALSEALARM_THRESH_LOW;
	pDM_DigTable->FAHighThresh	= DM_FALSEALARM_THRESH_HIGH;

	if (rtlhal->board_type & (ODM_BOARD_EXT_PA|ODM_BOARD_EXT_LNA)) {
		pDM_DigTable->rx_gain_range_max = DM_DIG_MAX_NIC;
		pDM_DigTable->rx_gain_range_min = DM_DIG_MIN_NIC;
	} else {
		pDM_DigTable->rx_gain_range_max = DM_DIG_MAX_NIC;
		pDM_DigTable->rx_gain_range_min = DM_DIG_MIN_NIC;
	}
	pDM_DigTable->BackoffVal = DM_DIG_BACKOFF_DEFAULT;
	pDM_DigTable->BackoffVal_range_max = DM_DIG_BACKOFF_MAX;
	pDM_DigTable->BackoffVal_range_min = DM_DIG_BACKOFF_MIN;
	pDM_DigTable->PreCCK_CCAThres = 0xFF;
	pDM_DigTable->CurCCK_CCAThres = 0x83;
	pDM_DigTable->ForbiddenIGI = DM_DIG_MIN_NIC;
	pDM_DigTable->LargeFAHit = 0;
	pDM_DigTable->Recover_cnt = 0;
	pDM_DigTable->DIG_Dynamic_MIN_0 = DM_DIG_MIN_NIC;
	pDM_DigTable->DIG_Dynamic_MIN_1 = DM_DIG_MIN_NIC;
	pDM_DigTable->bMediaConnect_0 = FALSE;
	pDM_DigTable->bMediaConnect_1 = FALSE;

	/* To Initialize pDM_Odm->bDMInitialGainEnable == FALSE to avoid DIG error */
	pDM_Odm->bDMInitialGainEnable = TRUE;

	/* To Initi BT30 IGI */
	pDM_DigTable->BT30_CurIGI = 0x32;

}

static void odm_AdaptivityInit(struct _rtw_dm *pDM_Odm)
{
	struct rtl_priv *rtlpriv = pDM_Odm->rtlpriv;

	pDM_Odm->TH_H = 0xfa; 		/* -6dB */
	pDM_Odm->TH_L = 0xfd; 		/* -3dB */
	pDM_Odm->IGI_Base = 0x32;
	pDM_Odm->IGI_target = 0x1c;
	pDM_Odm->ForceEDCCA = 0;
	pDM_Odm->AdapEn_RSSI = 32;	/* 45; */
}

static void odm_RateAdaptiveMaskInit(struct _rtw_dm *pDM_Odm)
{
	PODM_RATE_ADAPTIVE	pOdmRA = &pDM_Odm->RateAdaptive;

	pOdmRA->Type = DM_Type_ByDriver;
	if (pOdmRA->Type == DM_Type_ByDriver)
		pDM_Odm->bUseRAMask = _TRUE;
	else
		pDM_Odm->bUseRAMask = _FALSE;

	pOdmRA->RATRState = DM_RATR_STA_INIT;
	pOdmRA->LdpcThres = 35;
	pOdmRA->bUseLdpc = FALSE;
	pOdmRA->HighRSSIThresh = 50;
	pOdmRA->LowRSSIThresh = 20;
}

static void ODM_EdcaTurboInit(struct _rtw_dm *pDM_Odm)
{

	struct rtl_priv *rtlpriv = pDM_Odm->rtlpriv;
	pDM_Odm->DM_EDCA_Table.bCurrentTurboEDCA = FALSE;
	pDM_Odm->DM_EDCA_Table.bIsCurRDLState = FALSE;
	rtlpriv->recvpriv.bIsAnyNonBEPkts = FALSE;

	ODM_RT_TRACE(pDM_Odm, ODM_COMP_EDCA_TURBO, ODM_DBG_LOUD, ("Orginial VO PARAM: 0x%x\n", rtl_read_dword(pDM_Odm->rtlpriv, ODM_EDCA_VO_PARAM)));
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_EDCA_TURBO, ODM_DBG_LOUD, ("Orginial VI PARAM: 0x%x\n", rtl_read_dword(pDM_Odm->rtlpriv, ODM_EDCA_VI_PARAM)));
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_EDCA_TURBO, ODM_DBG_LOUD, ("Orginial BE PARAM: 0x%x\n", rtl_read_dword(pDM_Odm->rtlpriv, ODM_EDCA_BE_PARAM)));
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_EDCA_TURBO, ODM_DBG_LOUD, ("Orginial BK PARAM: 0x%x\n", rtl_read_dword(pDM_Odm->rtlpriv, ODM_EDCA_BK_PARAM)));


}

static u8 getSwingIndex(struct _rtw_dm *pDM_Odm)
{
	struct rtl_priv *	rtlpriv = pDM_Odm->rtlpriv;
	 struct _rtw_hal	*pHalData = GET_HAL_DATA(rtlpriv);
	u8 			i = 0;
	uint32_t 			bbSwing;

	bbSwing = phy_get_tx_swing_8821au(rtlpriv, pHalData->CurrentBandType, RF90_PATH_A);

	for (i = 0; i < TXSCALE_TABLE_SIZE; ++i)
		if (bbSwing == TxScalingTable_Jaguar[i])
			break;

	return i;
}



static void odm_TXPowerTrackingThermalMeterInit(struct _rtw_dm *pDM_Odm)
{
	u8 		p = 0;
	struct rtl_dm	*rtldm = rtl_dm(pDM_Odm->rtlpriv);
	struct rtl_priv *rtlpriv = pDM_Odm->rtlpriv;
	struct rtl_efuse *efuse = rtl_efuse(rtlpriv);
	 struct _rtw_hal	*pHalData = GET_HAL_DATA(rtlpriv);

	rtldm->bTXPowerTracking = _TRUE;
	rtldm->TXPowercount = 0;
	rtldm->bTXPowerTrackingInit = _FALSE;
	/* #if	(MP_DRIVER != 1) */		/* for mp driver, turn off txpwrtracking as default */
	if (*(pDM_Odm->mp_mode) != 1)
		rtldm->TxPowerTrackControl = _TRUE;
	/* #endif//#if	(MP_DRIVER != 1) */
	MSG_8192C("pDM_Odm TxPowerTrackControl = %d\n", rtldm->TxPowerTrackControl);

	rtldm->TxPowerTrackControl = TRUE;
	rtldm->thermalvalue = efuse->EEPROMThermalMeter;
	rtldm->thermalvalue_iqk = efuse->EEPROMThermalMeter;
	rtldm->thermalvalue_lck = efuse->EEPROMThermalMeter;

	/* The index of "0 dB" in SwingTable. */
	{
		u8 defaultSwingIndex = getSwingIndex(pDM_Odm);


		rtldm->DefaultOfdmIndex = (defaultSwingIndex == TXSCALE_TABLE_SIZE) ? 24 : defaultSwingIndex;
		rtldm->DefaultCckIndex = 24;
	}

	rtldm->BbSwingIdxCckBase = rtldm->DefaultCckIndex;
	rtldm->CCK_index = rtldm->DefaultCckIndex;

	for (p = RF90_PATH_A; p < MAX_RF_PATH; ++p) {
		rtldm->BbSwingIdxOfdmBase[p] = rtldm->DefaultOfdmIndex;
		rtldm->OFDM_index[p] = rtldm->DefaultOfdmIndex;
		rtldm->DeltaPowerIndex[p] = 0;
		rtldm->DeltaPowerIndexLast[p] = 0;
		rtldm->PowerIndexOffset[p] = 0;
	}
}

static void odm_TXPowerTrackingInit(struct _rtw_dm *pDM_Odm)
{
	odm_TXPowerTrackingThermalMeterInit(pDM_Odm);
}

void ODM_DMInit(struct _rtw_dm *pDM_Odm)
{
	/* 2012.05.03 Luke: For all IC series */
	odm_CommonInfoSelfInit(pDM_Odm);
	odm_DIGInit(pDM_Odm);
	odm_AdaptivityInit(pDM_Odm);
	odm_RateAdaptiveMaskInit(pDM_Odm);

	ODM_EdcaTurboInit(pDM_Odm);

	odm_TXPowerTrackingInit(pDM_Odm);
}

/* From hal/OUTSRC/rtl8812a/HalPhyRf_8812A.c */

/*
 * ============================================================
 *  Tx Power Tracking
 * ============================================================
 */
/* From hal/OUTSRC/rtl8812a/HalPhyRf_8812A.c, caution function pointer */
void DoIQK_8812A(struct rtl_priv *rtlpriv, u8 DeltaThermalIndex,
	u8 	ThermalValue, u8 Threshold)
{
	struct rtl_dm	*rtldm = rtl_dm(rtlpriv);

	rtldm->thermalvalue_iqk = ThermalValue;
	rtl8812au_phy_iq_calibrate(rtlpriv, FALSE);
}

/*-----------------------------------------------------------------------------
 * Function:	odm_TxPwrTrackSetPwr88E()
 *
 * Overview:	88E change all channel tx power accordign to flag.
 *				OFDM & CCK are all different.
 *
 * Input:		NONE
 *
 * Output:		NONE
 *
 * Return:		NONE
 *
 * Revised History:
 *	When		Who		Remark
 *	04/23/2012	MHC		Create Version 0.
 *
 *---------------------------------------------------------------------------*/

void ODM_TxPwrTrackSetPwr8812A(struct rtl_priv *rtlpriv, PWRTRACK_METHOD Method,
	u8 	RFPath, u8 	ChannelMappedIndex)
{
	uint32_t 	finalBbSwingIdx[2];

	struct rtl_dm	*rtldm = rtl_dm(rtlpriv);
	struct _rtw_hal *pHalData = GET_HAL_DATA(rtlpriv);

	u8 PwrTrackingLimit = 26; /* +1.0dB */
	u8 TxRate = 0xFF;
	s8 Final_OFDM_Swing_Index = 0;
	s8 Final_CCK_Swing_Index = 0;
	u8 i = 0;

	if (TxRate != 0xFF) {
		/* Ulli better with switch case, see in rtlwifi-lib */
		/* 2 CCK */
		if ((TxRate >= MGN_1M) && (TxRate <= MGN_11M))
			PwrTrackingLimit = 32;				/* +4dB */
		/* 2 OFDM */
		else if ((TxRate >= MGN_6M) && (TxRate <= MGN_48M))
			PwrTrackingLimit = 32;				/* +4dB */
		else if (TxRate == MGN_54M)
			PwrTrackingLimit = 30;				/* +3dB */

		/* ULLI 80211n */
		/* 2 HT */
		else if ((TxRate >= MGN_MCS0) && (TxRate <= MGN_MCS2))  /* QPSK/BPSK */
			PwrTrackingLimit = 34;				/* +5dB */
		else if ((TxRate >= MGN_MCS3) && (TxRate <= MGN_MCS4))  /* 16QAM */
			PwrTrackingLimit = 32;				/* +4dB */
		else if ((TxRate >= MGN_MCS5) && (TxRate <= MGN_MCS7))  /* 64QAM */
			PwrTrackingLimit = 30;				/* +3dB */

		else if ((TxRate >= MGN_MCS8) && (TxRate <= MGN_MCS10)) 	/* QPSK/BPSK */
			PwrTrackingLimit = 34; 				/* +5dB */
		else if ((TxRate >= MGN_MCS11) && (TxRate <= MGN_MCS12)) 	/* 16QAM */
			PwrTrackingLimit = 32; 				/* +4dB */
		else if ((TxRate >= MGN_MCS13) && (TxRate <= MGN_MCS15)) 	/* 64QAM */
			PwrTrackingLimit = 30; 				/* +3dB */

		/* Ulli 802.11ac */
		/* 2 VHT */
		else if ((TxRate >= MGN_VHT1SS_MCS0) && (TxRate <= MGN_VHT1SS_MCS2))    /* QPSK/BPSK */
			PwrTrackingLimit = 34;						/* +5dB */
		else if ((TxRate >= MGN_VHT1SS_MCS3) && (TxRate <= MGN_VHT1SS_MCS4))    /* 16QAM */
			PwrTrackingLimit = 32;						/* +4dB */
		else if ((TxRate >= MGN_VHT1SS_MCS5) && (TxRate <= MGN_VHT1SS_MCS6))    /* 64QAM */
			PwrTrackingLimit = 30;						/* +3dB */
		else if (TxRate == MGN_VHT1SS_MCS7)					/* 64QAM */
			PwrTrackingLimit = 28;						/* +2dB */
		else if (TxRate == MGN_VHT1SS_MCS8)					/* 256QAM */
			PwrTrackingLimit = 26;						/* +1dB */
		else if (TxRate == MGN_VHT1SS_MCS9)					/* 256QAM */
			PwrTrackingLimit = 24;						/* +0dB */

		else if ((TxRate >= MGN_VHT2SS_MCS0) && (TxRate <= MGN_VHT2SS_MCS2)) 	/* QPSK/BPSK */
			PwrTrackingLimit = 34; 						/* +5dB */
		else if ((TxRate >= MGN_VHT2SS_MCS3) && (TxRate <= MGN_VHT2SS_MCS4)) 	/* 16QAM */
			PwrTrackingLimit = 32; 						/* +4dB */
		else if ((TxRate >= MGN_VHT2SS_MCS5) && (TxRate <= MGN_VHT2SS_MCS6)) 	/* 64QAM */
			PwrTrackingLimit = 30; 						/* +3dB */
		else if (TxRate == MGN_VHT2SS_MCS7) 					/* 64QAM */
			PwrTrackingLimit = 28; 						/* +2dB */
		else if (TxRate == MGN_VHT2SS_MCS8) 					/* 256QAM */
			PwrTrackingLimit = 26; 						/* +1dB */
		else if (TxRate == MGN_VHT2SS_MCS9) 					/* 256QAM */
			PwrTrackingLimit = 24; 						/* +0dB */

		else
			PwrTrackingLimit = 24;
	}
#if 0	
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("TxRate=0x%x, PwrTrackingLimit=%d\n", TxRate, PwrTrackingLimit));
#endif
	if (Method == BBSWING) {
#if 0		
		ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("===>ODM_TxPwrTrackSetPwr8812A\n"));
#endif
		if (RFPath == RF90_PATH_A) {
			finalBbSwingIdx[RF90_PATH_A] = (rtldm->OFDM_index[RF90_PATH_A] > PwrTrackingLimit) ? PwrTrackingLimit : rtldm->OFDM_index[RF90_PATH_A];
#if 0			
			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("pDM_Odm->RFCalibrateInfo.OFDM_index[RF90_PATH_A]=%d, pDM_Odm->RealBbSwingIdx[RF90_PATH_A]=%d\n",
				rtldm->OFDM_index[RF90_PATH_A], finalBbSwingIdx[RF90_PATH_A]));
#endif
			rtl_set_bbreg(rtlpriv, rA_TxScale_Jaguar, 0xFFE00000, TxScalingTable_Jaguar[finalBbSwingIdx[RF90_PATH_A]]);
		} else {
			finalBbSwingIdx[RF90_PATH_B] = (rtldm->OFDM_index[RF90_PATH_B] > PwrTrackingLimit) ? PwrTrackingLimit : rtldm->OFDM_index[RF90_PATH_B];
#if 0			
			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("pDM_Odm->RFCalibrateInfo.OFDM_index[RF90_PATH_B]=%d, pDM_Odm->RealBbSwingIdx[RF90_PATH_B]=%d\n",
				rtldm->OFDM_index[RF90_PATH_B], finalBbSwingIdx[RF90_PATH_B]));
#endif
			rtl_set_bbreg(rtlpriv, rB_TxScale_Jaguar, 0xFFE00000, TxScalingTable_Jaguar[finalBbSwingIdx[RF90_PATH_B]]);
		}
	} else if (Method == MIX_MODE) {
#if 0		
			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("pDM_Odm->DefaultOfdmIndex=%d, pDM_Odm->Aboslute_OFDMSwingIdx[RFPath]=%d, RF_Path = %d\n",
				rtldm->DefaultOfdmIndex, rtldm->Aboslute_OFDMSwingIdx[RFPath], RFPath));
#endif

			Final_OFDM_Swing_Index = rtldm->DefaultOfdmIndex + rtldm->Aboslute_OFDMSwingIdx[RFPath];

			if (RFPath == RF90_PATH_A) {
				if (Final_OFDM_Swing_Index > PwrTrackingLimit) {    /* BBSwing higher then Limit */
					rtldm->Remnant_CCKSwingIdx = Final_OFDM_Swing_Index - PwrTrackingLimit;            /*  CCK Follow the same compensate value as Path A */
					rtldm->Remnant_OFDMSwingIdx[RFPath] = Final_OFDM_Swing_Index - PwrTrackingLimit;

					rtl_set_bbreg(rtlpriv, rA_TxScale_Jaguar, 0xFFE00000, TxScalingTable_Jaguar[PwrTrackingLimit]);

					rtldm->Modify_TxAGC_Flag_PathA = TRUE;

					/* et TxAGC Page C{}; */
					/* rtlpriv->cfg->ops.SetTxPowerLevelHandler(rtlpriv, pHalData->CurrentChannel); */
					PHY_SetTxPowerLevel8812(rtlpriv, rtlpriv->phy.current_channel);
#if 0
					ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("******Path_A Over BBSwing Limit , PwrTrackingLimit = %d , Remnant TxAGC Value = %d \n", PwrTrackingLimit, rtldm->Remnant_OFDMSwingIdx[RFPath]));
#endif				
				} else if (Final_OFDM_Swing_Index < 0) {
					rtldm->Remnant_CCKSwingIdx = Final_OFDM_Swing_Index;            /* CCK Follow the same compensate value as Path A */
					rtldm->Remnant_OFDMSwingIdx[RFPath] = Final_OFDM_Swing_Index;

					rtl_set_bbreg(rtlpriv, rA_TxScale_Jaguar, 0xFFE00000, TxScalingTable_Jaguar[0]);

					rtldm->Modify_TxAGC_Flag_PathA = TRUE;

					/* Set TxAGC Page C{}; */
					/* rtlpriv->cfg->ops.SetTxPowerLevelHandler(rtlpriv, pHalData->CurrentChannel);*/
					PHY_SetTxPowerLevel8812(rtlpriv, rtlpriv->phy.current_channel);
#if 0
					ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("******Path_A Lower then BBSwing lower bound  0 , Remnant TxAGC Value = %d \n", rtldm->Remnant_OFDMSwingIdx[RFPath]));
#endif					
				} else 	{
					rtl_set_bbreg(rtlpriv, rA_TxScale_Jaguar, 0xFFE00000, TxScalingTable_Jaguar[Final_OFDM_Swing_Index]);
#if 0
					ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("******Path_A Compensate with BBSwing , Final_OFDM_Swing_Index = %d \n", Final_OFDM_Swing_Index));
#endif
					if (rtldm->Modify_TxAGC_Flag_PathA) { /* If TxAGC has changed, reset TxAGC again */
						rtldm->Remnant_CCKSwingIdx = 0;
						rtldm->Remnant_OFDMSwingIdx[RFPath] = 0;

						/* Set TxAGC Page C{}; */
						/* rtlpriv->cfg->ops.SetTxPowerLevelHandler(rtlpriv, pHalData->CurrentChannel); */
						PHY_SetTxPowerLevel8812(rtlpriv, rtlpriv->phy.current_channel);

						rtldm->Modify_TxAGC_Flag_PathA = FALSE;
#if 0
						ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("******Path_A pDM_Odm->Modify_TxAGC_Flag = FALSE \n"));
#endif						
					}
				}
			}

			if (RFPath == RF90_PATH_B) {
				if (Final_OFDM_Swing_Index > PwrTrackingLimit) {			/* BBSwing higher then Limit */
					rtldm->Remnant_OFDMSwingIdx[RFPath] = Final_OFDM_Swing_Index - PwrTrackingLimit;

					rtl_set_bbreg(rtlpriv, rB_TxScale_Jaguar, 0xFFE00000, TxScalingTable_Jaguar[PwrTrackingLimit]);

					rtldm->Modify_TxAGC_Flag_PathB = TRUE;

					/* Set TxAGC Page E{}; */
#if 0
					ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("******Path_B Over BBSwing Limit , PwrTrackingLimit = %d , Remnant TxAGC Value = %d \n", PwrTrackingLimit, rtldm->Remnant_OFDMSwingIdx[RFPath]));
#endif					
				} else if (Final_OFDM_Swing_Index < 0) {
					rtldm->Remnant_OFDMSwingIdx[RFPath] = Final_OFDM_Swing_Index;

					rtl_set_bbreg(rtlpriv, rB_TxScale_Jaguar, 0xFFE00000, TxScalingTable_Jaguar[0]);

					rtldm->Modify_TxAGC_Flag_PathB = TRUE;

					/* Set TxAGC Page E{}; */
#if 0
					ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("******Path_B Lower then BBSwing lower bound  0 , Remnant TxAGC Value = %d \n", rtldm->Remnant_OFDMSwingIdx[RFPath]));
#endif					
				} else {
					rtl_set_bbreg(rtlpriv, rB_TxScale_Jaguar, 0xFFE00000, TxScalingTable_Jaguar[Final_OFDM_Swing_Index]);
#if 0
					ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("******Path_B Compensate with BBSwing , Final_OFDM_Swing_Index = %d \n", Final_OFDM_Swing_Index));
#endif
					if (rtldm->Modify_TxAGC_Flag_PathB) {			/* If TxAGC has changed, reset TxAGC again */
						rtldm->Remnant_CCKSwingIdx = 0;
						rtldm->Remnant_OFDMSwingIdx[RFPath] = 0;

						/* Set TxAGC Page E{}; */

						rtldm->Modify_TxAGC_Flag_PathB = FALSE;
#if 0
						ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("******Path_B pDM_Odm->Modify_TxAGC_Flag = FALSE \n"));
#endif						
					}
				}
			}

	} else {
		return;
	}
}

/* START Copied from hal/OUTSRC/rtl8812a/HalHWImg8812A_RF.c */
/******************************************************************************
*                           TxPowerTrack_USB.TXT
******************************************************************************/

static u8 rtl8812ae_delta_swing_table_idx_5gb_n[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 2, 3, 4, 5, 6,  6,  7,  7,  8,  8,  9,  9,
	10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 14, 14, 14, 14},
	{0, 1, 1, 2, 3, 3, 4, 5, 5,  6,  7,  7,  8,  8,  9,  9,
	10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 1, 2, 3, 3, 4, 5, 6,  7,  7,  8,  8,  9,  9, 10,
	11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
};

static u8 rtl8812ae_delta_swing_table_idx_5gb_p[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 2, 3, 3, 4, 5,  6,  7,  7,  8,  8,  9,  9, 
	10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 1, 2, 3, 3, 4, 5, 5,  6,  7,  7,  8,  8,  9,  9,
	10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 1, 2, 3, 3, 4, 5, 6,  7,  7,  8,  8,  9,  9, 10, 
	11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
};

static u8 rtl8812ae_delta_swing_table_idx_5ga_n[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 2, 3, 4, 5, 6,  6,  7,  7,  8,  8,  9,  9, 
	10, 10, 11, 11, 12, 12, 13, 13, 14, 15, 15, 15, 15, 15},
	{0, 1, 1, 2, 2, 3, 4, 5, 6,  6,  7,  7,  8,  8,  9,  9, 
	10, 10, 11, 11, 12, 12, 13, 13, 14, 15, 15, 15, 15, 15},
	{0, 1, 1, 2, 2, 3, 4, 5, 6,  6,  7,  7,  8,  8,  9,  9, 
	10, 10, 11, 11, 12, 12, 13, 13, 14, 15, 15, 15, 15, 15},
};

static u8 rtl8812ae_delta_swing_table_idx_5ga_p[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 2, 3, 4, 5, 6,  7,  7,  8,  8,  9, 10, 11, 
	11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 1, 2, 3, 3, 4, 5, 6,  7,  7,  8,  8,  9, 10, 11, 
	11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 1, 2, 3, 3, 4, 5, 6,  7,  7,  8,  8,  9, 10, 11, 
	11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
};

static u8 rtl8812au_delta_swing_table_idx_24gb_n[] = {
	0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  5,  5,  5,  6,  6,  
	7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 11, 11, 11, 11
};
	
static u8 rtl8812au_delta_swing_table_idx_24gb_p[] = {
	0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  4,  5,  5,  5,  6,  
	6,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7
};
	
static u8 rtl8812au_delta_swing_table_idx_24ga_n[] = {
	0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  4,  5,  5,  5,  6,  
	6,  6,  7,  7,  7,  8,  8,  9, 10, 10, 10, 10, 10, 10
};

static u8 rtl8812au_delta_swing_table_idx_24ga_p[] = {
	0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  4,  5,  5,  5,  6,  
	6,  6,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7
};

static u8 rtl8812au_delta_swing_table_idx_24gcckb_n[] = {
	0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  5,  5,  5,  6,  6,  
	7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 11, 11, 11, 11
};

static u8 rtl8812au_delta_swing_table_idx_24gcckb_p[] = {
	0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  4,  5,  5,  5,  6,  
	6,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7
};

static u8 rtl8812au_delta_swing_table_idx_24gccka_n[] = {
	0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  4,  5,  5,  5,  6,  
	6,  6,  7,  7,  7,  8,  8,  9, 10, 10, 10, 10, 10, 10
};
	
static u8 rtl8812au_delta_swing_table_idx_24gccka_p[] = {
	0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  4,  5,  5,  5,  6,  
	6,  6,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7
};

/******************************************************************************
*                           TxPowerTrack_USB_RFE3.TXT
******************************************************************************/

static u8 rtl8812ae_delta_swing_table_idx_5gb_n_rfe3[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 3, 3, 4, 5, 5,  6,  7,  7,  8,  8,  9,  9, 
	10, 10, 11, 12, 13, 13, 14, 15, 16, 16, 17, 17, 18, 18},
	{0, 1, 1, 2, 2, 3, 3, 4, 4,  5,  6,  7,  8,  8,  9,  9, 
	10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 1, 2, 2, 3, 3, 4, 4,  5,  6,  6,  7,  7,  8,  9, 
	10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
};

static u8 rtl8812ae_delta_swing_table_idx_5gb_p_rfe3[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 3, 3, 4, 5, 6,  7,  7,  8,  9,  9, 10, 10, 
	11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 1, 2, 2, 3, 3, 4, 4,  5,  6,  7,  8,  8,  9,  9, 
	10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 1, 2, 2, 3, 3, 4, 4,  5,  6,  6,  7,  7,  8,  9, 
	10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
};

static u8 rtl8812ae_delta_swing_table_idx_5ga_n_rfe3[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 3, 3, 4, 5, 5,  6,  7,  7,  8,  8,  9,  9, 
	10, 10, 11, 11, 12, 13, 14, 15, 16, 16, 17, 17, 18, 18},
	{0, 1, 1, 2, 3, 3, 4, 4, 5,  6,  6,  7,  7,  8,  9,  9, 
	10, 10, 11, 11, 12, 12, 13, 13, 14, 15, 16, 16, 17, 17},
	{0, 1, 1, 2, 3, 3, 4, 4, 5,  6,  7,  7,  8,  8,  9,  9, 
	10, 10, 11, 12, 13, 13, 14, 14, 15, 15, 16, 17, 18, 18},
};

static u8 rtl8812ae_delta_swing_table_idx_5ga_p_rfe3[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 2, 3, 4, 5, 6,  7,  7,  8,  9,  9, 10, 10, 
	11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 2, 3, 4, 4, 5, 5, 6,  7,  7,  8,  9,  9, 10, 11, 
	11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 2, 3, 4, 4, 5, 5, 6,  7,  7,  8,  9,  9, 10, 11, 
	11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
};

static u8 rtl8812au_delta_swing_table_idx_24gb_n_rfe3[] = {
	0, 1, 1, 2, 2, 3, 3, 4, 4,  4,  5,  5,  6,  6,  6,  7,  
	7,  7,  8,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15
};

static u8 rtl8812au_delta_swing_table_idx_24gb_p_rfe3[] = {
	0, 1, 1, 2, 2, 2, 2, 3, 3,  3,  4,  4,  5,  5,  5,  6,  
	6,  7,  7,  8,  9, 10, 10, 10, 10, 11, 11, 11, 11, 11
};

static u8 rtl8812au_delta_swing_table_idx_24ga_n_rfe3[] = {
	0, 1, 1, 2, 2, 3, 4, 5, 6,  6,  6,  7,  7,  8,  8,  9, 
	10, 10, 11, 11, 12, 12, 13, 13, 13, 13, 14, 14, 15, 15
};

static u8 rtl8812au_delta_swing_table_idx_24ga_p_rfe3[] = {
	0, 0, 1, 1, 1, 2, 2, 3, 3,  4,  4,  4,  5,  5,  5,  6,  
	6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 11, 11, 11
};

static u8 rtl8812au_delta_swing_table_idx_24gcckb_n_rfe3[] = {
	0, 1, 1, 2, 2, 3, 3, 4, 4,  4,  5,  5,  6,  6,  6,  7,  
	7,  7,  8,  8,  9,  9, 10, 11, 12, 12, 13, 14, 15, 15
};

static u8 rtl8812au_delta_swing_table_idx_24gcckb_p_rfe3[] = {
	0, 1, 1, 2, 2, 2, 2, 3, 3,  3,  4,  4,  5,  5,  5,  6,  
	6,  7,  7,  8,  9, 10, 10, 10, 10, 11, 11, 11, 11, 11
};

static u8 rtl8812au_delta_swing_table_idx_24gccka_n_rfe3[] = {
	0, 1, 1, 2, 2, 3, 4, 5, 6,  6,  6,  7,  7,  8,  8,  9, 
	10, 10, 11, 11, 12, 12, 13, 13, 13, 13, 14, 14, 15, 15
};

static u8 rtl8812au_delta_swing_table_idx_24gccka_p_rfe3[] = {
	0, 0, 1, 1, 1, 2, 2, 3, 3,  4,  4,  4,  5,  5,  5,  6,  
	6,  7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 11, 11, 11
};

/* END Copied from hal/OUTSRC/rtl8812a/HalHWImg8812A_RF.c */

void rtl8812au_get_delta_swing_table(struct rtl_priv *rtlpriv,
					    u8 **up_a, u8 **down_a,
					    u8 **up_b, u8 **down_b)
{
	struct rtl_hal	*rtlhal = rtl_hal(rtlpriv);
	struct _rtw_hal	*pHalData = GET_HAL_DATA(rtlpriv);
	struct _rtw_dm *pDM_Odm = &pHalData->odmpriv;	
	
	u16	rate = *(pDM_Odm->pForcedDataRate);
	u8         	channel   		 = rtlpriv->phy.current_channel;

	if (rtlhal->rfe_type == 3 && pDM_Odm->bIsMPChip) {
		if (1 <= channel && channel <= 14) {
			if (IS_CCK_RATE(rate)) {
				*up_a   = rtl8812au_delta_swing_table_idx_24gccka_p_rfe3;
				*down_a = rtl8812au_delta_swing_table_idx_24gccka_n_rfe3;
				*up_b   = rtl8812au_delta_swing_table_idx_24gcckb_p_rfe3;
				*down_b = rtl8812au_delta_swing_table_idx_24gcckb_n_rfe3;
			} else {
				*up_a   = rtl8812au_delta_swing_table_idx_24ga_p_rfe3;
				*down_a = rtl8812au_delta_swing_table_idx_24ga_n_rfe3;
				*up_b   = rtl8812au_delta_swing_table_idx_24gb_p_rfe3;
				*down_b = rtl8812au_delta_swing_table_idx_24gb_n_rfe3;
			}
		} else if (36 <= channel && channel <= 64) {
			*up_a   = rtl8812ae_delta_swing_table_idx_5ga_p_rfe3[0];
			*down_a = rtl8812ae_delta_swing_table_idx_5ga_n_rfe3[0];
			*up_b   = rtl8812ae_delta_swing_table_idx_5gb_p_rfe3[0];
			*down_b = rtl8812ae_delta_swing_table_idx_5gb_n_rfe3[0];
		} else if (100 <= channel && channel <= 140) {
			*up_a   = rtl8812ae_delta_swing_table_idx_5ga_p_rfe3[1];
			*down_a = rtl8812ae_delta_swing_table_idx_5ga_n_rfe3[1];
			*up_b   = rtl8812ae_delta_swing_table_idx_5gb_p_rfe3[1];
			*down_b = rtl8812ae_delta_swing_table_idx_5gb_n_rfe3[1];
		} else if (149 <= channel && channel <= 173) {
			*up_a   = rtl8812ae_delta_swing_table_idx_5ga_p_rfe3[2];
			*down_a = rtl8812ae_delta_swing_table_idx_5ga_n_rfe3[2];
			*up_b   = rtl8812ae_delta_swing_table_idx_5gb_p_rfe3[2];
			*down_b = rtl8812ae_delta_swing_table_idx_5gb_n_rfe3[2];
		} else {
			*up_a   = (u8 *)DeltaSwingTableIdx_2GA_P_8188E;
			*down_a = (u8 *)DeltaSwingTableIdx_2GA_N_8188E;
			*up_b   = (u8 *)DeltaSwingTableIdx_2GA_P_8188E;
			*down_b = (u8 *)DeltaSwingTableIdx_2GA_N_8188E;
		}
	} else {
		if (1 <= channel && channel <= 14) {
			if (IS_CCK_RATE(rate)) {
				*up_a   = rtl8812au_delta_swing_table_idx_24gccka_p;
				*down_a = rtl8812au_delta_swing_table_idx_24gccka_n;
				*up_b   = rtl8812au_delta_swing_table_idx_24gcckb_p;
				*down_b = rtl8812au_delta_swing_table_idx_24gcckb_n;
			} else {
				*up_a   = rtl8812au_delta_swing_table_idx_24ga_p;
				*down_a = rtl8812au_delta_swing_table_idx_24ga_n;
				*up_b   = rtl8812au_delta_swing_table_idx_24gb_p;
				*down_b = rtl8812au_delta_swing_table_idx_24gb_n;
			}
		} else if (36 <= channel && channel <= 64) {
			*up_a   = rtl8812ae_delta_swing_table_idx_5ga_p[0];
			*down_a = rtl8812ae_delta_swing_table_idx_5ga_n[0];
			*up_b   = rtl8812ae_delta_swing_table_idx_5gb_p[0];
			*down_b = rtl8812ae_delta_swing_table_idx_5gb_n[0];
		} else if (100 <= channel && channel <= 140) {
			*up_a   = rtl8812ae_delta_swing_table_idx_5ga_p[1];
			*down_a = rtl8812ae_delta_swing_table_idx_5ga_n[1];
			*up_b   = rtl8812ae_delta_swing_table_idx_5gb_p[1];
			*down_b = rtl8812ae_delta_swing_table_idx_5gb_n[1];
		} else if (149 <= channel && channel <= 173) {
			*up_a   = rtl8812ae_delta_swing_table_idx_5ga_p[2];
			*down_a = rtl8812ae_delta_swing_table_idx_5ga_n[2];
			*up_b   = rtl8812ae_delta_swing_table_idx_5gb_p[2];
			*down_b = rtl8812ae_delta_swing_table_idx_5gb_n[2];
		} else {
			*up_a   = (u8 *)DeltaSwingTableIdx_2GA_P_8188E;
			*down_a = (u8 *)DeltaSwingTableIdx_2GA_N_8188E;
			*up_b   = (u8 *)DeltaSwingTableIdx_2GA_P_8188E;
			*down_b = (u8 *)DeltaSwingTableIdx_2GA_N_8188E;
		}
	}

	return;
}


/* From hal/OUTSRC/rtl8821a/HalPhyRf_8821A.c, caution function pointer */

void DoIQK_8821A(struct rtl_priv *rtlpriv, u8 DeltaThermalIndex,
	u8 ThermalValue, u8 Threshold)
{
	struct rtl_dm	*rtldm = rtl_dm(rtlpriv);

	rtldm->thermalvalue_iqk = ThermalValue;
	rtl8821au_phy_iq_calibrate(rtlpriv, FALSE);
}


void ODM_TxPwrTrackSetPwr8821A(struct rtl_priv *rtlpriv, PWRTRACK_METHOD Method,
	u8 RFPath, u8 ChannelMappedIndex)
{
	struct rtl_dm	*rtldm = rtl_dm(rtlpriv);
	struct _rtw_hal *pHalData = GET_HAL_DATA(rtlpriv);

	u8 PwrTrackingLimit = 26; /* +1.0dB */
	u8 TxRate = 0xFF;
	s8 Final_OFDM_Swing_Index = 0;
	s8 Final_CCK_Swing_Index = 0;
	u8 i = 0;
	uint32_t finalBbSwingIdx[1];

#if 0
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("===>ODM_TxPwrTrackSetPwr8821A\n"));
#endif
	if (TxRate != 0xFF) {
		/* 2 CCK */
		if ((TxRate >= MGN_1M) && (TxRate <= MGN_11M))
			PwrTrackingLimit = 32;				/* +4dB */
		/* 2 OFDM */
		else if ((TxRate >= MGN_6M) && (TxRate <= MGN_48M))
			PwrTrackingLimit = 32;				/* +4dB */
		else if (TxRate == MGN_54M)
			PwrTrackingLimit = 30;				/* +3dB */
		/* 2 HT */
		else if ((TxRate >= MGN_MCS0) && (TxRate <= MGN_MCS2))  /* QPSK/BPSK */
			PwrTrackingLimit = 34;				/* +5dB */
		else if ((TxRate >= MGN_MCS3) && (TxRate <= MGN_MCS4))  /* 16QAM */
			PwrTrackingLimit = 32;				/* +4dB */
		else if ((TxRate >= MGN_MCS5) && (TxRate <= MGN_MCS7))  /* 64QAM */
			PwrTrackingLimit = 30;				/* +3dB */
		/* 2 VHT */
		else if ((TxRate >= MGN_VHT1SS_MCS0) && (TxRate <= MGN_VHT1SS_MCS2))    /* QPSK/BPSK */
			PwrTrackingLimit = 34;						/* +5dB */
		else if ((TxRate >= MGN_VHT1SS_MCS3) && (TxRate <= MGN_VHT1SS_MCS4))    /* 16QAM */
			PwrTrackingLimit = 32;						/* +4dB */
		else if ((TxRate >= MGN_VHT1SS_MCS5) && (TxRate <= MGN_VHT1SS_MCS6))    /* 64QAM */
			PwrTrackingLimit = 30;						/* +3dB */
		else if (TxRate == MGN_VHT1SS_MCS7)					/* 64QAM */
			PwrTrackingLimit = 28;						/* +2dB */
		else if (TxRate == MGN_VHT1SS_MCS8)					/* 256QAM */
			PwrTrackingLimit = 26;						/* +1dB */
		else if (TxRate == MGN_VHT1SS_MCS9)					/* 256QAM */
			PwrTrackingLimit = 24;						/* +0dB */
		else
			PwrTrackingLimit = 24;
	}
#if 0	
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("TxRate=0x%x, PwrTrackingLimit=%d\n", TxRate, PwrTrackingLimit));
#endif
	if (Method == BBSWING) {
		if (RFPath == RF90_PATH_A) {
			finalBbSwingIdx[RF90_PATH_A] = (rtldm->OFDM_index[RF90_PATH_A] > PwrTrackingLimit) ? PwrTrackingLimit : rtldm->OFDM_index[RF90_PATH_A];
#if 0			
			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("pDM_Odm->RFCalibrateInfo.OFDM_index[RF90_PATH_A]=%d, pDM_Odm->RealBbSwingIdx[RF90_PATH_A]=%d\n",
				rtldm->OFDM_index[RF90_PATH_A], finalBbSwingIdx[RF90_PATH_A]));
#endif
			rtl_set_bbreg(rtlpriv, rA_TxScale_Jaguar, 0xFFE00000, TxScalingTable_Jaguar[finalBbSwingIdx[RF90_PATH_A]]);
		}
	} else if (Method == MIX_MODE) {
#if 0		
			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("pDM_Odm->DefaultOfdmIndex=%d, pDM_Odm->Aboslute_OFDMSwingIdx[RFPath]=%d, RF_Path = %d\n",
				rtldm->DefaultOfdmIndex, rtldm->Aboslute_OFDMSwingIdx[RFPath], RFPath));
#endif

			Final_OFDM_Swing_Index = rtldm->DefaultOfdmIndex + rtldm->Aboslute_OFDMSwingIdx[RFPath];

			if (RFPath == RF90_PATH_A) {
				if (Final_OFDM_Swing_Index > PwrTrackingLimit) {
					/* BBSwing higher then Limit */
					rtldm->Remnant_CCKSwingIdx = Final_OFDM_Swing_Index - PwrTrackingLimit;            /* CCK Follow the same compensate value as Path A */
					rtldm->Remnant_OFDMSwingIdx[RFPath] = Final_OFDM_Swing_Index - PwrTrackingLimit;

					rtl_set_bbreg(rtlpriv, rA_TxScale_Jaguar, 0xFFE00000, TxScalingTable_Jaguar[PwrTrackingLimit]);

					rtldm->Modify_TxAGC_Flag_PathA = TRUE;

					/* Set TxAGC Page C{}; */
					/* rtlpriv->cfg->ops.SetTxPowerLevelHandler(rtlpriv, pHalData->CurrentChannel); */
					PHY_SetTxPowerLevel8812(rtlpriv, rtlpriv->phy.current_channel);
#if 0
					ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("******Path_A Over BBSwing Limit , PwrTrackingLimit = %d , Remnant TxAGC Value = %d \n", PwrTrackingLimit, rtldm->Remnant_OFDMSwingIdx[RFPath]));
#endif					
				} else if (Final_OFDM_Swing_Index < 0) {
					rtldm->Remnant_CCKSwingIdx = Final_OFDM_Swing_Index;            /* CCK Follow the same compensate value as Path A */
					rtldm->Remnant_OFDMSwingIdx[RFPath] = Final_OFDM_Swing_Index;

					rtl_set_bbreg(rtlpriv, rA_TxScale_Jaguar, 0xFFE00000, TxScalingTable_Jaguar[0]);

					rtldm->Modify_TxAGC_Flag_PathA = TRUE;

					/* Set TxAGC Page C{}; */
					/* rtlpriv->cfg->ops.SetTxPowerLevelHandler(rtlpriv, pHalData->CurrentChannel); */
					PHY_SetTxPowerLevel8812(rtlpriv, rtlpriv->phy.current_channel);
#if 0
					ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("******Path_A Lower then BBSwing lower bound  0 , Remnant TxAGC Value = %d \n", rtldm->Remnant_OFDMSwingIdx[RFPath]));
#endif					
				} else {
					rtl_set_bbreg(rtlpriv, rA_TxScale_Jaguar, 0xFFE00000, TxScalingTable_Jaguar[Final_OFDM_Swing_Index]);
#if 0
					ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("******Path_A Compensate with BBSwing , Final_OFDM_Swing_Index = %d \n", Final_OFDM_Swing_Index));
#endif
					if (rtldm->Modify_TxAGC_Flag_PathA) {
						/* If TxAGC has changed, reset TxAGC again */
						rtldm->Remnant_CCKSwingIdx = 0;
						rtldm->Remnant_OFDMSwingIdx[RFPath] = 0;

						/* Set TxAGC Page C{}; */
						/* rtlpriv->cfg->ops.SetTxPowerLevelHandler(rtlpriv, pHalData->CurrentChannel); */
						PHY_SetTxPowerLevel8812(rtlpriv, rtlpriv->phy.current_channel);

						rtldm->Modify_TxAGC_Flag_PathA = FALSE;
#if 0
						ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("******Path_A pDM_Odm->Modify_TxAGC_Flag = FALSE \n"));
#endif						
					}
				}
			}

	} else {
		return;
	}
}
/* START Copied from hal/OUTSRC/rtl8821a/HalHWImg8821A_RF.c */

/******************************************************************************
*                           TxPowerTrack_USB.TXT
******************************************************************************/

static u8 rtl8821au_delta_swing_table_idx_5gb_n[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 2, 3, 4, 5, 6,  6,  7,  7,  8,  8,  9,  9, 
	10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 14, 14, 14, 14},
	{0, 1, 1, 2, 3, 3, 4, 5, 5,  6,  7,  7,  8,  8,  9,  9, 
	10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 1, 2, 3, 3, 4, 5, 6,  7,  7,  8,  8,  9,  9, 10, 
	11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
};

static u8 rtl8821au_delta_swing_table_idx_5gb_p[][DELTA_SWINGIDX_SIZE] = {
	{0, 1, 1, 2, 2, 3, 3, 4, 5,  6,  7,  7,  8,  8,  9,  9, 
	10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 1, 2, 3, 3, 4, 5, 5,  6,  7,  7,  8,  8,  9,  9, 
	10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
	{0, 1, 1, 2, 3, 3, 4, 5, 6,  7,  7,  8,  8,  9,  9, 10, 
	11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},
};

static u8 rtl8821au_delta_swing_table_idx_5ga_n[][DELTA_SWINGIDX_SIZE] = {
	{0, 0, 0, 1, 2, 2, 3, 4, 5, 6,  6,  7,  7,  8,  8,  9,  
	9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 15, 15, 15, 15},
	{0, 0, 0, 1, 2, 2, 3, 4, 5, 6,  6,  7,  7,  8,  8,  9,  
	9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 15, 15, 15, 15},
	{0, 0, 0, 1, 2, 2, 3, 4, 5, 6,  6,  7,  7,  8,  8,  9,  
	9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 15, 15, 15, 15},
};

static u8 rtl8821au_delta_swing_table_idx_5ga_p[][DELTA_SWINGIDX_SIZE] = {
	{1, 2, 3, 4, 5, 6, 7, 8, 9,  10, 11, 12,  13,  14, 15, 16, 
	16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16},
	{1, 2, 3, 4, 5, 6, 7, 8, 9,  10, 11, 12,  13,  14, 15, 16, 
	16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16},
	{1, 2, 3, 4, 5, 6, 7, 8, 9,  10, 11, 12,  13,  14, 15, 16, 
	16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16},
};

static u8 rtl8821au_delta_swing_table_idx_24gb_n[]    = {
	0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  5,  5,  5,  6,  6,  
	7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 11, 11, 11, 11
};

static u8 rtl8821au_delta_swing_table_idx_24gb_p[]    = {
	0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  4,  5,  5,  5,  6,  
	6,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7
};

static u8 rtl8821au_delta_swing_table_idx_24ga_n[]    = {
	0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  4,  5,  5,  5,  6,  
	6,  6,  7,  7,  7,  8,  8,  9, 10, 10, 10, 10, 10, 10
};

static u8 rtl8821au_delta_swing_table_idx_24ga_p[]    = {
	0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  4,  5,  5,  5,  6,  
	6,  6,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7
};

static u8 rtl8821au_delta_swing_table_idx_24gcckb_n[] = {
	0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  5,  5,  5,  6,  6,  
	7,  7,  8,  8,  9,  9, 10, 10, 11, 11, 11, 11, 11, 11
};

static u8 rtl8821au_delta_swing_table_idx_24gcckb_p[] = {
	0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  4,  5,  5,  5,  6,  
	6,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7
};

static u8 rtl8821au_delta_swing_table_idx_24gccka_n[] = {
	0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  4,  5,  5,  5,  6,  
	6,  6,  7,  7,  7,  8,  8,  9, 10, 10, 10, 10, 10, 10
};

static u8 rtl8821au_delta_swing_table_idx_24gccka_p[] = {
	0, 1, 1, 2, 2, 2, 3, 3, 3,  4,  4,  4,  5,  5,  5,  6, 
	6,  6,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7
};


/* END Copied from hal/OUTSRC/rtl8821a/HalHWImg8821A_RF.c */

void rtl8821au_get_delta_swing_table(struct rtl_priv *rtlpriv,
	u8 **up_a, u8 **down_a,
	u8 **up_b, u8 **down_b)
{
	 struct _rtw_hal  	*pHalData = GET_HAL_DATA(rtlpriv);
	/* u16     rate = pMgntInfo->ForcedDataRate; */
	u16	rate = 0;
	u8         	channel   		 = rtlpriv->phy.current_channel;

	if (1 <= channel && channel <= 14) {
		if (IS_CCK_RATE(rate)) {
			*up_a   = rtl8821au_delta_swing_table_idx_24gccka_p;
			*down_a = rtl8821au_delta_swing_table_idx_24gccka_n;
			*up_b   = rtl8821au_delta_swing_table_idx_24gcckb_p;
			*down_b = rtl8821au_delta_swing_table_idx_24gcckb_n;
		} else {
			*up_a   = rtl8821au_delta_swing_table_idx_24ga_p;
			*down_a = rtl8821au_delta_swing_table_idx_24ga_n;
			*up_b   = rtl8821au_delta_swing_table_idx_24gb_p;
			*down_b = rtl8821au_delta_swing_table_idx_24gb_n;
		}
	} else if (36 <= channel && channel <= 64) {
		*up_a   = rtl8821au_delta_swing_table_idx_5ga_p[0];
		*down_a = rtl8821au_delta_swing_table_idx_5ga_n[0];
		*up_b   = rtl8821au_delta_swing_table_idx_5gb_p[0];
		*down_b = rtl8821au_delta_swing_table_idx_5gb_n[0];
	} else if (100 <= channel && channel <= 140) {
		*up_a   = rtl8821au_delta_swing_table_idx_5ga_p[1];
		*down_a = rtl8821au_delta_swing_table_idx_5ga_n[1];
		*up_b   = rtl8821au_delta_swing_table_idx_5gb_p[1];
		*down_b = rtl8821au_delta_swing_table_idx_5gb_n[1];
	} else if (149 <= channel && channel <= 173) {
		*up_a   = rtl8821au_delta_swing_table_idx_5ga_p[2];
		*down_a = rtl8821au_delta_swing_table_idx_5ga_n[2];
		*up_b   = rtl8821au_delta_swing_table_idx_5gb_p[2];
		*down_b = rtl8821au_delta_swing_table_idx_5gb_n[2];
	} else {
		*up_a   = (u8 *)DeltaSwingTableIdx_2GA_P_8188E;
		*down_a = (u8 *)DeltaSwingTableIdx_2GA_N_8188E;
		*up_b   = (u8 *)DeltaSwingTableIdx_2GA_P_8188E;
		*down_b = (u8 *)DeltaSwingTableIdx_2GA_N_8188E;
	}

	return;
}

static void rtl8812au_dm_txpower_tracking_callback_thermalmeter(struct rtl_priv *rtlpriv)
{
	struct rtl_hal *rtlhal = rtl_hal(rtlpriv);
	struct rtl_efuse *efuse = rtl_efuse(rtlpriv);
	struct rtl_dm	*rtldm = rtl_dm(rtlpriv);

	 struct _rtw_hal	*pHalData = GET_HAL_DATA(rtlpriv);
	struct _rtw_dm *pDM_Odm = &pHalData->odmpriv;

	u8	ThermalValue = 0, delta, delta_LCK, delta_IQK, p = 0, i = 0;
	u8	ThermalValue_AVG_count = 0;
	uint32_t	ThermalValue_AVG = 0;

	u8	OFDM_min_index = 0;  /* OFDM BB Swing should be less than +if (.0dB, which is required by Arthur */
	u8	Indexforchannel = 0; /* GetRightChnlPlaceforIQK(pHalData->CurrentChannel) */

	/* 4 1. The following TWO tables decide the final index of OFDM/CCK swing table. */
	u8 *up_a, *down_a, *up_b, *down_b;

	/* 4 2. Initilization ( 7 steps in total ) */

	rtl8812au_get_delta_swing_table(rtlpriv, (u8 **)&up_a, (u8 **)&down_a,
					 (u8 **)&up_b, (u8 **)&down_b);

	rtldm->TXPowerTrackingCallbackCnt++; /* cosa add for debug */
	rtldm->bTXPowerTrackingInit = TRUE;

	ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("===>ODM_TXPowerTrackingCallback_ThermalMeter, \n rtldm->BbSwingIdxCckBase: %d, rtldm->BbSwingIdxOfdmBase[A]: %d, rtldm->DefaultOfdmIndex: %d\n", rtldm->BbSwingIdxCckBase, rtldm->BbSwingIdxOfdmBase[RF90_PATH_A], rtldm->DefaultOfdmIndex));

	ThermalValue = (u8)rtw_hal_read_rfreg(pDM_Odm->rtlpriv, RF90_PATH_A, RF_T_METER_8812A, 0xfc00);	/* 0x42: RF Reg[15:10] 88E */
	if (!rtldm->TxPowerTrackControl
	 || efuse->EEPROMThermalMeter == 0
	 || efuse->EEPROMThermalMeter == 0xFF)
		return;

	/* 4 if (. Initialize ThermalValues of RFCalibrateInfo */

	if (rtldm->bReloadtxpowerindex) {
		ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("reload ofdm index for band switch\n"));
	}

	/* 4 4. Calculate average thermal meter */

	rtldm->thermalvalue_avg[rtldm->thermalvalue_avg_index] = ThermalValue;
	rtldm->thermalvalue_avg_index++;
	if (rtldm->thermalvalue_avg_index == AVG_THERMAL_NUM_8812A)   /* Average times =  c.AverageThermalNum */
		rtldm->thermalvalue_avg_index = 0;

	for (i = 0; i < AVG_THERMAL_NUM_8812A; i++) {
		if (rtldm->thermalvalue_avg[i]) {
			ThermalValue_AVG += rtldm->thermalvalue_avg[i];
			ThermalValue_AVG_count++;
		}
	}

	if (ThermalValue_AVG_count) {               /* Calculate Average ThermalValue after average enough times */
		ThermalValue = (u8)(ThermalValue_AVG / ThermalValue_AVG_count);
		ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("AVG Thermal Meter = 0x%X, EFUSE Thermal Base = 0x%X\n", ThermalValue, efuse->EEPROMThermalMeter));
	}

	/* 4 5. Calculate delta, delta_LCK, delta_IQK. */

	/* "delta" here is used to determine whether thermal value changes or not. */
	delta 	  = (ThermalValue > rtldm->thermalvalue)?(ThermalValue - rtldm->thermalvalue):(rtldm->thermalvalue - ThermalValue);
	delta_LCK = (ThermalValue > rtldm->thermalvalue_lck)?(ThermalValue - rtldm->thermalvalue_lck):(rtldm->thermalvalue_lck - ThermalValue);
	delta_IQK = (ThermalValue > rtldm->thermalvalue_iqk)?(ThermalValue - rtldm->thermalvalue_iqk):(rtldm->thermalvalue_iqk - ThermalValue);

	ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("(delta, delta_LCK, delta_IQK) = (%d, %d, %d)\n", delta, delta_LCK, delta_IQK));

	/* 4 6. If necessary, do LCK. */

	if ((delta_LCK >= IQK_THRESHOLD)) {	/* Delta temperature is equal to or larger than 20 centigrade. */
		ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("delta_LCK(%d) >= Threshold_IQK(%d)\n", delta_LCK, IQK_THRESHOLD));
		rtldm->thermalvalue_lck = ThermalValue;
		PHY_LCCalibrate_8812A(rtlpriv);
	}

	/* if ( 7. If necessary, move the index of swing table to adjust Tx power. */

	if (delta > 0 && rtldm->TxPowerTrackControl) {
		/* "delta" here is used to record the absolute value of differrence. */
	    delta = ThermalValue > efuse->EEPROMThermalMeter?(ThermalValue - efuse->EEPROMThermalMeter):(efuse->EEPROMThermalMeter - ThermalValue);
		if (delta >= TXSCALE_TABLE_SIZE)
			delta = TXSCALE_TABLE_SIZE - 1;

		/* 4 7.1 The Final Power Index = BaseIndex + PowerIndexOffset */

		if (ThermalValue > efuse->EEPROMThermalMeter) {
			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("deltaSwingTableIdx_TUP_A[%d] = %d\n", delta, up_a[delta]));
			rtldm->DeltaPowerIndexLast[RF90_PATH_A] = rtldm->DeltaPowerIndex[RF90_PATH_A];
			rtldm->DeltaPowerIndex[RF90_PATH_A] = up_a[delta];

			rtldm->Aboslute_OFDMSwingIdx[RF90_PATH_A] =  up_a[delta];        /* Record delta swing for mix mode power tracking */

			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("******Temp is higher and rtldm->Aboslute_OFDMSwingIdx[RF90_PATH_A] = %d\n", rtldm->Aboslute_OFDMSwingIdx[RF90_PATH_A]));

			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("deltaSwingTableIdx_TUP_B[%d] = %d\n", delta, up_b[delta]));
			rtldm->DeltaPowerIndexLast[RF90_PATH_B] = rtldm->DeltaPowerIndex[RF90_PATH_B];
			rtldm->DeltaPowerIndex[RF90_PATH_B] = up_b[delta];

			rtldm->Aboslute_OFDMSwingIdx[RF90_PATH_B] =  up_a[delta];       /* Record delta swing for mix mode power tracking */

			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("******Temp is higher and rtldm->Aboslute_OFDMSwingIdx[RF90_PATH_B] = %d\n", rtldm->Aboslute_OFDMSwingIdx[RF90_PATH_B]));

		} else {
			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("deltaSwingTableIdx_TDOWN_A[%d] = %d\n", delta, down_a[delta]));

			rtldm->DeltaPowerIndexLast[RF90_PATH_A] = rtldm->DeltaPowerIndex[RF90_PATH_A];
			rtldm->DeltaPowerIndex[RF90_PATH_A] = -1 * down_a[delta];

			rtldm->Aboslute_OFDMSwingIdx[RF90_PATH_A] =  -1 * down_a[delta];        /* Record delta swing for mix mode power tracking */

			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("******Temp is lower and rtldm->Aboslute_OFDMSwingIdx[RF90_PATH_A] = %d\n", rtldm->Aboslute_OFDMSwingIdx[RF90_PATH_A]));

			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("deltaSwingTableIdx_TDOWN_B[%d] = %d\n", delta, down_b[delta]));

			rtldm->DeltaPowerIndexLast[RF90_PATH_B] = rtldm->DeltaPowerIndex[RF90_PATH_B];
			rtldm->DeltaPowerIndex[RF90_PATH_B] = -1 * down_b[delta];

			rtldm->Aboslute_OFDMSwingIdx[RF90_PATH_B] =  -1 * down_b[delta];       /* Record delta swing for mix mode power tracking */

			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("******Temp is lower and rtldm->Aboslute_OFDMSwingIdx[RF90_PATH_B] = %d\n", rtldm->Aboslute_OFDMSwingIdx[RF90_PATH_B]));
		}

	    for (p = RF90_PATH_A; p < MAX_PATH_NUM_8812A; p++) {
			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("\n\n================================ [Path-%c] Calculating PowerIndexOffset ================================\n", (p == RF90_PATH_A ? 'A' : 'B')));
			if (rtldm->DeltaPowerIndex[p] == rtldm->DeltaPowerIndexLast[p])         /* If Thermal value changes but lookup table value still the same */
				rtldm->PowerIndexOffset[p] = 0;
			else
				rtldm->PowerIndexOffset[p] = rtldm->DeltaPowerIndex[p] - rtldm->DeltaPowerIndexLast[p];      /* Power Index Diff between 2 times Power Tracking */

			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("[Path-%c] PowerIndexOffset(%d) = DeltaPowerIndex(%d) - DeltaPowerIndexLast(%d)\n", (p == RF90_PATH_A ? 'A' : 'B'), rtldm->PowerIndexOffset[p], rtldm->DeltaPowerIndex[p],
			rtldm->DeltaPowerIndexLast[p]));

			rtldm->OFDM_index[p] = rtldm->BbSwingIdxOfdmBase[p] + rtldm->PowerIndexOffset[p];
			rtldm->CCK_index = rtldm->BbSwingIdxCckBase + rtldm->PowerIndexOffset[p];

			rtldm->BbSwingIdxCck = rtldm->CCK_index;
			rtldm->BbSwingIdxOfdm[p] = rtldm->OFDM_index[p];

	       /* *************Print BB Swing Base and Index Offset************* */

			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("The 'CCK' final index(%d) = BaseIndex(%d) + PowerIndexOffset(%d)\n", rtldm->BbSwingIdxCck, rtldm->BbSwingIdxCckBase, rtldm->PowerIndexOffset[p]));
			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("The 'OFDM' final index(%d) = BaseIndex[%c](%d) + PowerIndexOffset(%d)\n", rtldm->BbSwingIdxOfdm[p], (p == RF90_PATH_A ? 'A' : 'B'), rtldm->BbSwingIdxOfdmBase[p], rtldm->PowerIndexOffset[p]));

		    /* 4 7.1 Handle boundary conditions of index. */

			if (rtldm->OFDM_index[p] > TXSCALE_TABLE_SIZE-1) {
				rtldm->OFDM_index[p] = TXSCALE_TABLE_SIZE-1;
			} else if (rtldm->OFDM_index[p] < OFDM_min_index) {
				rtldm->OFDM_index[p] = OFDM_min_index;
			}
		}
		ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("\n\n========================================================================================================\n"));
		if (rtldm->CCK_index > TXSCALE_TABLE_SIZE-1)
			rtldm->CCK_index = TXSCALE_TABLE_SIZE-1;
		/*
		 * else if (rtldm->RFCalibrateInfo.CCK_index < 0)
		 * 	rtldm->RFCalibrateInfo.CCK_index = 0;
		 */
	} else {
		ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("The thermal meter is unchanged or TxPowerTracking OFF(%d): ThermalValue: %d , rtldm->RFCalibrateInfo.ThermalValue: %d\n", rtldm->TxPowerTrackControl, ThermalValue, rtldm->thermalvalue));

		for (p = RF90_PATH_A; p < MAX_PATH_NUM_8812A; p++)
			rtldm->PowerIndexOffset[p] = 0;
	}
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("TxPowerTracking: [CCK] Swing Current Index: %d, Swing Base Index: %d\n", rtldm->CCK_index, rtldm->BbSwingIdxCckBase));       /* Print Swing base & current */
	for (p = RF90_PATH_A; p < MAX_PATH_NUM_8812A; p++) {
		ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("TxPowerTracking: [OFDM] Swing Current Index: %d, Swing Base Index[%c]: %d\n", rtldm->OFDM_index[p], (p == RF90_PATH_A ? 'A' : 'B'), rtldm->BbSwingIdxOfdmBase[p]));
	}

	if ((rtldm->PowerIndexOffset[RF90_PATH_A] != 0 ||  rtldm->PowerIndexOffset[RF90_PATH_B] != 0)
	 && rtldm->TxPowerTrackControl) {
		/* 4 7.2 Configure the Swing Table to adjust Tx Power. */
		rtldm->bTxPowerChanged = TRUE; /* Always TRUE after Tx Power is adjusted by power tracking. */
		/*
		 *  2012/04/2if ( MH According to Luke's suggestion, we can not write BB digital
		 *  to increase TX power. Otherwise, EVM will be bad.
		 *
		 *  2012/04/25 MH Add for tx power tracking to set tx power in tx agc for 88E.
		 */
		if (ThermalValue > rtldm->thermalvalue) {
			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("Temperature Increasing(A): delta_pi: %d , delta_t: %d, Now_t: %d, EFUSE_t: %d, Last_t: %d\n", rtldm->PowerIndexOffset[RF90_PATH_A], delta, ThermalValue, efuse->EEPROMThermalMeter, rtldm->thermalvalue));
			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("Temperature Increasing(B): delta_pi: %d , delta_t: %d, Now_t: %d, EFUSE_t: %d, Last_t: %d\n", rtldm->PowerIndexOffset[RF90_PATH_B], delta, ThermalValue, efuse->EEPROMThermalMeter, rtldm->thermalvalue));

			} else if (ThermalValue < rtldm->thermalvalue) { /* Low temperature */
				ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("Temperature Decreasing(A): delta_pi: %d , delta_t: %d, Now_t: %d, EFUSE_t: %d, Last_t: %d\n", rtldm->PowerIndexOffset[RF90_PATH_A], delta, ThermalValue, efuse->EEPROMThermalMeter, rtldm->thermalvalue));
				ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("Temperature Decreasing(B): delta_pi: %d , delta_t: %d, Now_t: %d, EFUSE_t: %d, Last_t: %d\n", rtldm->PowerIndexOffset[RF90_PATH_B], delta, ThermalValue, efuse->EEPROMThermalMeter, rtldm->thermalvalue));

			}
			if (ThermalValue > efuse->EEPROMThermalMeter) {
				ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("Temperature(%d) higher than PG value(%d)\n", ThermalValue, efuse->EEPROMThermalMeter));

				for (p = RF90_PATH_A; p < MAX_PATH_NUM_8812A; p++)
					ODM_TxPwrTrackSetPwr8812A(rtlpriv, BBSWING, p, Indexforchannel);
			} else {
				ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("Temperature(%d) lower than PG value(%d)\n", ThermalValue, efuse->EEPROMThermalMeter));

				for (p = RF90_PATH_A; p < MAX_PATH_NUM_8812A; p++)
					ODM_TxPwrTrackSetPwr8812A(rtlpriv, BBSWING, p, Indexforchannel);
			}

			rtldm->BbSwingIdxCckBase = rtldm->BbSwingIdxCck;  	/* Record last time Power Tracking result as base. */
			for (p = RF90_PATH_A; p < MAX_PATH_NUM_8812A; p++)
				rtldm->BbSwingIdxOfdmBase[p] = rtldm->BbSwingIdxOfdm[p];

			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD,  ("rtldm->RFCalibrateInfo.ThermalValue = %d ThermalValue= %d\n", rtldm->thermalvalue, ThermalValue));

			rtldm->thermalvalue = ThermalValue;     /* Record last Power Tracking Thermal Value */

	}
	if ((delta_IQK >= IQK_THRESHOLD))	/* Delta temperature is equal to or larger than 20 centigrade (When threshold is 8). */
		DoIQK_8812A(rtlpriv, delta_IQK, ThermalValue, 8);

	ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("<===ODM_TXPowerTrackingCallback_ThermalMeter\n"));

	rtldm->TXPowercount = 0;
}


static void rtl8821au_dm_txpower_tracking_callback_thermalmeter(struct rtl_priv *rtlpriv)
{
	struct rtl_hal *rtlhal = rtl_hal(rtlpriv);
	struct rtl_efuse *efuse = rtl_efuse(rtlpriv);
	struct rtl_dm	*rtldm = rtl_dm(rtlpriv);

	 struct _rtw_hal	*pHalData = GET_HAL_DATA(rtlpriv);
	struct _rtw_dm *pDM_Odm = &pHalData->odmpriv;

	u8	ThermalValue = 0, delta, delta_LCK, delta_IQK, p = 0, i = 0;
	u8	ThermalValue_AVG_count = 0;
	uint32_t	ThermalValue_AVG = 0;

	u8	OFDM_min_index = 0;  /* OFDM BB Swing should be less than +if (.0dB, which is required by Arthur */
	u8	Indexforchannel = 0; /* GetRightChnlPlaceforIQK(pHalData->CurrentChannel) */

	/* 4 1. The following TWO tables decide the final index of OFDM/CCK swing table. */
	u8 *up_a, *down_a, *up_b, *down_b;

	/* 4 2. Initilization ( 7 steps in total ) */

	rtl8821au_get_delta_swing_table(rtlpriv, (u8 **)&up_a, (u8 **)&down_a,
					 (u8 **)&up_b, (u8 **)&down_b);


	rtldm->TXPowerTrackingCallbackCnt++; /* cosa add for debug */
	rtldm->bTXPowerTrackingInit = TRUE;

	ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("===>ODM_TXPowerTrackingCallback_ThermalMeter, \n rtldm->BbSwingIdxCckBase: %d, rtldm->BbSwingIdxOfdmBase[A]: %d, rtldm->DefaultOfdmIndex: %d\n", rtldm->BbSwingIdxCckBase, rtldm->BbSwingIdxOfdmBase[RF90_PATH_A], rtldm->DefaultOfdmIndex));

	ThermalValue = (u8)rtw_hal_read_rfreg(pDM_Odm->rtlpriv, RF90_PATH_A, RF_T_METER_8812A, 0xfc00);	/* 0x42: RF Reg[15:10] 88E */
	if (!rtldm->TxPowerTrackControl
	 || efuse->EEPROMThermalMeter == 0
	 || efuse->EEPROMThermalMeter == 0xFF)
		return;

	/* 4 if (. Initialize ThermalValues of RFCalibrateInfo */

	if (rtldm->bReloadtxpowerindex) {
		ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("reload ofdm index for band switch\n"));
	}

	/* 4 4. Calculate average thermal meter */

	rtldm->thermalvalue_avg[rtldm->thermalvalue_avg_index] = ThermalValue;
	rtldm->thermalvalue_avg_index++;
	if (rtldm->thermalvalue_avg_index == AVG_THERMAL_NUM_8812A)   /* Average times =  c.AverageThermalNum */
		rtldm->thermalvalue_avg_index = 0;

	for (i = 0; i < AVG_THERMAL_NUM_8812A; i++) {
		if (rtldm->thermalvalue_avg[i]) {
			ThermalValue_AVG += rtldm->thermalvalue_avg[i];
			ThermalValue_AVG_count++;
		}
	}

	if (ThermalValue_AVG_count) {               /* Calculate Average ThermalValue after average enough times */
		ThermalValue = (u8)(ThermalValue_AVG / ThermalValue_AVG_count);
		ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("AVG Thermal Meter = 0x%X, EFUSE Thermal Base = 0x%X\n", ThermalValue, efuse->EEPROMThermalMeter));
	}

	/* 4 5. Calculate delta, delta_LCK, delta_IQK. */

	/* "delta" here is used to determine whether thermal value changes or not. */
	delta 	  = (ThermalValue > rtldm->thermalvalue)?(ThermalValue - rtldm->thermalvalue):(rtldm->thermalvalue - ThermalValue);
	delta_LCK = (ThermalValue > rtldm->thermalvalue_lck)?(ThermalValue - rtldm->thermalvalue_lck):(rtldm->thermalvalue_lck - ThermalValue);
	delta_IQK = (ThermalValue > rtldm->thermalvalue_iqk)?(ThermalValue - rtldm->thermalvalue_iqk):(rtldm->thermalvalue_iqk - ThermalValue);

	ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("(delta, delta_LCK, delta_IQK) = (%d, %d, %d)\n", delta, delta_LCK, delta_IQK));

	/* 4 6. If necessary, do LCK. */

	if ((delta_LCK >= IQK_THRESHOLD)) {	/* Delta temperature is equal to or larger than 20 centigrade. */
		ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("delta_LCK(%d) >= Threshold_IQK(%d)\n", delta_LCK, IQK_THRESHOLD));
		rtldm->thermalvalue_lck = ThermalValue;
		PHY_LCCalibrate_8812A(rtlpriv);
	}

	/* if ( 7. If necessary, move the index of swing table to adjust Tx power. */

	if (delta > 0 && rtldm->TxPowerTrackControl) {
		/* "delta" here is used to record the absolute value of differrence. */
	    delta = ThermalValue > efuse->EEPROMThermalMeter?(ThermalValue - efuse->EEPROMThermalMeter):(efuse->EEPROMThermalMeter - ThermalValue);
		if (delta >= TXSCALE_TABLE_SIZE)
			delta = TXSCALE_TABLE_SIZE - 1;

		/* 4 7.1 The Final Power Index = BaseIndex + PowerIndexOffset */

		if (ThermalValue > efuse->EEPROMThermalMeter) {
			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("deltaSwingTableIdx_TUP_A[%d] = %d\n", delta, up_a[delta]));
			rtldm->DeltaPowerIndexLast[RF90_PATH_A] = rtldm->DeltaPowerIndex[RF90_PATH_A];
			rtldm->DeltaPowerIndex[RF90_PATH_A] = up_a[delta];

			rtldm->Aboslute_OFDMSwingIdx[RF90_PATH_A] =  up_a[delta];        /* Record delta swing for mix mode power tracking */

			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("******Temp is higher and rtldm->Aboslute_OFDMSwingIdx[RF90_PATH_A] = %d\n", rtldm->Aboslute_OFDMSwingIdx[RF90_PATH_A]));
		} else {
			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("deltaSwingTableIdx_TDOWN_A[%d] = %d\n", delta, down_a[delta]));

			rtldm->DeltaPowerIndexLast[RF90_PATH_A] = rtldm->DeltaPowerIndex[RF90_PATH_A];
			rtldm->DeltaPowerIndex[RF90_PATH_A] = -1 * down_a[delta];

			rtldm->Aboslute_OFDMSwingIdx[RF90_PATH_A] =  -1 * down_a[delta];        /* Record delta swing for mix mode power tracking */

			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("******Temp is lower and rtldm->Aboslute_OFDMSwingIdx[RF90_PATH_A] = %d\n", rtldm->Aboslute_OFDMSwingIdx[RF90_PATH_A]));
		}

	    for (p = RF90_PATH_A; p < MAX_PATH_NUM_8821A; p++) {
			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("\n\n================================ [Path-%c] Calculating PowerIndexOffset ================================\n", (p == RF90_PATH_A ? 'A' : 'B')));
			if (rtldm->DeltaPowerIndex[p] == rtldm->DeltaPowerIndexLast[p])         /* If Thermal value changes but lookup table value still the same */
				rtldm->PowerIndexOffset[p] = 0;
			else
				rtldm->PowerIndexOffset[p] = rtldm->DeltaPowerIndex[p] - rtldm->DeltaPowerIndexLast[p];      /* Power Index Diff between 2 times Power Tracking */

			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("[Path-%c] PowerIndexOffset(%d) = DeltaPowerIndex(%d) - DeltaPowerIndexLast(%d)\n", (p == RF90_PATH_A ? 'A' : 'B'), rtldm->PowerIndexOffset[p], rtldm->DeltaPowerIndex[p],
			rtldm->DeltaPowerIndexLast[p]));

			rtldm->OFDM_index[p] = rtldm->BbSwingIdxOfdmBase[p] + rtldm->PowerIndexOffset[p];
			rtldm->CCK_index = rtldm->BbSwingIdxCckBase + rtldm->PowerIndexOffset[p];

			rtldm->BbSwingIdxCck = rtldm->CCK_index;
			rtldm->BbSwingIdxOfdm[p] = rtldm->OFDM_index[p];

	       /* *************Print BB Swing Base and Index Offset************* */

			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("The 'CCK' final index(%d) = BaseIndex(%d) + PowerIndexOffset(%d)\n", rtldm->BbSwingIdxCck, rtldm->BbSwingIdxCckBase, rtldm->PowerIndexOffset[p]));
			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("The 'OFDM' final index(%d) = BaseIndex[%c](%d) + PowerIndexOffset(%d)\n", rtldm->BbSwingIdxOfdm[p], (p == RF90_PATH_A ? 'A' : 'B'), rtldm->BbSwingIdxOfdmBase[p], rtldm->PowerIndexOffset[p]));

		    /* 4 7.1 Handle boundary conditions of index. */

			if (rtldm->OFDM_index[p] > TXSCALE_TABLE_SIZE-1) {
				rtldm->OFDM_index[p] = TXSCALE_TABLE_SIZE-1;
			} else if (rtldm->OFDM_index[p] < OFDM_min_index) {
				rtldm->OFDM_index[p] = OFDM_min_index;
			}
		}
		ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("\n\n========================================================================================================\n"));
		if (rtldm->CCK_index > TXSCALE_TABLE_SIZE-1)
			rtldm->CCK_index = TXSCALE_TABLE_SIZE-1;
		/*
		 * else if (rtldm->RFCalibrateInfo.CCK_index < 0)
		 * 	rtldm->RFCalibrateInfo.CCK_index = 0;
		 */
	} else {
		ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("The thermal meter is unchanged or TxPowerTracking OFF(%d): ThermalValue: %d , rtldm->RFCalibrateInfo.ThermalValue: %d\n", rtldm->TxPowerTrackControl, ThermalValue, rtldm->thermalvalue));

		for (p = RF90_PATH_A; p < MAX_PATH_NUM_8821A; p++)
			rtldm->PowerIndexOffset[p] = 0;
	}
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("TxPowerTracking: [CCK] Swing Current Index: %d, Swing Base Index: %d\n", rtldm->CCK_index, rtldm->BbSwingIdxCckBase));       /* Print Swing base & current */
	for (p = RF90_PATH_A; p < MAX_PATH_NUM_8821A; p++) {
		ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("TxPowerTracking: [OFDM] Swing Current Index: %d, Swing Base Index[%c]: %d\n", rtldm->OFDM_index[p], (p == RF90_PATH_A ? 'A' : 'B'), rtldm->BbSwingIdxOfdmBase[p]));
	}

	if ((rtldm->PowerIndexOffset[RF90_PATH_A] != 0 ||  rtldm->PowerIndexOffset[RF90_PATH_B] != 0)
	 && rtldm->TxPowerTrackControl) {
		/* 4 7.2 Configure the Swing Table to adjust Tx Power. */
		rtldm->bTxPowerChanged = TRUE; /* Always TRUE after Tx Power is adjusted by power tracking. */
		/*
		 *  2012/04/2if ( MH According to Luke's suggestion, we can not write BB digital
		 *  to increase TX power. Otherwise, EVM will be bad.
		 *
		 *  2012/04/25 MH Add for tx power tracking to set tx power in tx agc for 88E.
		 */
		if (ThermalValue > rtldm->thermalvalue) {
			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("Temperature Increasing(A): delta_pi: %d , delta_t: %d, Now_t: %d, EFUSE_t: %d, Last_t: %d\n", rtldm->PowerIndexOffset[RF90_PATH_A], delta, ThermalValue, efuse->EEPROMThermalMeter, rtldm->thermalvalue));

			} else if (ThermalValue < rtldm->thermalvalue) { /* Low temperature */
				ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("Temperature Decreasing(A): delta_pi: %d , delta_t: %d, Now_t: %d, EFUSE_t: %d, Last_t: %d\n", rtldm->PowerIndexOffset[RF90_PATH_A], delta, ThermalValue, efuse->EEPROMThermalMeter, rtldm->thermalvalue));

			}
			if (ThermalValue > efuse->EEPROMThermalMeter) {
				ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("Temperature(%d) higher than PG value(%d)\n", ThermalValue, efuse->EEPROMThermalMeter));

				ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("**********Enter POWER Tracking MIX_MODE**********\n"));
				for (p = RF90_PATH_A; p < MAX_PATH_NUM_8821A; p++)
					ODM_TxPwrTrackSetPwr8821A(rtlpriv, MIX_MODE, p, Indexforchannel);
			} else {
				ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("Temperature(%d) lower than PG value(%d)\n", ThermalValue, efuse->EEPROMThermalMeter));

				ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("**********Enter POWER Tracking MIX_MODE**********\n"));
				for (p = RF90_PATH_A; p < MAX_PATH_NUM_8821A; p++)
					ODM_TxPwrTrackSetPwr8821A(rtlpriv, MIX_MODE, p, Indexforchannel);
			}

			rtldm->BbSwingIdxCckBase = rtldm->BbSwingIdxCck;  	/* Record last time Power Tracking result as base. */
			for (p = RF90_PATH_A; p < MAX_PATH_NUM_8821A; p++)
				rtldm->BbSwingIdxOfdmBase[p] = rtldm->BbSwingIdxOfdm[p];

			ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD,  ("rtldm->RFCalibrateInfo.ThermalValue = %d ThermalValue= %d\n", rtldm->thermalvalue, ThermalValue));

			rtldm->thermalvalue = ThermalValue;     /* Record last Power Tracking Thermal Value */

	}
	if ((delta_IQK >= IQK_THRESHOLD))	/* Delta temperature is equal to or larger than 20 centigrade (When threshold is 8). */
		DoIQK_8821A(rtlpriv, delta_IQK, ThermalValue, 8);

	ODM_RT_TRACE(pDM_Odm, ODM_COMP_TX_PWR_TRACK, ODM_DBG_LOUD, ("<===ODM_TXPowerTrackingCallback_ThermalMeter\n"));

	rtldm->TXPowercount = 0;
}

static void odm_TXPowerTrackingCheckCE(struct _rtw_dm *pDM_Odm)
{
	struct rtl_priv *rtlpriv = pDM_Odm->rtlpriv;
	struct rtl_hal *rtlhal = rtl_hal(rtlpriv);

	if (!(pDM_Odm->SupportAbility & ODM_RF_TX_PWR_TRACK)) {
		return;
	}

	if (!pDM_Odm->RFCalibrateInfo.TM_Trigger) {		/* at least delay 1 sec */
		/* pHalData->TxPowerCheckCnt++;	//cosa add for debug */
		if (IS_HARDWARE_TYPE_JAGUAR(rtlhal))
			rtw_hal_write_rfreg(pDM_Odm->rtlpriv, RF90_PATH_A, RF_T_METER_NEW, (BIT17 | BIT16), 0x03);
		else
			rtw_hal_write_rfreg(pDM_Odm->rtlpriv, RF90_PATH_A, RF_T_METER_OLD, bRFRegOffsetMask, 0x60);

		/* DBG_871X("Trigger Thermal Meter!!\n"); */

		pDM_Odm->RFCalibrateInfo.TM_Trigger = 1;
		return;
	} else {
		/* DBG_871X("Schedule TxPowerTracking direct call!!\n"); */
		if (IS_HARDWARE_TYPE_8812AU(rtlhal))
			rtl8812au_dm_txpower_tracking_callback_thermalmeter(rtlpriv);
		if (IS_HARDWARE_TYPE_8821U(rtlhal))
			rtl8821au_dm_txpower_tracking_callback_thermalmeter(rtlpriv);
		pDM_Odm->RFCalibrateInfo.TM_Trigger = 0;
	}

}

void ODM_TXPowerTrackingCheck(struct _rtw_dm *pDM_Odm)
{
	/*
	 * For AP/ADSL use prtl8192cd_priv
	 * For CE/NIC use _ADAPTER
	 */

	/*
	 * if (!(pDM_Odm->SupportAbility & ODM_RF_TX_PWR_TRACK))
	 * 	return;
	 */

	/*
	 * 2011/09/29 MH In HW integration first stage, we provide 4 different handle to operate
	 * at the same time. In the stage2/3, we need to prive universal interface and merge all
	 * HW dynamic mechanism.
	 */

	odm_TXPowerTrackingCheckCE(pDM_Odm);
}
