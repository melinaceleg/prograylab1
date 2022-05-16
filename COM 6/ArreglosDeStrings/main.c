#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FIL 20
#define COL 30

/**
    Arreglos de strings
    -> es una matriz de caracteres donde cada fila se la considera como un bloque completo de texto (string)
    -> Se recorre solo por filas, por cada fila tengo un string


    char arregloStrings[4][10]; -> puedo cargar 4 lineas de texto o 4 strings de una longitud 9 caracteres + '\0'

        '\0' terminator o nulo


    'j' 'u' 'a' 'n' '\0'
    'P' 'a' 'b' 'l' 'o' '\0'
    'P' 'i' 'o' '\0'
    'M' 'a' 'r' 'i' 'a' 'n' 'o' '\0'

    No se evalua algoritmos de ordenacion en la 2da parte de la cursada

**/

///funciones

///prototipados
void cargaArregloStrings(char[][COL], int*);
void muestraArregloStrings(char[][COL], int);
void insercionOrdenada(char [][COL], char[], int);


///implementacion
void insercionOrdenada(char arregloStrings[][COL], char nombre[], int validos)
{
    int i = validos - 1;
    while (i >=0 && strcmpi(arregloStrings[i],nombre) > 0)
    {
        strcpy(arregloStrings[i+1],arregloStrings[i]);
        i--;
    }

    strcpy(arregloStrings[i+1], nombre);

}


void cargaArregloStrings(char arregloStrings[][COL], int* validos)
{
    int i = 0;
    char continuar;
    char nombre[COL];
    do
    {
        printf("Ingrese string a cargar\n");
        fflush(stdin);
        gets(nombre);
        insercionOrdenada(arregloStrings,nombre,i);
        i++;
        printf("Desea cargar otro string?\n");
        fflush(stdin);
        scanf("%c",&continuar);
    }
    while (i < FIL && continuar == 's');

    *validos = i;

}

void muestraArregloStrings(char arregloStrings[][COL], int validos)
{
    for (int i = 0; i < validos ; i++)
    {
        printf("%s\n", arregloStrings[i]); /// puts(arregloStrings[i]);
    }



}

int main()
{
    char arregloStrings[FIL][COL] = {"Juan Pablo",
                                     "Pedro Gomez",
                                     "Mario Lopez",
                                     "Mariano toy"
                                    };
///muestra
    for (int i = 0; i < FIL; i++)
    {
        printf("%s\n", arregloStrings[i]);
    }

///carga a traves del teclado y el usuario va a decidir hasta donde cargar
///tenemos un validos que es el validos de filas

    char nombresAlumnos[FIL][COL];
    int validos;
    char continuar;
    int i = 0;

    do
    {
        printf("Ingrese un nombre y apellido de alumno\n");
        fflush(stdin);
        gets(nombresAlumnos[i]); ///scanf("%s", nombresAlumnos[i]); no nos conviene para nombres y apellidos ( para texto que contenga espacios u otros caracteres especiales)
        i++;
        printf("Desea agregar otro alumno?\n");
        fflush(stdin);
        scanf("%c",&continuar);

    }
    while( i < FIL && continuar == 's');

    validos = i ;

///muestra
    for (int i = 0 ; i < validos; i++)
    {
        printf("%s\n",nombresAlumnos[i]);
    }


///uso de  funciones
    char arregloStrings[FIL][COL];
    int validos;
    cargaArregloStrings(arregloStrings,&validos);
    muestraArregloStrings(arregloStrings,validos);


    return 0;
}
