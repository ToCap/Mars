#ifndef EFX_H
#define EFX_H

/*---------------------------------------------------- Headers --------------------------------------------------*/

/* Include standard headers */
#include "Std_Types.h"						/*standard type definition*/

/*---------------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------- CONSTANTS -------------------------------------------------*/


/*!
 * \ingroup Efx 
 *  This is the first group
 * \par Autosar standard
 * 
 */
#define	EFX_MODULE_ID					MODULE_ID_EFX

/*!
 * \ingroup Efx 
 *  This is the first group
 * \par Autosar standard
 * 
 */
#define EFX_VENDOR_ID					0x0//TODO : A coder


/*!
 * \ingroup Efx 
 *  This is the first group
 * \par Autosar standard
 * 
 */
#define EFX_SW_MAJOR_VERSION 			1
#define EFX_SW_MINOR_VERSION 			0
#define EFX_SW_PATCH_VERSION			0

#define EFX_AR_RELEASE_MAJOR_VERSION	4
#define EFX_AR_RELEASE_MINOR_VERSION	2
#define EFX_AR_RELEASE_REVISION_VERSION	1


/*---------------------------------------------------------------------------------------------------------------*/


/*----------------------------------------------------- TYPES ---------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------- PROTOTYPES -------------------------------------------------*/

#if (EFX_VERSION_INFO_API == STD_ON)
void Efx_GetVersionInfo(P2VAR(Std_VersionInfoType) versioninfo);
#endif

/*---------------------------------------------------------------------------------------------------------------*/

#endif /*EFX_H*/
