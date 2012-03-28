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
#define RTC_C
#include "rtc.h"
#include "10sk.h"
void init_rtc(void);
void set_time(char hh, char mm, char ss);
void get_time(char *hh, char *mm, char *ss);

#pragma	INTERRUPT	rtc_timer
void rtc_timer(void);

char c_hh, c_mm, c_ss;
long int secs;
#define ENABLE_INTERRUPTS   { asm(" FSET I");}
#define DISABLE_INTERRUPTS	{ asm(" FCLR I");}
#define NO_OP			   	{ asm("nop"); }


// Code ------------------------------------------------------------------------
/*****************************************************************************
Name:         init_rtc  
Parameters:   none                  
Returns:      none  
Description:  Intializes Real Time Clcok Function.    

*****************************************************************************/
void init_rtc(void)
{
	secs=0;
	prc0 = 1;	 	// protect off
	cm03 = 1;	 	// Xcin/Xcout high drive
	cm04 = 1;	 	// Xc enable
	prc0 = 0;	 	// protect off.  
	t1ck0 = 1; t1ck1 = 1; // Set Timer 1 count source.   
	pre1 = 7;       // Load prescaler with 4
    t1 = 127;       // load t1 with 251   4 x 255 = 1024   :// 32.768 KHz / 32 / 1024 = 1 sec.
	DISABLE_INTERRUPTS
	t1ic = 0x06; 	// timer 1 underflow interrut.  (S4). 
	ENABLE_INTERRUPTS
}
/*****************************************************************************
Name:          set_time 
Parameters:    Current hour, minute, and second.                  
Returns:       none 
Description:   Sets the current time.  

*****************************************************************************/
void set_time(char hh, char mm, char ss)
{
	DISABLE_INTERRUPTS
	t1ic = 0x00; 	// disable interrupt for timer b0. 
	ENABLE_INTERRUPTS
	c_hh = hh; c_mm = mm; c_ss = ss;	 // set the current time. 
	init_rtc();
}
/*****************************************************************************
Name:         get_time  
Parameters:   none                  
Returns:      Current hour, minutes, and seconds.   
Description:  Gets the current time.    

*****************************************************************************/
void get_time(char *hh, char *mm, char *ss)
{
	DISABLE_INTERRUPTS
	*hh = c_hh; *mm = c_mm; *ss = c_ss;
	ENABLE_INTERRUPTS
}
/*****************************************************************************
Name:      INTERRUPT HANDLER, rtc_timer.  
Parameters:    none                   
Returns:       none 
Description:   Increaments the current time when the timer expires.    

*****************************************************************************/
void rtc_timer(void)
{
static char logic;
 if(logic)
    logic = 0;
 else
    logic = 1; 
 LED(YEL_LED, logic);
 if (++c_ss >=60){
	c_ss = 0;					
	if(++c_mm >= 60){
		c_mm = 0;
		if(++c_hh >= 12){
			c_hh = 0;
			// insert code for date adjustment.   
			}
		}
	}
	secs++;
}

/*****************************************************************************
Name:      gets the seconds
Parameters:    none                   
Returns:        number of seconds since init_rtc
Description:   returns the number seconds since init_rtc 

*****************************************************************************/

long int get_Secs(){
	return secs;
}


