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

HACER

    **IMPRIMIR EL MENU**
    leer opcion

    SEGUN OPCION HACER
    CASO 1:
        Hacer esto
    CASO 2:
         Hacer esto otro
    ...
    CASO N:
          HAcer este N cosa
    De Otro Modo:
          escribir 'OPCION INVALIDA'
    FINSEGUN

MIENTRAS-QUE (CONDICION);
**/

int main()
{
    ///DO - WHILE : SENTENCIAS - CONDICION - SENTENCIAS - CONDICION - SENTENCIAS ....

    int operando1, operando2,opcion;
    float resultado=0;
    do
    {

        printf("MENU DE OPCIONES\n");
        printf("1 - SUMA\n");
        printf("2 - RESTA\n");
        printf("3 - MULTIPLICACION\n");
        printf("4 - DIVISION\n");
        printf("5 - SALIR\n");
        printf("Ingrese su opcion: ");
        scanf("%i",&opcion);

        while (opcion < 1 || opcion > 5) ///validacion
        {
            printf("Opcion invalida..\n");
            printf("Ingrese su opcion: ");
            scanf("%i",&opcion);
        }

        if (opcion != 5)
        {
            printf("Ingrese valor1: ");
            scanf("%i", &operando1);
            printf("Ingrese valor2: ");
            scanf("%i", &operando2);

            switch(opcion)
            {
            case 1:
                resultado = operando1 + operando2;
                break;//corto el flujo del switch para que no evalue los otros casos, sale afuera
            case 2:
                resultado = operando1 - operando2;
                break;
            case 3:
                resultado = operando1 * operando2;
                break;
            case 4:
                resultado = (float)operando1 / operando2;
                break;
            }

            printf("El resultado es: %.2f\n", resultado);
            system("PAUSE"); /// espera a que el usuario aprete una tecla
            system("cls"); ///limpia la pantalla
        }
        else
            printf("Saliendo del programa...\n");
    }while(opcion != 5);



    return 0;
}
