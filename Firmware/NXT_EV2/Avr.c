#ifndef AVR_NXC
#define AVR_NXC
/**
 * \defgroup Avr
*/

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
*/
/* Includes of library headers */
#include "BswLib.h"
#include "BswLib_Prv.h"

/* Include of diagnostic headers */
#include "Det.h"
#include "Dem.h"

/* Includes of specific headers */
#include "Avr.h"						/**/
#include "Avr_MemMap.h"					/**/
#include "SchM_Avr.h"					/**/

/* Includes of Communication headers */
#include "Twi.h"
#include "Twi_Prv.h"

/* Includes of private headers */



/*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
*/
#define AVR_PRV_NUM_BUFFER_MAX				2u

#define NXT_AVR_ADDRESS						1	//TODO : Trouver un meilleur nom
#define AVR_NUM_NXT_OUTPUT_MAX				4
#define AVR_NUM_NXT_INPUT_MAX				4


/*
 ***************************************************************************************************
 * Types
 ***************************************************************************************************
*/
#ifdef ARM_C_GNU
typedef struct
{
  // Raw values
  uint8 power;
  uint8 pwm_frequency;
  sint8 output_percent[AVR_NUM_NXT_OUTPUT_MAX];
  uint8 output_mode;
  uint8 input_power;
} __attribute__((packed)) to_avr;

typedef struct {
  // Raw values
  uint16 adc_value[AVR_NUM_NXT_INPUT_MAX];
  uint16 buttonsVal;
  uint16 extra;
  uint8 csum;
} __attribute__((packed)) from_avr;
#endif

#ifdef ARM_C_WIN
#pragma pack(push,1)
typedef struct
{
  // Raw values
  uint8 power;
  uint8 pwm_frequency;
  sint8 output_percent[AVR_NUM_NXT_OUTPUT_MAX];
  uint8 output_mode;
  uint8 input_power;
} to_avr;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct {
  // Raw values
  uint16 adc_value[AVR_NUM_NXT_INPUT_MAX];
  uint16 buttonsVal;
  uint16 extra;
  uint8 csum;
} from_avr;
#pragma pack(pop)
#endif

/*-------------------------------------------------- Variables --------------------------------------------------*/


/** \var Avr
 *  \brief ???
 */
const char Avr_brainwash_string[] =
  "\xCC" "Let's samba nxt arm in arm, (c)LEGO System A/S";

/** \var Avr_Prv_ctUpd
 *  \brief ???
 */
uint8 Avr_Prv_ctUpd = 0;

/** \var Avr_stInit
 *  \brief ???
 */
uint8 Avr_stInit = STD_INIT_STATE_UNINIT;

static to_avr io_to_avr;

// Output data is double buffered via the following (note extra space for csum
static uint8 data_to_avr[5 + AVR_NUM_NXT_OUTPUT_MAX];

static from_avr data_from_avr[AVR_PRV_NUM_BUFFER_MAX];
static from_avr* io_from_avr; 

static uint32 from_buf;

/** \var Avr_BufIdx
 *  \brief ???
 */
static uint32 Avr_BufIdx;

static Avr_LinkStatusType Avr_stLink;

/*---------------------------------------------------------------------------------------------------------------*/


/*
 ***************************************************************************************************
 * Functions
 ***************************************************************************************************
*/

/*
 ***************************************************************************************************
 * Functions
 ***************************************************************************************************
*/

#define Avr_Prv_GetNextBufIndex(idxBuf)		BswLib_Prv_GetNextBufIndex((idxBuf), (AVR_PRV_NUM_BUFFER_MAX))




void Avr_Prv_DecodeBuf(void)
{
	/* Declaration of local variables */
	uint8* xCurData;
	uint8* xLstData;
	uint8 stChecksum;
	
	/* Initialisation of local variables */
	xCurData = (uint8*)(&data_from_avr[from_buf]);
	xLstData = xCurData + sizeof(from_avr);
	
	/* Compute checksum */
	while(xCurData < (xLstData)) 
	{
		stChecksum += *xCurData++;
	}

	/* Check if checksum is valid */
	if (stChecksum == MAXUINT8)
	{
		/* On checksum is valid, Update IO map from current buffer */
		io_from_avr = &data_from_avr[from_buf];/*copy for quick access*/
		from_buf = Avr_Prv_GetNextBufIndex(from_buf);/*switch to next buffer*/
		
		//TODO : Coder le debounce pour la gestion des boutons
		
	}
	else
	{
		/* On checksum is not valid, Do nothing */
	}
}




