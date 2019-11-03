#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include "crctrl.h" //funcão GOTOXY
#include "game.h"



int menu()
{
    unsigned char opcao;
    unsigned short centroX = consoleInfo('X')/2,centroY = consoleInfo('Y')/2;
    
    int i = 0,j = 0;

    const char *nome[] = {

    "    _____ _  __  _____       ",
    "   |_   _/_\\ \\ \\/ |_ _|      ",
    "     | |/ _ \\ >  < | |       ",
    "     |_/_/ \\_/_/\\_|___|      ",
    " ",
    " _    __ __ _  __  _   ___  ",
    "| |  | | | | \\| | /_\\ | _ \\",
    "| |_ | |_| | .` |/ _ \\|   /",
    "|___|\\____/|_|\\_/_/ \\_|_|_\\"
                                              
    };

    
    gotoxy(-13, centroY/1.5f + 1);
    
    for(i = 0; i < 9 ; i++ )
    {
        puts(nome[i]);
        gotoxy(-13, centroY/1.5f - i);
    }
       
    gotoxy(0,centroY/4); printf("\n");
    crmove(centroX - 9,0);
    printf("PRESS 1 TO    START\n");
    crmove(centroX - 9,0);
    printf("PRESS 2 TO  OPTIONS\n");
    crmove(centroX - 9,0);
    printf("PRESS 3 TO CONTROLS\n");


       
    gotoxy(-1,0); printf("XXX");  gotoxy(0,1); printf("X");  gotoxy(0,-1); printf("X"); gotoxy(0,-centroY/2 + 1); printf("X");
    do
    {
        if(kbhit())
        opcao = getch();
        else
        {
                 if(!(j % 2))
                { 
                    Sleep(200);
                    gotoxy(-7,-centroY/2);
                    printf("INSERT 1 COIN");
                }else
                {      
                    Sleep(200);
                    gotoxy(-7,-centroY/2);
                    printf("               ");
                }
                if(consoleInfo('C') == -10) //Caso o tamanho mude
                {
                    system("cls");
                    return menu();
                }
        }
        j++;
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
    getchar();
    return 0;
}