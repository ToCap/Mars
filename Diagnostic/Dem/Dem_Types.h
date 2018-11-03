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

#ifndef DEM_TYPES_H
#define DEM_TYPES_H


/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
*/
#include "Std_Types.h"						/*standard type definition*/



/*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
*/

/*!
 * \ingroup Dem 
 * \defgroup Dem_DebounceResetStatusTypes
 *  This is the first group
 *  @{
 */
#define DEM_DEBOUNCE_STATUS_FREEZE		0x00	/*!< Freeze the internal debounce counter/timer */
#define DEM_DEBOUNCE_STATUS_RESET		0x01	/*!< Reset the internal debounce counter/timer */
/** @} */ // end of Dem_DebounceResetStatusTypes





#define	DEM_EVENT_AVAILABILITY			0x01/*!< Support availability by Event */
#define	DEM_NO_AVAILABILITY				0x00/*!< Availability is not supported */

/*!
 * \ingroup Dem 
 * \defgroup Dem_OperationCycleStateTypes
 *  This is the first group
 * \par Autosar standard
 * SWS_Dem_00934
 * \sa Dem_OperationCycleStateType
 *  @{
 */
#define DEM_CYCLE_STATE_START				0x00/*!< Start/restart the operation cycle */
#define DEM_CYCLE_STATE_END					0x01/*!< End the operation cycle */
/** @} */ // end of Dem_OperationCycleStateTypes

/*!
 * \ingroup Dem 
 * \defgroup Dem_DTCOriginTypes
 *  This is the first group
 * \par Autosar standard
 * SWS_Dem_00934
 * \sa Dem_DTCOriginType
 *  @{
 */
#define DEM_DTC_ORIGIN_PRIMARY_MEMORY	0x01/*!< Event information is located in the primary memory */
#define DEM_DTC_ORIGIN_MIRROR_MEMORY	0x02/*!< Event information is located in the mirror memory */
#define DEM_DTC_ORIGIN_PERMANENT_MEMORY	0x03/*!< Event information is located in the permanent memory */
/** @} */ // end of Dem_DTCOriginTypes

/*!
 * \ingroup Dem 
 * \defgroup Dem_EventDisplacementStrategies
 *  This is the first group
 * \par Autosar standard
 * SWS_Dem_00934
 * \sa Dem_DTCOriginType
 *  @{
 */
#define DEM_DISPLACEMENT_FULL			0x02/*!< */
#define DEM_DISPLACEMENT_NONE			0x00/*!< */
#define DEM_DISPLACEMENT_PRIO_OCC		0x01/*!< */
/** @} */ // end of Dem_EventDisplacementStrategies

/*!
 * \ingroup Dem 
 * \enum Dem_DtrUpdateKind
 * \brief ???
 *
 * \par Autosar standard
 * SWS_Dem_00754
 */
#define DEM_DTR_UPDATE_ALWAYS				0x00/*!<Any DTR result reported by the monitor is used by the Dem*/
#define DEM_DTR_UPDATE_STEADY				0x01
/** @} */ // end of Dem_EventDisplacementStrategies

/*!
 * \ingroup Dem 
 * \defgroup Dem_DTRControlTypes
 *  This is the first group
 * \par Autosar standard
 * SWS_Dem_00941, 
 * \sa Dem_DTRControlType
 *  @{
 */
#define DEM_DTR_CTL_NORMAL				0x00 /*!< Values are reported and regarded as valid test result */
#define DEM_DTR_CTL_NO_MAX				0x01 /*!< Values are reported, but maximum limit is not available (not valid); upper limit   value is ignored*/
#define DEM_DTR_CTL_NO_MIN				0x02 /*!< Values are reported, but minimum limit is not available (not valid); lower limit value is ignored*/
#define DEM_DTR_CTL_RESET				0x03 /*!< Values are all ignored. External representation will be all zeros as initialized (e.g. after  fault clear)*/
#define DEM_DTR_CTL_INVISIBLE			0x04 /*!< Values are all ignored. This DTR is treated for the external view (tester) as if not integrated*/
/** @} */ // end of Dem_DTRControlTypes

