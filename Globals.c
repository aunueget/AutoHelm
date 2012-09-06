#include <stdlib.h>
#include "Globals.h"
#include "10sk.h"
#include "MagAcc.h"
#include "PIDController.h"

int c_ticks;
int allowedTolerance;
int moveCount;
char key;
volatile int motorRunning;
int paused;
double old_value;
int useTilt=0;
int bailOutBadCompass=0;
int shaftPosition=MIDDLE;
const char deg_S[8] = {0x08,0x14,0x08,0x00,0x00,0x00,0x00,0x00};
// added object from compass.h
compass heading={0,0,0,0};

/*****************************************************************************
Name:        getCompassReading 
Parameters:        none             
Returns:        a newly read compass heading from the digital compass
Description:  returns a newly read compass heading from the digital compass   

*****************************************************************************/

void setCompass(int compassReading){
	heading.current=compassReading;
	heading.tilt=tilt;
}
void setDesired(int userSelectedDegrees){
	heading.desired=userSelectedDegrees;
	heading.desiredTilt=tilt;
}
int getCompassReading(int avg){
	double newDigitHeading;
	double old_value;
	//txs=0;
	newDigitHeading=get_digital_heading();
	//txs=1;
	//old_value=heading.current;
	newDigitHeading-=180;//flip the compass to correct digital compass position
    if (newDigitHeading < 0) newDigitHeading += 360;//correct for 0 turns to 360
	if(avg&&degreeDifferance(1,newDigitHeading,heading.current)<=7){
		if(abs(heading.current-newDigitHeading)>180){//for across 360 zero area
			//required for averaging across 360 zero area
			old_value=newDigitHeading+degreeDifferance(0,heading.current,newDigitHeading);
		}
		else{
			old_value=heading.current;
		}
		newDigitHeading=((11.0/16.0)*old_value)+(((16.0-11.0)/16.0)*newDigitHeading);
		if(newDigitHeading>360)
			newDigitHeading-=360;
		if(newDigitHeading<0){
			newDigitHeading+=360;
		}
		bailOutBadCompass=0;
	}
	else if(avg){
		newDigitHeading=(double)heading.current;
		if(bailOutBadCompass++>3){
			newDigitHeading=startCompass();
			bailOutBadCompass=0;
		}
	}
return (int)newDigitHeading;
}

//write smoothing compass for menutask before follow starts
int startCompass(){
	int i=0;
	int newReading=0;
	for(i=0;i<2;i++){
		setCompass(getCompassReading(0));
	}
	for(i=0;i<3;i++){
		setCompass(getCompassReading(1));
	}
//	PID.settleTime=5;//let the dterm and iterm get back on track before starting
	return heading.current;
}

/* if the absoluteValue is set to 0 then degreeDifferance will have a sign pos or  neg */
int degreeDifferance(int absoluteValue,int current,int desired){
	int compDiff=0;
	int accrossN=0;
	compDiff=abs(current-desired);
	if(compDiff>180){
		compDiff=abs(compDiff-360);
		accrossN=1;
	}
	if(absoluteValue || ((heading.current>heading.desired && accrossN==0) || (accrossN==1 && heading.current<heading.desired))){
		return compDiff;
	}
	else{
		return (-1*compDiff);
	}
}

void toStr(char strNum[9],int value,int menuNum){
	strNum[0]=' ';
	strNum[1]=' ';
	if(menuNum==8){
		strNum[2]='>';
	}
	else{
		strNum[2]=' ';
	}
	digits2String(value,3,strNum);
	if(menuNum!=1 ){
		strNum[6]=0x07;
	}
	else{
		strNum[6]=' ';
	}
	if(menuNum==9){
		strNum[7]='<';
	}
	else{
		strNum[7]=' ';
	}
	strNum[8]='\0';
}
void digits2String(int value,int pos,char strNum[9]){
	strNum[0+pos]=(value/100)+48;
	strNum[1+pos]=(((value%100)/10))+48;
	strNum[2+pos]=(value%10)+48;
}
void tiltToStr(char strNum[9],int value){
	strNum[0]='T';
	strNum[1]='I';
	strNum[2]='L';
	strNum[3]='T';
	strNum[4]=' ';
	digits2String(value,5,strNum);
	strNum[8]='\0';
}

void numsToStr(char strNum[9],int value1,int value2){
	digits2String(value1,0,strNum);
	strNum[3]='<';
	digits2String(value2,4,strNum);
	strNum[7]=' ';
	strNum[8]='\0';
}
void tack2Heading(int starboard){
	motorRunning=0;
	txs=0;
	p4_1=0;//set move out to off
	p4_0=0;//set move in to off		
	tdelay(50);
	if(starboard==1){
		motorRunning=1;
	}
	else{
		motorRunning=-1;
	}
	PID.runTime=130;
	txs=1;
	setCompass(getCompassReading(1));
	while(paused==0&&degreeDifferance(1,heading.current,heading.desired)>35){
		setCompass(getCompassReading(0));

		check4ShaftNOut();
	}
	
	motorRunning=0;
	txs=0;
	p4_1=0;//set move out to off
	p4_0=0;//set move in to off		
	tdelay(50);

}
void check4ShaftNOut(){
	if(p4_2){
		if(motorRunning<0){
			motorRunning=0;
		}	
		p4_0=0;
		shaftPosition=ALLIN;
	}
	else if(p4_3){
		if(motorRunning>0){
			motorRunning=0;
		}	
		p4_1=0;
		shaftPosition=ALLOUT;
	}
	else{
		shaftPosition=MIDDLE;
	}
}
