/*********************************************************************************
*																				 
*	File Name: convert_temp.h                                          						 
*                                                                  				 
*	Content:   header file for temperature conversions.                  												 
**********************************************************************************                                                                 				 
*	Copyright (c) 2002 Mitsubishi Electric and Electronics USA, Inc.             *    
*	All rights reserved															 *
**********************************************************************************
*	The software supplied by Mitsubishi Electric and Electronics USA, Inc. 		 *
*	is intended and supplied for use on Mitsubishi Electric  products. 			 *
*	This software is owned by Mitsubishi Electric and Electronics USA, Inc.  	 *
*	or Mitsubishi Electric Corporation and is protected under applicable 		 *
*	copyright laws. All rights are reserved. 									 *
*									 											 * 																				 *
*	THIS SOFTWARE IS PROVIDED "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED 	 *
*	OR STATUTORY, INCLUDING BUT NOT LIMITED TO IMPLIED WARRANTIES OF 			 *
*	MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. *
*	MITSUBISHI ELECTRIC AND ELECTRONICS USA, INC. AND MITSUBISHI ELECTRIC 		 *
*	CORPORATION RESERVE THE RIGHT, WITHOUT NOTICE, TO MAKE CHANGES TO THIS 		 *
*	SOFTWARE. NEITHER MITSUBISHI ELECTRIC AND ELECTRONICS USA, INC. NOR 		 *
*   MITSUBISHI ELECTRIC CORPORATION SHALL, IN ANY CIRCUMSTANCES, BE LIABLE 		 *
*	FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES FOR ANY REASON WHATSOEVER  *
*	ARISING OUT OF THE USE OR APPLICATION OF THIS SOFTWARE.	 					 *
*                                                               				 *
*================================================================================*
*	$Log: convert_temp.h,v $
*	Revision 1.2  2002-06-07 14:00:18-04  bembry
*	Fixed flicker problem.  Chang Temp conversion equation fixes problem at "0" crossover point.
*
*================================================================================*/
extern float AD_input_to_deg_F(unsigned int x);
extern float Convert_F_to_C(float x);
