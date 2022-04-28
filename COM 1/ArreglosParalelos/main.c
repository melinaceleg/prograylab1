#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 20

/**
  ARREGLOS PARALELOS
  int edades[20];
  int dnis[20];
  float sueldos[20];
  char cat_monotributo[20];

  -El indice me va a representar la relacion entre estos conjuntos de datos
  -Todos poseen la misma cantidad de datos cargados
    -Van a tener un unico validos.
  -TAM_MAX de datos  tiene que ser el mismo para todos
    -LA constante es la misma para todos (Tamano maximo)

**/

/**
  CONSIDERACION BUSQUEDA EN CUALQUIER CONJUNTO DE DATOS
  ->ordenado
  ->desordenado
**/

///prototipados
int busquedaDNI_ord(int[],int,int);


//3454 1123 6534 1125 5345
//0      1   2    3     4
//validos = 4

///insercion ordenada por DNI

//345  380  453  628
// 0    1    2   3
//i   i+1
//
//14   25   80   13
//0     1    2   3
//i   i+1
//
// validos = 3
// dni = 380
// edad= 25

void insercionOrdenada(int dnis[],int edades[], float sueldos[], char cat_monotributo[], int validos, int dni, int edad, float sueldo, char catMono)
{
    int i = validos - 1;
    while (i>=0 && dnis[i] > dni)
    {
        dnis[i+1] = dnis[i];
        edades[i+1] =edades[i];
        sueldos[i+1] = sueldos[i];
        cat_monotributo[i+1] = cat_monotributo[i];
        i--;
    }

    dnis[i+1] = dni;
    edades[i+1] = edad;
    sueldos[i+1] = sueldo;
    cat_monotributo[i+1] = catMono;

}


void insercionDesordenada(int dnis[], int edades[], float sueldos[], char cat_monotributo[], int validos,int dni, int edad, float sueldo, char catMono)
{
    int i = validos;
    dnis[i] = dni;
    edades[i] = edad;
    sueldos[i] = sueldo;
    cat_monotributo[i] = catMono;

}


void carga(int dnis[], int edades[], float sueldos[], char cat_monotributo[], int* validos)
{
    char continuar;
    //int i = *validos;
    int dni,edad;
    float sueldo;
    char catMono;
    do
    {
        printf("Ingrese dni: ");
        scanf("%i",&dni);
        printf("Ingresar edad: ");
        scanf("%i", &edad);
        printf("Ingrese sueldo: ");
        scanf("%f", &sueldo);
        printf("Ingrese cat Monotributo: ");
        fflush(stdin);
        scanf("%c", &catMono);
        //insercionDesordenada(dnis,edades,sueldos,cat_monotributo,*validos,dni,edad,sueldo,catMono);
        insercionOrdenada(dnis,edades,sueldos,cat_monotributo,*validos,dni,edad,sueldo,catMono);
        (*validos)++;
        printf("Desea continuar\n");
        fflush(stdin);
        scanf("%c",&continuar);
    }
    while ((continuar == 's' || continuar == 'S') && *validos < TAM_MAX);


}

void muestraDNIS(int dnis[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("%i ", dnis[i]);
    }
}

//123 543 444 333
//0   1    2   3
//
//dni = 555

int busquedaDNI_ord(int[],int,int);

//123 255 455 523
// 0   1   2   3
//
//
//dni = 280





int busquedaDNI_des(int dnis[], int validos, int dni)
{
    int i = 0;
    int indice;
    while (i<validos && dni != dnis[i])
    {
        i++;
    }
    if (i < validos)
    {
        indice = i;
    }
    else
        indice = -1;

    return indice;

}

void mostrarDatosUnaPersona(int dnis[],int edades[], float sueldos[], char cat_monotributo[],int indice)
{
    printf("DNI: %i\n", dnis[indice]);
    printf("EDAD: %i\n", edades[indice]);
    printf("SUELDO: %.2f\n", sueldos[indice]);
    printf("CATEGORIA MONOT.: %c\n", cat_monotributo[indice]);

}



int main()
{
    int edades[TAM_MAX];
    int dnis[TAM_MAX];
    float sueldos[TAM_MAX];
    char cat_monotributo[TAM_MAX];
    int validos=0;
    int dni;
    int indice;
    carga(dnis,edades,sueldos,cat_monotributo,&validos);
    printf("ingrese dni a buscar\n");
    scanf("%i", &dni);
    indice=busquedaDNI_des(dnis,validos,dni);
    if (indice != -1)
    {
        printf("Se encontro a la persona\n");
        mostrarDatosUnaPersona(dnis,edades,sueldos,cat_monotributo,indice);
    }
    else
    {
        printf("No se encontro a la persona con dni %i\n", dni);
    }
    return 0;
}
