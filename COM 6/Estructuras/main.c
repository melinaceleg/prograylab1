#include <stdio.h>
#include <stdlib.h>
#define CANT_MAX 20

/**
 conjunto de datos relacionados

 int edades[30];
 int DNIs[30];
 float estaturas[30];

 cada indice de los arreglos representaba la edad,  dni y estatura de una persona determinada

 //////
 ESTRUCTURAS

 -conjunto de datos relacionados bajo un mismo tipo de dato
 -relacionar datos bajo un mismo nombre
 -varios tipos de datos que van a conformar campos de un registro
 - yo como usuario voy a poder crear un REGISTRO en el cual voy a conformar sus campos, y le voy a dar un nombre
 - se denomina registro o estructura

 typedef struct
 {
  ///campos
  int dni;
  int edad;
  float estatura;
 }Persona;


 ///donde se crean las estructuras
 - se generan por encima de las funciones (incluidos los prototipados)

EN ESTA 2da PARTE NO SE EVALUA ALGORITMOS DE ORDENACION
 - si se evalua insercion ordenada

**/

typedef struct
{
    char nombre[30];
    char DNI[9];
    int edad;
    float estatura;
} Persona;

///prototipados
void cargaUnaPersona(Persona*);
void mostrarUnaPersona(Persona);
void cargaListaPersonas(Persona[], int*);
void mostrarListaPersonas(Persona[], int);
void insercionOrdenada(Persona[],int,Persona);
void cargaListaPersonasOrdenada(Persona[],int*);
int busquedaUnaPersonaxDNI(Persona[],int,char[]);
int busquedaUnaPersonaxNombre(Persona[],int,char[]);

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
}

void mostrarUnaPersona(Persona p)
{
    printf("Nombre: %s\n", p.nombre);
    printf("Dni: %s\n", p.DNI);
    printf("Edad: %i\n", p.edad);
    printf("Estatura: %.2f\n\n", p.estatura);
}
///carga de lista de personas por orden de llegada
void cargaListaPersonas(Persona listaPersonas[], int* validos)
{
    int i = 0;
    char continuar;
    do
    {
        cargaUnaPersona(&listaPersonas[i]);
        printf("Desea cargar otra persona?\n");
        fflush(stdin);
        scanf("%c", &continuar);
        i++;
    }
    while( i < CANT_MAX && continuar == 's');

    *validos = i;

}


void mostrarListaPersonas(Persona listaPersonas[], int validos)
{
    for (int i = 0 ; i < validos ; i++)
    {
        mostrarUnaPersona(listaPersonas[i]);
    }


}

///insercion ordenada de una persona en la lista de personas por nombre alfabeticamente
void insercionOrdenada(Persona listaPersonas[], int validos, Persona p)
{
    int i = validos - 1; //posicionarse sobre la ultima posicion valida del arreglo
    while (i >= 0 && strcmp(listaPersonas[i].nombre, p.nombre) >0)
    {
        listaPersonas[i+1] = listaPersonas[i];
        i--;
    }

    listaPersonas[i+1] = p;

}

void cargaListaPersonasOrdenada(Persona listaPersonas[], int* validos)
{
    int i = 0;
    char continuar;
    Persona p;
    do
    {
        cargaUnaPersona(&p);
        insercionOrdenada(listaPersonas,i,p);
        printf("Desea cargar otra persona?\n");
        fflush(stdin);
        scanf("%c", &continuar);
        i++;
    }
    while( i < CANT_MAX && continuar == 's');

    *validos = i;
}

int busquedaUnaPersonaxDNI(Persona listaPersonas[], int validos, char dni[])
{
    int i = 0;
    int indice = -1; ///indice invalido
    while (i<validos && strcmpi(listaPersonas[i].DNI, dni) != 0)
    {
        i++;
    }
    if (i < validos)
    {
        indice = i;
    }

    return indice;
}

//tengo que tener en cuenta que buscare un nombre en un arreglo de personas ordenado por nombre
//    Ana Barbara Juan Pedro Tomas
//
//    Jorge
//
///tengo que tener en cuenta que mi listaPersonas esta ORDENADA por nombre
int busquedaUnaPersonaxNombre(Persona listaPersonas[], int validos, char nombre[])
{
    int indice = -1;
    int i = 0;
    while (i< validos && strcmpi(listaPersonas[i].nombre, nombre) < 0)
    {
        i++;
    }
    if (i < validos && strcmpi(listaPersonas[i].nombre,nombre) == 0)
    {
        indice = i;
    }

    return indice;

}












int main()
{
//    Persona p; ///declare una variable de tipo Persona -> Persona es un registro/estructura
//    ///cargamos los campos de la persona p
//    ///accedo a los campos de p a traves del operador punto '.'
//    strcpy(p.DNI,"37452618");
//    strcpy(p.nombre,"Pablo");
//    p.edad = 27;
//    p.estatura = 1.70;

//    Persona p;
//   cargaUnaPersona(&p);
//   mostrarUnaPersona(p);

///coleccion de personas
    Persona listaPersonas[CANT_MAX];
    int validos;
    int indice;
    //cargaListaPersonas(listaPersonas,&validos);
    cargaListaPersonasOrdenada(listaPersonas,&validos);
    mostrarListaPersonas(listaPersonas,validos);
    //indice=busquedaUnaPersonaxDNI(listaPersonas,validos,"27364567");
    indice = busquedaUnaPersonaxNombre(listaPersonas,validos,"Juan Gomez");
    if (indice != -1)
    {
        printf("La persona fue encontrada y es: \n");
        mostrarUnaPersona(listaPersonas[indice]);
    }
    else
    {
        printf("La persona con ese dni no esta en la lista\n");
    }

    return 0;
}
