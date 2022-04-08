#include <stdio.h>
#include <stdlib.h>
///prototipado
float suma(float,float); ///esta funcion es de suma de dos valores
float promedio(float,int); ///calcula el promedio recibiendo la suma y diviendo entre N valores
///ambito global

//tipo_de_salida nombre_funcion(parametros de entrada)
//{
//    ///ambito de mi subprograma o funcion
//    ///codigo...
//
//    retorno
//}




int main()
{
///ambito main
  float a;
  float b;
  float res;
  float sum;
  a=3;
  b=7.2;

  sum = suma(a,b);
  res=promedio(sum,2);
  printf("El promedio es %.2f", res);

return 0;
}

float promedio(float suma, int cantidad)
{
   float res = suma / cantidad;
   return res;
}


float suma(float a, float b) ///cabecera de la funcion  a = 3, b = 4
{
///ambito de la funcion suma
  float resultado; ///local a la funcion

  resultado = a + b;

   return resultado; //// return 7
}



