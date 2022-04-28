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

/**
  Criterios de insercion en arreglos/arreglos paralelos
  ->insercion ordenada
  ->insercion desordenada
**/

/**
  Criterios de busqueda en arreglos
   ->ordenado -> corto cuando encuentro el dato o el dato que estoy comparando resulta ser menor al dato del arreglo comparado
   ->desordenado -> no hay ningun criterio -> busco hasta encontrarlo o llegar al final
**/

/**
    -NO SE EVALUA ORDENACION POR INSERCION O SELECCION EN ARREGLOS PARALELOS
    -SOLO ENTRA HASTA TEORIA DE ARREGLOS PARALELOS PARA EL PARCIAL DE PROGRAMACION, lo demas puede ser teorico-practico
    -EN EL DE LABORATORIO ENTRA TODO (PRACTICO)

**/




///prototipados

void cargaDatos(int[],int[],float[],char[],int*);
void insercionPersonaDesordenado(int[], int[], float[], char[], int*,int,int,float,char);
void insercionPersonaOrdPorDni(int[], int[], float[], char[], int*, int, int,float,char);
void mostrarDNIS(int[],int);
void mostrarEDADES(int[],int);
int busquedaDNI(int[],int,int);
void mostrarDatosDeUnaPersona(int[],int[],float[],char[],int);
void mostrarTodos(int[],int[],float[],char[],int);

///implementacion

///carga de datos

void cargaDatos(int edades[],int dnis[],float sueldos[],char categ_mono[],int* validos)
{
    char continuar;
    int edad,dni;
    float sueldo;
    char catMono;
    do
    {
        printf("Ingrese una nueva persona\n");
        printf("Edad: ");
        scanf("%i",&edad);
        printf("dni: ");
        scanf("%i",&dni);
        printf("sueldo: ");
        scanf("%f",&sueldo);
        printf("categoria monotributo: ");
        fflush(stdin);
        scanf("%c",&catMono);
        insercionPersonaDesordenado(dnis,edades,sueldos,categ_mono,validos,dni,edad,sueldo,catMono);
        printf("Desea continuar?\n");
        fflush(stdin);
        scanf("%c",&continuar);

    }
    while((continuar == 's' || continuar == 's') && *validos < TAM_MAX);

}

///insercion de un dato

void insercionPersonaDesordenado(int dnis[], int edades[], float sueldos[], char categ_mono[], int* validos, int dni, int edad, float sueldo, char catMono)
{
    int i = *validos;
    dnis[i] = dni;
    edades[i] = edad;
    sueldos[i] = sueldo;
    categ_mono[i] = catMono;

    (*validos)++;


}
//211 240 288 322 565
//0    1   2   3  4
//     i  i+1
//
//27  12  80  16 14
//0    1   2  3
//     i  i+1
//dni = 288
//edad = 80
//validos = 4

///considero Ordenado POr dni
void insercionPersonaOrdPorDni(int dnis[],int edades[], float sueldos[], char categ_mono[], int* validos, int dni, int edad, float sueldo, char catMono)
{
    int i = (*validos) -1;
    while (i >= 0 && dnis[i] > dni)
    {
        dnis[i+1] = dnis[i];
        edades[i+1] = edades[i];
        sueldos[i+1] = sueldos[i];
        categ_mono[i+1] = categ_mono[i];
        i--;
    }
    dnis[i+1] = dni;
    edades[i+1] = edad;
    sueldos[i+1] = sueldo;
    categ_mono[i+1] = catMono;

    (*validos)++;


}

////busqueda de un valor

//121 233 345 450 600
//0   1   2    3   4
//
//int validos = 5
//              dni = 128
//se que el arreglo esta ordenado

                    int busquedaDNIORD(int dnis[], int validos, int dni)
{
    int i = 0;
    int indice;
    while (i < validos && dni[i] < dni)
    {
        i++;
    }
    if (i<validos && dni[i] == dni)
    {
        indice = i;
    }
    else
        indice = -1;

    return indice;
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

////muestra de datos
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


void mostrarDatosDeUnaPersona(int edades[],int dnis[], float sueldos[], char categ_mono[], int indice)
{
    printf("DNI: %i\n", dnis[indice]);
    printf("Edad: %i\n", edades[indice]);
    printf("Sueldo: %.2f\n", sueldos[indice]);
    printf("Categoria Monotributo: %c\n", categ_mono[indice]);
}

void mostrarTodos(int edades[],int dnis[], float sueldos[], char categ_mono[], int validos)
{
    for (int i = 0; i < validos ; i++)
    {
        mostrarDatosDeUnaPersona(edades,dnis,sueldos,categ_mono,i);
    }

}
//desordenado
//25 14 1 19 63
//0  1  2  3  4
//posM
//            i
//
//validos  =5

int edadMaxima(int edades[],int validos)
{
 int posM = 0;
 for (int i = 1; i < validos ; i++)
 {
     if (arreglo[posM] < arreglo[i])
     {
        posM = i;
     }
     i++;
 }

 return posM;
}


int main()
{
    int edades[TAM_MAX];
    int dnis[TAM_MAX];
    float sueldos[TAM_MAX];
    char categoria_monotributo[TAM_MAX];
    int indice;
    int dni;

    int validos; ///validos para todos
    cargaDatos(edades,dnis,sueldos,categoria_monotributo,&validos);
    mostrarTodos(edades,dnis,sueldos,categoria_monotributo,validos);
    printf("Ingrese DNI a buscar: ");
    scanf("%i", &dni);
    indice= busquedaDNI(dnis,validos,dni);
    if (indice != -1)
    {
        mostrarDatosDeUnaPersona(edades,dnis,sueldos,categoria_monotributo,indice);
    }
    else
        printf("No se encontro dicha persona con el dni enviado\n");

    mostrarDNIS(dnis,validos);  /// solo muestro los dnis
    indice = edadMaxima(edades,validos);
    printf("La edad maxima es %i", edades[indice]);
    ////si el arreglo de edades esta ordenado de menor a mayor
//    printf("La edad maxima es %i", edades[validos-1]);

    return 0;
}
