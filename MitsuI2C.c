
/*
*********************************************************************************************************
*
*                                         I2c DRIVER For Mitsubishi micro control
*
* Filename      : MitsuI2C.h
* Version       : V1.00
* Programmer(s) : Andrew McKnight
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include <math.h>
#include "10sk.h"		/* SFR register definition */
#include "MitsuI2C.h"
#include "delayTimer.h"

/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                            LOCAL MACRO'S
*********************************************************************************************************
*/
// #define  SDA_SET_LOW()      p1_2=0
// #define  SDA_READ()         p1_2      
// #define	 SDA_SET_RX()		pd1_2=0
// #define	 SDA_SET_TX()		pd1_2=1
  // /* Set the clock line low                                   */
// #define  SCL_SET_CLK_LOW()		p1_3=0
// #define  SCL_READ()             p1_3  
// #define	 SCL_SET_TX()			pd1_3=1
// #define	 SCL_SET_RX()			pd1_3=0
#define  SDA_SET_LOW()      p0_6=0
#define  SDA_READ()         p0_6      
#define	 SDA_SET_RX()		prc2=1; pd0_6=0
#define	 SDA_SET_TX()		prc2=1; pd0_6=1
  /* Set the clock line low                                   */
#define  SCL_SET_CLK_LOW()		p0_7=0
#define  SCL_READ()             p0_7  
#define	 SCL_SET_TX()			bailSCLrx=0; prc2=1; pd0_7=1
#define	 SCL_SET_RX()			do{prc2=1; pd0_7=0; bailSCLrx++; waitOne();}while(!SCL_READ()||bailSCLrx>200)	
    


/*
*********************************************************************************************************
*                                       LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/
CPU_INT08U data[12];
int dataCount=0;
int dataPos=0;
int bailSCLrx=0;
/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void 		waitOne(void);
static  CPU_INT08U  readByte (CPU_INT08S ack);         
static  CPU_INT08U  writeByte (CPU_INT08U var);
static  void		issueStart(void);
static  void		issueStop(void);
static CPU_INT08U acknowledge(void);
static void waitTicks(int count);
/*
*********************************************************************************************************
*                                       MitsuI2C_Init()
*
* Description : This function intializes the I/O necessary to communicate with the MitsuI2C
*
* Argument(s) : None.
*
* Return(s)   : None.
*
* Notes(s)    : None.
*********************************************************************************************************
*/

void MitsuI2C_Init (void)
{ 
// #define  SDA_SET_LOW()      p1_2=0
// #define  SDA_READ()         p1_2      
// #define	 SDA_SET_RX()		pd1_2=0
// #define	 SDA_SET_TX()		pd1_2=1
  // /* Set the clock line low                                   */
// #define  SCL_SET_CLK_LOW()		p1_3=0
// #define  SCL_READ()             p1_3  
// #define	 SCL_SET_TX()			pd1_3=1
// #define	 SCL_SET_RX()			pd1_3=0

	SCL_SET_RX();
	SDA_SET_RX();
	//MitsuI2C_testPullUp();
	//issueStart();
	//issueStop();
}
/*
*********************************************************************************************************
*                                           issueStart()
*
* Description : This is a test to be sure that when you set the SDA pin or the SCL pin to read that the
*				resistor pulls the pin to high
*
*********************************************************************************************************
*/

void MitsuI2C_testPullUp(void){
	SCL_SET_TX();
	SCL_SET_CLK_LOW();
	SCL_SET_RX();
	SDA_SET_TX();
	SDA_SET_LOW();
	SDA_SET_RX();

}
/*
*********************************************************************************************************
*                                           issueStart()
*
* Description : This is an I2c protocal method that sends the start message to the slave device by 
*				setting sda low while the clock is high
*
*********************************************************************************************************
*/


static  void issueStart(void){
	SDA_SET_RX();
	waitOne();
	SCL_SET_RX();
	waitOne();
	SDA_SET_TX();
	SDA_SET_LOW();
	waitOne();
	SCL_SET_TX();
	SCL_SET_CLK_LOW();
	waitOne();
}
/*
*********************************************************************************************************
*                                           issueStop()
*
* Description : This is an I2c protocal method that sends the stop message to the slave device by 
*				setting sda high while the clock is high
*
*********************************************************************************************************
*/

