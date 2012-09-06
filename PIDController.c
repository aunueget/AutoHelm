

#include <stdlib.h>
#include "10sk.h"
#include "Globals.h"
#include "PIDController.h"


pidCon PID;
int pidPrior;
int pidTaskTime;



void initPID(void){
	pidPrior=1;
	pidTaskTime=100;
	//init PID variables
	PID.previous_error=0;  //PID error variable
	PID.ivar=0;//PID intral variable
	PID.dvar=0;//
	PID.Kp=12;
	PID.Ki=8;//.00001;
	PID.Kd=25;
	PID.out=0;
	PID.runTime=0;
	PID.KdCount=0;
	PID.dterm=0;
//	PID.settleTime=5;
	//kiZeros=4;
	//end init PID variables


}
/*****************************************************************************
Name:         AD_sample_task 
Parameters:                     
Returns:        
Description:  calculates the pidOutput

*****************************************************************************/
void modPID_task(void)
{
	int error=0;
	if(degreeDifferance(1,heading.current,heading.desired)>=allowedTolerance){
		if(useTilt){
			error=degreeDifferance(0,heading.desiredTilt,heading.tilt);
			if(++PID.KdCount>3){
				PID.dterm=(degreeDifferance(0,heading.tilt,PID.dvar))/3.0;
				PID.dvar=heading.tilt;
				PID.KdCount=0;
			}
		}
		else{
			error=degreeDifferance(0,heading.desired,heading.current);
			if(++PID.KdCount>3){
				PID.dterm=(degreeDifferance(0,heading.current,PID.dvar))/3.0;
				PID.dvar=heading.current;
				PID.KdCount=0;
			}
		}
		if((PID.ivar>0&&error>0)||(PID.ivar<0&&error<0)){
			PID.ivar = PID.ivar + error;
		}
		else{
			PID.ivar=error;
		}
		PID.previous_error = error;
//		if(PID.settleTime--<0){
			PID.out=((PID.Kp/10.0)*error) + (((PID.Ki/10.0)/10.0)*PID.ivar) - (((PID.Kd*10.0)/10.0)*PID.dterm);
			// PID.settleTime=-2;
		// }
		// else{
			// PID.out=((PID.Kp/10.0)*error)+ (((PID.Ki/10.0)/10.0)*PID.ivar);
		// }
		if((int)abs(PID.out)>100){
			PID.runTime=110;//11;
		}
		else{
			PID.runTime=abs(PID.out);//((abs(PID.out))/100)*9;
		}
	}
}