#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**14. Determinar si la cantidad de elementos de la pila DADA es par.
Si es par, pasar el elemento del tope de la pila AUX a la pila PAR y si es impar pasar el tope a la pila IMPAR. **/
////necesariamente la pila debe tener al menos un valor


int main()
{
    Pila DADA;
    Pila AUX;
    Pila PAR;
    Pila IMPAR;
    inicpila(&DADA);
    inicpila(&AUX);
    inicpila(&PAR);
    inicpila(&IMPAR);

    apilar(&DADA,1);
    apilar(&DADA,2);
    apilar(&DADA,3);
    apilar(&DADA,5);

    while (!pilavacia(&DADA))
    {
        apilar(&AUX,desapilar(&DADA));
        if (!pilavacia(&DADA))
        {
            apilar(&AUX,desapilar(&DADA));
        }
        else ///si no puedo sacar el 2do elemento significa que es impar
        {
            apilar(&IMPAR,desapilar(&AUX));
        }
    }

    if (pilavacia(&IMPAR))
    {
        apilar(&PAR,desapilar(&AUX));
    }
    printf("IMPAR:\n");
    mostrar(&IMPAR);
    printf("PAR:\n");
    mostrar(&PAR);



    return 0;
}
