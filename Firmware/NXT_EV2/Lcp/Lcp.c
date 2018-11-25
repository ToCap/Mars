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

#ifndef LCP_NXC
#define LCP_NXC


/**
 * \defgroup Lcp
 */


/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
*/
#include "Bfx.h"
#include "Tck.h"
#include "Bth.h"

/* Include of diagnostic headers */
#include "Det.h"						/**/
#include "FiM.h"

/* Includes of specific headers */
#include "Lcp.h"
#include "Lcp_MemMap.h"					/**/
#include "SchM_Lcp.h"					/**/


/*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
*/
/** \def LCP_PRV_MESSAGE_TIMEOUT
 *  \brief ???
 */
#define LCP_PRV_MESSAGE_TIMEOUT  (3000) /* msec */


/*
 ***************************************************************************************************
 * Variables
 ***************************************************************************************************
*/

/** \var Lcp_stInit
 *  \brief ???
 */
uint8 Lcp_stInit = STD_INIT_STATE_UNINIT;

Lcp_TransactionStatusType Lcp_stTransaction;//TODO : Trouver un meilleur nom

uint8 Lcp_xTmpTxBuf[BTH_SIZE_TX_BUFFER];
uint8 Lcp_xTmpRxBuf[BTH_SIZE_RX_BUFFER];

/** \var Lcp_Prv_xHandle
 *  \brief ???
 */
static volatile uint8 Lcp_Prv_xHandle;

/*
 ***************************************************************************************************
 * Functions
 ***************************************************************************************************
*/


/**
 * \ingroup Lcp
 * \brief	Send Lcp command on Bluetooth
 * \param[out] versioninfo Pointer to where to store the version information of this module
 * \return	None
 * \see	None
 * \warning Function is intended to only locally used thus no error detection (DET) is implemented
			therefore caller shall ensure validity of input parameter
 * 
*/
LOCAL_INLINE uint32 Lcp_Prv_SendCommand(uint8* Buffer, uint16 LenByte)
{
	/* Declaration of local variables */
	sint32 checkSum = 0;//TODO : Trouver un meilleur nom
	uint32 stRetVal;	
	uint16 i;//TODO : Trouver un meilleur nom

	
	/* Initialize local variables */
	stRetVal = E_OK;	

	/* Compute checksum */
	for(i = 0; i < LenByte; i ++)
	{
		checkSum += Buffer[i];
	}
	checkSum = -checkSum;
	
	/**/
	Lcp_xTmpTxBuf[0] = (uint8)(LenByte + 2);//sendBuf[0] = (U8) (bufLen + 2);
	BswLib_MemCpy(&Lcp_xTmpTxBuf[1], Buffer, LenByte);
	
	/**/
	Lcp_xTmpTxBuf[LenByte+2] = (uint8)((checkSum >> 8) & 0xff);/*set MSB checksum */
	Lcp_xTmpTxBuf[LenByte+3] = (uint8)(checkSum & 0xff);/*set LSB checksum */

	/* Call interface to low-level driver */
	stRetVal = Bth_write(Lcp_xTmpTxBuf, 0u, (LenByte + 3));
	
	return stRetVal;
}


/**
 * \ingroup Lcp
 * Get the mode of a BT controller
 * 
 * \return	None
 * 
 * \see	None
*/
LOCAL_INLINE void Lcp_Prv_CloseTransaction(void)
{	
	/* Check transaction status */
	if (Lcp_stTransaction == LCP_TRANSACTION_STREAM)
	{
		/* On transaction is on-going, Clear any command on underlying Bth driver */
		Bth_ClearCommand();/* set command mode */
	
		/* Wait for hardware */
		Tck_BusyWait1ms(100u);
	
		/* Update transaction status */
		Lcp_stTransaction = LCP_TRANSACTION_CONNECTED;
	}
	else
	{
		/* On transaction is NOT on-going, Do nothing */
		/* HINTS : There's no pending transaction to close therefore operation would be always successful */
	}
}


LOCAL_INLINE void Lcp_Prv_OpenTransaction(void)
{
	/* Declaration of local variables */
	uint8					xTxBuff[2];

	/* Check transaction status */
	if (Lcp_stTransaction == LCP_TRANSACTION_CONNECTED)
	{
		/**/
		xTxBuff[0] = (uint8)LCP_MESSAGE_OPEN_STREAM;
		xTxBuff[1] = Lcp_Prv_xHandle;
		
		Lcp_Prv_SendCommand(xTxBuff, 2);
	}
	else
	{
	
	}
}


