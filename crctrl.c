#include <windows.h>
#include <math.h>

//Tamanho minimo da tela
#define minY 44
#define minX 78

/* 
  X -> TamanhoMax em X,
  Y -> Tamanho Max em Y,
  H -> Horizontal: Pos Atual em X (Independente do Centro),
  V -> Vertical:   Pos Atual em Y (Independente do Centro),
  S -> Setup:      Responsividade: Ajusta o tamanho da tela e do Buffer p/ tira as barras de rolagem. Chamar pelo menos no inicio.
*/
int consoleInfo(unsigned char c) 
{

  HANDLE console;        //Variavel que acessa algo do sistema(no Caso o console);

  CONSOLE_SCREEN_BUFFER_INFO info; //Struct que guarda informações (tamanho,posição do cursor, etc) de um console; V

  SMALL_RECT scrSize;    //4 Variaveis mas só duas(Bottom e Right) importam porque o tamanho é na diagonal
  COORD bufferSize;      //Vetor R2
  unsigned short r = -1; //Variavel de retorno


// V Aponta para o terminal atual; V
  //Abre o arquivo de nome CNOUT$(Console Output) com acesso para leitura e escrita e compartilhamento
  console = CreateFileW(L"CONOUT$", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
   NULL, OPEN_EXISTING,0, NULL); //getstdhandle não funcionou idkwhy.
  //OPEN_EXISTING = Só tentar abrir se o console existir;
  
  if (console == INVALID_HANDLE_VALUE) //Se o console for Inválido retorna um número negativo;
		return -1;


  if (GetConsoleScreenBufferInfo(console, &info) == 0) //Caso não consiga atribuir nada (Return 0;) a função retorna um número negativo;
		return -1;
 

  scrSize = info.srWindow;

  switch (c)
  {
  /* */
  case 'x': case 'X': case 0: 
    r = abs(scrSize.Right - scrSize.Left + 1);
    break;
  case 'Y': case 'y': case 1:
    r = abs(scrSize.Bottom - scrSize.Top + 1);
    break;
  /* */
  case 'v': case 'V': case 2:
    r = info.dwCursorPosition.Y;
    break;
  case 'h': case 'H': case 3:
    r = info.dwCursorPosition.X;
    break;
  /* */
  case 'S': case 's': case 190:
    
     
    if(abs(scrSize.Right - scrSize.Left + 1) < minX || abs(scrSize.Bottom - scrSize.Top + 1) < minY)
      {
        scrSize.Right  = minX;
        scrSize.Bottom = minY;
        scrSize.Left   = 0;
        scrSize.Top    = 0;
      }

/*
    if( info.dwSize.Y % 2 != 0) 
      {scrSize.Bottom -= 1; scrSize.Top = 0;}
    if(abs(info.dwSize.X % 2 != 0))
      {scrSize.Right -= 1;  scrSize.Left = 0;}
*/
    
    bufferSize.X = scrSize.Right  + 1;
    bufferSize.Y = scrSize.Bottom + 1;
    

    SetConsoleScreenBufferSize(console,bufferSize); //Tamanho do buffer (sempre tem que ser >= o da janela, por isso setado duas vezes);
    SetConsoleWindowInfo(console, 1, &scrSize);     //Tamanho da janela;
    SetConsoleScreenBufferSize(console,bufferSize); //Tamanho do buffer norvamente para remover barras de rolagem.

    break;
  /* */
  default:
    return -1;
    break;
  }

  CloseHandle(console);  //Fecha o acesso ao console p/ liberar espaço para outras aplicações que possam usar ele;


  return  r;

}




int gotoxy(int x, int y)
{
  COORD coord; //Vetor R2
  
  x = (consoleInfo('X')/2) + x - 1; //Centro + X;
  y = (consoleInfo('Y')/2) - y; //Centro + Y;
  

  coord.X = x;
  coord.Y = y;

 
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //Seta a posição do cursor dentro do console padrão

  return 0;
}

int crmove(int x, int y)
{
  COORD coord; //Vetor R2
  
  x = consoleInfo('H') + x - 1; //PosAtual em X + x;
  y = consoleInfo('V') + y; //PosAtual em Y + Y;
  

  coord.X = x;
  coord.Y = y;

  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //Seta a posição do cursor dentro do console padrão
  
  return  0;
}
