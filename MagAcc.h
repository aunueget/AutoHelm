#ifndef MagAcc_h
#define MagAcc_h




// register addresses

#define MagAcc_CTRL_REG1_A 0x20
#define MagAcc_CTRL_REG2_A 0x21
#define MagAcc_CTRL_REG3_A 0x22
#define MagAcc_CTRL_REG4_A 0x23
#define MagAcc_CTRL_REG5_A 0x24
#define MagAcc_HP_FILTER_RESET_A 0x25
#define MagAcc_REFERENCE_A 0x26
#define MagAcc_STATUS_REG_A 0x27

#define MagAcc_OUT_X_L_A 0x28
#define MagAcc_OUT_X_H_A 0x29
#define MagAcc_OUT_Y_L_A 0x2A
#define MagAcc_OUT_Y_H_A 0x2B
#define MagAcc_OUT_Z_L_A 0x2C
#define MagAcc_OUT_Z_H_A 0x2D

#define MagAcc_INT1_CFG_A 0x30
#define MagAcc_INT1_SRC_A 0x31
#define MagAcc_INT1_THS_A 0x32
#define MagAcc_INT1_DURATION_A 0x33
#define MagAcc_INT2_CFG_A 0x34
#define MagAcc_INT2_SRC_A 0x35
#define MagAcc_INT2_THS_A 0x36
#define MagAcc_INT2_DURATION_A 0x37

#define MagAcc_CRA_REG_M 0x00
#define MagAcc_CRB_REG_M 0x01
#define MagAcc_MR_REG_M 0x02

#define MagAcc_OUT_X_H_M 0x03
#define MagAcc_OUT_X_L_M 0x04
#define MagAcc_OUT_Y_H_M 0x05
#define MagAcc_OUT_Y_L_M 0x06
#define MagAcc_OUT_Z_H_M 0x07
#define MagAcc_OUT_Z_L_M 0x08

#define MagAcc_SR_REG_M 0x09
#define MagAcc_IRA_REG_M 0x0A
#define MagAcc_IRB_REG_M 0x0B
#define MagAcc_IRC_REG_M 0x0C


typedef struct vector
{
float x, y, z;
} vector;


extern void initMagAcc(void);

extern void enableDefault(void);
extern void getCalibrateReadings(void);

extern void writeAccReg(unsigned char reg, unsigned char value);
extern unsigned char readAccReg(unsigned char reg);
extern void writeMagReg(unsigned char reg, unsigned char value);
extern unsigned char readMagReg(unsigned char reg);

extern void readAcc(void);
extern void readMag(void);
extern void read(void);

extern int get_digital_heading(void);
extern int heading_from(vector from);

// vector functions
extern void vector_cross(const vector *a, const vector *b, vector *out);
extern float vector_dot(const vector *a,const vector *b);
extern void vector_normalize(vector *a);


#endif

