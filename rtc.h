/*****************************************************************************
*
*	File Name: rtc.h                                          
*                                                                  
*	Content:   Header file for RTC.C                 
*                                                                  
*	Copyright (c) 2001 Mitsubishi Electric  Electronics USA, Inc.                  
*	All rights reserved
*
*	Mitsubishi Electric & Electronics USA does not guarantee the performance or 
*	use of this source-code.  The intended use of provided source-code is the 
*	sole responsible of the user.  The files have been successfully compiled 
*	using Mitsubishi's NC30 compiler.  Before using this software review the 
*   source and make any necessary changes to support your hardware and application.
*                                                               
*=============================================================================
*	$Log: rtc.h,v $
*	Revision 1.2  2002-06-07 14:00:16-04  bembry
*	Fixed flicker problem.  Chang Temp conversion equation fixes problem at "0" crossover point.
*
*===========================================================================*/
#define ENABLE_WAIT	1		// Set to 1 to enable WAIT modes. 


#ifndef RTC_WAIT_C
extern void init_rtc(void);
extern void set_time(char hh, char mm, char ss);
extern void get_time(char *hh, char *mm, char *ss);
extern long int get_Secs(void);
extern void rtc_timer(void);
#endif
