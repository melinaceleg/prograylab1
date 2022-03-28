#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
   PILA
   ->coleccion o lista de elementos donde se pueden agregar o extraer desde el tope
   -> permite hasta 50 elementos de tipo entero
   -> las pilas son solamente de enteros (int)
   FUNCIONES
   Pila p -> Crear pila
   inicpila(&p) -> inicializar la pila (dejarla lista para usar)
   apilar(&p, valor) -> ingresa un valor en el tope de la pila
   pilavacia(&p) -> nos devuelve 1 si esta vacia, de caso contrario 0
   tope(&p) -> nos devuelve el valor en el tope de la pila, PERO NO LO QUITA
   mostrar(&p) -> nos imprime los valores de la pila
   leer(&p) -> lee un dato desde el teclado y lo ingresa al tope de la pila (apilar)

**/

int main()
{
    Pila p;
    Pila aux;
    inicpila(&p);
    inicpila(&aux);
    int valor;
    char continuar;
    do
    {
//        printf("Ingrese un valor entero: ");
//        scanf("%i", &valor);
//        apilar(&p, valor);
        leer(&p);
        printf("Desea continuar? s/n \n");
        fflush(stdin);
        scanf("%c", &continuar);

    }
    while(continuar == 's' || continuar == 'S');

//    printf("TOPE ------");
//    while (!pilavacia(&p)) /// pilavacia(&p) == 0
//    {
//        //valor = desapilar(&p);
//        printf("%i ", tope(&p));
//        apilar(&aux, desapilar(&p));
//
//    }
//    printf("----BASE");
//
//    while (!pilavacia(&aux))
//    {
//        apilar(&p, desapilar(&aux));
//    }

    //mostrar(&p);

    return 0;
}
