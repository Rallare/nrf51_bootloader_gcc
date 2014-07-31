/* Linker script to configure memory regions. */

SEARCH_DIR(.)
GROUP(-lgcc -lc -lnosys)

MEMORY
{
  FLASH (rx) : ORIGIN = 0x0003C000, LENGTH = 0x3C00 
  RAM (rwx) :  ORIGIN = 0x20002000, LENGTH = 0x2000 
  bootloader_settings (rwx) : ORIGIN = 0x0003FC00, LENGTH = 0x400
  NRF_UICR_BOOT_START (rwx) : ORIGIN = 0x10001014, LENGTH = 0x4
}
SECTIONS
{
    .bootloader_settings_block 0x0003FC00 :
    {
        KEEP(*(.bootloader_settings_sect))
    } > bootloader_settings

    .NRF_UICR_BOOT_START_BLOCK 0x10001014 :
    {
        KEEP(*(.NRF_UICR_BOOT_START_SECT))
    } > NRF_UICR_BOOT_START
}	

INCLUDE "gcc_nrf51_common.ld"