

#ifndef GLOBALS_H
#define GLOBALS_H

//#include "compass.h"

typedef struct var {
	//int offset;
    int current;
    int desired;
	int tilt;
	int desiredTilt;
	//char strCurrent[5];
	//char strDesired[4];
} compass;

extern int useTilt;
extern int c_ticks;
extern int allowedTolerance;
extern int moveCount;
extern char key;
extern volatile int motorRunning;
extern const char deg_S[8];
extern int paused;
extern int shaftPosition;
enum {ALLIN,ALLOUT,MIDDLE};

// added object from compass.h
extern compass heading;

int getCompassReading(int avg);
int degreeDifferance(int absoluteValue,int current,int desired);//calc error for pid
void toStr(char strNum[9],int value,int menuNum);
void tiltToStr(char strNum[9],int value);
void numsToStr(char strNum[9],int value,int value2);
void digits2String(int value,int pos,char strNum[9]);
void tack2Heading(int starboard);
void setCompass(int compassReading);
void setDesired(int userSelectedDegrees);
void check4ShaftNOut();

#endif  