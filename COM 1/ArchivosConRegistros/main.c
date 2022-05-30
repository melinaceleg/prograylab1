#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOM_ARCH "ArchivoPersonas.bin"
#define CANT_MAX 20

/**
    Alta - Modificacion - Baja de un registro en el archivo
    Alta -> Agregar una nueva persona
    Modificacion -> modificar un campo de un registro ya existente
    Baja -> (Baja logica) -> tener un campo adicional en la estructura que indica si el dato fue dado de baja o sigue activo


**/

//persona1 baja = 1
//persona2 baja = 1
//persona3 baja = 1
//persona4 baja = 0
//persona5 baja = 0
//persona6 baja = 1


typedef struct
{
    char nombre[20];
    char dni[9];
    char telefono[20];
    char o_social[20];
    int edad;
    int baja; ///campo que se setea en 1 -> si esta dado de baja o 0 -> si esta activo
} Persona;

///prototipado
///funciones con el arreglo
void cargaPersona(Persona*);
void cargaListaPersonas(Persona[], int*);
void muestraUnaPersona(Persona);
void muestraListaPersonas(Persona[],int);
void insercionOrdenada(Persona[],int,Persona);

///guardar datos en el archivo
void persistenciaListaPersonas(Persona[],int);

///traernos los datos del archivo
void despersistenciaListaPersonasSECUENCIAL(Persona[],int*);
void despersistenciaListaPersonasDIRECTO(Persona[],int*);
///dar de alta UNA persona en el archivo
void altaPersona();
void altaPersonaEnArchivoOrdenado();

///modificacion de un registro del archivo
void modificacionRegistro(char[]); ///modificacion de un registro buscando por DNI
int busquedaDniEnArchivo(FILE*,char[],Persona*);

///modificacion de un campo
void modificacionTelefono(Persona*);
void modificacionNombre(Persona*);

///baja logica
void bajaRegistroLogico(char[]);
void filtradoRegistrosDadosDeBaja();

///implementacion

/**
    Para modificar uin registro, debo leer para encontrar el dato a modificar
    Luego, me traigo el dato y lo modifico
    Reescribo el dato en el archivo
    El modo de apertura para modificar un registro debe ser:
        r+b -> implica lectura y escritura de un archivo binario
**/

int busquedaDniEnArchivo(FILE* fp,char dni[], Persona* p)
{
    int flag=0;
    while (fread(p,sizeof(Persona),1,fp) > 0 && strcmpi((*p).dni,dni) != 0);
    if (ftell(fp) > 0 && strcmpi((*p).dni,dni) == 0) ///si el archivo no estaba vacio, y el ultimo dato que lei es el que buscaba
    {
        flag =1;
    }
    return flag;

}

void modificacionTelefono(Persona* p)
{
    printf("Ingrese nuevo telefono: \n");
    fflush(stdin);
    gets((*p).telefono);
}

void modificacionRegistro(char dni[])
{
    FILE* fp;
    Persona p;
    fp = fopen(NOM_ARCH,"r+b");
    if (fp != NULL)
    {
        if (busquedaDniEnArchivo(fp,dni,&p) == 1)
        {
            modificacionTelefono(&p);
            ///ahora tengo que pisar el registro que contenia esta persona con la modificada
            fseek(fp,sizeof(Persona)*(-1),SEEK_CUR); ///me muevo una persona hacia atras desde donde estoy
            ///escribo la persona modificada en ese registro
            fwrite(&p,sizeof(Persona),1,fp);
        }
        else
        {
            printf("No existe dicho DNI en los registros\n");
        }

        fclose(fp);

    }
}

///baja logica de un registro
void bajaLogicaRegistro(char dni[])
{
    FILE *fp;
    Persona p;
    fp = fopen(NOM_ARCH,"r+b");
    if (fp != NULL)
    {
        if (busquedaDniEnArchivo(fp,dni,&p) == 1)
        {
            p.baja = 1; ///modificamos el campo de baja a 1
            fseek(fp,sizeof(Persona)*(-1), SEEK_CUR);
            fwrite(&p,sizeof(Persona),1,fp);
        }

        fclose(fp);

    }

}
///si yo no filtro mediante el arreglo
///debo cada tanto generar este mantenimiento de eliminar los registros dados de baja
void filtradoRegistrosDadosDeBaja()
{
    FILE* fp;
    int validos;
    Persona listaPersonas[CANT_MAX];
    despersistenciaListaPersonasSECUENCIAL(listaPersonas,&validos);///trae la lista de personas activas
    persistenciaListaPersonas(listaPersonas,validos); ///persiste la lista de personas activa
}



///si el archivo no posee un orden particular
void altaPersona()
{
    Persona p;
    FILE* fp;
    cargaPersona(&p);
    fp = fopen(NOM_ARCH,"ab"); /// abre el archivo y situa el puntero al final, lo anado al final del archivo
    if (fp != NULL)
    {
        fwrite(&p,sizeof(Persona),1,fp);
        fclose(fp);
    }

}

