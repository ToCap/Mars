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

#ifndef DEM_CFG_H
#define DEM_CFG_H

/*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
*/

#define	DEM_DEV_ERROR_DETECT					STD_ON

#define DEM_VERSION_INFO_API					STD_ON

#define DEM_BSW_ERROR_BUFFER_SIZE				10

#define DEM_MAX_NUMBER_PRESTORED_FF 			10

#define DEM_DEBOUNCE_COUNTER_BASED_SUPPORT		STD_OFF

#define DEM_DEBOUNCE_TIME_BASED_SUPPORT			STD_OFF

#define DEM_TRIGGER_FIM_REPORTS					STD_ON

#define  DEM_TRIGGER_DLT_REPORTS				STD_OFF

#define DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY		10
#define DEM_MAX_NUMBER_EVENT_ENTRY_MIRROR		0
#define DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT	0

#define DEM_EVENT_MEMORY_ENTRY_STORAGE_TRIGGER	3	/*DEM_TRIGGER_ON_TEST_FAILED*/

#define DEM_MAX_NUMBER_SIGNAL_ENTRY_SNAPSHOT	10

#define DEM_NUM_CFG_EVENT_MAX  					50
#define DEM_NUM_CFG_COMPONENT_MAX				10
#define DEM_NUM_CFG_INDICATOR_MAX				10
#define DEM_NUM_CFG_ENABLE_COND_MAX				50


#endif /*DEM_CFG_H*/
