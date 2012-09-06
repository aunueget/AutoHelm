

#ifndef MENUTASK_H
#define MENUTASK_H

enum menuValue{KP=0,KI,KD,TOLER};
enum SYSTEM_MODES{RUNNING=0,MENUCHANGE,VALUECHANGE};

extern unsigned char sys_mode;
extern int paused, selected_menu;
extern const char menu[8][9];
extern const char num[15];

void initMenuTask(void);
void menuTask(void);
int changeVariable(int menuSelected,int changeValue);
void prepare2Follow();





#endif  