void altaPersonaEnArchivoOrdenado()
{
    Persona p;
    Persona listaPersonas[CANT_MAX];
    int validos=0;
    cargaPersona(&p);
    despersistenciaListaPersonasDIRECTO(listaPersonas,&validos); ///nos traemos las personas a un arreglo
    insercionOrdenada(listaPersonas,validos,p); ///insertamos la nueva persona ordenadamente
    validos++; ///incrementalos los validos
    persistenciaListaPersonas(listaPersonas,validos); ///volvemos a guardar la lista de personas con la nueva persona agreegada
}

void cargaPersona(Persona* p)
{
    printf("NOMBRE: ");
    fflush(stdin);
    gets((*p).nombre);
    printf("DNI: ");
    fflush(stdin);
    gets((*p).dni);
    printf("EDAD: ");
    scanf("%i", &((*p).edad));
    printf("Obra Social: ");
    fflush(stdin);
    gets((*p).o_social);
    printf("Telefono: ");
    fflush(stdin);
    gets((*p).telefono);
    (*p).baja = 0; /// seteado por default en 0 ya que esta ACTIVO el registro en el archivo
}

void insercionOrdenada(Persona listaPersonas[],int validos, Persona p)
{
    int i = validos -1;
    while (i>=0 && strcmpi(listaPersonas[i].nombre, p.nombre) > 0 )
    {
        listaPersonas[i+1] = listaPersonas[i]; ///hago un corrimiento de una PERSONA hacia la posicion siguiente
        i--;
    }

    listaPersonas[i+1] = p; ///inserto la PERSONA en el hueco
}

///algoritmo de carga de personas por teclado en orden de llegada
void cargaListaPersonas(Persona listaPersonas[], int* validos)
{
    char continuar;
    int i=*validos;
    Persona p;
    do
    {
        //cargaPersona(&agenda[i]); //cargo una persona por orden de llegada
        cargaPersona(&p);
        insercionOrdenada(listaPersonas,i,p);
        printf("desea cargar otra persona?\n");
        fflush(stdin);
        scanf("%c", &continuar);
        i++;
    }
    while(i<CANT_MAX && continuar == 's');

    *validos = i;
}


void muestraListaPersonas(Persona listaPersonas[], int validos)
{
    for (int i = 0; i < validos ; i++)
    {
        muestraUnaPersona(listaPersonas[i]);

    }
}

void muestraUnaPersona(Persona p)
{
    printf("Nombre: %s\n", p.nombre);
    printf("DNI: %s\n", p.dni);
    printf("Edad: %i\n", p.edad);
    printf("Telefono: %s\n", p.telefono);
    printf("Obra Social: %s\n", p.o_social);
}

///cada vez que invoque a esta funcion se reescribira los datos del archivo con los datos del arreglo
void persistenciaListaPersonas(Persona listaPersonas[], int validos)
{
    FILE* fp;
    fp = fopen(NOM_ARCH,"wb");
    if (fp != NULL)
    {
        fwrite(listaPersonas,sizeof(Persona),validos,fp);
        fclose(fp);

    }

}
///lectura secuencial
///despersistencia de datos activos en mi archivo
///filtro solo los que estan dados de alta
void despersistenciaListaPersonasSECUENCIAL(Persona listaPersonas[], int* validos)
{
    FILE* fp;
    fp = fopen(NOM_ARCH,"rb");
    int i = 0;
    if (fp != NULL)
    {
        while (fread(&listaPersonas[i],sizeof(Persona),1,fp) > 0 )
        {
            if (listaPersonas[i].baja == 0) // si no esta dado de baja
                i++;
        }

        *validos = i;

        fclose(fp);
    }


}

///despersistencia de datos activos y no activos en mi archivo
/// en una despersistencia directa nos traemos TODO, incluso los dados de baja
void despersistenciaListaPersonasDIRECTO(Persona listaPersonas[], int* validos)
{
    FILE* fp;
    fp = fopen(NOM_ARCH, "rb");
    if (fp != NULL)
    {
        fseek(fp,0,SEEK_END); ///me situo al final;
        *validos = ftell(fp)/sizeof(Persona);
        fseek(fp,0,SEEK_SET); /// me vuelvo a situar al principio   //rewind(fp);
        fread(listaPersonas,sizeof(Persona),*validos,fp); ///leo la lista de personas de una tirada
        fclose(fp);
    }


}



int main()
{
    Persona listaPersonas[CANT_MAX];
    int validos = 0;
    char dni[9];
//    cargaListaPersonas(listaPersonas,&validos);
//   persistenciaListaPersonas(listaPersonas,validos);
//   //despersistenciaListaPersonasSECUENCIAL(listaPersonas,&validos);
    despersistenciaListaPersonasDIRECTO(listaPersonas,&validos);
    muestraListaPersonas(listaPersonas,validos);
    printf("Ingrese el dni de la persona a buscar: ");
    fflush(stdin);
    gets(dni);
    modificacionRegistro(dni);

    return 0;
}
