#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
/**
Buscar el menor elemento de una pila y mostrarlo,la pila debe conservarse
**/

int main()
{
    Pila p;
    Pila aux;
    Pila menor;
    inicpila(&p);
    inicpila(&aux);
    inicpila(&menor);

    apilar(&p,2);
    apilar(&p,1);
    apilar(&p,4);
    apilar(&p,5);

    if (!pilavacia(&p))
    {
        apilar(&menor,tope(&p));
        while (!pilavacia(&p))
        {
            apilar(&aux,desapilar(&p));
            if (tope(&p) < tope(&menor))
            {
                basura=desapilar(&menor);
                apilar(&menor,tope(&p));
            }
        }
        while (!pilavacia(&aux))
        {
            apilar(&p,desapilar(&aux));
        }

        printf("El menor es %i", menor);
        mostrar(&p);
    }



/////2da forma
//    apilar(&aux,desapilar(&p));
//    menor = tope(&aux);
//
//    while (!pilavacia(&p))
//    {
//        if (tope(&p) < menor)
//        {
//            menor = tope(&p);
//        }
//        apilar(&aux,desapilar(&p));
//    }



    return 0;
}


/**
Buscar el menor elemento de una pila, eliminarlo y mostrarlo, el resto de la pila debe conservarse
**/
