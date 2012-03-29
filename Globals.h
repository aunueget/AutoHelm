

#ifndef GLOBALS_H
#define GLOBALS_H

#include "compass.h"

extern int c_ticks;
extern int allowedTolerance;
extern int moveCount;
extern char key;
extern int motorRunning;
extern const char deg_S[8];
// added object from compass.h
extern compass heading;

int getCompassReading(int avg);
int degreeDifferance(int absoluteValue,int current,int desired);//calc error for pid
void toStr(char strNum[9],int value,int menuNum);

#endif  