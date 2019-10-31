#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void)
{
    unsigned char opcao;

    printf("\n\n\n\n\n\t\t\t\t\t\tMOON\n\t\t\t\t\t\tBUGGY\n\n\n\n\n");

    printf("\t\t\t\t\t  PRESS 1 TO PLAY\n");
    printf("\t\t\t\t\tPRESS 2 TO CONTROLS\n");
    printf("\t\t\t\t\t  PRESS 3 CREDITS\n");

    printf("\n\n\n\n");

    do
    {
        opcao = getch();

    }
    while(opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3');

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
