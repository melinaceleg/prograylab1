#include <stdio.h>
#include <stdlib.h>

#define CANT_CALIFICACIONES 6 /// existe de manera global
#define PI 3.14

/**
CONSTANTES
-> es un valor que no puede alterarse en tiempo de ejecucion
-> convencion: se utiliza mayusculas en su nombre
-> se declaran luego de las librerias y por encima de cualquier funcion (main)
#define NOMBRE VALOR
#define PI 3.14
#define OPERACION 3+4*7

otra forma:
const int valor = 7;
const float dato = 7.25;
const float raiz = sqrt(7);

Calcular el promedio de un alumno que
tiene 7 calificaciones en la materia de Formalización de Algoritmos y la nota mas baja.
**/

int main()
{
//   const int valorConstante = 8; /// existe en el ambito del main
//   printf("%i\n", valorConstante);
//   printf("%.2f", PI);

/** Ejemplo de uso de esta forma:
el usuario debe ingresar numeros enteros y debo calcular el mas pequeno de ellos
**/
    float nota;
    float promedio;
    float suma=0;  ///acumulador
    float notaMasBaja; ///nota invalida : 11

    for (int i = 1; i<= CANT_CALIFICACIONES; i++)
    {
        printf("Ingrese una nota\n");
        scanf("%f", &nota);
        if (i == 1) ///la puedo usar cuando no existe valor invalido a ingresar
        {
            notaMasBaja = nota;
        }
        else if (nota < notaMasBaja )
        {
            notaMasBaja = nota;
        }

        suma = suma + nota;
    }
    promedio = suma / CANT_CALIFICACIONES ;
    printf("El promedio es : %.2f ", promedio);



    ///OTRA FORMA

    float nota;
    float promedio;
    float suma=0;  ///acumulador
    float notaMasBaja=11; ///las notas van del 1 al 10

    for (int i = 1; i<= CANT_CALIFICACIONES; i++)
    {
        printf("Ingrese una nota\n");
        scanf("%f", &nota);
        if (nota < notaMasBaja )
        {
            notaMasBaja = nota;
        }

        suma = suma + nota;
    }
    promedio = suma / CANT_CALIFICACIONES ;
    printf("El promedio es : %.2f ", promedio);



    return 0;
}
