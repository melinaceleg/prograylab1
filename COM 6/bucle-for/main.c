#include <stdio.h>
#include <stdlib.h>

/**
    while :
    while (condicion) {
        sentencias
        ...
        sentencias..

    }
    /// CONDICION - SENTENCIAS - CONDICION - Sentencias...

    do-while:

    do {
        sentencias
        ..
        sentencias
    }while(condicion);
    /// SENTENCIAS - CONDICION - SENTENCIAS - CONDICION - SENTENCIAS ...

    for-para:

    PARA i = 1 hasta N Con Paso 1 Hacer
      sentencias
      ..
      sentencias
    Fin-Para

    for:

    -> inicializa la variable en un valor
    -> itera hasta que la condicion central sea falsa
    -> incrementa o decrementa el valor de la variable en una cantidad fija
    -> el for se utiliza cuando sabemos de antemano la CANTIDAD DE VECES QUE VAMOS A ITERAR
       -> tenemos un contador

    for (i = 1 ; i<=N ; i++)
    {
      sentencias
      ..
      sentencias
    }

    INICIALIZACION - CONDICION - SENTENCIAS
    INCREMENTO - CONDICION - SENTENCIAS
    INCREMENTO - CONDICION - SENTENCIAS
    ....

///imprimir los numeros enteros del 1 al 10
**/

///ambito global

int main()
{
///ambito del main
   //int i;
    for (int i=1; i<=10; i++) //desde i=1; mientras i<=10l; incremento de 1 en 1
    {
        ///ambito del for
        //int suma = 3;
        printf("%i ",i);
    }

 ///hacer una suma de numeros ingresados por el usuario hasta que le usuario ingrese un 0
 ///do-while o while

    //printf("Aca termina el bucle for, valor final de i: %i",i);

//////con un while
//    int i;
//    i=1;
//    while (i<=10)
//    {
//        printf("%i ", i);
//        i++; ///i = i+1
//    }



    return 0;
}
