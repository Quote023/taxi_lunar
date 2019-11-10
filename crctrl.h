#ifndef CRCTRL_H_INCLUDED
#define CRCTRL_H_INCLUDED

  typedef struct ScreenInfo
  {
    int X,Y,D;
  } ScreenInfo;


 ScreenInfo getScreen();
int consoleInfo(char c);
int showConsoleCursor(int showFlag);
int textcolor(int color);
int gotoxy(int x,int y);
int crmove(int x, int y);

#endif // CRCTRL_H_INCLUDED
