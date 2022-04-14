#include <stdio.h>
#include <stdlib.h>

#define SALIR 0

/**

Realice una pequeña calculadora, utilizando funciones
(una función de suma, una de multiplicación, una de resta, una de división…)
**/
///prototipos
int suma(int, int); ///realiza la suma de 2 enteros
int resta(int,int); ///realiza la resta de 2 enteros
int multiplicacion(int,int); ///realiza el producto de 2 enteros
float division(int,int); ///realiza la division entre 2 enteros
void menuCalculadora(); ///Menu de la calculadora donde se ingresan los valores y se elige la operacion




int suma(int op1, int op2)
{
    int sum;

    sum = op1 + op2;

    return sum;
}

int resta(int op1, int op2)
{
    int rest;

    rest = op1 - op2;

    return rest;

}

int multiplicacion(int op1, int op2)
{

    return op1*op2;

}

float division(int op1, int op2)
{

    return (float)op1/op2;
}


void menuCalculadora()
{
    int opcion;
    int op1;
    int op2;
    float resultado;

    do
    {
        resultado = 0;
        printf("***MENU CALCULADORA***\n");
        printf("1. SUMA\n");
        printf("2. RESTA\n");
        printf("3. PRODUCTO\n");
        printf("4. DIVISION\n");
        printf("0. SALIR\n");
        printf("Elija la opcion: ");
        scanf("%i", &opcion);

        while (opcion < 0 || opcion > 4) ////verificacion
        {
            printf("Opcion invalida, por favor ingrese otra vez :");
            scanf("%i",&opcion);
        }

        if (opcion != SALIR) ///si no eligio salir
        {

            printf("Ingrese operando1: ");
            scanf("%i", &op1);
            printf("Ingrese operando2: ");
            scanf("%i", &op2);
            switch(opcion)
            {
            case 1:
                resultado = suma(op1,op2);
                break;
            case 2:
                resultado = resta(op1,op2);
                break;
            case 3:
                resultado = multiplicacion(op1,op2);
                break;
            case 4:
                if (op2 != 0)
                    resultado = division(op1,op2);
                else
                    printf("ERROR: Division por 0\n");
                break;
            }
            if (op2 != 0 || opcion != 4)
            {
                printf("Resultado de la operacion: %.2f \n", resultado);
            }
            system("PAUSE");
            system("cls");

        }

    }while (opcion != SALIR);

}



int main()
{
    menuCalculadora();


    return 0;
}
