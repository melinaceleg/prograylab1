#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT_MAX 20
#define NOM_ARCH "ArchivoPersonas.bin"

typedef struct
{
    char nombre[20];
    char DNI[9];
    char telefono[20];
    char o_social[20];
    int edad;
    int baja; ///0 ALTA 1 BAJA
}Persona;

/**
ABM - Archivos
  Alta -> guardar un nuevo registro en el archivo (nueva persona)
  Baja -> dar de baja un registro del archivo (borrado LOGICO)
  Modificacion -> modificar un registro del archivo (se modifica al menos un campo de ese registro)

**/


///prototipos
void cargaPersona(Persona*); ///se carga una persona por teclado
void cargaListaPersonas(Persona[], int*); ///cargamos una lista de personas por teclado
void cargaListaPersonasOrdenada(Persona[],int*); ///cargamos una lista de personas ordenada por nombre
void insercionOrdenada(Persona[],int,Persona); ///insercion de una persona ordenada por nombre en el arreglo
void mostrarUnaPersona(Persona);
void mostrarListaPersonas(Persona[],int);
//----
void altaPersonaEnArchivo(Persona); ///escribe una persona nueva al final del archivo --> archivo sin orden
void persistenciaListaPersonas(Persona[],int); ///guardar en el archivo la lista de personas
////si el archivo posee un orden, deberia luego traerme esta lista de personas desde el archivo
////-Ordenarla por algun metodo de ordenacion visto
////-Sobreescribir este archivo con la nueva lista ordenada
///modificacion
void modificarTelefono(Persona*);
void modificarNombre(Persona*);
void modificacionRegistro(char[]);
int contarPersonas();
///baja
void bajaRegistro();
void mantenimientoArchivo();



///implementacion

void cargaPersona(Persona* p)
{
    printf("NOMBRE: ");
    fflush(stdin);
    gets((*p).nombre);
    printf("DNI: ");
    fflush(stdin);
    gets((*p).DNI);
    printf("EDAD: ");
    scanf("%i", &((*p).edad));
    printf("TELEFONO: ");
    fflush(stdin);
    gets((*p).telefono);
    printf("Obra Social: ");
    fflush(stdin);
    gets((*p).o_social);
    (*p).baja = 0; ///por defecto es 0 ALTA
}

void mostrarUnaPersona(Persona p)
{
    printf("Nombre: %s\n", p.nombre);
    printf("Dni: %s\n", p.DNI);
    printf("Edad: %i\n", p.edad);
    printf("Telefono: %s\n\n", p.telefono);
    printf("Obra Social: %s\n\n", p.o_social);
}
///carga de lista de personas por orden de llegada
///el arreglo debe contener la lista de personas que ya haya en el archivo
void cargaListaPersonas(Persona listaPersonas[], int* validos)
{
    int i = *validos; ///ultima posicion
    char continuar = 's';
    while( i < CANT_MAX && continuar == 's')
    {
        cargaPersona(&listaPersonas[i]);
        //altaPersonaEnArchivo(p);
        printf("Desea cargar otra persona?\n");
        fflush(stdin);
        scanf("%c", &continuar);
        i++;
    }

    *validos = i;

}


