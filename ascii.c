/*TO-DO: COLOCAR OS TEXTOS DO LOGO/CARRINHO AQUI*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "crctrl.h"

int drawRect(int X,int Y,char fill)
{
    int i,j;
    
    //gotoxy(-X/2,Y/2);

    for(i = 0; i < Y;++i)
    {
        for(j = 0; j < X; ++j)
        {
            if(i == 0 || i == Y-1 || j == 0 || j == X-1)
                textcolor(238);
            else
                textcolor(7);
            
            printf("%c",fill);
        }
        crmove(-X,-1);

    }


}



int elipse(short X,short Y,char fill)
{

    ScreenInfo      scr     = *getScreen();
    unsigned short  halfX   =      scr.X/2,
                    halfY   =      scr.Y/2,
                    offset  =   scr.X < 92 
                            ?            8 
                            :            0;
    float           eX,eY;
    int               i,j;




        gotoxy(-X + offset + 1,Y/2 - 2);
 
      

    for(i = Y; i >= -Y/2 + 8 ;i--)
    {
        for (j = -X; j <= X + offset/2; j++)
        {
            eX = pow(j,2)/pow(X,2);
            eY = pow(i+5,2)/pow(Y,2);

            if(eX + eY <= 1 && i != (Y - 5))
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
