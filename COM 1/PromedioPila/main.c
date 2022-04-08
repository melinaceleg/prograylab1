#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
///calcular el promedio de una pila mediante modularizacion
///ambito global
///prototipado
int suma(Pila); ///Realiza la suma de los elementos de una pila
int contador(Pila); ///Realiza el conteo de los elementos de una pila
float promedio(Pila); /// Realiza el promedio de los elementos de una pila

//&dada = 0x4445667
//dada = base 4 3 5 6 tope

float promedio(Pila dada)
{
    int cantidad;
    int sum;
    float res;
    cantidad = contador(dada);
    sum = suma(dada);
    if (cantidad >0 )
        res = (float)sum/cantidad; /// res = (float)contador(dada)/suma(dada);
    else
        res=0;
    return res; ///return (float)contador(dada)/suma(dada);
}

//void ej1() ///funcion sin retorno y sin argumentos
//{
//
//}

//int ejemplo() ///funcion con retorno y sin argumentos de entrada
//{
//   return v
//}

//void ejemplo(arg1,arg2) ///funcion sin retorno pero con argumentos de entrada
//{
//
//}

int contador(Pila dada)
{
    int i = 0; ///contador
    int basura;
    while (!pilavacia(&dada))
    {
        i++;
        basura=desapilar(&dada);
    }

    return i;
}


int suma(Pila dada) /// dada = p dada es una copia de p
{
    int sum=0; ///acumulador
    while (!pilavacia(&dada))
    {
        sum = sum + desapilar(&dada);
    }

    return sum;
}



int main()
{
///ambito main
    Pila p;
    Pila h;
    float promp;
    float promh;
    inicpila(&p);
    inicpila(&h);
    apilar(&p,3);
    apilar(&p,2);
    apilar(&p,1);
    apilar(&p,5);

    apilar(&h, 3);
    apilar(&h, 2);
    apilar(&h, 9);

    promp=promedio(p);
    promh=promedio(h);
    printf("El promedio de p es %.2f y el de h es: %.2f", promp, promh); ///printf("El promedio es %.2f", promedio(p));



    return 0;
}
