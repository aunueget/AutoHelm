/*****************************************************************************
*
*	File Name:  rtc.c                                         
*                                                                  
*	Content:    provides real_time_clock function for M16C.
*               Modified for M16C/10 MCU                   
*                                                                  
*	Copyright (c) 2001 Mitsubishi Electric & Electronics USA, Inc.                  
*	All rights reserved
*
*	Mitsubishi Electric & Electronics USA does not guarantee the performance or 
*	use of this source-code.  The intended use of provided source-code is the 
*	sole responsible of the user.  The files have been successfully compiled 
*	using Mitsubishi's NC30 compiler.  Before using this software review the 
*   source and make any necessary changes to support your hardware and application.
*                                                               
*=============================================================================
*	$Log: rtc.c,v $
*	Revision 1.2  2002-06-07 14:00:17-04  bembry
*	Fixed flicker problem.  Chang Temp conversion equation fixes problem at "0" crossover point.
*
*===========================================================================*/

#include "delayTimer.h"
#include "10sk.h"
#include "Globals.h"

// Code ------------------------------------------------------------------------
************************************************************************/

/*****************************************************************************
Name:      wait_ticks  waits a number of ticks which equal 20 micro seconds or 1/50 millisecond
Parameters:    none                   
Returns:       none 
Description:   Decrements c_ticks for a count down    

*****************************************************************************/
void wait_ticks(int tickCount){
	tys = 1;		// enable timer y
	c_ticks=tickCount;
	while(c_ticks);
	tys = 0;		// disable timer y
}

/*****************************************************************************
Name:      tick_count 
Parameters:    none                   
Returns:       number of milliseconds since program execution
Description:   keep track of time in millisecons

*****************************************************************************/
int tick_count(void)
{
	return c_ticks;
}