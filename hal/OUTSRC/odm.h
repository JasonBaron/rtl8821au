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


#ifndef	__HALDMOUTSRC_H__
#define __HALDMOUTSRC_H__

//============================================================
// Definition
//============================================================
//
// 2011/09/22 MH Define all team supprt ability.
//

//
// 2011/09/22 MH Define for all teams. Please Define the constan in your precomp header.
//
//#define		DM_ODM_SUPPORT_AP			0
//#define		DM_ODM_SUPPORT_ADSL			0
//#define		DM_ODM_SUPPORT_CE			0
//#define		DM_ODM_SUPPORT_MP			1

//
// 2011/09/28 MH Define ODM SW team support flag.
//



//
// Antenna Switch Relative Definition.
//

//
// 20100503 Joseph:
// Add new function SwAntDivCheck8192C().
// This is the main function of Antenna diversity function before link.
// Mainly, it just retains last scan result and scan again.
// After that, it compares the scan result to see which one gets better RSSI.
// It selects antenna with better receiving power and returns better scan result.
//
#define	TP_MODE		0
#define	RSSI_MODE		1
#define	TRAFFIC_LOW	0
#define	TRAFFIC_HIGH	1


//============================================================
//3 Tx Power Tracking
//3============================================================
#define DPK_DELTA_MAPPING_NUM	13
#define index_mapping_HP_NUM		15
#define OFDM_TABLE_SIZE 			37
#define OFDM_TABLE_SIZE_92D 		43
#define TXSCALE_TABLE_SIZE 			37
#define DELTA_SWINGIDX_SIZE		30
#define BAND_NUM 					3

//============================================================
//3 PSD Handler
//3============================================================

#define	AFH_PSD		1	//0:normal PSD scan, 1: only do 20 pts PSD
#define	MODE_40M		0	//0:20M, 1:40M
#define	PSD_TH2		3
#define	PSD_CHMIN		20   // Minimum channel number for BT AFH
#define	SIR_STEP_SIZE	3
#define   Smooth_Size_1 	5
#define	Smooth_TH_1	3
#define   Smooth_Size_2 	10
#define	Smooth_TH_2	4
#define   Smooth_Size_3 	20
#define	Smooth_TH_3	4
#define   Smooth_Step_Size 5
#define	Adaptive_SIR	1
#define	PSD_SCAN_INTERVAL	700 //ms



//8723A High Power IGI Setting
#define		DM_DIG_HIGH_PWR_IGI_LOWER_BOUND	0x22
#define  		DM_DIG_Gmode_HIGH_PWR_IGI_LOWER_BOUND 0x28
#define		DM_DIG_HIGH_PWR_THRESHOLD	0x3a
#define		DM_DIG_LOW_PWR_THRESHOLD	0x14

//ANT Test
#define 		ANTTESTALL		0x00		//Ant A or B will be Testing
#define		ANTTESTA		0x01		//Ant A will be Testing
#define		ANTTESTB		0x02		//Ant B will be testing

// LPS define
#define DM_DIG_FA_TH0_LPS				4 //-> 4 in lps
#define DM_DIG_FA_TH1_LPS				15 //-> 15 lps
#define DM_DIG_FA_TH2_LPS				30 //-> 30 lps
#define RSSI_OFFSET_DIG					0x05;



//for 8723A Ant Definition--2012--06--07 due to different IC may be different ANT define
#define		MAIN_ANT		1		//Ant A or Ant Main
#define		AUX_ANT		2		//AntB or Ant Aux
#define		MAX_ANT		3		// 3 for AP using


//Antenna Diversity Type
#define	SW_ANTDIV	0
#define	HW_ANTDIV	1

//Antenna Diversty Control Type
#define	ODM_AUTO_ANT	0
#define	ODM_FIX_MAIN_ANT	1
#define	ODM_FIX_AUX_ANT	2

//============================================================
// structure and define
//============================================================

//
// 2011/09/20 MH Add for AP/ADSLpseudo DM structuer requirement.
// We need to remove to other position???
//
#if(DM_ODM_SUPPORT_TYPE & (ODM_CE))
typedef		struct rtl8192cd_priv {
	u8		temp;

}rtl8192cd_priv, *prtl8192cd_priv;
#endif

typedef struct _Dynamic_Initial_Gain_Threshold_
{
	u8		Dig_Enable_Flag;
	u8		Dig_Ext_Port_Stage;

	int		   	RssiLowThresh;
	int		    	RssiHighThresh;

	uint32_t		FALowThresh;
	uint32_t		FAHighThresh;

	u8		CurSTAConnectState;
	u8		PreSTAConnectState;
	u8		CurMultiSTAConnectState;

	u8		PreIGValue;
	u8		CurIGValue;
	u8		BT30_CurIGI;
	u8		BackupIGValue;

	s8		BackoffVal;
	s8		BackoffVal_range_max;
	s8		BackoffVal_range_min;
	u8		rx_gain_range_max;
	u8		rx_gain_range_min;
	u8		Rssi_val_min;

	u8		PreCCK_CCAThres;
	u8		CurCCK_CCAThres;
	u8		PreCCKPDState;
	u8		CurCCKPDState;

	u8		LargeFAHit;
	u8		ForbiddenIGI;
	uint32_t		Recover_cnt;

	u8		DIG_Dynamic_MIN_0;
	u8		DIG_Dynamic_MIN_1;
	BOOLEAN		bMediaConnect_0;
	BOOLEAN		bMediaConnect_1;

	uint32_t		AntDiv_RSSI_max;
	uint32_t		RSSI_max;
}DIG_T,*pDIG_T;

typedef struct _Dynamic_Power_Saving_
{
	u8		PreCCAState;
	u8		CurCCAState;

	u8		PreRFState;
	u8		CurRFState;

	int		    Rssi_val_min;

	u8		initialize;
	uint32_t		Reg874,RegC70,Reg85C,RegA74;

}PS_T,*pPS_T;

typedef struct _FALSE_ALARM_STATISTICS{
	uint32_t	Cnt_Parity_Fail;
	uint32_t	Cnt_Rate_Illegal;
	uint32_t	Cnt_Crc8_fail;
	uint32_t	Cnt_Mcs_fail;
	uint32_t	Cnt_Ofdm_fail;
	uint32_t	Cnt_Cck_fail;
	uint32_t	Cnt_all;
	uint32_t	Cnt_Fast_Fsync;
	uint32_t	Cnt_SB_Search_fail;
	uint32_t	Cnt_OFDM_CCA;
	uint32_t	Cnt_CCK_CCA;
	uint32_t	Cnt_CCA_all;
	uint32_t	Cnt_BW_USC;	//Gary
	uint32_t	Cnt_BW_LSC;	//Gary
}FALSE_ALARM_STATISTICS, *PFALSE_ALARM_STATISTICS;

typedef struct _Dynamic_Primary_CCA{
	u8		PriCCA_flag;
	u8		intf_flag;
	u8		intf_type;
	u8		DupRTS_flag;
	u8		Monitor_flag;
	u8		CH_offset;
	u8  		MF_state;
}Pri_CCA_T, *pPri_CCA_T;

typedef struct _RX_High_Power_
{
	u8		RXHP_flag;
	u8		PSD_func_trigger;
	u8		PSD_bitmap_RXHP[80];
	u8		Pre_IGI;
	u8		Cur_IGI;
	u8		Pre_pw_th;
	u8		Cur_pw_th;
	BOOLEAN		First_time_enter;
	BOOLEAN		RXHP_enable;
	u8		TP_Mode;
	RT_TIMER	PSDTimer;

}RXHP_T, *pRXHP_T;

#if(DM_ODM_SUPPORT_TYPE & (ODM_CE))
#define ASSOCIATE_ENTRY_NUM					32 // Max size of AsocEntry[].
#define	ODM_ASSOCIATE_ENTRY_NUM				ASSOCIATE_ENTRY_NUM

#else
//
// 2012/01/12 MH Revise for compatiable with other SW team.
// 0 is for STA 1-n is for AP clients.
//
#define ODM_ASSOCIATE_ENTRY_NUM				ASSOCIATE_ENTRY_NUM+1// Default port only one
#endif

//#ifdef CONFIG_ANTENNA_DIVERSITY
// This indicates two different the steps.
// In SWAW_STEP_PEAK, driver needs to switch antenna and listen to the signal on the air.
// In SWAW_STEP_DETERMINE, driver just compares the signal captured in SWAW_STEP_PEAK
// with original RSSI to determine if it is necessary to switch antenna.
#define SWAW_STEP_PEAK		0
#define SWAW_STEP_DETERMINE	1

