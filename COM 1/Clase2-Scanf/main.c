#include <stdio.h>
#include <stdlib.h>

int main()
{
//  int var1, var2;
//  float resultado;
//
//  printf("Ingrese un valor entero\n"); ///mostrar "Ingrese un valor"
//  scanf("%i", &var1);  ///leer var1  /// el & (ampersand) es el operador direccion
//
//  printf("Ingrese otro valor entero\n"); ///mostrar "Ingrese un valor"
//  scanf("%i", &var2);  ///leer var2
//
//  resultado = (float)var1 / var2;
//
//  printf("El resultado es %f", resultado);

///pseint tipo de dato logico --> C NO EXISTE
int var1,var2;
int resultado;

var1 = 3; ///asignacion directa
var2 = 4;

/// > mayor < menor != distinto == igual
///cualquier valor distinto de 0 lo toma como verdadero, de lo contrario es falso
//resultado = !var1;

/// OR ||  AND &&  ! NOT
resultado = var1 > 3 && var2 > 2;

printf("%i", resultado);






//  int var;
//
//  printf("Ingrese un valor\n");
//  scanf("%i", &var);
//  printf("%c", (char)var);





  return 0;
}
