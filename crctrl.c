/*
  Biblioteca p/ controle do cursor
  V 081219
  Apenas Windows;
*/
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include "crctrl.h"

//Tamanho minimo da tela
  #define minY 44
  #define minX 60
/**/


/*struct ScreenInfo
  Guarda as informações da tela;*/


  ScreenInfo *getScreen()
  {
    static ScreenInfo Screen;// = {0,0,0};
    return &Screen;
  }

  static int setScreen(ScreenInfo s)
  {
    *getScreen() = s;
      return 0;
  }
/**/
  
/*textcolor(int color)
  Valor do Int = Cor da letra e cor do fundo, ./paletadecores.exe */
  int textcolor(int color)
  {
      HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); 
      SetConsoleTextAttribute(h, color);
      return 0;
  }
/**/

/* showConsoleCursor(int 0/!=0) 
  0 deixa o cursor invisivel e 1 deixa o cursor visivel*/
  int showConsoleCursor(int showFlag)
 {  
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;       
    GetConsoleCursorInfo(h, &info); //Pega as informações atuais do cursosr p/ só mudar a váriavel de visibilidade
    info.bVisible = showFlag;       
    SetConsoleCursorInfo(h, &info); 
    return showFlag;
  }
/**/
  
/* Console Info(char Mode);
  X -> TamanhoMax em X,  [Se possivel usar getScreen]
  Y -> Tamanho Max em Y, [Se possivel usar getScreen]
  H -> Horizontal: Pos Atual em X (Independente do Centro),
  V -> Vertical:   Pos Atual em Y (Independente do Centro),
  S -> Setup:      Responsividade: Ajusta o tamanho da tela e do Buffer p/ tira as barras de rolagem. Chamar pelo menos no inicio.
  C -> Check:      Retorna != 0 se o tamanho tiver mudado.
  */
  int consoleInfo(unsigned char c) 
  {
    
  /*Variaveis*/

    CONSOLE_SCREEN_BUFFER_INFO info; //Struct que guarda informações (tamanho,posição do cursor, etc) de um console; V
    SMALL_RECT              scrSize; //4 Variaveis mas só duas(Bottom e Right) importam porque o tamanho é na diagonal
    ScreenInfo              scrInfo; //Struct com Informações da tela;
    HANDLE                  console; //Variavel que acessa algo do sistema(no Caso o console);
    unsigned  int             x,y,d; //tamanho em x e y e a diagonal;
    unsigned char              tmpC; //P/ Recursividade;
    static    int              flag; //-11 caso a diagonal mude;
    short              r       = -1; //Variavel de retorno;
    char               cmd[30] = ""; //Comando do CMD p/ mudar o tamanho da tela;
    
  /*Variaveis*/
    
    scrInfo = *getScreen();
    tmpC  = c;

    //Abre o Handle(Arquivo) CNOUT$(Console Output) com acesso pleno(Escrita e Leitura)
      console = CreateFileW(L"CONOUT$", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL, OPEN_EXISTING,0, NULL); //getstdhandle não funcionou idkwhy.
        //OPEN_EXISTING = Só tentar abrir se o console existir;
    //Inicialização

    //Se o console for Inválido retorna um número negativo;
      if (console == INVALID_HANDLE_VALUE) 
        return -1;
    //(ERRO)

    //Caso não consiga atribuir nada (Return 0;) a função retorna um número negativo;
      if (GetConsoleScreenBufferInfo(console, &info) == 0) 
        return -1;
    //(ERRO)

    //Calcular tamanho da tela atual
      scrSize = info.srWindow;
      x       =  abs(scrSize.Right   - scrSize.Left  + 1);
      y       =  abs(scrSize.Bottom  - scrSize.Top   + 1);
      d       = sqrt(pow(x,2) + pow(y,2));
    //1
    
    //Na primeira inicialização o tamanho da tela salvo vai ser o calculado na hora.
      if(scrInfo.X == 0)
      {
        scrInfo.X = x;
        scrInfo.Y = y;
        scrInfo.D = d;
        setScreen(scrInfo);
      }
    //1.5;

    //Checa se a diagonal salva é igual a diagonal recem-calculada
      if(scrInfo.D != d)
      {
        flag  = -10;  //ativa a flag;
        c     = 's';  //modo setup pra ajustar o tamanho;
      }
    //1.75
    
    //Switch do argumento passado
      switch (c)
      {
      /*StartSwitch*/    
        /*C*/
          case 'c': case 'C': case 66:
            if(flag == -10) 
              {r = -10;}  //retorna -10 caso a flag esteja ativa;
            else
              {r =   0;}  //retorna 0 caso o tamanho não tenha mudado (!flag);
            flag =   0;   //desativa a flag independentemente
            break;
        /*X*/
          case 'x': case 'X': case 0: 
            r = x;        //retorna o valor de X puro que foi calculado acima.
            break;
        /*Y*/
          case 'Y': case 'y': case 1:
            r = y;        //retorna o valor de Y puro que foi calculado acima.
            break;
        /*V*/
          case 'v': case 'V': case 2:
            r = info.dwCursorPosition.Y; //retorna a posição do cursor em Y.
            break;
        /*H*/
          case 'h': case 'H': case 3:
            r = info.dwCursorPosition.X; //retorna a posição do cursor em X.
            break;
        /*S*/
          case 'S': case 's': case 190:
            
          //Se o tamanho em X for menor que o minimo ajustar para o minimo;
            if(x <= minX ) 
              {
                scrSize.Right  = minX;
                scrSize.Bottom = !scrSize.Bottom % 2 ? scrSize.Bottom : scrSize.Bottom + 1;
                scrSize.Left   = 0;
                scrSize.Top    = 0;
              }
          //Se o tamanho em Y for menor que o minimo ajustar para o minimo;
            if(y <= minY ) 
              {
                scrSize.Right  = !scrSize.Right % 2 ?  scrSize.Right  : scrSize.Right + 1;
                scrSize.Bottom = minY;
                scrSize.Left   = 0;
                scrSize.Top    = 0;
              }

          //Atualizar Struct
            scrInfo.X =  abs(scrSize.Right   - scrSize.Left  + 1);
            scrInfo.Y =  abs(scrSize.Bottom  - scrSize.Top   + 1);
            scrInfo.D = sqrt(pow(scrInfo.X,2) + pow(scrInfo.Y,2));;
            setScreen(scrInfo);
          //atualizar Struct

          //Concatena comando pra ser usado no console
            sprintf(cmd,"Mode con: cols=%d lines=%d",scrInfo.X,scrInfo.Y);
            system(cmd);
          //
          
                      
          
            break;
        /*default*/
          default:
            //Fecha o acesso ao console p/ liberar espaço para outras aplicações que possam usar ele;
            CloseHandle(console);
            return -1;
            break;
      /* EndSwitch */
      }
    //2

    //Fecha o acesso ao console p/ liberar espaço para outras aplicações que possam usar ele;
      CloseHandle(console);  
    //3

    //Recursão
      if(tmpC != c && tmpC!= 'S' && tmpC != 's' && tmpC != 190)
        return consoleInfo(tmpC);
    //Retorno Padrão
      else  
      return  r;
    //
    
  }
/**/

/* gotoxy(int x, int y):
  Move o Cursor até a posição
  relativa ao centro da tela. */
  int gotoxy(int x, int y)
  {
    COORD coord; //Vetor R2
    ScreenInfo Screen = *getScreen();

    x =  (Screen.X/2) + x - 1; //Centro + X;
    y =  (Screen.Y/2) - y;     //Centro + Y;
    

    coord.X = x;
    coord.Y = y;

  
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //Seta a posição do cursor dentro do console padrão

    return 0;
  }
/**/

/* crmove(int x, int y):
  Move o Cursor até a posição
  relativa à posição atual.*/
  int crmove(int x, int y)
  {
    COORD coord; //Vetor R2
    ScreenInfo Screen = *getScreen();

    x = consoleInfo('H') + x; //PosAtual em X + x;
    y = consoleInfo('V') - y; //PosAtual em Y + Y;
    

    coord.X = x;
    coord.Y = y;

    if(abs(y) > Screen.Y)
     return -1;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //Seta a posição do cursor dentro do console padrão
    
    return  0;
  }
/**/