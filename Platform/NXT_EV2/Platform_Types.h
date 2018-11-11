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

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/**
 * \defgroup Implementation
*/
/**
 * \ingroup Implementation
 * \defgroup Platform
*/


/*!
 * \ingroup General
 * \file Platform_Types.h
 * xxxx
*/

/*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
*/


/*! 
 * \ingroup Platform 
 * \defgroup CPU_TYPES
 *  This is the first group
 * \sa CPU_TYPE
 * \par Autosar standard
 * SWS_Platform_00064
 *  @{
 */
#define	CPU_TYPE_8        				8
#define CPU_TYPE_16       				16
#define CPU_TYPE_32       				32
/** @} */ // end of CPU_TYPES

/*! 
 * \ingroup Platform 
 * \defgroup CPU_BIT_ORDERS
 *  This is the first group
 * \sa CPU_BIT_ORDER
 * \par Autosar standard
 * SWS_Platform_00038
 *  @{
 */
#define MSB_FIRST         				0
#define LSB_FIRST         				1
/** @} */ // end of CPU_BIT_ORDERS

/*! 
 * \ingroup Platform 
 * \defgroup CPU_BYTE_ORDERS
 *  This is the first group
 * \sa CPU_BYTE_ORDER
 * \par Autosar standard
 * SWS_Platform_00039
 *  @{
 */
#define HIGH_BYTE_FIRST					0
#define LOW_BYTE_FIRST    				1
/** @} */ // end of CPU_BYTE_ORDERS

/*! 
 * \ingroup Platform
 * \def CPU_TYPE
 *  This is the first group
 * \par Autosar standard
 * SWS_Platform_00044, SWS_Platform_00045, SWS_Platform_00064
 */
#define CPU_TYPE						CPU_TYPE_32


/*! 
 * \ingroup Platform
 * \def PLATFORM_TYPE
 *  This is the first group
 * \par Autosar standard
 * Custom
 */
#define PLATFORM_TYPE					PLATFORM_NXT_EV2_VPF

/*! 
 * \ingroup Platform
 * \def CPU_BIT_ORDER
 *  This is the first group
 * \par Autosar standard
 * SWS_Platform_00043, SWS_Platform_00048, SWS_Platform_00049
 */
#define CPU_BIT_ORDER					LSB_FIRST


/*! 
 * \ingroup Platform
 * \def CPU_BYTE_ORDER
 *  This is the first group
 * \par Autosar standard
 * SWS_Platform_00046, SWS_Platform_00050, SWS_Platform_00051
 */
#define CPU_BYTE_ORDER					LOW_BYTE_FIRST


/*! 
 * \ingroup Platform
 * \def CPU_BYTE_ORDER
 *  This is the first group
 * \par Autosar standard
 * SWS_Platform_00056, SWS_Platform_00054, SWS_Platform_00055
 */
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define MAXSINT8						127
#define MINSINT8						-128

#define MAXUINT8						255
#define MINUINT8						0

#define MAXSINT16						32767
#define MINSINT16						-32768

#define MAXUINT16						65535
#define MINUINT16						0

#define MAXSINT32						2147483647
#define MINSINT32						-2147483648

#define MAXUINT32						4294967295
#define MINUINT32						0

/*
 ***************************************************************************************************
 * Types
 ***************************************************************************************************
*/


/*! 
 * \ingroup Platform
 *  This is the first group
 * \par Autosar standard
 * SWS_Platform_00026, SWS_Platform_00027, SWS_Platform_00034
 */
typedef unsigned char	boolean;


/*! 
 * \ingroup Platform
 *  This is the first group
 * \par Autosar standard
 * SWS_Platform_00016 (SRS_BSW_00304)
 */
typedef	char			sint8;


/*! 
 * \ingroup Platform
 *  This is the first group
 * \par Autosar standard
 * SWS_Platform_00023
 */
typedef	char			sint8_least;

/*! 
 * \ingroup Platform
 *  This is the first group
 * \par Autosar standard
 * SWS_Platform_00013 (SRS_BSW_00304)
 */
typedef	unsigned char	uint8;


/*! 
 * \ingroup Platform
 *  This is the first group
 * \par Autosar standard
 * SWS_Platform_00020
 */
typedef	unsigned char	uint8_least;

/*! 
 * \ingroup Platform
 *  This is the first group
 * \par Autosar standard
 * SWS_Platform_00017 (SRS_BSW_00304)
 */
typedef	int				sint16;


/*! 
 * \ingroup Platform
 *  This is the first group
 * \par Autosar standard
 * SWS_Platform_00024
 */
typedef	int				sint16_least;

/*! 
 * \ingroup Platform
 *  This is the first group
 * \par Autosar standard
 * SWS_Platform_00014 (SRS_BSW_00304)
 */
typedef	unsigned int	uint16;


/*! 
 * \ingroup Platform
 *  This is the first group
 * \par Autosar standard
 * SWS_Platform_00021
 */
typedef	unsigned int	uint16_least;

/*! 
 * \ingroup Platform
 *  This is the first group
 * \par Autosar standard
 * SWS_Platform_00018 (SRS_BSW_00304)
 */
typedef	long			sint32;


/*! 
 * \ingroup Platform
 *  This is the first group
 * \par Autosar standard
 * SWS_Platform_00025
 */
typedef	long			sint32_least;

/*! 
 * \ingroup Platform
 *  This is the first group
 * \par Autosar standard
 * SWS_Platform_00015 (SRS_BSW_00304)
 */
typedef	unsigned long	uint32;


/*! 
 * \ingroup Platform
 *  This is the first group
 * \par Autosar standard
 * SWS_Platform_00022
 */
typedef	unsigned long	uint32_least;


#endif /*PLATFORM_TYPES_H*/
