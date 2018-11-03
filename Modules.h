/*
 ***************************************************************************************************
 * MARS - the open source AR platform for Mindstorm https://github.com/ToCap/Mars
 *
 * Copyright (C) 2020  GC-MS Software (ThomTheCat)
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 *  Software distributed under the License is distributed on an "AS IS"
 *  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
 *  License for the specific language governing rights and limitations
 *  under the License.
 ***************************************************************************************************
*/

#ifndef MODULES_H
#define MODULES_H

/*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
*/

#define MODULE_ID_OS				(01) // OS
#define MODULE_ID_ECUM    			(10) // ECU state manager
#define MODULE_ID_FIM     			(11) // Function Inhibition Manager
#define MODULE_ID_WDGM				(13) // Watchdog Manager
#define MODULE_ID_TM				(14) // Time Service
#define MODULE_ID_DET     			(15) // Development Error Tracer

#define MODULE_ID_MEMIF				(22) // Memory Abstraction Interface

#define MODULE_ID_BSWM				(42) // BSW Mode Manager
#define MODULE_ID_WDGIF				(43) // Watchdog Interface

#define MODULE_ID_PDUR				(51) // PDU Router

#define MODULE_ID_DEM				(54) // Diagnostic Event Manager
#define MODULE_ID_DLT				(55) // Diagnostic Log and Trace


#define MODULE_ID_SPI				(83) // SPI Handler Driver
#define MODULE_ID_I2C				(83) // I2C Handler Driver (addition to AR standard)

#define MODULE_ID_FLS				(92) // Flash Driver
#define MODULE_ID_RAMTST			(93) // RAM Test

#define MODULE_ID_GPT				(100) // GPT Driver
#define MODULE_ID_MCU   			(101) // Microcontroller driver
#define MODULE_ID_WDG				(102) // Watchdog Driver
#define MODULE_ID_CORTST			(103) // Core Test

#define MODULE_ID_DIO				(120) // DIO Driver

#define MODULE_ID_PORT   			(124) // Port driver

#define MODULE_ID_SCHM   			(130) // BSW Scheduler Module

#define MODULE_ID_STBM				(160) // Synchronized Time-Base Manager

#define MODULE_ID_MEMMAP			(195) // Memory Mapping 

#define MODULE_ID_STD				(197) // Standard Types
#define MODULE_ID_COMPILER			(198) // Compiler Abstraction
#define MODULE_ID_PLATFORM 			(199) // Platform Types

#define MODULE_ID_BFX				(205) // BFx Library

#define MODULE_ID_EFX				(208) // EFx Library 

#define MODULE_ID_MFX				(218) // MFx Library 

#define MODULE_ID_IOHWAB			(254) // IO HW Abstraction
#define MODULE_ID_CPLX   			(255) // Complex drivers




	

#define CPLX_INSTANCE_ID_BTH		0 // Blutooth driver
#define CPLX_INSTANCE_ID_BTHIF		0 // Blutooth Interface
#define CPLX_INSTANCE_ID_XSP		0 // Xsp layer
#define CPLX_INSTANCE_ID_PWRM		0 // Power Manager
#define CPLX_INSTANCE_ID_CTM		0 // Continuous Track Management
#define CPLX_INSTANCE_ID_BTHSM		0

#define CPLX_INSTANCE_ID_BSWLIB		0//TODO : Mettre la bonne valeur

#endif /*MODULES_H*/
