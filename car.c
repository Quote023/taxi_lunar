#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "crctrl.h"


int jump(int *h)
{
    ScreenInfo scr = *getScreen();
    unsigned short halfX = scr.X/2,halfY = scr.Y/2,offset = scr.X < 92 ? 8 : 0;
    int i;

    gotoxy(-halfX + 10 - offset/2 - 3,-halfY + 6);
    printf("   "); 


    for(i = 0;i<2;i++)
    {
      gotoxy(-halfX + 10 - offset/2,-halfY + 6 + *h);
      *h += 1;
      printf("       "); //Apaga a roda
      gotoxy(-halfX + 10 - offset/2,-halfY + 6 + *h);
      *h += 1;
      printf("(|) (|)"); //Printa roda em cima 
      gotoxy(-halfX + 10 - offset/2,-halfY + 6 + *h);
      *h += 1;
      printf(" LULAL "); //Printa Carro;
      
      Sleep(60);

      gotoxy(-halfX + 10 - offset/2,-halfY + 6 + *h - 1);
      printf("       ");
      gotoxy(-halfX + 10 - offset/2,-halfY + 6 + *h - 2);
      printf("        "); 
      gotoxy(-halfX + 10 - offset/2,-halfY + 6 + *h - 3);
      printf("        "); 
    }
   
   
    gotoxy(-halfX + 10 - offset/2,-halfY + 6 + 1);
   
    printf(" LULAo "); //Printa Carro;
    *h = 0;
    return 0;
}



int turnWheel(int *i)
{
    ScreenInfo scr = *getScreen();
    unsigned short halfX = scr.X/2,halfY = scr.Y/2;
    int offset = scr.X < 92 ? 8 : 0;

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

    return(*i);
}