#include <stdio.h>
#include <stdlib.h>
/**
FOR

///el bucle for- para sirve para variables contadoras (incrementan en valor fijo)
  -> sirve cuando sabemos que debemos iterar N veces (N LO CONOCEMOS)
  definir i como entero
  -> inicializa la variable, dice hasta donde llegar, y la incrementa de 1 en 1, de 2 en 2,
  etc..
   PARA i = 1 hasta N con paso 1
    SENTENCIAS
    ..
    SENTENCIAS
   FIN-PARA

**/

///Realizar un programa que imprima en pantalla los números del 1 al 100.
int main()
{
    ///INICIALIZACION - CONDICION - SENTENCIAS
    /// INCREMENTO - CONDICION - SENTENCIAS..
    /// INCREMENTO -CONDICION - SENTENCIAS..
    /// INCREMENTO - CONDICION - SENTENCIAS..
    int i;
    for (i=1; i<=100 ; i++) //valor inicial ; condicion de iteracion ; incremento
    {
        printf("%i ", i); ///se ejecuta 100 veces
    }
    ///la variable i, cuando la declaro dentro del for, SOLO EXISTE DENTRO DE SU AMBITO
    printf("valor final de i: %i", i);


    return 0;
}
