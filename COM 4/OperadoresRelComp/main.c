#include <stdio.h>
#include <stdlib.h>


/// \n --> salto de linea (enter)
///definir valor como Logico --> EN C NO EXISTE
/// 1 --> verdadero 0 --> falso

int main()
{
  int numerito1;
  int numerito2;
  int resultado;

printf("Ingrese un valor entero para numerito1\n");
scanf("%i",&numerito1); //-3
printf("Ingrese un valor entero para numerito2\n");
scanf("%i",&numerito2);  //5

///todo numero distinto de 0 es VERDADERO, de lo contrario es FALSO

///operadores de comparacion -->devuelven V o F ( 1 o 0)
/// > mayor  < menor >= mayor igual <= menor igual  != distinto == equivalente
//resultado = numerito1 > numerito2;
//printf("%i",resultado);

///operadores de relacion ---> devuelve V o F (1 o 0)
/// AND &&  OR ||  NOT !
//resultado = numerito1 && numerito2;
//printf("%i", resultado);

///combinacion entre relacion y comparacion
resultado = (numerito1 > 3) && (numerito2 > 5);
printf("%i",resultado);
    return 0;

}
