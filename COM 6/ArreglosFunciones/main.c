#include <stdio.h>
#include <stdlib.h>
#define CANT_MAX 20

///prototipado
void cargaArreglo(int[],int*); ///recibo el arreglo por referencia y los validos por referencia
void muestraArreglo(int[],int); ///recibo el arreglo por referencia y los validos

///implementacion

void muestraArreglo(int arreglo[], int validos) /// arreglo = 0x10, validos = 4
{
    //mostrar el arreglo
    for (int j = 0; j < validos ; j++)
    {
        printf("arreglo[%i]: %i ", j, arreglo[j]);
    }

}


void cargaArreglo(int arreglo[], int* validos) /// arreglo = 0x10 , validos = 0x55
{
    int i=0; ///contador - iterador
    do
    {
        printf("Ingrese un valor para la celda %i\n", i);
        scanf("%i" &arreglo[i]); ///scanf("%i", arreglo+i);
        printf("Desea continuar?\n");
        fflush(stdin);
        scanf("%c", &continuar);
        i++; ///incremento
    }
    while((continuar == 's' || continuar == 'S') && i < CANT_MAX);

    *validos = i; /// 4 datos --> ultima celda valida: 3
}


//int validos; /// la puedo modificar o ver su valor (NO SE CREAN VARIABLES GLOBALES!!)

///FUNCION busqueda de un dato -> retornar el indice en el que se encuentra, si no lo encuentra retornar -1




int main()
{
    int arreglo[CANT_MAX]; ///arreglo = 0x10; // int *arreglo = 0x10
    char continuar;
    int validos;

    cargaArreglo(arreglo,&validos);
    muestraArreglo(arreglo,validos);

    printf("\nLa cantidad de datos cargados es %i", validos);

//    arreglo[validos] = 9; ///arreglo[4] = 9;
//    validos++;

 /// arreglo[j] === *(arreglo+j)
    ///busqueda de un dato en el arreglo
    int valor;
    int j =0; //contador - recorre el arreglo desde la celda 0
    printf("Ingrese valor a buscar\n");
    scanf("%i", &valor);
    while(j < validos && arreglo[j] != valor)
    {
        j++; ///avanzo a la siguiente celda
    }

    if (j < validos)
    {
        printf("Se encontro el dato, esta en la celda %i \n", j);
    }
    else
        printf("No lo encontro");



    return 0;
}
