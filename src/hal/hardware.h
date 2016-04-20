/**
 * @file      hardware.h
 */


#include "base.h"

/* Although these values were originally from the BCM2835 Arm peripherals PDF
   it's clear that was rushed and has some glaring errors - so these values
   may appear to be different. These values have been changed due to data on
   the elinux BCM2835 datasheet errata:
   http://elinux.org/BCM2835_datasheet_errata */

#define AUX_BASE    ( PERIPHERAL_BASE + 0x215000 )




typedef volatile uint32_t sfr_reg_t;
