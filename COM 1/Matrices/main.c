#include <stdio.h>
#include <stdlib.h>
#define FIL 4
#define COL 3


/**
    MATRICES

        a00 a01 a02
    A = a10 a11 a12
        a20 a21 a22
                    3x3

    aij  i fila  j columna


    vector horizontal
    int vector[3] a00 a01 a02
                   vector 1x3


    int matriz[4][3];   int matriz[cantFilas][cantcolumnas]

    a00 -> matriz[0][0] = 3;  a01 -> matriz[0][1] = 4;  a02 -> matriz[0][2] = 8;
    a10 -> matriz[1][0] = 10; a11 -> matriz[1][1] = 6; ...


**/

///funciones

///prototipado
void cargaMatriz(int[][COL], int*,int*);
void muestraMatriz(int[][COL], int,int);
void cargaCompletaMatriz(int[][COL]);


///implementacion

void cargacompletaMatriz(int matriz[][COL])
{
    for (int i = 0 ; i < FIL ; i++)
    {
        for (int j = 0 ; j < COL ; j++)
        {
            printf("matriz[%i][%i]=",i,j);
            scanf("%i", &matriz[i][j]);
        }
    }
}



void cargaMatriz(int matriz[][COL], int* validosF,int* validosC)
{
    int i = 0;
    char continuar;

    do
    {
        printf("Ingrese cantidad de columnas a cargar\n");
        scanf("%i", validosC);
    }
    while (*validosC < 1  || *validosC > COL);

    do
    {
        printf("FILA %i\n", i);
        for (int j = 0 ; j < *validosC ; j++)
        {
            printf("matriz[%i][%i]=",i,j);
            scanf("%i", &matriz[i][j]);
        }
        i++;
        printf("Desea cargar otra fila?\n");
        fflush(stdin);
        scanf("%c",&continuar);
    }
    while (i < FIL && continuar == 's');

    *validosF = i;

}





void muestraMatriz(int matriz[][COL], int validosF, int validosC)
{
    for (int i = 0 ; i < validosF ; i++)
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
//   int matriz[FIL][COL] = {{4,8,10},
//                       {5,7,6},
//                       {8,9,10},
//                       {7,1,15}};
//
//   ///carga por teclado (por el usuario) de una matriz completa
//
//    for (int i = 0; i < FIL ; i++)
//    {
//        for (int j = 0; j < COL ; j++)
//        {
//            printf("matriz[%i][%i]=", i,j);
//            scanf("%i", &matriz[i][j]);
//        }
//        printf("\n");
//    }
//
//    ///muestra en formato matricial
//    for (int i = 0 ; i < FIL ; i++)
//    {
//        for (int j = 0 ; j < COL ; j++)
//        {
//            printf("%i ", matriz[i][j]);
//        }
//
//        printf("\n");
//    }
//


    /// puedo no cargar completamente mi matriz, eligiendo no cargar todas las filas
    /// voy a tener un validos de filas
    ///el usuario cargara por filas y decidira cuando cortar
    ///las columnas por cada fila se cargan completamente (COL)

//    int matriz[FIL][COL];
//    int validosF;
//
//    char continuar;
//    int i=0;
//
//    do
//    {
//        printf("FILA %i\n", i);
//        for (int j = 0 ; j < COL ; j++)
//        {
//            printf("matriz[%i][%i]=",i,j);
//            scanf("%i", &matriz[i][j]);
//        }
//
//        i++;
//        printf("Desea cargar otra fila?\n");
//        fflush(stdin);
//        scanf("%c",&continuar);
//
//    }
//    while(i<FIL && continuar == 's');
//
//    validosF = i; ///cantidad de filas CARGADAS
//
//    ///muestra de la matriz
//
//    for (int i = 0 ; i < validosF ; i++)
//    {
//        for (int j = 0 ; j < COL ; j++)
//        {
//            printf("%i ", matriz[i][j]);
//        }
//        printf("\n");
//    }

    ///Que pasa si ahora quiero implementar cargar solo ciertas columnas y ciertas filas?
    /// validosF y validosC
    /// de antemano debo saber cuantas columnas el usuario quiere cargar.

//    int matriz[FIL][COL];
//    int validosF;
//    int validosC;
//    char continuar;
//    int i = 0;
//
//    printf("cuantas columnas desea que se carguen?\n");
//    scanf("%i", &validosC);
//    while ( validosC > COL)
//    {
//        printf("Debe ingresar una cantidad de columnas menor o igual a %i: ", COL);
//        scanf("%i", &validosC);
//    }
//
//
//    do
//    {
//        printf("FILA %i\n", i);
//        for (int j = 0 ; j < validosC ; j++)
//        {
//            printf("matriz[%i][%i]=",i,j);
//            scanf("%i", &matriz[i][j]);
//        }
//        i++;
//        printf("Desea cargar otra fila?\n");
//        fflush(stdin);
//        scanf("%c", &continuar);
//    }
//    while (i < FIL && continuar == 's');
//
//    validosF = i;
//
//    ///muestra matriz
//    for (int i = 0 ; i < validosF ; i++)
//    {
//        for (int j = 0 ; j < validosC ; j++)
//        {
//            printf("%i ", matriz[i][j]);
//        }
//
//        printf("\n");
//    }

    ///yo podria luego volver a cargar otra fila entonces validosF se veria modificado
    ///pero validosC una vez que yo elegi el valor NO SE PUEDE ALTERAR MAS


    ///usando desde funciones
    int matriz[FIL][COL];
    int validosF;
    int validosC;
    //cargaMatriz(matriz,&validosF,&validosC);
    cargaCompletaMatriz(matriz);
    muestraMatriz(matriz,FIL,COL);




    return 0;
}
