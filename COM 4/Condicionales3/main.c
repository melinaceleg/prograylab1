#include <stdio.h>
#include <stdlib.h>
/**
Desarrolle un algoritmo en el que se almacenen 3 números enteros leídos por teclado
 y nos indique cual de los tres es el mayor o si son iguales.

  SI numero1 > numero2 && numero1 > numero3 entonces
    escribir "numero1 es el mayor"
  FINSI
  SINO
     SI numero2 > numero1 && numero2 > numero3 entonces
      escribir "numero2 es el mayor"
     FINSI
     SINO
        SI numero3 > numero1 && numero3 > numero2 entonces
            escribir "numero3 es el mayor"
        FINSI
        SINO
           escribir "los numeros son iguales"


**/
int main()
{
    int numero1,numero2,numero3;
    printf("Ingrese numero1\n");
    scanf("%i", &numero1);
    printf("Ingrese numero2\n");
    scanf("%i", &numero2);
    printf("Ingrese numero3\n");
    scanf("%i", &numero3);

    if (numero1 > numero2 && numero1 >= numero3)
    {
        printf("%i es el mayor", numero1);
    }
    else
    {
        if (numero2 >= numero1 && numero2 > numero3)
        {
            printf("%i es el mayor", numero2);

        }
        else
        {
            if (numero3 > numero1 && numero3 >= numero2)
            {
                printf("%i es el mayor",numero3);

            }
            else
            {
                printf("Los 3 numeros son iguales\n");
            }
        }

    }



    return 0;
}