#define	TP_MODE		0
#define	RSSI_MODE		1
#define	TRAFFIC_LOW	0
#define	TRAFFIC_HIGH	1

typedef struct _SW_Antenna_Switch_
{
	u8		try_flag;
	int32_t		PreRSSI;
	u8		CurAntenna;
	u8		PreAntenna;
	u8		RSSI_Trying;
	u8		TestMode;
	u8		bTriggerAntennaSwitch;
	u8		SelectAntennaMap;
	u8		RSSI_target;

	// Before link Antenna Switch check
	u8		SWAS_NoLink_State;
	uint32_t		SWAS_NoLink_BK_Reg860;
	BOOLEAN		ANTA_ON;	//To indicate Ant A is or not
	BOOLEAN		ANTB_ON;	//To indicate Ant B is on or not

	int32_t		RSSI_sum_A;
	int32_t		RSSI_sum_B;
	int32_t		RSSI_cnt_A;
	int32_t		RSSI_cnt_B;

	uint64_t		lastTxOkCnt;
	uint64_t		lastRxOkCnt;
	uint64_t 		TXByteCnt_A;
	uint64_t 		TXByteCnt_B;
	uint64_t 		RXByteCnt_A;
	uint64_t 		RXByteCnt_B;
	u8 		TrafficLoad;
	RT_TIMER 	SwAntennaSwitchTimer;
/* CE Platform use
#ifdef CONFIG_SW_ANTENNA_DIVERSITY
	_timer SwAntennaSwitchTimer;
	uint64_t lastTxOkCnt;
	uint64_t lastRxOkCnt;
	uint64_t TXByteCnt_A;
	uint64_t TXByteCnt_B;
	uint64_t RXByteCnt_A;
	uint64_t RXByteCnt_B;
	u8 DoubleComfirm;
	u8 TrafficLoad;
	//SW Antenna Switch


#endif
*/
#ifdef CONFIG_HW_ANTENNA_DIVERSITY
	//Hybrid Antenna Diversity
	uint32_t		CCK_Ant1_Cnt[ASSOCIATE_ENTRY_NUM+1];
	uint32_t		CCK_Ant2_Cnt[ASSOCIATE_ENTRY_NUM+1];
	uint32_t		OFDM_Ant1_Cnt[ASSOCIATE_ENTRY_NUM+1];
	uint32_t		OFDM_Ant2_Cnt[ASSOCIATE_ENTRY_NUM+1];
	uint32_t		RSSI_Ant1_Sum[ASSOCIATE_ENTRY_NUM+1];
	uint32_t		RSSI_Ant2_Sum[ASSOCIATE_ENTRY_NUM+1];
	u8		TxAnt[ASSOCIATE_ENTRY_NUM+1];
	u8		TargetSTA;
	u8		antsel;
	u8		RxIdleAnt;

#endif

}SWAT_T, *pSWAT_T;
//#endif

typedef struct _EDCA_TURBO_
{
	BOOLEAN bCurrentTurboEDCA;
	BOOLEAN bIsCurRDLState;

	#if(DM_ODM_SUPPORT_TYPE == ODM_CE	)
	uint32_t	prv_traffic_idx; // edca turbo
	#endif

}EDCA_T,*pEDCA_T;

typedef struct _ODM_RATE_ADAPTIVE
{
	u8				Type;				// DM_Type_ByFW/DM_Type_ByDriver
	u8				LdpcThres;			// if RSSI > LdpcThres => switch from LPDC to BCC
	BOOLEAN				bUseLdpc;
	BOOLEAN				bLowerRtsRate;
	u8				HighRSSIThresh;		// if RSSI > HighRSSIThresh	=> RATRState is DM_RATR_STA_HIGH
	u8				LowRSSIThresh;		// if RSSI <= LowRSSIThresh	=> RATRState is DM_RATR_STA_LOW
	u8				RATRState;			// Current RSSI level, DM_RATR_STA_HIGH/DM_RATR_STA_MIDDLE/DM_RATR_STA_LOW

} ODM_RATE_ADAPTIVE, *PODM_RATE_ADAPTIVE;





#define IQK_MAC_REG_NUM		4
#define IQK_ADDA_REG_NUM		16
#define IQK_BB_REG_NUM_MAX	10


#define IQK_BB_REG_NUM			10
#define HP_THERMAL_NUM		8

#define AVG_THERMAL_NUM		8
#define IQK_Matrix_REG_NUM		8
#define IQK_Matrix_Settings_NUM	14+24+21 // Channels_2_4G_NUM + Channels_5G_20M_NUM + Channels_5G

#define		DM_Type_ByFW			0
#define		DM_Type_ByDriver		1

//
// Declare for common info
//
#define MAX_PATH_NUM_92CS			2
#define MAX_PATH_NUM_8188E		1
#define MAX_PATH_NUM_8192E		2
#define MAX_PATH_NUM_8723B		1
#define MAX_PATH_NUM_8812A		2
#define MAX_PATH_NUM_8821A		1

#define IQK_THRESHOLD				8

typedef struct _ODM_Phy_Status_Info_
{
	//
	// Be care, if you want to add any element please insert between
	// RxPWDBAll & SignalStrength.
	//
	u8		RxPWDBAll;

	u8		SignalQuality;	 		// in 0-100 index.
	s8		RxMIMOSignalQuality[4];	//per-path's EVM
	u8		RxMIMOEVMdbm[4]; 		//per-path's EVM dbm

	u8		RxMIMOSignalStrength[4];// in 0~100 index

	u16		Cfo_short[4]; 			// per-path's Cfo_short
	u16		Cfo_tail[4];			// per-path's Cfo_tail

#if (DM_ODM_SUPPORT_TYPE &  (ODM_CE))
	s8		RxPower;				// in dBm Translate from PWdB
	s8		RecvSignalPower;		// Real power in dBm for this packet, no beautification and aggregation. Keep this raw info to be used for the other procedures.
	u8		BTRxRSSIPercentage;
	u8		SignalStrength; 		// in 0-100 index.

	u8		RxPwr[4];				//per-path's pwdb
#endif
	u8		RxSNR[4];				//per-path's SNR
	u8		BandWidth;
	u8		btCoexPwrAdjust;
}ODM_PHY_INFO_T,*PODM_PHY_INFO_T;


typedef struct _ODM_Per_Pkt_Info_
{
	//u8		Rate;
	u8		DataRate;
	u8		StationID;
	BOOLEAN		bPacketMatchBSSID;
	BOOLEAN		bPacketToSelf;
	BOOLEAN		bPacketBeacon;
}ODM_PACKET_INFO_T,*PODM_PACKET_INFO_T;


typedef struct _ODM_Phy_Dbg_Info_
{
	//ODM Write,debug info
	s8		RxSNRdB[4];
	uint64_t		NumQryPhyStatus;
	uint64_t		NumQryPhyStatusCCK;
	uint64_t		NumQryPhyStatusOFDM;
	u8		NumQryBeaconPkt;
	//Others
	int32_t		RxEVM[4];

}ODM_PHY_DBG_INFO_T;


typedef struct _ODM_Mac_Status_Info_
{
	u8	test;

}ODM_MAC_INFO;


typedef enum tag_Dynamic_ODM_Support_Ability_Type
{
	// BB Team
	ODM_DIG				= 0x00000001,
	ODM_HIGH_POWER		= 0x00000002,
	ODM_CCK_CCA_TH		= 0x00000004,
	ODM_FA_STATISTICS		= 0x00000008,
	ODM_RAMASK			= 0x00000010,
	ODM_RSSI_MONITOR		= 0x00000020,
	ODM_SW_ANTDIV		= 0x00000040,
	ODM_HW_ANTDIV		= 0x00000080,
	ODM_BB_PWRSV			= 0x00000100,
	ODM_2TPATHDIV			= 0x00000200,
	ODM_1TPATHDIV			= 0x00000400,
	ODM_PSD2AFH			= 0x00000800
}ODM_Ability_E;

