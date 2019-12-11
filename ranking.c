#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "game.h"
#include "crctrl.h"
#include "ranking.h"

void lerRanking()
{
    int i;
    FILE *ranking = fopen("ranking.bin", "rb+");

    for(i = 0; i < N; i++)
    {
        fread(&jogadoresRanking[i],sizeof(jogadoresRanking),1,ranking);
    }

    fclose(ranking);
}


void salvarRanking()
{
    int i;
    FILE *ranking = fopen("ranking.bin", "wb+");

    for(i = 0; i < N; i++)
    {
        fwrite(&jogadoresRanking[i],sizeof(jogadoresRanking),1,ranking);

    }

    fclose(ranking);
}

void imprimirRanking()
{
    ScreenInfo scr = *getScreen();
    unsigned short halfY = scr.Y/2;

    int i, j = 0;
    gotoxy(-9,halfY/2 - 4);
    printf("Nome \t    Pontuacao\n");

    for(i=0; i < N; i++)
    {
        gotoxy(-9,halfY/2 - 5 - j);
        printf("%.5s\t     %.2f\n", jogadoresRanking[i].nome, jogadoresRanking[i].pontuacao);
        j++;
    }

}


void verificarRanking()
{
    int i,j;

    //verifica se a pontuação do jogador atual é maior do que a dos que já jogaram, se sim move para a posição adequada
    for(i = 0; i < N; i++)
    {
        if(jogadorAtual.pontuacao >= jogadoresRanking[i].pontuacao )
        {
            for(j = N-1; j > i; j--)
            {
                jogadoresRanking[j] = jogadoresRanking[j-1];
            }
            jogadoresRanking[i] = jogadorAtual;
            break;
        }

    }




}
