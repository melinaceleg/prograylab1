#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 10 /// tamano 'fisico' maximo del arreglo

/**insercion de un dato en un arreglo
    en un arreglo desordenado:
        -> insertar luego de la ultima celda cargada, utilizar esa primer celda no cargada
        -> incrementar validos
        -> el tamano del arreglo nos permite insertar un nuevo dato

    En un arreglo ordenado:

        -> tenemos que hacer un hueco para insertar el elemento
        -> hacer el hueco implica comparar si el dato que inserto en la celda es mas grande que el dato que esta insertado en la celda anterior a esta

        a b c d e f g h j
        letra = e;

**/

///prototipados

void insercionDesordenada(char[],int*,char); ///recibo el arreglo, los validos por referencia, y el caracter a insertar
void insercionOrdenada(char[],int*,char);
void ordenacionInsercion(char[],int);
void insercion(char[],int indiceActual,char);



///implementacion

void insercionDesordenada(char arreglo[],int* validos, char nuevoDato)
{
    if (*validos < TAM_MAX)
    {
        arreglo[*validos] = nuevoDato;
        (*validos)++;
    }

}



void insercionOrdenada(char arreglo[],int* validos,char letra)
{
//      a b c d e f g h
//     -1 0 1 2 3 4 5 6 7
//      i i+1
//        letra = a;

    int i = (*validos) - 1; /// 6  --> arreglo[i]  'h'

    while (i >=0 && (arreglo[i] > letra))
    {
        arreglo[i+1] = arreglo[i];
        i--;
    }

    arreglo[i+1] = letra;
    (*validos)++;

}

void ordenacionInsercion(char arreglo[],int validos)
{
    char letra;
    for (int i = 1 ; i < validos ; i++ )
    {
        letra = arreglo[i];
        insercionOrdenada(arreglo,i,letra);
    }
}


void insercion(char arreglo[],int indiceActual,char letra)
{

    int j = indiceActual - 1; ///ultimo indice del lado izquierdo (el que considero ordenado)

    while (j >=0 && (arreglo[j] > letra))
    {
        arreglo[j+1] = arreglo[j];
        j--;
    }

    arreglo[j+1] = letra;

}






int main()
{
///declarar e inicializar el arreglo con datos
///forma 1
    char letra;
    char arreglo[TAM_MAX] = { 'a', 'c', 'h', 'd', 'g', 'e', 'b'}; ///declare un arreglo con los primeros 7 datos cargados
/// la celda de 0 a 6 contiene datos.
    int validos = 7; /// la cantidad de datos actualmente cargados es 7
    char dato;
    printf("Ingrese una letra\n");
    fflush(stdin);
    scanf("%c", &letra);
     insercionDesordenada(arreglo,&validos,letra);
    //insercionOrdenada(arreglo,&validos,letra);









///forma 2
// char arreglo[] = {'a', 'c', 'h', 'j', 'd', 'v', 's'}; ///7 datos cargados - > arreglo es de tamano 7
// char arreglo[] = {'j'}; ///un arreglo que solo almacena un dato
// printf("%c", arreglo[0]);
///forma no valida
// char arreglo[] = {}; ///al momento de la compilacion la variable no posee ningun valor por le lado derecho como para indicar tamano,  ni ningun tamano indicado en el lado izquierdo

    return 0;
}
