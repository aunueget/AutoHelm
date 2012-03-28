/*****************************************************************************
*
*	File Name: compass.h                                         
*                                                                  
*	Content:   Header file for compass.c            
*                                                                  
*   source and make any necessary changes to support your hardware and application.
*                                                               
*=============================================================================
*	Revision 1.0 05Oct2010
*
*===========================================================================*/
#ifndef COMPASS_H
#define COMPASS_H
typedef struct var {
	int offset;
    int current;
    int desired;
	char strCurrent[5];
	char strDesired[4];
} compass;

extern compass init_compass(compass *heading,int desired, int current);
extern void change_heading(compass *heading,int degreeChange);
extern int get_heading(compass *heading);
extern void set_OffSet(compass *heading);
extern void set_compass(compass *heading,int compass);
extern void set_desired(compass *heading,int compass);
extern int get_compass(compass *heading);
extern void set_strCurrent(compass *heading,int value);
extern void set_strDesired(compass *heading,int value);
extern char* getStrHeading(compass *heading);
extern void bad_strCurrent(compass *heading);

#endif
