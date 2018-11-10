#ifndef STD_TYPES_H
#define STD_TYPES_H


/**
 * \defgroup SoftwareArchitecture
*/
/**
 * \ingroup SoftwareArchitecture
 * \defgroup General
*/

/** \file std_types.h
 * xxxx
 * \par Autosar standard
 * SWS_Std_00014
*/


/*---------------------------------------------------- Headers --------------------------------------------------*/
/* Include standard headers */
#include "Compiler.h"
#include "Platform_Types.h"

/* Include common headers */
#include "modules.h"

/*---------------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------- Constants -------------------------------------------------*/

/*! 
 * \ingroup General
 * \defgroup Std_ReturnTypes
 *  This is the first group
 * \sa Std_ReturnType
 * \par Autosar standard
 * SWS_Std_00006 (SRS_BSW_00357)
 *  @{
 */
#define E_OK							0x00
#define E_NOT_OK						0x01
/** @} */ // end of Std_ReturnTypes


/*! 
 * \ingroup General
 *  This is the first group
 * \sa Std_ReturnType
 * \par Autosar standard
 * SWS_Std_00007
 *  @{
 */
#define STD_HIGH						0x01 /*!< Physical state 5V or 3.3V */
#define STD_LOW							0x00 /*!< Physical state 0V */
/** @} */

#define STD_ACTIVE						0x01 /*!< Logical state active */
#define STD_IDLE						0x00 /*!< Logical state idle */


#define STD_ON							0x01
#define STD_OFF							0x00


/*!
 * \ingroup General 
 * \defgroup Std_InitStates
 *  This is the first group
 * \par Autosar standard
 * Deviations : Set of macro is not defined by Autosar standard
 *  @{
 */
#define STD_INIT_STATE_UNINIT			0x00
#define STD_INIT_STATE_INIT				0x01
#define STD_INIT_STATE_PREINIT			0x02


/** @} */ // end of Std_InitStates

/*---------------------------------------------------------------------------------------------------------------*/


/*----------------------------------------------------- Types ---------------------------------------------------*/


/*! 
 * \ingroup General
 *  This is the first group
 * \par Autosar standard
 * SWS_Std_00005, SWS_Std_00011

 */
typedef uint8 Std_ReturnType;


/*! 
 * \ingroup General
 *  This is the first group
 * \par Autosar standard
 * SWS_Std_00015 (SRS_BSW_00004)
 */
typedef struct
{
	uint16	vendorID;
	uint16	moduleID;
	uint8	sw_major_version;
	uint8	sw_minor_version;
	uint8	sw_patch_version;
} Std_VersionInfoType;

/*---------------------------------------------------------------------------------------------------------------*/
#endif /*STD_TYPES_H*/
