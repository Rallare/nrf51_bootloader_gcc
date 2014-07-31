/* Copyright (c) 2013 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */

#include "bootloader_util.h"
#include <stdint.h>
#include "nordic_common.h"
#include "bootloader_types.h"
#include "dfu_types.h"


uint8_t  m_boot_settings[CODE_PAGE_SIZE] __attribute__((section (".bootloader_settings_sect"))) __attribute__((used));          /**< This variable reserves a codepage for bootloader specific settings, to ensure the compiler doesn't locate any code or variables at his location. */
uint32_t m_uicr_bootloader_start_address __attribute__((section (".NRF_UICR_BOOT_START_SECT")))  = BOOTLOADER_REGION_START;      /**< This variable ensures that the linker script will write the bootloader start address to the UICR register. This value will be written in the HEX file and thus written to UICR when the bootloader is flashed into the chip. */


void StartApplication(uint32_t start_addr)
{
    asm volatile(	"LDR   R2, [R0]             \n\t" 	// Get App MSP.
					"MSR   MSP, R2              \n\t"	// Set the main stack pointer to the applications MSP.
					"LDR   R3, [R0, #0x00000004]\n\t"   // Get application reset vector address.
					"BX    R3                   \n\t"   // No return - stack code is now activated only through SVC and plain interrupts.
					".ALIGN"
					);
}


void bootloader_util_app_start(uint32_t start_addr)
{
    StartApplication(start_addr);
}


void bootloader_util_settings_get(const bootloader_settings_t ** pp_bootloader_settings)
{
    // Read only pointer to bootloader settings in flash. 
    static bootloader_settings_t const * const p_bootloader_settings = 
        (bootloader_settings_t *)&m_boot_settings[0];        

    *pp_bootloader_settings = p_bootloader_settings;
}
