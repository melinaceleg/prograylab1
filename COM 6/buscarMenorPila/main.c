#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
/**
Realizar la busqueda del menor elemento de una pila DADA y mostrarlo (cargada con al menos X cantidad de enteros, X>0 cargada por el usuario o no)
**/

///CASO 1: LA PILA NO SE CONSERVA
//int main()
//{
//    Pila DADA;
//    char continuar;
//    int menor;
//    int basura;
//    inicpila(&DADA);
//    do
//    {
//        leer(&DADA);
//        printf("Desea ingresar otro valor?s\n /n");
//        fflush(stdin);
//        scanf("%c",&continuar);
//
//    }
//    while(continuar == 's' || continuar == 'S');
//
//    menor = desapilar(&DADA);
//    while (!pilavacia(&DADA))
//    {
//        if (menor > tope(&DADA))
//        {
//            menor = desapilar(&DADA);
//        }
//        else
//        {
//            basura = desapilar(&DADA);
//        }
//    }
//
//    printf("El elemento menor de DADA es : %i\n", menor);
//    mostrar(&DADA);
//
//    return 0;
//}

///CASO 2: LA PILA SE CONSERVA
int main()
{
    Pila DADA;
    Pila AUX;
    char continuar;
    int menor;
    inicpila(&DADA);
    inicpila(&AUX);
    do
    {
        leer(&DADA);
        printf("Desea ingresar otro valor?s\n /n");
        fflush(stdin);
        scanf("%c",&continuar);

    }
    while(continuar == 's' || continuar == 'S');

    menor = tope(&DADA);
    apilar(&AUX,desapilar(&DADA));
    while (!pilavacia(&DADA))
    {
        if (menor > tope(&DADA))
        {
            menor = tope(&DADA);
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
    printf("El elemento menor de DADA es : %i\n", menor);
    mostrar(&DADA);


    return 0;
}
