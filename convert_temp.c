/*********************************************************************************
*                                                                                
*   File Name:   convert_temp.c                                                                
*                                                                                
*   Content:     Converts inputs from AD to temperature.                                                                 
**********************************************************************************                                                                               
*   Copyright (c) 2002 Mitsubishi Electric and Electronics USA, Inc.             *    
*   All rights reserved                                                          *
**********************************************************************************
*   The software supplied by Mitsubishi Electric and Electronics USA, Inc.       *
*   is intended and supplied for use on Mitsubishi Electric  products.           *
*   This software is owned by Mitsubishi Electric and Electronics USA, Inc.      *
*   or Mitsubishi Electric Corporation and is protected under applicable         *
*   copyright laws. All rights are reserved.                                     *
*                                                                                *                                                                               *
*   THIS SOFTWARE IS PROVIDED "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED   *
*   OR STATUTORY, INCLUDING BUT NOT LIMITED TO IMPLIED WARRANTIES OF             *
*   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. *
*   MITSUBISHI ELECTRIC AND ELECTRONICS USA, INC. AND MITSUBISHI ELECTRIC        *
*   CORPORATION RESERVE THE RIGHT, WITHOUT NOTICE, TO MAKE CHANGES TO THIS       *
*   SOFTWARE. NEITHER MITSUBISHI ELECTRIC AND ELECTRONICS USA, INC. NOR          *
*   MITSUBISHI ELECTRIC CORPORATION SHALL, IN ANY CIRCUMSTANCES, BE LIABLE       *
*   FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES FOR ANY REASON WHATSOEVER  *
*   ARISING OUT OF THE USE OR APPLICATION OF THIS SOFTWARE.                      *
*                                                                                *
*================================================================================*
*   $Log: convert_temp.c,v $
*   Revision 1.2  2002-06-07 14:00:17-04  bembry
*   Fixed flicker problem.  Chang Temp conversion equation fixes problem at "0" crossover point.
*
*================================================================================*/

#include <math.h> 

float AD_input_to_deg_F(unsigned int x);
float Convert_F_to_C(float x);
/*****************************************************************************
Name:         AD_input_to_deg_F  
Parameters:   x   ~ AD input                  
Returns:      Float --> temp in degree F.    
Description:  Convert AD input * 10 to temperture in degrees F.    

*****************************************************************************
   PlL050-3-5820-87-MS to Deg F
   X= AD input value * 10
   Y= Deg F
   Eqn# 7505  y=(a+cx^(0.5)+ex+gx^(1.5))/(1+bx^(0.5)+dx+fx^(1.5))
   r2=0.9999999866210196
   r2adj=0.9999999732420392
   StdErr=0.006158685687162524
   Fstat=99658813.83059718
   a= 384.1305523381259
   b= 0.004399939744046074
   c= -8.079194136912175
   d= -0.0003138255046416174
   e= 0.04758602176108498
   f= 1.716742234299249E-06
   g= -5.273756231991787E-05
 *--------------------------------------------------------------------------*/
 float AD_input_to_deg_F(unsigned int x1)
{
  double y;
  double x;
  x = (double)x1;
  x=sqrt(x);
  y=(384.1305523381259+x*(-8.079194136912175+
    x*(0.04758602176108498+x*-5.273756231991787E-05)))/
    (1.0+x*(0.004399939744046074+x*(-0.0003138255046416174+
    x*1.716742234299249E-06)));
  return(y);
}
/*****************************************************************************
Name:           Convert_F_to_C 
Parameters:     x --> temp in deg F.                 
Returns:        float --> temp in deg C
Description:    Converts temp in degrees F to C

*****************************************************************************/
float Convert_F_to_C(float x)
{
float y;
y = (x - 32)* (5.0/9.0);
return y;
}





