#include <stdio.h>
#include <stdlib.h>
#define CANT_MAX 20
/**
Estructuras
    -Un registro
    -A un conjunto de datos se los asocia bajo un mismo nombre
    -Crear un tipo de dato nuevo que me va asociar a un conjunto de tipos de dato
    -Es un tipo de dato que dentro tiene un conjunto de datos
    -Al conjunto de datos internos de este registro se denominan CAMPOS


typedef struct
{
  char nombre[30];
  int edad;
  float estatura;
  float peso;
}Persona;

///donde declaro los registros- struct?
-siempre se declaran por encima de TODAS las funciones (incluidos los prototipados) y el main



-- EN LA 2da parte de la cursada NO se evalua algoritmos de ordenacion
    -si se evalua insercion ordenada
**/

typedef struct
{
    char nombre[30];
    char DNI[9];
    int edad;
    float estatura;
    float peso;
} Persona;

///prototipados
void cargaUnaPersona(Persona*);
void mostrarUnaPersona(Persona);
void cargaListaPersonas(Persona[],int*);
void muestraListaPersonas(Persona[],int);
void insercionOrdenada(Persona[],int,Persona);
int busquedaUnaPersonaxDNI(Persona[],int, char[]); ///busco por DNI
int busquedaUnaPersonaxNombre(Persona[],int, char[]); ///busco por nombre

///implementacion

///carga por teclado de una persona
void cargaUnaPersona(Persona* p)
{
    printf("NOMBRE: ");
    fflush(stdin);
    gets((*p).nombre);
    printf("DNI: ");
    fflush(stdin);
    gets((*p).DNI);
    printf("EDAD: ");
    scanf("%i", &((*p).edad));
    printf("ESTATURA: ");
    scanf("%f", &((*p).estatura));
    printf("PESO: ");
    scanf("%f", &((*p).peso));
}

void mostrarUnaPersona(Persona p)
{
    printf("NOMBRE: %s\n", p.nombre);
    printf("DNI: %s\n", p.DNI);
    printf("EDAD: %i\n", p.edad);
    printf("ESTATURA: %.2f\n", p.estatura);
    printf("PESO: %.2f\n\n", p.peso);
}
///insercion ordenada de una persona por el criterio de nombre alfabeticamente
void insercionOrdenada(Persona agenda[], int validos, Persona p)
{
    int i = validos -1;
    while (i>=0 && strcmp(agenda[i].nombre, p.nombre) > 0)
    {
        agenda[i+1] = agenda[i];
        i--;
    }

    agenda[i+1] = p;

}
///busqueda de una persona por DNI
int busquedaUnaPersonaxDNI(Persona agenda[], int validos, char DNI[])
{
    int i = 0;
    int indice = -1;
    while (i < validos && strcmp(agenda[i].DNI,DNI) != 0)
    {
        i++;
    }
    if (i<validos)
    {
        indice = i;
    }

    return indice;
}

///busqueda de una persona por nombre
///tengo que tener en cuenta que esta ordenado alfabeticamente por nombre
int busquedaUnaPersonaxNombre(Persona agenda[], int validos, char nombre[])
{
    int i = 0;
    int indice = -1;
    while (i < validos && strcmpi(agenda[i].nombre,nombre) < 0)
    {
        i++;
    }
    if (i<validos && strcmpi(agenda[i].nombre,nombre) == 0)
    {
        indice = i;
    }

    return indice;
}


void cargaListaPersonas(Persona agenda[], int* validos)
{
    char continuar;
    Persona p;
    int i=*validos; ///empiezo desde la ultima posicion NO cargada
    do
    {
        cargaUnaPersona(&p);
        insercionOrdenada(agenda,i,p);
        printf("Desea agregar otra persona?\n");
        fflush(stdin);
        scanf("%c",&continuar);
        i++;
    }
    while(i < CANT_MAX && continuar == 's');

    *validos = i;
}

void muestraListaPersonas(Persona agenda[], int validos)
{
    for (int i = 0 ; i < validos ; i++)
    {
        mostrarUnaPersona(agenda[i]);
    }

}




int main()
{
//    Persona p;
//    ///para acceder a cada uno de los campos se hace con el operador '.'
//    p.edad = 28;
//    p.estatura = 1.70;
//    p.peso = 45.0;
//    strcpy(p.nombre,"juan");
//    Persona p;
//    cargaUnaPersona(&p);
//    mostrarUnaPersona(p);

    ///coleccion de personas

    Persona agenda[CANT_MAX];
    int validos=0;
    int indice;
    cargaListaPersonas(agenda,&validos);
    muestraListaPersonas(agenda,validos);
    indice=busquedaUnaPersonaxDNI(agenda,validos,"27364517");
    if (indice != -1)
    {
        printf("La persona fue encontrada, se encuentra en el indice %i\n", indice);
    }


    return 0;
}
