#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**

1. Cargar desde el teclado una pila DADA con 5 elementos.
Pasar los tres primeros elementos que se encuentren en el tope a la pila AUX1
y los restantes a la pila AUX2.

**/

int main()
{
    Pila DADA;
    Pila AUX1;
    Pila AUX2;
    inicpila(&DADA);
    inicpila(&AUX1);
    inicpila(&AUX2);

    for (int i = 1 ; i <= 5 ; i++)
    {
        leer(&DADA);
    }
    printf("Despues de cargar dada...\n");
    printf("DADA:\n");
    mostrar(&DADA);
     printf("AUX1:\n");
    mostrar(&AUX1);
    printf("AUX2:\n");
    mostrar(&AUX2);


    for (int i = 1; i <= 3; i++)
    {
        apilar(&AUX1,desapilar(&DADA)); ///apilo en aux1, lo que desapilo de dada
    }
    printf("DEspues de desapilar 3 elementos de dada..\n");
    printf("DADA:\n");
    mostrar(&DADA);
    printf("AUX1:\n");
    mostrar(&AUX1);
    printf("AUX2:\n");
    mostrar(&AUX2);

    while (!pilavacia(&DADA)) ///mientras NO este vacia DADA
    {
        apilar(&AUX2,desapilar(&DADA));
    }
    printf("DEspues de desapilar los restantes de dada..\n");
    printf("DADA:\n");
    mostrar(&DADA);
    printf("AUX1:\n");
    mostrar(&AUX1);
    printf("AUX2:\n");
    mostrar(&AUX2);



    return 0;
}


/**
2. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
 Pasar todos los elementos de la pila ORIGEN a la pila DESTINO.
**/

int main()
{
    Pila ORIGEN;
    Pila DESTINO;
    char continuar;
    inicpila(&ORIGEN);
    inicpila(&DESTINO);

//    printf("Desea agregar un valor? s/n \n");
//    fflush(stdin);
//    scanf("%c", &continuar);
//    while (continuar == 's' || continuar == 'S')
//    {
//        leer(&ORIGEN);
//        printf("Desea agregar otro valor? \n");
//        fflush(stdin);
//        scanf("%c", &continuar);
//    }

    do
    {
        leer(&ORIGEN);
        printf("Desea agregar otro valor? s/n \n"); ///salida de caracteres
        fflush(stdin); ///limpieza del flujo de datos (buffer)
        scanf("%c", &continuar); /// entrada de caracteres
    }
    while(continuar == 's' || continuar == 'S');

    printf("ORIGEN: \n");
    mostrar(&ORIGEN);

    while (!pilavacia(&ORIGEN))
    {
        apilar(&DESTINO,desapilar(&ORIGEN));
    }
    printf("DESTINO: \n");
    mostrar(&DESTINO);

    return 0;
}

/**
3. Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos elementos distintos al valor 8.
**/

int main()
{
    Pila DADA;
    Pila DISTINTOS;
    Pila AUX;
    char continuar;
    int valor; ///la uso para el descarte
    inicpila(&DADA);
    inicpila(&DISTINTOS);
    inicpila(&AUX);
    do
    {
        leer(&DADA);
        printf("Desea agregar otro valor? s/n \n"); ///salida de caracteres
        fflush(stdin); ///limpieza del flujo de datos (buffer)
        scanf("%c", &continuar); /// entrada de caracteres
    }
    while(continuar == 's' || continuar == 'S');

//Caso en el que se conservan los 8's en la pila DADA
//uso Pila aux como puente
//    while (!pilavacia(&DADA))
//    {
//        if (tope(&DADA) == 8)
//        {
//            apilar(&AUX, desapilar(&DADA));
//        }
//        else
//        {
//            apilar(&DISTINTOS,desapilar(&DADA));
//        }
//    }
//    while (!pilavacia(&AUX))
//    {
//        apilar(&DADA,desapilar(&AUX));
//    }


//Caso en el que no conservo los 8's
// uso int valor como descarte
    while (!pilavacia(&DADA))
    {

        if (tope(&DADA) == 8)
        {
            valor=desapilar(&DADA);
        }
        else
            apilar(&DISTINTOS,desapilar(&DADA));
        }



    return 0;
}

/**
8. Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa.
**/

#include <time.h>
#define CANT_CARTAS 40
#define NUMERO_MAX 12
#define NUMERO_MIN 1

int main()
{
    Pila MAZO;
    Pila JUGADOR1;
    Pila JUGADOR2;
    int valor;
    srand(time(NULL)); ///semilla (reloj de la pc) que alimenta la formula matematica que nos da un valor al azar
    inicpila(&MAZO);
    inicpila(&JUGADOR1);
    inicpila(&JUGADOR2);


    for (int i = 1; i <= CANT_CARTAS ; i++)
    {
        valor = (rand() % NUMERO_MAX) + NUMERO_MIN;
        while (valor == 8 || valor == 9) ///validacion para no tomar los 8's y los 9's
        {
            valor = (rand() % 12) + 1;
        }
        apilar(&MAZO,  valor); /// el operador resto devuelve un valor entre 0 y N-1 (siendo N el divisor)
    }

///otra forma
//    int i=1;
//    while (i<=40)
//    {
//        valor = (rand() % 12) + 1;
//        if (valor != 8 && valor != 9)
//        {
//            apilar(&MAZO,  valor);
//            i++;
//        }
//    }

    while (!pilavacia(&MAZO))
    {
        apilar(&JUGADOR1,desapilar(&MAZO));
        if (!pilavacia(&MAZO))
        {
            apilar(&JUGADOR2,desapilar(&MAZO));
        }
    }

    mostrar(&JUGADOR1);
    mostrar(&JUGADOR2);



 return 0;
}



