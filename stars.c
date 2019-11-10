#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "crctrl.h"
#include "stars.h"
#include <windows.h>

//dividi o print de insert 1coin e espaço em 2 funções pra poder rodar no contratempo das estrelas euso burrinha
void coin(){
    
    ScreenInfo scr = getScreen();
    unsigned short centroX = scr.X/2,centroY = scr.Y/2;
    
    textcolor(63);
                    Sleep(200);
                    gotoxy(-7,-centroY/2);
                    printf("INSERT 1 COIN");
                    textcolor(7);
}

void space(){
    ScreenInfo scr = getScreen();
    unsigned short centroX = scr.X/2,centroY = scr.Y/2;
     textcolor(59);
                    Sleep(200);
                    gotoxy(-7,-centroY/2);
                    printf("              ");
                    textcolor(7);
}

void estrelas1(){
    ScreenInfo scr = getScreen();
    unsigned short centroX = scr.X/2,centroY = scr.Y/2;

        Sleep(300);
        gotoxy(centroX/2+4, centroY/2+6); //1
            printf("*");
        space();
        Sleep(300);
        gotoxy(centroX/2+4, centroY/2+6); //2
            printf(" ");
        Sleep(300);
        gotoxy(centroX/2-4, centroY/2); //3
            printf("*");
        coin();
        Sleep(300);
        gotoxy(centroX/2-4, centroY/2); //4
            printf(" ");
        Sleep(300);
        gotoxy(centroX/2-10, centroY/2-5); //5
            printf("*");
         space();
        Sleep(300);
        gotoxy(centroX/2-15, centroY/2+8); //6
            printf(" ");
        Sleep(300);
        gotoxy(centroX/2+15, centroY/2+3); //7
            printf("*");
         coin();
        Sleep(300);
        gotoxy(centroX/2+10, centroY/2-5); //8
            printf(" ");
        Sleep(300);
        gotoxy(centroX/2+20, centroY/2+10); //9
            printf("*");
        space();
        Sleep(300);
        gotoxy(-centroX/2+4, centroY/2+6); //10
            printf(" ");
        Sleep(300);
        gotoxy(-centroX/2-4, centroY/2); //11
            printf("*");
        coin();
        Sleep(300);
        gotoxy(-centroX/2-4, centroY/2); //12
            printf(" ");
        Sleep(300);
        gotoxy(-centroX/2-10, centroY/2-5); //13
            printf("*");
        space();
        Sleep(300);
        gotoxy(-centroX/2-15, centroY/2+8); //14
            printf(" ");
        Sleep(300);
        gotoxy(-centroX/2-30, centroY/2+3); //15
            printf("*");
        coin();
        Sleep(300);
        gotoxy(-centroX/2-25, centroY/2-8); //16
            printf(" ");
        Sleep(300);
        gotoxy(-centroX/2-17, centroY/2); //17
            printf("*");
        space();
        Sleep(300);
        gotoxy(0, centroY-2); //18
            printf(" ");


}

void estrelas2(){
    ScreenInfo scr = getScreen();
    unsigned short centroX = scr.X/2,centroY = scr.Y/2;
        Sleep(300);
        gotoxy(centroX/2+4, centroY/2+6); //1
            printf(" ");
        coin();
        Sleep(300);
        gotoxy(centroX/2+4, centroY/2+6); //2
            printf("*");
        Sleep(300);
        gotoxy(centroX/2-4, centroY/2); //3
            printf(" ");
        space();
        Sleep(300);
        gotoxy(centroX/2-4, centroY/2); //4
            printf("*");
        Sleep(300);
        gotoxy(centroX/2-10, centroY/2-5); //5
            printf(" ");
       coin();
        Sleep(300);
        gotoxy(centroX/2-15, centroY/2+8); //6
            printf("*");
        Sleep(300);
        gotoxy(centroX/2+15, centroY/2+3); //7
            printf(" ");
        space();
        Sleep(300);
        gotoxy(centroX/2+10, centroY/2-5); //8
            printf("*");
        Sleep(300);
        gotoxy(centroX/2+20, centroY/2+10); //9
            printf(" ");
        coin();
        Sleep(300);
        gotoxy(-centroX/2+4, centroY/2+6); //10
            printf("*");
        Sleep(300);
        gotoxy(-centroX/2-4, centroY/2); //11
            printf(" ");
        space();
        Sleep(300);
        gotoxy(-centroX/2-4, centroY/2); //12
            printf("*");
        Sleep(300);
        gotoxy(-centroX/2-10, centroY/2-5); //13
            printf(" ");
        coin();
        Sleep(300);
        gotoxy(-centroX/2-15, centroY/2+8); //14
            printf("*");
        Sleep(300);
        gotoxy(-centroX/2-30, centroY/2+3); //15
            printf(" ");
        space();
        Sleep(300);
        gotoxy(-centroX/2-25, centroY/2-8); //16
            printf("*");
        Sleep(300);
        gotoxy(-centroX/2-17, centroY/2); //17
            printf(" ");
        coin();
        Sleep(300);
        gotoxy(0, centroY-2); //18
            printf("*");

    }

    