//
// 2011/20/20 MH For MP driver RT_WLAN_STA =  STA_INFO_T
// Please declare below ODM relative info in your STA info structure.
//
#if 1
typedef		struct _ODM_STA_INFO{
	// Driver Write
	BOOLEAN		bUsed;				// record the sta status link or not?
	//u8		WirelessMode;		//
	u8		IOTPeer;			// Enum value.	HT_IOT_PEER_E

	// ODM Write
	//1 PHY_STATUS_INFO
	u8		RSSI_Path[4];		//
	u8		RSSI_Ave;
	u8		RXEVM[4];
	u8		RXSNR[4];

	// ODM Write
	//1 TX_INFO (may changed by IC)
	//TX_INFO_T		pTxInfo;				// Define in IC folder. Move lower layer.
#if 0
	u8		ANTSEL_A;			//in Jagar: 4bit; others: 2bit
	u8		ANTSEL_B;			//in Jagar: 4bit; others: 2bit
	u8		ANTSEL_C;			//only in Jagar: 4bit
	u8		ANTSEL_D;			//only in Jagar: 4bit
	u8		TX_ANTL;			//not in Jagar: 2bit
	u8		TX_ANT_HT;			//not in Jagar: 2bit
	u8		TX_ANT_CCK;			//not in Jagar: 2bit
	u8		TXAGC_A;			//not in Jagar: 4bit
	u8		TXAGC_B;			//not in Jagar: 4bit
	u8		TXPWR_OFFSET;		//only in Jagar: 3bit
	u8		TX_ANT;				//only in Jagar: 4bit for TX_ANTL/TX_ANTHT/TX_ANT_CCK
#endif

	//
	// 	Please use compile flag to disabe the strcutrue for other IC except 88E.
	//	Move To lower layer.
	//
	// ODM Write Wilson will handle this part(said by Luke.Lee)
	//TX_RPT_T		pTxRpt;				// Define in IC folder. Move lower layer.
#if 0
	//1 For 88E RA (don't redefine the naming)
	u8		rate_id;
	u8		rate_SGI;
	u8		rssi_sta_ra;
	u8		SGI_enable;
	u8		Decision_rate;
	u8		Pre_rate;
	u8		Active;

	// Driver write Wilson handle.
	//1 TX_RPT (don't redefine the naming)
	u16		RTY[4];				// ???
	u16		TOTAL;				// ???
	u16		DROP;				// ???
	//
	// Please use compile flag to disabe the strcutrue for other IC except 88E.
	//
#endif

}ODM_STA_INFO_T, *PODM_STA_INFO_T;
#endif

//
// 2011/10/20 MH Define Common info enum for all team.
//
typedef enum _ODM_Common_Info_Definition
{
//-------------REMOVED CASE-----------//
	//ODM_CMNINFO_CCK_HP,
	//ODM_CMNINFO_RFPATH_ENABLE,		// Define as ODM write???
	//ODM_CMNINFO_OP_MODE,				// ODM_OPERATION_MODE_E
//-------------REMOVED CASE-----------//

	//
	// Fixed value:
	//

	//-----------HOOK BEFORE REG INIT-----------//
	ODM_CMNINFO_PLATFORM = 0,
	ODM_CMNINFO_ABILITY,					// ODM_ABILITY_E
	ODM_CMNINFO_INTERFACE,				// ODM_INTERFACE_E
	ODM_CMNINFO_MP_TEST_CHIP,
	ODM_CMNINFO_IC_TYPE,					// ODM_IC_TYPE_E
	ODM_CMNINFO_CUT_VER,					// ODM_CUT_VERSION_E
	ODM_CMNINFO_FAB_VER,					// ODM_FAB_E
	ODM_CMNINFO_RF_TYPE,					// ODM_RF_PATH_E or ODM_RF_TYPE_E?
	ODM_CMNINFO_RFE_TYPE,
	ODM_CMNINFO_BOARD_TYPE,				// ODM_BOARD_TYPE_E
	ODM_CMNINFO_EXT_LNA,					// TRUE
	ODM_CMNINFO_5G_EXT_LNA,
	ODM_CMNINFO_EXT_PA,
	ODM_CMNINFO_5G_EXT_PA,
	ODM_CMNINFO_EXT_TRSW,
	ODM_CMNINFO_PATCH_ID,				//CUSTOMER ID
	ODM_CMNINFO_BINHCT_TEST,
	ODM_CMNINFO_BWIFI_TEST,
	ODM_CMNINFO_SMART_CONCURRENT,
	//-----------HOOK BEFORE REG INIT-----------//


	//
	// Dynamic value:
	//
//--------- POINTER REFERENCE-----------//
	ODM_CMNINFO_MAC_PHY_MODE,			// ODM_MAC_PHY_MODE_E
	ODM_CMNINFO_WM_MODE,				// ODM_WIRELESS_MODE_E
	ODM_CMNINFO_BAND,					// ODM_BAND_TYPE_E
	ODM_CMNINFO_SEC_CHNL_OFFSET,		// ODM_SEC_CHNL_OFFSET_E
	ODM_CMNINFO_SEC_MODE,				// ODM_SECURITY_E
	ODM_CMNINFO_BW,						// ODM_BW_E
	ODM_CMNINFO_CHNL,
	ODM_CMNINFO_FORCED_RATE,

	ODM_CMNINFO_DMSP_GET_VALUE,
	ODM_CMNINFO_BUDDY_ADAPTOR,
	ODM_CMNINFO_DMSP_IS_MASTER,
	ODM_CMNINFO_SCAN,
	ODM_CMNINFO_POWER_SAVING,
	ODM_CMNINFO_ONE_PATH_CCA,			// ODM_CCA_PATH_E
	ODM_CMNINFO_DRV_STOP,
	ODM_CMNINFO_PNP_IN,
	ODM_CMNINFO_INIT_ON,
	ODM_CMNINFO_ANT_TEST,
	ODM_CMNINFO_NET_CLOSED,
	ODM_CMNINFO_MP_MODE,
//--------- POINTER REFERENCE-----------//

//------------CALL BY VALUE-------------//
	ODM_CMNINFO_WIFI_DIRECT,
	ODM_CMNINFO_WIFI_DISPLAY,
	ODM_CMNINFO_LINK,
	ODM_CMNINFO_RSSI_MIN,
	ODM_CMNINFO_DBG_COMP,				// uint64_t
	ODM_CMNINFO_DBG_LEVEL,				// uint32_t
	ODM_CMNINFO_RA_THRESHOLD_HIGH,		// u8
	ODM_CMNINFO_RA_THRESHOLD_LOW,		// u8
	ODM_CMNINFO_RF_ANTENNA_TYPE,		// u8
	ODM_CMNINFO_BT_DISABLED,
	ODM_CMNINFO_BT_HS_CONNECT_PROCESS,
	ODM_CMNINFO_BT_HS_RSSI,
	ODM_CMNINFO_BT_OPERATION,
	ODM_CMNINFO_BT_LIMITED_DIG,					//Need to Limited Dig or not
	ODM_CMNINFO_BT_DISABLE_EDCA,
//------------CALL BY VALUE-------------//

	//
	// Dynamic ptr array hook itms.
	//
	ODM_CMNINFO_STA_STATUS,
	ODM_CMNINFO_PHY_STATUS,
	ODM_CMNINFO_MAC_STATUS,

	ODM_CMNINFO_MAX,


}ODM_CMNINFO_E;

//
// 2011/10/20 MH Define ODM support ability.  ODM_CMNINFO_ABILITY
//
typedef enum _ODM_Support_Ability_Definition
{
	//
	// BB ODM section BIT 0-15
	//
	ODM_BB_DIG					= BIT0,
	ODM_BB_RA_MASK				= BIT1,
	ODM_BB_DYNAMIC_TXPWR		= BIT2,
	ODM_BB_FA_CNT					= BIT3,
	ODM_BB_RSSI_MONITOR			= BIT4,
	ODM_BB_CCK_PD				= BIT5,
	ODM_BB_ANT_DIV				= BIT6,
	ODM_BB_PWR_SAVE				= BIT7,
	ODM_BB_PWR_TRAIN				= BIT8,
	ODM_BB_RATE_ADAPTIVE			= BIT9,
	ODM_BB_PATH_DIV				= BIT10,
	ODM_BB_PSD					= BIT11,
	ODM_BB_RXHP					= BIT12,
	ODM_BB_ADAPTIVITY				= BIT13,
	ODM_BB_DYNAMIC_ATC			= BIT14,

	//
	// MAC DM section BIT 16-23
	//
	ODM_MAC_EDCA_TURBO			= BIT16,
	ODM_MAC_EARLY_MODE			= BIT17,

	//
	// RF ODM section BIT 24-31
	//
	ODM_RF_TX_PWR_TRACK			= BIT24,
	ODM_RF_RX_GAIN_TRACK			= BIT25,
	ODM_RF_CALIBRATION			= BIT26,

}ODM_ABILITY_E;

//	ODM_CMNINFO_INTERFACE
typedef enum tag_ODM_Support_Interface_Definition
{
	ODM_ITRF_USB 	=	0x2,
}ODM_INTERFACE_E;

