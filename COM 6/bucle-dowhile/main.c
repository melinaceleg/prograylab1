#include <stdio.h>
#include <stdlib.h>

///hacer un programa en el que el usuario cada vez que diga 'h' de hola, el sistema responda con hola
/// y si dice 'c' de chau, el sistema dice chau y termina

int main()
{
    /// MIENTRAS - WHILE : CONDICION - SENTENCIAS - CONDICION - SENTENCIAS .....
    char saludo;
    saludo = 'h';
//    while (saludo == 'h' || saludo == 'H')
//    {
//        printf("hola\n");
//        fflush(stdin); /// limpio el buffer de entrada
//        scanf("%c", &saludo);
//        ///validacion del caracter que ingrese (otro bucle while)
//    }

    printf("chau nos vemos\n");

/////////////////////////
///HACER - MIENTRASQUE
/**
   REPETIR
    ....
     ...
   MIENTRAS-QUE (CONDICION)

   do {

   }while(condition);


**/
/// do-while: SENTENCIAS - CONDICION - SENTENCIAS - CONDICION...
///el do while ejecuta las sentencias AL MENOS UNA VEZ..
   char saludo;
   do
   {
      printf("hola\n");
      fflush(stdin); ///limpio el buffer de entrada
      scanf("%c", &saludo);

   }while(saludo == 'h' || saludo == 'H');

   printf("chau nos vemos");



    return 0;
}
