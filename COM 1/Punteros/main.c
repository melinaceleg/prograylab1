#include <stdio.h>
#include <stdlib.h>

///prototipados

void cambiarSigno(int*);
void cargaValores(int*, int*); /**Realizar una función que reciba dos números enteros por parámetro por referencia
y cargue sus valores el usuario dentro de la función**/

/**
& --> operador direccion (direccion de memoria)
* --> operador indireccion

int* var1; -->variable que almacena la direccion de una variable entera
  puntero

**/








//int main()
//{
//   int a;
//   int b;
//   int* c; ///puntero a entero
//   a = 3;
//   b = a;
//   c = &a; ///c = 0x45 se almacena la direccion de a /// c esta apuntando a 'a'
//   *c = 1; /// se mete adentro de la direccion que almacena 'c' y la modifica
//   ///al contenido de la direccion que esta almacenando c, cambialo por un 1
//   printf("Direccion de a: %x\n", &a);
//   printf("Direccion que almacena c: %x\n", c);
//   printf("El valor de a es %i\n", *c);
//   printf("El valor de b es %i\n", b);
//
//
//
//    return 0;
//}

void modificarValor(int* c) // c = 0x45
{
  *c = 8;
}

///intercambiar los valores de 2 variables por referencia
void intercambioValores(int* a, int* b)
{
    int aux;
    aux = *a;
    *a=*b;
    *b = aux;

}





// &a 0x45
int main()
{
//    int a;
//    a = 3;
//    printf("%i\n",a);
//    modificarValor(&a); ///modificarValor(0x45)
//    printf("%i",a);

    int h;
    int k;
    int aux;
    h = 8;
    k = 9;
    printf("h: %i, k: %i\n", h,k);
    intercambioValores(&h,&k);
    printf("Despues de intercambiar: h: %i, k: %i\n", h,k);

    cambiarSigno(&h);
    printf("h cambiada de signo: %i\n", h);

    cargaValores(&h,&k); //// cargaValores(0x43,0x48);
    printf("h: %i, k: %i\n", h,k);

    return 0;
}



///Realizar una función que reciba un número positivo entero por parámetro por referencia,
/// y cambie su signo a negativo.


void cambiarSigno(int* numero)
{
   *numero = (*numero) * (-1);

}




void cargaValores(int* num1, int* num2) ///num1 = 0x43  num2 = 0x48
{
    printf("Ingrese un valor para el numero 1: ");
    scanf("%i", num1);
    printf("Ingrese un valor para numero 2: ");
    scanf("%i", num2);
}