/*
 ***************************************************************************************************
 * Services
 ***************************************************************************************************
*/


/**
 * \ingroup Avr
 * \brief Start an asynchronous read operation of data from the AVR
 *
 * commentaire supplementaire
 * \return	void
 * \remarks
 * \see	None
 * \par Autosar standard
 * Not Specified by Autosar Standard
*/
void Avr_AsyncReceive(void)
{
	(void)Twi_AsyncReceive(NXT_AVR_ADDRESS, (uint8*)(&data_from_avr[Avr_BufIdx]), sizeof(from_avr));
}

/**
 * \ingroup Avr
 * \brief Start to asynchronous write operation to the AVR
 *
 * commentaire supplementaire
 * \return	void
 * \remarks
 * \see	None
 * \par Autosar standard
 * Not Specified by Autosar Standard
*/
void Avr_AsyncSend(void)
{ 
	/* Declaration of local variables */
	uint32 stChecksum;
	
	
	uint8 *a = data_to_avr;
	uint8 *b = (uint8 *) (&io_to_avr);
	uint8 *e = b + sizeof(io_to_avr);
	
	/* Initialize local variables */
	stChecksum = 0;
	
	/* Prepare message to send */
	while (b < e) 
	{
		stChecksum += *b;/*compute checksum*/
		*a++ = *b++;/*copy message*/
	}
	
	*a = ~stChecksum;//TODO : A verifier
	
	(void)Twi_AsyncSend(NXT_AVR_ADDRESS, data_to_avr, sizeof(data_to_avr));
}


Std_ReturnType Avr_GetBatteryLevel(uint32* BatteryLevel)
{
	/* Declaration of local variables */
	uint32 uBatInt;
	Std_ReturnType stRetVal;
	
	/* Initialize variables with default value */
	stRetVal = E_OK;
	
	/* Check Avr driver initialisation status */
	if (Avr_stInit == STD_INIT_STATE_INIT)
	{
		/* On Avr driver is fully initialized, Check validity of pointer */
		if (BatteryLevel != NULL_PTR)
		{
			/* Get raw value from AVR internal RAM */
			uBatInt = io_from_avr->extra;
			uBatInt &= 0x3FF;/*remove unwanted bits*/
			
			/* Convert to user friendly resolution */
			uBatInt = (uBatInt * 14180) >> 10;//TODO : Utiliser un service Mfx
			/* HINTS : Resolution from AVR is 13.848 mv per bit 
			therefore computation method is 14180/1024 to avoid using floating-point arithmetic */
			
			*BatteryLevel = uBatInt;
		}
		else
		{
			/*, Return error */
			stRetVal = E_NOT_OK;
			
			/* Trace error in Det if required */
			#if (AVR_DEV_ERROR_DETECT == STD_ON)
			Det_ReportError(AVR_MODULE_ID, 0, AVR_GETBATTERYLEVEL_ID, AVR_E_PARAM_POINTER);
			#endif		
		}
	}
	else
	{
		/* On initialisation is on-going, Return error */
		stRetVal = E_NOT_OK;
		
		/* Trace error in Det if required */
		#if (AVR_DEV_ERROR_DETECT == STD_ON)
		Det_ReportError(AVR_MODULE_ID, 0, AVR_GETBATTERYLEVEL_ID, AVR_E_UNINIT);
		#endif		
	}
	
	return stRetVal;
}


/**
 * \ingroup Avr
 * \brief Initialise the link with the AVR by sending the handshake string
 *
 * Note that
 * because of the length of this string we need to allow more than 1ms for it
 * to go.
 * \return	void
 * \remarks
 * \see	None
 * \par Autosar standard
 * Deviations : Avr module is not a part of Autosar standard however implementation follows Autosar Eth SWS
*/
void Avr_InitializeLink(void)
{
  (void)Twi_AsyncSend(NXT_AVR_ADDRESS, 
					(const uint8*)Avr_brainwash_string,
					(uint16)BswLib_GetStrLength(Avr_brainwash_string));
}


