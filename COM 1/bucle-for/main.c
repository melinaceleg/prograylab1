#include <stdio.h>
#include <stdlib.h>

/**

   FOR-PARA

   PARA i = 1 HASTA N Con Paso 1 Hacer
    ..sentencias
    sentencias..
   FIN-PARA

   -> Nos inicializa la variable contadora
   -> tenemos la condicion de continuidad
   -> El contador incrementa/decrementa en un valor fijo

   En C:

   for (i = 1; i <= N ; i++) ///i inicializa en 1, la condicion de continuidad es i <= N, i incrementa de 1 en 1
   {
     .. sentencias
   }

   -> Sabemos cuantas veces se va a repetir el codigo

 Orden de los bucles:

   while:  CONDICION - SENTENCIAS- CONDICION - SENTENCIAS...
   do-while: SENTENCIAS - CONDICION - SENTENCIAS - CONDICION - SENTENCIAS..
   for: INICIALIZACION - CONDICION - SENTENCIAS - INCREMENTO/DECREMENTO - CONDICION - SENTENCIAS
        INCREMENTO/DECEMENTO - CONDICION - SENTENCIAS INCREMENTO/DECREMENTO - CONDICION - SENTENCIAS..
**/


/**Realizar un programa que imprima en pantalla los números del 1 al 100. **/

///ambito global

int main()
{
    ///ambito del main
//   int i;
//   i=1;
//   while (i<=100)
//   {
//       printf("%i ", i);
//       i++;
//   }
//   for: INICIALIZACION - CONDICION - SENTENCIAS - INCREMENTO/DECREMENTO - CONDICION - SENTENCIAS
//        INCREMENTO/DECEMENTO - CONDICION - SENTENCIAS INCREMENTO/DECREMENTO - CONDICION - SENTENCIAS..

    //int i;
     for (int i=1; i<=100 ; i++) /// i no existe fuera del ambito del for
     {
         int suma=0; ///solo existe en el ambito del for
         ///ambito del for
         printf("%i ", i);
     }

      for (int i = 100 ; i>= 1 ; i--) /// i=i-1
      {
          printf("%i ", i);
      }

    // printf("El ultimo valor es %i\n", i );

    return 0;
}
