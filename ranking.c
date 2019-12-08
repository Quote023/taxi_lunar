#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "game.h"
#include "car.h"
#include "ascii.h"
#include "crctrl.h"
#include "stars.h"
#include "bullets.h"
#include "ranking.h"

void lerRanking()
{
    int i;
    char nome[5], pontuacao[20];
    FILE *ranking = fopen("ranking.txt", "r+");
    fscanf(ranking,"%s \t %s\n",nome,pontuacao);

    for(i = 0; i < N; i++)
    {
        fscanf(ranking, "%s \t %f\n",jogadoresRanking[i].nome,&jogadoresRanking[i].pontuacao);
    }

    fclose(ranking);
}


void salvarRanking()
{
    int i;
    FILE *ranking = fopen("ranking.txt", "w+");
    fprintf(ranking,"Nome \t Pontuacao\n");

    for(i = 0; i < N; i++)
    {
        fprintf(ranking, "%s \t %f\n",jogadoresRanking[i].nome,jogadoresRanking[i].pontuacao);
    }

    fclose(ranking);
}

void imprimirRanking()
{
    ScreenInfo scr = *getScreen();
    unsigned short  halfX = scr.X/2, halfY = scr.Y/2;

    int i, j = 0;
    gotoxy(-9,halfY/2 - 4);
    printf("Nome \tPontuacao\n");

    for(i=0; i < N; i++)
    {
        gotoxy(-9,halfY/2 - 5 - j);
        printf("%s \t%.2f\n", jogadoresRanking[i].nome, jogadoresRanking[i].pontuacao);
        j++;

    }

}


void verificarRanking()
{
    int i,j;


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

    FILE *ranking;


}
