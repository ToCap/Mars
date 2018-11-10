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

#ifndef COMPILER_H
#define COMPILER_H

/**
 * \defgroup Compiler
*/

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
*/
#include "Std_Types.h"
#include "Compiler_Cfg.h"


/*
 ***************************************************************************************************
 * Constants
 ***************************************************************************************************
*/



/*! 
 * \ingroup Compiler
 *  This is the first group
 * \par Autosar standard
 * SWS_COMPILER_00046
 */
#define AUTOMATIC		


#define EXTERN							extern

/*! 
 * \ingroup Compiler
 *  This is the first group
 * \par Autosar standard
 * SWS_COMPILER_00059
 */
#define TYPEDEF							typedef

/*! 
 * \ingroup Compiler
 *  This is the first group
 * \par Autosar standard
 * SWS_COMPILER_00051
 * \warning : Deviation : defintion does not contain required cast since C-pointer mechanism is not supported in NXC language
 */
#define NULL_PTR						(0)


/*! 
 * \ingroup Compiler
 *  This is the first group
 * \par Autosar standard
 * SWS_COMPILER_00057
 */
#define INLINE							__inline

/*! 
 * \ingroup Compiler
 *  This is the first group
 * \par Autosar standard
 * SWS_COMPILER_00060
* \warning : Deviation : defintion does not contain "static" keyword since mechanism is not supported in NXC language
 */
#define LOCAL_INLINE					static __inline


/*! 
 * \ingroup Compiler
 *  This is the first group
 * \par Autosar standard
 * SWS_COMPILER_00023
 */		
#define CONST(type, memclass) memclass const type

/*! 
 * \ingroup Compiler
 *  This is the first group
 * \par Autosar standard
 * SWS_COMPILER_00026
 */		
#define VAR(type, memclass) memclass type


/*! 
 * \ingroup Compiler
 *  This is the first group
 * \brief	Return the version information of this module
 * \param[out] ptrtype type of the referenced data
 * \param[out] memclass classification of the pointer's variable itself
 * \param[out] ptrclass define the classification of the pointer's distance
 * \par Autosar standard
 * SWS_COMPILER_00006
 */		
#define P2VAR(ptrtype) ptrtype *



#endif /*COMPILER_H*/
