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
#ifndef __XMIT_OSDEP_H_
#define __XMIT_OSDEP_H_


struct pkt_file {
	struct sk_buff *pkt;
	SIZE_T pkt_len;	 //the remainder length of the open_file
	uint8_t *cur_buffer;
	uint8_t *buf_start;
	uint8_t *cur_addr;
	SIZE_T buf_len;
};



#ifdef PLATFORM_LINUX

#define NR_XMITFRAME	256

struct xmit_priv;
struct pkt_attrib;
struct sta_xmit_priv;
struct xmit_frame;
struct xmit_buf;

extern int rtw_xmit_entry(struct sk_buff *pkt, struct  net_device *ndev);

#endif

void rtw_os_xmit_schedule(struct rtl_priv *rtlpriv);

int rtw_os_xmit_resource_alloc(struct rtl_priv *rtlpriv, struct xmit_buf *pxmitbuf, u32 alloc_sz, uint8_t flag);
void rtw_os_xmit_resource_free(struct rtl_priv *rtlpriv, struct xmit_buf *pxmitbuf, u32 free_sz, uint8_t flag);

extern void rtw_set_tx_chksum_offload(struct sk_buff *pkt, struct pkt_attrib *pattrib);

extern uint rtw_remainder_len(struct pkt_file *pfile);
extern void _rtw_open_pktfile(struct sk_buff *pkt, struct pkt_file *pfile);
extern uint _rtw_pktfile_read (struct pkt_file *pfile, uint8_t *rmem, uint rlen);
extern sint rtw_endofpktfile (struct pkt_file *pfile);

extern void rtw_os_pkt_complete(struct rtl_priv *rtlpriv, struct sk_buff *pkt);
extern void rtw_os_xmit_complete(struct rtl_priv *rtlpriv, struct xmit_frame *pxframe);

#endif //__XMIT_OSDEP_H_

