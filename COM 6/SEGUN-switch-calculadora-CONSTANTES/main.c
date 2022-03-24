#include <stdio.h>
#include <stdlib.h>

///CONSTANTES
/**
   ->Es un valor
   -> NO ES UNA VARIABLE FIJA
   ->No se puede modificar en tiempo de ejecucion
   -> se le da nombre a los valores, tienen un espacio designado en el programa
   -> por convencion las constantes de declaran en mayuscula
   -> se declara debajo de las librerias y por encima de cualquier funcion (main), en el ambito global
**/

#define SALIR 5
#define PI 3.14
//const int num = 3;

/**
 SEGUN opcion HACER
   CASO 1:
          ....
   CASO 2:
          ....
   ...
   CASO N:
         ...
   De Otro Modo:
                ....
 FIN-SEGUN


 CALCULADORA
  MENU
  - Ingrese 2 valores enteros

  1 - SUMA
  2 - RESTAR
  3 - MULTIPLICAR
  4 - DIVIDIR
 - muestra el resultado


**/
int main()
{
    int operando1,operando2,opcion;
    float resultado=0;
    ///printf("%.2f",PI);
    do
    {
        printf("MENU DE OPCIONES\n");
        printf("1 - SUMA\n");
        printf("2 - RESTA\n");
        printf("3 - MULTIPLICACION\n");
        printf("4 - DIVISION\n");
        printf("5 - SALIR\n");
        printf("Elija una opcion: ");
        scanf("%i", &opcion);
        if (opcion > 0 && opcion < 6) ///validacion
        {
            if (opcion != SALIR )
            {
                printf("Ingrese valor 1: ");
                scanf("%i", &operando1);
                printf("Ingrese valor 2: ");
                scanf("%i", &operando2);
                switch(opcion)
                {
                case 1:
                    resultado = operando1 + operando2;
                    break;///cortar con el flujo del switch, se va afuera del ambito del switch
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
                system("PAUSE"); ///se queda esperando hasta que el usuario presione una tecla
                system("cls"); ///limpia la pantalla

            }
            else
                printf("Saliendo del programa...");
        }
        else
        {
            printf("opcion invalida\n");
        }
    }
    while(opcion != SALIR);





    return 0;
}
