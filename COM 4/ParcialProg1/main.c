#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
/**

Realice una función que dada  una pila por referencia, un entero N,
quite los primeros N elementos de la pila (desde la base), o menos, si no posee N

**/

//Pila p TOPE 3 6 BASE
//Pila aux TOPE BASE


void ej1(Pila* p, int N)
{
    Pila aux;
    inicpila(&aux);
    //int i = 0;
    int basura;
    while (!pilavacia(p))
    {
        apilar(&aux,desapilar(p));
    }
    while (!pilavacia(&aux) && N > 0) ///saco los primeros N elementos de la base
    {
        basura = desapilar(&aux);
        N--;
    }

    while (!pilavacia(&aux)) ///devuelvo los elementos que restan a la pila original
    {
        apilar(p,desapilar(&aux));
    }


}


/**

Se desea realizar una función que retorne el promedio de los valores que
hay desde el inicio del arreglo hasta encontrar un valor negativo
 (este no se tiene en cuenta, y puede no existir).

**/

//arr1 = 2 4 5 7 -1 9 3 -2
/// i = 4
/// suma = 18

float ej2(int arr[], int validos)
{
    int i = 0; ///contador
    int suma=0; ///acumulador
    float promedio;
    while (i < validos && arr[i] >= 0) ///mientras sea menor a validos y el valor no negativo
    {
        suma = suma + arr[i]; ///acumulamos los valores
        i++; ///incrementamos
    }
    promedio = (float)suma/i;

    return promedio;
}

/**

Indique la salida de la siguiente función para los siguientes valores:

a = 5

b = 8

BASE  2  6  1  9  TOPE
**/
int funcion1(int*a, int b, Pila* p) ///me llega la ubicacion de a, me llega el valor de b, y me llega la ubicacion de p

{

    int* h; ///puntero (almacena direccion de memoria)

    h = a; //h almacena la ubicacion de a

    b = desapilar(p); /// b = 5

    *a = b; /// *a = 5

    return *h; /// devuelve el contenido de h  --> 5

}





int main()
{
//    Pila dada;
//    inicpila(&dada);
//    float prom;
//    int arreglo[] = {2,4,5,7,-1,9,3,-2};
//    int validos = 8;
//    int N = 3;
//    ... //cargo la pila
//    ej1(&dada,N);
//    prom = ej2(arreglo,validos);
    Pila p;
    inicpila(&p);
    apilar(&p,2);
    apilar(&p,6);
    apilar(&p,1);
    apilar(&p,9);
    apilar(&p,5);
    int j;
    int a = 3;
    int b = 8;
    j=funcion1(&a,b,&p);
    printf("contenido de h: %i ", j);


    return 0;
}
