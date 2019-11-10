#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "car.h"
#include "ascii.h"
#include "crctrl.h"
#include "stars.h"


/*Background(true = printar o chao/false = não printar)*/
 int background(int iFlag)
 {
    ScreenInfo scr = getScreen();
    unsigned short halfX = scr.X/2,halfY = scr.Y/2;
    int i,j,offset = scr.X < 92 ? 8 : 0;

    const char *car[] = {
    //\u2587\u2587
    " LULAo ",
    "(/) (/)",

    };

    textcolor(59);
    //gotoxy(0,-halfY );
    elipse(halfX/1.5f,halfY,0,' ');
    textcolor(7);

   ///CARRROOOOOOOOOO
    textcolor(7);
    gotoxy(-halfX + 10 - offset/2,-halfY + 7);
    puts (car[0]);
    gotoxy(-halfX + 10 - offset/2,-halfY + 6);
    puts (car[1]);
    ///CARRROOOOOOOOOO
    //Chão Inicial
    if(iFlag)
    {
        textcolor(119);
        gotoxy(-halfX + 1,-halfY + 5);
        for(j = 0; j <= 4 ;j++)
        {

            for(i = 0; i < (halfX) * 2;i++)
            {printf("X");}
            // gotoxy(-halfX,-halfY + 6 - i);
        }
        textcolor(7);
    }
    //Chão Inicial
 }

/*jogo(roda)*/
 int jogo(int *wState)
 {
    ScreenInfo scr = getScreen();
    unsigned short halfX = scr.X/2,halfY = scr.Y/2;
    int i,j,offset = scr.X < 92 ? 8 : 0;


    Sleep(200);
    turnWheel(wState);
    Sleep(150);
    turnWheel(wState);
    Sleep(100);
    turnWheel(wState);
    Sleep(75);
    turnWheel(wState);
    
    i = 0;
    while(1 == 1)
    {
        Sleep(50);
        turnWheel(wState);
        if(i % 2)
        {
            Sleep(10);
            gotoxy(-halfX + 10 - offset/2 - 3,-halfY + 6);
            printf("  o");
        }
        else
        {
            Sleep(10);
            gotoxy(-halfX + 10 - offset/2 - 3,-halfY + 6);
            printf(" O ");

        }
        if(i % 3 == 0)
        {
            Sleep(10);
            gotoxy(-halfX + 10 - offset/2 - 3,-halfY + 6);
            printf("0  "); 
        }
        if(i % 6 == 0)
        {
            
            gotoxy(-halfX + 10 - offset/2 - 5,-halfY + 7);
            printf("o "); 
            crmove(-1,-1);
            printf("0");
        }
        else   
        {
            Sleep(10);
            gotoxy(-halfX + 10 - offset/2 - 5,-halfY + 7);
            printf("  "); 
            crmove(-1,-1);
            printf("  ");
        }

        if(consoleInfo('C') == -10) //Caso o tamanho mude
        {

            system("cls");
            showConsoleCursor(0);
            background(1);
            return jogo(wState);
        }
        
        i++;
    }

    return 0;
 }

/*clsMenu()
 Apagar o Menu*/
 int clsMenu()
 {
    ScreenInfo scr = getScreen();
    unsigned short halfX = scr.X/2,halfY = scr.Y/2;
    int i,j, offset = scr.X < 92 ? 8 : 0;


    gotoxy(-12 + offset, halfY/1.5f + 1);
    for(i = 0; i < 9 ; i++ )
    {
        puts("                             ");
        gotoxy(-12 + offset, halfY/1.5f - i);
    }
    
    textcolor(63);
    gotoxy(0,halfY/4); printf("\n");
    crmove(halfX + offset - 9,0);
    printf("                   \n");
    crmove(halfX + offset - 9,0);
    printf("                   \n");
    crmove(halfX + offset - 9,0);
    printf("                   \n");

    gotoxy(-7,-halfY/2);
    printf("              ");
 }

/*Menu(roda)*/
 int menu(int *wState)
 {
    unsigned char sOption;
    ScreenInfo scr = getScreen();
    unsigned short halfX = scr.X/2,halfY = scr.Y/2;
    int i = 0,j = 0,offset = scr.X < 92 ? 8 : 0;

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

  
    background(1);
    



    //MENU
    gotoxy(-12 + offset, halfY/1.5f + 1);
    textcolor(6);
    for(i = 0; i < 9 ; i++ )
    {
        puts(nome[i]);
        gotoxy(-12 + offset, halfY/1.5f - i);
    }
    textcolor(63);
    //gotoxy(offset,halfY/4); printf("\n");
    gotoxy( -9 + offset,-1);
    printf("PRESS 1 TO    START\n");
    gotoxy(-9 + offset,-2);
    printf("PRESS 2 TO  OPTIONS\n");
    gotoxy(-9 + offset,-3);
    printf("PRESS 3 TO CONTROLS\n");
    //MENU
 

    do
    {
        if(kbhit())
        sOption = getch();
        else
        {
                 if(!(j % 2))
                {
                    
                    Sleep(150);
                    turnWheel(wState);
                    textcolor(63);
                    gotoxy(-7,-halfY/2);
                    printf("INSERT 1 COIN");
                    textcolor(7);
                   // estrelas1();

                }else
                {
                   
                    Sleep(150);
                    turnWheel(wState);
                    textcolor(59);
                    gotoxy(-7,-halfY/2);
                    printf("              ");
                    textcolor(7);
                   // estrelas2();
                }
                if(consoleInfo('C') == -10) //Caso o tamanho mude
                {
                    system("cls");
                    showConsoleCursor(0);
                    return menu(wState);
                }
        }
        j++;
    }
    while(sOption != '0' && sOption != '1' && sOption != '2' && sOption != '3');
     textcolor(7);
     //printf("\a\n"); //Som de beep, trocar depois

    switch(sOption)
    {
    case '0':
        system("cls");
        printf("quitar");
        break;
    case '1':
        clsMenu();
        jogo(wState);
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

