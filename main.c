/*********************************************************************************
*                                                                                
*   File Name:   main.c                                                                
*                                                                                
*   Content:     Contains main loop for demo code                                                                
********************************************************************************** 
*================================================================================*
*   $Log: main.c,v $
*   Revision 1.2  2002-06-07 14:00:18-04  bembry
*   Fixed flicker problem.  Chang Temp conversion equation fixes problem at "0" crossover point.
*================================================================================*/

#include "10sk.h"		/* SFR register definition */
#include "Globals.h"
#include "delayTimer.h" /* delay timer for compass I2C readings*/
//#include "compass.h"  //analog compass andrew mcknight
#include "MenuTask.h"
#include "PIDController.h"
#include "FollowTask.h"
#include "DisplayTask.h"
#include "MagAcc.h"		//digital compass revised andrew mcknight

//motor controls are in interupts.c

int displayTaskTime;
int displayTaskPrior;

void initDisplayTask();
void displayCurrent();

/*****************************************************************************
Name:		main
Parameters:	None
Returns:	None 
Description: Initializes the system and then responds to user actions.
*****************************************************************************/
void main()
{

	/*** setup input for shaft extended all ,shaft in all ****/
	pd4_2=0;//shaft in all input
	pd4_3=0;// shaft out all input
	/*** setup output move shaft in, move shaft out ****/
	pd4_0=1;//move shaft in
	pd4_1=1;//move shaft out               
	/** setup led ouput ***/
	pd4_4=1;
	moveCount=0;
	motorRunning=0;
	allowedTolerance=0;//degrees + or minus of the heading on start

  //end of menu prep**********************************************
    init_BSP();     // Intialize Board Support Package.
    disp_ctrlw(0x78); // write CGRAM address pointer 
    for (key=0; key <8; key++)   // degree symbole is 0x08 hex.  
        disp_dataw(deg_S[key]);  // Write degree symbole to LCD's CGRAM area.       
	//initialize everything
	initInterupts();
	initPID();
	initMenuTask();
	initFollowTask();
	initDisplayTask();
	initMagAcc();

	//intro screen
	display(0,"AUTOHELM");
	display(1," < > OK ");
	
    //addTask(display_task, 30, 1);
    addTask(menuTask, 35, 3);
	//addTask(shaftDelayToggle_task,1,2);

    Run_RR_Scheduler();
}





