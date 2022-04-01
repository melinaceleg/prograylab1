#include <stdio.h>
#include <stdlib.h>

/**
12. Suponiendo la existencia de una pila MODELO (vacía o no), eliminar de la pila DADA todos los elementos que existan en MODELO.
**/

int main()
{
    int basura;
    Pila MODELO;
    Pila AUX1;
    Pila DADA;
    Pila AUX2;
    inicpila(&MODELO);
    inicpila(&DADA);
    inicpila(&AUX1);
    inicpila(&AUX2);
    while (!pilavacia(&MODELO))
    {
        apilar(&AUX1,desapilar(&MODELO));  ///quito un elemento de modelo para luego usar tope de aux1 en la comparacion

        while (!pilavacia(&DADA))
        {
            if (tope(&AUX1) != tope(&DADA))   ///conservo el elemento, por lo tanto lo llevo a aux2
            {
                apilar(&AUX2, desapilar(&DADA));
            }
            else ///elimino el elemento
            {
                basura = desapilar(&DADA);
            }
        }
        while (!pilavacia(&AUX2))       ///devuelvo los elementos a dada para volver a comparar con el siguiente elemento de aux
        {
            apilar(&DADA,desapilar(&AUX2));
        }
    }
    while (!pilavacia(&AUX1))    ///devuelvo los elementos que se encuentran en aux1 a modelo , por lo tanto se conserva modelo
    {
        apilar(&MODELO,desapilar(&AUX1));
    }
    return 0;
}
