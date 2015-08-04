//////////////////////////////////////////////////////////////////////////
//		Bastian CAN: Header/Library and definitions
//	This file contains the basic address definitions for the MCP2515 
//		CAN controller module. This file also contains access to internal 
//		variables. 
//////////////////////////////////////////////////////////////////////////

#ifndef BASTIAN_CAN_H_
#define BASTIAN_CAN_H_

// ############################################
// ####### CAN Interface Controller Registers
		// Main Control Registers
#define CAN_CANCTRL		( ( uint8_t ) 0x0F )	// CANCTRL - CAN Control Register
#define CAN_CANSTAT		( ( uint8_t ) 0x0E )	// CANSTAT - CAN Status Register

		// Bit Timing Registers
#define CAN_CNF_1		( ( uint8_t ) 0x2A )	// CANSTAT - CAN Configuration 1
#define CAN_CNF_2		( ( uint8_t ) 0x29 )	// CANSTAT - CAN Configuration 2
#define CAN_CNF_3		( ( uint8_t ) 0x28 )	// CANSTAT - CAN Configuration 3
		
		// Communication Control Registers
#define CAN_TXB_0_CTRL	( ( uint8_t ) 0x30 )	// Transmit Buffer 0 Control Register
#define CAN_TXB_1_CTRL	( ( uint8_t ) 0x30 )	// Transmit Buffer 1 Control Register
#define CAN_TXB_2_CTRL	( ( uint8_t ) 0x30 )	// Transmit Buffer 2 Control Register

#define TXRTSCTRL		( ( uint8_t ) 0x0D )	// TXnRTS Pin Control and Status Register

#define CAN_TXB_0_SIDH	( ( uint8_t ) 0x31 )	// Transmit Buffer 0 Standard Identifier High
#define CAN_TXB_1_SIDH	( ( uint8_t ) 0x41 )	// Transmit Buffer 1 Standard Identifier High
#define CAN_TXB_2_SIDH	( ( uint8_t ) 0x51 )	// Transmit Buffer 2 Standard Identifier High
#define CAN_TXB_0_SIDL	( ( uint8_t ) 0x32 )	// Transmit Buffer 0 Standard Identifier Low
#define CAN_TXB_1_SIDL	( ( uint8_t ) 0x42 )	// Transmit Buffer 1 Standard Identifier Low
#define CAN_TXB_2_SIDL	( ( uint8_t ) 0x52 )	// Transmit Buffer 2 Standard Identifier Low

#define CAN_TXB_0_EID8	( ( uint8_t ) 0x33 )	// Transmit Buffer 0 Extended Identifier High
#define CAN_TXB_1_EID8	( ( uint8_t ) 0x43 )	// Transmit Buffer 1 Extended Identifier High
#define CAN_TXB_2_EID8	( ( uint8_t ) 0x53 )	// Transmit Buffer 2 Extended Identifier High
#define CAN_TXB_0_EID0	( ( uint8_t ) 0x34 )	// Transmit Buffer 0 Extended Identifier Low
#define CAN_TXB_1_EID0	( ( uint8_t ) 0x44 )	// Transmit Buffer 1 Extended Identifier Low
#define CAN_TXB_2_EID0	( ( uint8_t ) 0x54 )	// Transmit Buffer 2 Extended Identifier Low

#define CAN_TXB_0_DLC	( ( uint8_t ) 0x35 )	// Transmit Buffer 0 Data Length Code
#define CAN_TXB_1_DLC	( ( uint8_t ) 0x45 )	// Transmit Buffer 1 Data Length Code
#define CAN_TXB_2_DLC	( ( uint8_t ) 0x55 )	// Transmit Buffer 2 Data Length Code

#define CAN_TXB_0_D_0	( ( uint8_t ) 0x36 )	// Transmit Buffer 0: Data Byte 0
#define CAN_TXB_0_D_1	( ( uint8_t ) 0x37 )	// Transmit Buffer 0: Data Byte 1
#define CAN_TXB_0_D_2	( ( uint8_t ) 0x38 )	// Transmit Buffer 0: Data Byte 2
#define CAN_TXB_0_D_3	( ( uint8_t ) 0x39 )	// Transmit Buffer 0: Data Byte 3
#define CAN_TXB_0_D_4	( ( uint8_t ) 0x3A )	// Transmit Buffer 0: Data Byte 4
#define CAN_TXB_0_D_5	( ( uint8_t ) 0x3B )	// Transmit Buffer 0: Data Byte 5
#define CAN_TXB_0_D_6	( ( uint8_t ) 0x3C )	// Transmit Buffer 0: Data Byte 6
#define CAN_TXB_0_D_7	( ( uint8_t ) 0x3D )	// Transmit Buffer 0: Data Byte 7

