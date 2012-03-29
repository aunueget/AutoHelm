
#include "10sk.h"
#include "Globals.h"
#include "PIDController.h"
#include "FollowTask.h"


int followTaskTime;
int followTaskPrior;

void initFollowTask(){
	followTaskTime=100;
	followTaskPrior=4;
}


/**********************************************************************************
Name:		  followHeading
Parameters:
Returns:
Description:  sets the lines to high and low to move the motor in order to follow the heading
**************************************************************************/

void followHeading_task(){
	char temp0Str[9]="\0";
	char temp1Str[9]="\0";
	set_compass(&heading,getCompassReading(1));
	if(degreeDifferance(1,heading.current,heading.desired)>allowedTolerance){
		toStr(temp0Str,heading.current,0);
		display(0,temp0Str);
		if(!p4_2&&PID.out>0){
			if(motorRunning>0){
				motorRunning=0;
				p4_1=0;//set move out to off
				tdelay(50);
			}
			motorRunning=-1;
			toStr(temp1Str,heading.desired,9);
			display(1,temp1Str);
		}
		if(!p4_3&&PID.out<0){
			if(motorRunning<0){
				motorRunning=0;
				p4_0=0;//set move in to off
				tdelay(50);
			}
			motorRunning=1;
			toStr(temp1Str,heading.desired,8);
			display(1,temp1Str);
		}
	}
	else{
		motorRunning=0;
		p4_1=0;//set move out to off
		p4_0=0;//set move in to off		
		tdelay(50);
		toStr(temp0Str,heading.current,0);
		display(0,temp0Str);
	}
	if(p4_2){
		p4_0=0;
		display(1,"SHAFT IN");
	}
	else if(p4_3){
		p4_1=0;
		display(1,"SHAFTOUT");
	}
}