/**
 * \ingroup Lcp
 * \brief	Return the version information of this module
 * \param[out] versioninfo Pointer to where to store the version information of this module
 * \return	None
 * \see	None
 * \warning Function is intended to only locally used thus no error detection (DET) is implemented
			therefore caller shall ensure validity of input parameter
 * \par Autosar standard
 * 
*/
LOCAL_INLINE uint16 Lcp_Prv_GetCommandResponse(uint8* BufPtr, uint16 bufLen)
{
	/* Declaration of local variables */
	uint32 i;//TODO : Trouver un meilleur nom
	sint32 checkSum, negSum;
	uint16 len;//TODO : Trouver un meilleur nom
	uint16 stRetVal;
	
	/* Initialize local variables */
	stRetVal = E_OK;	

	/* */
	BswLib_MemSet(&Lcp_xTmpRxBuf[0], 0, BTH_SIZE_RX_BUFFER);
	Bth_Receive(&Lcp_xTmpRxBuf[0]);
		
	/* Get length from received buffer */
	len = Lcp_xTmpRxBuf[0];
	
	if (len > (uint16)0)
	{
		checkSum = len;
		for(i = 1; i < len-1; i++) 
		{
			BufPtr[i] = Lcp_xTmpRxBuf[i];
			checkSum += (Lcp_xTmpRxBuf[i] & 0xFF);
			//TODO : Verifier l'utilite du mask sur un u8 :)
		}
		
		negSum = (Lcp_xTmpRxBuf[len-1] & 0xff) << 8;//TODO : utiliser une cste
		negSum += (Lcp_xTmpRxBuf[len] & 0xff);//TODO : utiliser une cste

		if (checkSum + negSum == 65536)//TODO : utiliser une cste
		{
			stRetVal = (len - 1);
			
		}
		else
		{
			stRetVal = 0;
		}
	}
	else
	{
		stRetVal = 0;
	}
	
	return stRetVal;
}

/*
 ***************************************************************************************************
 * Services
 ***************************************************************************************************
*/

/**
 * \ingroup Lcp
 * \brief	Return the version information of this module
 * \param[out] versioninfo Pointer to where to store the version information of this module
 * \return	None
 * \see	None
 * \par Autosar standard
 * 
*/
#if (LCP_VERSION_INFO_API == STD_ON)
void Lcp_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
	/* Copy module information */
	versioninfo->vendorID = LCP_VENDOR_ID;
	versioninfo->moduleID = LCP_MODULE_ID;
	
	/* Copy version information */
	versioninfo->sw_major_version = LCP_SW_MAJOR_VERSION;
	versioninfo->sw_minor_version = LCP_SW_MINOR_VERSION;
	versioninfo->sw_patch_version = LCP_SW_PATCH_VERSION;
}
#endif


/**
 * \ingroup Lcp
 * \brief	Return the version information of this module
 * \param[out] versioninfo Pointer to where to store the version information of this module
 * \return	None
 * \see	None
 * \par Autosar standard
 * 
*/
Std_ReturnType Lcp_GetSignalStrength(sint16* SignalStrength)
{
	/* Declaration of local variables */
	uint32					timeout;//TODO : Trouver un meilleur nom
	uint8					xTxBuff[2];
	uint8					xRxBuff[32];
	Std_ReturnType 			stRetVal;
	
	
	/* Initialize variables with default value */
	stRetVal = E_OK;					/*operation sucessful*/
	
	/* */
	if (Lcp_stTransaction == LCP_TRANSACTION_CONNECTED || Lcp_stTransaction == LCP_TRANSACTION_STREAM)//TODO : A coder
	{
		/* On , Close current transaction */
		Lcp_Prv_CloseTransaction();
		
		/* Build command message */
		xTxBuff[0] = (uint8)LCP_MESSAGE_GET_LINK_QUALITY;
		xTxBuff[1] = Lcp_Prv_xHandle;
		
		/* Send command message */
		Lcp_Prv_SendCommand(xTxBuff, 2);
		
		timeout = Tck_GetCurrentTickCounter() + LCP_PRV_MESSAGE_TIMEOUT;
		while(Tck_GetCurrentTickCounter() < timeout)
		{
			Lcp_Prv_GetCommandResponse(xRxBuff, 32);
			if (xRxBuff[0] != (uint8)0 && xRxBuff[1] == (uint8)LCP_MESSAGE_LINK_QUALITY_RESULT)
			{
				*SignalStrength = (sint16)(xRxBuff[2]);
			}
			else
			{
				/*, Return error */
				stRetVal = E_NOT_OK;
			}
		}
		
		Lcp_Prv_OpenTransaction();
	}
	else
	{
		/* On Dem initialisation is still on-going, Return error */
		stRetVal = E_NOT_OK;
		
		/* Trace error in Det if required */
		#if (LCP_DEV_ERROR_DETECT == STD_ON)
		Det_ReportError(LCP_MODULE_ID, 0, LCP_GETSIGNALSTRENGTH_ID, LCP_E_UNINIT);
		#endif		
	}
	
	return stRetVal;
}



/*
 ***************************************************************************************************
 * Processes
 ***************************************************************************************************
*/


void Lcp_Init(void)
{
	Lcp_stInit = STD_INIT_STATE_INIT;
}



#endif /*LCP_NXC*/
