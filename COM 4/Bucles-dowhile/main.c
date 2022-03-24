#include <stdio.h>
#include <stdlib.h>

/**
   HACER-MIENTRAS // DO-WHILE

   HACER
    sentencias
    ..
    sentencias
   Mientras CONDICION

   do {
    SENTENCIAS
    ..
    SENTENCIAS
   while(condicion);

   DO-WHILE = SENTENCIAS - CONDICION - SENTENCIAS - CONDICION
   -> al menos una vez vamos a pasar por las sentencias

**/
/**
 Escribir un programa que solicite la carga de números entre 0 y 999 y nos muestre un mensaje
 de cuántos dígitos tiene cada número.
Finalizar el programa cuando se cargue el valor 0.
**/

int main()
{
    int numero;

    do
    {
        printf("Ingrese un valor\n");
        scanf("%i",&numero);
        while (numero < 0 || numero >= 1000) ///validacion del numero
        {
            printf("numero incorrecto, vuelva a ingresarlo..\n");
            scanf("%i",&numero);
        }

        if (numero > 0 && numero < 10)
        {
            printf("El numero tiene 1 digito\n");
        }
        else if (numero >= 10 && numero < 100)
        {
            printf("El numero tiene 2 digitos\n");
        }
        else
        {
            if (numero >=100)
            {
                printf("El numero tiene 3 digitos\n");
            }
        }

    }
    while (numero != 0);


    return 0;
}
