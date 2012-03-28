#ifndef INTERUPTS_H
#define INTERUPTS_H


#pragma	INTERRUPT delay_ticker  //delays for lsm303 digital compass and accelerometer
void delay_ticker(void);

#pragma	INTERRUPT motorToggle //motor toggle
void motorToggle(void);

#pragma	INTERRUPT motorKill //motor kill
void motorKill(void);

void initInterupts(void);


#endif  