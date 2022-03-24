#include <stdio.h>
#include <stdlib.h>
#include "pila.h" ///incluyo la libreria de pila
int main()
{
    Pila p; ///declare una variable de tipo Pila
    int valor;
    inicpila(&p); ///inicializarla , me deja la pila en 0 lista para agregar valores SIEMPRE SE DEBE HACER
    apilar(&p,5); //agrego un valor al tope de la pila
    apilar(&p,4);
    apilar(&p,2);
    apilar(&p,1);

    ///ver el tope
    valor = tope(&p); ///me va a devolver lo que hay en el tope, pero no lo quita
    printf("el tope es : %i\n", valor);

    while (!pilavacia(&p)) /// si no esta vacia la pila p
    {
        valor = desapilar(&p); ///le quito un valor
        printf("%i ",valor);
    }

//    printf("Ingrese un valor entero: ");
//    scanf("%i",&valor);
//    apilar(&p,valor);

    leer(&p); ///el usuario ingresa el valor, toma ese valor y lo apila en la pila p

  // printf("\n%i", tope(&p));// NO SE PUEDE PORQUE YA ESTA VACIA , MOSTRARA UN DATO INVALIDO


    return 0;
}
