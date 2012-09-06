#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H


typedef struct{
	int previous_error;  //pid error variable
	int ivar;//pid intral variable
	int dvar;//
	double Kp,Ki,Kd;//pid constants
	double out;
	double dterm;
	int runTime;
	int KdCount;
//	int settleTime;
}pidCon;

extern pidCon PID;
extern int pidPrior;
extern int pidTaskTime;

void initPID(void);
void modPID_task(void);







#endif  