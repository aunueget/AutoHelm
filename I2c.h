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
*                                         HARDWARE DRIVER
*
*                                  Hitachi HM55B digital compass
*
*                                             with the
*
*                                      Luminary Micro LM3S2965
*
* Filename      : hm55b.h
* Version       : V1.00
* Programmer(s) : EHS
*                 BAN (adapted for LM3S2965)
*********************************************************************************************************
*/

#ifndef HM55B_H
#define HM55B_H

/*
*********************************************************************************************************
*                                         CONSTANTS
*********************************************************************************************************
*/

#define  HM55B_ERR_NONE         (0)
#define  HM55B_ERR_BUSY         (1)
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
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

extern void        HM55B_Init(void);
extern  CPU_INT08U  readByte(CPU_INT16U  *var, CPU_INT08U bits);         
extern  CPU_INT08U  writeByte (CPU_INT08U *var);
extern void			issueStart(void);
extern void			issueStop(void);

#endif                           /* End of file      */
