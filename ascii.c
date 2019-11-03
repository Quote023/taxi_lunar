/*TO-DO: COLOCAR OS TEXTOS DO LOGO/CARRINHO AQUI*/
#include <stdio.h>
#include <math.h>
#include "crctrl.h"

int circulo(int r,char fill)
{
    
    int i,j,dist;
    dist = r > 0 ? r : r * -1;
    crmove(-dist,dist);
    
    for(i = dist; i >= (r > 0 ? -dist : 0);i--)
    {
        for (j = -dist; j <= dist; j++)
        {
            crmove(1,0);
            if((i*i)+(j*j) <= (dist*dist))
            {
            printf("%c",fill);
            crmove(-1,0);
            }
        }
        crmove(-dist*2 - 1,-1);
    }
    
    gotoxy(0,0);

}

int elipse(int X,int Y,short f,char fill)
{
    
    int i,j,maior;//,menor;
    int k = consoleInfo('Y');

     if(X > Y){ maior = X;} //crmove(-X,Y);
     else { maior = Y;} //crmove(-Y,X);
        
       // gotoxy(0,0);
        crmove(-X,Y);

    for(i = maior; i > Y + 10;i--)
    {
        for (j = -maior; j <= maior; j++)
        {
            crmove(1,0);
            if((i*i)+(j*j) <= (maior*maior))
            {
            printf("%c",fill);
            crmove(-1,0);
            }
        }
        if(crmove(-X*2 - 1,-1)) break;
        // if(consoleInfo('V') >= consoleInfo('Y')) break;
    }
    
    gotoxy(0,0);

}