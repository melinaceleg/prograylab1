#include <stdio.h>
#include <stdlib.h>
///mostrar un saludo mientras se diga 'H' de hola hasta que el usuario diga 'C' de chau
int main()
{
  char letra;
  letra = 'H';

  while (letra == 'H' || letra == 'h')
  {
      printf("Hola como va!\n");
      fflush(stdin);
      scanf("%c",&letra);
      while (letra != 'c' && letra != 'h' && letra != 'C' && letra != 'H')
      {
          printf("opcion invalida\n");
          fflush(stdin);
          scanf("%c", &letra);
      }
  }

  printf("chau nos vemos");


    return 0;
}
