#include <stdio.h>
#include <stdlib.h>

void mainEj1();
void mainEj2();
void mainEj3();
void mainEj4();

void cargaArregloFlotantes(float[],int*);
void cargaArregloEnteros(int[],int*);
float sumaArreglo(int[],int);
float promedioArreglo(int[],int);

///calcular un promedio
void mainEj1()
{
 float arreglo[20];
 int validos;
 float prom;
 cargaArregloFlotantes(arreglo,&validos);
 ...
 prom = promedioArreglo(arreglo,validos);
 printf("El promedio es %.2f", prom);

}


int main()
{

    int opcion;
    printf("Menu de ejercicios\n");
    printf("1. Ej 1\n");
    printf("2. Ej 2\n");
    printf("3. Ej 3\n");
    printf("4. Ej 4\n");
    scanf("%i", &opcion);
    switch(opcion)
    {
        case 1: mainEj1();
                break;
        case 2: mainEj2();
                break;

        case 3: mainEj3();
                break;

        case 4: mainEj4();
                break;

    }

    return 0;
}
