#include <stdio.h>
#include "crctrl.h" //funcão GOTOXY
#include "game.h"


int main(void)
{
    int wState = 0; 
    showConsoleCursor(0);
    consoleInfo('s');
    menu(&wState);
    getchar();
    return 0;
}
