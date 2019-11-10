#ifndef CRCTRL_H_INCLUDED
#define CRCTRL_H_INCLUDED


int consoleInfo(char c);
int ShowConsoleCursor(int showFlag);
int textcolor(int color);
int gotoxy(int x,int y);
int crmove(int x, int y);

#endif // CRCTRL_H_INCLUDED