void cargaListaPersonasOrdenada(Persona listaPersonas[], int* validos)
{
    int i = 0;
    char continuar;
    Persona p;
    do
    {
        cargaPersona(&p);
        insercionOrdenada(listaPersonas,i,p);
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
    while (i >= 0 && strcmpi(listaPersonas[i].nombre, p.nombre) >0)
    {
        listaPersonas[i+1] = listaPersonas[i];
        i--;
    }

    listaPersonas[i+1] = p;

}


///Trabajando con Archivos

void altaPersonaEnArchivo(Persona p)
{
    FILE* fp;
    fp = fopen(NOM_ARCH, "ab"); ///anado una persona al final del archivo
    if (fp != NULL)
    {
        fwrite(&p,sizeof(Persona),1,fp);
        fclose(fp);
    }
}

void persistenciaListaPersonas(Persona listaPersonas[], int validos)
{
    FILE* fp = fopen(NOM_ARCH, "wb");
    if (fp != NULL)
    {
        fwrite(listaPersonas,sizeof(Persona),validos,fp);
        fclose(fp);
    }

}

///considero que la lista de personas almacenada en archivo nunca va a superar CANT_MAX
/// me trae las personas dadas de alta y dadas de baja
void despersistirListaPersonas(Persona listaPersonas[], int* validos)
{
    FILE* fp = fopen(NOM_ARCH, "rb");
    int i = 0;
    if (fp != NULL)
    {
        while (i < CANT_MAX && fread(&listaPersonas[i],sizeof(Persona),1,fp) > 0)
        {
            i++;
        }

        fclose(fp);
    }

    *validos = i;

}
///modificacion

int contarPersonas()
{
    FILE * fp;
    fp = fopen(NOM_ARCH,"rb");
    int cant=0;
    if (fp != NULL)
    {
        fseek(fp,0,SEEK_END);
        cant = ftell(fp)/sizeof(Persona);
        fclose(fp);
    }

    return cant;

}

void modificarTelefono(Persona* p)
{
    printf("Ingrese nuevo telefono: ");
    fflush(stdin);
    gets((*p).telefono);
}

////vamos a un registro, nos lo traemos, modificamos el campo, y lo volvemos a escribir
///modo r+b -> lectura y escritura
void modificacionRegistro(char dni[])
{
    Persona p;
    FILE* fp;
    fp = fopen(NOM_ARCH,"r+b");
    int cantPersonas = contarPersonas();
    int i = 0;
    if (fp != NULL)
    {
        fread(&p,sizeof(Persona),1,fp);
        while (i < cantPersonas && strcmpi(p.DNI,dni) != 0)
        {
            fread(&p,sizeof(Persona),1,fp);
            i++;
        }
        if (i < cantPersonas)
        {
            modificarTelefono(&p);
            ///plasmo el registro modificado en el archivo
            fseek(fp,sizeof(Persona)*(-1),SEEK_CUR);
            fwrite(&p,sizeof(Persona),1,fp);
        }
        else
            printf("Dicho dni no se encuentra en los registros\n");
        fclose(fp);
    }


}

///baja de un registro
///la baja sera LOGICA, es decir, anadiremos un campo de BAJA para que cuando eliminemos una persona
///simplemente modifiquemos el valor de ese campo.

void bajaRegistro(char dni[])
{
    Persona p;
    FILE* fp;
    int cantPersonas;
    int i = 0;
    cantPersonas = contarPersonas();
    fp = fopen(NOM_ARCH, "r+b");
    if (fp != NULL)
    {
        fread(&p, sizeof(Persona),1,fp);
        while (i < cantPersonas && strcmpi(p.DNI,dni) != 0)
        {
            i++;
            fread(&p,sizeof(Persona),1,fp);
        }
        if (i < cantPersonas)
        {
            p.baja = 1;
            fseek(fp,sizeof(Persona)*(-1),SEEK_CUR);
            fwrite(&p,sizeof(Persona),1,fp);
        }

        fclose(fp);

    }

}

void mantenimientoArchivo()
{
    FILE* fp;
    Persona personas[CANT_MAX];
    int i = 0;
    fp = fopen(NOM_ARCH,"rb");
    if (fp != NULL)
    {
        while (fread(&personas[i],sizeof(Persona),1,fp) > 0 )
        {
            if (personas[i].baja == 0)
                i++;
        }
        fclose(fp);
        persistenciaListaPersonas(listaPersonas,i); ///sobreescribe el archivo
    }
}


int main()
{
    Persona listaPersonas[CANT_MAX];
    char dni[9];
    int validos = 0;
    despersistirListaPersonas(listaPersonas,&validos); ///traigo la lista a memoria
    //cargaListaPersonas(listaPersonas,&validos);
    //persistenciaListaPersonas(listaPersonas,validos);
    mostrarListaPersonas(listaPersonas,validos);
    printf("Ingrese dni a buscar: ");
    fflush(stdin);
    gets(dni);
    modificacionRegistro(dni);
    despersistirListaPersonas(listaPersonas,&validos);
    mostrarListaPersonas(listaPersonas,validos);
    bajaRegistro("2238743");
    bajaRegistro("2238742");
    bajaRegistro("2238741");
    mantenimientoArchivo(); ///realiza una limpieza de las personas dadas de baja


    return 0;
}
