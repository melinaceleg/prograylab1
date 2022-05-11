#include <stdio.h>
#include <stdlib.h>

#define FIL 3
#define COL 4

/**
        MATRICES

          a00 a01 a02
        A a10 a11 a12
          a20 a21 a22
                     3x3

        aij   i fila   j columna

        Matriz vector

        int vector[4]
                    a00 a01 a02 a03

        int matriz[3][4] -> matriz[cantFilas][cantColumnas]

                    a00 a01 a02 a03
                    a10 a11 a12 a13
                    a20 a21 a22 a23
                                   3x4

        a00 -> matriz[0][0] = 3;  a01 -> matriz[0][1] = 4;  a02 -> matriz[0][2] = 1; a03 -> matriz[0][3] = 8;
        a10 -> matriz[1][0] = 7;  a11 -> matriz[1][1] = 2;  a12 -> matriz[1][2] = 5; a13 -> matriz[1][3] = 9;
        a20 -> matriz[2][0] = 1;  a21 -> matriz[2][1] = 11; a22 -> matriz[2][2] = 14;a23 -> matriz[2][3] = 3;


**/


///usando funciones

///prototipados

void cargaMatriz(int[][COL], int*, int*); ///recuerden que se debe especificar si o si CANTIDAD DE COLUMNAS
void cargaMatrizCompleta(int[][COL]);
void muestraMatriz(int[][COL], int, int );


///implementacion
void cargaMatriz(int matriz[][COL], int* validosF, int* validosC)
{
    char continuar;
    int i=0;

    do
    {
        printf("Ingrese la cantidad de columnas que desea que se carguen en la filas: ");
        scanf("%i", validosC);
    }
    while(*validosC > COL);

    do
    {
        printf("FILA %i\n", i+1);
        for (int j = 0 ; j < *validosC, j++)
        {
            printf("matriz[%i][%j]=", i,j);
            scanf("%i",&matriz[i][j]);
        }
        i++;

        printf("Desea agregar otra fila?\n");
        fflush(stdin);
        scanf("%c", &continuar);
    }
    while(i < FIL && continuar == 's');

    *validosF = i;

}

void cargaMatrizCompleta(int matriz[][COL])
{
    for ( int i = 0 ; i < FIL; i++)
    {
        for (int j = 0 ; j < COL ; j++)
        {
            scanf("%i",&matriz[i][j]);
        }
    }

}



void muestraMatriz(int matriz[][COL], int validosF, int validosC)
{
    for (int i = 0 ; i < validosF ; i++)
    {
        for (int j = 0; j < validosC ; j++)
        {
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }

}


//char alumnos[20][30] = {{"Estefania Storari"},
//                        {"Juan Aguirre"},
//                        {"Fran Carne"}};
//
//



int main()
{
    /// indice i para filas indice j para columnas, i va de 0 a 2,  j va de 0 a 3
    int matriz[FIL][COL] = {{2,4,1,8},{5,1,2,3},{8,3,4,1}};

    int matriz2[FIL][COL];
    ///carga de una matriz completa mediante teclado
    for (int i = 0 ; i < FIL ; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("matriz2[%i][%i]=", i,j);
            scanf("%i",&matriz2[i][j]);
        }
        printf("\n");
    }

    ///mostrarla en formato matricial

    for (int i=0; i< FIL ; i++)
    {

        for (int j = 0; j < COL; j++)
        {
            printf("%i ", matriz2[i][j]);
        }

        printf("\n"); ///hago salto de linea para que ahora la proxima fila se me imprima debajo
    }

    ///Que pasa si la carga no la quiero hacer completa?
    ///puedo hacer un validos de FILAS -> cargar menos filas y las columnas completas

    int matriz3[FIL][COL];
    char continuar;
    int i = 0 ;
    int validosF=0;
    do
    {
        printf("CARGA FILA %i\n", i+1);
        for (int j = 0 ; j < COL ; j++)
        {
            printf("matriz3[%i][%i]=",i,j);
            scanf("%i",&matriz3[i][j]);
        }

        i++; //avanzamos a la siguiente fila

        printf("Desea cargar otra fila?\n");
        fflush(stdin);
        scanf("%c",&continuar);
    }while(i < FIL && continuar == 's');

    validosF = i; ///cantidad de filas cargadas

  ///MUESTRA:
    for (int i = 0 ; i < validosF ;i++)
    {
        for (int j = 0 ; j < COL ; j++)
        {
            printf("%i ", matriz3[i][j]);
        }

        printf("\n");
    }


    ///podriamos tener una combinacion en donde tengamos un validos de filas y un validos para columnas

    int matriz4[FIL][COL];
    int validosF=0;
    int validosC=0;

    cargaMatriz(matriz4,&validosF,&validosC);
    muestraMatriz(matriz4, validosF,validosC);



//    char continuar;
//    int i=0;
//
//    printf("Ingrese cantidad de columnas que desea que se cargue en cada fila:");
//    scanf("%i", &validosC);
//    while (validosC > COL) ///No podemos dejar que ingrese un valor MAYOR a col porque se rompe
//    {
//        printf("Esa es una cantidad que se excede, ingrese un valor entre 1 y %i: ", COL);
//        scanf("%i", &validosC);
//    }
//
//    do
//    {
//        printf("FILA %i\n", i+1);
//        for (int j= 0; j< validosC ; j++)
//        {
//            printf("Matriz4[%i][%i]=", i,j);
//            scanf("%i",&matriz4[i][j]);
//        }
//        i++;
//        printf("Desea agregar otra fila?\n");
//        fflush(stdin);
//        scanf("%c",&continuar);
//
//    }
//    while(i<FIL && continuar == 's');
//
//    validosF = i;
//
//    ///muestra
//
//    for (int i = 0; i < validosF; i++)
//    {
//        for (int j = 0 ; j < validosC ; j ++)
//        {
//            printf("%i ", matriz4[i][j]);
//        }
//
//        printf("\n");
//    }




    return 0;
}
