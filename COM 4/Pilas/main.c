#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
  Pila
  -> es una coleccion de elementos que se agregan o quitan desde el tope
  -> solo almacena valores enteros
  -> puedo almacenar hasta 50 enteros

  inicpila(&p) --> inicializamos la pila (la dejamos lista para usar)
  apilar(&p,valor) --> agrega un elemento en el tope de la pila
  desapilar(&p) --> quita un elemento de la pila y lo devuelve
  tope(&p)  --> me devuelve lo que hay en el tope, pero no lo desapila
  pilavacia(&p) --> devuelve 1 si esta vacia, de lo contrario devuelve 0
   mostrar(&p);   --> nos muestra por pantalla el contenido de la pila
   leer(&p) --> pide un valor desde teclado y luego lo apila en la pila (p)

  Las variables auxiliares se utilizan como 'auxiliar' a casos como por ej: mostrar una pila sin perder los datos
  almacenar temporalmente valores que no queremos perder.

**/

int main()
{
    Pila p;
    Pila aux;
    int valor;
    char continuar;
    inicpila(&p); ///inicializamos la pila
    inicpila(&aux);
//    apilar(&p,5);
//    apilar(&p,6);
//    apilar(&p,1);

    do
    {
//        printf("Ingrese un valor entero: ");
//        scanf("%i", &valor);
//        apilar(&p,valor);
        leer(&p);
        printf("Desea agregar otro elemento?\n");
        fflush(stdin);
        scanf("%c", &continuar);

    }
    while(continuar == 's' || continuar == 'S');

    //valor = tope(&p);
    printf("El tope es: %i\n", tope(&p));

//    printf("TOPE --");
//    while (!pilavacia(&p)) /// pilavacia(&p) == 0
//    {
//        printf("%i ", tope(&p));
//        //valor = desapilar(&p);
//        apilar(&aux, desapilar(&p));
//        //printf("%i ",valor);
//
//    }
//    printf("--- BASE\n");
//
//    while (!pilavacia(&aux))
//    {
//      apilar(&p, desapilar(&aux));
//    }

   mostrar(&p);

    return 0;
}
