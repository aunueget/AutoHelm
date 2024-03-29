/*
*********************************************************************************************************
*                                              EXAMPLE CODE
*
*                               (c) Copyright 2007; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*               Knowledge of the source code may NOT be used to develop a similar product.
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                         software I2C controller
*
* Filename      : MitsuI2C.h
* Version       : V1.00
* Programmer(s) : EHS
*                 BAN (adapted for LM3S2965)
*********************************************************************************************************
*/

#ifndef MitsuI2C_H
#define MitsuI2C_H

/*
*********************************************************************************************************
*                                         CONSTANTS
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                         TYPES DEFINED
*********************************************************************************************************
*/
#define CPU_FP32 	float
#define CPU_INT08U 	unsigned char
#define CPU_INT08S 	char
#define CPU_INT16U 	unsigned short int
#define CPU_INT16S 	short int
#define CPU_INT32U 	unsigned int
#define CPU_INT32S 	int
/*
*********************************************************************************************************
*                                         variables
*********************************************************************************************************
*/
extern int problemI2C;
/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

extern void        	MitsuI2C_Init(void);
extern CPU_INT16S 	MitsuI2C_getHeading(void);
extern void 		MitsuI2C_testPullUp(void);
extern CPU_INT32S	MitsuI2C_calibrate(void);
extern int MitsuI2C_beginTransmission(CPU_INT08U address);
extern int MitsuI2C_send(CPU_INT08U number);
extern void MitsuI2C_endTransmission();
extern int MitsuI2C_requestFrom(CPU_INT08U address, int count);
extern CPU_INT08U MitsuI2C_receive(int pos);
extern int MitsuI2C_available();
extern int problemOccured();
#endif                           /* End of file      */
