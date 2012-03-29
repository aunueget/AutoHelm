
#include "10sk.h"
#include "Globals.h"
#include "PIDController.h"
#include "Interupts.h"



void initInterupts(void){
	 /*** enable electric motor one-shot start interupt.****/   /*** enable 32K clcok for real time clock.****/
	// prc0 = 1;       // Enable writes to clock control register.
	// cm03 = 1;       // Xcin, Xcout high drive mode  
	// cm04 = 1;       // Enable Xcin, Xcout ports 
	// cm2 = 0x03;      // Enable OSC STOPPED detection 
	// prc0 = 0;       // Disable writes to clock control register. 
	// t1ck1 = 0; t1ck0 = 1;  // Set Timer 1 count source to 1/8
	// pre1 = 100;       // Load prescaler with 1
	// t1 = 82;       // load t1 with 4  2 x 5 = 10 :// 32.768 KHz / 32 / 10 = 102.4 times a second = 10 msec
	// DISABLE_INTS
	// t1ic = 0x06; 	// timer 1 underflow interrut.  (S4). 
	// ENABLE_INTS 
	  // tcss = SRC_SEL;  //  timers X, Y, Z set to 16MHz divide by 8 
   // prex = 99;      // 16MHz xtal, divide by 8, times 10,000 counts-> 5msec interrrupts.
   // tx = 99;        // so set prescaler and timer to 100-1
   // prey = 99;      // 16MHz xtal, divide by 8, times 5000 counts-> 2.5msec interrrupts.
   // typr = 49;        
   // prez = 99;      // 16MHz xtal, divide by 8, times 2500 counts-> 1,25msec interrrupts.
   // tzpr = 24;        

	txck1 = 0; txck0 = 1;      // Set Timer X source clock to "/8"
    prex = 99;     // 16MHz xtal, divide by 8, times 10,000 counts-> 5msec interrrupts.
    tx = 99;        // load timer x with 82. 
	DISABLE_INTS
	txic = 0x06;	// Timer X interrupt request control register.   
	ENABLE_INTS 
	//txs = 1;		// enable timer X

	/*** enable one-shot motor kill interupt.****/
	tzmod0 = 0;      // Set Timer Z timer mode to timer mode
	tzmod1 = 0;		// Set Timer Z timer mode 
	tzck1 = 0; tzck0 = 1;     //16Mhz divide by 8 
	prez = 99;		// load Z prescaller with 99 = 1/10ms
	tzpr = 9;		//load Z primary with 9 x 99 = 1 milliseconds
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
	tzpr = (unsigned char) PID.runTime;	
	if(!p4_2&&motorRunning<0&&PID.runTime>0){
		p4_1=0;//set move out to off
		p4_0=1;//set move in to on
		if(PID.runTime<9){
			tzs=1;
		}
	}
	else if(!p4_3&&motorRunning>0&&PID.runTime>0){
		p4_0=0;//set move in to off
		p4_1=1;//set move out to on
		if(PID.runTime<9){
			tzs=1;
		}
	}
	else{
		p4_1=0;//set move out to off
		p4_0=0;//set move in to off
	}
}
void motorKill(void){
		p4_1=0;//set move out to off
		p4_0=0;//set move in to off
		tzs=0;
}