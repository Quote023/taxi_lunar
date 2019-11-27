#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "crctrl.h"


//Variaveis Globais;
    ScreenInfo scr;
    unsigned short halfX,halfY,offset;


    void setGlobal()
    {
        scr = *getScreen();
        halfX = scr.X/2;
        halfY = scr.Y/2;
        offset = scr.X < 92 ? 8 : 0;
    }
//



int jump(int *h, int i)
{

    static int down;
    
    if(*h != 0)
    {
      gotoxy(-halfX + 10 - offset/2,-halfY + 5 + *h);
      printf("       ");  //Espaço vazio onde era a roda
      gotoxy(-halfX + 10 - offset/2,-halfY + 6 + *h);
      printf("(|) (|)"); //Printa roda em cima 
      gotoxy(-halfX + 10 - offset/2,-halfY + 7 + *h);
      printf(" LULAo ");
      gotoxy(-halfX + 10 - offset/2,-halfY + 8 + *h);
      printf("       ");
    }
      
      
      if(*h == 7)
      {
        down = 1;
      }
      if(!down)
       *h += 1;
       else
        *h -= 1;

        if(*h == 0)
        {
            if(!down) setGlobal();
            gotoxy(-halfX + 10 - offset/2,-halfY + 8 + *h);
            printf("       ");
            gotoxy(-halfX + 10 - offset/2,-halfY + 7 + *h);
            printf(" LULAo ");
            down = 0; 
        }
        

     
    //}
    return 0;
}



int turnWheel(int *i)
{


    textcolor(7);

    
  //gotoxy(-halfX + 10 - 4,-halfY + 6);
  //printf("           ");
  
  if(!*i) setGlobal();

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