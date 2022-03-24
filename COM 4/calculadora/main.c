#include <stdio.h>
#include <stdlib.h>

#define SALIR 6 //constante

/** CALCULADORA
El usuario ingresa dos valores

 1 - SUMA
 2 - RESTA
 3 - MULTIPLICACION
 4 - DIVISION

 SEGUN OPCION
    CASO 1
    CASO 2..
    ...
    CASO N...
    De Otra Forma: ... (caso por defecto)
  FINSEGUN

 **/

int main()
{
    int valor1,valor2,opcion;
    float resultado;

    do
    {
        printf("MENU DE OPCIONES\n");
        printf("1 - SUMA\n");
        printf("2 - RESTA\n");
        printf("3 - MULTIPLICACION\n");
        printf("4 - DIVISION\n");
        printf("6 - SALIR\n");
        printf("Elige una opcion: ");
        scanf("%i", &opcion);


        while (opcion < 1 || opcion > SALIR) ///validacion
        {
            printf("Opcion invalida.. vuelva a intentarlo\n");
            printf("Elige una opcion: ");
            scanf("%i", &opcion);
        }

        if (opcion != SALIR)
        {

            printf("Ingrese un valor\n");
            scanf("%i", &valor1);
            printf("Ingrese un valor\n");
            scanf("%i", &valor2);

            switch(opcion)
            {
            case 1:
                resultado = valor1 + valor2;
                break; ///sale de los cases
            case 2:
                resultado = valor1 - valor2;
                break;
            case 3:
                resultado = valor1 * valor2;
                break;
            case 4:
                resultado = (float)valor1 / valor2;
                break;
            }

            printf("El resultado es: %.2f\n",resultado);
            system("PAUSE"); ///va a esperar a que el usuario presione cualquier tecla
            system("cls"); ///limpiar pantalla
        }
    }
    while(opcion != SALIR);


    return 0;
}
