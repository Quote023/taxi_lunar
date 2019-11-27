#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "car.h"
#include "ascii.h"
#include "crctrl.h"
#include "stars.h"
#include "bullets.h"



/*Background(true = printar o chao/false = não printar)*/
 int background(int iFlag)
 {
    ScreenInfo scr = *getScreen();
    unsigned short halfX = scr.X/2,halfY = scr.Y/2;
    int i,j,offset = scr.X < 92 ? 8 : 0;

    const char *car[] = {
    //\u2587\u2587
    " LULAo ",
    "(/) (/)",

    };

    textcolor(59);
    //gotoxy(0,-halfY );
    elipse(halfX/1.5f,halfY,' ');
    textcolor(7);

   ///CARRROOOOOOOOOO
    textcolor(7);
    gotoxy(-halfX + 10 - offset/2,-halfY + 7);
    puts (car[0]);
    gotoxy(-halfX + 10 - offset/2,-halfY + 6);
    puts (car[1]);
    ///CARRROOOOOOOOOO
 
 }
//



int smoke(int state)
{
    ScreenInfo scr = *getScreen();
    unsigned short halfX = scr.X/2,halfY = scr.Y/2,offset = scr.X < 92 ? 8 : 0;


        if(state % 2)
        {
            gotoxy(-halfX + 10 - offset/2 - 3,-halfY + 6);
            printf("  o");

        }
        else
        {
            gotoxy(-halfX + 10 - offset/2 - 3,-halfY + 6);
            printf(" O ");

        }
        if(state % 3 == 0)
        {
            gotoxy(-halfX + 10 - offset/2 - 3,-halfY + 6);
            printf("0  ");


        }
        if(state % 6 == 0)
        {

            gotoxy(-halfX + 10 - offset/2 - 5,-halfY + 7);
            printf("o ");
            crmove(-1,-1);
            printf("0");


        }
        else
        {
            gotoxy(-halfX + 10 - offset/2 - 5,-halfY + 7);
            printf("  ");
            crmove(-1,-1);
            printf("  ");

        }



    return 0;
}

/*jogo(roda)*/
 int jogo(int *wState)
 {

    ScreenInfo scr = *getScreen();
    unsigned short halfX = scr.X/2,halfY = scr.Y/2,offset = scr.X < 92 ? 8 : 0;
    int i = 0, y = 0, t = 0, x = 0;
    char tecla = 0;
    char array[] = "##########   ###############   ###############   ###############   ###############   ###############   ####################################";
    int n = 0,gIndex = 0;

    float cont = 0;


    //Acelerção gradual
        Sleep(200);
        turnWheel(wState);
        Sleep(150);
        turnWheel(wState);
        Sleep(100);
        turnWheel(wState);
        Sleep(75);
        turnWheel(wState);
    //


    while(1)
    {
        // gotoxy(-58, -7);
        // printf("score: ");

        // gotoxy(-50, -7);
        // printf("%.2f km", cont);

        //  cont += 0.1;

        //   gotoxy(-50, -7);
        //  printf("    ");

        //  gotoxy(-50, -7);
        //  printf("%.2f km", cont);


        if(kbhit())
        {
            tecla = getch();
            if(tecla == 32)
                jump(&y);
            if(tecla == 46)
               bullet(&t);

        }

        if(t > 0)
            bullet(&t);



            if(y == 0 && i % 2 == 0)
            {
                turnWheel(wState);
                smoke    (*wState);
                estrelas ();
            }



        
       

    
            for(n=0; n< scr.X; n++)
            {
             
                //gotoxy(2+n,3);
                //if(i % 2 == 0){ 
                    
                //n = x - n > 0 ? x-n : 1;
                gotoxy(consoleInfo('X')/2 - n,-17);
                
                gIndex = n - x >= 0 ? n-x : n-x + scr.X;
                 if(gIndex < 0)
                    {x = 0; n = 0; gIndex = 0;}
                    
                printf("%c",array[gIndex]);
                
               
               // if(x >= sizeof(array)){ x = 0; n++;}


               
            }


           // }

           
            //Sleep(100);


            if(consoleInfo('C') == -10) //Caso o tamanho mude
            {
                system("cls");
                showConsoleCursor(0);   //Apaga o cursor
                background(1);          //Redesenha o fundo
                return jogo(wState);    //Recomeça o jogo
            }
            
            x++;
            i++;


    }


    return 0;
 }

/*clsMenu()
 Apagar o Menu*/
 int clsMenu()
 {
    ScreenInfo scr = *getScreen();
    unsigned short halfY = scr.Y/2,offset = scr.X < 92 ? 8 : 0;
    int i;

    //Nome
        gotoxy(-12 + offset, halfY/1.5f + 1);
        for(i = 0; i < 9 ; i++ )
        {
            puts("                             ");
            gotoxy(-12 + offset, halfY/1.5f - i);
        }
    //

    //Seleção
        textcolor(63);
        gotoxy(-10 + offset,-1);
        printf("                    ");
        gotoxy(-10 + offset,-2);
        printf("                    ");
        gotoxy(-10 + offset,-3);
        printf("                    ");
    //

    //Insert Coin
        gotoxy(-7,-halfY/2);
        printf("              ");
    //

    return 0;
 }

/*Menu(roda)*/
 int menu(int *wState)
 {
    unsigned char sOption;
    ScreenInfo scr = *getScreen();
    unsigned short halfY = scr.Y/2;
    int i = 0,j = 0,offset = scr.X < 92 ? 8 : 0;

    const char *nome[] =
     {

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
    //

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
        gotoxy( -9 + offset,-1);
        printf("PRESS 1 TO    START");
        gotoxy(-9 + offset,-2);
        printf("PRESS 2 TO  OPTIONS");
        gotoxy(-9 + offset,-3);
        printf("PRESS 3 TO CONTROLS");
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
                    estrelas();

                }else
                {

                    Sleep(150);
                    turnWheel(wState);
                    textcolor(59);
                    gotoxy(-7,-halfY/2);
                    printf("              ");
                    textcolor(7);

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

    switch(sOption)
    {
    case '0':
        system("exit");
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

