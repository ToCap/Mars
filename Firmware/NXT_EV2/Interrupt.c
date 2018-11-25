#ifndef INTERRUPT_NXC
#define INTERRUPT_NXC



/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
*/

/* Include of standard headers */
#include "Std_Types.h"


/*
 ***************************************************************************************************
 * Services
 ***************************************************************************************************
*/

#if (PLATFORM_TYPE == PLATFORM_NXT_EV2_VPF)
void systick_isr_entry(void)
{

}
#endif

#if (PLATFORM_TYPE == PLATFORM_NXT_EV2_VPF)
void systick_low_priority_entry(void)
{

}
#endif

#if (PLATFORM_TYPE == PLATFORM_NXT_EV2_VPF)
void twi_isr_entry(void)
{
	return ;
}
#endif


#if (PLATFORM_TYPE == PLATFORM_NXT_EV2_VPF)
uint32 interrupts_get_and_disable(void)
{
	return (uint32)1;
}
#endif


#if (PLATFORM_TYPE == PLATFORM_NXT_EV2_VPF)
void interrupts_enable(void)
{
	return ;
}
#endif

#endif