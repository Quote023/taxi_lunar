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

    int wState = 0;

    showConsoleCursor(0);
    consoleInfo('s');
    menu(&wState);

    getchar();
    return 0;
}
