#include <stdio.h>
#include <stdlib.h>

#define FIL 3
#define COL 3


/**
    MATRIZ

         a00 a01 a02
     A=  a10 a11 a12
         a20 a21 a22
                    3x3

      aij  i fila  j columna

    int vector[4]
             a00 a01 a02 a03
                            1x4

    int matriz[3][3]/// matriz[cantFilas][cantColumnas]
    a00 -> matriz[0][0] = 3; a01 -> matriz[0][1] = 4; a02 -> matriz[0][2] = 8;
    a10 -> matriz[1][0] = 7; a11 -> matriz[1][1] = 10; a12 -> matriz[1][2] = 6;
    a20 -> matriz[2][0] = 4; a21 -> matriz[2][1] = 3;  a22 -> matriz[2][2] = 9;



    **/


///en funciones

///prototipo
void cargaMatriz(int[][COL],int*, int*);
void muestraMatriz(int[][COL],int, int);

///implementacion

void cargaMatriz(int matriz[][COL],int* validosF, int* validosC)
{
    int i = 0;
    char continuar;
    do
    {
        printf("Ingrese la cantidad de columnas que desea cargar por cada fila: ");
        scanf("%i", validosC);
    }
    while(*validosC > COL);

    do
    {
        printf("FILA %i\n", i+1);
        for (int j = 0; j < *validosC; j++)
        {
            printf("a[%i][%i]=", i,j);
            scanf("%i", &matriz[i][j]);
        }
        i++;
        printf("Desea agregar otra fila?\n");
        fflush(stdin);
        scanf("%c",&continuar);
    }
    while(i<FIL && continuar =='s');

    *validosF = i;

}

void muestraMatriz(int matriz[][COL], int validosF, int validosC)
{
    for (int i = 0 ; i < validosF; i++)
    {
        for (int j = 0; j < validosC; j++)
        {
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }


}


int main()
{
    int matriz[FIL][COL] = {{2,3,5}, {6,8,1}, {9,6,2}};

    int matriz2[FIL][COL];
    for (int i=0 ; i< FIL; i++)
    {
        for (int j = 0 ; j < COL; j++)
        {
            printf("a[%i][%i] =:",i,j);
            scanf("%i", &matriz2[i][j]);
        }

        printf("\n");
    }

    for (int i =0 ; i < FIL; i++)
    {
        for (int j = 0; j < COL; j++) ///recorro todas las columnas
        {
            printf("%i ", matriz2[i][j]);
        }

        printf("\n"); ///hago salto de linea para luego ir a la siguiente fila
    }

    ///puedo no cargar completamente mi matriz, no cargando todas las filas
    ///pero las columnas las debo cargar completamente por cada fila
    ///por lo tanto: puedo tener un validos de filas

    int matriz3[FIL][COL];
    char continuar;
    int i = 0;
    int validosF;

    do
    {
        printf("cargando fila %i\n", i+1);
        for (int j = 0 ; j < COL ; j++)
        {
            printf("a[%i][%i]=",i,j);
            scanf("%i",&matriz3[i][j]);
        }
        i++;
        printf("desea cargar otra fila?\n");
        fflush(stdin);
        scanf("%c", &continuar);
    }
    while(i<FIL && continuar == 's');

    validosF = i; ///cantidad de filas cargadas


    for (int i =0 ; i < validosF; i++)
    {
        for (int j = 0; j < COL; j++) ///recorro todas las columnas
        {
            printf("%i ", matriz3[i][j]);
        }

        printf("\n"); ///hago salto de linea para luego ir a la siguiente fila
    }



    ///puedo usar una combinacion de validos de filas y tambien validos de columnas
    ///por lo tanto me quedaria una submatriz mas pequena o igual a la que yo puedo generar

    int matriz4[FIL][COL];
    int validosF;
    int validosC;

    cargaMatriz(matriz,&validosF,&validosC);
    muestraMatriz(matriz,validosF,validosC);

//    int i = 0;
//    char continuar;
//    printf("Cuantas columnas por cada fila desea cargar?\n");
//    scanf("%i", &validosC);
//    while (validosC > COL)
//    {
//        printf("Ingrese nuevamente una cantidad de columnas menor o igual a %i: ", COL);
//        scanf("%i", &validosC);
//    }
//
//    do
//    {
//        printf("FILA %i\n", i+1);
//        for (int j = 0; j< validosC; j++)
//        {
//            printf("a[%i][%i]=",i,j);
//            scanf("%i",&matriz4[i][j]);
//        }
//
//        i++;
//        printf("Desea ingresar otra fila?\n");
//        fflush(stdin);
//        scanf("%c", &continuar);
//    }
//    while (i<FIL && continuar == 's');
//
//    validosF = i;
//
//    for ( int i = 0; i < validosF; i++)
//    {
//        for (int j = 0; j< validosC ; j++)
//        {
//            printf("%i ", matriz4[i][j]);
//        }
//        printf("\n");
//    }


    return 0;
}