// ODM_CMNINFO_IC_TYPE
typedef enum tag_ODM_Support_IC_Type_Definition
{
	ODM_RTL8812 	=	BIT5,
	ODM_RTL8821 	=	BIT6,
	ODM_RTL8813A	=	BIT9
}ODM_IC_TYPE_E;

#define ODM_IC_11AC_SERIES		(ODM_RTL8812 | ODM_RTL8821|ODM_RTL8813A)

//ODM_CMNINFO_CUT_VER
typedef enum tag_ODM_Cut_Version_Definition
{
	ODM_CUT_A 		=	1,
	ODM_CUT_B 		=	2,
	ODM_CUT_C 		=	3,
	ODM_CUT_D 		=	4,
	ODM_CUT_E 		=	5,
	ODM_CUT_F 		=	6,
	ODM_CUT_I 		=	9,
	ODM_CUT_TEST 	=	7,
}ODM_CUT_VERSION_E;

// ODM_CMNINFO_FAB_VER
typedef enum tag_ODM_Fab_Version_Definition
{
	ODM_TSMC 	=	0,
	ODM_UMC 	=	1,
	ODM_SMIC	=	2,
}ODM_FAB_E;

// ODM_CMNINFO_RF_TYPE
//
// For example 1T2R (A+AB = BIT0|BIT4|BIT5)
//
typedef enum tag_ODM_RF_Path_Bit_Definition
{
	ODM_RF_TX_A 	=	BIT0,
	ODM_RF_TX_B 	=	BIT1,
	ODM_RF_TX_C	=	BIT2,
	ODM_RF_TX_D	=	BIT3,
	ODM_RF_RX_A	=	BIT4,
	ODM_RF_RX_B	=	BIT5,
	ODM_RF_RX_C	=	BIT6,
	ODM_RF_RX_D	=	BIT7,
}ODM_RF_PATH_E;


typedef enum tag_ODM_RF_Type_Definition
{
	ODM_1T1R 	=	0,
	ODM_1T2R 	=	1,
	ODM_2T2R	=	2,
	ODM_2T3R	=	3,
	ODM_2T4R	=	4,
	ODM_3T3R	=	5,
	ODM_3T4R	=	6,
	ODM_4T4R	=	7,
}ODM_RF_TYPE_E;


//
// ODM Dynamic common info value definition
//

//typedef enum _MACPHY_MODE_8192D{
//	SINGLEMAC_SINGLEPHY,
//	DUALMAC_DUALPHY,
//	DUALMAC_SINGLEPHY,
//}MACPHY_MODE_8192D,*PMACPHY_MODE_8192D;
// Above is the original define in MP driver. Please use the same define. THX.
typedef enum tag_ODM_MAC_PHY_Mode_Definition
{
	ODM_SMSP	= 0,
	ODM_DMSP	= 1,
	ODM_DMDP	= 2,
}ODM_MAC_PHY_MODE_E;


typedef enum tag_BT_Coexist_Definition
{
	ODM_BT_BUSY 		= 1,
	ODM_BT_ON 			= 2,
	ODM_BT_OFF 		= 3,
	ODM_BT_NONE 		= 4,
}ODM_BT_COEXIST_E;

// ODM_CMNINFO_OP_MODE
typedef enum tag_Operation_Mode_Definition
{
	ODM_NO_LINK 		= BIT0,
	ODM_LINK 			= BIT1,
	ODM_SCAN 			= BIT2,
	ODM_POWERSAVE 	= BIT3,
	ODM_CLIENT_MODE	= BIT5,
	ODM_AD_HOC 		= BIT6,
	ODM_WIFI_DIRECT	= BIT7,
	ODM_WIFI_DISPLAY	= BIT8,
}ODM_OPERATION_MODE_E;

// ODM_CMNINFO_WM_MODE
typedef enum tag_Wireless_Mode_Definition
{
	ODM_WM_UNKNOW	= 0x0,
	ODM_WM_B			= BIT0,
	ODM_WM_G			= BIT1,
	ODM_WM_A			= BIT2,
	ODM_WM_N24G		= BIT3,
	ODM_WM_N5G		= BIT4,
	ODM_WM_AUTO		= BIT5,
	ODM_WM_AC		= BIT6,
}ODM_WIRELESS_MODE_E;

// ODM_CMNINFO_BAND
typedef enum tag_Band_Type_Definition
{
	ODM_BAND_2_4G 	= BIT0,
	ODM_BAND_5G 		= BIT1,

}ODM_BAND_TYPE_E;

// ODM_CMNINFO_SEC_CHNL_OFFSET
typedef enum tag_Secondary_Channel_Offset_Definition
{
	ODM_DONT_CARE 	= 0,
	ODM_BELOW 		= 1,
	ODM_ABOVE 			= 2
}ODM_SEC_CHNL_OFFSET_E;

// ODM_CMNINFO_SEC_MODE
typedef enum tag_Security_Definition
{
	ODM_SEC_OPEN 			= 0,
	ODM_SEC_WEP40 		= 1,
	ODM_SEC_TKIP 			= 2,
	ODM_SEC_RESERVE 		= 3,
	ODM_SEC_AESCCMP 		= 4,
	ODM_SEC_WEP104 		= 5,
	ODM_WEP_WPA_MIXED    = 6, // WEP + WPA
}ODM_SECURITY_E;

// ODM_CMNINFO_BW
typedef enum tag_Bandwidth_Definition
{
	ODM_BW20M 		= 0,
	ODM_BW40M 		= 1,
	ODM_BW80M 		= 2,
	ODM_BW160M 		= 3,
	ODM_BW10M 		= 4,
}ODM_BW_E;

// ODM_CMNINFO_CHNL

// ODM_CMNINFO_BOARD_TYPE
// For non-AC-series IC , ODM_BOARD_5G_EXT_PA and ODM_BOARD_5G_EXT_LNA are ignored
// For AC-series IC, external PA & LNA can be indivisuallly added on 2.4G and/or 5G
typedef enum tag_Board_Definition
{
    ODM_BOARD_DEFAULT  	= 0, 	  // The DEFAULT case.
    ODM_BOARD_MINICARD  = BIT(0), // 0 = non-mini card, 1= mini card.
    ODM_BOARD_SLIM      = BIT(1), // 0 = non-slim card, 1 = slim card
    ODM_BOARD_BT        = BIT(2), // 0 = without BT card, 1 = with BT
    ODM_BOARD_EXT_PA    = BIT(3), // 0 = no 2G ext-PA, 1 = existing 2G ext-PA
    ODM_BOARD_EXT_LNA   = BIT(4), // 0 = no 2G ext-LNA, 1 = existing 2G ext-LNA
    ODM_BOARD_EXT_TRSW  = BIT(5), // 0 = no ext-TRSW, 1 = existing ext-TRSW
    ODM_BOARD_EXT_PA_5G    = BIT(6), // 0 = no 5G ext-PA, 1 = existing 5G ext-PA
    ODM_BOARD_EXT_LNA_5G   = BIT(7), // 0 = no 5G ext-LNA, 1 = existing 5G ext-LNA
}ODM_BOARD_TYPE_E;


// ODM_CMNINFO_ONE_PATH_CCA
typedef enum tag_CCA_Path
{
	ODM_CCA_2R			= 0,
	ODM_CCA_1R_A			= 1,
	ODM_CCA_1R_B			= 2,
}ODM_CCA_PATH_E;


typedef struct _ODM_RA_Info_
{
	u8 RateID;
	uint32_t RateMask;
	uint32_t RAUseRate;
	u8 RateSGI;
	u8 RssiStaRA;
	u8 PreRssiStaRA;
	u8 SGIEnable;
	u8 DecisionRate;
	u8 PreRate;
	u8 HighestRate;
	u8 LowestRate;
	uint32_t NscUp;
	uint32_t NscDown;
	u16 RTY[5];
	uint32_t TOTAL;
	u16 DROP;
	u8 Active;
	u16 RptTime;
	u8 RAWaitingCounter;
	u8 RAPendingCounter;
#if 1 //POWER_TRAINING_ACTIVE == 1 // For compile  pass only~!
	u8 PTActive;  // on or off
	u8 PTTryState;  // 0 trying state, 1 for decision state
	u8 PTStage;  // 0~6
	u8 PTStopCount; //Stop PT counter
	u8 PTPreRate;  // if rate change do PT
	u8 PTPreRssi; // if RSSI change 5% do PT
	u8 PTModeSS;  // decide whitch rate should do PT
	u8 RAstage;  // StageRA, decide how many times RA will be done between PT
	u8 PTSmoothFactor;
#endif
} ODM_RA_INFO_T,*PODM_RA_INFO_T;

