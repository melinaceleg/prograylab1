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


/**
8. Hacer una función que sume
 y retorne los dos primeros elementos de una pila (tope y anterior),
  sin alterar su contenido. **/

  ///prototipado
  void sumaYRetorno2Primeros(Pila,int*,int*,int*);

  ///implementacion
  void sumaYRetorno2Primeros(Pila p, int* suma, int* primero, int* segundo)
  {
     *primero = desapilar(&p);
     *segundo = desapilar(&p);
     *suma = *primero + *segundo;
  }

 int laPilaTiene2Valores(Pila A)
 {
     int basura;
     int respuesta = 0;
     if (!pilavacia(&A))
     {
         basura= desapilar(&A);
         if (!pilavacia(&A))
         {
             respuesta = 1;
         }
     }

     return respuesta;

 }


/// &A 0x60
int main()
{
    Pila A;
    Pila B;
    int suma;
    int pri;
    int seg;
    inicpila(&A);
    inicpila(&B);
    cargaPila(&A);
    if (laPilaTiene2Valores(A))
    {
        sumaYRetorno2Primeros(A,&suma,&pri,&seg);
        printf("pri: %i", pri);
        printf("seg: %i", seg);
        printf("suma : %i", suma);

    }

//    mostrar(&A);



    return 0;
}
