#define N 10

typedef struct _jog
{
    char nome[5];
    float pontuacao;
} jog;

jog jogadorAtual, jogadoresRanking[N];


void lerRanking();
void salvarRanking();
void imprimirRanking();
void verificarRanking();

