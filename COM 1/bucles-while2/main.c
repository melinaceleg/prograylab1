#include <stdio.h>
#include <stdlib.h>

///Desarrolle un algoritmo que permita visualizar el cuadrado de los números entre 80 y 100.
/// potencia N de un numero, un numero multiplicado por si mismo N veces
int main()
{
    int numero;
    int cuadrado;
    numero = 80;
    while (numero <= 100)
    {
        cuadrado = numero*numero;
        printf("numero: %i, cuadrado: %i \n",numero, cuadrado);
        numero++; ///numero = numero + 1

    }

    return 0;
}
