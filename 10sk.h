/*********************************************************************************
*																				 
*  File Name:  m10sk.h                                         
*                                                                  
*  Content: Hardware and interface definitions to support the  starter kit.
*			Special version of MDECE30102 board support package that uses Timer X
*			for Real Time Interrupt instead of Timer C.
**********************************************************************************                                                                 				 
*	Copyright (c) 2002 Mitsubishi Electric and Electronics USA, Inc.             *    
*	All rights reserved															 *
**********************************************************************************
*	The software supplied by Mitsubishi Electric and Electronics USA, Inc. 		 *
*	is intended and supplied for use on Mitsubishi Electric  products. 			 *
*	This software is owned by Mitsubishi Electric and Electronics USA, Inc.  	 *
*	or Mitsubishi Electric Corporation and is protected under applicable 		 *
*	copyright laws. All rights are reserved. 									 *
*									 											 * 																				 *
*	THIS SOFTWARE IS PROVIDED "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED 	 *
*	OR STATUTORY, INCLUDING BUT NOT LIMITED TO IMPLIED WARRANTIES OF 			 *
*	MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. *
*	MITSUBISHI ELECTRIC AND ELECTRONICS USA, INC. AND MITSUBISHI ELECTRIC 		 *
*	CORPORATION RESERVE THE RIGHT, WITHOUT NOTICE, TO MAKE CHANGES TO THIS 		 *
*	SOFTWARE. NEITHER MITSUBISHI ELECTRIC AND ELECTRONICS USA, INC. NOR 		 *
*   MITSUBISHI ELECTRIC CORPORATION SHALL, IN ANY CIRCUMSTANCES, BE LIABLE 		 *
*	FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES FOR ANY REASON WHATSOEVER  *
*	ARISING OUT OF THE USE OR APPLICATION OF THIS SOFTWARE.	 					 *
*                                                               				 *
*================================================================================*
*	$Log:$
*================================================================================*/
#ifndef _10SK_H
#define _10SK_H
#endif
#define USE_LCD_DISPLAY			1		// Set to 1 if using LCD display.  
#define USE_DELAYS				1		// Set to 1 if delay timer is used.  
#define USE_ROUND_ROBIN_SCH		1		// Set to 1 if using Round Robin Task Scheduler
#define MAX_TASKS 				6		// Set maximum number of tasks to be used in system 
    									// Will effect performance. 
#define USE_KEY_INPUT_BUFFER	1		// Set to 1 to use key input buffer.
#define SIZE_OF_KEY_BUFFER		5		// Size of key input buffer. 
#ifndef MAIN_CLOCK
#define MAIN_CLOCK	   (unsigned long)16e6	// Main clock crystal speed
#endif
/* ** DO NOT EDIT BELOW THIS LINE **************************************************/

// **** Key Input mode section.  Ram required (3 + SIZE_OF_KEY_BUFFER) bytes.
enum SYSTEM_KEYS{ KEY_A = 1,  KEY_B, KEY_C,KEY_RED_1,KEY_RED_2,KEY_BLACK_1,KEY_BLACK_2};
#ifndef _10SK_C 
extern void init_BSP(void);
extern char dequeue_key(void);
extern void  keyinput_down(void);
/**** LCD Fuction section *********************************************************/
#if USE_LCD_DISPLAY == 1
extern void disp_ctrlw(unsigned char disp_ctrl);
extern void disp_dataw(unsigned char disp_data);
extern void init_disp( void );
extern void display(int ln, far char *Buff);
#endif
/**** Round Robin function section ************************************************/
#if USE_ROUND_ROBIN_SCH == 1
extern int  addTask(void (*task)(void), int time, int priority);
extern void removeTask(void (*task)(void));
extern void Run_RR_Scheduler(void);
extern void Run_Task(int task_number);
#endif
/**** delayes ******************** ************************************************/
#if USE_DELAYS	== 1
extern void tdelay(unsigned int milliseconds);
#endif 
#endif // #ifndef _10SK_C 
/**** Tick timer section.  Fixed at 1 milli second ***************/

#define TIMER_BASE ((unsigned int)(1000.0 * 8 * 8192 / MAIN_CLOCK)) 	//At 16M Hz timer base is 4.098e-3 seconds
#define mSECONDS(time) ((uI16)((time / TIMER_BASE) + 1)) // Minimum time = Timer Base. 
														 // Accuracy of delays are +1 Timer Base
/**********************************************************************************/
// LCD command mnemonic.   use 	disp_ctrlw funciton to write these commands to the LCD. 
/**********************************************************************************/
#define LCD_CLEAR        0x01    /* Clear LCD display and home cursor   */
#define LINE1   		0
#define LINE2   		1
#define LCD_HOME_L1      0x80    /* move cursor to line 1               */
#define LCD_HOME_L2      0xC0    /* move cursor to line 2               */
#define CURSOR_MODE_DEC  0x04    /* Cursor auto decrement after R/W     */
#define CURSOR_MODE_INC  0x06    /* Cursor auto increment after R/W     */
#define FUNCTION_SET     0x28    /* Setup, 4 bits,2 lines, 5X7          */
#define LCD_CURSOR_ON    0x0E    /* Display ON with Cursor              */
#define LCD_CURSOR_OFF   0x0C    /* cursor off*/
#define LCD_CURSOR_BLINK 0x0D    /* Display on with blinking cursor     */
#define LCD_CURSOR_LEFT  0x10    /* Move Cursor Left One Position       */
#define LCD_CURSOR_RIGHT 0x14    /* Move Cursor Right One Position      */
/**********************************************************************************/
/* Type definitions */
/**********************************************************************************/
typedef unsigned char  Bool;
typedef signed char    sI08;
typedef signed short   sI16;
typedef signed long    sI32;
typedef unsigned char  uI08;
typedef unsigned short uI16;
typedef unsigned long  uI32;
/**********************************************************************************/
#include "sfr10.h"
/**********************************************************************************/
/* Handy Macros */
/**********************************************************************************/
#define ON      (Bool)1
#define OFF     (Bool)0

#ifndef TRUE
#define TRUE    (Bool)1
#endif

#ifndef FALSE
#define FALSE   (Bool)0
#endif

#ifndef HIGH
#define HIGH 1
#endif

#ifndef LOW
#define LOW 0
#endif

#ifndef ENABLE_INTS
#define ENABLE_INTS   {asm(" FSET I");}
#endif

#ifndef DISABLE_INTS
#define DISABLE_INTS	{asm(" FCLR I");}
#endif
/* initialization code for starter kit */
/**********************************************************************************/
/*  Interface to the M30102 SK keys (buttons).                                    */
/**********************************************************************************/
#define S_S2 p4_5   /* M30102 SK push button S2 */
#define S_S3 p1_0   /* M30102 SK push button S3 */
#define S_S4 p1_1   /* M30102 SK push button S4 */
/**********************************************************************************/
/* M30102 SK LED output declarations                                              */  
/**********************************************************************************/
#define RED_LED  p3_0
#define YEL_LED	 p3_1
#define GRN_LED  p3_2
#define LED(led, state) ((led) = !state)
#define ENABLE_LEDS {pd3_0 = ON; pd3_1 = ON; pd3_2 = ON;}
#define ALL_LED_ON  {p3_0 = 0; p3_1 = 0; p3_2 = 0;}
#define ALL_LED_OFF {p3_0 = 1; p3_1 = 1; p3_2 = 1;}

