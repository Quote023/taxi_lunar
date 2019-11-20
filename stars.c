#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "crctrl.h"
#include "stars.h"
#include <windows.h>

void estrelas(){
    ScreenInfo scr = *getScreen();
    unsigned short centroX = scr.X/2,centroY = scr.Y/2;


        gotoxy(centroX/2+4, centroY/2+6); //1
        if(rand() % 200 < 10)
            printf("*");
        else
            printf(" ");


        gotoxy(centroX/2+4, centroY/2+6); //2
        if(rand() % 200 < 15)
            printf("*");
        else
            printf(" ");

        gotoxy(centroX/2-4, centroY/2); //3
        if(rand() % 200 < 20)
            printf("*");
        else
            printf(" ");

        gotoxy(centroX/2-4, centroY/2); //4
        if(rand() % 200 < 25)
            printf("*");
        else
            printf(" ");

        gotoxy(centroX/2-10, centroY/2-5); //5
        if(rand() % 200 < 30)
            printf("*");
        else
            printf(" ");

        gotoxy(centroX/2-15, centroY/2+8); //6
        if(rand() % 200 < 35)
            printf("*");
        else
            printf(" ");

        gotoxy(centroX/2+15, centroY/2+3); //7
        if(rand() % 200 < 40)
            printf("*");
        else
            printf(" ");

        gotoxy(centroX/2+10, centroY/2-5); //8
        if(rand() % 200 < 45)
            printf("*");
        else
            printf(" ");

        gotoxy(centroX/2+20, centroY/2+10); //9
        if(rand() % 200 < 50)
            printf("*");
        else
            printf(" ");

        gotoxy(-centroX/2+4, centroY/2+6); //10
        if(rand() % 200 < 50)
            printf("*");
        else
            printf(" ");

        gotoxy(-centroX/2-4, centroY/2); //11
        if(rand() % 200 < 55)
            printf("*");
        else
            printf(" ");

        gotoxy(-centroX/2-4, centroY/2); //12
        if(rand() % 200 < 60)
            printf("*");
        else
            printf(" ");

        gotoxy(-centroX/2-10, centroY/2-5); //13
        if(rand() % 200 < 65)
            printf("*");
        else
            printf(" ");

        gotoxy(-centroX/2-15, centroY/2+8); //14
        if(rand() % 200 < 70)
            printf("*");
        else
            printf(" ");

        gotoxy(-centroX/2-30, centroY/2+3); //15
        if(rand() % 200 < 75)
            printf("*");
        else
            printf(" ");

        gotoxy(-centroX/2-25, centroY/2-8); //16
        if(rand() % 200 < 80)
            printf("*");
        else
            printf(" ");

        gotoxy(-centroX/2-17, centroY/2); //17
        if(rand() % 200 < 85)
            printf("*");
        else
            printf(" ");

        gotoxy(0, centroY-2); //18
        if(rand() % 200 < 90)
            printf("*");
        else
            printf(" ");

        gotoxy(-1, 5);
        if(rand() % 200 < 35)
            printf("*");
        else
            printf(" ");

        gotoxy(-15, 10);
        if(rand() % 200 < 35)
            printf("*");
        else
            printf(" ");

        gotoxy(-25, 7);
        if(rand() % 200 < 35)
            printf("*");
        else
            printf(" ");

        gotoxy(-15, 17);
        if(rand() % 200 < 35)
            printf("*");
        else
            printf(" ");

        gotoxy(25, 15);
        if(rand() % 200 < 50)
            printf("*");
        else
            printf(" ");

        gotoxy(20, 10);
        if(rand() % 200 < 35)
            printf("*");
        else
            printf(" ");

        gotoxy(60, 17);
        if(rand() % 200 < 80)
            printf("*");
        else
            printf(" ");

        gotoxy(55, 7);
        if(rand() % 200 < 50)
            printf("*");
        else
            printf(" ");



}