typedef struct _IQK_MATRIX_REGS_SETTING{
	BOOLEAN 	bIQKDone;
	int32_t		Value[3][IQK_Matrix_REG_NUM];
	BOOLEAN 	bBWIqkResultSaved[3];
}IQK_MATRIX_REGS_SETTING,*PIQK_MATRIX_REGS_SETTING;


typedef struct ODM_RF_Calibration_Structure
{
	//for tx power tracking

	uint32_t	RegA24; // for TempCCK
	int32_t	RegE94;
	int32_t 	RegE9C;
	int32_t	RegEB4;
	int32_t	RegEBC;

	u8  	TXPowercount;
	BOOLEAN bTXPowerTrackingInit;
	BOOLEAN bTXPowerTracking;
	u8  	TxPowerTrackControl; //for mp mode, turn off txpwrtracking as default
	u8  	TM_Trigger;
    	u8  	InternalPA5G[2];	//pathA / pathB

	u8  	ThermalMeter[2];    // ThermalMeter, index 0 for RFIC0, and 1 for RFIC1
	u8  	ThermalValue;
	u8  	ThermalValue_LCK;
	u8  	ThermalValue_IQK;
	u8	ThermalValue_DPK;
	u8	ThermalValue_AVG[AVG_THERMAL_NUM];
	u8	ThermalValue_AVG_index;
	u8	ThermalValue_RxGain;
	u8	ThermalValue_Crystal;
	u8	ThermalValue_DPKstore;
	u8	ThermalValue_DPKtrack;
	BOOLEAN	TxPowerTrackingInProgress;
	BOOLEAN	bDPKenable;

	BOOLEAN	bReloadtxpowerindex;
	u8 	bRfPiEnable;
	uint32_t 	TXPowerTrackingCallbackCnt; //cosa add for debug


	//------------------------- Tx power Tracking -------------------------//
	u8 	bCCKinCH14;
	u8 	CCK_index;
	u8 	OFDM_index[MAX_RF_PATH];
	s8	PowerIndexOffset[MAX_RF_PATH];
	s8	DeltaPowerIndex[MAX_RF_PATH];
	s8	DeltaPowerIndexLast[MAX_RF_PATH];
	BOOLEAN bTxPowerChanged;

	u8 	ThermalValue_HP[HP_THERMAL_NUM];
	u8 	ThermalValue_HP_index;
	BOOLEAN	bNeedIQK;
	u8	Delta_IQK;
	u8	Delta_LCK;
	s8  BBSwingDiff2G, BBSwingDiff5G; // Unit: dB

	//--------------------------------------------------------------------//

	//for IQK
	uint32_t 	RegC04;
	uint32_t 	Reg874;
	uint32_t 	RegC08;
	uint32_t 	RegB68;
	uint32_t 	RegB6C;
	uint32_t 	Reg870;
	uint32_t 	Reg860;
	uint32_t 	Reg864;

	BOOLEAN	bIQKInitialized;
	BOOLEAN bLCKInProgress;
	BOOLEAN	bAntennaDetected;
	uint32_t	ADDA_backup[IQK_ADDA_REG_NUM];
	uint32_t	IQK_MAC_backup[IQK_MAC_REG_NUM];
	uint32_t	IQK_BB_backup_recover[9];
	uint32_t	IQK_BB_backup[IQK_BB_REG_NUM];

	//for APK
	uint32_t 	APKoutput[2][2]; //path A/B; output1_1a/output1_2a
	u8 	bAPKdone;
	u8 	bAPKThermalMeterIgnore;
	u8 	bDPdone;
	u8 	bDPPathAOK;
	u8 	bDPPathBOK;

	uint32_t 	TxIQC_8723B[2][3][2]; // { {S0: 0xc94, 0xc80, 0xc4c} , {S1: 0xc9c, 0xc88, 0xc4c}}
	uint32_t 	RxIQC_8723B[2][2][2]; // { {S0: 0xc14, 0xca0} , {S1: 0xc1c, 0xc78}}

}ODM_RF_CAL_T,*PODM_RF_CAL_T;
//
// ODM Dynamic common info value definition
//

typedef struct _FAST_ANTENNA_TRAINNING_
{
	u8	Bssid[6];
	u8	antsel_rx_keep_0;
	u8	antsel_rx_keep_1;
	u8	antsel_rx_keep_2;
	uint32_t	antSumRSSI[7];
	uint32_t	antRSSIcnt[7];
	uint32_t	antAveRSSI[7];
	u8	FAT_State;
	uint32_t	TrainIdx;
	u8	antsel_a[ODM_ASSOCIATE_ENTRY_NUM];
	u8	antsel_b[ODM_ASSOCIATE_ENTRY_NUM];
	u8	antsel_c[ODM_ASSOCIATE_ENTRY_NUM];
	uint32_t	MainAnt_Sum[ODM_ASSOCIATE_ENTRY_NUM];
	uint32_t	AuxAnt_Sum[ODM_ASSOCIATE_ENTRY_NUM];
	uint32_t	MainAnt_Cnt[ODM_ASSOCIATE_ENTRY_NUM];
	uint32_t	AuxAnt_Cnt[ODM_ASSOCIATE_ENTRY_NUM];
	u8	RxIdleAnt;
	BOOLEAN		bBecomeLinked;

}FAT_T,*pFAT_T;

typedef enum _FAT_STATE
{
	FAT_NORMAL_STATE			= 0,
	FAT_TRAINING_STATE 		= 1,
}FAT_STATE_E, *PFAT_STATE_E;

typedef enum _ANT_DIV_TYPE
{
	NO_ANTDIV			= 0xFF,
	CG_TRX_HW_ANTDIV		= 0x01,
	CGCS_RX_HW_ANTDIV 	= 0x02,
	FIXED_HW_ANTDIV		= 0x03,
	CG_TRX_SMART_ANTDIV	= 0x04,
	CGCS_RX_SW_ANTDIV	= 0x05,
	S0S1_HW_ANTDIV          = 0x06, //8723B intrnal switch S0 S1
}ANT_DIV_TYPE_E, *PANT_DIV_TYPE_E;

typedef struct _ODM_PATH_DIVERSITY_
{
	u8	RespTxPath;
	u8	PathSel[ODM_ASSOCIATE_ENTRY_NUM];
	uint32_t	PathA_Sum[ODM_ASSOCIATE_ENTRY_NUM];
	uint32_t	PathB_Sum[ODM_ASSOCIATE_ENTRY_NUM];
	uint32_t	PathA_Cnt[ODM_ASSOCIATE_ENTRY_NUM];
	uint32_t	PathB_Cnt[ODM_ASSOCIATE_ENTRY_NUM];
}PATHDIV_T, *pPATHDIV_T;


typedef enum _BASEBAND_CONFIG_PHY_REG_PG_VALUE_TYPE{
	PHY_REG_PG_RELATIVE_VALUE = 0,
	PHY_REG_PG_EXACT_VALUE = 1
} PHY_REG_PG_TYPE;


//
// Antenna detection information from single tone mechanism, added by Roger, 2012.11.27.
//
typedef struct _ANT_DETECTED_INFO{
	BOOLEAN			bAntDetected;
	uint32_t			dBForAntA;
	uint32_t			dBForAntB;
	uint32_t			dBForAntO;
}ANT_DETECTED_INFO, *PANT_DETECTED_INFO;

//
// 2011/09/22 MH Copy from SD4 defined structure. We use to support PHY DM integration.
//
struct rtl_dm {
	//RT_TIMER 	FastAntTrainingTimer;
	//
	//	Add for different team use temporarily
	//
	struct rtl_priv *	Adapter;		// For CE/NIC team
	prtl8192cd_priv	priv;			// For AP/ADSL team
	// WHen you use Adapter or priv pointer, you must make sure the pointer is ready.
	BOOLEAN			odm_ready;

#if(DM_ODM_SUPPORT_TYPE & (ODM_CE))
	rtl8192cd_priv		fake_priv;
#endif

	PHY_REG_PG_TYPE		PhyRegPgValueType;

	uint64_t			DebugComponents;
	uint32_t			DebugLevel;

