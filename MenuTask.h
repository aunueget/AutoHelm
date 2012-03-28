

#ifndef MENUTASK_H
#define MENUTASK_H

enum menuValue{KP=0,KI,KD,TOLER};
unsigned char sys_mode;
enum SYSTEM_MODES{RUNNING=0,MENUCHANGE,VALUECHANGE};
int paused, selected_menu;
const char menu[5][9] = {
{" KP     "},
{" KI     "},
{" KD     "},
{"TOLERANC"},
{" PAUSED "}};
const char num[15] = {'0','1','2','3','4','5','6','7','8','9',':','F','C',' ','.'};

void initMenuTask(void);
void menuTask(void);
int changeVariable(int menuSelected,int changeValue);
void toStr(char strNum[9],int value,int menuNum);




#endif  