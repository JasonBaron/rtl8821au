#ifndef __RTL8821AU_PHY_H__
#define __RTL8821AU_PHY_H__

u32 rtl8821au_phy_query_bb_reg(struct rtl_priv *Adapter, u32 RegAddr, u32 BitMask);
void rtl8821au_phy_set_bb_reg(struct rtl_priv *	Adapter, u32 RegAddr, u32 BitMask, u32 Data);

void rtl8821au_phy_iq_calibrate(struct rtl_priv *pAdapter, BOOLEAN bReCovery);


HAL_STATUS _rtl8821au_phy_config_mac_with_headerfile(struct rtl_dm *pDM_Odm);
HAL_STATUS _rtl8821au_phy_read_and_config_txpwr_lmt(struct rtl_dm *pDM_Odm);

void ODM_ReadAndConfig_MP_8821A_RadioA(struct rtl_dm * pDM_Odm, ODM_RF_RADIO_PATH_E eRFPath);
void rtl8812au_phy_config_rf_with_headerfile(struct rtl_dm *pDM_Odm, ODM_RF_RADIO_PATH_E eRFPath);

#endif
