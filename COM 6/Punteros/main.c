#include <stdio.h>
#include <stdlib.h>

/**
  & -> operador direccion (direccion de memoria)
  * -> operador indireccion
**/

///prototipado
void modificarValor(int*);
void intercambioValores(int*,int*);
void cargaNumeros(int*,int*);

void modificarValor(int* x) /// x = 0x55
{

    *x = 10;


}

/**
Realizar una función que reciba dos números enteros por parámetro por referencia y
cargue sus valores el usuario dentro de la función.
**/

void cargaNumeros(int* x, int* y) ///  x = 0x55,  y= 0x40
{
  printf("Ingrese el valor para a: ");
  scanf("%i", x);
  printf("Ingresar el valor para b: ");
  scanf("%i", y);

}

void intercambioValores(int* x, int* y) ///  x = 0x15 , y= 0x20
{
  int aux;
  aux = *x; ///aux = 3
  *x = *y;  /// a = 8 ///al contenido de la dir que hay en x le asigno el contenido de lo que hay en la dir y
  *y = aux; /// b = 3 ///al contenido de la dir que hay en y le asigno aux
}


int main()
{
  int a; /// &a 0x15
  int b; /// &b 0x20

 // cargaNumeros(&a,&b);




  int* c; ///puntero -> almacena una direccion de memoria de una variable entera
  a = 3;
  b = 8;

  printf("a: %i, b: %i\n",a,b);

   intercambioValores(&a,&b); ///pasaje por referencia
  printf("a: %i, b: %i\n",a,b);

  ///b = 3 , a = 8


  //modificarValor(&b);/// modificarValor(0x55);
  //printf("b: %i", b);



// c = &b; /// c = 0x55
//  printf("b antes: %i\n", b);
// *c = 5;
//  printf("a: %i\n", a);
//  printf("b: %i\n", b);
//  printf("direccion de b: %x\n", &b);
//  printf("c: %x\n", c);
// printf("*c: %i\n", *c)





    return 0;
}
