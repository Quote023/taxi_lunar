#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include "crctrl.h" //funcão GOTOXY
#include "game.h"
#include "ascii.h"
#include "stars.h"



int girarroda(int *i)
{
    unsigned short centroX = consoleInfo('X')/2,centroY = consoleInfo('Y')/2;

    textcolor(7);

  if(*i == 0 || *i == 4)
  {
    gotoxy(-centroX + 10,-centroY/1.5f - 1);
    printf("(/) (/)");
  }
  if(*i == 1 || *i == 5)
  {
    gotoxy(-centroX + 10,-centroY/1.5f - 1);
    printf("(-) (-)");
  }
   if(*i == 2 || *i == 6)
  {
    gotoxy(-centroX + 10,-centroY/1.5f - 1);
    printf("(\\) (\\)");
    if(*i == 6)
    *i = -1;

  }
    if(*i == 3)
  {
    gotoxy(-centroX + 10,-centroY/1.5f - 1);
    printf("(|) (|)");
  }

    *i = *i + 1;

}



int menu()
{
    unsigned char opcao;
    unsigned short centroX = consoleInfo('X')/2,centroY = consoleInfo('Y')/2;
    int wState = 0;
    int i = 0,j = 0;

    const char *nome[] = {

    "    _____ _  __  _____",
    "   |_   _/_\\ \\ \\/ |_ _|",
    "     | |/ _ \\ >  < | |",
    "     |_/_/ \\_/_/\\_|___|",
    "",
    " _    __ __ _  __  _   ___  *",
    "| |  | | | | \\| | /_\\ | _ \\",
    "| |_ | |_| | .` |/ _ \\|   /",
    "|___|\\____/|_|\\_/_/ \\_|_|_\\"

    };

    const char *car[] = {
    //\u2587\u2587
    " LULAo ",
    "(/) (/)",

    };

    

    textcolor(59);
    gotoxy(0,-centroY + 5);
    elipse(centroX - 4,centroY,0,' ');
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
    
    ///CARRROOOOOOOOOO
    textcolor(7);
    gotoxy(-centroX + 10,-centroY/1.5f);
    puts (car[0]);
    gotoxy(-centroX + 10,-centroY/1.5f - 1);
    puts (car[1]);
    crmove(-15,-1);
    ///CARRROOOOOOOOOO


    textcolor(119);
    for(j = 0; j <(consoleInfo('Y') - consoleInfo('V')) + 4 ;j++)
    {

        for(i = 0; i < centroX * 2 - 1;i++)
        {printf("X");}
        printf("\n\r");
    }
    textcolor(7);


   // gotoxy(-1,0); printf("XXX");  gotoxy(0,1); printf("X");  gotoxy(0,-1); printf("X"); gotoxy(0,-centroY/2 + 1); printf("X");

    //gotoxy(-consoleInfo('X'),-consoleInfo('Y'));
    //for(i = 0; i < consoleInfo('Y')*2 + 1;i++)
    //printf("A");

    do
    {
        if(kbhit())
        opcao = getch();
        else
        {
                 if(!(j % 2))
                {
                    /*
                    Sleep(200);
                    girarroda(&wState);
                    textcolor(63);
                    gotoxy(-7,-centroY/2);
                    printf("INSERT 1 COIN");
                    textcolor(7);*/
                    estrelas1();
                }else
                {
                   
                    /*Sleep(200);
                    girarroda(&wState);
                    textcolor(59);
                    gotoxy(-7,-centroY/2);
                    printf("              ");
                     textcolor(7);*/
                    estrelas2();
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
       // system("cls");
        jogo(car);
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




int jogo(char **c)
{
    unsigned short centroX = consoleInfo('X')/2,centroY = consoleInfo('Y')/2;
    int i;

    
    gotoxy(-13, centroY/1.5f + 1);
     for(i = 0; i < 9 ; i++ )
    {
        puts("                             ");
        gotoxy(-13, centroY/1.5f - i);
    }
    
    textcolor(63);
    gotoxy(0,centroY/4); printf("\n");
    crmove(centroX - 9,0);
    printf("                   \n");
    crmove(centroX - 9,0);
    printf("                   \n");
    crmove(centroX - 9,0);
    printf("                   \n");

    gotoxy(-7,-centroY/2);
    printf("              ");





/*
    textcolor(7);
    gotoxy(-centroX + 15,-centroY/1.5f);
    puts (c[0]);
    gotoxy(-centroX + 15,-centroY/1.5f - 1);
    puts (c[1]);
    crmove(-15,-1);
 */   








}



int main(void)
{
    setlocale(LC_ALL, "");

    printf("\e[?25l");
   // consoleInfo('s');
    menu();
   // gotoxy(-1,0); printf("XXX");  gotoxy(0,1); printf("X");  gotoxy(0,-1); printf("X");



    getchar();
    return 0;
}
