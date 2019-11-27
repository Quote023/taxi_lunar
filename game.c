#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "car.h"
#include "ascii.h"
#include "crctrl.h"
#include "stars.h"
#include "bullets.h"

//Variaveis Globais;
    ScreenInfo scr;
    unsigned short halfX,halfY,offset;


    static void setGlobal()
    {
        scr = *getScreen();
        halfX = scr.X/2;
        halfY = scr.Y/2;
        offset = scr.X < 92 ? 8 : 0;
    }
//

/*Background(true = printar o chao/false = não printar)*/
 static int background(int iFlag)
 {

    int i;

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
    
    gotoxy(-halfX,-17);
     for(i=0; i< scr.X; i++)
        printf("#");
    printf("\n\r");
      for(i=0; i< scr.X; i++)
        printf("#");

 }
//


//Fumaça atrás do carro
    int smoke(int state)
    {

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
//

/*jogo(roda)*/
 int jogo(int *wState)
 {

    int i = 0, y = 0, t = 0, x = 0;
    char tecla = 0;
    const char array[] = "#####################################      ###############      ###############       ###############       ###############   ###############      ####################################";
    int n = 0,gIndex = 0;
    int j = 1;


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
    gotoxy(-halfX + 1,-halfY + 3);
    textcolor(102);//dourado
    drawRect(scr.X,4,' ');
    textcolor(7);//branco

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
            if(tecla == 32 && y == 0)
                jump(&y,i);
            if(tecla == 46 && t == 0)
               bullet(&t);

        }
        
        
        if( i % 10 == 0)
        estrelas ();

        if(t > 0)
            bullet(&t);
        if(y > 0)
            jump(&y,i);



            if(y == 0 && i % 2 == 0)
            {
                turnWheel(wState);
                smoke    (*wState);
                
            }



        
       

            for(n=0; n< j; ++n)
            {
             
                gotoxy(halfX - n,-17);   
                gIndex = n - x >= 0 ? n-x : n-x + scr.X;
                 if(gIndex < 0)
                    {x = 0; n = 0; gIndex = 0;}    
                printf("%c",array[gIndex]);
                
               

            }

               if(j < scr.X)
                j+=1;


           // }

           
            //Sleep(100);


            if(consoleInfo('C') == -10) //Caso o tamanho mude
            {
                system("cls");
                showConsoleCursor(0);   //Apaga o cursor
                setGlobal();
                background(1);          //Redesenha o fundo
                return jogo(wState);    //Recomeça o jogo
            }
            
            x+= 1;
            i+= 1;


    }


    return 0;
 }

/*clsMenu()
 Apagar o Menu*/
 int clsMenu()
 {

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
    //Inicializa as variaveis Globais (primeria função a rodar).
        setGlobal();
    //Inicializa as variaveis Globais

    unsigned char sOption;
    int i = 0,j = 0;

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

