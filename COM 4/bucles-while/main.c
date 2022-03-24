#include <stdio.h>
#include <stdlib.h>
/**
  ///bucles
  repetir una porcion de codigo una y otra vez mientras se cumpla
  una determinada condicion

  MIENTRAS

  ESTRUCTURA:
    MIENTRAS CONDICION HACER
       SENTENCIAS
       ..
       SENTENCIAS
    FIN-MIENTRAS

  -> ver si dentro del ambito del bucle estamos en algun momento
  afectando a la condicion (el valor de la variable..)
  -> CONDICION - SENTENCIAS - CONDICION - SENTENCIAS....

Contador: incrementa/decrementa en un valor fijo (de 1 en 1.. de 2 en 2..)
Acumulador : Incrementa/decrementa en un valor variable (valores que le acumule)

Desarrolle un algoritmo que permita visualizar los números
 del 1 al 10.

  Definir i como entero
  i=1  //como todo contador, debo inicializar la variable
  mientras i<=10 hacer
    mostrar i
    i=i+1
  fin-mientras
  ...
  ...

**/

int main()
{
    int i;
    i=1;
    while (i<=10)
    {
        printf("%i ",i);
        i++; ///i=i+1;
    }
   printf("sali del bucle");
    return 0;
}
