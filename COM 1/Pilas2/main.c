#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "time.h"

#define CANT_CARTAS 39

/**

4) Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
Pasar los elementos de la pila ORIGEN a la pila DESTINO,
pero dejándolos en el mismo orden

TODAS LAS PILAS QUE CREAMOS DEBEN INICIALIZARSE!!
**/
int main()
{
    Pila ORIGEN;
    Pila DESTINO;
    Pila AUX;
    char continuar;
    inicpila(&ORIGEN);
    inicpila(&DESTINO);
    inicpila(&AUX);

    do
    {
        leer(&ORIGEN);
        printf("Desea ingresar otro valor?\n");
        fflush(stdin); //limpia el buffer de entrada (la manguerita del flujo de caracteres)
        scanf("%c",&continuar);
    }
    while(continuar == 's' || continuar =='S');

    printf("Pila origen: \n");
    mostrar(&ORIGEN);

    while (!pilavacia(&ORIGEN)) // 1 si esta vacia, de lo contrario 0,  pilavacia(&ORIGEN) == 0
    {
        apilar(&AUX,desapilar(&ORIGEN));
    }

    printf("Pila aux: \n");
    mostrar(&AUX);

    while (!pilavacia(&AUX))
    {
        apilar(&DESTINO, desapilar(&AUX));
    }
    printf("Pila Destino: \n");
    mostrar(&DESTINO);


    continuar = 's';
    while (continuar == 's' || continuar == 'S')
    {
        leer(&ORIGEN);
        printf("Desea ingresar otro valor?\n");
        fflush(stdin);
        scanf("%c",&continuar);
    }

    return 0 ;
}
/**

    5. Cargar desde el teclado la pila DADA. Invertir la pila de manera que
     DADA contenga los elementos cargados originalmente en ella, pero en orden inverso.
     **/
int main ()
{
    Pila DADA;
    Pila AUX1;
    Pila AUX2;
    char continuar;
    inicpila(&DADA);
    inicpila(&AUX1);
    inicpila(&AUX2);


    do
    {
        leer(&DADA);
        printf("Desea ingresar otro valor?\n");
        fflush(stdin); //limpia el buffer de entrada (la manguerita del flujo de caracteres)
        scanf("%c",&continuar);
    }
    while(continuar == 's' || continuar =='S');
    ///DADA : tope 5 4 3 2 BASE


    while (!pilavacia(&DADA))
    {
        apilar(&AUX1,desapilar(&DADA));
    }

    ///AUX1 :  tope 2 3 4 5 BASE

    while (!pilavacia(&AUX1))
    {
        apilar(&AUX2, desapilar(&AUX1));
    }

    ///AUX2: tope 5 4 3 2 BASE

    while (!pilavacia(&AUX2))
    {
        apilar(&DADA,desapilar(&AUX2));
    }

    ///DADA: tope 2 3 4 5 BASE

    return 0;
}


/**

8. Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa.
**/

int main()
{
    Pila MAZO;
    Pila JUGADOR1;
    Pila JUGADOR2;

    srand(time(NULL)); ///semilla : establecer que toma de valor inicial para resolver la formula que me da un valor random

    inicpila(&MAZO);
    inicpila(&JUGADOR1);
    inicpila(&JUGADOR2);

///cargo 40 cartas
    for (int i = 0; i < CANT_CARTAS ; i++)
    {
        apilar(&MAZO, (rand() % 12) + 1); ///la operacion resto me devuelve desde el 0 hasta N-1
    }

    while (!pilavacia(&MAZO))
    {
        apilar(&JUGADOR1,desapilar(&MAZO));
        if (!pilavacia(&MAZO))
        {
            apilar(&JUGADOR2,desapilar(&MAZO));

        }
    }

    return 0;
}


/**
9. Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado.
**/
int main()
{
    Pila A;
    Pila B;
    inicpila(&A);
    inicpila(&B);
    int v;
    ....
///se carga A
///Se carga B

    while (!pilavacia(&A) && !pilavacia(&B))
    {
        v= desapilar(&A);
        v= desapilar(&B);
    }

    if (pilavacia(&A) && !pilavacia(&B) ) // pilavacia(&A) && !pilavacia(&B) || pilavacia(&B) && !pilavacia(&A)
    {
        printf("La pilas no tienen la misma cantidad\n");
    }
    else if (pilavacia(&B) && !pilavacia(&A))
    {
        printf("Las pilas no tienen la misma cantidad\n");
    }
    else
    {
        printf("Las pilas tienen la misma cantidad de elementos\n");
    }


    return 0;
}


