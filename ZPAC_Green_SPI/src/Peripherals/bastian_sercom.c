//////////////////////////////////////////////////////////////////////////
//			SAM D - Cortex M0+ SERCOM Source Code
//	Author: Andres Vasquez
//	Purpose: THis code is in charge of the necessary transactions that
//				are to take place between any main code and the code
//				necessary to send data through the SERCOM peripherals
//////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "bastian_sercom.h"

void fcnSPIconfiguration (void);
static void spi_master_callback_received(const struct spi_module *const module);
static void spi_master_callback_transmitted(const struct spi_module *const module);
static void spi_master_callback_transceived(const struct spi_module *const module);

////////////////////  BASTIAN SERCOM  ////////////////////////////////////
//		MODULE: Slave Module -> spi_slave
//		module handler for the SPI interaction with RED
struct spi_module spi_master;
struct spi_slave_inst spi_shield;
struct spi_slave_inst spi_CAN_controller;

////////////////////  BASTIAN SERCOM  ////////////////////////////////////
//		Perform complete SERCOM module setup for the application
//		Takes no arguments
void bastian_complete_sercom_setup(void) {
	// Configure the SPI
	fcnSPIconfiguration();
	
}

void fcnSPIconfiguration (void) {
	//////////////////////////////////////////////////////////////////////////
	// "SHIELD" communication module Setup for Red
	// Declare our configuration parameters
	struct spi_config spi_conf;
	struct spi_slave_inst_config spi_shield_config;
	struct spi_slave_inst_config spi_CAN_controller_config;

	// Initialize them to default values
	spi_get_config_defaults(&spi_conf);
	spi_slave_inst_get_config_defaults(&spi_shield_config);
	
	// Shield Slave Instance Setup
	spi_shield_config.ss_pin = PIN_PA24;
	spi_attach_slave(&spi_shield, &spi_shield_config);
	
	// CAN-Interface Setting
	spi_CAN_controller_config.ss_pin = PIN_PA15;
	spi_attach_slave(&spi_CAN_controller, &spi_CAN_controller_config);
	
	spi_conf.mode_specific.master.baudrate = 10000000;
	spi_conf.transfer_mode = SPI_TRANSFER_MODE_0;
	
	spi_conf.mux_setting = SPI_SIGNAL_MUX_SETTING_E;
	// Pad Configuration
	spi_conf.pinmux_pad0 = PINMUX_PA14C_SERCOM0_PAD0;
	spi_conf.pinmux_pad1 = PINMUX_UNUSED;
	spi_conf.pinmux_pad2 = PINMUX_PA04C_SERCOM0_PAD2;
	spi_conf.pinmux_pad3 = PINMUX_PA05C_SERCOM0_PAD3;

	

	// Initialize the previous settings
	spi_init(&spi_master, SERCOM0, &spi_conf);

	// Enable the module
	spi_enable(&spi_master);

	// ******** Callback setup
	spi_register_callback(&spi_master, spi_master_callback_received, SPI_CALLBACK_BUFFER_RECEIVED);
	spi_enable_callback(&spi_master, SPI_CALLBACK_BUFFER_RECEIVED);
	
	spi_register_callback(&spi_master, spi_master_callback_transmitted, SPI_CALLBACK_BUFFER_TRANSMITTED);
	spi_enable_callback(&spi_master, SPI_CALLBACK_BUFFER_TRANSMITTED);
	
	spi_register_callback(&spi_master, spi_master_callback_transceived, SPI_CALLBACK_BUFFER_TRANSCEIVED);
	spi_enable_callback(&spi_master, SPI_CALLBACK_BUFFER_TRANSCEIVED);
}




//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
////////////////////// SPI CALLBACK FUNCTIONS ////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// SPI RX Callback Function
static void spi_master_callback_received(const struct spi_module *const module) {
	
}

static void spi_master_callback_transmitted(const struct spi_module *const module) {
	spi_read_buffer_job(&spi_master, rd_buffer, SYSTEM_SLAVE_TX_SINGLE_BYTE, 0x00);
}

static void spi_master_callback_transceived(const struct spi_module *const module) {
	if ( rd_buffer[0] == 0 ) {
		nop();
	}
	spi_select_slave(&spi_master, &spi_CAN_controller, false);
}