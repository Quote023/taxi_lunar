#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "crctrl.h"
#include "stars.h"
#include "time.h"
#include <windows.h>

void estrelas(){
    ScreenInfo scr = *getScreen();
    unsigned short centroX = scr.X/2,centroY = scr.Y/2;
    static unsigned short rn;

      srand(time(NULL));
      rn = rand() % 100;

        gotoxy(centroX/2+4, centroY/2+6); //1
        if(rn < 10)
            printf("*");
        else
            printf(" ");


        gotoxy(centroX/2+4, centroY/2+6); //2
        if(rn < 15)
            printf("*");
        else
            printf(" ");

        gotoxy(centroX/2-4, centroY/2); //3
        if(rn < 20)
            printf("*");
        else
            printf(" ");

        gotoxy(centroX/2-4, centroY/2); //4
        if(rn < 25)
            printf("*");
        else
            printf(" ");

        gotoxy(centroX/2-10, centroY/2-5); //5
        if(rn < 30)
            printf("*");
        else
            printf(" ");

        gotoxy(centroX/2-15, centroY/2+8); //6
        if(rn < 35)
            printf("*");
        else
            printf(" ");

        gotoxy(centroX/2+15, centroY/2+3); //7
        if(rn < 40)
            printf("*");
        else
            printf(" ");

        gotoxy(centroX/2+10, centroY/2-5); //8
        if(rn < 45)
            printf("*");
        else
            printf(" ");

        gotoxy(centroX/2+20, centroY/2+10); //9
        if(rn < 50)
            printf("*");
        else
            printf(" ");

        gotoxy(-centroX/2+4, centroY/2+6); //10
        if(rn < 50)
            printf("*");
        else
            printf(" ");

        gotoxy(-centroX/2-4, centroY/2); //11
        if(rn < 55)
            printf("*");
        else
            printf(" ");

        gotoxy(-centroX/2-4, centroY/2); //12
        if(rn < 60)
            printf("*");
        else
            printf(" ");

        gotoxy(-centroX/2-10, centroY/2-5); //13
        if(rn < 65)
            printf("*");
        else
            printf(" ");

        gotoxy(-centroX/2-15, centroY/2+8); //14
        if(rn < 70)
            printf("*");
        else
            printf(" ");

        gotoxy(-centroX/2-30, centroY/2+3); //15
        if(rn< 75)
            printf("*");
        else
            printf(" ");

        gotoxy(-centroX/2-25, centroY/2-8); //16
        if(rn < 80)
            printf("*");
        else
            printf(" ");

        gotoxy(-centroX/2-17, centroY/2); //17
        if(rn < 85)
            printf("*");
        else
            printf(" ");

        gotoxy(0, centroY-2); //18
        if(rn < 90)
            printf("*");
        else
            printf(" ");

        gotoxy(-1, 5);
        if(rn < 35)
            printf("*");
        else
            printf(" ");

        gotoxy(-15, 10);
        if(rn < 35)
            printf("*");
        else
            printf(" ");

        gotoxy(-25, 7);
        if(rn < 35)
            printf("*");
        else
            printf(" ");

        gotoxy(-15, 17);
        if(rn < 35)
            printf("*");
        else
            printf(" ");

        gotoxy(25, 15);
        if(rn < 50)
            printf("*");
        else
            printf(" ");

        gotoxy(20, 10);
        if(rn < 35)
            printf("*");
        else
            printf(" ");

        gotoxy(60, 17);
        if(rn < 80)
            printf("*");
        else
            printf(" ");

        gotoxy(55, 7);
        if(rn < 50)
            printf("*");
        else
            printf(" ");



}



