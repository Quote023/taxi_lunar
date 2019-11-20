#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "crctrl.h"
#include "stars.h"
#include <windows.h>

void bullet(){

    int estado = 7;

    ScreenInfo scr = *getScreen();
    unsigned short halfX = scr.X/2,halfY = scr.Y/2,offset = scr.X < 92 ? 8 : 0;


    while(estado < 115){

    if(estado % 10 == 0){
        gotoxy(-halfX + 10 - offset/2 + estado,-halfY + 7);
            printf(".");
        gotoxy(-halfX + 10 - offset/2 + estado - 10,-halfY + 7);
            printf(" ");
    }

        ++estado;

    }







}
