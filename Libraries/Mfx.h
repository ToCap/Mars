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

#ifndef MFX_H
#define MFX_H

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
*/
#include "Std_Types.h"						/*standard type definition*/
#include "Mfx_Cfg.h"						/*module self-configuration*/


/*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
*/
/*!
 * \ingroup Mfx 
 *  This is the first group
 * \par Autosar standard
 * 
 */
#define	MFX_MODULE_ID					MODULE_ID_MFX

/*!
 * \ingroup Mfx 
 *  This is the first group
 * \par Autosar standard
 * 
 */
#define MFX_VENDOR_ID					0x0


/*!
 * \ingroup Mfx 
 *  This is the first group
 * \par Autosar standard
 * 
 */
#define MFX_SW_MAJOR_VERSION 				1
#define MFX_SW_MINOR_VERSION 				0
#define MFX_SW_PATCH_VERSION				0

#define MFX_AR_RELEASE_MAJOR_VERSION		4
#define MFX_AR_RELEASE_MINOR_VERSION		2
#define MFX_AR_RELEASE_REVISION_VERSION		1


/*
 ***************************************************************************************************
 * Prototypes
 ***************************************************************************************************
*/
#if (MFX_VERSION_INFO_API == STD_ON)
void Mfx_GetVersionInfo(P2VAR(Std_VersionInfoType) versioninfo);
#endif

uint8 Mfx_Min_u8(uint8 x_value, uint8 y_value);
uint16 Mfx_Min_u16(uint16 x_value, uint16 y_value);
uint32 Mfx_Min_u32(uint32 x_value, uint32 y_value);

uint8 Mfx_Add_u8u8_u8(uint8 x_value, uint8 y_value);

uint32 Mfx_AbsDiff_u32u32_u32(uint32 x_value, uint32 y_value);

uint8 Mfx_Div_u32u32_u8(uint32 x_value, uint32 y_value);
uint32 Mfx_Div_u32u32_u32(uint32 x_value, uint32 y_value);
sint32 Mfx_Div_s32u32_s32(sint32 x_value, uint32 y_value);

uint8 Mfx_Limit_u8(uint8 Value, uint8 Min, uint8 Max);
uint8 Mfx_Mod_u8(uint8 x_value, uint8 y_value);
uint8 Mfx_Sub_u8u8_u8(uint8 x_value, uint8 y_value);

#endif /*MFX_H*/
