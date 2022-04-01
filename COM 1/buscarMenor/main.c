#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>
#include <math.h>

/**
Buscar el menor elemento de una pila y mostrarlo, la pila debe conservarse
 **/

int main()
{
    int menor;
    Pila p;
    Pila aux;
    inicpila(&p);
    inicpila(&aux);
    int var = -1;
    srand(time(NULL));
    int cantElementos = (rand() % 51); /// 50 elementos

    for (int i = 1 ; i <= cantElementos ; i++)
    {
        var = pow(var,rand() % 4); ///para que haya valores negativos o positivos
        apilar(&p, var*(rand() % 21)); ///apila valores del rango -20 a 20
    }

    mostrar(&p);

    if (!pilavacia(&p)) ///primero verifico que la pila tenga datos
    {
        apilar(&aux,desapilar(&p)); ///desapilo en aux para que en la comparacion no vuelva a usar el mismo elemento
        menor = tope(&aux); ///inicializo menor con el primer elemento de p (para luego comparar)

        while (!pilavacia(&p))
        {
            if (tope(&p) < menor) ///comparo cada elemento de p con menor y actualizo su valor
            {
                menor = tope(&p);
            }
            apilar(&aux,desapilar(&p)); ///desapilo en aux, haya o no haya sido menor

        }
        while (!pilavacia(&aux)) ///devuelvo los elementos de aux hacia p (para conservarla)
        {
            apilar(&p,desapilar(&aux));
        }

        printf("El menor elemento es: %i", menor);
    }
    else
    {
        printf("La pila esta vacia..\n");
    }
    mostrar(&p);


    return 0;
}
