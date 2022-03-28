#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>
#define CANT_CARTAS 39

/**
1. Cargar desde el teclado una pila DADA con 5 elementos. Pasar los tres
 primeros elementos que se encuentren en el tope a la pila AUX1
 y los restantes a la pila AUX2.

**/

int main()
{
    Pila DADA, AUX1, AUX2;
    inicpila(&DADA);
    inicpila(&AUX1);
    inicpila(&AUX2);

    for (int i = 0; i < 5 ; i++)
    {
       leer(&DADA);
    }

    printf("DADA: \n");
    mostrar(&DADA);
    printf("AUX1: \n");
    mostrar(&AUX1);
    printf("AUX2: \n");
    mostrar(&AUX2);
    printf("\n");

    ///DADA -> tope 5 7 9 3 1 base

    for (int i = 1 ; i <= 3 ; i++)
    {
        apilar(&AUX1,desapilar(&DADA));
    }
    printf("Despues de quitarle 3 elementos y pasarlos a AUX1: \n");
    printf("DADA: \n");
    mostrar(&DADA);
    printf("AUX1: \n");
    mostrar(&AUX1);
    printf("AUX2: \n");
    mostrar(&AUX2);
    printf("\n");
    ///DADA -> tope 3 1 base
    ///AUX1 -> tope 9 7 5 base

    while (!pilavacia(&DADA))
    {
        apilar(&AUX2,desapilar(&DADA));
    }
    printf("DEspues de quitarle los restantes y pasarlos a aux2\n");
    printf("DADA: \n");
    mostrar(&DADA);
    printf("AUX1: \n");
    mostrar(&AUX1);
    printf("AUX2: \n");
    mostrar(&AUX2);
    /// DADA -> tope base
    /// AUX1 -> tope 9 7 5 base
    /// AUX2 -> tope 1 3 base


    return 0;
}

/**

3. Cargar desde teclado una pila DADA y
pasar a la pila DISTINTOS todos aquellos elementos distintos al valor 8.
**/
int main()
{
    Pila DADA;
    Pila DISTINTOS;
    Pila AUX;
    int valor;
    char continuar;
    inicpila(&DADA);
    inicpila(&DISTINTOS);
    inicpila(&AUX);

    do
    {
        leer(&DADA);
        printf("Desea continuar? s\n /n");
        fflush(stdin);
        scanf("%c",&continuar);
    }
    while (continuar == 's' || continuar == 'S');

    printf("DADA: \n");
    mostrar(&DADA);
    printf("DISTINTOS: \n");
    mostrar(&DISTINTOS);
/////Forma 1 : conservando los 8's, usando AUX
//    while (!pilavacia(&DADA))
//    {
//        if (tope(&DADA) != 8)
//        {
//            apilar(&DISTINTOS,desapilar(&DADA));
//        }
//        else
//            apilar(&AUX, desapilar(&DADA));
//    }
//    while (!pilavacia(&AUX))
//    {
//        apilar(&DADA,desapilar(&AUX));
//    }



    ///forma 2: no conservando los 8's, uso int valor
    while (!pilavacia(&DADA))
{
    if (tope(&DADA) != 8)
        {
            apilar(&DISTINTOS,desapilar(&DADA));

        }
        else
        {
            valor = desapilar(&DADA);
        }
    }
    printf("DADA: \n");
    mostrar(&DADA);
    printf("DISTINTOS: \n");
    mostrar(&DISTINTOS);
    return 0;
}




/**

8. Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa.

**/

int main()
{
    Pila MAZO;
    Pila JUGADOR1;
    Pila JUGADOR2;
    inicpila(&MAZO);
    inicpila(&JUGADOR1);
    inicpila(&JUGADOR2);

    srand(time(NULL)); ///le doy un valor inicial, una semilla que alimenta los valores aleatorios basado en el reloj de mi pc

    for (int i = 1 ; i<= CANT_CARTAS; i++)
    {
        apilar(&MAZO, (rand() % 12) + 1); ///operador resto me devuelve 0 hasta N-1
    }

    ///PARA MANANA, considerar MAZO CON CANTIDAD PAR o MAZO CON CANTIDAD IMPAR
    mostrar(&MAZO);


}


