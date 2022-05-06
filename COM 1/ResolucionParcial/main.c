#include <stdio.h>
#include <stdlib.h>

///Hacer una función que inserte los datos de cada persona ordenados por ‘dni’ de menor a mayor.
////podian hacer un algoritmo de carga normal o los datos ya podian llegar por parametro


void insertarOrdenado(int dnis[],float sueldos[],int antiguedades[],char generos[],int validos, int dni, int antiguedad, float sueldo, char genero)
{
    int i = validos - 1;
    while (i>=0 && dnis[i] > dni )
    {
        dnis[i+1] = dnis[i];
        sueldos[i+1] = sueldos[i];
        antiguedades[i+1] = antiguedades[i];
        generos[i+1] = generos[i];
        i--;
    }
    dnis[i+1] = dni;
    sueldos[i+1] = sueldo;
    antiguedades[i+1] = antiguedad;
    generos[i+1] = genero;
}


void insertarPersonas(int dnis[],float sueldos[],int antiguedades[],char generos[], int* validos)
{
    char continuar;
    int dni;
    float sueldo;
    int antiguedad;
    char genero;
    do
    {

        printf("Ingrese dni: ");
        scanf("%i", &dni);
        printf("Ingrese sueldo: ");
        scanf("%f", &sueldo);
        printf("Ingrese antiguedad: ");
        scanf("%i", &antiguedad);
        printf("Ingrese genero: ");
        scanf("%c", &genero);
        insertarOrdenado(dnis,sueldos,antiguedades,generos,*validos);
        (*validos)++;
        printf("Desea ingresar otra persona?");
        fflush(stdin);
        scanf("%c",&continuar);
    }
    while(continuar=='s');

}

///Hacer una función que pase a una pila ‘dnisMujeres’’ los dnis de las mujeres’.
void pasarDnis(int dnis[], char generos[],Pila* dnisMujeres, int validos)
{
    for (int i = 0 ; i< validos ; i++)
    {
        if (generos[i] == 'f')
        {
            apilar(dnisMujeres,dnis[i]);
        }
    }

}

///Hacer una función que informe el sueldo promedio de los hombres.
void mostrarPromedioHombres(float sueldo[], char genero[], int validos)
{
    float suma =0;
    int cantidad=0;
    for (int i = 0 ; i < validos ; i++)
    {
        if (genero[i] == 'm')
        {
            suma = suma + sueldo[i];
            cantidad++;
        }
    }
    if (cantidad > 0)
        printf("El promedio de sueldo de los hombres es de %.2f\n", suma/cantidad);

}

///Realizar una función que busque un dni recibido por parámetro, se debe retornar el índice, puede no existir.
//En esta funcion hay que tener cuenta que los datos de las personas estan ORDENADOS POR DNI, por lo tanto es una busqueda en un arreglo ordenado
int busquedaxDni(int dnis[], int validos, int dni)
{
    int i=0;
    int indice = -1; //por defecto uno invalido
    while (i < validos && dnis[i] < dni)
    {
        i++;
    }
    if ( i < validos && dnis[i] == dni)
    {
        indice = i;
    }
    return indice;
}

///Realizar una función que reciba la pila de ‘dnisMujeres’ e informe en detalle cada dni que posee la pila (dni,sueldo,antigüedad)
/// que cumpla con el requisito de poseer una antigüedad menor a una recibida por parámetro.
void informarDniXAntiguedad(Pila dnisMujeres, int dnis[], float sueldo[], int antiguedad[], int validos, int antiguedad)
{
    int indice;
    while (!pilavacia(&dnisMujeres))
    {
        indice = busquedaxDni(dnis,validos,desapilar(&dnisMujeres));
        if (antiguedad[indice] < antiguedad)
        {
            printf("DNI: %i\n", dni);
            printf("SUELDO: %.2f\n", sueldo[indice]);
            printf("ANTIGUEDAD: %i\n\n", antiguedad[indice]);
        }
    }

}

int main()
{
    int dnis[CANT_MAX];
    float sueldo[CANT_MAX];
    int antiguedad[CANT_MAX];
    char genero[CANT_MAX];  /// ‘m’ hombre , ‘f’ mujer
    Pila dnisMujeres;
    int indice;
    inicpila(&dnisMujeres);
    int validos = 0 ;
    insertarPersonas(dnis,sueldo,antiguedad,genero,&validos);
    pasarDnis(dnis,genero,&dnisMujeres,validos);
    mostrarPromedioHombres(sueldo,genero,validos);
    indice = busquedaxDni(dnis,validos,2718394);
    informarDniXAntiguedad(dnisMujeres,dnis,sueldo,antiguedad,validos,5);

    return 0;
}
