#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**

14. Determinar si la cantidad de elementos de la pila DADA es par.
Si es par, pasar el elemento del tope de la pila AUX a la pila PAR
y si es impar pasar el tope a la pila IMPAR ( no se puede contar los elementos)
**/

int main()
{
    Pila DADA;
    Pila PAR;
    Pila IMPAR;
    Pila AUX;
    char continuar;
    inicpila(&DADA);
    inicpila(&PAR);
    inicpila(&IMPAR);
    inicpila(&AUX);

    do
    {
        leer(&DADA);
        printf("Desea agregar otro valor? S/N \n");
        fflush(stdin);
        scanf("%c", &continuar);
    }
    while (continuar == 's' || continuar == 'S');

    while (!pilavacia(&DADA))
    {
        apilar(&AUX,desapilar(&DADA));
        if (!pilavacia(&DADA)) ///si no esta vacia dada (desapilo el par)
        {
            apilar(&AUX,desapilar(&DADA)); //desapile el par
        }
        else ///desapile uno solo (IMPAR)
        {
            apilar(&IMPAR,desapilar(&AUX));
        }
    }

    if (pilavacia(&IMPAR)) ///si la pila impar ESTA VACIA
    {
        apilar(&PAR,desapilar(&AUX));
    }

    printf("PILA PAR: \n");
    mostrar(&PAR);
    printf("PILA IMPAR: \n");
    mostrar(&IMPAR);




    return 0;
}
