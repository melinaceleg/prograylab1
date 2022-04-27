#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 20
/**
    ARREGLOS PARALELOS

    int edades[20];
    int dnis[20];
    float sueldos[20];
    char categoria_monotributo[20];

    ->se relacionan por el indice
    ->son conjuntos de datos donde cada uno se relaciona por un indice.
    -> cantidad de datos cargados en los arreglos debe ser la misma
    -> validos es uno solo para todos
    -> TAM_MAX (tamano maximo de datos e n la declaracion debe ser el mismo para todos los arreglos)


**/

///prototipados

void cargaDatos(int[],int[],float[],char[],int*);


///implementacion
void cargaDatos(int edades[],int dnis[],float sueldos[],char cat_monot[],int* validos)
{
    char continuar;
    int i=0;
    do
    {
        printf("Ingrese una nueva persona\n");
        printf("Edad: ");
        scanf("%i",&edades[i]);
        printf("dni: ");
        scanf("%i",&dnis[i]);
        printf("sueldo: ");
        scanf("%f",&sueldos[i]);
        printf("categoria monotributo: ");
        fflush(stdin);
        scanf("%c",&cat_monot[i]);
        i++;
        printf("Desea continuar?\n");
        fflush(stdin);
        scanf("%c",&continuar);

    }
    while((continuar == 's' || continuar == 's') && i < TAM_MAX);

    *validos = i;
}

void mostrarDNIS(int dnis[],int validos)
{
    printf("DNIS\n");
    for(int i = 0; i < validos ; i++)
    {
        printf("%i ",dnis[i]);
    }
}

void mostrarEDADES(int edades[],int validos)
{
      printf("edades\n");
    for (int i = 0 ; i < validos ; i++)
    {
        printf("% i ",edades[i]);
    }
}

int busquedaDNI(int dnis[], int validos, int dni)
{
    int i = 0;
    int indice = -1;
    while (i < validos && dni != dnis[i])
    {
        i++;
    }
    if (i<validos) ///lo encontre
    {
        indice = i;
    }

    return indice;

}

void mostrarTodosLosDatosDeUnaPersona(int edades[],int dnis[], float sueldos[], char categ_mono[], int indice)
{
    printf("DNI: %i\n", dnis[indice]);
    printf("Edad: %i\n", edades[indice]);
    printf("Sueldo: %.2f\n", sueldos[indice]);
    printf("Categoria Monotributo: %c\n", categ_mono[indice]);
}


int main()
{
    int edades[TAM_MAX];
    int dnis[TAM_MAX];
    float sueldos[TAM_MAX];
    char categoria_monotributo[TAM_MAX];
    int indice;

    int validos; ///validos para todos
    cargaDatos(edades,dnis,sueldos,categoria_monotributo,&validos);
    indice= busquedaDNI(dnis,validos,1254356);
    if (indice != -1)
    {
        mostrarTodosLosDatosDeUnaPersona(edades,dnis,sueldos,categoria_monotributo,indice);
    }
    else
        printf("No se encontro dicha persona con el dni enviado\n");

    mostrarDNIS(dnis,validos);  /// solo muestro los dnis
    return 0;
}
