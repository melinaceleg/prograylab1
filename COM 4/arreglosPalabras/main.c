#include <stdio.h>
#include <stdlib.h>
#define FIL 10
#define COL 35

/**
    Arreglos de palabras

    -> Es una matriz de caracteres en la cual a cada fila la voy a interpretar como un bloque completo de texto
    -> Se recorre solamente por filas, por cada fila tengo un string

    char palabras[4][5] -> puedo cargar 4 lineas de texto de 4 caracteres de longitud para ingresar + '\0'



**/

///funciones

///prototipos
void cargaArregloPalabras(char[][COL], int*);
void muestraArregloPalabras(char [][COL], int);
void insercionOrdenadaString(char [][COL], int, char[]);


///implementacion
void cargaArregloPalabras(char arregloPalabras[][COL], int* validos)
{
    int i = 0;
    char continuar;
    char string[COL];

    do
    {
        printf("Ingrese un texto\n");
        fflush(stdin);
        gets(string);
        insercionOrdenadaString(arregloPalabras,i,string);
        i++;
        printf("Desea cargar otro string?\n");
        fflush(stdin);
        scanf("%c", &continuar);

    }
    while(i < FIL && continuar == 's');

    *validos = i;

}


void muestraArregloPalabras(char arregloPalabras[][COL], int validos)
{
    for (int i = 0 ; i < validos; i++)
    {
        printf("%s\n",arregloPalabras[i]);
        //puts(arregloPalabras[i]);
    }
}


void insercionOrdenadaString(char arregloPalabras[][COL], int validos, char string[COL])
{
    int i = validos - 1;

    while (i >= 0 && strcmp(arregloPalabras[i],string) > 0)
    {
        strcpy(arregloPalabras[i+1],arregloPalabras[i]);
        i--;
    }

    strcpy(arregloPalabras[i+1],string);

}




int main()
{
    char matriz[4][5] = {{'h','o','l','a','\0'},
        {'d','o','s','\0','h'},
        {'m','a','l','o','\0'},
        {'u','n','\0','t','l'}
    };

for (int i = 0 ; i < FIL ; i++ )
{
    for (int j = 0; j < COL; j++)
    {
        printf("%c ", matriz[i][j]);
    }
    printf("\n");
}

for (int i = 0; i < FIL; i++)
{
    printf("%s\n", matriz[i]);
    //puts(matriz[i]);
}

char arregloPalabras[4][35];

for (int i = 0 ; i < FIL; i++)
{
    printf("Ingrese un texto para fila %i\n", i);
    fflush(stdin);
    gets(arregloPalabras[i]);
}

for (int i = 0; i < FIL; i++)
{
   puts(arregloPalabras[i]);
}



    char arregloPalabras[FIL][COL];
    int validos;
    cargaArregloPalabras(arregloPalabras,&validos);
    muestraArregloPalabras(arregloPalabras,validos);


    return 0;
}