	uint64_t			NumQryPhyStatusAll; 	//CCK + OFDM
	uint64_t			LastNumQryPhyStatusAll;
	uint64_t			RxPWDBAve;
	uint64_t			RxPWDBAve_final;
	BOOLEAN			MPDIG_2G; 		//off MPDIG
	u8			Times_2G;

//------ ODM HANDLE, DRIVER NEEDS NOT TO HOOK------//
	BOOLEAN			bCckHighPower;
	u8			RFPathRxEnable;		// ODM_CMNINFO_RFPATH_ENABLE
	u8			ControlChannel;
//------ ODM HANDLE, DRIVER NEEDS NOT TO HOOK------//

//--------REMOVED COMMON INFO----------//
	//u8				PseudoMacPhyMode;
	//BOOLEAN			*BTCoexist;
	//BOOLEAN			PseudoBtCoexist;
	//u8				OPMode;
	//BOOLEAN			bAPMode;
	//BOOLEAN			bClientMode;
	//BOOLEAN			bAdHocMode;
	//BOOLEAN			bSlaveOfDMSP;
//--------REMOVED COMMON INFO----------//


//1  COMMON INFORMATION

	//
	// Init Value
	//
//-----------HOOK BEFORE REG INIT-----------//
	// ODM Platform info AP/ADSL/CE/MP = 1/2/3/4
	u8			SupportPlatform;
	// ODM Support Ability DIG/RATR/TX_PWR_TRACK/ �K�K = 1/2/3/�K
	uint32_t			SupportAbility;
	// ODM PCIE/USB/SDIO = 1/2/3
	u8			SupportInterface;
	// ODM composite or independent. Bit oriented/ 92C+92D+ .... or any other type = 1/2/3/...
	uint32_t			SupportICType;
	// Cut Version TestChip/A-cut/B-cut... = 0/1/2/3/...
	u8			CutVersion;
	// Fab Version TSMC/UMC = 0/1
	u8			FabVersion;
	// RF Type 4T4R/3T3R/2T2R/1T2R/1T1R/...
	u8			RFType;
	u8			RFEType;
	// Board Type Normal/HighPower/MiniCard/SLIM/Combo/... = 0/1/2/3/4/...
	u8			BoardType;
	// with external LNA  NO/Yes = 0/1
	u8			ExtLNA;
	u8			ExtLNA5G;
	// with external PA  NO/Yes = 0/1
	u8			ExtPA;
	u8			ExtPA5G;
	// with external TRSW  NO/Yes = 0/1
	u8			ExtTRSW;
	u8			PatchID; //Customer ID
	BOOLEAN			bInHctTest;
	BOOLEAN			bWIFITest;

	BOOLEAN			bDualMacSmartConcurrent;
	uint32_t			BK_SupportAbility;
	u8			AntDivType;
//-----------HOOK BEFORE REG INIT-----------//

	//
	// Dynamic Value
	//
//--------- POINTER REFERENCE-----------//

	u8			u8_temp;
	BOOLEAN			BOOLEAN_temp;
	struct rtl_priv *	ADAPTER_temp;

	// MAC PHY Mode SMSP/DMSP/DMDP = 0/1/2
	u8			*pMacPhyMode;
	// Wireless mode B/G/A/N = BIT0/BIT1/BIT2/BIT3
	u8			*pWirelessMode; //ODM_WIRELESS_MODE_E
	// Frequence band 2.4G/5G = 0/1
	u8			*pBandType;
	// Secondary channel offset don't_care/below/above = 0/1/2
	u8			*pSecChOffset;
	// Security mode Open/WEP/AES/TKIP = 0/1/2/3
	u8			*pSecurity;
	// BW info 20M/40M/80M = 0/1/2
	u8			*pBandWidth;
 	// Central channel location Ch1/Ch2/....
	u8			*pChannel;	//central channel number
	// Common info for 92D DMSP

	BOOLEAN			*pbGetValueFromOtherMac;
	struct rtl_priv *	*pBuddyAdapter;
	BOOLEAN			*pbMasterOfDMSP; //MAC0: master, MAC1: slave
	// Common info for Status
	BOOLEAN			*pbScanInProcess;
	BOOLEAN			*pbPowerSaving;
	// CCA Path 2-path/path-A/path-B = 0/1/2; using ODM_CCA_PATH_E.
	u8			*pOnePathCCA;
	//pMgntInfo->AntennaTest
	u8			*pAntennaTest;
	BOOLEAN			*pbNet_closed;
	u8			*mp_mode;
	//u8			*pAidMap;
//--------- POINTER REFERENCE-----------//
	u16			*pForcedDataRate;
//------------CALL BY VALUE-------------//
	BOOLEAN			bLinkInProcess;
	BOOLEAN			bWIFI_Direct;
	BOOLEAN			bWIFI_Display;
	BOOLEAN			bLinked;
	u8			RSSI_Min;
	u8          InterfaceIndex; // Add for 92D  dual MAC: 0--Mac0 1--Mac1
	BOOLEAN         bIsMPChip;
	BOOLEAN			bOneEntryOnly;
	// Common info for BTDM
	BOOLEAN			bBtDisabled;			// BT is disabled
	BOOLEAN			bBtConnectProcess;	// BT HS is under connection progress.
	u8			btHsRssi;				// BT HS mode wifi rssi value.
	BOOLEAN			bBtHsOperation;		// BT HS mode is under progress
	BOOLEAN			bBtDisableEdcaTurbo;	// Under some condition, don't enable the EDCA Turbo
	BOOLEAN			bBtLimitedDig;   		// BT is busy.
//------------CALL BY VALUE-------------//
	u8			RSSI_A;
	u8			RSSI_B;
	uint64_t			RSSI_TRSW;
	uint64_t			RSSI_TRSW_H;
	uint64_t			RSSI_TRSW_L;
	uint64_t			RSSI_TRSW_iso;

	u8			RxRate;
	BOOLEAN			StopDIG;
	u8			TxRate;
	u8			LinkedInterval;
	u8			preChannel;
	u8			AntType;
	uint32_t			TxagcOffsetValueA;
	BOOLEAN			IsTxagcOffsetPositiveA;
	uint32_t			TxagcOffsetValueB;
	BOOLEAN			IsTxagcOffsetPositiveB;
	uint64_t			lastTxOkCnt;
	uint64_t			lastRxOkCnt;
	uint32_t			BbSwingOffsetA;
	BOOLEAN			IsBbSwingOffsetPositiveA;
	uint32_t			BbSwingOffsetB;
	BOOLEAN			IsBbSwingOffsetPositiveB;
	uint32_t			TH_H;
	uint32_t			TH_L;
	uint32_t			IGI_Base;
	uint32_t			IGI_target;
	BOOLEAN			ForceEDCCA;
	u8			AdapEn_RSSI;
	BOOLEAN			bForceThresh;
	uint32_t			Force_TH_H;
	uint32_t			Force_TH_L;

	//2 Define STA info.
	// _ODM_STA_INFO
	// 2012/01/12 MH For MP, we need to reduce one array pointer for default port.??
	PSTA_INFO_T		pODM_StaInfo[ODM_ASSOCIATE_ENTRY_NUM];

#if (RATE_ADAPTIVE_SUPPORT == 1)
	u16 			CurrminRptTime;
	ODM_RA_INFO_T   RAInfo[ODM_ASSOCIATE_ENTRY_NUM]; //See HalMacID support
#endif
	//
	// 2012/02/14 MH Add to share 88E ra with other SW team.
	// We need to colelct all support abilit to a proper area.
	//
	BOOLEAN				RaSupport88E;

	// Define ...........

	// Latest packet phy info (ODM write)
	ODM_PHY_DBG_INFO_T	 PhyDbgInfo;
	//PHY_INFO_88E		PhyInfo;

	// Latest packet phy info (ODM write)
	ODM_MAC_INFO		*pMacInfo;
	//MAC_INFO_88E		MacInfo;

	// Different Team independt structure??

	//
	//TX_RTP_CMN		TX_retrpo;
	//TX_RTP_88E		TX_retrpo;
	//TX_RTP_8195		TX_retrpo;

	//
	//ODM Structure
	//
	FAT_T		DM_FatTable;
	DIG_T		DM_DigTable;
	PS_T		DM_PSTable;
	Pri_CCA_T	DM_PriCCA;
	RXHP_T		DM_RXHP_Table;
	FALSE_ALARM_STATISTICS	FalseAlmCnt;
	FALSE_ALARM_STATISTICS	FlaseAlmCntBuddyAdapter;
	//#ifdef CONFIG_ANTENNA_DIVERSITY
	SWAT_T		DM_SWAT_Table;
	BOOLEAN		RSSI_test;
	//#endif


	EDCA_T		DM_EDCA_Table;
	uint32_t		WMMEDCA_BE;
	PATHDIV_T	DM_PathDiv;
	// Copy from SD4 structure
	//
	// ==================================================
	//