/**
 * \ingroup Avr
 * \brief	Reports a DTR result with lower and upper limi
 *
 * \param	a			Identification of a DTR element by assigned DTRId
 * \param	Value		Test result of DTR
 * \return	Std_ReturnType
 *				E_OK: Report of DTR result successful
 *				E_NOT_OK: Report of DTR result failed
 * \exception
 *			AVR_E_PARAM_DATA : function called with wrong parameter value
 *			AVR_E_UNINIT : function called before the module has been full initialized
 * \par Autosar standard
 * Not specified in Autosar standard
*/
Std_ReturnType Avr_ReadADC(uint32 Input, uint32* Value)
{
	/* Declaration of local variables */
	Std_ReturnType stRetVal;

	/* Initialize variables with default value */
	stRetVal = E_OK;
	
	/* Check Avr driver initialisation status */
	if (Avr_stInit == STD_INIT_STATE_INIT)
	{
		/* On Avr driver is fully initialized, Check if specified aaaa is valid */
		if (Input < (uint32)AVR_NUM_NXT_INPUT_MAX)
		{
			/* On specified aaaa is valid, Read back value */
			*Value = io_from_avr->adc_value[Input];
		}
		else
		{
			/* On specified aaaa is NOT valid, Return error */
			stRetVal = E_NOT_OK;
			
			/* Trace error in Det if required */
			#if (AVR_DEV_ERROR_DETECT == STD_ON)
			Det_ReportError(AVR_MODULE_ID, 0, AVR_READADC_ID, AVR_E_PARAM_DATA);
			#endif	
		}
	}
	else
	{
		/* On initialisation is on-going, Return error */
		stRetVal = E_NOT_OK;
		
		/* Trace error in Det if required */
		#if (AVR_DEV_ERROR_DETECT == STD_ON)
		Det_ReportError(AVR_MODULE_ID, 0, AVR_READADC_ID, AVR_E_UNINIT);
		#endif		
	}
	
	return stRetVal;
}


/**
 * \ingroup Avr
 * \brief	Control the power supplied to an input sensor
 *
 * \param	a			Identification of a DTR element by assigned DTRId
 * \param	Value		Test result of DTR
 * \return	Std_ReturnType
 *				E_OK: Report of DTR result successful
 *				E_NOT_OK: Report of DTR result failed
 * \exception
 *			AVR_E_PARAM_DATA	function called with wrong parameter value
 *			AVR_E_UNINIT		function called before the module has been full initialized
 * \par Autosar standard
 * Not specified in Autosar standard
 * \remarks
 * The power supplied to sensor is controlled by byte status word 
 * divided in two nibbles of four bits : there is one bit for each sensor
 * in both low and high nibble
 * If "low nibble" bit is set then the sensor is "ACTIVE" and 9v is
 * supplied to it but it will be pulsed off to allow
 * the sensor to be be read. 
 * A 1 in the high nibble
 * indicates that it is a 9v always on sensor and
 * 9v will be supplied constantly. If both bits are
 * clear then 9v is not supplied to the sensor. 
 * Having both bits set is currently not supported.
*/
Std_ReturnType Avr_SetInputPower(uint32 Input, Avr_PowerTypes PowerType)
{
	/* Declaration of local variables */
	Std_ReturnType stRetVal;
	uint8	value;

	/* Initialize variables with default value */
	stRetVal = E_OK;
	
	/* Check Avr driver initialisation status */
	if (Avr_stInit == STD_INIT_STATE_INIT)
	{
		/* On Avr driver is fully initialized, Check if specified power inputs are valid */
		if (Input < (uint32)AVR_NUM_NXT_INPUT_MAX && PowerType <= AVR_POWER_BBB)
		{
			/* On inputs are valid, Compute new status */
			value = (PowerType & 0x2 ? 0x10 << Input : 0) | ((PowerType & 1) << Input);
			
			/* Assign computed status */
			io_to_avr.input_power &= ~(0x11 << Input);/*clear bits for specified sensor*/
			io_to_avr.input_power |= value;/*set new status*/
		}
		else
		{
			/* On specified aaaa is NOT valid, Return error */
			stRetVal = E_NOT_OK;
			
			/* Trace error in Det if required */
			#if (AVR_DEV_ERROR_DETECT == STD_ON)
			Det_ReportError(AVR_MODULE_ID, 0, AVR_SETINPUTPOWER_ID, AVR_E_PARAM_DATA);
			#endif	
		}
	}
	else
	{
		/* On initialisation is on-going, Return error */
		stRetVal = E_NOT_OK;
		
		/* Trace error in Det if required */
		#if (AVR_DEV_ERROR_DETECT == STD_ON)
		Det_ReportError(AVR_MODULE_ID, 0, AVR_SETINPUTPOWER_ID, AVR_E_UNINIT);
		#endif		
	}
	
	return stRetVal;
}
/*---------------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------- PROCESSES -------------------------------------------------*/

