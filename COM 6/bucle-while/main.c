#include <stdio.h>
#include <stdlib.h>

/**MIENTRAS**/

///Desarrolle un algoritmo que permita visualizar los números del 1 al 10

/**

   MIENTRAS (CONDICION) HACER
     ....
   FIN-MIENTRAS


   definir numero como entero
   numero = 1
   mientras (numero <= 10) hacer
      mostrar numero
      numero = numero + 1
   fin-mientras
***/

///contador (incrementa en un valor fijo)
/// generalmente se denominan con letras (i,j,k..)
///se deben inicializar en un valor
///se incrementan en un valor fijo (de 1 en 1, de 2 en 2...)
int main()
{
    int i;
    i=1; ///inicializacion del contador
    while (i <= 10)
    {
        printf("%i ", i);
        i++; ///i=i+1;
    }



    return 0;
}
