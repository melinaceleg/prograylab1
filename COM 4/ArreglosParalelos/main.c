#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 20

/**
  Arreglos Paralelos
  int edades[20];
  float sueldos[20];
  int dnis[20];
  char categoria_monot[20];

  ->conjuntos de datos que estan relacionados
  -> la relacion es el indice
  -> Todos los arreglos poseen la misma cantidad de datos cargada
     -> se utiliza un solo validos para todos
  -> la cantidad MAXIMA de datos que se puede cargar es la misma para todos
     -> una sola TAM_MAX para todos
  -> Cuando realizo la carga de un dato nuevo, se hace sobre cada uno de los conjunto de datos.

**/

///Algoritmos de ordenacion en arreglos paralelos NO
///insercion de un dato de manera ordenada SI

/**TENER EN CUENTA QUE EN LA BUSQUEDA DE UN DATO:
   -> considerar el arreglo ordenado
   -> considerar el arreglo desordenado
   -> considerar la pila desordenada u ordenada
**/


///prototipados
void cargaUnaPersonaDesordenada(int[],float[],int[],char[],int*);
void cargaUnaPersonaOrdenada(int[],float[],int[],char[],int*);
void insercionOrdenadaPorDNI(int[],float[],int[],char[],int*,int,float,int,char);
void cargaVariasPersonas(int[],float[],int[],char[],int*);
void mostrarDNIS(int[], int);
void mostrarEDADES(int[], int);
int busquedaPersonaPorDNI(int[],int, int);
void mostrarUnaPersona(int[], float[], int[], char[], int);
int busquedaPersonaPorDNIORD(int[], int, int);


///implementacion
void cargaUnaPersonaDesordenada(int dnis[],float sueldos[], int edades[], char categ_mono[], int* validos)
{
    int i=*validos;
    printf("Ingrese su dni: ");
    scanf("%i", &dnis[i]);
    printf("Ingrese su edad: ");
    scanf("%i", &edades[i]);
    printf("Ingrese su sueldo: ");
    scanf("%f", &sueldos[i]);
    printf("Ingrese categoria monotributo: ");
    fflush(stdin);
    scanf("%c", &categ_mono[i]);

    (*validos)++;
}

//    111 123 212 345  672
//-1  0   1   2  3   4
// i  i+1
//
//    20  25  80  18  30
//-1  0   1   2   3  4
// i  i+1
// validos = 4
//
//dni = 111
//edad = 20

void cargaUnaPersonaOrdenada(int dnis[],float sueldos[],int edades[], char categ_mono[], int* validos)
{
    int dni,edad;
    float sueldo;
    char catMono;
    printf("Ingrese dni: ");
    scanf("%i", &dni);
    printf("Ingrese edad: ");
    scanf("%i", &edad);
    printf("Ingrese sueldo: ");
    scanf("%f", &sueldo);
    printf("Ingrese categoria monotributo: ");
    fflush(stdin);
    scanf("%c", &catMono);
    insercionOrdenadaPorDNI(dnis,sueldos,edades,categ_mono,validos,dni,sueldo,edad,catMono);
}

void insercionOrdenadaPorDNI(int dnis[], float sueldos[], int edades[], char categ_mono[], int* validos, int dni, float sueldo, int edad, char catMono)
{
    int i = *validos - 1;
    ///la busqueda del huequito esta dada por el orden dni
    while (i>=0 && dni < dnis[i])
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


void cargaVariasPersonas(int dnis[],float sueldos[],int edades[],char categ_mono[],int* validos)
{
    char continuar;
    do
    {
        //cargaUnaPersonaDesordenada(dnis,sueldos,edades,categ_mono,validos);
        cargaUnaPersonaOrdenada(dnis,sueldos,edades,categ_mono,validos);
        printf("Desea cargar otra persona?\n");
        fflush(stdin);
        scanf("%c",&continuar);
    }
    while((continuar == 's' || continuar == 'S') && *validos < TAM_MAX);

}

void mostrarDNIS(int dnis[], int validos)
{
    for (int i = 0 ; i < validos; i++)
    {
        printf("%i ",dnis[i]);
    }
}

void mostrarEDADES(int edades[], int validos)
{
    for (int i = 0 ; i < validos; i++)
    {
        printf("%i ",edades[i]);
    }
}
///busca un dni en el arreglo de dnis y retorna el indice, si no esta retornara un indice invalido (-1)
//1231  32423  23423  12312
//0      1       2      3
//validos = 4
int busquedaPersonaPorDNIDesordenado(int dnis[],int validos, int dni)
{
    int i = 0;
    int indice;

    while (i< validos && dnis[i] != dni)
    {
        i++;
    }
    if (i<validos) ///encontre el dato
    {
        indice = i;
    }
    else
        indice = -1;

    return indice;
}
//111 123  224 366
//0    1    2   3
//          i
//dni = 151
int busquedaPersonaPorDNIORD(int dnis[], int validos, int dni)
{
    int i = 0;
    int indice = -1;
    while (i < validos && dnis[i] < dni)
    {
        i++;
    }
    if (i < validos && dnis[i] == dni)
    {
        indice = i;
    }

    return indice
}



void mostrarUnaPersona(int dnis[], float sueldos[], int edades[], char categoria_monot[], int indicePersona)
{
    printf("Mostrando la persona en el indice %i\n", indicePersona);
    printf("DNI: %i\n", dnis[indicePersona]);
    printf("SUELDO: %.2f\n", sueldos[indicePersona]);
    printf("EDAD: %i\n", edades[indicePersona]);
    printf("CATEGORIA MONOTRIBUTO: %c\n", categoria_monot[indicePersona]);
}

void mostrarVariasPersonas(int dnis[],float sueldos[],int edades[],char categ_monot[], int validos)
{
    for (int i = 0; i < validos; i++)
    {
        mostrarUnaPersona(dnis,sueldos,edades,categ_monot,i);
    }
}


int main()
{
    int edades[TAM_MAX];
    float sueldos[TAM_MAX];
    int dnis[TAM_MAX];
    char categoria_monot[TAM_MAX];
    int dni;
    int indice;
    int validos=0; ///un solo validos para todos
    //cargaUnaPersona(dnis,sueldos,edades,categoria_monot,&validos);
    cargaVariasPersonas(dnis,sueldos,edades,categoria_monot,&validos);
    mostrarVariasPersonas(dnis,sueldos,edades,categoria_monot,validos);
    printf("Ingrese dni a buscar\n");
    scanf("%i", &dni);
    indice=busquedaPersonaPorDNIORD(dnis,validos,dni);
    if (indice != -1)
    {
        mostrarUnaPersona(dnis,sueldos,edades,categoria_monot,indice);
    }
    else
        printf("La persona con el dni %i no se encuentra\n", dni);
    return 0;
}
