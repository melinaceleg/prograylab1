#include <stdio.h>
#include <stdlib.h>
//8. Hacer una función que sume
// y retorne los dos primeros elementos de una pila (tope y anterior),
//  sin alterar su contenido.



///trabajamos con el retorno a traves de los parametros (los recibo por referencia)
///cuando necesariamente debo retornar mas de un valor, hago todo a traves de los parametros.
void sumaYRetorno(Pila,int*,int*,int*); ///Pila, primerDato,SegunDato,suma
int verificarSiHay2Datos(Pila); ///verifica si hay 2 datos en la pila, retorna 1, de lo contrario 0

void sumaYRetorno(Pila p,int* primero,int* segundo,int* suma)
{
    *primero = desapilar(&p);
    *segundo = desapilar(&p);
    *suma = *primero + *segundo;

}

}

int verificarSiHay2Datos(Pila p )
{
    int basura;
    int respuesta=0;
    if (!pilavacia(&p))
    {
        basura = desapilar(&p);
        if (!pilavacia(&p))
        {
            respuesta=1;
        }
    }

    return respuesta;

}


int main()
{
    Pila dada;
    inicpila(&dada);
    int primerElemento;
    int segundoElemento;
    int suma;
    if (verificarSiHay2Datos(dada))
    {
        sumaYRetorno(dada,&primerElemento,&segundoElemento,&suma);
        printf("La suma es: %i, de %i con %i\n",suma,primerElemento,segundoElemento)
    }
    return 0;
}
