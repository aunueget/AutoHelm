

#include "Globals.h"
#include "10sk.h"		/* SFR register definition */

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
					set_desired(&heading,getCompassReading(0));
					//init PID variables
					PID.ivar=0;//PID intral variable
					PID.dvar=0;//
					PID.out=0;
					//end init PID variables
					addTask(followHeading_task, followTaskTime, followTaskPrior);
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
					display(1,menu[4]);//display paused
				}
			}
			else if(key==KEY_A || key == KEY_B || key == KEY_C){
					paused=1;//true
					toStr(tempStr,heading.desired,0);
					display(0,tempStr);
					display(1,menu[4]);//display paused
					p4_1=0;//set move out to off
					p4_0=0;//set move in to off
					DISABLE_INTS
					motorRunning=0;
					ENABLE_INTS
					removeTask(followHeading_task);
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
			selected_menu=3;
		  else if(selected_menu>3)
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
						set_desired(&heading,getCompassReading(0));
						//init PID variables
						PID.ivar=0;//PID intral variable
						PID.dvar=0;//
						PID.out=0;
						//end init PID variables
						addTask(followHeading_task, followTaskTime, followTaskPrior);
				break;
			}
		break;
    }
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
			if(changeValue>0){
				PID.Ki+=.01;//=10;
				//kiZeros++;
			}
			else if(changeValue<0){
				PID.Ki -=.01;
				//kiZeros--;
			}
			if(PID.Ki<0){
			//kiZeros<0){
				PID.Ki=0;
				//kiZeros=0;
			}
			return PID.Ki*100;//kiZeros;
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
	}
	return 0;
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
	strNum[3]=(value/100)+48;
	strNum[4]=(((value%100)/10))+48;
	strNum[5]=(value%10)+48;
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