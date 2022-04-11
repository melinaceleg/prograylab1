#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
///prototipado
int sumaPila(Pila); /// sumar los elementos de una pila
int cuentaPila(Pila); ///cuenta los elementos de una pila
float promedio(Pila); ///calcula el promedio

float promedio(Pila p)
{

    float prom=0;
    int sum;
    int i;
    sum = sumaPila(p);
    i = cuentaPila(p);
    if (i>0)
        prom = (float)sumaPila(p)/cuentaPila(p);

    return prom;
}


int sumaPila(Pila j) /// j base 3 4 5 6 tope
{

    int suma=0; ///acumulador

    while (!pilavacia(&j))
    {
        suma = suma + desapilar(&j);
    }


   return suma;
}

int cuentaPila(Pila p)
{
    int i = 0; ///contador
    int basura;
    while (!pilavacia(&p))
    {
        basura = desapilar(&p);
        i++;
    }
    return i;
}



///hacer una funcion que calcule el promedio de valores de una pila
/// y lo retorne (modularizar)
///modulo suma
/// modulo cuenta
///modulo promedio (suma/cuenta)

///las funciones pueden generar una salida o no
///pueden tener parametros de entrada o no
/**

void func1(int,int);
int  func1();
void func1();

**/



int main()
{
    Pila h;
    Pila dada;
    float prom;
    inicpila(&h);
    inicpila(&dada);
    apilar(&h,3);
    apilar(&h,5);
    apilar(&h,7);

    apilar(&dada,1);
    apilar(&dada,2);
    apilar(&dada,5);
    prom= promedio(h); ///invocar o llamar a la funcion
    printf("El promedio es %.2f", prom); /// promedio(h);

    printf("El promedio de dada es: %.2f", promedio(dada));
    return 0;
}
