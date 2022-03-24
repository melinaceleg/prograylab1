#include <stdio.h>
#include <stdlib.h>
/**
CALCULADORA
-EL usuario ingresara 2 valores enteros

MENU
 1 - SUMA
 2 - RESTA
 3 - MULTIPLICAR
 4 - DIVIDIR

Se muestra el resultado de la operacion
**/

int main()
{
    int operando1, operando2,opcion;
    float resultado;
    printf("Ingrese valor1: ");
    scanf("%i", &operando1);
    printf("Ingrese valor2: ");
    scanf("%i", &operando2);

    printf("MENU DE OPCIONES\n");
    printf("1 - SUMA\n");
    printf("2 - RESTA\n");
    printf("3 - MULTIPLICACION\n");
    printf("4 - DIVISION\n");
    printf("Ingrese su opcion: ");
    scanf("%i",&opcion);

    if (opcion == 1)
    {
        resultado = operando1 + operando2;
    }
    else  ///sino
    {
        if (opcion == 2)
        {
            resultado = operando1 - operando2;
        }
        else
        {
            if (opcion == 3)
            {
                resultado = operando1 * operando2;
            }
            else
            {
                if (opcion == 4)
                {
                    resultado = (float)operando1 / operando2;
                }
                else
                {
                    printf("La opcion es invalida..\n");
                }
            }

        }

    }
    printf("El resultado es: %.2f", resultado );

    return 0;
}
