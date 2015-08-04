/*
 * main.h
 *
 * Created: 7/14/2015 1:07:08 PM
 *  Author: avasquez
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#include <asf.h>

#define SYSTEM_MODE_START	( ( uint8_t ) 100 )
#define SYSTEM_MODE_IDLE	( ( uint8_t ) 0 )
// Slave Modes
#define SYSTEM_MODE_DISCOVERY_REQUEST	( ( uint8_t ) 1 )
#define SYSTEM_MODE_DO_JOB				( ( uint8_t ) 2 )
#define SYSTEM_MODE_TX_JOB_CONFIRMATION	( ( uint8_t ) 3 )

#define SYSTEM_MODE_IS_DISCOVERED		( ( uint8_t ) 11 )
#define SYSTEM_MODE_JOB_DONE			( ( uint8_t ) 22 )

#define SYS_SPI_DISCOVERY_TRX_IN_PROGRESS	( ( uint8_t ) 81 )
#define SYS_SPI_DO_JOB_TRX_IN_PROGRESS		( ( uint8_t ) 82 )

#define SYSTEM_MODE_DATA_PROBE			( ( uint8_t ) 91 )

#define SYSTEM_SLAVE_TX_SINGLE_BYTE	1
#define SYSTEM_SLAVE_RX_BYTES_TO_RECEIVE	1
#define SYSTEM_SLAVE_STATUS_TRANSACTION_LENGTH	3

#define SYSTEM_TX_BUFFER_SIZE	3
#define SYSTEM_RX_BUFFER_SIZE	3

#define SPI_MSG_DISCOVERY	( ( uint8_t ) 0xAA )
#define SPI_MSG_JOB_REQUEST	( ( uint8_t ) 0xAB )
#define SPI_MSG_JOB_CONFIRM	( ( uint8_t ) 0xAC )

#define SPI_MSG_DISC_RESPONSE	( ( uint8_t ) 0xBA )
#define SPI_MSG_JOB_COMPLETED	( ( uint8_t ) 0xBB )

extern volatile uint8_t system_mode;
extern volatile uint8_t rd_buffer[SYSTEM_RX_BUFFER_SIZE];
extern volatile uint8_t wr_buffer[SYSTEM_TX_BUFFER_SIZE];

extern volatile bool isInTransaction;


#endif /* MAIN_H_ */