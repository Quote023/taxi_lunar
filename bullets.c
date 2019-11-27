#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "crctrl.h"
#include "stars.h"
#include <windows.h>

int bullet(int *i)
{

    ScreenInfo scr;
    unsigned short halfX,halfY,offset;

    if(*i <= 0)
    {
        scr = *getScreen();
        halfX = scr.X/2;
        halfY = scr.Y/2;
        offset = scr.X < 92 ? 8 : 0;

    }


    if(*i < (scr.X - 20)){

        gotoxy(-halfX + 10 - offset/2 + *i + 7,-halfY + 7);
            printf(" ");
        ++*i;
        gotoxy(-halfX + 10 - offset/2 + *i + 7,-halfY + 7);
            printf(".");

    }else{

        gotoxy(-halfX + 10 - offset/2 + *i + 7,-halfY + 7);
            printf(" ");

        *i = 0;

    }


    return(*i);




}
