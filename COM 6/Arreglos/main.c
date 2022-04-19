#include <stdio.h>
#include <stdlib.h>




int main()
{
//  int var1,var2,var3;
//  char caracter;
//  float numeroReal;
//  long int numeroLargo;
//  .......
//  Pila p;
  /**
    Coleccion de datos -> coleccion de enteros -> hasta 50 enteros -> comportamiento LIFO
   **/

   /**
    ARREGLO
    -> coleccion de datos
    -> coleccion de enteros, o de caracteres, o de flotantes, o enteros largos...
    -> limite en cantidad de datos va a estar dictado en la declaracion del arreglo
    -> acceso directo a cada dato
    -> es un puntero por definicion
    **/

    int arreglo[4]; /// arreglo = 0x10
    *(arreglo+0) = 3;
    *(arreglo+1) = 5;
    *(arreglo+2) = 8;
    *(arreglo+3) = 9;



//    printf("%i\t",*arreglo);
//    printf("%i\t",*(arreglo+1));
//    printf("%i\t",*(arreglo+2));
//    printf("%i\n",*(arreglo+3));

    printf("%i", arreglo[0]);
    printf("%i", arreglo[1]);
    printf("%i", arreglo[2]);
    printf("%i", arreglo[3]);



    printf("%x ", arreglo);
    printf("%x ", arreglo+1);
    printf("%x ", arreglo+2);
    printf("%x", arreglo+3);

    return 0;
}
