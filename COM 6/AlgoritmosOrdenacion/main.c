#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 10

///busqueda del elemento menor en el arreglo y retornar el indice
int busquedaMenor(int[],int); ///recibo el arreglo y los validos
int busquedaMenorSeleccion(int[], int, int);
void ordenacionSeleccion(int[],int);
void insercionArregloDesordenado(int[],int*,int);
void insercionArregloOrdenada(int[],int*,int);/// VER!



/**

    insercion en arreglo
      ->arreglo desordenado
      3 4 5 9 1 8
      0 1 2 3 4 5
      validos = 5;
      TAM_MAX 10
      ->arreglo ordenado
       2 3 4 6 7 8
       dato = 3

**/

void insercionArregloDesordenado(int arreglo[], int* validos, int dato)
{
    arreglo[*validos] = dato;
    (*validos)++;

}



int busquedaMenor(int arreglo[], int validos)
{
    int indiceMenor=0;
    int i=1;
    while (i < validos)
    {
        if (arreglo[i] < arreglo[indiceMenor])
        {
            indiceMenor = i;
        }

        i++;

    }

    return indiceMenor;
}

///busqueda del menor indicando desde que posicion comenzar
int busquedaMenorSeleccion(int arreglo[], int posInicial, int validos)
{
    int indiceMenor = posInicial; ///considero la posicion donde estoy como la del elemento menor
    int i= posInicial+1; ///comparo comenzando por el siguiente a posInicial
    while (i < validos)
    {
        if (arreglo[i] < arreglo[indiceMenor])
        {
            indiceMenor = i;
        }
        i++;
    }
    return indiceMenor; ///retorno el indice donde pertenece el elemento menor
}

void ordenacionSeleccion(int arreglo[],int validos)
{
    int indiceMenor;
    int aux;
    for (int i = 0; i < validos-1 ; i++)
    {
        indiceMenor = busquedaMenorSeleccion(arreglo,i,validos);
        ///proceso de intercambio
        aux = arreglo[i];
        arreglo[i]= arreglo[indiceMenor];
        arreglo[indiceMenor] = aux;
    }

}

void muestraArreglo(int arreglo[],int validos)
{
    for (int i = 0 ; i < validos; i++)
    {
        printf("%i ", arreglo[i]);
    }
}

int main()
{
    int arreglo[TAM_MAX] = {2,4,1,7,6,3};
    int validos = 6;
    int indiceMenor;
    indiceMenor = busquedaMenor(arreglo,validos);
    printf("El menor elemento es %i\n", arreglo[indiceMenor]);
    muestraArreglo(arreglo,validos);
    printf("Despues de ordenarlo\n");
    ordenacionSeleccion(arreglo,validos);
    muestraArreglo(arreglo,validos);
    if (validos < TAM_MAX)
    {
        insercionArregloDesordenado(arreglo,&validos,2);
    }


    return 0;
}
