#include <stdio.h>
#include <stdlib.h>
#include "crctrl.h"


int turnWheel(int *i)
{
    unsigned short halfX = consoleInfo('X')/2,halfY = consoleInfo('Y')/2;
    int offset = consoleInfo('X') < 92 ? 8 : 0;
    textcolor(7);

    
  //gotoxy(-halfX + 10 - 4,-halfY + 6);
  //printf("           ");

  if(*i == 0 || *i == 4)
  {
    gotoxy(-halfX + 10 - offset/2,-halfY + 6);
    printf("(\\) (\\)");
  }
  if(*i == 1 || *i == 5)
  {
    gotoxy(-halfX + 10 - offset/2,-halfY + 6);
    printf("(-) (-)");
  }
   if(*i == 2 || *i == 6)
  {
    gotoxy(-halfX + 10 - offset/2,-halfY + 6);
    printf("(/) (/)");
    if(*i == 6)
    *i = -1;
  }
    if(*i == 3)
  {
    gotoxy(-halfX + 10 - offset/2,-halfY + 6);
    printf("(|) (|)");
  }

    *i = *i + 1;

}