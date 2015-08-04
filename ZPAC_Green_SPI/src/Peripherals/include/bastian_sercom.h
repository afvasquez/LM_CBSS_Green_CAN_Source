/*
 * bastian_sercom.h
 *
 * Created: 7/14/2015 1:04:25 PM
 *  Author: avasquez
 */ 


#ifndef BASTIAN_SERCOM_H_
#define BASTIAN_SERCOM_H_


////////////////////  BASTIAN SERCOM  ////////////////////////////////////
//		Perform complete SERCOM module setup for the application
//		Takes no arguments
void bastian_complete_sercom_setup(void);

////////////////////  BASTIAN SERCOM  ////////////////////////////////////
//		MODULE: Slave Module -> spi_slave
//		module handler for the SPI interaction with RED
extern struct spi_module spi_master;
extern struct spi_slave_inst spi_shield;
extern struct spi_slave_inst spi_CAN_controller;

#endif /* BASTIAN_SERCOM_H_ */