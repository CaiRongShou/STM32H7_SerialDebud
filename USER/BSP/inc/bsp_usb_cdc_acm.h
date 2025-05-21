#ifndef __DEV_USB_CDC_ACM_H_
#define __DEV_USB_CDC_ACM_H_

#include <stdint.h>


void cdc_acm_init(uint8_t busid, uintptr_t reg_base);
void cdc_acm_data_send_with_dtr_test(uint8_t busid);
void usb_send_data(uint8_t *data,uint16_t len);

#endif


 