#define CAN_TXB_1_D_0	( ( uint8_t ) 0x46 )	// Transmit Buffer 1: Data Byte 0
#define CAN_TXB_1_D_1	( ( uint8_t ) 0x47 )	// Transmit Buffer 1: Data Byte 1
#define CAN_TXB_1_D_2	( ( uint8_t ) 0x48 )	// Transmit Buffer 1: Data Byte 2
#define CAN_TXB_1_D_3	( ( uint8_t ) 0x49 )	// Transmit Buffer 1: Data Byte 3
#define CAN_TXB_1_D_4	( ( uint8_t ) 0x4A )	// Transmit Buffer 1: Data Byte 4
#define CAN_TXB_1_D_5	( ( uint8_t ) 0x4B )	// Transmit Buffer 1: Data Byte 5
#define CAN_TXB_1_D_6	( ( uint8_t ) 0x4C )	// Transmit Buffer 1: Data Byte 6
#define CAN_TXB_1_D_7	( ( uint8_t ) 0x4D )	// Transmit Buffer 1: Data Byte 7

#define CAN_TXB_2_D_0	( ( uint8_t ) 0x56 )	// Transmit Buffer 2: Data Byte 0
#define CAN_TXB_2_D_1	( ( uint8_t ) 0x57 )	// Transmit Buffer 2: Data Byte 1
#define CAN_TXB_2_D_2	( ( uint8_t ) 0x58 )	// Transmit Buffer 2: Data Byte 2
#define CAN_TXB_2_D_3	( ( uint8_t ) 0x59 )	// Transmit Buffer 2: Data Byte 3
#define CAN_TXB_2_D_4	( ( uint8_t ) 0x5A )	// Transmit Buffer 2: Data Byte 4
#define CAN_TXB_2_D_5	( ( uint8_t ) 0x5B )	// Transmit Buffer 2: Data Byte 5
#define CAN_TXB_2_D_6	( ( uint8_t ) 0x5C )	// Transmit Buffer 2: Data Byte 6
#define CAN_TXB_2_D_7	( ( uint8_t ) 0x5D )	// Transmit Buffer 2: Data Byte 7

// For message reception
#define CAN_RXB_0_CTRL	( ( uint8_t ) 0x60 )	// Receive Buffer 0 Control
#define CAN_RXB_1_CTRL	( ( uint8_t ) 0x70 )	// Receive Buffer 1 Control

#define CAN_BFPCTRL		( ( uint8_t ) 0x0C)		// RxnBF Pin Control and Status

#define CAN_RXB_0_SIDH	( ( uint8_t ) 0x61 )	// Receive Buffer 0 Standard Identifier High
#define CAN_RXB_1_SIDH	( ( uint8_t ) 0x71 )	// Receive Buffer 1 Standard Identifier High
#define CAN_RXB_0_SIDL	( ( uint8_t ) 0x62 )	// Receive Buffer 0 Standard Identifier Low
#define CAN_RXB_1_SIDL	( ( uint8_t ) 0x72 )	// Receive Buffer 1 Standard Identifier Low

#define CAN_RXB_0_EID8	( ( uint8_t ) 0x63 )	// Receive Buffer 0 Extended Identifier High
#define CAN_RXB_1_EID8	( ( uint8_t ) 0x73 )	// Receive Buffer 1 Extended Identifier High
#define CAN_RXB_0_EID0	( ( uint8_t ) 0x64 )	// Receive Buffer 0 Extended Identifier Low
#define CAN_RXB_1_EID0	( ( uint8_t ) 0x74 )	// Receive Buffer 1 Extended Identifier Low

#define CAN_RXB_0_DLC	( ( uint8_t ) 0x65 )	// Receive Buffer 0 Data Length Code
#define CAN_RXB_1_DLC	( ( uint8_t ) 0x75 )	// Receive Buffer 1 Data Length Code

#define CAN_RXB_0_D_0	( ( uint8_t ) 0x66 )	// Receive Buffer 0: Byte # 0
#define CAN_RXB_0_D_1	( ( uint8_t ) 0x67 )	// Receive Buffer 0: Byte # 1
#define CAN_RXB_0_D_2	( ( uint8_t ) 0x68 )	// Receive Buffer 0: Byte # 2
#define CAN_RXB_0_D_3	( ( uint8_t ) 0x69 )	// Receive Buffer 0: Byte # 3
#define CAN_RXB_0_D_4	( ( uint8_t ) 0x6A )	// Receive Buffer 0: Byte # 4
#define CAN_RXB_0_D_5	( ( uint8_t ) 0x6B )	// Receive Buffer 0: Byte # 5
#define CAN_RXB_0_D_6	( ( uint8_t ) 0x6C )	// Receive Buffer 0: Byte # 6
#define CAN_RXB_0_D_7	( ( uint8_t ) 0x6D )	// Receive Buffer 0: Byte # 7

