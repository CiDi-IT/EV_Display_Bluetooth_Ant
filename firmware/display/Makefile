PROJECT_NAME     := display_firmware
TARGETS          := display_firmware

# This is the user visible string for the version
VERSION_STRING := 0.15.0

# This is the expected version of the motor firmware. Display will stop to work with correct TSDZ2 firmware version
MOTOR_FIRMWARE_MAJOR := 1
MOTOR_FIRMWARE_MINOR := 1

APP_VER_MAJOR = 1
APP_VER_MINOR = 0

ifdef MOTOR_TSDZ2
$(warning )
$(warning MOTOR: TSDZ2)
MOTOR = TSDZ2
CFLAGS = -DMOTOR_TSDZ2
endif

ifdef MOTOR_BAFANG
$(warning )
$(warning MOTOR: BAFANG)
MOTOR = BAFANG_M500_M600
CFLAGS = -DMOTOR_BAFANG
endif

ifdef DISPLAY_OLED_1.3_SPI
$(warning DISPLAY OLED 1.3 SPI)
$(warning )
DISPLAY = OLED_1.3_SPI
CFLAGS += -DDISPLAY_SH1106
CFLAGS += -DDISPLAY_SPI
endif

ifdef DISPLAY_OLED_1.3_I2C
$(warning DISPLAY OLED 1.3 I2C)
$(warning )
DISPLAY = OLED_1.3_I2C
CFLAGS += -DDISPLAY_SH1106
CFLAGS += -DDISPLAY_I2C
endif

ifdef DISPLAY_OLED_0.96_SPI
$(warning DISPLAY OLED 0.96 SPI)
$(warning )
DISPLAY = OLED_0.96_SPI
CFLAGS += -DDISPLAY_SSD1306
CFLAGS += -DDISPLAY_SPI
endif

ifdef DISPLAY_OLED_0.96_I2C
$(warning DISPLAY_OLED_0.96_I2C)
$(warning )
DISPLAY = OLED_0.96_I2C
CFLAGS += -DDISPLAY_SSD1306
CFLAGS += -DDISPLAY_I2C
endif

# This is the expected version of the motor firmware. Display will stop to work with correct TSDZ2 firmware version
MOTOR_FIRMWARE_MAJOR := 1
MOTOR_FIRMWARE_MINOR := 1

OUTPUT_DIRECTORY := _build

SDK_ROOT := ../common_firmware/nRF5_SDK_16.0.0
PROJ_DIR := .

$(OUTPUT_DIRECTORY)/display_firmware.out: \
  LINKER_SCRIPT  := linker_script_nrf52.ld

BOOTLOADER_DIR = $(PROJ_DIR)/../EBike_wireless_bootloader/firmware
BOOTLOADER_HEX = $(BOOTLOADER_DIR)/_build/bootloader.hex

# The integer build number for this release, MUST BE INCREMENTED FOR EACH RELEASE SO BOOTLOADER WILL INSTALL
# it is not user visible, but we must ensure it is monotonically increasing
VERSION_NUM := 1

CFLAGS += -DVERSION_STRING=\"$(VERSION_STRING)\" -DMOTOR_FIRMWARE_MAJOR=\"$(MOTOR_FIRMWARE_MAJOR)\" -DMOTOR_FIRMWARE_MINOR=\"$(MOTOR_FIRMWARE_MINOR)\"

