#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include "crctrl.h" //funcão GOTOXY
#include "game.h"
#include "ascii.h"



int menu()
{
    unsigned char opcao;
    unsigned short centroX = consoleInfo('X')/2,centroY = consoleInfo('Y')/2;
    
    int i = 0,j = 0;

    const char *nome[] = {

    "    _____ _  __  _____",
    "   |_   _/_\\ \\ \\/ |_ _|",
    "     | |/ _ \\ >  < | |",
    "     |_/_/ \\_/_/\\_|___|",
    " ",
    " _    __ __ _  __  _   ___  ",
    "| |  | | | | \\| | /_\\ | _ \\",
    "| |_ | |_| | .` |/ _ \\|   /",
    "|___|\\____/|_|\\_/_/ \\_|_|_\\"
                                              
    };
    
    const char *car[] = {
    //\u2587\u2587
    " oMMMo ",
    "(/) (\\)",
           
    };
    textcolor(59);
    gotoxy(0,-centroY + 5);
    elipse(centroX - 5,centroY,0,'O');
    textcolor(7);

    gotoxy(-13, centroY/1.5f + 1);
    textcolor(6);
    for(i = 0; i < 9 ; i++ )
    {
        puts(nome[i]);
        gotoxy(-13, centroY/1.5f - i);
    }
    textcolor(63);
    gotoxy(0,centroY/4); printf("\n");
    crmove(centroX - 9,0);
    printf("PRESS 1 TO    START\n");
    crmove(centroX - 9,0);
    printf("PRESS 2 TO  OPTIONS\n");
    crmove(centroX - 9,0);
    printf("PRESS 3 TO CONTROLS\n");
    textcolor(7);
    gotoxy(-centroX + 15,-centroY/1.5f);
    puts (car[0]);
    gotoxy(-centroX + 15,-centroY/1.5f - 1);
    puts (car[1]);
    crmove(-15,-1);
    for(j = 0; j <(consoleInfo('Y') - consoleInfo('V')) + 4 ;j++)
    {
        for(i = 0; i < centroX * 2 - 1;i++)
        {crmove(1,0); printf("X"); crmove(-1,0);}
        printf("\n\r");
    }
    
       
   // gotoxy(-1,0); printf("XXX");  gotoxy(0,1); printf("X");  gotoxy(0,-1); printf("X"); gotoxy(0,-centroY/2 + 1); printf("X");
    
    do
    {
        if(kbhit())
        opcao = getch();
        else
        {
                 if(!(j % 2))
                { 
                    textcolor(63);
                    Sleep(200);
                    gotoxy(-7,-centroY/2);
                    printf("INSERT 1 COIN");
                     textcolor(7);
                }else
                {      
                    textcolor(63);
                    Sleep(200);
                    gotoxy(-7,-centroY/2);
                    printf("OOOOOOOOOOOOOO");
                     textcolor(7);
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
     textcolor(7);
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

int printtaxi()
{




}


int main(void)
{
    setlocale(LC_ALL, "");
   

    consoleInfo('s');
    //setup();
    menu();
   // gotoxy(-1,0); printf("XXX");  gotoxy(0,1); printf("X");  gotoxy(0,-1); printf("X");
    
   
    
    getchar();
    return 0;
}