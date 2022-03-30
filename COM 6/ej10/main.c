#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


/** 10. Cargar las pilas A y B, y luego compararlas,
 evaluando si son completamente iguales
 (en cantidad de elementos, valores que contienen y posición de los mismos).
 Mostrar por pantalla el resultado.
 **/

int main()
{
    Pila A;
    Pila B;
    int basura;
    char continuar;
    inicpila(&A);
    inicpila(&B);
    printf("PILA A: \n");
    do
    {
        leer(&A);
        printf("Desea continuar? s/n \n");
        fflush(stdin);
        scanf("%c", &continuar);
    }
    while (continuar == 's' || continuar == 'S');


    printf("PILA B: \n");

    do
    {
        leer(&B);
        printf("Desea continuar?\n");
        fflush(stdin);
        scanf("%c", &continuar);
    }
    while (continuar == 's' || continuar == 'S');


    //-(p^q) = pilavacia(&A) o pilavacia(&B)

    while ((!pilavacia(&A) && !pilavacia(&B)) && (tope(&A) == tope(&B)))
    {
        basura = desapilar(&A);
        basura = desapilar(&B);

    }

    if (pilavacia(&A) && pilavacia(&B))
    {
        printf("Las pilas son identicas\n");
    }
    else
    {
        if (!pilavacia(&A) && !pilavacia(&B))
        {
            printf("Tienen elementos distintos\n");
        }
        else
        {
            if (!pilavacia(&A))
            {
                    printf("A tiene mas elementos que B\n");
            }
            else
            {
                printf("B tiene mas elementos que A\n");
            }
        }
        //printf("Las pilas son distintas\n");
    }

    printf("A:\n");

    mostrar(&A);
    printf("B:\n");
    mostrar(&B);


    return 0;
}