static  void		issueStop(void){
	waitOne();
	SDA_SET_TX();
	SDA_SET_LOW();
	waitOne();
	SCL_SET_RX();
	waitOne();
	SDA_SET_RX();
	waitOne();
}
int MitsuI2C_calibrate(void){
	issueStart();				//issue start
	if(!writeByte(0x42)){  			//send write register
		issueStop();
		return 4800;
	}
	if(!writeByte('C')){              // The Calibrate Start
		issueStop();
		return 4900;
	}
	issueStop();				//issue stop command
	tdelay(20000);             // 500 x 20 micro seconds = wait 10 milli seconds
	// after this command.  Using 10ms just makes it safe
	// Read the 2 heading bytes, MSB first
	// The resulting 16bit word is the compass heading in 10th's of a degree
	// For example: a heading of 1345 would be 134.5 degrees
	issueStart();
	if(!writeByte(0x42)){  			//send write register
		issueStop();
		return 4600;
	}
	if(!writeByte('E')){              // Calibrate stop
		issueStop();
		return 4700;
	}
	issueStop();//issue stop
	return 0;
}
/*
*********************************************************************************************************
*                                           getHeading()
*
* Description : This writes the command 'A' to the MitsuI2C digital compass and reads back
*				the current heading of the compass
*
*				
* Return      : a 16 bit Signed integer that represents the degrees the MitsuI2C compass is currently pointed
				or 0 if MitsuI2C compass did not acknowledge write command
*********************************************************************************************************
*/

CPU_INT16S MitsuI2C_getHeading(){
	CPU_INT16S headingValue;
	CPU_INT08U headingData[2];
	CPU_INT16S i = 0;
	issueStart();				//issue start
	if(!writeByte(0x42)){  			//send write register
		issueStop();
		return 4100;
	}
	if(!writeByte('A')){              // The "Get Data" command
		issueStop();
		return 4200;
	}
	issueStop();				//issue stop command
	waitTicks(500);             // 500 x 20 micro seconds = wait 10 milli seconds
	// after this command.  Using 10ms just makes it safe
	// Read the 2 heading bytes, MSB first
	// The resulting 16bit word is the compass heading in 10th's of a degree
	// For example: a heading of 1345 would be 134.5 degrees
	issueStart();
	if(!writeByte(0x43)){ 	       // Request the 2 byte heading (MSB comes first)
		issueStop();
		return 4300;
	}
	for(i=0; i < 2;i++)
	{ 
		headingData[i] = readByte(1);
		if(i==0){
			if(!acknowledge()){//if slave failed to receive
				//return 4400;
			}
		}	
	}
	issueStop();//issue stop
	headingValue = headingData[0]*256 + headingData[1];// put to bytes together in a 16 bit number
	return headingValue;
}

/*
*********************************************************************************************************
*                                           readByte()
*
* Description : This is an I2c protocal 8 bit read function.  reads MSB first out of the I2c slave
*				an 8 bit number and returns it as an unsigned char
*
* Argument(s) : ack    set true or 1 if you want to send the acknowledge low on sda to the slave device
*				
* Return      : a 8 bit unsigned number read from the slave I2c 
*********************************************************************************************************
*/

static  CPU_INT08U  readByte (CPU_INT08S ack)
{
	int bailOut=0;
	CPU_INT08S x, d=0;
	SDA_SET_RX();
	waitOne();
	for(x=0; x<8; x++) {
		d <<= 1;
		SCL_SET_RX();
		while(!SCL_READ()){
			waitOne();
			if(bailOut++>200){/* Wait for 1/2 of a clock period                           */    
				return 0;
			}
		}
		if(SDA_READ()){ 
			d |= 1;
		}
		waitOne();
		SCL_SET_TX();
		SCL_SET_CLK_LOW();
		waitOne();
	} 
	if(ack){
		waitOne();
		SDA_SET_TX();
		SDA_SET_LOW();
	}
	else{
		SDA_SET_RX();
	}
	waitOne();
	SCL_SET_RX();
	waitTicks(50);             // send (N)ACK bit
	SCL_SET_TX();
	SCL_SET_CLK_LOW();
	waitOne();
	return d;       
}

