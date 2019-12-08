#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "crctrl.h"
#include "stars.h"
#include <windows.h>

int bullet(int *i)
{

    static ScreenInfo scr;
    static unsigned short halfX,halfY,offset,pMax,pMin;
    short posH;

    if(*i <= 0)
    {
        scr = *getScreen();
        halfX = scr.X/2;
        halfY = scr.Y/2;
        offset = scr.X < 92 ? 8 : 0;

    }


    textcolor(7);
    pMax = halfX + halfX/1.5f;
    pMin = halfX - halfX/1.5f + 1;

    if(*i < (scr.X - 20)){

        posH = -halfX + 10 - offset/2 + *i + 7;
        gotoxy(posH,-halfY + 7);

        posH+= halfX;
        if(posH > pMin && posH <= pMax )
        {
            if(rand()% 100 < 30) textcolor(34);
                else textcolor(52);
        }


        printf(" ");

        ++*i;

        posH = -halfX + 10 - offset/2 + *i + 7;
        gotoxy(posH,-halfY + 7);

        posH+= halfX;
        if(posH > pMin && posH <= pMax ) textcolor(52);

        printf("@");

    }else{

        posH = -halfX + 10 - offset/2 + *i + 7;
        gotoxy(posH,-halfY + 7);
        printf(" ");

        *i = 0;

    }

    textcolor(7);
    return(*i);




}
