
#include "10sk.h"
#include "Globals.h"
#include "MagAcc.h"
#include "DisplayTask.h"


void initDisplayTask(){
	displayTaskTime=300;
	displayTaskPrior=2;
}

void displayCurrent_task(){
	char temp0Str[9]="\0";
	char temp0Str2[9]="\0";
	numsToStr(temp0Str,heading.desired,heading.current);
	display(0,temp0Str);
	if(shaftPosition!=MIDDLE){
		if(shaftPosition==ALLIN){
			display(1,"HARDPORT");
		}
		else{
			display(1,"HARDSTAR");
		}
	}
	else{
		tiltToStr(temp0Str2,degreeDifferance(1,heading.tilt,heading.desiredTilt));
		display(1,temp0Str2);
	}

}
