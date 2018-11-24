#ifndef LCP_H
#define LCP_H

/*---------------------------------------------------- Headers --------------------------------------------------*/

/* Include standard headers */
#include "Std_Types.h"						/*standard type definition*/

/* Include of configuration specific headers */
#include "Lcp_Cfg.h"
/*---------------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------- CONSTANTS -------------------------------------------------*/


/*!
 * \ingroup LCP 
 *  This is the first group
 * \par Autosar standard
 * 
 */
#define	LCP_MODULE_ID					MODULE_ID_CPLX

/*!
 * \ingroup LCP 
 *  This is the first group
 * \par Autosar standard
 * 
 */
#define LCP_VENDOR_ID					0x0//TODO : A coder


/*!
 * \ingroup LCP 
 *  This is the first group
 * \par Autosar standard
 * 
 */
#define LCP_SW_MAJOR_VERSION 				1
#define LCP_SW_MINOR_VERSION 				0
#define LCP_SW_PATCH_VERSION				0

#define LCP_AR_RELEASE_MAJOR_VERSION		4
#define LCP_AR_RELEASE_MINOR_VERSION		2
#define LCP_AR_RELEASE_REVISION_VERSION		1



/*! 
 * \ingroup Lcp
 * \defgroup Lcp_DevelopmentErrors
 *  This is the first group
 * \sa Det
 *  @{
 */
#define	LCP_E_UNINIT						0x20 /*!< API function called before the module has been full initialized or after the module has been shut down */

/** @} */ // end of Lcp_DevelopmentErrors

/*! 
 * \ingroup Lcp
 * \defgroup Lcp_Apis
 *  This is the first group
 * \sa Det
 *  @{
 */
#define LCP_INIT_ID							0x00
#define LCP_DEINIT_ID						0x01
#define LCP_GETVERSIONINFO_ID				0x02
#define LCP_GETSIGNALSTRENGTH_ID			0x03
/** @} */ // end of Lcp_Apis

/*---------------------------------------------------------------------------------------------------------------*/


/*
 ***************************************************************************************************
 * Types
 ***************************************************************************************************
*/
/*!
 * \ingroup Lcp 
 * \enum Lcp_TransactionStatusType
 * \brief ???
 *
 * \par Autosar standard
 * 
 */
typedef enum 
{
	LCP_TRANSACTION_UNINIT,
	LCP_TRANSACTION_INIT,
	LCP_TRANSACTION_CONNECTED,
	LCP_TRANSACTION_STREAM,
	
} Lcp_TransactionStatusType;

typedef enum
{
	LCP_MESSAGE_BEGIN_INQUIRY = 0,
	LCP_MESSAGE_CANCEL_INQUIRY = 1,
	LCP_MESSAGE_CONNECT = 2,
	LCP_MESSAGE_OPEN_PORT = 3,
	LCP_MESSAGE_LOOKUP_NAME = 4,
	LCP_MESSAGE_ADD_DEVICE = 5,
	LCP_MESSAGE_REMOVE_DEVICE = 6,
	LCP_MESSAGE_DUMP_LIST = 7,
	LCP_MESSAGE_CLOSE_CONNECTION = 8,
	LCP_MESSAGE_ACCEPT_CONNECTION = 9,
	LCP_MESSAGE_PIN_CODE = 10,
	LCP_MESSAGE_OPEN_STREAM = 11,
	LCP_MESSAGE_START_HEART = 12,
	LCP_MESSAGE_HEARTBEAT = 13,
	LCP_MESSAGE_INQUIRY_RUNNING = 14,
	LCP_MESSAGE_INQUIRY_RESULT = 15,
	LCP_MESSAGE_INQUIRY_STOPPED = 16,
	LCP_MESSAGE_LOOKUP_NAME_RESULT = 17,
	LCP_MESSAGE_LOOKUP_NAME_FAILURE = 18,
	LCP_MESSAGE_CONNECT_RESULT = 19,
	LCP_MESSAGE_RESET_INDICATION = 20,
	LCP_MESSAGE_REQUEST_PIN_CODE = 21,
	LCP_MESSAGE_REQUEST_CONNECTION = 22,
	LCP_MESSAGE_LIST_RESULT = 23,
	LCP_MESSAGE_LIST_ITEM = 24,
	LCP_MESSAGE_LIST_DUMP_STOPPED = 25,
	LCP_MESSAGE_CLOSE_CONNECTION_RESULT = 26,
	LCP_MESSAGE_PORT_OPEN_RESULT = 27,
	LCP_MESSAGE_SET_DISCOVERABLE = 28,
	LCP_MESSAGE_CLOSE_PORT = 29,
	LCP_MESSAGE_CLOSE_PORT_RESULT = 30,
	LCP_MESSAGE_PIN_CODE_ACK = 31,
	LCP_MESSAGE_DISCOVERABLE_ACK = 32,
	LCP_MESSAGE_SET_FRIENDLY_NAME = 33,
	LCP_MESSAGE_SET_FRIENDLY_NAME_ACK = 34,
	LCP_MESSAGE_GET_LINK_QUALITY = 35,
	LCP_MESSAGE_LINK_QUALITY_RESULT = 36,
	LCP_MESSAGE_SET_FACTORY_SETTINGS = 37,
	LCP_MESSAGE_SET_FACTORY_SETTINGS_ACK = 38,
	LCP_MESSAGE_GET_LOCAL_ADDR = 39,
	LCP_MESSAGE_GET_LOCAL_ADDR_RESULT = 40,
	LCP_MESSAGE_GET_FRIENDLY_NAME = 41,
	LCP_MESSAGE_GET_DISCOVERABLE = 42,
	LCP_MESSAGE_GET_PORT_OPEN = 43,
	LCP_MESSAGE_GET_FRIENDLY_NAME_RESULT = 44,
	LCP_MESSAGE_GET_DISCOVERABLE_RESULT = 45,
	LCP_MESSAGE_GET_PORT_OPEN_RESULT = 46,
	LCP_MESSAGE_GET_VERSION = 47,
	LCP_MESSAGE_GET_VERSION_RESULT = 48,
	LCP_MESSAGE_GET_BRICK_STATUSBYTE_RESULT = 49,
	LCP_MESSAGE_SET_BRICK_STATUSBYTE_RESULT = 50,
	LCP_MESSAGE_GET_BRICK_STATUSBYTE = 51,
	LCP_MESSAGE_SET_BRICK_STATUSBYTE = 52,
	LCP_MESSAGE_GET_OPERATING_MODE = 53,
	LCP_MESSAGE_SET_OPERATING_MODE = 54,
	LCP_MESSAGE_SET_OPERATING_MODE_RESULT = 55,
	LCP_MESSAGE_GET_CONNECTION_STATUS = 56,
	LCP_MESSAGE_CONNECTION_STATUS_RESULT = 57,
	LCP_MESSAGE_GOTO_DFUMODE = 58,

} Lcp_MessageType;

/*
 ***************************************************************************************************
 * Prototypes
 ***************************************************************************************************
*/
void Lcp_Init(void);


/*---------------------------------------------------------------------------------------------------------------*/

#endif /*LCP_H*/

