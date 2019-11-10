/*TO-DO: COLOCAR OS TEXTOS DO LOGO/CARRINHO AQUI*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "crctrl.h"


int elipse(int X,int Y,short f,char fill)
{
    ScreenInfo scr = *getScreen();
    int i,j,offset = scr.X < 92 ? 8 : 0;;//,menor;
    float eX,eY;

    

        gotoxy(-X + offset + 1,Y/2 - 2);
 
       // crmove(,);
      

    for(i = Y - 2; i >= -Y/2 + 2 ;i--)
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