# Source files common to all targets
SRC_FILES += \
  $(SDK_ROOT)/modules/nrfx/mdk/gcc_startup_nrf52840.S \
  $(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_clock.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_clock.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_backend_rtt.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_backend_serial.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_backend_uart.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_default_backends.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_frontend.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_str_formatter.c \
  $(SDK_ROOT)/modules/nrfx/mdk/system_nrf52840.c \
  $(SDK_ROOT)/components/libraries/button/app_button.c \
  $(SDK_ROOT)/components/libraries/util/app_error.c \
  $(SDK_ROOT)/components/libraries/util/app_error_handler_gcc.c \
  $(SDK_ROOT)/components/libraries/util/app_error_weak.c \
  $(SDK_ROOT)/components/libraries/scheduler/app_scheduler.c \
  $(SDK_ROOT)/components/libraries/timer/app_timer2.c \
  $(SDK_ROOT)/components/libraries/util/app_util_platform.c \
  $(SDK_ROOT)/components/libraries/timer/drv_rtc.c \
  $(SDK_ROOT)/components/libraries/hardfault/nrf52/handler/hardfault_handler_gcc.c \
  $(SDK_ROOT)/components/libraries/hardfault/hardfault_implementation.c \
  $(SDK_ROOT)/components/libraries/util/nrf_assert.c \
  $(SDK_ROOT)/components/libraries/atomic_fifo/nrf_atfifo.c \
  $(SDK_ROOT)/components/libraries/atomic/nrf_atomic.c \
  $(SDK_ROOT)/components/libraries/balloc/nrf_balloc.c \
  $(SDK_ROOT)/external/fprintf/nrf_fprintf.c \
  $(SDK_ROOT)/external/fprintf/nrf_fprintf_format.c \
  $(SDK_ROOT)/components/libraries/memobj/nrf_memobj.c \
  $(SDK_ROOT)/components/libraries/pwr_mgmt/nrf_pwr_mgmt.c \
  $(SDK_ROOT)/components/libraries/ringbuf/nrf_ringbuf.c \
  $(SDK_ROOT)/components/libraries/experimental_section_vars/nrf_section_iter.c \
  $(SDK_ROOT)/components/libraries/sortlist/nrf_sortlist.c \
  $(SDK_ROOT)/components/libraries/strerror/nrf_strerror.c \
  $(SDK_ROOT)/components/libraries/sensorsim/sensorsim.c \
  $(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_uart.c \
	$(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_twi.c \
  $(SDK_ROOT)/modules/nrfx/soc/nrfx_atomic.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_gpiote.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/prs/nrfx_prs.c \
	$(SDK_ROOT)/modules/nrfx/hal/nrf_nvmc.c \
	$(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_twi.c \
	$(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_twim.c \
  $(SDK_ROOT)/components/libraries/bsp/bsp.c \
  $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT.c \
  $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT_Syscalls_GCC.c \
  $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT_printf.c \
  $(SDK_ROOT)/components/softdevice/common/nrf_sdh.c \
  $(SDK_ROOT)/components/softdevice/common/nrf_sdh_ant.c \
	$(SDK_ROOT)/components/libraries/crc16/crc16.c \
	$(SDK_ROOT)/components/libraries/fifo/app_fifo.c \
  $(SDK_ROOT)/components/libraries/uart/app_uart_fifo.c \
	$(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_uart.c \
	$(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_uart.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_uarte.c \
  $(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_spi.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_spi.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_spim.c \
	$(SDK_ROOT)/components/libraries/atomic_flags/nrf_atflags.c \
	$(SDK_ROOT)/components/libraries/fstorage/nrf_fstorage.c \
	$(SDK_ROOT)/components/libraries/fstorage/nrf_fstorage_sd.c \
	$(SDK_ROOT)/components/libraries/fds/fds.c \
	$(SDK_ROOT)/components/ble/common/ble_advdata.c \
  $(SDK_ROOT)/components/ble/common/ble_conn_params.c \
  $(SDK_ROOT)/components/ble/common/ble_conn_state.c \
  $(SDK_ROOT)/components/ble/common/ble_srv_common.c \
  $(SDK_ROOT)/components/ble/nrf_ble_gatt/nrf_ble_gatt.c \
  $(SDK_ROOT)/components/ble/nrf_ble_qwr/nrf_ble_qwr.c \
  $(SDK_ROOT)/components/ble/peer_manager/gatt_cache_manager.c \
  $(SDK_ROOT)/components/ble/peer_manager/gatts_cache_manager.c \
  $(SDK_ROOT)/components/ble/peer_manager/id_manager.c \
  $(SDK_ROOT)/components/ble/nrf_ble_gq/nrf_ble_gq.c \
  $(SDK_ROOT)/components/ble/peer_manager/peer_data_storage.c \
  $(SDK_ROOT)/components/ble/peer_manager/peer_database.c \
  $(SDK_ROOT)/components/ble/peer_manager/peer_id.c \
  $(SDK_ROOT)/components/ble/peer_manager/peer_manager.c \
  $(SDK_ROOT)/components/ble/peer_manager/peer_manager_handler.c \
  $(SDK_ROOT)/components/ble/peer_manager/pm_buffer.c \
  $(SDK_ROOT)/components/ble/peer_manager/security_dispatcher.c \
  $(SDK_ROOT)/components/ble/peer_manager/security_manager.c \
	$(SDK_ROOT)/components/ble/common/ble_advdata.c \
  $(SDK_ROOT)/components/ble/ble_advertising/ble_advertising.c \
  $(SDK_ROOT)/components/softdevice/common/nrf_sdh_ble.c \
  $(SDK_ROOT)/components/softdevice/common/nrf_sdh_soc.c \
  $(SDK_ROOT)/components/ant/ant_profiles/ant_common/ant_request_controller/ant_request_controller.c \
  $(SDK_ROOT)/components/ant/ant_channel_config/ant_channel_config.c \
  $(SDK_ROOT)/components/ant/ant_key_manager/ant_key_manager.c \
  $(SDK_ROOT)/components/ant/ant_state_indicator/ant_state_indicator.c \
  $(SDK_ROOT)/components/ant/ant_search_config/ant_search_config.c \
  $(SDK_ROOT)/components/ant/ant_profiles/ant_common/pages/ant_common_page_70.c \
  $(SDK_ROOT)/components/ant/ant_profiles/ant_common/pages/ant_common_page_80.c \
  $(SDK_ROOT)/components/ant/ant_profiles/ant_common/pages/ant_common_page_81.c \
  $(PROJ_DIR)/antplus_lev/antplus_lev.c \
  $(PROJ_DIR)/antplus_lev/pages/antplus_lev_page_1.c \
  $(PROJ_DIR)/antplus_lev/pages/antplus_lev_page_2.c \
  $(PROJ_DIR)/antplus_lev/pages/antplus_lev_page_3.c \
  $(PROJ_DIR)/antplus_lev/pages/antplus_lev_page_4.c \
  $(PROJ_DIR)/antplus_lev/pages/antplus_lev_page_5.c \
  $(PROJ_DIR)/antplus_lev/pages/antplus_lev_page_34.c \
  $(PROJ_DIR)/antplus_lev/pages/antplus_lev_page_16.c \
  $(PROJ_DIR)/antplus_lev/pages/antplus_lev_common_data.c \
  $(PROJ_DIR)/antplus_controls/antplus_controls.c \
  $(PROJ_DIR)/antplus_controls/pages/antplus_controls_page_73.c \
  $(PROJ_DIR)/antplus_controls/pages/antplus_controls_page_82.c \
  $(PROJ_DIR)/pins.c \
	$(PROJ_DIR)/utils.c \
	$(PROJ_DIR)/eeprom.c \
	$(PROJ_DIR)/state.c \
	$(PROJ_DIR)/uart.c \
	$(PROJ_DIR)/utils.c \
	$(PROJ_DIR)/ble_services.c \
  $(PROJ_DIR)/buttons.c \
  $(PROJ_DIR)/../common_firmware/ledalert.c \
  $(PROJ_DIR)/../common_firmware/common.c \
  $(PROJ_DIR)/main.c \
  $(SDK_ROOT)/components/boards/boards.c \
	$(PROJ_DIR)/ssd1306_driver/glcdfont.c \
	$(PROJ_DIR)/ssd1306_driver/SSD1306.c \
	$(PROJ_DIR)/display.c \
	$(PROJ_DIR)/ugui.c \
	$(PROJ_DIR)/screen.c \
	$(PROJ_DIR)/fonts.c \
	$(PROJ_DIR)/mainscreen.c \
	$(PROJ_DIR)/mainscreen-oled128x64.c \
	$(PROJ_DIR)/battery_gui.c \
	$(PROJ_DIR)/rtc.c \
	$(PROJ_DIR)/configscreen.c \
	$(PROJ_DIR)/spi.c \
  $(PROJ_DIR)/can/MCP2515.c \
  $(PROJ_DIR)/can/CANSPI.c \
  $(PROJ_DIR)/can.c \
 
# Include folders common to all targets
INC_FOLDERS += \
  $(SDK_ROOT)/ \
  $(PROJ_DIR)/../common_firmware/include \
  $(SDK_ROOT)/components/libraries/sensorsim \
  $(SDK_ROOT)/external/fprintf \
  $(SDK_ROOT)/components/softdevice/s340/headers \
  $(SDK_ROOT)/components/softdevice/s340/headers/nrf52 \
  $(SDK_ROOT)/components/libraries/hardfault/nrf52 \
  $(SDK_ROOT)/integration/nrfx \
  $(SDK_ROOT)/components/libraries/scheduler \
  $(SDK_ROOT)/components/libraries/experimental_section_vars \
  $(SDK_ROOT)/components/libraries/atomic_fifo \
	$(SDK_ROOT)/components/libraries/uart \
	$(SDK_ROOT)/components/libraries/fifo \
	$(SDK_ROOT)/components/libraries/fstorage \
	$(SDK_ROOT)/components/libraries/fds \
  $(SDK_ROOT)/modules/nrfx/mdk \
  $(SDK_ROOT)/components/libraries/strerror \
  $(SDK_ROOT)/integration/nrfx/legacy \
  $(SDK_ROOT)/components/boards \
  $(SDK_ROOT)/components/softdevice/s340/headers \
  $(SDK_ROOT)/components/libraries/button \
  $(SDK_ROOT)/components/libraries/log \
  $(SDK_ROOT)/modules/nrfx/hal \
  $(SDK_ROOT)/components/libraries/log/src \
  $(SDK_ROOT)/components/libraries/bsp \
  $(SDK_ROOT)/components/libraries/bootloader \
  $(SDK_ROOT)/modules/nrfx/hal \
  $(SDK_ROOT)/components/libraries/sortlist \
  $(SDK_ROOT)/modules/nrfx/drivers/include \
  $(SDK_ROOT)/components/libraries/hardfault \
  $(SDK_ROOT)/components/libraries/balloc \
	$(SDK_ROOT)/components/libraries/crc16 \
  $(SDK_ROOT)/components/libraries/util \
  $(SDK_ROOT)/components/libraries/queue \
  $(SDK_ROOT)/modules/nrfx \
  $(SDK_ROOT)/components/softdevice/common \
  $(SDK_ROOT)/components \
  $(SDK_ROOT)/external/segger_rtt \
  $(SDK_ROOT)/components/libraries/ringbuf \
  $(SDK_ROOT)/components/libraries/svc \
  $(SDK_ROOT)/components/libraries/memobj \
  $(SDK_ROOT)/components/libraries/atomic \
  $(SDK_ROOT)/components/libraries/delay \
  $(SDK_ROOT)/components/toolchain/cmsis/include \
  $(SDK_ROOT)/components/libraries/mutex \
  $(SDK_ROOT)/components/libraries/pwr_mgmt \
  $(SDK_ROOT)/components/libraries/timer \
	$(SDK_ROOT)/components/libraries/atomic_flags \
  $(SDK_ROOT)/components/libraries/bootloader \
	$(SDK_ROOT)/components/ble/common \
	$(SDK_ROOT)/components/ble/ble_services/ble_ancs_c \
  $(SDK_ROOT)/components/ble/ble_services \
  $(SDK_ROOT)/components/ble/ble_services/ble_ias_c \
	$(SDK_ROOT)/components/ble/ble_services/ble_gls \
	$(SDK_ROOT)/components/ble/ble_advertising \
	$(SDK_ROOT)/components/ble/ble_dtm \
	$(SDK_ROOT)/components/ble/ble_services/ble_rscs_c \
	$(SDK_ROOT)/components/ble/ble_services/ble_lls \
	$(SDK_ROOT)/components/ble/ble_services/ble_bas \
	$(SDK_ROOT)/components/ble/ble_services/ble_ans_c \
	$(SDK_ROOT)/components/ble/ble_services/ble_nus_c \
	$(SDK_ROOT)/components/nfc/ndef/conn_hand_parser/ble_oob_advdata_parser \
	$(SDK_ROOT)/components/ble/ble_services/ble_lbs \
  $(SDK_ROOT)/components/ble/ble_services/ble_hts \
  $(SDK_ROOT)/components/ble/ble_services/ble_ias \
	$(SDK_ROOT)/components/ble/ble_services/ble_cts_c \
  $(SDK_ROOT)/components/ble/ble_services/ble_nus \
  $(SDK_ROOT)/components/ble/ble_services/ble_hids \
	$(SDK_ROOT)/components/ble/peer_manager \
	$(SDK_ROOT)/components/ble/ble_services/ble_tps \
	$(SDK_ROOT)/components/ble/ble_services/ble_dis \
	$(SDK_ROOT)/components/ble/nrf_ble_gatt \
  $(SDK_ROOT)/components/ble/nrf_ble_qwr \
	$(SDK_ROOT)/components/ble/ble_services/ble_lbs_c \
	$(SDK_ROOT)/components/ble/ble_racp \
	$(SDK_ROOT)/components/ble/ble_services/ble_hrs \
  $(SDK_ROOT)/components/ble/ble_services/ble_rscs \
	$(SDK_ROOT)/components/ble/peer_manager \
	$(SDK_ROOT)/components/ble/ble_advertising \
  $(SDK_ROOT)/components/ant/ant_state_indicator \
  $(SDK_ROOT)/components/ant/ant_key_manager \
  $(SDK_ROOT)/components/ant/ant_search_config \
  $(SDK_ROOT)/components/ant/ant_channel_config \
  $(SDK_ROOT)/components/ant/ant_profiles/ant_common/ant_request_controller \
  $(SDK_ROOT)/components/ant/ant_profiles/ant_common/pages \
	$(PROJ_DIR)/include \
  $(PROJ_DIR)/antplus_lev \
  $(PROJ_DIR)/antplus_lev/pages \
  $(PROJ_DIR)/antplus_controls \
  $(PROJ_DIR)/antplus_controls/pages \
	$(PROJ_DIR)/ssd1306_driver \
  $(PROJ_DIR)/can \

# Libraries common to all targets
LIB_FILES += \

# Optimization flags
OPT = -O0 -g3
# Uncomment the line below to enable link time optimization
#OPT += -flto

# C flags common to all targets
CFLAGS += $(OPT)
CFLAGS += -DAPP_TIMER_V2
CFLAGS += -DAPP_TIMER_V2_RTC1_ENABLED
CFLAGS += -DBOARD_PCA10059
CFLAGS += -DFLOAT_ABI_HARD
CFLAGS += -DNRF52840_XXAA
CFLAGS += -DNRF_SD_BLE_API_VERSION=6
CFLAGS += -DS340
CFLAGS += -DSOFTDEVICE_PRESENT
CFLAGS += -mcpu=cortex-m4
CFLAGS += -mthumb -mabi=aapcs
#CFLAGS += -Wall -Werror
CFLAGS += -Wall
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# keep every function in a separate section, this allows linker to discard unused ones
CFLAGS += -ffunction-sections -fdata-sections -fno-strict-aliasing
CFLAGS += -fno-builtin -fshort-enums
CFLAGS += -DMOTOR_FIRMWARE_MAJOR=\"$(MOTOR_FIRMWARE_MAJOR)\"
CFLAGS += -DMOTOR_FIRMWARE_MINOR=\"$(MOTOR_FIRMWARE_MINOR)\"



# C++ flags common to all targets
CXXFLAGS += $(OPT)
# Assembler flags common to all targets
ASMFLAGS += -g3
ASMFLAGS += -mcpu=cortex-m4
ASMFLAGS += -mthumb -mabi=aapcs
ASMFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
ASMFLAGS += -DAPP_TIMER_V2
ASMFLAGS += -DAPP_TIMER_V2_RTC1_ENABLED
ASMFLAGS += -DBOARD_PCA10059
ASMFLAGS += -DFLOAT_ABI_HARD
ASMFLAGS += -DNRF52840_XXAA
ASMFLAGS += -DNRF_SD_BLE_API_VERSION=6
ASMFLAGS += -DS340
ASMFLAGS += -DSOFTDEVICE_PRESENT


# Linker flags
LDFLAGS += $(OPT)
LDFLAGS += -mthumb -mabi=aapcs -L$(SDK_ROOT)/modules/nrfx/mdk -T$(LINKER_SCRIPT)
LDFLAGS += -mcpu=cortex-m4
LDFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# let linker dump unused sections
LDFLAGS += -Wl,--gc-sections
# use newlib in nano version
LDFLAGS += --specs=nano.specs

display_firmware: CFLAGS += -D__HEAP_SIZE=8192
display_firmware: CFLAGS += -D__STACK_SIZE=8192
display_firmware: ASMFLAGS += -D__HEAP_SIZE=8192
display_firmware: ASMFLAGS += -D__STACK_SIZE=8192

# Add standard libraries at the very end of the linker input, after all objects
# that may need symbols provided by these libraries.
LIB_FILES += -lc -lnosys -lm


.PHONY: default help

# Default target - first one defined
default: display_firmware TSDZ2_bootloader bl_settings final OTA
#default: display_firmware

for_development_only: display_firmware bl_settings final


TSDZ2_bootloader:
	cd $(BOOTLOADER_DIR) && make -f ./Makefile

# We use srec_cat here but if you want to be able to use the combined hex file with nRF Connect you should use Nordic's mergehex tool
final:
	srec_cat $(OUTPUT_DIRECTORY)/display_firmware.hex -intel $(OUTPUT_DIRECTORY)/bl_settings.hex -intel $(BOOTLOADER_HEX) -intel -o $(OUTPUT_DIRECTORY)/display_firmware_combined.hex -intel -address-length=4

bl_settings:
	$(SREC_PATH)nrfutil settings generate --family NRF52840 --application $(OUTPUT_DIRECTORY)/display_firmware.hex --application-version-string $(APP_VER_MAJOR).$(APP_VER_MINOR).0 --bootloader-version 1 --bl-settings-version 2 $(OUTPUT_DIRECTORY)/bl_settings.hex

OTA:
	$(SREC_PATH)nrfutil pkg generate --hw-version 52 --sd-req 0xB9 --application-version-string $(APP_VER_MAJOR).$(APP_VER_MINOR).0 --application $(OUTPUT_DIRECTORY)/display_firmware.hex --key-file private.key --app-boot-validation VALIDATE_ECDSA_P256_SHA256 $(OUTPUT_DIRECTORY)/firmware_ota-$(MOTOR)-$(DISPLAY)-$(VERSION_STRING).zip


TEMPLATE_PATH := $(SDK_ROOT)/components/toolchain/gcc

include $(TEMPLATE_PATH)/Makefile.common

$(foreach target, $(TARGETS), $(call define_target, $(target)))

.PHONY: flash erase

# Flash the program
flash: default
	@echo Flashing: $(OUTPUT_DIRECTORY)/display_firmware.hex
	nrfjprog -f nrf52 --program $(OUTPUT_DIRECTORY)/display_firmware.hex --sectorerase
	nrfjprog -f nrf52 --reset

erase:
	nrfjprog -f nrf52 --eraseall

SDK_CONFIG_FILE := $(PROJ_DIR)/include/sdk_config.h
CMSIS_CONFIG_TOOL := $(SDK_ROOT)/external_tools/cmsisconfig/CMSIS_Configuration_Wizard.jar
sdk_config:
	java -jar $(CMSIS_CONFIG_TOOL) $(SDK_CONFIG_FILE)
