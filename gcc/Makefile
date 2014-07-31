TARGET_CHIP := NRF51822_QFAA_CA
BOARD := BOARD_NRF6310

# application source
C_SOURCE_FILES += main.c
C_SOURCE_FILES += dfu_dual_bank.c
C_SOURCE_FILES += bootloader.c
C_SOURCE_FILES += bootloader_util_gcc.c
C_SOURCE_FILES += ble_dfu.c
C_SOURCE_FILES += crc16.c
C_SOURCE_FILES += softdevice_handler.c
C_SOURCE_FILES += ble_advdata.c
C_SOURCE_FILES += ble_debug_assert_handler.c
C_SOURCE_FILES += ble_error_log.c
C_SOURCE_FILES += ble_conn_params.c
C_SOURCE_FILES += app_timer.c
C_SOURCE_FILES += app_scheduler.c
C_SOURCE_FILES += pstorage.c
C_SOURCE_FILES += app_gpiote.c
C_SOURCE_FILES += hci_mem_pool.c
C_SOURCE_FILES += dfu_transport_ble.c



SDK_PATH = ../../../../../

OUTPUT_FILENAME := bootloader_gcc

DEVICE_VARIANT := xxaa
#DEVICE_VARIANT := xxab

USE_SOFTDEVICE := S110_BOOT
#USE_SOFTDEVICE := S210

CFLAGS := -DDEBUG_NRF_USER -DBLE_STACK_SUPPORT_REQD -DS110 -DBOARD_NRF6310 -DBOOTLOADER_BANKED

# we do not use heap in this app
ASMFLAGS := -D__HEAP_SIZE=0

# keep every function in separate section. This will allow linker to dump unused functions
CFLAGS += -ffunction-sections 
CFLAGS += -fno-short-enums

# let linker to dump unused sections
#LDFLAGS := -Wl --gc-sections --specs=nano.specs
LDFLAGS := --specs=nano.specs

INCLUDEPATHS += -I"../"
INCLUDEPATHS += -I"../include"
INCLUDEPATHS += -I"../include/ble_transport"
INCLUDEPATHS += -I"$(SDK_PATH)Include/s110"
INCLUDEPATHS += -I"$(SDK_PATH)Include/ble"
INCLUDEPATHS += -I"$(SDK_PATH)Include/ble/device_manager"
INCLUDEPATHS += -I"$(SDK_PATH)Include/ble/ble_services"
INCLUDEPATHS += -I"$(SDK_PATH)Include/app_common"
INCLUDEPATHS += -I"$(SDK_PATH)Include/sd_common"
INCLUDEPATHS += -I"$(SDK_PATH)Include/sdk"

C_SOURCE_PATHS += $(SDK_PATH)Source/ble
C_SOURCE_PATHS += $(SDK_PATH)Source/ble/device_manager
C_SOURCE_PATHS += $(SDK_PATH)Source/app_common
C_SOURCE_PATHS += $(SDK_PATH)Source/sd_common
C_SOURCE_PATHS += -I"../"
C_SOURCE_PATHS += -I"../include"
C_SOURCE_PATHS += -I"../include/ble_transport"

include $(SDK_PATH)Source/templates/gcc/Makefile.common
