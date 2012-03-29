
/*****************************************************************************
*
*	File Name: 	10sk.c                                          
*                                                                  
*	Content:    Board support package for <SV30102-SKP
*				Provides the following functionality.                
*               1) Round-Robin Task Scheduler.
*				2) Key buffer and debounce functions
*				3) Delay function 
*               4) LCD Display functions 
*   This version is 10sk.c uses Timer X as RTI instead of Timer C Overflow.        
*                                                 
**********************************************************************************                                                                               
*   Copyright (c) 2002 Mitsubishi Electric and Electronics USA, Inc.             *    
*   All rights reserved                                                          *
**********************************************************************************
*   The software supplied by Mitsubishi Electric and Electronics USA, Inc.       *
*   is intended and supplied for use on Mitsubishi Electric  products.           *
*   This software is owned by Mitsubishi Electric and Electronics USA, Inc.      *
*   or Mitsubishi Electric Corporation and is protected under applicable         *
*   copyright laws. All rights are reserved.                                     *
*                                                                                *                                                                               *
*   THIS SOFTWARE IS PROVIDED "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED   *
*   OR STATUTORY, INCLUDING BUT NOT LIMITED TO IMPLIED WARRANTIES OF             *
*   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. *
*   MITSUBISHI ELECTRIC AND ELECTRONICS USA, INC. AND MITSUBISHI ELECTRIC        *
*   CORPORATION RESERVE THE RIGHT, WITHOUT NOTICE, TO MAKE CHANGES TO THIS       *
*   SOFTWARE. NEITHER MITSUBISHI ELECTRIC AND ELECTRONICS USA, INC. NOR          *
*   MITSUBISHI ELECTRIC CORPORATION SHALL, IN ANY CIRCUMSTANCES, BE LIABLE       *
*   FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES FOR ANY REASON WHATSOEVER  *
*   ARISING OUT OF THE USE OR APPLICATION OF THIS SOFTWARE.                      *
*                                                                                *
*================================================================================*
*   $Log:$
*================================================================================*/
#define _10SK_C
#include "10sk.h"
#if USE_KEY_INPUT_BUFFER  == 1
char key_buff[SIZE_OF_KEY_BUFFER];		// key input buffer. 
char key_out,key_in, key_mode;			// Indexes to key buffer. 
#define  KEY_1	p4_5					// S2
#define	 KEY_2	p1_0					// S3
#define  KEY_3	p1_1					// S4                   
#endif 	 //#if USE_KEY_INPUT_BUFFER  == 1
typedef struct {
  int initialTimerValue;
  int timer;
  int run;
  void (* task)(void);
} task_t;
typedef unsigned char byte;
/* =================== Global variables ======================= */
#if USE_ROUND_ROBIN_SCH	== 1
task_t GBL_task_list[MAX_TASKS];
int    GBL_run_scheduler=0;
#endif
#ifndef NULL
#define NULL ((void *)0)
#endif
#if	USE_DELAYS == 1
unsigned int delay_time;
#endif
/* ==================== Function prototypes ==================== */
void init_BSP(void);
#if USE_KEY_INPUT_BUFFER  == 1
void  Keyinput_task(void);
char  dequeue_key(void);
void enqueue (char key);
#endif
#pragma INTERRUPT tick_timer_intr
void tick_timer_intr(void);
int  addTask(void (*task)(void), int time, int priority);
void removeTask(void (*task)(void));
void init_Task_Timers(void);
void Run_RR_Scheduler(void);
void Run_Task(int task_number);
#if	USE_DELAYS == 1
void tdelay(unsigned int milliseconds);
#endif
#if USE_LCD_DISPLAY == 1
void DIS_delay(int milli_secs);
unsigned char disp_datar(void);
void disp_ctrlw(unsigned char disp_ctrl);
void disp_dataw(unsigned char disp_data);
unsigned char disp_datar(void);
void init_disp( void );
void display(int ln, far char *Buff);
void LCD_write( far char *Buff );

typedef union {
	unsigned char data;
	struct{
		unsigned char low: 4;
		unsigned char high:4;
		} nibble;
	} CHAR_DATA;

CHAR_DATA buff;

#define HIGH 1
#define LOW 0
#define DISPLAY_DATA		p0		  // Data bus
#define DISPLAY_RW			p2_1	  // Read/Write
#define DISPLAY_RS 			p2_0	  // RS Register Select.
#define DISPLAY_E			p3_4	  // Display Enable
#define DIS_DATA_DIR    	pd0		  // Data bus direction register
#define DIS_RW_DIR			pd2_1	  // Read/Write direction register. 
#define DIS_RS_DIR			pd2_0	  // RS Register Select..
#define DIS_E_DIR			pd3_4	  // Display Enable direction register. 
#define MAXIMUM_LINES		2		  // number of lines on the LCD display
#define NUMB_CHARS_PER_LINE	8		  // Maximum charactors per line of LCD display.  
#define WRITE_DIS_DATA  {prc2 = 1; DIS_DATA_DIR |= 0x0f; prc2 = 0;}
#define READ_DIS_DATA {prc2 = 1; DIS_DATA_DIR &= 0xf0; prc2 = 0;}

