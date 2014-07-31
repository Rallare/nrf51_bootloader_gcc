nrf51-uart-bitbanged
==================

This project is a arm-none-eabi-gcc port of the DFU bootloader delivered in Nordic's nRF51 SDK

KNOWN LIMITATIONS:
- not tested very well

Requirements
------------
- nRF51 SDK version 6 or newer
- nRF51822 Development kit or Evaluation kit

The project may need modifications to work with later versions or other boards. 

To compile it, clone the repository in the ../nrf51822/Board/nrf6310/device_firmware_updates/ folder.
Makefile.common and gcc_nrf51_s110_bootloader_xxaa.ld must be copied to folder ..\nrf51822\Source\templates\gcc

About this project
------------------
This application is one of several applications that has been built by the support team at Nordic Semiconductor, as a demo of some particular feature or use case. It has not necessarily been thoroughly tested, so there might be unknown issues. It is hence provided as-is, without any warranty. 

However, in the hope that it still may be useful also for others than the ones we initially wrote it for, we've chosen to distribute it here on GitHub. 

The application is built to be used with the official nRF51 SDK, that can be downloaded from www.nordicsemi.no, provided you have a product key for one of our kits.