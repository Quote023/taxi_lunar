#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void main()
{
    unsigned char option;
    struct jogador, novo_jogador, rankingjogadores[i];
    file* ranking;
    jogador = &novo_jogador
     for(;;)
     {
         option = returnvalidoption();
         switch(option)
         {
         case '1':
            system("cls");
            printf("digite o seu nome:");
            gets(jogador->nome);
            jogador->pontuacao = 300;

            for(i = 0; i < N; i++)
            {
                if(rankingjogadores[i].pontuacao<=novo_jogador.pontuacao)
                {
                    for(j = N - 1; j > i; j--)
                    {
                       rankingjogadores[j] = rankingjogadores[j-1];
                    }
                    rankingjogadores[i] = novo_jogador;
                }
                break;
            }
            break;

         case '2':

            printf("\n RANKING \n");
            printf("NOME\tPONTUACAO\t\n");
            for(i = 0; i < N; i++);
            {
                printf(" %s\t %d\n",rankingjogadores[i].nome,rankingjogadores[i].pontuacao);
            }
            break;

         case '3':
            printf("Creditos");
            break

         default
         printf("Saindo....");

         ranking = fopen("ranking.txt","wr");

         fwrite(rankingjogadores, sizeof(jogador), N, ranking);
         fclose(ranking);

         exit(1);
         break;
         }
     }
}
