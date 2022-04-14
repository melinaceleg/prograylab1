#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///prototipado
void cargaPila(Pila*);

///hacer una funcion que cargue una pila por teclado recibida por parametro por referencia.

///implementacion
void cargaPila(Pila* p)     //// p = 0x60
{

    char continuar;
    do
    {
        leer(p);
        printf("Desea continuar?\n");
        fflush(stdin);
        scanf("%c",&continuar);


    }
    while (continuar == 's' || continuar == 'S');


}

///Hacer una función que pase todos los elementos de una pila a otra.
void pasarPilas(Pila*,Pila*);
///Hacer una función que copie todos los elementos de una pila a otra.
void copiarPilas(Pila,Pila*);



/// &A 0x60
int main()
{
    Pila A;
    Pila B;
    inicpila(&A);
    inicpila(&B);
    leer(&A)
    cargaPila(&A);
    mostrar(&A);



    return 0;
}
