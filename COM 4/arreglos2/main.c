#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 20

int main()
{
   int arreglo[TAM_MAX]; ///0..1.2.3.4.5..6.7.....19
   ///arreglo = 0x10
   char continuar;
   int i = 0; ///contadora, inicializada en 0
   int validos; ///variable que uso para saber cuantos datos cargue
   ////primera carga del arreglo

   do
   {
      printf("Ingrese un valor\n");
      scanf("%i", arreglo+i); ///scanf("%i", &arreglo[i]);
      printf("Desea continuar?\n");
      fflush(stdin);
      scanf("%c", &continuar);
      i++;

   }while((continuar == 's' || continuar == 'S') && i < TAM_MAX );

   validos = i; ///cantidad de datos que yo cargue


   for (int j = 0 ; j < validos; j++ )
   {
       printf("%i ", arreglo[j]); /// printf("[%i]", *(arreglo+i));
   }

    return 0;
}
