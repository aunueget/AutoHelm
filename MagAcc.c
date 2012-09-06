#include "MagAcc.h"
#include <math.h>
#include <stdio.h>
#include "MitsuI2C.h" // for unsigned char data type
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
// Defines ////////////////////////////////////////////////////////////////

// The Arduino two-wire interface uses a 7-bit number for the address,
// and sets the last bit correctly based on reads and writes
#define ACC_ADDRESS (0x30)
#define MAG_ADDRESS (0x3C)

//Global variables////////////////////////////////////////////////////////////

vector a; // accelerometer readings
vector m; // magnetometer readings
vector m_max; // maximum magnetometer values, used for calibration
vector m_min; // minimum magnetometer values, used for calibration
vector test_max;
vector test_min;
volatile double tilt;

// Constructors ////////////////////////////////////////////////////////////////

void initMagAcc(void)
{
	// These are just some values for a particular unit; it is recommended that
	// a calibration be done for your particular unit.
	m_max.x = +372; m_max.y = +622; m_max.z = 612;
	m_min.x = -786; m_min.y = -646; m_min.z = -528;
	test_max.x=0; test_max.y=0; test_max.z=0;
	test_min.x=0; test_min.y=0; test_min.z=0;
	tilt=0;
	MitsuI2C_Init();
	enableDefault();
//	getCalibrateReadings();
}
// void getCalibrateReadings(){
	// int i=0;
	// File *dataFile;
	// dataFile=fopen("testData.csv","w");
	// for(i=0;i<100;i++){
		// readAcc();
		// readMag();
	// }
	// fclose(dataFile);
// }

// Public Methods //////////////////////////////////////////////////////////////

// Turns on the MagAcc's accelerometer and magnetometers and places them in normal
// mode.
void enableDefault(void)
{
// Enable Accelerometer
// 0x27 = 0b00100111
// Normal power mode, all axes enabled
writeAccReg(MagAcc_CTRL_REG1_A, 0x27);
readAccReg(MagAcc_CTRL_REG1_A);
writeAccReg(MagAcc_CTRL_REG4_A, 0x00);
readAccReg(MagAcc_CTRL_REG4_A);

// Enable Magnetometer
// 0x00 = 0b00000000
// Continuous conversion mode
writeMagReg(MagAcc_MR_REG_M, 0x00);
readMagReg(MagAcc_MR_REG_M);
writeMagReg(MagAcc_CRA_REG_M, 0x14);
readMagReg(MagAcc_CRA_REG_M);
}

// Writes an accelerometer register
void writeAccReg(unsigned char reg, unsigned char value)
{
	if(MitsuI2C_beginTransmission(ACC_ADDRESS))
		if(MitsuI2C_send(reg))
			if(MitsuI2C_send(value))
				MitsuI2C_endTransmission();
}

// Reads an accelerometer register
unsigned char readAccReg(unsigned char reg)
{
	unsigned char value=0;

	if(MitsuI2C_beginTransmission(ACC_ADDRESS))
		if(MitsuI2C_send(reg))
	//MitsuI2C_endTransmission();
			if(MitsuI2C_requestFrom(ACC_ADDRESS, 1)){
				value = MitsuI2C_receive(0);
				MitsuI2C_endTransmission();
			}

return value;
}

// Writes a magnetometer register
void writeMagReg(unsigned char reg, unsigned char value)
{
	if(MitsuI2C_beginTransmission(MAG_ADDRESS))
		if(MitsuI2C_send(reg))
			if(MitsuI2C_send(value))
				MitsuI2C_endTransmission();

}

// Reads a magnetometer register
unsigned char readMagReg(unsigned char reg)
{
unsigned char value=0;

if(MitsuI2C_beginTransmission(MAG_ADDRESS))
	if(MitsuI2C_send(reg))
		//MitsuI2C_endTransmission();
		if(MitsuI2C_requestFrom(MAG_ADDRESS, 1)){
			value = MitsuI2C_receive(0);
			MitsuI2C_endTransmission();
		}

return value;
}