#define CAN_RXB_1_D_0	( ( uint8_t ) 0x76 )	// Receive Buffer 1: Byte # 0
#define CAN_RXB_1_D_1	( ( uint8_t ) 0x77 )	// Receive Buffer 1: Byte # 1
#define CAN_RXB_1_D_2	( ( uint8_t ) 0x78 )	// Receive Buffer 1: Byte # 2
#define CAN_RXB_1_D_3	( ( uint8_t ) 0x79 )	// Receive Buffer 1: Byte # 3
#define CAN_RXB_1_D_4	( ( uint8_t ) 0x7A )	// Receive Buffer 1: Byte # 4
#define CAN_RXB_1_D_5	( ( uint8_t ) 0x7B )	// Receive Buffer 1: Byte # 5
#define CAN_RXB_1_D_6	( ( uint8_t ) 0x7C )	// Receive Buffer 1: Byte # 6
#define CAN_RXB_1_D_7	( ( uint8_t ) 0x7D )	// Receive Buffer 1: Byte # 7

		// Acceptance Filters and Masks
#define CAN_RXF_0_SIDH	( ( uint8_t ) 0x00 )	// Filter 0-5 Standard Identifier High
#define CAN_RXF_1_SIDH	( ( uint8_t ) 0x04 )
#define CAN_RXF_2_SIDH	( ( uint8_t ) 0x08 )
#define CAN_RXF_3_SIDH	( ( uint8_t ) 0x10 )
#define CAN_RXF_4_SIDH	( ( uint8_t ) 0x14 )
#define CAN_RXF_5_SIDH	( ( uint8_t ) 0x18 )

#define CAN_RXF_0_SIDL	( ( uint8_t ) 0x01 )	// Filter 0-5 Standard Identifier Low
#define CAN_RXF_1_SIDL	( ( uint8_t ) 0x05 )
#define CAN_RXF_2_SIDL	( ( uint8_t ) 0x09 )
#define CAN_RXF_3_SIDL	( ( uint8_t ) 0x11 )
#define CAN_RXF_4_SIDL	( ( uint8_t ) 0x15 )
#define CAN_RXF_5_SIDL	( ( uint8_t ) 0x19 )

#define CAN_RXF_0_EID8	( ( uint8_t ) 0x02 )	// Filter 0-5 Extended Identifier High
#define CAN_RXF_1_EID8	( ( uint8_t ) 0x06 )
#define CAN_RXF_2_EID8	( ( uint8_t ) 0x0A )
#define CAN_RXF_3_EID8	( ( uint8_t ) 0x12 )
#define CAN_RXF_4_EID8	( ( uint8_t ) 0x16 )
#define CAN_RXF_5_EID8	( ( uint8_t ) 0x1A )

#define CAN_RXF_0_EID0	( ( uint8_t ) 0x03 )	// Filter 0-5 Extended Identifier Low
#define CAN_RXF_1_EID0	( ( uint8_t ) 0x07 )
#define CAN_RXF_2_EID0	( ( uint8_t ) 0x0B )
#define CAN_RXF_3_EID0	( ( uint8_t ) 0x13 )
#define CAN_RXF_4_EID0	( ( uint8_t ) 0x17 )
#define CAN_RXF_5_EID0	( ( uint8_t ) 0x1B )

#define CAN_RXM_0_SIDH	( ( uint8_t ) 0x20 )	// Mask 0-1 Standard Identifier High
#define CAN_RXM_1_SIDH	( ( uint8_t ) 0x24 )	
#define CAN_RXM_0_SIDL	( ( uint8_t ) 0x21 )	// Mask 0-1 Standard Identifier Low
#define CAN_RXM_1_SIDL	( ( uint8_t ) 0x25 )

#define CAN_RXM_0_EID8	( ( uint8_t ) 0x22 )	// Mask 0-1 Extended Identifier High
#define CAN_RXM_1_EID8	( ( uint8_t ) 0x26 )	
#define CAN_RXM_0_EID0	( ( uint8_t ) 0x23 )	// Mask 0-1 Extended Identifier Low
#define CAN_RXM_1_EID0	( ( uint8_t ) 0x27 )

	// ####### ERROR DETECTION
#define CAN_TEC			( ( uint8_t ) 0x1C )	// Transmit Error Counter
#define CAN_REC			( ( uint8_t ) 0x1D )	// Receive Error Counter
#define CAN_EFLG		( ( uint8_t ) 0x2D )	// Error Flag

	// ####### Interrupt
#define CAN_CANINTE		( ( uint8_t ) 0x2B )	// Interrupt Enable Register
#define CAN_CANINTF		( ( uint8_t ) 0x2C )	// Interrupt Flag Register



#endif /* BASTIAN_CAN_H_ */