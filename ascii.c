/*TO-DO: COLOCAR OS TEXTOS DO LOGO/CARRINHO AQUI*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "crctrl.h"


int elipse(int X,int Y,short f,char fill)
{

    int i,j,maior;//,menor;
    int offset = consoleInfo('X') < 92 ? 7 : 0;
    float eX,eY;

     if(X > Y){ maior = X;} //crmove(-X,Y);
     else { maior = Y;} //crmove(-Y,X);

        gotoxy(0,0);
 
        crmove(-X + offset,Y/2 - 2);
      

    for(i = Y - 2; i >= -Y/2 ;i--)
    {
        for (j = -X; j <= X + offset/2; j++)
        {
            eX = pow(j,2)/pow(X,2);
            eY = pow(i+5,2)/pow(Y,2);

            if(eX + eY <= 1 )
            {
                if(rand()% 100 < 30)    textcolor(34); //Verde
                    else                textcolor(59); //Azul
                
                printf("%c",fill);
            }
            else
            crmove(1,0);
        }
        if(crmove(-X*2 - 1,-1)) break;
    }

    gotoxy(0,0);
    return 0;
}
