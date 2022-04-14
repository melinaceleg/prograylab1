#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
/**
Hacer una funcion que cargue elementos en una pila por teclado
**/
//salida: void
//entrada: Pila *

///prototipos
void cargaPila(Pila*); ///funcion para cargar una pila
void mostrarPila(Pila);
void pasarPila(Pila*,Pila*); ///2. Hacer una función que pase todos los elementos de una pila a otra.
void copiarPila(Pila,Pila*); ///Hacer una función que copie todos los elementos de una pila a otra.

void pasarPila(Pila* p1, Pila* p2) /// p1 = 0x55  , p2 = 0x66
{
    while (!pilavacia(p1))
    {
        apilar(p2,desapilar(p1));
    }


}

void copiarPila(Pila p1,Pila* p2) ///p1 = base 3 4 5 6 tope , p2 = 0x77
{
    while (!pilavacia(&p1))
    {
        apilar(p2,desapilar(&p1));
    }

}




void mostrarPila(Pila p) /// p =  base 4 5 6 7 tope
{
    int dato;
    printf("\ntope.......................base\n");
    while (!pilavacia(&p))
    {
        dato = desapilar(&p);
        printf("| %i |", dato);
    }
    printf("\ntope.......................base\n");

}



void cargaPila(Pila* p) /// p = 0x44
{
    char continuar;
    do
    {

        leer(p);
        printf("desea continuar?\n");
        fflush(stdin);
        scanf("%c",&continuar);

    }
    while (continuar =='s' || continuar == 'S');

}








int main()
{
    Pila A;
    Pila B;
    inicpila(&A);
    inicpila(&B);
    cargaPila(&A);
    mostrarPila(A);
    //pasarPila(&A,&B);
    copiarPila(A,&B);
    mostrarPila(A);
    mostrarPila(B);

    return 0;
}