// Reads the 3 accelerometer channels and stores them in vector a
void readAcc(void)
{
int xla;
int xha;
int yla;
int yha;
int zla;
int zha;
int prevAvailable=0;
int bailout=0;
MitsuI2C_beginTransmission(ACC_ADDRESS);
// assert the MSB of the address to get the accelerometer
// to do slave-transmit subaddress updating.
MitsuI2C_send(MagAcc_OUT_X_L_A | (1 << 7));
//MitsuI2C_endTransmission();
MitsuI2C_requestFrom(ACC_ADDRESS, 6);
if(problemOccured()){
	initMagAcc();
}

while (bailout++<200&&((prevAvailable>=MitsuI2C_available())&&MitsuI2C_available() < 6));

xla = MitsuI2C_receive(0);
xha = MitsuI2C_receive(1);
yla = MitsuI2C_receive(2);
yha = MitsuI2C_receive(3);
zla = MitsuI2C_receive(4);
zha = MitsuI2C_receive(5);

a.x = (xha << 8 | xla) >> 4;
a.y = (yha << 8 | yla) >> 4;
a.z = (zha << 8 | zla) >> 4;
}

// Reads the 3 magnetometer channels and stores them in vector m
void readMag(void)
{

int xhm;
int xlm;
int yhm;
int ylm;
int zhm;
int zlm;

int bailout=0;

MitsuI2C_beginTransmission(MAG_ADDRESS);
MitsuI2C_send(MagAcc_OUT_X_H_M);
//MitsuI2C_endTransmission();
MitsuI2C_requestFrom(MAG_ADDRESS, 6);
if(problemOccured()){
	initMagAcc();
}

while (bailout++<200&&MitsuI2C_available() < 6);

xhm = MitsuI2C_receive(0);
xlm = MitsuI2C_receive(1);
yhm = MitsuI2C_receive(2);
ylm = MitsuI2C_receive(3);
zhm = MitsuI2C_receive(4);
zlm = MitsuI2C_receive(5);

m.x = (xhm << 8 | xlm);
m.y = (yhm << 8 | ylm);
m.z = (zhm << 8 | zlm);
if(m.x>test_max.x)
	test_max.x=m.x;
else if(m.x<test_min.x)
	test_min.x=m.x;
if(m.y>test_max.y)
	test_max.y=m.y;
else if(m.y<test_min.y)
	test_min.y=m.y;
if(m.z>test_max.z)
	test_max.z=m.z;
else if(m.z<test_min.z)
	test_min.z=m.z;	
}

// Reads all 6 channels of the MagAcc and stores them in the object variables
void read(void)
{
readAcc();
readMag();
}

// Returns the number of degrees from the -Y axis that it
// is pointing.
int get_digital_heading(void)
{
vector tempVector={0,-1,0};
read();
return heading_from(tempVector);
}

// Returns the number of degrees from the From vector projected into
// the horizontal plane is away from north.
//
// Description of heading algorithm:
// Shift and scale the magnetic reading based on calibration data to
// to find the North vector. Use the acceleration readings to
// determine the Down vector. The cross product of North and Down
// vectors is East. The vectors East and North form a basis for the
// horizontal plane. The From vector is projected into the horizontal
// plane and the angle between the projected vector and north is
// returned.
int heading_from(vector from)
{
    vector temp_a;
	vector tiltFrom={0,0,1};
	vector E;
    vector N;
	int heading; 
    // shift and scale
    m.x = (m.x - m_min.x) / (m_max.x - m_min.x) * 2 - 1.0;
    m.y = (m.y - m_min.y) / (m_max.y - m_min.y) * 2 - 1.0;
    m.z = (m.z - m_min.z) / (m_max.z - m_min.z) * 2 - 1.0;


	temp_a.x= a.x;
	temp_a.y= a.y;
	temp_a.z= a.z;		
    // normalize
    vector_normalize(&temp_a);
    //vector_normalize(&m);

    // compute E and N
    vector_cross(&m, &temp_a, &E);
    vector_normalize(&E);
    vector_cross(&temp_a, &E, &N);
	
	//compute tilt
    tilt = (double)(atan2(vector_dot(&N, &tiltFrom), vector_dot(&temp_a, &tiltFrom)) * 180.0 / M_PI);//deleted round
	if (tilt < 0) tilt += 360;
    // compute heading
    heading = (int)(atan2(vector_dot(&E, &from), vector_dot(&N, &from)) * 180 / M_PI);//deleted round
    if (heading < 0) heading += 360;
return heading;
}

void vector_cross(const vector *a,const vector *b, vector *out)
{
  out->x = a->y*b->z - a->z*b->y;
  out->y = a->z*b->x - a->x*b->z;
  out->z = a->x*b->y - a->y*b->x;
}

float vector_dot(const vector *a,const vector *b)
{
  return a->x*b->x+a->y*b->y+a->z*b->z;
}

void vector_normalize(vector *a)
{
  float mag = sqrt(vector_dot(a,a));
  a->x /= mag;
  a->y /= mag;
  a->z /= mag;
}