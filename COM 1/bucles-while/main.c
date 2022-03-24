#include <stdio.h>
#include <stdlib.h>

/**
 definir i como entero
 i=1
 MIENTRAS (i <= 10) HACER
   mostrar i
   i = i +1;
 FIN-MIENTRAS


 Desarrolle un algoritmo que permita visualizar los números del 1 al 10
 **/

///while ---> CONDICION SENTENCIAS CONDICION SENTENCIAS......

int main()
{
    int i;  ///contador
    i = 1;
    while (i <= 10) ///primero evalua condicion
    {
        printf("%i ",i);
        i++; ///i = i +1;
    }

    return 0;
}
