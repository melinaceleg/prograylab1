#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///prototipo
void cargaPila(Pila*); ///carga una pila por el usuario
void pasarElementos(Pila*,Pila*); //Hacer una función que pase todos los elementos de una pila a otra.
void copiarElementos(Pila,Pila*);//Hacer una función que copie todos los elementos de una pila a otra.

int main()
{
    Pila A;
    Pila B;
    inicpila(&A);
    inicpila(&B);

    cargaPila(&A); //cargaPila(0x55);
    mostrar(&A);
//    cargaPila(&B);// cargaPila(0x38);
//    mostrar(&B);

//    pasarElementos(&A,&B);
    copiarElementos(A,&B);
    printf("B: ");
    mostrar(&B);
    printf("A: ");
    mostrar(&A);


    return 0;
}

void cargaPila(Pila* p) /// p = 0x55
{
    char seguir;
    do
    {
        leer(p);
        printf("desea seguir s/n \n");
        fflush(stdin);
        scanf("%c", &seguir);

    }
    while(seguir == 's' || seguir == 'S');

}

void pasarElementos(Pila* p, Pila* h) /// p = 0x66, h = 0x70
{
    while (!pilavacia(p))
    {
        apilar(h,desapilar(p));
    }

}

void copiarElementos(Pila p,Pila* h) //p = base 3 7 8 4 tope    h = 0x55
{
    while (!pilavacia(&p))
    {
        apilar(h,desapilar(&p));
    }
}
