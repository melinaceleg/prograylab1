#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 10

/**
3- Hacer una función que reciba como parámetro un arreglo,
la cantidad de elementos (válidos) cargados en él y una Pila.
La función debe copiar los elementos del arreglo en la pila.
**/

///prototipado
void cargaPila(int[],int,Pila*);

///implementacion
void cargaPila(int arreglo[], int validos, Pila* dada)
{
    for (int i = 0; i < validos ; i++)
    {
        apilar(dada, arreglo[i]);
    }

}



int main()
{
   Pila p;
   inicpila(&p);
   ///declarar e inicializar el arreglo con datos
   ///1 forma: declarar el tamano del arreglo e inicializarlo con datos
   int arreglo1[TAM_MAX] = {2, 5, 1, 7, 8, 3}; /// 6 datos cargados de los 10 posibles
   int validos = 6;
   cargaPila(arreglo1,validos,&p);
   mostrar(&p);











//   ///2 forma: declarar el arreglo sin el tamano, pero su tamano va a estar dado por la cantidad de datos que inicializo
//   int arreglo2[] = {6,1,2,4,5,3,5}; ///el tamano del arreglo es de 7
//   int validos2 = 7 ;
//
//   int arreglo4[]; ///NO!
//
//   ///3 forma
//   int arreglo[TAM_MAX];
    return 0;
}
