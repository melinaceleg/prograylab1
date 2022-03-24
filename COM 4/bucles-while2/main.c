#include <stdio.h>
#include <stdlib.h>

///Desarrolle un algoritmo que permita visualizar el cuadrado de los números entre 80 y 100.
///cuadrado : un numero multiplicado por si mismo 2 veces ( numero * numero)
/**
    definir numero como entero
    definir i como entero ///contador
    i=80
    mientras i<=100 hacer
      numero = i*i
      mostrar numero
      i=i+1
    finmientras
**/

int main()
{
    int numero;
    int i; ///contador
    i=80; ///inicializamos el contador
    while (i<=100)
    {
        numero = i*i; ///funcion que permite calcular la potencia de un numero -->numero=pow(i,7);  pow(NumeroEntero,exponente)
        printf("%i ",numero);
        i++;
    }

    return 0;
}