/*!
 * \ingroup Dem 
 * \defgroup Dem_EventKindTypes
 *  This is the first group
 *  @{
 */
#define DEM_EVENT_KIND_BSW				0x00
#define DEM_EVENT_KIND_SWC				0x01
/** @} */ // end of Dem_EventKindTypes


/*! 
 * \ingroup Dem 
 * \defgroup Dem_EventStatusTypes
 *  This is the first group
 * \sa Dem_EventStatusType
 *  @{
 */
#define DEM_EVENT_STATUS_PASSED			0x00/*!< Monitor reports qualified test result passed */
#define DEM_EVENT_STATUS_FAILED			0x01/*!< Monitor reports qualified test result */
#define DEM_EVENT_STATUS_PREPASSED		0x02/*!< Monitor reports non-qualified test result pre-passed (shall be debounced by Dem) */
#define DEM_EVENT_STATUS_PREFAILED		0x03/*!< Monitor reports non-qualified test result pre-failed (shall be debounced by Dem) */
/** @} */ // end of Dem_EventStatusTypes


/*! 
 * \ingroup Dem
 * \defgroup Dem_IndicatorStatusTypes
 *  This is the first group
 *  @{
 */
#define DEM_INDICATOR_OFF				0x00/*!<Indicator off mode */
#define DEM_INDICATOR_CONTINUOUS		0x01/*!<Indicator continuously on mode */
#define DEM_INDICATOR_BLINKING			0x02/*!<Indicator blinking mode */
#define DEM_INDICATOR_BLINK_CONT		0x03/*!<Indicator blinking or continuously on mode */
#define DEM_INDICATOR_SLOW_FLASH		0x04/*!<Indicator slow flashing mode */
#define DEM_INDICATOR_FAST_FLASH		0x05/*!<Indicator fast flashing mode */
#define DEM_INDICATOR_ON_DEMAND			0x06/*!<Indicator on-demand mode */
#define DEM_INDICATOR_SHORT				0x07/*!<Indicator short mode */
/** @} */ // end of Dem_IndicatorStatusTypes

/*! 
 * \ingroup Dem
 * \defgroup Dem_EventMemoryEntryStorageTriggers
 *  This is the first group
 *  @{
 */
#define DEM_TRIGGER_ON_CONFIRMED			0x00/*!<Event Memory entries are triggered if the UDS DTC status bit 3 (confirmedDTC) changes from 0 to 1 */
#define DEM_TRIGGER_ON_FDC_THRESHOLD		0x01/*!<Event Memory entries are triggered when the FDC threshold is reached */
#define DEM_TRIGGER_ON_PENDING				0x02/*!<Event Memory entries are triggered if the UDS DTC status bit 2 (pendingDTC) changes from 0 to 1 */
#define DEM_TRIGGER_ON_TEST_FAILED			0x03/*!<Event Memory entries are triggered if the UDS DTC status bit 0 (testFailed) changes from 0 to 1 */
/** @} */ // end of Dem_EventMemoryEntryStorageTriggers

/*! 
 * \ingroup Dem
 * \defgroup Dem_UdsStatusByteTypes
 *  This is the first group
 * \sa Dem_UdsStatusByteType
 *  @{
 */
#define DEM_UDS_STATUS_TF				0x01/*!< Bit 0: TestFailed */
#define DEM_UDS_STATUS_TFTOC			0x02/*!< Bit 1: TestFailedThisOperationCycle */
#define DEM_UDS_STATUS_PDTC				0x04/*!< Bit 2: PendingDTC */
#define DEM_UDS_STATUS_CDTC				0x08/*!< Bit 3: ConfirmedDTC */
#define DEM_UDS_STATUS_TNCSLC			0x10/*!< Bit 4: TestNotCompletedSinceLastClear */
#define DEM_UDS_STATUS_TFSLC			0x20/*!< Bit 5: TestFailedSinceLastClear */
#define DEM_UDS_STATUS_TNCTOC			0x40/*!< Bit 6: TestNotCompletedThisOperationCycle */
#define DEM_UDS_STATUS_WIR				0x80/*!< Bit 7: WarningIndicatorRequested */
/** @} */ // end of Dem_UdsStatusByteTypes

