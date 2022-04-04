#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
12. Suponiendo la existencia de una pila MODELO (vacía o no),
eliminar de la pila DADA todos los elementos que existan en MODELO.
**/

int main()
{
    Pila MODELO;
    Pila DADA;
    Pila auxMODELO;
    Pila auxDADA;
    int basura;
    inicpila(&DADA);
    inicpila(&MODELO);
    inicpila(&auxDADA);
    inicpila(&auxMODELO);

    apilar(&MODELO,3);
    apilar(&MODELO,5);
    apilar(&MODELO,7);

    apilar(&DADA,1);
    apilar(&DADA,4);
    apilar(&DADA,3);
    apilar(&DADA,5);


    while (!pilavacia(&MODELO))
    {
       // apilar(&auxMODELO, desapilar(&MODELO));
        while (!pilavacia(&DADA))
        {
            if (tope(&DADA) == tope(&MODELO)) ///si el tope es igual debo eliminarlo
            {
                basura = desapilar(&DADA); ///lo desapilo en euna variable entera
            }
            else
            {
                apilar(&auxDADA,desapilar(&DADA)); ///conservo el valor apilandolo en aux
            }

        }
        apilar(&auxMODELO,desapilar(&MODELO));
        while (!pilavacia(&auxDADA)) ///devuelvo los elementos de aux hacia dada para avanzar con la siguiente comparacion
        {
            apilar(&DADA,desapilar(&auxDADA));
        }
    }

    while (!pilavacia(&auxMODELO)) ///devuelve los elementos a modelo
    {
        apilar(&MODELO,desapilar(&auxMODELO));
    }

    printf("DADA:");
    mostrar(&DADA);
    printf("MODELO: ");
    mostrar(&MODELO);



    return 0;
}
