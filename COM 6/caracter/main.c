#include <stdio.h>
#include <stdlib.h>

int main()
{
   char letra; ///1 byte (8 bits)
   long int numerote=3; ///long int es un numero mas grande que un int
   printf("%li", numerote);

   int numerito1 = 3;
   printf("%i", numerito1);

   short numerito2 = 3; ///es un numero mas pequeno que un int
   printf("%hi", numerito2);

   float numerito3 =5.2; ///pesa lo mismo que un int
   printf("%f", numerito3);

   unsigned int numeroSinSigno = 3; /// 0..
   printf("%ui",numeroSinSigno);

   letra = 97;
   printf("La letra es: %i", (int)letra);



    return 0;
}
