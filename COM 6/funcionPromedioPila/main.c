#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
///Hacer una funcion que calcule el promedio de los elementos de una pila y lo retorne, mostrar en el main. Modularizar

///prototipado
int sumaPila(Pila); ///suma los elementos de una pila y lo retorna
int cuentaPila(Pila); ///cuenta los elementos de una pila y lo retorna
float promedioPila(Pila); ///calcula el promedio de una pila y lo retorna


int sumaPila(Pila p) /// p = base 1 5 3 8 tope /// p = fotocopia de k
{
    int suma = 0; ///acumulador
    while(!pilavacia(&p))
    {
        suma = suma + desapilar(&p);
    }

    return suma;
}

int cuentaPila(Pila h) /// h es una fotocopia de k
{
    int i = 0; ///contador
    int basura;
    while(!pilavacia(&h))
    {
        i++;
        basura=desapilar(&h);
    }

     return i;
}

float promedioPila(Pila k) { /// k es parametro formal

  int suma;
  int cuenta;
  float prom=0;
  suma = sumaPila(k);
  cuenta = cuentaPila(k);
  if (cuenta > 0)
  {
    prom = (float)suma/cuenta;
  }

  return prom;
}


int main()
{
    ///ambito del main
    Pila A;
    Pila B;
    float prom;
    inicpila(&A);
    inicpila(&B);
    apilar(&A,1);
    apilar(&A,5);
    apilar(&A,3);
    apilar(&A,8);

    apilar(&B,1);
    apilar(&B,2);
    apilar(&B,5);
    apilar(&B,3);
//    prom=promedioPila(A); /// A es parametro actual
//    printf("El promedio de A es %.2f", prom);
//    prom = promedioPila(B);
//    printf("El promedio de B es %.2f", prom);

    printf("El promedio de A es %.2f y el de B es %.2f", promedioPila(A), promedioPila(B));
    return 0;
}
