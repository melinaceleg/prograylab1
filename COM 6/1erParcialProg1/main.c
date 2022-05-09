#include <stdio.h>
#include <stdlib.h>

/**
Realice una función que dada  una pila por referencia, un entero N,
quite los primeros N elementos de la pila (desde la base), o menos, si no posee N-

 - debe resolverlo sin contar la cantidad de elementos que posee la pila de antemano -
 **/

//p  tope base
//
//aux tope 4 2 base

void ej1(Pila* h, int N)
{
    Pila aux;
    inicpila(&aux);
    int i = 0;
    int basura;

    while (!pilavacia(h)) ///volcamos en aux todo lo de p, para que quede lo de la base en el tope
    {
        apilar(&aux,desapilar(h));
    }

    while (!pilavacia(&aux) && i < N ) ///mientras no este vacia aux y la cantidad de elementos que desapile sea menor a los que me pide
    {
        basura = desapilar(&aux);
        i++; ///desapile un elemento mas
    }

    while (!pilavacia(&aux)) ///le devuelvo el resto de los elementos a la pila original
    {
        apilar(h,desapilar(&aux));
    }


}

//Contenido de dada:
//
//BASE    4  6  7  8  9  0  5   TOPE


//Contenido de p:
//
//BASE       TOPE
//a = 4

int funcion1(Pila p)
{
    int a = 0;
    int b;

    while (!pilavacia(&p))
    {
        a = a + (tope(&p) % 2 == 0); ///(tope(&p) % 2 == 0) --> devuelve 1 si es V , 0 si es falso
        b = desapilar(&p);
    }

    return a; /// return 4

}


//Indique la salida de la siguiente función para los siguientes valores:

//a = 5
//
//b = 8
//
//BASE  2  6  1  9 TOPE

int funcion1(int*a, int b, Pila* p) /// me llega la ubicacion de a, me llega el valor de b, y me llega la ubicacion de p

{

  int* h; /// almacena una ubicacion de una variable entera

  h = a; /// h apunta a "a", ahora tiene su ubicacion

  b = desapilar(p); /// b=5

  *a = b; /// *a = 5

  return *h; ///return 5

}





void main()
{

    Pila dada;

    int valor;

    ..... (se carga la pila)

    valor = funcion1(dada);

}




//int main()
//{
//    Pila p;
//    inicpila(&p);
//    //cargo la pila....
//    ej1(&h,3);
//
//
//
//    return 0;
//}