/**
 * \ingroup Avr
 * \brief Initialize or reinitializes the Avr module
 *
 * commentaire supplementaire
 * \return	void
 * \warning : This process SHALL be scheduled any time after Twi_Init
 * \remarks
 * \see	None
 * \par Autosar standard
 * Not Specified by Autosar Standard
*/
void Avr_Init(void)
{
	/* Check Twi initialisation status */
	if (Twi_GetInitialisationStatus())
	{
		/* Initilize output data to AVR chip */
		BswLib_MemSet(&io_to_avr, 0, sizeof(io_to_avr));
		io_to_avr.power = 0;
		io_to_avr.pwm_frequency = 8;

		/* Initialize input data from AVR chip */
		from_buf = 0;
		io_from_avr = &data_from_avr[1];
		
		/**/
		//button_state = 0;
		//prev_buttons = 0;
		//debounce_state = 0;
		//debounce_cnt = BUTTON_DEBOUNCE_CNT;
		
		//link_state = LS_RESET;
		/* HINTS : Connection with AVR is considered as inative until explicit opening */
	
		/* On Twi is fully initialized, Initialize */
		BswLib_MemSet(&io_to_avr, 0, sizeof(io_to_avr));
		io_to_avr.power = 0;
		io_to_avr.pwm_frequency = 8;	
		
		/* Initialize */
		Avr_BufIdx = 0;
		io_from_avr = &data_from_avr[1];
		
		/* */
		//button_state = 0;
		//prev_buttons = 0;
		//debounce_state = 0;
		//debounce_cnt = BUTTON_DEBOUNCE_CNT;
		
		/* */
		Avr_stLink = LS_RESET;
		
		/* Update initialisation status */
		Avr_stInit = STD_INIT_STATE_INIT;
	}
	else
	{
		/* On Dem initialisation is still on-going, Do nothing */
		#if (AVR_DEV_ERROR_DETECT == STD_ON)
		Det_ReportError(AVR_MODULE_ID, 0, AVR_INIT_ID, TWI_E_UNINIT);
		#endif	
	}
}


void Avr_MainFunction(void)
{
	/* Declaration of local variables */
	Twi_StatusType stTwi;

	switch (Avr_stLink)
	{
		case LS_CLOSED:
		{
		
		}
		break;
		
		case LS_INIT1:
		case LS_INIT2:
		{
			// Add extra wait states during initialisation
			Avr_stLink ++;
		}
		break;
		
		case LS_RUNNING:
		case LS_RETRY:
		{
			/* Switch on Twi driver status */
			stTwi = Twi_GetHWUnitStatus(0);
			if (stTwi == TWI_IDLE)
			{
				/* On Twi driver is idle, Check */
				if (BswLib_Prv_Toggle(Avr_Prv_ctUpd))
				{
					Avr_AsyncReceive();
				}
				else
				{
					/**/
					Avr_AsyncSend();
					Avr_Prv_DecodeBuf();
				}
				
				/* Update Avr link status */
				Avr_stLink = LS_RUNNING;
			}
			else if (stTwi == TWI_BUSY)
			{
				/* On Twi driver is busy, */
				if (Avr_stLink == LS_RUNNING)
				{
					Avr_stLink = LS_RETRY;
				}
				else
				{
					Avr_stLink = LS_RESET;
				} 
			}
			else
			{
				/* On Twi driver is NOT initialized/unknown */
				Avr_stLink = LS_RESET;
			}
		}
		break;
		
		case LS_RESET:
		{
			(void)Twi_ReInit();
			BswLib_MemSet(data_from_avr, 0, sizeof(data_from_avr));
			Avr_InitializeLink();
			Avr_Prv_ctUpd = 0;
			//nxt_avr_stats.resets++;
			Avr_stLink = LS_INIT1;
		}
		break;
		
		default:
		{
			Avr_stLink = LS_RESET;
		}
		break;
	}
}

/*---------------------------------------------------------------------------------------------------------------*/
#endif /*AVR_NXC*/
