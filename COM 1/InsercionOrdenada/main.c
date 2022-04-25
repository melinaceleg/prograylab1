#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 10
#include <ctype.h>

/**insercion de un dato en un arreglo
    en un arreglo desordenado:
        -> insertar luego de la ultima celda cargada, utilizar esa primer celda no cargada
        -> incrementar validos
        -> el tamano del arreglo nos permite insertar un nuevo dato


    En un arreglo ordenado:

        -> tenemos que hacer un hueco para insertar el elemento
        -> hacer el hueco implica comparar si el dato que inserto en la celda es mas grande que el dato que esta insertado en la celda anterior a esta

Algoritmos de ordenacion

    insercion:
            -> parte el arreglo en una parte izq ordenada y una parte derecha desordenada
            -> a partir del indice siguiente a la ultima celda izquierda toma un elemento
            -> ese elemento de la parte derecha le busca el hueco en la parte izquierda
            -> avanza hacia el siguiente indice

    seleccion:
            -> selecciona el menor elemento de la parte derecha a partir de un indice
            -> intercambia el elemento menor que se encontro en dicho indice con el actual
            -> avanza hacia el siguiente indice

**/
///prototipados
void insercionOrdenada(char[],int*,char);
void insercion(char[],int,char);
void insercionDesordenada(char[],int*,char);


//parte izq = ordenada
//parte der = desordenada
void ordenacionInsercion(char arreglo[],int validos)
{
    for (int i = 1; i < validos; i++)
    {
        insercion(arreglo,i,arreglo[i]);
    }

}

void insercion(char arreglo[],int indiceActual,char letra)
{

    int j = indiceActual - 1;
    ///int i = (*validos) - 1;

    while (j >=0 && (arreglo[j] > letra))
    {
        arreglo[j+1] = arreglo[j];
        j--;
    }

    arreglo[i+1] = letra;
    //(*validos)++;
}



void insercionOrdenada(char arreglo[],int* validos,char letra)
{

    int i = (*validos) - 1;

    while (i >=0 && (arreglo[i] > letra))
    {
        arreglo[i+1] = arreglo[i];
        i--;
    }

    arreglo[i+1] = letra;
    (*validos)++;
}



void insercionDesordenada(char arreglo[],int* validos,char letra)
{
    arreglo[*validos] = letra;
    (*validos)++;
}



int main()
{
    ///1 forma de declarar e inicializar con valores el arreglo
    char arreglo1[TAM_MAX] = {'b','a','e','f','h','w'};
    ///el arreglo es de tamano 10, pero la cantidad de celdas que le ingrese valores es 6
    int validos = 6;
    if (validos < TAM_MAX)
    {
        insercionDesordenada(arreglo,&validos,'j');
    }










//    ///2 forma: declaro e inicializo el arreglo
//    /// -> no le doy tamano desde el izquierdo, sino desde el lado derecho
//    char arreglo2[] = {'b','c','d','a','h'};
//    ///el arreglo es de tamano 5, dado por los elementos ingresados en el lado derecho.
//
//
//    ///esto no se puede, no se le da tamano del lado izquierdo ni derecho
//    char arreglo3[] = {};





    return 0;
}
