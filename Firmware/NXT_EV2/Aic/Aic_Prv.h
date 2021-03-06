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

#ifndef AIC_PRV_H
#define AIC_PRV_H

/**
 * \defgroup Aic
 */



/*
 ***************************************************************************************************
 * Prototypes
 ***************************************************************************************************
*/

/* Default handlers for the three general kinds of interrupts that the
 * ARM core has to handle. These are defined in irq.s, and just freeze
 * the board in an infinite loop.
 */
extern void default_isr(void);
extern void default_fiq(void);
extern void spurious_isr(void);

#endif /*AIC_PRV_H*/
