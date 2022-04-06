#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///1. Sumar los elementos de una pila (usar variables enteras)
///2. Contar los elementos de una pila (usar variables enteras)
///3. Hacer el promedio de los elementos de una pila

int main()
{
    Pila DADA;
    Pila AUX;
    char continuar='n';
    float promedio=0;
    int suma=0; ///acumulador
    int i=0; ///contador
    inicpila(&DADA);
    inicpila(&AUX);

    while(continuar == 's' || continuar == 'S')
    {
        leer(&DADA);
        printf("Desea ingresar otro valor? s/n \n");
        fflush(stdin);
        scanf("%c",&continuar);

    }

///conservamos la pila (devolvemos los valores de aux hacia ella)
    while (!pilavacia(&DADA))
    {
        suma = suma + tope(&DADA); /// suma += tope(&DADA);
        apilar(&AUX,desapilar(&DADA));
        i++;
    }

    if (i != 0)
        promedio = (float)suma/i;

    while (!pilavacia(&AUX))
    {
        apilar(&DADA,desapilar(&AUX));
    }
    printf("La suma es %i\n", suma);
    printf("La cantidad de elementos es %i\n", i);
    printf("El promedio es %.2f", promedio);


    return 0;
}


/**
Encontrar el menor elemento de una pila y guardarlo en otra.
(sin variables enteras, solo pilas)
**/

int main()
{
    Pila DADA;
    Pila AUX;
    Pila BASURA;
    char continuar;
    Pila MENOR;
    inicpila(&MENOR);
    inicpila(&DADA);
    inicpila(&AUX);
    inicpila(&BASURA);
    do
    {
        leer(&DADA);
        printf("Desea ingresar otro valor?s\n /n");
        fflush(stdin);
        scanf("%c",&continuar);

    }
    while(continuar == 's' || continuar == 'S');


    apilar(&MENOR,tope(&DADA));
    apilar(&AUX,desapilar(&DADA));
    while (!pilavacia(&DADA))
    {
        if (tope(&MENOR) > tope(&DADA))
        {
            apilar(&BASURA,desapilar(&MENOR));
            apilar(&MENOR,tope(&DADA));
            apilar(&AUX,desapilar(&DADA));
        }
        else
        {
            apilar(&AUX,desapilar(&DADA));
        }
    }

    while(!pilavacia(&AUX))
    {
        apilar(&DADA,desapilar(&AUX));
    }

    return 0;
}

/**
Usando lo resuelto en el ejercicio 4,
pasar los elementos de una pila a otra de forma tal que la segunda pila
quede ordenada de mayor (tope) a menor (base).
Esto se llama m�todo de ordenaci�n por selecci�n.
**/


int main()
{
    Pila DADA;
    Pila AUX;
    char continuar;
    Pila MENOR;
    inicpila(&MENOR);
    inicpila(&DADA);
    inicpila(&AUX);
    do
    {
        leer(&DADA);
        printf("Desea ingresar otro valor?s/n \n");
        fflush(stdin);
        scanf("%c",&continuar);

    }
    while(continuar == 's' || continuar == 'S');


    while (!pilavacia(&DADA))
    {
        apilar(&MENOR,desapilar(&DADA));

        while (!pilavacia(&DADA)) ///busco el menor y lo paso a la otra pila (lo elimino de dada)
        {
            if (tope(&MENOR) > tope(&DADA))
            {
                apilar(&AUX,desapilar(&MENOR));
                apilar(&MENOR,desapilar(&DADA));
            }
            else
            {
                apilar(&AUX,desapilar(&DADA));
            }
        }
        while (!pilavacia(&AUX)) ///devuelvo los restantes (los que estan en aux) a dada
        {
            apilar(&DADA,desapilar(&AUX));
        }
    }

    mostrar(&MENOR);

//    while (!pilavacia(&MENOR))
//    {
//        apilar(&DADA,desapilar(&MENOR));
//    }
//    mostrar(&DADA);


    return 0;
}
/**

Insertar un elemento en una pila ordenada de menor (tope) a mayor (base)
de forma tal que se conserve el orden. (sin variables, solo pilas)
**/

int main()
{
    Pila p;
    Pila aux;
    int valor;
    char continuar;
    inicpila(&p);
    inicpila(&aux);

    do
    {
        printf("Ingrese un valor a insertar \n");
        scanf("%i",&valor);

        while (!pilavacia(&p) && tope(&p) > valor )
        {
            apilar(&aux,desapilar(&p));
        }

        apilar(&p,valor);
        while(!pilavacia(&aux))
        {
            apilar(&p,desapilar(&aux));
        }
        printf("desea continuar?\n");
        fflush(stdin);
        scanf("%c", &continuar);
    }
    while(continuar == 's' || continuar == 'S');

    mostrar(&p);
    return 0;
}


