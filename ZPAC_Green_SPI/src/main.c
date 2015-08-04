#include "main.h"
#include "bastian_sercom.h"

#define FEATURE_SYSTEM_CLOCK_DPLL

//////////////////////////////////////////////////////////////////////////
//	System Mode Variable
volatile uint8_t system_mode = SYSTEM_MODE_START;

void fnc_can_controller_disable(void);

static void tcc_callback_function( struct tcc_module *const module_instance );	// TCC Callback Function
static void tcc_configure_function(void);		// TCC Configuration Function
static void tcc_callback_configuration(void);	// TCC Callback Function

struct tcc_module tcc_instance;

//////////////////////////////////////////////////////////////////////////
//	SPI Transceiving Buffers
volatile uint8_t wr_buffer[SYSTEM_TX_BUFFER_SIZE] = { 0xAA, 0xAB, 0xAC };
volatile uint8_t wr_can_buffer[SYSTEM_TX_BUFFER_SIZE] = { 0xA0, 0x00, 0x00 };
volatile uint8_t wr_can_buffer_startup[SYSTEM_TX_BUFFER_SIZE + 2] = { 0xC0, 0x03, 0x0F, 0x00, 0x00 };
volatile uint8_t probe_buff[2] = {0};
volatile uint8_t rd_buffer[SYSTEM_RX_BUFFER_SIZE] = { 0 };
volatile bool isInTransaction =  false;
volatile bool inProgress = false;
volatile uint8_t intProgressTimer = 0;

int main (void)
{
	system_init();
	
	while ( !system_clock_source_is_ready(SYSTEM_CLOCK_SOURCE_DPLL) ) {
	}
	
	// Disable the pin select for the CAN Controller
	fnc_can_controller_disable();
	
	// Perform the SERCOM configuration for this board
	bastian_complete_sercom_setup();
	
	// TCC Configuration
	tcc_configure_function();		// Counter Configuration
	tcc_callback_configuration();	// Timer Callback Configuration
	
	
	
	
	
	// Select Slave
	spi_select_slave(&spi_master, &spi_shield, false);
	
	// Wait the necessary time for the chip to restart
	inProgress = true;
	intProgressTimer = 100;	// wait for 11ms
	while ( inProgress ) { }
	
	// Read the status from the on-board CAN controller
	spi_select_slave(&spi_master, &spi_CAN_controller, true);
	spi_write_buffer_wait(&spi_master, wr_can_buffer_startup, SYSTEM_SLAVE_TX_SINGLE_BYTE);
	spi_select_slave(&spi_master, &spi_CAN_controller, false);
	
	// Wait the necessary time for the chip to restart
	inProgress = true;
	intProgressTimer = 50;	// wait for 11ms
	while ( inProgress ) { }
	
	spi_select_slave(&spi_master, &spi_CAN_controller, true);
	spi_transceive_buffer_job(&spi_master, &wr_can_buffer_startup[1], rd_buffer, SYSTEM_SLAVE_STATUS_TRANSACTION_LENGTH);
	//spi_select_slave(&spi_master, &spi_CAN_controller, false);
	
// 	inProgress = true;
// 	intProgressTimer = 10;	// wait for 2ms
// 	while ( inProgress ) { }
// 	
// 	spi_select_slave(&spi_master, &spi_CAN_controller, true);
// 	spi_transceive_buffer_job(&spi_master, wr_can_buffer, rd_buffer, SYSTEM_SLAVE_STATUS_TRANSACTION_LENGTH);
	// Main Loop
	while (1) {
		
	}
}

void fnc_can_controller_disable(void) {
			
}

//////////////////////////////////////////////////////////////////////////
//	TCC Callback Function
//		-> This function only toggles the LED when TCC is triggered
static void tcc_callback_function( struct tcc_module *const module_instance ) {
	if ( inProgress ) {
		intProgressTimer--;
		
		if ( intProgressTimer == 0 ) {
			inProgress = false;
			intProgressTimer = 0xFF;
		}
	}
}
//
//	TCC Configuration Function
static void tcc_configure_function(void){
	struct tcc_config config_tcc;	// Configuration structure
	
	tcc_get_config_defaults(&config_tcc, TCC0);	// Initialize with known values
	
	// Custom Counter Configuration
	config_tcc.counter.clock_source = GCLK_GENERATOR_0;
	//config_tcc.counter.clock_prescaler = TCC_CLOCK_PRESCALER_DIV1024;
	config_tcc.counter.clock_prescaler = TCC_CLOCK_PRESCALER_DIV64;
	config_tcc.counter.period = 750UL;
	
	tcc_init(&tcc_instance, TCC0, &config_tcc);	// Commit Counter Configuration
	tcc_enable(&tcc_instance);	// Enable this counter instance
}
//
//	TCC Callback Configuration
static void tcc_callback_configuration(void){
	// Register the address to the function that is to be used when counter overflows
	tcc_register_callback(&tcc_instance, tcc_callback_function, TCC_CALLBACK_OVERFLOW);
	
	// Enable this callback entry
	tcc_enable_callback(&tcc_instance, TCC_CALLBACK_OVERFLOW);
}
