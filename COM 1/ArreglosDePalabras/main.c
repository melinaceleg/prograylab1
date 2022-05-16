#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FIL 20
#define COL 30

/**
    Arreglos de Strings

    ->Es una matriz de caracteres en la cual a cada fila la voy a interpretar como un bloque completo de texto
    -> Se recorre solo por filas, por cada fila tengo un string

    char arregloStrings[4][10]  -> puedo cargar 4 lineas de texto con una longitud de 9 caracteres cada una + '\0'

"Matias Diaz"

  0  "Ana Lopez"
  1  "Juan Pablo"
  2  "Matias Diaz"
  3  "Martin Gomez"


    'p' 'e' 'd' 'r' 'o' '\0'
    'j' 'u' 'a' 'n' '\0'
    't' 'e' 'o' '\0'
    'm' 'a' 'u' 'r' 'i' 'c' 'i' 'o' '\0'



**/

///funciones

///prototipos
void cargaArregloStrings(char[][COL], int*); ///carga a traves del usuario hasta donde quiera
void muestraArregloStrings(char[][COL], int);
void insercionOrdenada(char [][COL], char[], int validos);



///implementacion
void cargaArregloStrings(char arregloStrings[][COL], int* validos)
{
    int i = 0;
    char continuar;
    char nombre[COL];
    do
    {
        printf("Ingrese un string\n");
        fflush(stdin);
        gets(nombre);
        insercionOrdenada(arregloStrings,nombre,i);
        printf("Desea cargar otro string?\n");
        fflush(stdin);
        scanf("%c",&continuar);
        i++;


    }
    while (i < FIL && continuar == 's');

    *validos = i;

}


void insercionOrdenada(char arregloStrings[][COL], char nombre[], int validos)
{
    int i = validos - 1;
    while (i >=0 && strcmp(arregloStrings[i],nombre) >0)
    {
        strcpy(arregloStrings[i+1], arregloStrings[i]);
        i--;
    }

    strcpy(arregloStrings[i+1],nombre);

}



void muestraArregloStrings(char arregloStrings[][COL], int validos)
{
    for (int i = 0 ; i < validos ; i++)
    {
        puts(arregloStrings[i]); ///imprime y hace un salto de linea
    }

}



int main()
{
//  char nombresAlumnosCOM1[4][30] = {"Juan Pablo","Luciano Pagnutti", "Federico Falotiche", "Imanol Quiroga"};
///// puedo cargar 4 nombres de alumnos de una longitud de 29 caracteres cada uno
// ///recorro solo por filas
//
// for (int i = 0; i < FIL ; i++)
// {
//    printf("%s\n", nombresAlumnosCOM1[i]);
// }
////carga de una matriz de caracteres como arreglo de strings
/// -> la carga se da por filas
/// -> la carga el usuario
/// -> validos de filas

// char arregloNombres[FIL][COL];
// int validos;
// char continuar;
// int i = 0;
// do
// {
//     printf("Ingrese nombre de alumno\n");
//     fflush(stdin);
//     gets(arregloNombres[i]); /// scanf("%s",arregloNombres[i]) No nos conviene, porque tenemos nombres con espacios;
//     i++;
//     printf("Desea agregar otro alumno?\n");
//     fflush(stdin);
//     scanf("%c", &continuar);
// }while (i < FIL && continuar == 's');
//
// validos = i;
//
// for (int h = 0 ; h < validos ; h++ )
// {
//     printf("%s\n", arregloNombres[h]); ///puts(arregloNombres[i]);
// }

///carga con funciones

    char arregloStrings[FIL][COL];
    int validos;
    cargaArregloStrings(arregloStrings, &validos);
    muestraArregloStrings(arregloStrings, validos);


    return 0;
}
