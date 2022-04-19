#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///prototipo
void cargaPila(Pila*); ///carga una pila por el usuario
void pasarElementos(Pila*,Pila*); //Hacer una función que pase todos los elementos de una pila a otra.
void copiarElementos(Pila,Pila*);//Hacer una función que copie todos los elementos de una pila a otra.
void sumarYdevolver2Primeros(Pila, int*, int*, int*);
int laPilatiene2elementos(Pila); // 1 si tiene 2 , contrario 0


///RETORNO A TRAVES DE LOS PARAMETROS ( SIRVE CUANDO DEBO DEVOLVER MAS DE UN VALOR)
/**
8. Hacer una función que sume y
retorne los dos primeros elementos de una pila (tope y anterior),
sin alterar su contenido.
**/
///implementacion
void sumarYdevolver2Primeros(Pila p, int* suma, int* primero, int* segundo) ///
/// p base 3 4 5 tope  , primero = 0x12 , segundo = 0x55
{
        *primero = desapilar(&p);
        *segundo = desapilar(&p);
        *suma = *primero + *segundo;
}

int laPilatiene2elementos(Pila p)
{
    int basura;
    int respuesta=0;
    if (!pilavacia(&p))
    {
        basura= desapilar(&p);
        if (!pilavacia(&p))
        {
            respuesta = 1;
        }
    }

    return respuesta;
}


int main()
{
    Pila A;
    Pila B;
    int suma;
    int primerElemento;
    int segundoElemento;
    inicpila(&A);
    inicpila(&B);
    cargaPila(&A); //cargaPila(0x55);
    mostrar(&A);
    if (laPilatiene2elementos(A))
    {
        sumarYdevolver2Primeros(A,&suma,&primerElemento,&segundoElemento);
        printf("%i", primerElemento);
        printf("%i", segundoElemento);
        printf("suma: %i", suma);

    }
//    cargaPila(&B);// cargaPila(0x38);
//    mostrar(&B);

    //pasarElementos(&A,&B);
//    copiarElementos(A,&B);
//    printf("B: ");
//    mostrar(&B);
//    printf("A: ");
//    mostrar(&A);


    return 0;
}

void cargaPila(Pila* p) /// p = 0x55
{
    char seguir;
    do
    {
        leer(p);
        printf("desea seguir s/n \n");
        fflush(stdin);
        scanf("%c", &seguir);

    }
    while(seguir == 's' || seguir == 'S');

}

void pasarElementos(Pila* p, Pila* h) /// p = 0x66, h = 0x70
{
    while (!pilavacia(p))
    {
        apilar(h,desapilar(p));
    }

}

void copiarElementos(Pila p,Pila* h) //p = base 3 7 8 4 tope    h = 0x55
{
    while (!pilavacia(&p))
    {
        apilar(h,desapilar(&p));
    }
}
