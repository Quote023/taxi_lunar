#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "crctrl.h" //funcão GOTOXY



int Menu()
{
    unsigned char opcao;
    
    int centroX = TermMax('X') / 2;
    int centroY = TermMax('Y') / 2;

    gotoxy(centroX, centroY/1.5f - 1);
    printf("MOON");
    gotoxy(centroX - 3,centroY/1.5f);
    printf("BUGGY");
    
    printf("\n\n\n\n");
    printf("\t\t\t\t\t  PRESS 1 TO PLAY\n");
    printf("\t\t\t\t\tPRESS 2 TO CONTROLS\n");
    printf("\t\t\t\t\t  PRESS 3 CREDITS\n");
    
    do
    {
        opcao = getch();
    }
    while(opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3');
    
    printf("\a\n"); //Som de beep, trocar depois
    
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
    Menu();
    return 0;
}