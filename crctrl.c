#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <string.h>

//Tamanho minimo da tela
  #define minY 44
  #define minX 60
  
/*textcolor(int color)
  Valor do Int = Cor da letra e cor do fundo, ./paletadecores.exe */
  int textcolor(int color)
  {
      HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); 
      SetConsoleTextAttribute(h, color);
      return 0;
  }
  
/* ShowConsoleCursor(int 0/!=0) 
  0 deixa o cursor invisivel e 1 deixa o cursor visivel*/
  int ShowConsoleCursor(int showFlag)
 {  
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;       
    GetConsoleCursorInfo(h, &cursorInfo); //Pega as informações atuais do cursosr p/ só mudar a váriavel de visibilidade
    cursorInfo.bVisible = showFlag;       
    SetConsoleCursorInfo(h, &cursorInfo); 
    return showFlag;
  }

  
/* Console Info(char Mode);
  X -> TamanhoMax em X,
  Y -> Tamanho Max em Y,
  H -> Horizontal: Pos Atual em X (Independente do Centro),
  V -> Vertical:   Pos Atual em Y (Independente do Centro),
  S -> Setup:      Responsividade: Ajusta o tamanho da tela e do Buffer p/ tira as barras de rolagem. Chamar pelo menos no inicio.
  C -> Check:      Retorna != 0 se o tamanho tiver mudado.
  */
  int consoleInfo(unsigned char c) 
  {

    HANDLE console;                   //Variavel que acessa algo do sistema(no Caso o console);
    CONSOLE_SCREEN_BUFFER_INFO info; //Struct que guarda informações (tamanho,posição do cursor, etc) de um console; V

    SMALL_RECT scrSize;    //4 Variaveis mas só duas(Bottom e Right) importam porque o tamanho é na diagonal
    COORD bufferSize;      //Vetor R2
    char cmd[30] = "";
    char num[4] = "";
    unsigned char tmpC;
    unsigned int tmpD = 0;
    unsigned static int x ,y ,d;
    static int flag;
    short r = -1; //Variavel de retorno
    tmpC = c;

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
    x = abs(scrSize.Right - scrSize.Left + 1);
    y = abs(scrSize.Bottom - scrSize.Top + 1);
    tmpD = sqrt(pow(x,2) + pow(y,2));

    if(tmpD != d)
    {
      if(c != 'c' && c != 'C' && c != 66)
      flag = -10;

      c = 's';   
      
    }
    

    switch (c)
    {
    case 'c': case 'C': case 66:
      
      if(flag == -10)
      {r = -10;}
      else
      {r = 0;}
      flag = 0;
      break;
    /* */
    case 'x': case 'X': case 0: 
      r = x;
      break;
    case 'Y': case 'y': case 1:
      r = y;
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
      
      
      if(x <= minX )
        {
          scrSize.Right  = minX;
          scrSize.Bottom = !scrSize.Bottom % 2 ? scrSize.Bottom : scrSize.Bottom + 1;
          scrSize.Left   = 0;
          scrSize.Top    = 0;
        }
      
      if(y <= minY )
        {
          scrSize.Right  = !scrSize.Right % 2 ? scrSize.Right : scrSize.Right + 1;
          scrSize.Bottom = minY;
          scrSize.Left   = 0;
          scrSize.Top    = 0;
        }


      bufferSize.X = scrSize.Right  + 1;
      bufferSize.Y = scrSize.Bottom + 1;
      
      x = abs(scrSize.Right - scrSize.Left + 1);
      y = abs(scrSize.Bottom - scrSize.Top + 1);
      d = sqrt(pow(x,2) + pow(y,2));
      r = d;

      strcat(cmd,"Mode con: cols=");
      sprintf(num,"%d",x);
      strcat(cmd,num);
      strcat(cmd," lines=");
      sprintf(num,"%d",y);
      strcat(cmd,num);
      system(cmd);
    
      break;
    /* */
    default:
      CloseHandle(console);
      return -1;
      break;
    }

    CloseHandle(console);  //Fecha o acesso ao console p/ liberar espaço para outras aplicações que possam usar ele;

    if(tmpC != c && tmpC!= 'S' && tmpC != 's' && tmpC != 190)
    return consoleInfo(tmpC);
    else  
    return  r;

  }


/* gotoxy(int x, int y):
  Move o Cursor até a posição
  relativa ao centro da tela. */
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


/* crmove(int x, int y):
  Move o Cursor até a posição
  relativa à posição atual.*/
  int crmove(int x, int y)
  {
    COORD coord; //Vetor R2
    
    x = consoleInfo('H') + x; //PosAtual em X + x;
    y = consoleInfo('V') - y; //PosAtual em Y + Y;
    

    coord.X = x;
    coord.Y = y;

    if(y > consoleInfo('Y'))
    return -1;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //Seta a posição do cursor dentro do console padrão
    
    return  0;
  }
