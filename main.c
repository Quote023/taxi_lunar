#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include "crctrl.h" //funcão GOTOXY
#include "game.h"
#include "ascii.h"
#include "car.h"
#include "stars.h"


int main(void)
{
    setlocale(LC_ALL, "");
    int wState = 0; 
    ShowConsoleCursor(0);
    consoleInfo('s');
    menu(&wState);

    getchar();
    return 0;
}
