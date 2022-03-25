#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**
 PILAS
 -> solo almacenan valores enteros
 -> tiene un limite de 50 datos
 -> siempre hay que inicializarlas luego de crearlas

 Funciones:
    inicpila(&p) -> inicializa la pila (para que se pueda usar)
    apilar(&p,valor) - > apila un valor en el tope de la pila
    leer(&p); -> lee un valor desde el teclado y lo ingresa en la pila
    desapilar(&p) -> desapila el valor que hay en el tope y lo devuelve
    pilavacia(&p) -> devuelve 1 si esta vacia, de lo contrario 0
    tope(&p) -> devuelve el valor del tope PERO NO LO DESAPILA
    mostrar(&p) -> muestra los  valores de la pila
**/
int main()
{
    char continuar;
    int valor;
    Pila p;
    Pila aux;
    inicpila(&aux);
    inicpila(&p); ///inicializando la pila
    do
    {
//        printf("Ingrese un valor\n");
//        scanf("%i", &valor);
//        apilar(&p,valor);
        leer(&p);
        printf("desea continuar?\n");
        fflush(stdin);
        scanf("%c",&continuar);
    }
    while(continuar != 'n');

//    printf("TOPE -- ");
//    while (!pilavacia(&p))
//    {
//        valor = desapilar(&p);
//        printf("%i ", valor);
//        apilar(&aux,valor);
//    }
//    printf("--BASE");
//    while (!pilavacia(&aux))
//    {
//        apilar(&p,desapilar(&aux));
//    }

    mostrar(&p);





    return 0;
}
