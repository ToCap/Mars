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

#ifndef IOLIB_TYPES_H
#define IOLIB_TYPES_H


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
 * \ingroup IoLib 
 * \defgroup IoLib_PortInputTypes
 *  This is the first group
 * \sa IoLib_PortInputType
 *  @{
 */
 
#define IOLIB_PORT_SENSOR_1					0x00
#define IOLIB_PORT_SENSOR_2					0x01
#define IOLIB_PORT_SENSOR_3					0x02
#define IOLIB_PORT_SENSOR_4					0x03
/** @} */ // end of IoLib_PortInputTypes 

#define IOLIB_NUM_SENSOR_MAX					4

/*! 
 * \ingroup IoLib 
 * \defgroup IoLib_PortButtonTypes
 *  This is the first group
 * \sa IoLib_PortButtonType
 *  @{
 */
#define IOLIB_PORT_BUTTON_1					0x00
#define IOLIB_PORT_BUTTON_2					0x01
#define IOLIB_PORT_BUTTON_3					0x02
#define IOLIB_PORT_BUTTON_4					0x03
/** @} */ // end of IoLib_PortButtonTypes 


#define IOLIB_NUM_BUTTON_MAX				4

/*! 
 * \ingroup IoLib 
 * \defgroup IoLib_PortActuatorTypes
 *  This is the first group
 * \sa IoLib_PortActuatorType
 *  @{
 */
 
#define IOLIB_PORT_ACTUATOR_A				PORT_PIN_OUT_A
#define IOLIB_PORT_ACTUATOR_B				PORT_PIN_OUT_B
#define IOLIB_PORT_ACTUATOR_C				PORT_PIN_OUT_C
//TODO : Definir les combinaisons
/** @} */ // end of IoLib_PortActuatorTypes 

/*! 
 * \ingroup IoLib 
 * \defgroup IoLib_SensorFailureTypes
 *  This is the first group
 * \sa IoLib_SensorFailureType
 *  @{
 */
#define IOLIB_SENSOR_FAILURE_OPENLOAD		0
#define IOLIB_SENSOR_FAILURE_LOTHRSLD		1
#define IOLIB_SENSOR_FAILURE_HITHRSLD		2
/** @} */ // end of IoLib_SensorFailureTypes

#define IOLIB_SENSOR_NUM_FAILURE_MAX		3

/*! 
 * \ingroup IoLib 
 * \defgroup IoLib_ServoDiagTypes
 *  This is the first group
 * \sa IoLib_ServoDiagType
 *  @{
 */
#define IOLIB_SERVO_DIAG_0					0x0
#define IOLIB_SERVO_DIAG_1					0x1
#define IOLIB_SERVO_DIAG_2					0x2
/** @} */ // end of IoLib_ServoDiagTypes


/*! 
 * \ingroup IoLib 
 * \defgroup IoLib_ServoStatusTypes
 *  This is the first group
 * \sa IoLib_ServoStatusType
 *  @{
 */
#define IOLIB_SERVO_STATUS_CMD_BEG			0x00
#define IOLIB_SERVO_STATUS_CMD_END			0x01
#define IOLIB_SERVO_STATUS_RAT_LOLIM		0x02
#define IOLIB_SERVO_STATUS_RAT_UPLIM		0x03
/** @} */ // end of IoLib_ServoStatusTypes



/*!
 * \ingroup IoLib 
 * \defgroup IoLib_SensorModes
 *  This is the first group
 * \par Autosar standard
 * SWS_Dem_00934
 * \sa IoLib_SensorMode
 *  @{
 */
#define IOLIB_SENSOR_MODE_RAW				0x00 /*!< IN_MODE_RAW */        
#define IOLIB_SENSOR_MODE_BOOL				0x20 /*!< IN_MODE_BOOLEAN */   
#define IOLIB_SENSOR_MODE_EDGE				0x40 /*!< IN_MODE_TRANSITIONCNT */
#define IOLIB_SENSOR_MODE_PULSE				0x60 /*!< IN_MODE_PERIODCOUNTER */
#define IOLIB_SENSOR_MODE_PERCENT			0x80 /*!< IN_MODE_PCTFULLSCALE */
//#define IOLIB_SENSOR_MODE_CELSIUS			IN_MODE_CELSIUS       
//#define IOLIB_SENSOR_MODE_FAHRENHEIT		IN_MODE_FAHRENHEIT    
//#define IOLIB_SENSOR_MODE_ROTATION		IN_MODE_ANGLESTEP
/** @} */ // end of IoLib_SensorModes


/*!
 * \ingroup IoLib 
 * \defgroup IoLib_InputTypes
 *  This is the first group
 * \par Autosar standard
 * SWS_Dem_00934
 * \sa IoLib_InputType
 *  @{
 */
#define IOLIB_SENSOR_TYPE_NONE				0x00 /*!< NXT no SENSOR */
#define IOLIB_SENSOR_TYPE_SWITCH			0x01 /*!< NXT switch SENSOR used as port expander */
//#define IOLIB_SENSOR_TYPE_TEMPERATURE		0x02 
//#define IOLIB_SENSOR_TYPE_REFLECTION		0x03 
//#define IOLIB_SENSOR_TYPE_ANGLE			0x04 
#define IOLIB_SENSOR_TYPE_LIGHT_ACTIV		0x05 
#define IOLIB_SENSOR_TYPE_LIGHT_INACTIV		0x06 
#define IOLIB_SENSOR_TYPE_SOUND_DB			0x07 
#define IOLIB_SENSOR_TYPE_SOUND_DBA			0x08 
#define IOLIB_SENSOR_TYPE_CUSTOM				0x09 
#define IOLIB_SENSOR_TYPE_LOWSPEED			0x0A 
#define IOLIB_SENSOR_TYPE_LOWSPEED_9V		0x0B 
//#define IOLIB_SENSOR_TYPE_HISPEED			0x0C 
#define IOLIB_SENSOR_TYPE_COLORFULL			0x0D 
#define IOLIB_SENSOR_TYPE_COLORRED			0x0E 
#define IOLIB_SENSOR_TYPE_COLORGREEN			0x0F 
#define IOLIB_SENSOR_TYPE_COLORBLUE			0x10 
#define IOLIB_SENSOR_TYPE_COLORNONE			0x11 
#define IOLIB_SENSOR_TYPE_COLOREXIT			0x12 
			
/** @} */ // end of IoLib_InputTypes

/*
 ***************************************************************************************************
 * Types
 ***************************************************************************************************
*/

/*!
 * \ingroup IoLib 
 * \struct IoLib_PortSensorType
 * \brief ???
 *
 * \par Autosar standard
 * 
 */
typedef uint8 IoLib_PortSensorType;

/*!
 * \ingroup IoLib 
 * \struct IoLib_PortActuatorType
 * \brief ???
 *
 * \par Autosar standard
 * 
 */
typedef uint8 IoLib_PortActuatorType;


typedef uint8 IoLib_SensorMode;

typedef uint8 IoLib_SensorType;

typedef uint8 IoLib_SensorFailureType;


typedef uint8 IoLib_SignalType;

typedef uint8 IoLib_ServoDiagType;

typedef uint16 IoLib_ServoStatusType;






/*---------------------------------------------------------------------------------------------------------------*/
#endif /*IOLIB_TYPES_H*/