/*
*********************************************************************************************************
*                                           writeByte()
*
* Description : This is an I2c protocal 8 bit write function.  The var parameter is an 8 bit char
*				to be written MSB first into the slave I2c device
*
* Argument(s) : var           unsigned  8 bit char to be written to slave I2c device
*
*********************************************************************************************************
*/
         
static  CPU_INT08U  writeByte (CPU_INT08U var)
{
    CPU_INT08U  i;
	int bailOut=0;
	// SDA_SET_TX();                   
    // SCL_SET_CLK_LOW();                                                          /* Init clock. MSBFIRST, clock idles low                    */
	// waitOne();
    for (i = 8; i > 0; i--) {											/* Begin shifting out data highest bit first                */
		SDA_SET_TX();
		if ((var & (1 << (i - 1))) > 0) {                              /* If the next bit to shift is a 1                          */
            SDA_SET_RX();                                             /* Set the Tx pin high                                      */   
        } else {
            SDA_SET_LOW();                                              /* Next bit is a 0, set the Tx pin low                      */
        }
		waitOne();
        SCL_SET_RX();
		while(!SCL_READ()){               /* Send the high part of the clk pulse (clock the data in)  */
			waitOne();
			if(bailOut++>200){/* Wait for 1/2 of a clock period                           */    
				return 0;
			}
		}		
		SCL_SET_TX();
        SCL_SET_CLK_LOW();                                                      /* Send the low part of the clock pulse (clock idles low)   */
        waitOne();												/* Wait for 1/2 of a clock period (clock period now over)   */
	}
	if(!acknowledge()){//if slave failed to receive
		return 0;
	}
    return 1;
}
/*
*********************************************************************************************************
*                                           acknowledge()
*
* Description : This is an I2c protoc0l check for acknowledge after writing to an I2c slave device
*				after the 8th bit is written to the slave device the slave should pull the 
*				SDA value low, acknowledging that it received the 8 bits
*
* Return :   This function returns 1 or true if the Slave Acknoledge the 8 bit write or 0 or false if slave device did not Acknowledge
*
*********************************************************************************************************
*/

static CPU_INT08U acknowledge(void){
	SDA_SET_RX();
	waitOne();
	SCL_SET_RX();
	waitOne();
	if(SDA_READ()){
		SCL_SET_TX();
		SCL_SET_CLK_LOW();	
		waitOne();
		return 0;
	}
	SCL_SET_TX();
	SCL_SET_CLK_LOW();
	waitOne();
	return 1;
}
/*
*********************************************************************************************************
*                                           waitOne()
*
* Description : This is a delay that is set for the specific slave device used in this case calls
*				a timer in delayTimer.h that waits one 20 micro second period
*
*
*********************************************************************************************************
*/
static void waitOne(void){
	wait_ticks(1);
}
/*
*********************************************************************************************************
*                                           waitTicks()
*
* Description : This is a delay that will count down the number of the count x 20 micro second period
				delay   =     count    x     20 micro seconds
*
*
*********************************************************************************************************
*/
static void waitTicks(int count){
		wait_ticks(count);
}
int MitsuI2C_beginTransmission(CPU_INT08U address){
	issueStart();
	if(!writeByte ((CPU_INT08U) address)){ 	       // send slave address
		issueStop();
		return 0;
	}
	return 1;
}
int MitsuI2C_send(CPU_INT08U number){
	if(!writeByte ((CPU_INT08U) number)){ 	       // send slave address
		issueStop();
		return 0;
	}
	return 1;
}
void MitsuI2C_endTransmission(){
	issueStop();//issue stop
}

int MitsuI2C_requestFrom(CPU_INT08U address, int count){
	int i=0;
	dataCount=0;
	dataPos=0;
	if(!MitsuI2C_beginTransmission(address+1)){
		return 0;
	}
	for(i=0; i < count;i++)
	{ 
		if(i==count-1){//last byte to read
			data[i] = readByte(0);
		}
		else{
			data[i] = readByte(1);
		}
		dataCount++;	
	}
	issueStop();//issue stop
	return 1;
}
int MitsuI2C_available(){
	return dataCount;
}
CPU_INT08U MitsuI2C_receive(){
	if(dataPos>=6){
		return 0;
	}
	return data[dataPos++];

}



 