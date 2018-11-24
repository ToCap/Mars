#ifndef AVR_H
#define AVR_H

/**
 * \defgroup Avr
 */
 
/** \file avr.h
 * xxxx
 * \par Autosar standard
 * 
*/
/*---------------------------------------------------- Headers --------------------------------------------------*/
/* Include standard headers */
//

/* Include common headers */
//

/* Includes of specific headers */
//#include "port_dbg.h"

/* Include of configuration specific headers */
#include "Avr_Cfg.h"



/*---------------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------- Constants -------------------------------------------------*/


/*!
 * \ingroup Avr 
 *  This is the first group
 * \par Autosar standard
 * Deviations : Avr module is not a part of Autosar standard but implementation follows however implementation follows Autosar XCP SWS
*/
#define	AVR_MODULE_ID						MODULE_ID_CPLX

/*!
 * \ingroup Avr 
 *  This is the first group
 * \par Autosar standard
 * Deviations : Avr module is not a part of Autosar standard but implementation follows however implementation follows Autosar XCP SWS
*/
#define AVR_VENDOR_ID						0x0//TODO : A coder


/*!
 * \ingroup Avr 
 *  This is the first group
 * \par Autosar standard
 * Deviations : Avr module is not a part of Autosar standard but implementation follows however implementation follows Autosar XCP SWS
*/
#define AVR_SW_MAJOR_VERSION 				1
#define AVR_SW_MINOR_VERSION 				0
#define AVR_SW_PATCH_VERSION				0

#define AVR_AR_RELEASE_MAJOR_VERSION		4
#define AVR_AR_RELEASE_MINOR_VERSION		2
#define AVR_AR_RELEASE_REVISION_VERSION		1

/*! 
 * \ingroup Avr
 * \defgroup Avr_DevelopmentErrors
 *  This is the first group
 * \sa Det
 *  @{
 */
#if (AVR_DEV_ERROR_DETECT == STD_ON)
#define	AVR_E_PARAM_POINTER				0x11 /*!< API function called with a NULL pointer */
#define	AVR_E_PARAM_DATA				0x12 /*!< API function called with wrong parameter value */
#define AVR_E_UNINIT					0x20 /*!< API function called before the Avr driver has been full initialized or after the Avr driver has been shut down */
#endif
/** @} */ // end of PORT_DevelopmentErrors

/*! 
 * \ingroup Avr
 * \defgroup Avr_Apis
 *  This is the first group
 * \sa Det
 *  @{
 */
#define AVR_INIT_ID							0x00

#define AVR_GETBATTERYLEVEL_ID				0x20

#define	AVR_READADC_ID						0x30
#define AVR_SETINPUTPOWER_ID				0x35
/** @} */ // end of Avr_Apis

/*
 ***************************************************************************************************
 * Types
 ***************************************************************************************************
*/

typedef enum
{
	LS_CLOSED = 0,
	LS_INIT1 = 1,
	LS_INIT2 = 2,
	LS_RUNNING = 3,
	LS_RETRY = 4,
	LS_RESET = 5
} Avr_LinkStatusType;

typedef enum
{
	AVR_POWER_OFF = 0,
	AVR_POWER_AAA = 1,
	AVR_POWER_BBB = 2
	
} Avr_PowerTypes;


/*
 ***************************************************************************************************
 * Prototypes
 ***************************************************************************************************
*/
Std_ReturnType Avr_GetBatteryLevel(uint32* BatteryLevel);
Std_ReturnType Avr_ReadADC(uint32 Input, uint32* Value);

void Avr_Init(void);

#endif /*PORT_H*/
