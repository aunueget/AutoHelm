



#include "Globals.h"

void initPID(void){
	//init PID variables
	PID.previous_error=0;  //PID error variable
	PID.ivar=0;//PID intral variable
	PID.dvar=0;//
	PID.Kp=50;
	PID.Ki=.60;//.00001;
	PID.Kd=50;
	PID.out=0;
	PID.runTime=0;
	kiZeros=4;
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
	int dterm=0;
	if(degreeDifferance(1,heading.current,heading.desired)>allowedTolerance){
		error=modPID(degreeDifferance(0,heading.desired,heading.current));
		dterm=degreeDifferance(0,heading.current,PID.dvar);
		PID.dvar=heading.current;
		PID.ivar = PID.ivar + error;
		if(PID.ivar>100){
			PID.ivar=100;
		}
		if(PID.ivar<(-100)){
			PID.ivar=-100;
		}
		PID.previous_error = error;
		PID.out=((PID.Kp/10.0)*error) + ((PID.Ki/10.0)*PID.ivar) - ((PID.Kd/10.0)*dterm);
		if((int)abs(PID.out)>100){
			DISABLE_INTS
			PID.runTime=11;
			ENABLE_INTS 
		}
		else{
			DISABLE_INTS
			PID.runTime=((abs(PID.out))/100)*9;
			ENABLE_INTS 
		}
	}
}