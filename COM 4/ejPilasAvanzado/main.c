#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


/**
5 Insertar un elemento en una pila ordenada de ordenada (tope) a mayor (base) de forma tal que se conserve el orden.
 (sin variables enteras, solo pilas)
**/
//int main()
//{
//    Pila p;
//    Pila dato;
//    Pila aux;
//    char continuar;
//    inicpila(&p);
//    inicpila(&dato);
//    inicpila(&aux);
//
////    p ->  base tope
////    dato ->  base 4 3 7 tope
////    aux -> base  tope
//    do
//    {
//        leer(&dato);
//        while (!pilavacia(&p) && tope(&dato) < tope(&p))
//        {
//            apilar(&aux,desapilar(&p));
//        }
//
//        apilar(&p,desapilar(&dato));
//
//        while (!pilavacia(&aux))
//        {
//            apilar(&p,desapilar(&aux));
//        }
//        printf("Desea ingresar otro dato? s/n \n");
//        fflush(stdin);
//        scanf("%c",&continuar);
//
//    }while(continuar =='S' || continuar == 's');
//    mostrar(&p);
//
//    return 0;
//}

///si no quisiese insertar elementos repetidos
//    if ((!pilavacia(&p) && tope(&p) != tope(&dato)) || pilavacia(&p)) ///no apilo elementos repetidos
//    {
//       apilar(&p, desapilar(&dato));
//    }


/**6
Usando lo resuelto en el ejercicio 4,
pasar los elementos de una pila a otra de forma tal
 que la segunda pila quede ordenada de mayor (tope) a ordenada (base).
 Esto se llama método de ordenación por selección.
**/

int main()
{
    Pila p;
    Pila aux;
    Pila ordenada;
    inicpila(&p);
    inicpila(&aux);
    inicpila(&ordenada);

    apilar(&p,2);
    apilar(&p,1);
    apilar(&p,4);
    apilar(&p,5);

//    p -> base   tope
//    ordenada -> base 1 4 5 7 tope
//    aux -> base  tope

    while (!pilavacia(&p))
    {
        apilar(&menor,desapilar(&p));
        while (!pilavacia(&p)) ///selecciona el elemento menor (lo elimina de la pila y lo lleva hacia otra)
        {
            // apilar(&aux,desapilar(&p));
            if (tope(&p) < tope(&ordenada))
            {
                apilar(&aux,desapilar(&ordenada));
                apilar(&ordenada,desapilar(&p));
            }
            else
                apilar(&aux,desapilar(&p)); ///no es el menor, lo llevo directamente hacia aux
        }
        while (!pilavacia(&aux)) ///devuelve los restantes a la pila original
        {
            apilar(&p,desapilar(&aux));
        }
    }

    while (!pilavacia(&ordenada)) ///devuelvo los elementos ordenados a la pila original
    {
        apilar(&p,desapilar(&ordenada));
    }
    mostrar(&ordenada);



    return 0;
}

/**
Dada la pila ORIGEN ordenarla en forma ascendente por método de inserción
 dejando el resultado en la pila ORIGEN.
 Para este ejercicio usar lo aprendido para el ejercicio 5.
*/

int main()
{
    Pila ORIGEN;
    Pila aux2;
    Pila aux;
    inicpila(&ORIGEN);
    inicpila(&dato);
    inicpila(&aux2);

//    ORIGEN ->  base 4 5 6 1 tope
//    ORDENADA -> base 1 4 5 6  tope
//    dato ->  base  tope
//    aux -> base  tope

    while(!pilavacia(&ORIGEN)) ///a partir de una pila de datos desordenada, hago una insercion ordenada en otra pila
    {
        apilar(&dato,desapilar(&ORIGEN)); ///leer(&dato)
        while (!pilavacia(&ORDENADA) && tope(&dato) < tope(&ORDENADA))
        {
            apilar(&aux,desapilar(&ORDENADA));
        }

        apilar(&ORDENADA,desapilar(&dato));

        while (!pilavacia(&aux))
        {
            apilar(&ORDENADA,desapilar(&aux));
        }
    }
    while (!pilavacia(&ORDENADA)) ///le devuelvo los datos ordenados a la pila original
    {
        apilar(&ORIGEN,desapilar(&ORDENADA));
    }
    return 0;
}
