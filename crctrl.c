#include <windows.h>
#include <math.h>
//#include <wchar.h>

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int TermMax(char c)
{
// v Handle = Variável que acessa algo do sistema(no Caso o console); V
  HANDLE console;
//V Struct que guarda informações (tamanho,posição do cursor, etc) de um console; V
  CONSOLE_SCREEN_BUFFER_INFO info;
  unsigned short size;

// V Aponta para o terminal atual; V
  //Abre o arquivo de nome CNOUT$(Console Output) com acesso para leitura e escrita e compartilhamento
  console = CreateFileW(L"CONOUT$", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
   NULL, OPEN_EXISTING,0, NULL);
  //OPEN_EXISTING = Só tentar abrir se o console existir;
  if (console == INVALID_HANDLE_VALUE)
		return -1;
// ^ Se o console for Inválido retorna um número negativo; ^
// V tenta atribuir as informações do console atual que foi pego acima no Struct de informações; V
  if (GetConsoleScreenBufferInfo(console, &info) == 0)
		return -1;
// ^ Caso não consiga atribuir nada (Return 0;) a função retorna um número negativo; ^
// V Fecha o acesso ao console p/ liberar espaço para outras aplicações que possam usar ele; V
  CloseHandle(console);
 

  if(c == 'x'|| c == 'X'|| c == 0)
  size = abs(info.srWindow.Right - info.srWindow.Left + 1);
  else if(c == 'y'|| c == 'Y'|| c == 0)
  size = abs(info.srWindow.Bottom - info.srWindow.Top + 1);
  else 
    return -1;

  return  size;

}

