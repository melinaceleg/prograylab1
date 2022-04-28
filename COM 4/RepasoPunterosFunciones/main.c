#include <stdio.h>
#include <stdlib.h>




void cargaPila(Pila* h) /// h = 0x55
{
    do
    {
        leer(h);

    }while (continuar...);
}
///copiar los datos de una pila a un arreglo
void copiarPilaaArreglo(Pila h, int arreglo[], int* validos)
{
    int i=0;
    while (!pilavacia(&h))
    {
        arreglo[i] = desapilar(&h);
        i++;
    }
    *validos = i; ///cantidad de datos cargados
}

///pasar los datos de una pila (vaciar) hacia el arreglo
void pasarPilaaArreglo(Pila* h, int arreglo[], int* v)
{
    int i = 0;
    while (!pilavacia(h))
    {
        arreglo[i] = desapilar(h);
        i++;
    }

    *v = i;

}


int main()
{
    Pila p; /// &p = 0x55
    int arreglo[20];
    int validos;
    inicPila(&p);
    cargaPila(&p);
    copiarPilaaArreglo(p,arreglo,&validos);
    pasarPilaaArreglo(&p,arreglo,&validos);

    return 0;
}
