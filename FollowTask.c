
#include "10sk.h"
#include "Globals.h"
#include "PIDController.h"
#include "FollowTask.h"


int followTaskTime;
int followTaskPrior;
int displayCount;
//int delayForCompassSmooth;

void initFollowTask(){
	followTaskTime=100;
	followTaskPrior=4;
	displayCount=0;
//	delayForCompassSmooth=5;
}


/**********************************************************************************
Name:		  followHeading
Parameters:
Returns:
Description:  sets the lines to high and low to move the motor in order to follow the heading
**************************************************************************/

void followHeading_task(){
	//char temp0Str[9]="\0";
	//char temp1Str[9]="\0";
	setCompass(getCompassReading(1));

	if(degreeDifferance(1,heading.current,heading.desired)>=allowedTolerance){		
		if(!p4_2&&PID.out>0){
			if(motorRunning>0){
				txs=0;
				motorRunning=0;
				p4_1=0;//set move out to off
				tdelay(50);
			}
			motorRunning=-1;
			if(!txs){
				txs=1;
			}
			// if(displayCount==0){
				// toStr(temp1Str,heading.desired,9);
				// display(1,temp1Str);
			// }
		}
		else if(!p4_3&&PID.out<0){
			if(motorRunning<0){
				txs=0;
				motorRunning=0;
				p4_0=0;//set move in to off
				tdelay(50);
			}
			motorRunning=1;
			if(!txs){
				txs=1;
			}
			// if(displayCount==0){
				// toStr(temp1Str,heading.desired,8);
				// display(1,temp1Str);
			// }
		}
	}
	else{
		motorRunning=0;
		txs=0;
		p4_1=0;//set move out to off
		p4_0=0;//set move in to off		
		tdelay(50);
	}
	// if(displayCount++>5){
		// toStr(temp0Str,heading.current,0);
		// display(0,temp0Str);
		// displayCount=0;
	// }

	check4ShaftNOut();

}
