#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM_MAX 10

///ordenacion por seleccion
///-> buscaba el menor y lo quitaba
///-> se agregaba el menor a una nueva pila
//a partir de la siguiente posicion j = i+1 busco el menor comparando arreglo[posMenor] con arreglo[j]


///ordenacion por insercion
/// -> por cada dato de la pila que desapilaba
///-> con el dato buscaba el hueco en la nueva de forma ordenada



///prototipados
int buscarMenor(char[],int,int); ///recibo el arreglo, la posicion i, y validos
void ordenarSeleccion(char[],int); ///recibo el arreglo y los validos
void cargaArreglo(char arreglo[], int* validos); ///carga el arreglo con valores random enteros
void muestraArreglo(char[], int);
void insercionOrdenada(char[],int*,char); ///inserta una letra en un arreglo ordenado



///insertar una letra en un arreglo ordenado alfabeticamente
///sabiendo que le arreglo tiene una capacidad que permite insertar un dato nuevo
void insercionOrdenada(char arreglo[],int* validos,char letra)
{
//TAM_MAX = 10
//arreglo a b c d e f g h
//        0 1 2 3 4 5 6 7
//                j
//letra = f
//validos = 7

    int j = *validos -1;
    while (j>=0 && letra < arreglo[j]) ///busqueda del hueco, desplazando celdas
    {
        arreglo[j+1] = arreglo[j];
        j--;
    }
    arreglo[j+1] = letra;

    (*validos)++; ///incremento en 1 la cantidad del arreglo


}



int buscarMenor(char arreglo[],int i, int validos)
{
    int posMenor = i;

    for (int j = i+1 ; j < validos ; j++ )
    {
        if (arreglo[posMenor] > arreglo[j])
        {
            posMenor = j;
        }
    }

    return posMenor;
}





void ordenarSeleccion(char arreglo[], int validos)
{
    int aux;
    int posMenor;
    for (int i = 0; i < validos-1 ; i++)
    {

        posMenor = buscarMenor(arreglo,i,validos);

        ///proceso de intercambio
        aux = arreglo[posMenor];
        arreglo[posMenor] = arreglo[i];
        arreglo[i] = aux;
    }

}


void cargaArreglo(char arreglo[], int* validos) /// validos = 0x25
{
    srand(time(NULL));
    *validos = (rand() % TAM_MAX) + 1; /// 1...TAM_MAX
    for (int i=0; i < *validos; i++)
    {
        arreglo[i] = (rand() % 26) + 97;   ///desde el 97 hasta 122
    }
}


void muestraArreglo(char arreglo[], int validos)
{
    ///muestra del arreglo
    for (int j = 0; j < validos ; j++)
    {
        printf(" %c ", arreglo[j]); ///printf("%i", *(arreglo+j));
    }

}

int main()
{

    char arreglo[TAM_MAX];
    int validos;
    cargaArreglo(arreglo,&validos);
    printf("La cantidad de datos cargados es %i\n",validos);
    muestraArreglo(arreglo,validos);
    printf("\n");
    ordenarSeleccion(arreglo,validos);
    muestraArreglo(arreglo,validos);
    insercionOrdenada(arreglo,&validos,'h');


    return 0;
}
