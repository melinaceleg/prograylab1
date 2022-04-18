#include <stdio.h>
#include <stdlib.h>

/**
Arreglo : ->Coleccion de datos (viene en el propio lenguaje)
          -> puede almacenar datos de cualquier tipo
          -> guarda la cantidad de datos que le fue declarada
          -> acceso directo -> no tiene comportamiento en particular
**/


int main()
{
//int var1;
//int var2;
//int var3;
//char caracter;
//float numeroReal;
//long int enteroLargo;
//...
//Pila P; ///colecciones de datos -> coleccion de enteros -> guarda hasta 50 enteros -> LIFO
//...

int var1,var2,var3;
var1=5;
int arreglo[3]; ///array-arreglo -> coleccion de datos que almacena hasta 3 enteros
int validos;
//printf("%x", arreglo); /// arreglo = 0x10
arreglo[0] = 3;
arreglo[1] = 1;
validos = 2;

for (int i = 0; i < validos; i++)
{
    printf("%i ", arreglo[i]);
}

arreglo[2] = 4;
validos++; // validos = 3




//printf("%i\t", arreglo[0]);
//printf("%i\t", arreglo[1]);
//printf("%i", *(arreglo+2));
//printf("\n0\t");
//printf("1\t");
//printf("2\n");
//printf("\n%x ", arreglo);
//printf("%x ", arreglo+1);
//printf("%x", arreglo+2);


///
*(arreglo+0) = 8; ///arreglo[0] = 8;
//printf("primer celda: %i", arreglo[0]);
*(arreglo+1) = 9;
*(arreglo+2) = 6;
///


    return 0;
}
