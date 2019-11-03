#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "crctrl.h" //funcão GOTOXY
#include "game.h"



int menu()
{
    unsigned char opcao;
    unsigned short centroX = consoleInfo('X')/2,centroY = consoleInfo('Y')/2;

    const char *nome[] = {

    " _____ _  __  _____       ",
    "|_   _/_\\ \\ \\/ |_ _|      ",
    "  | |/ _ \\ >  < | |       ",
    " _|_/_/ \\_/_/\\_|___|      ",
    "",
    "                      ___ ",
    "| | | | | | \\| | /_\\ | _ \\",
    "| |_| |_| | .` |/ _ \\|   /",
    "|____\\___/|_|\\_/_/ \\_|_|_\\"
                                              
    };


    gotoxy(-3, centroY/2);
    printf("MOON");
    gotoxy(0,  centroY/2 - 1);
    printf("BUGGY");



    gotoxy(0,centroY/4); printf("\n");
    crmove(centroX - 9,0);
    printf("PRESS 1 TO    START\n");
    crmove(centroX - 9,0);
    printf("PRESS 2 TO  OPTIONS\n");
    crmove(centroX - 9,0);
    printf("PRESS 3 TO CONTROLS\n");


       
    gotoxy(-1,0); printf("XXX");  gotoxy(0,1); printf("X");  gotoxy(0,-1); printf("X");
    do
    {
        opcao = getch();
    }
    while(opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3');
    
    //printf("\a\n"); //Som de beep, trocar depois
    
    switch(opcao)
    {
    case '0':
        system("cls");
        printf("quitar");
        break;
    case '1':
        system("cls");
        printf("jogarrrrr");
        break;
    case '2':
        system("cls");
        printf("controles aqqqq");
        break;
    case '3':
        system("cls");
        printf("creditosss");
        break;
    }
    
    return 0;
}


int main(void)
{
    //system("MODE con: cols=45 lines=15");
    consoleInfo('s');
    setup();
    menu();
    return 0;
}