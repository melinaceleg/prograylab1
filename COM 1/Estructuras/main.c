#include <stdio.h>
#include <stdlib.h>
#define CANT_MAX 30

///una estructura es un registro
/// crear un tipo de dato nuevo que me asocie un conjunto de tipos de dato
/// es un tipo de dato que dentro tiene un conjunto de datos.
/// El conjunto de datos internos de la estructura se denominan CAMPOS

typedef struct
{
    char nombre[30];
    int dni;
    int edad;
    float estatura;
    char estado_civil;
} Persona;

///funciones

///prototipados
void muestraPersona(Persona);
void cargaPersona(Persona*); ///por teclado
///en colecciones de datos (arreglos)
void cargaAgenda(Persona[], int*);
void mostrarAgenda(Persona[],int);
void insercionOrdenada(Persona[],int, Persona);

///implementacion

void muestraPersona(Persona p)
{
    printf("Nombre: %s\n", p.nombre);
    printf("DNI: %i\n", p.dni);
    printf("Edad: %i\n", p.edad);
    printf("Estatura: %.2f\n", p.estatura);
    if (p.estado_civil == 's')
        printf("Estado Civil: Soltero\n");
    else
        printf("Estado Civil: Casado\n");
    printf("\n");
}

/**
void cargaPersona(Persona* p)...

(*p) -> contenido de esa ubicacion -> me paro sobre la persona
(*p).campo -> contenido de esa ubicacion -> me paro sobre la persona -> accedo a un campo
&((*p).campo) -> (contenido de esa ubicacion -> me paro sobre la persona -> accedo a un campo) -> ubicacion del campo

**/
void cargaPersona(Persona* p)
{
    printf("NOMBRE: ");
    fflush(stdin);
    gets((*p).nombre);
    printf("DNI: ");
    scanf("%i", &((*p).dni)); ///
    printf("EDAD: ");
    scanf("%i", &((*p).edad));
    printf("ESTATURA: ");
    scanf("%f", &((*p).estatura));
    do
    {
        printf("ESTADO CIVIL: ");
        fflush(stdin);
        scanf("%c", &((*p).estado_civil));
    }
    while ((*p).estado_civil != 's' && (*p).estado_civil != 'c');
}

///algoritmo de carga de personas por teclado en orden de llegada
void cargaAgenda(Persona agenda[], int* validos)
{
    char continuar;
    int i=*validos;
    Persona p;
    do
    {
        //cargaPersona(&agenda[i]); //cargo una persona por orden de llegada
        cargaPersona(&p);
        insercionOrdenada(agenda,i,p);
        printf("desea cargar otra persona?\n");
        fflush(stdin);
        scanf("%c", &continuar);
        i++;
    }
    while(i<CANT_MAX && continuar == 's');

    *validos = i;
}


void mostrarAgenda(Persona agenda[], int validos)
{
    for (int i = 0; i < validos ; i++)
    {
        muestraPersona(agenda[i]);

    }
}
///insercion ordenada por nombre de persona de menor a mayor
void insercionOrdenada(Persona agenda[],int validos, Persona p)
{
   int i = validos -1;
   while (i>=0 && strcmpi(agenda[i].nombre, p.nombre) > 0 )
   {
     agenda[i+1] = agenda[i]; ///hago un corrimiento de una PERSONA hacia la posicion siguiente
     i--;
   }

   agenda[i+1] = p; ///inserto la PERSONA en el hueco
}




int main()
{
//    Persona p; ///variable de tipo Persona
//    ///para acceder a los campos debo usar el operador '.'
//    p.dni = 25487956;
//    p.edad = 27;
//    p.estado_civil = 's';
//    p.estatura = 1.80;
//    strcpy(p.nombre,"juan");


//    Persona p;
//    cargaPersona(&p);
//    muestraPersona(p);

///coleccion de personas

    Persona agenda[CANT_MAX];
    int validos=0;
    cargaAgenda(agenda,&validos);
    mostrarAgenda(agenda,validos);


    return 0;
}