#endif
/*****************************************************************************
Name:            void init_BSP(void)
Parameters:                     
Returns:        
Description:     Intializes borad support firmware. 
*****************************************************************************/
void init_BSP(void)
{
	ENABLE_LEDS
#if USE_LCD_DISPLAY == 1
    init_disp();
#endif
    init_Task_Timers();
	ALL_LED_ON
	t1ck1 = 0; t1ck0 = 1;  // Set Timer 1 count source to 1/8
	pre1 = 100;       // Load prescaler with 1
	t1 = 82;       // load t1 with 4  2 x 5 = 10 :// 32.768 KHz / 32 / 10 = 102.4 times a second = 10 msec
	DISABLE_INTS
	t1ic = 0x01; 	// timer 1 underflow interrut.  (S4). 
	ENABLE_INTS 
#if USE_KEY_INPUT_BUFFER  == 1
	addTask(Keyinput_task, 5,(MAX_TASKS-1));	  // Sample key input every 25 ms. 
#endif
	ALL_LED_OFF 
}
/*****************************************************************************
Name:           Keyinput_task
Parameters:     none                
Returns:        none
Description:    Scans the keys of the MDECE30102 board and places press keys 
				the key buffer.  This provide debounce function for key input.   
*****************************************************************************/
#if USE_KEY_INPUT_BUFFER == 1
void  Keyinput_task(void)
{
switch(key_mode){
	case 0:	if((!KEY_1) || (!KEY_2) || (!KEY_3) ) key_mode = 1; break;	  
	case 1:
		 if((!KEY_1) || (!KEY_2) || (!KEY_3))
			{
			if(!KEY_1)	enqueue (KEY_A);
			if(!KEY_2) 	enqueue (KEY_B);
			if(!KEY_3)	enqueue (KEY_C);
			//if(KEY_4)	enqueue (KEY_RED_1);
			//if(KEY_5) 	enqueue (KEY_BLACK_1);
			//if(KEY_6)	enqueue (KEY_BLACK_2);
			//if(KEY_7)	enqueue (KEY_RED_2);
			key_mode = 2;
			}
		 else key_mode = 0;
		 break;
	case 2:	if((KEY_1) & (KEY_2) && (KEY_3)) key_mode = 3; break;	
	case 3:	if((KEY_1) & (KEY_2) && (KEY_3)) key_mode = 0; break;
	default: key_mode = 0; break;
	}
}
void  keyinput_down(void)
{
	if((!KEY_1) || (!KEY_2) || (!KEY_3)){
		if(!KEY_1)	enqueue (KEY_A);
		if(!KEY_2) 	enqueue (KEY_B);
		if(!KEY_3)	enqueue (KEY_C);
		//if(KEY_4)	enqueue (KEY_RED_1);
		//if(KEY_5) 	enqueue (KEY_BLACK_1);
		//if(KEY_6)	enqueue (KEY_BLACK_2);
		//if(KEY_7)	enqueue (KEY_RED_2);
	}
}
/*****************************************************************************
Name:    char    dequeue_key(void)    void enqueue (char key);
Parameters:                     
Returns:        
Description:   Input and get keys from the queue. 
*****************************************************************************/
char    dequeue_key(void)
{
char key;
	if(key_in != key_out){
		key =  key_buff[key_out];
		if(++key_out >= SIZE_OF_KEY_BUFFER)
			  key_out = 0;
		return key;
		}
	return 0;
}
void enqueue (char key)
{
	key_buff[key_in] = key;
	if(++key_in >= SIZE_OF_KEY_BUFFER)
		key_in = 0;
}
#endif
/*****************************************************************************
Name:        tick_timer_intr   
Parameters:                     
Returns:        
Description: Handler for real time interrupt   
*****************************************************************************/
//#if (USE_ROUND_ROBIN_SCH == 1) || (USE_DELAYS == 1)
void tick_timer_intr(void)
{
static char i;
#if USE_ROUND_ROBIN_SCH == 1
  	for (i=0 ; i<MAX_TASKS ; i++) {		 /* If this is a scheduled task */
    	if (GBL_task_list[i].task != NULL) {
			if (GBL_task_list[i].timer) { 
      			if (--GBL_task_list[i].timer == 0){
        			GBL_task_list[i].run = 1;
					GBL_task_list[i].timer = GBL_task_list[i].initialTimerValue;
					} } } }
#endif
#if	USE_DELAYS == 1
	if(delay_time)		// use decrement function for delays. 
		--delay_time;
#endif
}
//#endif
/*****************************************************************************
Name:           tdelay	
Parameters:     int milliseconds                
Returns:        
Description:    provide a delay time for application use.  
*****************************************************************************/
#if	USE_DELAYS == 1
void tdelay(unsigned int milliseconds)
{ 
	delay_time = milliseconds;
	while(delay_time);
}
#endif
/*****************************************************************************
Name:      		addTask    
Parameters:     void (*task)(void), int time, int priority                
Returns:        1 execute ok,  
				0 unable to load task.  priority already assigned. 
Description:    Adds task to Round Robin Scheduler. 
*****************************************************************************/
#if USE_ROUND_ROBIN_SCH == 1
int	addTask(void (*task)(void), int time, int priority)
{
unsigned int t_time;
  /* Check for valid priority */
  if (priority >= MAX_TASKS || priority < 0)
    return 0;
  /* Check to see if we are overwriting an already scheduled task */
  if (GBL_task_list[priority].task != NULL)
    return 0;
  /* Schedule the task */
  	GBL_task_list[priority].task = task;
  	GBL_task_list[priority].run  = 0;
	GBL_task_list[priority].timer = time;
  	GBL_task_list[priority].initialTimerValue = time;
  return 1;
}
/*****************************************************************************
Name:        removeTask   
Parameters:  void (* task)(void)  "task name"                   
Returns:     none   
Description: Removes task for Round Robin Scheduler.    
*****************************************************************************/
void removeTask(void (* task)(void))
{
  int i;

  for (i=0 ; i<MAX_TASKS ; i++) {
    if (GBL_task_list[i].task == task) {
      GBL_task_list[i].task = NULL;
      GBL_task_list[i].timer = 0;
      GBL_task_list[i].initialTimerValue = 0;
      GBL_task_list[i].run = 0;
      return;
    } }
}
/*****************************************************************************
Name:      init_Task_Timers     
Parameters: none                    
Returns:    none    
Description: Initializes task information structure to null and zeroes.     

*****************************************************************************/
void init_Task_Timers(void)
{
  int i;
  /* Initialize all tasks */
  for (i=0 ; i<MAX_TASKS ; i++) {
    GBL_task_list[i].initialTimerValue = 0;
    GBL_task_list[i].run = 0;
    GBL_task_list[i].timer = 0;
    GBL_task_list[i].task = NULL;
  }
}
/*****************************************************************************
Name:         Run_RR_Scheduler  
Parameters:   none                  
Returns:      none  
Description:  Starts Round Robin Scheduler.  Should be call in Main program after
			  all of the initialization code. 	   

*****************************************************************************/
void Run_RR_Scheduler(void)
{
  int i;
  GBL_run_scheduler = 1;
  /* Loop forever */
  while (1) {
    /* Check each task */
    for (i=0 ; i<MAX_TASKS ; i++) {

      /* If this is a scheduled task */
      if (GBL_task_list[i].task != NULL) {

		if (GBL_task_list[i].run == 1) {
          /* Run the task */
          GBL_task_list[i].task();
           /* Reset the task timer */
          GBL_task_list[i].run = 0;
		  break;
        } } } }
}
/*****************************************************************************
Name:         Run_Task  
Parameters:   task_number                  
Returns:      none  
Description:  Set task as specified by task_number to run.    

*****************************************************************************/
void Run_Task(int task_number)
{
	GBL_task_list[task_number].run = 1;
}
#endif
#if USE_LCD_DISPLAY	 == 1
/*****************************************************************************
Name:        	display   
Parameters:  	ln		Line number of display
			    *Buff	Buffer containing data to be written to display. 
			    		Last charactor should be null.                
Returns:        none
Description:    This function writes charactors to the LCD display.  
*****************************************************************************/
void display(int ln, far char *Buff)
{                
int i;
			if(ln == 0)	disp_ctrlw(LCD_HOME_L1);
		    if(ln == 1)	disp_ctrlw(LCD_HOME_L2);
			for (i=0; i < NUMB_CHARS_PER_LINE; i++)
                disp_dataw( Buff[i] );
}
/*****************************************************************************
Name:          	init_disp 
Parameters:     none                
Returns:        none
Description:    Intializes the LCD display. 
*****************************************************************************/
void init_disp( void )
{
        // initial ports of MCU.
        DIS_RW_DIR 	 = 1;
		DIS_RS_DIR	 = 1;
        DIS_E_DIR	 = 1;
        DISPLAY_RW	 = HIGH;
		DISPLAY_RS	 = HIGH;
		DISPLAY_E	 = LOW;
        DIS_delay( 500 );               /* lcd power on delay */
        disp_ctrlw(FUNCTION_SET);                                   /* reset sequence */
        DIS_delay(5);                                           /* lcd power on delay */
        disp_ctrlw(FUNCTION_SET);
        DIS_delay(1);                                           /* lcd power on delay */
        disp_ctrlw(LCD_CURSOR_ON);
        DIS_delay(1);
        disp_ctrlw(LCD_CLEAR);
        DIS_delay(2);
        disp_ctrlw(LCD_HOME_L1);
        DIS_delay(1);
}
/*****************************************************************************
Name:   	LCD_write        
Parameters: *buff                    
Returns:        
Description: Write data to curren cursor position.     
*****************************************************************************/
void LCD_write(far char *Buff )
{                
static int i = 0;
   	while (((*(Buff + i)) != 0x00) && (i < NUMB_CHARS_PER_LINE)){
    	disp_dataw( Buff[i] );
		i++;
		}
}
/*****************************************************************************
Name:           disp_datar
Parameters:                   
Returns:        unsigned char 
Description:    Reads data from the display  
*****************************************************************************/
unsigned char disp_datar(void)
{
    READ_DIS_DATA
    DIS_delay(1);                   /* at least 1/2 ms between normal data */
    DISPLAY_RW = HIGH; 			    /* R/W low to write (LOW) */
    DISPLAY_RS = HIGH;           	/* RS DATA SELECT (HIGH) */
    asm ("nop");
    DISPLAY_E =  HIGH;          	/* E enable chip (HIGH) */
    asm ("nop");
    DISPLAY_E = LOW;          		/* E latch data, disable chip (LOW) */
	buff.nibble.high = DISPLAY_DATA;
    DISPLAY_E = HIGH;
    asm ("nop");
   	DISPLAY_E = LOW;                /* E latch data, disable chip (LOW) */
	buff.nibble.low = DISPLAY_DATA;
    return buff.data;
}
/*****************************************************************************
Name:           disp_dataw
Parameters:     disp_data  Writes data to display               
Returns:        
Description:    Sends command to display.  
*****************************************************************************/
void disp_dataw(unsigned char disp_data)
{
    WRITE_DIS_DATA
    DIS_delay(1);                   /* at least 1/2 ms between normal data */
	buff.data = disp_data;
    DISPLAY_RW = LOW; 			    /* R/W low to write (LOW) */
    DISPLAY_RS = HIGH;           	/* RS DATA SELECT (HIGH) */
    DISPLAY_E =  HIGH;          	/* E enable chip (HIGH) */
	DISPLAY_DATA = buff.nibble.high;
    asm ("nop");
    DISPLAY_E = LOW;          		/* E latch data, disable chip (LOW) */
    DISPLAY_E = HIGH;
	DISPLAY_DATA = buff.nibble.low;
	DISPLAY_E = LOW;                /* E latch data, disable chip (LOW) */
}
/*****************************************************************************
Name:            disp_ctrlw
Parameters:      disp_ctrl  Command to send to LCD display, See display.h for
							commands               
Returns:        
Description:     Writes commands to the display.  
*****************************************************************************/
void disp_ctrlw(unsigned char disp_ctrl)
{
    WRITE_DIS_DATA
    DIS_delay(1);                   /* at least 1/2 ms between normal data */
	buff.data = disp_ctrl;
    DISPLAY_RW = LOW;          		/* R/W low to write (LOW) */
    DISPLAY_RS = LOW;          		/* RS CONTROL SELECT (LOW) */
    DISPLAY_E = HIGH;               /* E enable chip (HIGH) */
    DISPLAY_DATA = buff.nibble.high;       /* place data on latch */
    asm ("nop");
    DISPLAY_E = LOW;                /* E latch data, disable chip (LOW) */
    DISPLAY_E = HIGH;
	DISPLAY_DATA = buff.nibble.low;
	DISPLAY_E = LOW;                /* E latch data, disable chip (LOW) */
}
/*****************************************************************************
Name:          DIS_delay 
Parameters:    milli_secs   Delay time in milli-seconds.                   
Returns:        
Description:   Program delay for sending commands to LCD display.   
*****************************************************************************/
void DIS_delay(int milli_secs)
{
int i, j, delay;
	if(cm22 == 1)
		delay = 5;	  // ring-osc
	else 
		delay = 1000;
	for (j = 1; j <= milli_secs; j++ ){
    	for (i = 1; i <= delay; i++);	   // Adjust for MCU opertional speed. 
        }
}

#endif
/* end of file */