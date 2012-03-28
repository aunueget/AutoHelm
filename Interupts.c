

#include "Globals.h"




void initInterupts(void){
	 /*** enable electric motor one-shot start interupt.****/   /*** enable 32K clcok for real time clock.****/
	prc0 = 1;       // Enable writes to clock control register.
	cm03 = 1;       // Xcin, Xcout high drive mode  
	cm04 = 1;       // Enable Xcin, Xcout ports 
	cm2 = 0x03;      // Enable OSC STOPPED detection 
	prc0 = 0;       // Disable writes to clock control register. 
	t1ck0 = 1; t1ck1 = 1; // Set Timer 1 count source to 1/32
	pre1 = 2;       // Load prescaler with 1
	t1 = 2;       // load t1 with 4  2 x 5 = 10 :// 32.768 KHz / 32 / 10 = 102.4 times a second = 10 msec
	DISABLE_INTS
	t1ic = 0x06; 	// timer 1 underflow interrut.  (S4). 
	ENABLE_INTS 

	/*** enable one-shot motor kill interupt.****/
	tzmod0 = 0;      // Set Timer Z timer mode to programmable wait one-shot
	tzmod1 = 1;		// Set Timer Z timer mode 
	tzck0 = 1;     //divide by 32 = 1 milli second seconds long period
	tzck1 = 1;		//divide by 32 = 1 milli second seconds long period
	tzwc = 1;
	prez = 0;		// load Z prescaller with 0 = 1ms
	tzpr = 1;		//load Z primary with 5 = 5 x 1 milli secs = 5 milliseconds
	tzpum0 = 0;
	//tzpum1 = 0; 
	DISABLE_INTS
	tzic = 0x02;	// Timer Z interrupt request control register.   
	ENABLE_INTS 
	
	
	// fifty_ticks=49;
	// total_ticks=0;
    tymod0 = 0;      // Set Timer Y timer mode
	tyck0 = 0;     //divide by 8 = 500 nano seconds long period
    tyck1 = 1;
	tywc = 0;
    prey = 20;     // load Y prescaller with 20 = 20 x 500ns= 10 micro seconds
	typr = 2;		//load Y primary with 2 = 2 x 10 micro secs = 20 microseconds
	DISABLE_INTS
	tyic = 0x03;	// Timer Y interrupt request control register.   
	ENABLE_INTS 
}


/*****************************************************************************
Name:      INTERRUPT HANDLER, rtc_ticker.  
Parameters:    none                   
Returns:       none 
Description:   Decrements c_ticks for a count down    

*****************************************************************************/
void delay_ticker(void)
{
	if(c_ticks)
		c_ticks--;
	// if(fifty_ticks){
		// fifty_ticks--;
	// }
	// else{
		// total_ticks++;
		// fifty_ticks=49;
	// }
}








/*****************************************************************************
Name:           shaftDelayToggle      
Parameters:     none                     
Returns:        none
Description:    this helps create an intermitent shaft movement by waiting the 
					aloted moveDelay time with the shaft moving and then
					spending the same moveDelay time without moving the shaft
*****************************************************************************/
void motorToggle(){
	DISABLE_INTS
	tzpr = (unsigned char) PID.runTime;	
	tzs=1;
	if(!p4_2&&motorRunning<0&&PID.runTime>0){
		p4_1=0;//set move out to off
		p4_0=1;//set move in to on
		if(PID.runTime<9){
			tzos=1;
		}
	}
	else if(!p4_3&&motorRunning>0&&PID.runTime>0){
		p4_0=0;//set move in to off
		p4_1=1;//set move out to on
		if(PID.runTime<9){
			tzos=1;
		}
	}
	else{
		p4_1=0;//set move out to off
		p4_0=0;//set move in to off
	}
	ENABLE_INTS 
}
void motorKill(void){
		p4_1=0;//set move out to off
		p4_0=0;//set move in to off
}