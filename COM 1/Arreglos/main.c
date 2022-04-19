#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 4

int main()
{
// int var1,var2,var3;
// char caracter;
// float numeroReal;
// long int enteroLargo;
// ....
 ///coleccion de datos
// Pila p; ///coleccion de datos -> coleccion de enteros -> hasta 50 enteros -> comportamiento LIFO

 /**
    Arreglo:
     -> coleccion de datos
     -> coleccion de cualquier tipo de dato (datos de tipo de entero, char, float...)
     -> puede almacenar una cantidad determinada de datos que va a estar dada en la declaracion
     -> el acceso a cada uno de esos datos es de manera directa
     -> es un puntero por definicion
 **/

 ///declaracion arreglo:

 int arreglo[TAM_MAX]; ///espacio de memoria con la capacidad de almacenar 10 enteros, partido en 10 enteros
///arreglo = 0x10
 arreglo[0] = 2;
 arreglo[1] = 3;
 arreglo[2] = 5;
 arreglo[3] = 6;

 printf("%i\n", sizeof(arreglo)/sizeof(int)); ///para saber el tamano del arreglo

 printf("%i\t", arreglo[0]);
 printf("%i\t", *(arreglo+1)); /// *(dir. inicial + despl.)
 printf("%i\t", *(arreglo+2));
 printf("%i ", *(arreglo+3));
 printf("\n");
 printf("%x ", arreglo);
 printf("%x ", arreglo+1);
 printf("%x ", arreglo+2);
 printf("%x", arreglo+3);




    return 0;
}
