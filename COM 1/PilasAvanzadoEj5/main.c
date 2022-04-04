#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**

5 Insertar N elementos en una pila ordenada de menor (tope) a mayor (base)
de forma tal que se conserve el orden. (sin variables, solo pilas)

**/
//int main()
//{
//    Pila p;
//    Pila aux;
//    Pila x;
//    inicpila(&p);
//    inicpila(&aux);
//    inicpila(&x);
//
////    apilar(&p,3);
////    apilar(&p,2);
////    apilar(&p,1);
//
//    apilar(&x,2);
//    apilar(&x,1);
//    apilar(&x,7);
//    apilar(&x,3);
//
//    while (!pilavacia(&x))
//    {
//
//        while (!pilavacia(&p) && tope(&p) < tope(&x))
//        {
//            apilar(&aux,desapilar(&p));
//
//        }
//        apilar(&p,desapilar(&x));
//
//        while (!pilavacia(&aux)) ///vuelvo a apilar en p los elementos de aux
//        {
//            apilar(&p,desapilar(&aux));
//        }
//    }
//
//    mostrar(&p);
//
//
//    return 0;
//}


/**6 Usando lo resuelto en el ejercicio 4,
pasar los elementos de una pila a otra de forma tal que
la segunda pila quede ordenada de mayor (tope) a menor (base).
 Esto se llama método de ordenación por selección. **/

//int main()
//{
//    Pila p;
//    Pila aux;
//    Pila menor;
//    inicpila(&p);
//    inicpila(&aux);
//    inicpila(&menor);
//
//    apilar(&p,2);
//    apilar(&p,1);
//    apilar(&p,4);
//    apilar(&p,5);
//
//    while (!pilavacia(&p))
//    {
//        apilar(&menor,desapilar(&p));
//        while (!pilavacia(&p)) ///proceso de seleccionar el menor y quitarlo de la pila
//        {
//
//            if (tope(&p) < tope(&menor))
//            {
//                apilar(&aux,desapilar(&menor));
//                apilar(&menor,desapilar(&p));
//            }
//            else
//                apilar(&aux,desapilar(&p));
//        }
//        while (!pilavacia(&aux))
//        {
//            apilar(&p,desapilar(&aux));
//        }
//
//    }
//    mostrar(&menor);
//
//    ///si quisiese devolver todos los elementos a la pila original
////    while(!pilavacia(&menor))
////    {
////        apilar(&p,desapilar(&menor));
////    }
////
////    mostrar(&p);
//
//}

/**
eterminar si un elemento buscado está dentro de una pila.
Al encontrarlo, finalizar la búsqueda.
**/

int main()
{
    Pila p;
    inicpila(&p);
    int basura;
    int valor;
    apilar(&p,2);
    apilar(&p,1);
    apilar(&p,4);
    apilar(&p,5);

    printf("Ingrese el valor que desea buscar\n");
    scanf("%i", &valor);

    //corte del bucle:
    //-(p && q) = !p || !q

    while (!pilavacia(&p) && tope(&p) != valor)
    {
        basura= desapilar(&p);
    }

    if (!pilavacia(&p))
        printf("Se encontro el elemento\n");




    return 0;

}
