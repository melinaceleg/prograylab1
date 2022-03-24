#include <stdio.h>
#include <stdlib.h>

////  \n -> salto de linea
//// \t -> tabulacion
////  & (ampersand) -> direccion de memoria ///ubicacion
int main()
{

//OPERADORES ARITMETICOS
 int numerito1,numerito2;
// float resultado; ///tipo de dato con coma, decimal (Real)
// printf("Ingrese un valor entero: ");  /// escribir "ingrese un valor"
// scanf("%i", &numerito1);  ///leer numerito1
//
// printf("Ingrese otro valor entero: ");  /// escribir "ingrese un valor"
// scanf("%i", &numerito2);  ///leer numerito2
//
// resultado = (float)numerito1/numerito2; ///casting: hacer que una variable se comporte como otro tipo de dato asociado

// printf("El resultado es: %.1f", resultado);

//int resultado;
//numerito1 = 4;
//resultado = numerito1 % 2;  ///operador MODULO, nos devuelve el resto de la division
//printf("%i", resultado);


int var1;
//var1= var1 + 1;
var1=0; ///contador
var1--; /// var1 = var1 - 1;
printf("%i",var1);




////OPERADORES LOGICOS
///definir var como Logico --> EN C NO EXISTE
/// true -> 1    false -> 0

//int var1,var2;
//int resultado;

//var1 = 8;
//var2 = 4;

/// > mayor < menor != distinto == equivalente
//resultado = var1 == var2;
//printf("%i", resultado);

/// AND &&  OR ||  NOT  !
/// cualquier valor distinto de 0 es VERDADERO, de lo contrario es FALSO
//resultado = !var1;
//printf("%i",resultado);

//resultado = var1 && var2;
//printf("%i",resultado);

//resultado = (var1 > var2) && (var1 > 7);
//printf("%i",resultado);


//printf("%i",sizeof(int));

    return 0;
}
