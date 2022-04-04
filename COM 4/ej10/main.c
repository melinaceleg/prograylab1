#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
10. Cargar las pilas A y B, y luego compararlas,
evaluando si son completamente iguales (en cantidad de elementos,
valores que contienen y posición de los mismos).
Mostrar por pantalla el resultado.
**/

//int main()
//{
//    Pila A;
//    Pila B;
//    Pila auxA;
//    Pila auxB;
//    inicpila(&A);
//    inicpila(&B);
//    inicpila(&auxA);
//    inicpila(&auxB);
//
//    apilar(&A,1); ///base
//    apilar(&A,2);
//    apilar(&A,3); ///tope
//
//    //apilar(&B,4); ///base
//    apilar(&B,1);
//    apilar(&B,2);
//    apilar(&B,3); ///tope
//
//    while (!pilavacia(&A) && !pilavacia(&B) && tope(&A) == tope(&B))
//    {
//        apilar(&auxA,desapilar(&A));
//        apilar(&auxB,desapilar(&B));
//
//    }
//    if ((pilavacia(&A) && !pilavacia(&B)) || (!pilavacia(&A) && pilavacia(&B))) ///caso 1 -> alguna quedo con datos, pero no ambas
//    {
//        printf("Las pilas tienen distinta cantidad de elementos");
//    }
//    else
//    {
//        if (!pilavacia(&A) && !pilavacia(&B))  ///2do caso
//        {
//            printf("Las pilas son distintas"); ///(no tienen los mismos elementos y tienen la misma cantidad o no )
//        }
//        else
//        {
//            printf("Las pilas son identicas"); //caso 3
//        }
//    }
//    printf("\nA:");
//    mostrar(&A);
//
//    printf("\nB:");
//    mostrar(&B);
//
//    return 0;
//}

/**12. Suponiendo la existencia de una pila MODELO (vacía o no), eliminar de la pila DADA todos los elementos que existan en MODELO.
**/
//
//int main()
//{
//    Pila DADA;
//    Pila MODELO;
//    Pila auxMODELO;
//    Pila auxDADA;
//    int basura;
//    inicpila(&DADA);
//    inicpila(&MODELO);
//    inicpila(&auxDADA);
//    inicpila(&auxMODELO);
//
//    apilar(&DADA,1);
//    apilar(&DADA,3);
//    apilar(&DADA,5);
//
//    apilar(&MODELO,2);
//    apilar(&MODELO,3);
//    apilar(&MODELO,4);
//    apilar(&MODELO,1);
//
//    while (!pilavacia(&MODELO))
//    {
//
//        apilar(&auxMODELO,desapilar(&MODELO)); ///quito un elemento de modelo
//        while (!pilavacia(&DADA)) ///comparo el tope de auxModelo con cada uno de los  elementos de dada
//        {
//            if (tope(&DADA) == tope(&auxMODELO))
//            {
//                basura = desapilar(&DADA);
//            }
//            else
//            {
//                apilar(&auxDADA,desapilar(&DADA));
//            }
//        }
//        while (!pilavacia(&auxDADA)) ///devuelvo los elementos a dada para luego comparar con el siguiente de modelo
//        {
//            apilar(&DADA,desapilar(&auxDADA));
//        }
//    }
//
//    while (!pilavacia(&auxMODELO))
//    {
//        apilar(&MODELO,desapilar(&auxMODELO));
//    }
//
//    printf("DADA: \n");
//    mostrar(&DADA);
//    printf("MODELO: \n");
//    mostrar(&MODELO);
//
//
//    return 0;
//}


/**
14. Determinar si la cantidad de elementos de la pila DADA es par.
Si es par, pasar el elemento del tope de la pila AUX a la pila PAR
y si es impar pasar el tope a la pila IMPAR. (NO contar los elementos)
**/

int main()
{
    Pila PAR;
    Pila IMPAR;
    Pila AUX;
    Pila DADA;
    inicpila(&DADA);
    inicpila(&PAR);
    inicpila(&IMPAR);
    inicpila(&AUX);

    apilar(&DADA,2);
    apilar(&DADA,3);
    apilar(&DADA,4);
    apilar(&DADA,5);

    while (!pilavacia(&DADA))
    {
        apilar(&AUX,desapilar(&DADA));
        if (!pilavacia(&DADA))
        {
            apilar(&AUX,desapilar(&DADA));
        }
        else ///si no puedo desapilar el 2do elemento, es impar
            apilar(&IMPAR,desapilar(&AUX));
    }
    if (pilavacia(&IMPAR)) ///si no hay datos en impar significa que es par
    {
        apilar(&PAR,desapilar(&AUX));
    }


    printf("PAR:");
    mostrar(&PAR);
    printf("PAR:");
    mostrar(&IMPAR);



}
