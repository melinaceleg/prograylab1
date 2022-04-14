#include <stdio.h>
#include <stdlib.h>

/**
  & --> direccion (direccion de memoria)
  * --> operador indirecccion

  puntero -> son variables que almacenan direcciones de memoria
  ->con un puntero podemos modificar el contenido de una direccion de memoria, es decir,
  modificar el valor de una variable de manera remota.
**/

///funcion que modifica el valor de una variable remota
void modificaValor(int* var1) /// var1 = 0x60
{
   *var1 = 8;

}

///funcion que intercambia dos valores por valor

void intercambio(int* v1, int* v2) /// v1 = 0x50   v2 = 0x60
{
    int aux;
    aux = *v1; /// aux = 7
    *v1=*v2; /// a = 10
    *v2=aux;  /// b = 7

}


int main()
{
   int a; /// &a = 0x50
   int b;  /// &b = 0x60
   a = 7;
   b = 10;

   intercambio(&a,&b);
   printf("a: %i, b: %i",a,b);




//   modificaValor(&a);
//
//   printf("valor de a: %i", a);
//


//   int* c; ///puntero a entero
//   a=2;
//   b=a;
//   c = &b; // c = 0x50
//   *c = 5; /// b = 5

  // printf("a: %i\n", a);
//   printf("direccion de b: %x\n", &b);
//   printf("c: %x\n", c);
//   printf("*c: %i\n", *c); /// *c: contenido de la direccion que almacena c




    return 0;
}
