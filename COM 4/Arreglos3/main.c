#include <stdio.h>
#include <stdlib.h>
#define CANT_MAX 20
///prototipado

void cargaArreglo(int[], int*); ///recibo el arreglo por referencia y los validos por referencia
void muestraArreglo(int[],int); ///recibo el arreglo por referencia (no hay otra forma) y los validos
int sumaArreglo(int[],int); ///recibo el arreglo por referencia y los validos
void ordenacionSeleccion(int[], int validos);
int buscaMenor(int[],int,int); ///funcion que busca el menor desde una celda hasta la ultima

int sumaArreglo(int arreglo[],int validos)
{
    int suma=0; //variable local acumuladora

    for (int j = 0 ; j < validos ; j++)
    {
        suma = suma + arreglo[j]; ///suma += arreglo[j];
    }
    return suma;
}


void muestraArreglo(int arreglo[], int validos)
{
    for (int j = 0; j < validos ; j++)
    {
        printf("%i ", arreglo[j]);
    }
}


void cargaArreglo(int arreglo[], int* validos)
{
    int i = 0;
    char continuar;
    do
    {
        printf("Ingrese un valor");
        scanf("%i", &arreglo[i]); // scanf("%i", arreglo+i);
        printf("Desea continuar\n");
        fflush(stdin);
        scanf("%c",&continuar);
        i++; ///3 -> celdas cargadas 0 a 2
    }
    while((continuar == 's' || continuar == 'S') && i < CANT_MAX);
    *validos = i;
}

int buscaMenor(int arreglo[],int i,int validos)
{
    int indiceMenor = i;
    for (int j = i+1; j < validos; j++)
    {
        if (arreglo[j] < arreglo[indiceMenor])
        {
            indiceMenor = j;
        }
    }
    return indiceMenor;
}

void ordenacionSeleccion(int arreglo[], int validos)
{
    int indiceMenor;
    int aux;
    for (int i = 0 ; i < validos-1; i++)
    {
        ///busqueda del indice que contiene el menor elemento, partiendo desde la celda i
        indiceMenor= buscaMenor(arreglo,i,validos);

        ///proceso de intercambio
        aux = arreglo[i];
        arreglo[i] = arreglo[indiceMenor];
        arreglo[indiceMenor] = aux;

    }

}



int main()
{
    int arreglo[CANT_MAX];
    //iterador-contador
    int validos; ///cantidad de datos reales cargados
    int suma=0; //acumulador

    cargaArreglo(arreglo,&validos);
    muestraArreglo(arreglo,validos);

///ordenacion por seleccion
/// - iterador que recorria celda por celda
///     -> desde esa celda buscaba el menor -> intercambiaba el valor de esa celda con la celda del menor

int indiceMenor;
int aux;
    ///recorro todo el arreglo hasta el anteultimo
    for (int i = 0; i < validos-1; i++)
    {
        ///proceso de buscar el menor desde i+1 hasta hasta la ultima celda, considerando al principio como indiceMenor i
        indiceMenor = i;
        for (int j = i+1 ; j < validos; j++)
        {
            if (arreglo[j] < arreglo[indiceMenor])
            {
              indiceMenor = j;
            }
        }
        ///proceso de intercambio entre la celda i y la celda indiceMenor
        aux = arreglo[i];
        arreglo[i] = arreglo[indiceMenor];
        arreglo[indiceMenor] = aux;

    }






//    suma=sumaArreglo(arreglo,validos);
//
//    printf("El promedio es %.2f", (float)suma/validos);
//
//    printf("\nCantidad de datos cargados %i", validos);


    return 0;
}
