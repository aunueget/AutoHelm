


#include "10sk.h"		/* SFR register definition */
#include "Globals.h"
#include "MenuTask.h"
#include "PIDController.h"
#include "FollowTask.h"
#include "DisplayTask.h"


unsigned char sys_mode;
int selected_menu;
const char menu[8][9] = {
{" KP     "},
{" KI     "},
{" KD     "},
{"TOLERANC"},
{"TACKSTAR"},
{"TACKPORT"},
{"USETILT "},
{" PAUSED "}
};
const char num[15] = {'0','1','2','3','4','5','6','7','8','9',':','F','C',' ','.'};

void initMenuTask(){
  //menu prep*******************************************
  paused=1;
  selected_menu=0;
  sys_mode =  RUNNING;

}


/*****************************************************************************
Name:         mode_task  
Parameters:                     
Returns:        
Description:  Process key inputs and changes mode and data.    
*****************************************************************************/
void menuTask(void)
{	
	//KEY_A IS UP//KEY_B IS DOWN//KEY_C IS OK
	int i=0;
	int selected_value=0;
	char tempStr[9]="";
    int testHeading=0;
	key = dequeue_key();
    switch(sys_mode){
		case RUNNING:
			if(paused){
				if(key==KEY_C){
					paused=0;
					setDesired(startCompass());
					setCompass(heading.desired);

					addTask(displayCurrent_task, displayTaskTime, displayTaskPrior);
					prepare2Follow();
				}
				else if(key==KEY_A||key==KEY_B){
					sys_mode=MENUCHANGE;
					selected_menu=0;
				  	display(0,menu[0]);
					display(1," < > OK ");
				}
				else{
					toStr(tempStr,heading.desired,0);
					display(0,tempStr);
					display(1,menu[7]);//display paused
				}
			}
			else if(key==KEY_A){
				int newDesired=heading.desired-1;
				if(newDesired<0)
					newDesired+=360;
				setDesired(newDesired);
				
			}
			else if( key == KEY_B){
				int newDesired=heading.desired+1;
				if(newDesired>359)
					newDesired-=360;
				setDesired(newDesired);

			}
			else if(key == KEY_C){
					paused=1;//true
					p4_1=0;//set move out to off
					p4_0=0;//set move in to off
					motorRunning=0;
					txs=0;
					removeTask(followHeading_task);
					removeTask(displayCurrent_task);
					removeTask(modPID_task);
					
					sys_mode=MENUCHANGE;
					display(0,menu[selected_menu]);
					display(1," < > OK ");
			}
		break;
		case MENUCHANGE:
			switch(key){
				case KEY_A:
					selected_menu++;
					display(1," < > OK ");
				break;
				case KEY_B:
					selected_menu--;
					display(1," < > OK ");
				break;
				case KEY_C:
					sys_mode=VALUECHANGE;
					selected_value=changeVariable(selected_menu,0);
					toStr(tempStr,selected_value,selected_menu);
					display(1,tempStr);					
				break;
				
			}
		  if(selected_menu<0)
			selected_menu=6;
		  else if(selected_menu>6)
			selected_menu=0;
		display(0,menu[selected_menu]);
		break;
		case VALUECHANGE:
			switch(key){
				case KEY_A:
					selected_value=changeVariable(selected_menu,-1);
					toStr(tempStr,selected_value,selected_menu);
					display(0,menu[selected_menu]);
					display(1,tempStr);					
				break;
				case KEY_B:
					selected_value=changeVariable(selected_menu,1);
					toStr(tempStr,selected_value,selected_menu);
					display(0,menu[selected_menu]);
					display(1,tempStr);					

				break;
				case KEY_C:
					sys_mode=RUNNING;
					paused=0;
					addTask(displayCurrent_task, displayTaskTime, displayTaskPrior);
					if(selected_menu==4){
						display(1,"TACK    ");
						tack2Heading(1);//1 for starboard
					}
					else if(selected_menu==5){
						tack2Heading(0);//not 1 for port
						display(1,"TACK    ");
					}
					else{
						setDesired(startCompass());
						setCompass(heading.desired);
					}
					prepare2Follow();
				break;
			}
		break;
    }
}
void prepare2Follow(){
						//init PID variables
						PID.ivar=0;//PID intral variable
						PID.dvar=heading.current;//
						PID.dterm=0;
						PID.out=0;
//						PID.settleTime=5;
						//end init PID variables
						addTask(followHeading_task, followTaskTime, followTaskPrior);
						addTask(modPID_task, pidTaskTime,pidPrior);
						txs=1;

}
int changeVariable(int menuSelected,int changeValue){
	switch(menuSelected){
		case 0:
			PID.Kp+=(changeValue);//PID.Kp+=(changeValue);
			if(PID.Kp<0)
				PID.Kp=0;
			return PID.Kp;
		break;
		case 1:
			PID.Ki+=(changeValue);//PID.Kd+=(10*changeValue);
			if(PID.Ki<0)
				PID.Ki=0;
			return PID.Ki;
		break;
		case 2:
			PID.Kd+=(changeValue);//PID.Kd+=(10*changeValue);
			if(PID.Kd<0)
				PID.Kd=0;
			return PID.Kd;
		break;
		case 3:
			allowedTolerance+=changeValue;
			if(allowedTolerance<0)
				allowedTolerance=0;
			return allowedTolerance;
		break;
		case 4:
		case 5:
			heading.desired+=(10*changeValue);
			if(heading.desired>=360){
				heading.desired-=360;
			}
			if(heading.desired<0){
				heading.desired+=360;
			}
			return heading.desired;
		break;
		case 6:
			if(useTilt)
				useTilt=0;
			else
				useTilt=1;
			return useTilt;
		break;
			
	}
	return 0;
}
