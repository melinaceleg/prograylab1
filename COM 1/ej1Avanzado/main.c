#include <stdio.h>
#include <stdlib.h>

/**
Sumar los elementos de una pila (usar variables enteras)
**/

///ambito global

int main()
{
///ambito main
    Pila p;
    Pila aux;
    inicpila(&p);
    inicpila(&aux);

    int suma =0; ///acumulador
    int i = 0; ///contador
    ..\

    ///conservo p

    ///caso acumular
    while (!pilavacia(&p))
    {
        suma = suma + tope(&p); ///suma += tope(&p);
        apilar(&aux,desapilar(&p));
    }
    while (!pilavacia(&aux))
    {
        apilar(&p,desapilar(&aux))
    }

    ///contar elementos de p conservando la pila
    while (!pilavacia(&p))
    {
        apilar(&aux,desapilar(&p));
        i++;
    }
    while (!pilavacia(&aux))
    {
        apilar(&p,desapilar(&aux))
    }


    /// no conservo p

    ///caso acumular
    while (!pilavacia(&p))
    {
        suma = suma + desapilar(&p);
    }
    ///caso contar
    while (!pilavacia(&p))
    {
        basura = desapilar(&p);
        i++;
    }



    ///caso contar y sumar (para sacar promedio)
    ///conservando p
    int i = 0;
    int suma = 0;
    float promedio;
    while (!pilavacia(&p))
    {
        i++;
        suma = suma + tope(&p);
        apilar(&aux,desapilar(&p));
    }
    while (!pilavacia(&aux))
    {
        apilar(&p,desapilar(&aux))
    }
    if (i != 0)
        promedio = (float)suma / i;
    else
        promedio = 0;



    return 0;
}
