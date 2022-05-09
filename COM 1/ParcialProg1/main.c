#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//Contenido de p:
//
//BASE    4  6  7  8  9  0  5   TOPE



int funcion1(Pila p)
{

    int a = 0;

    int b;

    while (!pilavacia(&p))
    {
        a = a + (tope(&p) % 2 == 0);
        b = desapilar(&p);
    }

    return a;

}

///Se desea realizar una función que informe la suma total de los valores
///que hay en un arreglo hasta encontrar un valor negativo.

//arreglo 2 4 3 -1 8 -2 7

void ej2(int arreglo[], int validos)
{
    int i = 0; ///contador
    int suma=0; ///acumulador
    while (i < validos && arreglo[i] >=0)
    {
        suma = suma + arreglo[i];
        i++;
    }
    printf("La suma total es: %i", suma);
}


///Indique la salida de la siguiente función para los siguientes valores:
///main
//a = 5
//
//b = 8
//
//BASE  2  6  1  9  5  TOPE

int funcion1(int* a, int b, Pila* p)

{

  int* h; ///almacena direccion de memoria (ubicacion)

  h = a; /// h guarda la ubicacion de a

  b = desapilar(p); /// b = 5

  *a = b;   ////*a = 5

  return *h; /// return 5 /// devuelve el contenido de la ubicacion que almacena h

}



int main()
{
    Pila p;
    inicpila(&p);
    int valor;
    int arreglo[] = {2,4, 3, -1, 8, -2, 7};
    int validos = 7;
    apilar(&p,4);
    apilar(&p,6);
    apilar(&p,7);
    apilar(&p,8);
    apilar(&p,9);
    apilar(&p,0);
    apilar(&p,5);
    valor= funcion1(p);
    printf("%i",valor);
    ej2(arreglo,validos);



    return 0;
}
