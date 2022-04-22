#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 10
///prototipado
void cargaArreglo(int[], int*); ///recibo el arreglo y los validos para modificar
void muestraArreglo(int[],int); ///recorre y muestra celda por celda

void muestraArreglo(int arreglo[], int validos)
{
    ///muestra del arreglo
    for (int j = 0; j < validos ; j++)
    {
        printf(" %i ", arreglo[j]); ///printf("%i", *(arreglo+j));
    }

}

void cargaArreglo(int arreglo[], int* validos) /// arreglo = 0x10
{
    char continuar;
    int i=0; ///contador - iterador
    do
    {
        printf("Ingrese un valor\n");
        scanf("%i", &arreglo[i]); ///scanf("%i", arreglo+i);
        printf("desea continuar\n");
        fflush(stdin);
        scanf("%c", &continuar);
        i++; ///avanza hacia la siguiente celda

    }
    while((continuar == 's' || continuar == 's') && i < TAM_MAX);

    *validos = i; ///cantidad de datos cargados

}

///hacer una funcion que reciba por parametro el arreglo, el elemento a buscar y los validos, y lo busque en el arreglo, y retorne el indice si lo encontro,
///de lo contrario que retorne -1.


int main()
{
    int arreglo[TAM_MAX]; /// arreglo= 0x10;
    int validos;

    cargaArreglo(arreglo,&validos);
    muestraArreglo(arreglo,validos);


    ///buscar un elemento en el arreglo
    int valor;
    printf("Ingrese valor a buscar\n");
    scanf("%i",&valor);
    int j=0;
//    arreglo  2  3  5  7 ghjghj
//    valor = 8
//    validos = 4

    while (j < validos && arreglo[j] != valor)
    {
        j++;
    }
    if (j == validos )
    {
        printf("El elemento no se encuentra en el arreglo\n");
    }
    else
        printf("El elemento esta posicionado en el indice %i", j);






    return 0;
}
