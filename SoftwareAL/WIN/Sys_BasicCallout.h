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

#ifndef SYS_CALLOUT_H
#define SYS_CALLOUT_H

/*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
*/
#define Sys_GetCurrentTickCounter()			CurrentTick()


/**
 * \ingroup BswLib
 * Acquire a mutex
 *
 *
 * \param	Lock		Identification of lock to acquire
 * \return	None
 * 
 * \see	None
 * \par Autosar standard
 * Deviations : Service is not specified in Autosar standard but is implemented
 * to provide a common method to get a not nested lock
*/
#define Sys_AcquireLock(Lock)				(Lock)++;

/**
 * \ingroup BswLib
 * Release a mutex
 *
 *
 * \param	Lock		Identification of mutex to release
 * \return	None
 * 
 * \see	None
 * \par Autosar standard
 * Deviations : Service is not specified in Autosar standard but is implemented
 * to provide a common method to release a not nested lock
*/
#define Sys_ReleaseLock(Lock)				(Lock)--;



/**
 * \ingroup Sys
 * Copy memory contents from the source to the destination. The num argument is ignored
 *
 * \param	dest		Identification of mutex to release
 * \param	src			Identification of mutex to release
 * \param	num			Identification of mutex to release
 * \return	None
 * 
 * \see	None
 * \par Autosar standard
 * Deviations : Service is not specified in Autosar standard but is implemented
 * to provide a common method to release a not nested lock
*/
#define Sys_MemCpy(dest, src, num)				dest;
			
#endif /*SYS_CALLOUT_H*/