	//common
	//u8		DM_Type;
	//u8    PSD_Report_RXHP[80];   // Add By Gary
	//u8    PSD_func_flag;               // Add By Gary
	//for DIG
	//u8		bDMInitialGainEnable;
	//u8		binitialized; // for dm_initial_gain_Multi_STA use.
	//for Antenna diversity
	//u8	AntDivCfg;// 0:OFF , 1:ON, 2:by efuse
	//PSTA_INFO_T RSSI_target;

	BOOLEAN			*pbDriverStopped;
	BOOLEAN			*pbDriverIsGoingToPnpSetPowerSleep;
	BOOLEAN			*pinit_adpt_in_progress;

	//PSD
	BOOLEAN			bUserAssignLevel;
	RT_TIMER 		PSDTimer;
	u8			RSSI_BT;			//come from BT
	BOOLEAN			bPSDinProcess;
	BOOLEAN			bPSDactive;
	BOOLEAN			bDMInitialGainEnable;

	//MPT DIG
	RT_TIMER 		MPT_DIGTimer;

	//for rate adaptive, in fact,  88c/92c fw will handle this
	u8			bUseRAMask;

	ODM_RATE_ADAPTIVE	RateAdaptive;

	ANT_DETECTED_INFO	AntDetectedInfo; // Antenna detected information for RSSI tool

	ODM_RF_CAL_T	RFCalibrateInfo;

	//
	// TX power tracking
	//
	u8			BbSwingIdxOfdm[MAX_RF_PATH];
	u8			BbSwingIdxOfdmCurrent;
	u8			BbSwingIdxOfdmBase[MAX_RF_PATH];
	BOOLEAN			BbSwingFlagOfdm;
	u8			BbSwingIdxCck;
	u8			BbSwingIdxCckCurrent;
	u8			BbSwingIdxCckBase;
	u8			DefaultOfdmIndex;
	u8			DefaultCckIndex;
	BOOLEAN			BbSwingFlagCck;

	s8			Aboslute_OFDMSwingIdx[MAX_RF_PATH];
	s8			Remnant_OFDMSwingIdx[MAX_RF_PATH];
	s8			Remnant_CCKSwingIdx;
	s8			Modify_TxAGC_Value;       //Remnat compensate value at TxAGC
	BOOLEAN			Modify_TxAGC_Flag_PathA;
	BOOLEAN			Modify_TxAGC_Flag_PathB;

	//
	// Dynamic ATC switch
	//
	BOOLEAN			bATCStatus;
	BOOLEAN			largeCFOHit;
	BOOLEAN			bIsfreeze;
	int				CFO_tail[2];
	int				CFO_ave_pre;
	int				CrystalCap;
	u8			CFOThreshold;
	uint32_t			packetCount;
	uint32_t			packetCount_pre;

	//
	// ODM system resource.
	//

	// ODM relative time.
	RT_TIMER 				PathDivSwitchTimer;
	//2011.09.27 add for Path Diversity
	RT_TIMER				CCKPathDiversityTimer;
	RT_TIMER 	FastAntTrainingTimer;

	// ODM relative workitem.

};


#if 1 //92c-series
#define ODM_RF_PATH_MAX 2
#else //jaguar - series
#define ODM_RF_PATH_MAX 4
#endif
 typedef enum _ODM_RF_CONTENT{
	odm_radioa_txt = 0x1000,
	odm_radiob_txt = 0x1001,
	odm_radioc_txt = 0x1002,
	odm_radiod_txt = 0x1003
} ODM_RF_CONTENT;

typedef enum _ODM_BB_Config_Type{
    CONFIG_BB_PHY_REG,
    CONFIG_BB_AGC_TAB,
    CONFIG_BB_AGC_TAB_2G,
    CONFIG_BB_AGC_TAB_5G,
    CONFIG_BB_PHY_REG_PG,
} ODM_BB_Config_Type, *PODM_BB_Config_Type;

typedef enum _ODM_RF_Config_Type{
	CONFIG_RF_RADIO,
} ODM_RF_Config_Type, *PODM_RF_Config_Type;

// Status code
typedef enum _RT_STATUS{
	RT_STATUS_SUCCESS,
	RT_STATUS_FAILURE,
	RT_STATUS_PENDING,
	RT_STATUS_RESOURCE,
	RT_STATUS_INVALID_CONTEXT,
	RT_STATUS_INVALID_PARAMETER,
	RT_STATUS_NOT_SUPPORT,
	RT_STATUS_OS_API_FAILED,
}RT_STATUS,*PRT_STATUS;

#ifdef REMOVE_PACK
#pragma pack()
#endif

//#include "odm_function.h"

//3===========================================================
//3 DIG
//3===========================================================

typedef enum tag_Dynamic_Init_Gain_Operation_Type_Definition
{
	DIG_TYPE_THRESH_HIGH	= 0,
	DIG_TYPE_THRESH_LOW	= 1,
	DIG_TYPE_BACKOFF		= 2,
	DIG_TYPE_RX_GAIN_MIN	= 3,
	DIG_TYPE_RX_GAIN_MAX	= 4,
	DIG_TYPE_ENABLE 		= 5,
	DIG_TYPE_DISABLE 		= 6,
	DIG_OP_TYPE_MAX
}DM_DIG_OP_E;
/*
typedef enum tag_CCK_Packet_Detection_Threshold_Type_Definition
{
	CCK_PD_STAGE_LowRssi = 0,
	CCK_PD_STAGE_HighRssi = 1,
	CCK_PD_STAGE_MAX = 3,
}DM_CCK_PDTH_E;

typedef enum tag_DIG_EXT_PORT_ALGO_Definition
{
	DIG_EXT_PORT_STAGE_0 = 0,
	DIG_EXT_PORT_STAGE_1 = 1,
	DIG_EXT_PORT_STAGE_2 = 2,
	DIG_EXT_PORT_STAGE_3 = 3,
	DIG_EXT_PORT_STAGE_MAX = 4,
}DM_DIG_EXT_PORT_ALG_E;

typedef enum tag_DIG_Connect_Definition
{
	DIG_STA_DISCONNECT = 0,
	DIG_STA_CONNECT = 1,
	DIG_STA_BEFORE_CONNECT = 2,
	DIG_MultiSTA_DISCONNECT = 3,
	DIG_MultiSTA_CONNECT = 4,
	DIG_CONNECT_MAX
}DM_DIG_CONNECT_E;


#define DM_MultiSTA_InitGainChangeNotify(Event) {DM_DigTable.CurMultiSTAConnectState = Event;}

#define DM_MultiSTA_InitGainChangeNotify_CONNECT(_ADAPTER)	\
	DM_MultiSTA_InitGainChangeNotify(DIG_MultiSTA_CONNECT)

#define DM_MultiSTA_InitGainChangeNotify_DISCONNECT(_ADAPTER)	\
	DM_MultiSTA_InitGainChangeNotify(DIG_MultiSTA_DISCONNECT)
*/
#define		DM_DIG_THRESH_HIGH			40
#define		DM_DIG_THRESH_LOW			35

#define		DM_FALSEALARM_THRESH_LOW	400
#define		DM_FALSEALARM_THRESH_HIGH	1000

#define		DM_DIG_MAX_NIC				0x3e
#define		DM_DIG_MIN_NIC				0x1e //0x22//0x1c

#define		DM_DIG_MAX_AP					0x32
#define		DM_DIG_MIN_AP					0x20

#define		DM_DIG_MAX_NIC_HP			0x46
#define		DM_DIG_MIN_NIC_HP			0x2e

#define		DM_DIG_MAX_AP_HP				0x42
#define		DM_DIG_MIN_AP_HP				0x30

//vivi 92c&92d has different definition, 20110504
//this is for 92c
#ifdef CONFIG_SPECIAL_SETTING_FOR_FUNAI_TV
#define		DM_DIG_FA_TH0				0x80//0x20
#else
#define		DM_DIG_FA_TH0				0x200//0x20
#endif
#define		DM_DIG_FA_TH1				0x300//0x100
#define		DM_DIG_FA_TH2				0x400//0x200
//this is for 92d
#define		DM_DIG_FA_TH0_92D			0x100
#define		DM_DIG_FA_TH1_92D			0x400
#define		DM_DIG_FA_TH2_92D			0x600

#define		DM_DIG_BACKOFF_MAX			12
#define		DM_DIG_BACKOFF_MIN			-4
#define		DM_DIG_BACKOFF_DEFAULT		10

