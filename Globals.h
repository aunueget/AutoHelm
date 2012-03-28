#ifndef GLOBALVARS_H
#define GLOBALVARS_H

int c_ticks;
int allowedTolerance;
int moveCount;
char key;
int motorRunning;
const char deg_S[8] = {0x08,0x14,0x08,0x00,0x00,0x00,0x00,0x00};
// added object from compass.h
compass heading={0,0,0,"    ","   "};

int getCompassReading(int avg);
int degreeDifferance(int absoluteValue,int current,int desired);//calc error for pid

#endif  