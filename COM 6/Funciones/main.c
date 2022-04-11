#include <stdio.h>
#include <stdlib.h>
///ambito global
///funciones
///estructura:
/**

tipo_de_salida  nombre_funcion(parametros_de_Entrada)
{
 ///ambito de la funcion


  retorno
}

si tiene retorno -> tipo_de_salida:  char, float, int, long int, Pila,....
si no tiene retorno -> tipo_de_salida: void

puede tener N parametros, o ninguno.

**/

///prototipado
int sumaDe2Enteros(int, int); ///cabecera de la funcion -> suma 2 valores enteros y devuelve un entero
float promedio(int, int);
void ej1(); ///este ejercicio hace la resta de N valores..



////hacer una funcion que calcule el promedio entre 2 varialbes
float promedio(int a, int b) /// a = 3, b = 5
{
    float prom;
    prom = (float)sumaDe2Enteros(a,b) / 2;

    return prom;
}


///el objetivo de  este modulo es realizar la suma de 2 enteros y retornarla
int sumaDe2Enteros(int a, int b) /// a = 3, b = 5
{
    ///ambito de sumade2enteros
    int resultado; ///local a la funcion sumade2enteros

    resultado = a + b;

    return resultado; ///return a+b;

}

void ej1()
{
    ///
}



void decirHola()
{
    printf("HOLA");
}




int main()
{
  ///ambito del main

  int var1,var2;
  float result;
  var1= 3;
  var2 = 5;
  //result=sumaDe2Enteros(var1,var2); ///sumaDe2Enteros(3,5); ///invocacion, llamada
 //printf("El resultado de la suma es %i", result);
 //decirHola();
  result = promedio(var1,var2); ////promedio(3,5);
  printf("El promedio es %.2f", result);

    return 7;
}





