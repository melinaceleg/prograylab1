#include <stdio.h>
#include <stdlib.h>
#define CANT_MAX 20
///prototipado

void cargaArreglo(int[], int*); ///recibo el arreglo por referencia y los validos por referencia
void muestraArreglo(int[],int); ///recibo el arreglo por referencia (no hay otra forma) y los validos
int sumaArreglo(int[],int); ///recibo el arreglo por referencia y los validos

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

int main()
{
    int arreglo[CANT_MAX];
    //iterador-contador
    int validos; ///cantidad de datos reales cargados
    int suma=0; //acumulador

    cargaArreglo(arreglo,&validos);
    muestraArreglo(arreglo,validos);
    suma=sumaArreglo(arreglo,validos);

    printf("El promedio es %.2f", (float)suma/validos);

    printf("\nCantidad de datos cargados %i", validos);


    return 0;
}
