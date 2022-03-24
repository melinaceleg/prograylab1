#include <stdio.h>
#include <stdlib.h>

/**
 SI CONDICION ENTONCES
    //hago lo de aca adentro
 FINSI
...
...

 SI CONDICION ENTONCES
   ///hago lo de aca
   ///
   ///
 SINO
   ///hare esto otro
 FINSI

///Se debe determinar si un numero es negativo o positivo. (informar)

 Definir numerito como Entero

 escribir "ingrese un numero entero"
 leer numerito

 SI numerito > 0 entonces
   escribir "numerito es positivo"
 SINO
   escribir "numerito es 0 o negativo"
 FINSI


**/
///Se debe determinar si un numero es negativo o positivo. (informar)

//    int numerito;
//    printf("Ingrese un numero entero\n");
//    scanf("%i", &numerito);
//
//    if (numerito > 0)
//    {
//        printf("numerito es positivo\n");
//    }
//    else
//    {
//        printf("numerito es 0 o negativo\n");
//    }

/**
   numero1 , numero2

   //planteamos estructura del si

   SI numero1 > numero2 entonces
     escribir "numero1 es mayor a numero2"
   SINO
      SI numero1 == numero2 entonces
         escribir "numero1 es igual a numero2"
      SINO
         escribir "numero2 es mayor a numero1"
      FINSI
   FINSINO
**/

///Desarrolle un algoritmo que permita leer dos números desde el teclado
///y nos muestre por pantalla cuál de los dos es más grande.
int main()
{
    int numero1,numero2;

    printf("Ingrese un numero entero\n");
    scanf("%i",&numero1);
    printf("Ingrese otro numero entero\n");
    scanf("%i",&numero2);

    if (numero1 > numero2) ///si
    {
        printf("%i es mayor a %i",numero1,numero2);

    }
    else ///sino
    {
        if (numero1 == numero2)
        {

            printf("%i es igual a %i",numero1,numero2);

        }
        else
        {
            printf("%i es mayor a %i",numero2,numero1);
        }
    }

    printf("Sigo con mis lineas de codigo...\n");

    return 0;
}