/*! 
 * \ingroup Dem
 * \defgroup Dem_DebouncingStateTypes
 *  This is the first group
 *  @{
 */
#define DEM_TEMPORARILY_DEFECTIVE		0x01/*!< Bit 0: Temporarily Defective (corresponds to 0 < FDC < 127) */
#define DEM_FINALLY_DEFECTIVE			0x02/*!< Bit 1: finally Defective (corresponds to FDC = 127) */
#define DEM_TEMPORARILY_HEALED			0x04/*!< Bit 2: temporarily healed (corresponds to -128 < FDC < 0) */
#define DEM_TEST_COMPLETE				0x08/*!< Bit 3: Test complete (corresponds to FDC = -128 or FDC = 127) */
#define DEM_DTR_UPDATE					0x10/*!< Bit 4: DTR Update (= Test complete && Debouncing complete && enable conditions / storage conditions fulfilled) */
/** @} */ // end of Dem_DebouncingStateTypes


/*! 
 * \ingroup Dem
 * \defgroup Dem_DebounceAlgorithms The First Group
 *  This is the first group
 * \sa Dem_DebounceAlgorithm
 *  @{
 */
#define DEM_DEBOUNCE_ALGORITHM_NATIVE	0x00/*!<    */
#define DEM_DEBOUNCE_ALGORITHM_COUNTER	0x01/*!<    */
#define DEM_DEBOUNCE_ALGORITHM_TIME		0x02/*!<    */
/** @} */ // end of Dem_DebounceAlgorithms



/*
 ***************************************************************************************************
 * Types
 ***************************************************************************************************
*/

/*! \struct Dem_DTRControlType
 *  \brief allias of Dem_UdsStatusByteType
 * \par Autosar standard
 * SWS_Dem_00941, 
 */
typedef uint8 Dem_DTRControlType;

/*! \struct Dem_EventIdType
 *  \brief Internal identifier of a diagnostic event
 *
 */
typedef uint16 Dem_EventIdType;

/*! \struct Dem_EventStatusType
 *  \brief allias of Dem_UdsStatusByteType
 *  \remark
 */
typedef uint8 Dem_EventStatusExtendedType;

typedef uint8 Dem_IndicatorStatusType;

/*! \struct Dem_InitMonitorReasonType
 *  \brief allias of Dem_UdsStatusByteType
 * \par Autosar standard
 * SWS_Dem_00942, 
 */
typedef uint8 Dem_InitMonitorReasonType;

/*!
 * \ingroup Dem 
 * \struct Dem_DTCFormatType
 * \brief ???
 *
 * \par Autosar standard
 * SWS_Dem_00933
 */
typedef uint8 Dem_DTCFormatType;

/*!
 * \ingroup Dem 
 * \struct Dem_ComponentIdType
 * \brief ???
 *
 * \par Autosar standard
 * SWS_Dem_01114, SRS_Diag_04142
 */
typedef uint16 Dem_ComponentIdType;

typedef uint8 Dem_DebounceResetStatusType;

/*! \struct Dem_DebouncingStateType
 *  \brief ???
 *
 * \par Autosar standard
 * SWS_Dem_01000
 */
typedef uint8 Dem_DebouncingStateType;

/*! \struct Dem_DTCOriginType
 *  \brief ???
 *
 * \par Autosar standard
 * SWS_Dem_00934
 */
typedef uint8 Dem_DTCOriginType;






/*! Dem_EventStatusType
 *  \brief ???
 *  \remark
 */
typedef uint8 Dem_EventStatusType;


/*! \struct Dem_DTCOriginType
 *  \brief ???
 *
 * \par Autosar standard
 * SWS_Dem_00929
 */
typedef uint8 Dem_OperationCycleStateType;


/*! \struct Dem_UdsStatusByteType
 *  \brief ???
 *  \remark
 */
typedef uint8 Dem_UdsStatusByteType;










/*---------------------------------------------------------------------------------------------------------------*/
#endif /*DEM_TYPES_H*/