//3===========================================================
//3 AGC RX High Power Mode
//3===========================================================
#define          LNA_Low_Gain_1                      0x64
#define          LNA_Low_Gain_2                      0x5A
#define          LNA_Low_Gain_3                      0x58

#define          FA_RXHP_TH1                           5000
#define          FA_RXHP_TH2                           1500
#define          FA_RXHP_TH3                             800
#define          FA_RXHP_TH4                             600
#define          FA_RXHP_TH5                             500

//3===========================================================
//3 EDCA
//3===========================================================

//3===========================================================
//3 Dynamic Tx Power
//3===========================================================
//Dynamic Tx Power Control Threshold
#define		TX_POWER_NEAR_FIELD_THRESH_LVL2	74
#define		TX_POWER_NEAR_FIELD_THRESH_LVL1	67
#define		TX_POWER_NEAR_FIELD_THRESH_AP		0x3F

#define		TxHighPwrLevel_Normal		0
#define		TxHighPwrLevel_Level1		1
#define		TxHighPwrLevel_Level2		2
#define		TxHighPwrLevel_BT1			3
#define		TxHighPwrLevel_BT2			4
#define		TxHighPwrLevel_15			5
#define		TxHighPwrLevel_35			6
#define		TxHighPwrLevel_50			7
#define		TxHighPwrLevel_70			8
#define		TxHighPwrLevel_100			9

//3===========================================================
//3 Tx Power Tracking
//3===========================================================
#if 0 //mask this, since these have been defined in typdef.h, vivi
#define	OFDM_TABLE_SIZE 	37
#define	OFDM_TABLE_SIZE_92D 	43
#endif


//3===========================================================
//3 Rate Adaptive
//3===========================================================
#define		DM_RATR_STA_INIT			0
#define		DM_RATR_STA_HIGH			1
#define 		DM_RATR_STA_MIDDLE		2
#define 		DM_RATR_STA_LOW			3

//3===========================================================
//3 BB Power Save
//3===========================================================


//3===========================================================
//3 Dynamic ATC switch
//3===========================================================
#define		ATC_Status_Off				0x0			// enable
#define		ATC_Status_On				0x1			// disable
#define		CFO_Threshold_Xtal			10			// kHz
#define		CFO_Threshold_ATC			80			// kHz

typedef enum tag_1R_CCA_Type_Definition
{
	CCA_1R =0,
	CCA_2R = 1,
	CCA_MAX = 2,
}DM_1R_CCA_E;

typedef enum tag_RF_Type_Definition
{
	RF_Save =0,
	RF_Normal = 1,
	RF_MAX = 2,
}DM_RF_E;

//3===========================================================
//3 Antenna Diversity
//3===========================================================
typedef enum tag_SW_Antenna_Switch_Definition
{
	Antenna_A = 1,
	Antenna_B = 2,
	Antenna_MAX = 3,
}DM_SWAS_E;


// Maximal number of antenna detection mechanism needs to perform, added by Roger, 2011.12.28.
#define	MAX_ANTENNA_DETECTION_CNT	10

//
// Extern Global Variables.
//
extern	uint32_t OFDMSwingTable[OFDM_TABLE_SIZE_92D];
extern	uint32_t OFDMSwingTable_New[OFDM_TABLE_SIZE_92D];
extern  uint32_t TxScalingTable_Jaguar[TXSCALE_TABLE_SIZE];

// <20121018, Kordan> In case fail to read TxPowerTrack.txt, we use the table of 88E as the default table.
static u8 DeltaSwingTableIdx_2GA_P_8188E[] = {0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 4,  4,  4,  4,  4,  4,  5,  5,  7,  7,  8,  8,  8,  9,  9,  9,  9,  9};
static u8 DeltaSwingTableIdx_2GA_N_8188E[] = {0, 0, 0, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5,  6,  6,  7,  7,  7,  7,  8,  8,  9,  9, 10, 10, 10, 11, 11, 11, 11};

//
// check Sta pointer valid or not
//
#define IS_STA_VALID(pSta)		(pSta)
// 20100514 Joseph: Add definition for antenna switching test after link.
// This indicates two different the steps.
// In SWAW_STEP_PEAK, driver needs to switch antenna and listen to the signal on the air.
// In SWAW_STEP_DETERMINE, driver just compares the signal captured in SWAW_STEP_PEAK
// with original RSSI to determine if it is necessary to switch antenna.
#define SWAW_STEP_PEAK		0
#define SWAW_STEP_DETERMINE	1

VOID ODM_Write_DIG(IN	struct rtl_dm *pDM_Odm, 	IN	u8	CurrentIGI);
VOID ODM_Write_CCK_CCA_Thres(IN	struct rtl_dm *pDM_Odm, IN	u8	CurCCK_CCAThres);

VOID
ODM_SetAntenna(
	IN 	struct rtl_dm *pDM_Odm,
	IN	u8		Antenna);


#define SwAntDivRestAfterLink	ODM_SwAntDivRestAfterLink
VOID ODM_SwAntDivRestAfterLink(	IN	struct rtl_dm *pDM_Odm);

#define dm_CheckTXPowerTracking 	ODM_TXPowerTrackingCheck
VOID
ODM_TXPowerTrackingCheck(
	IN		struct rtl_dm *	pDM_Odm
	);

BOOLEAN
ODM_RAStateCheck(
	IN		struct rtl_dm *	pDM_Odm,
	IN		int32_t			RSSI,
	IN		BOOLEAN			bForceUpdate,
	OUT		u8 *		pRATRState
	);


#define dm_SWAW_RSSI_Check	ODM_SwAntDivChkPerPktRssi
VOID ODM_SwAntDivChkPerPktRssi(
	IN struct rtl_dm *	pDM_Odm,
	IN u8			StationID,
	IN PODM_PHY_INFO_T pPhyInfo
	);

#if((DM_ODM_SUPPORT_TYPE==ODM_CE))

uint32_t
GetPSDData(
	struct rtl_dm *pDM_Odm,
	unsigned int 	point,
	u8 initial_gain_psd);

#endif

#if (DM_ODM_SUPPORT_TYPE == ODM_CE)

VOID
odm_DIGbyRSSI_LPS(
	IN		struct rtl_dm *	pDM_Odm
	);

uint32_t ODM_Get_Rate_Bitmap(
	IN	struct rtl_dm *pDM_Odm,
	IN	uint32_t		macid,
	IN	uint32_t 		ra_mask,
	IN	u8 		rssi_level);

#endif


VOID ODM_DMInit( IN	struct rtl_dm *pDM_Odm);

VOID
ODM_DMWatchdog(
	IN		struct rtl_dm *		pDM_Odm			// For common use in the future
	);

VOID
ODM_CmnInfoInit(
	IN		struct rtl_dm *	pDM_Odm,
	IN		ODM_CMNINFO_E	CmnInfo,
	IN		uint32_t			Value
	);

VOID
ODM_CmnInfoHook(
	IN		struct rtl_dm *	pDM_Odm,
	IN		ODM_CMNINFO_E	CmnInfo,
	IN		PVOID			pValue
	);

VOID
ODM_CmnInfoPtrArrayHook(
	IN		struct rtl_dm *	pDM_Odm,
	IN		ODM_CMNINFO_E	CmnInfo,
	IN		u16			Index,
	IN		PVOID			pValue
	);

VOID
ODM_CmnInfoUpdate(
	IN		struct rtl_dm *	pDM_Odm,
	IN		uint32_t			CmnInfo,
	IN		uint64_t			Value
	);

VOID
ODM_InitAllTimers(
    IN struct rtl_dm *pDM_Odm
    );

VOID
ODM_CancelAllTimers(
    IN struct rtl_dm *   pDM_Odm
    );

VOID
ODM_ReleaseAllTimers(
    IN struct rtl_dm *pDM_Odm
    );

VOID
ODM_AntselStatistics_88C(
	IN		struct rtl_dm *	pDM_Odm,
	IN		u8			MacId,
	IN		uint32_t			PWDBAll,
	IN		BOOLEAN			isCCKrate
);

#if( DM_ODM_SUPPORT_TYPE & (ODM_CE))


#endif	// #if((DM_ODM_SUPPORT_TYPE==ODM_CE))

VOID
ODM_UpdateInitRate(
	IN	struct rtl_dm *pDM_Odm,
	IN	u8		Rate
	);
#if (DM_ODM_SUPPORT_TYPE == ODM_CE)
void odm_dtc(struct rtl_dm *pDM_Odm);
#endif /* #if (DM_ODM_SUPPORT_TYPE == ODM_CE) */

#endif

