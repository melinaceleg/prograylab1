#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    STRING

    ->arreglo de caracteres
    ->se le da un tratamiento como si fuera un bloque entero
    -> vamos a hablar de el como TEXTO
    ->terminator o nulo \0
      -> es un caracter que indica el fin del string

    ->como debo tener en cuenta que existe ese caracter NULO o TERMINATOR al final del string
      la longitud del arreglo (string) se ve como la cantidad de letras que yo tenga + \0
      char palabra[5] -> 4 letras + '\0'
**/



int main()
{
    char palabra[10] = {'h','o','l','a','\0','a','h','j'}; /// 9 caracteres
    printf("%s",palabra);
    char palabra2[10] = "hola como"; ///automaticamente me agrega el caracter nulo
    printf("%s",palabra2);
    char palabra3[10];
    printf("Ingrese una palabra o texto\n");
    fflush(stdin);
//    //scanf("%s", palabra3); ///no agrega el caracter nulo
//    //printf("%s", palabra3);

    ///funcion especial para la lectura de strings
    gets(palabra3); ///te agrega el caracter nulo al final de la lectura del string
    printf("%s", palabra3);
//    palabra3 hola como\0
    gets(palabra3);
//    palabra3 perro\0omo\0
    ///funcion especial para la escritura por pantalla de strings
    puts(palabra3);

    /**
        #include <string.h>
          -> void strcpy(dest,origen) --> copia los caracteres del string origen (incluido el nulo) hacia el dest
          -> int strcmp(str1,str2)   --> retorna 0 cuando son iguales
                                 --> retorna < 0 cuando str1 < str2
                                 --> retorna > 0 cuando str1 > str2

                                 str1 -> Maria
                                 str2 -> MariaMarta

         -> int strcmpi(str1,str2) -> igual a strcmp pero NO DISTINGUE MAYUSCULAS DE MINUSCULAS
         -> int strlen(str1) -> me va a retornar la cantidad de caracteres que posee hasta el nulo( sin incluir el nulo)

         de yapa (no se evalua )
         -> char *strcat(str1, str2) -> concatenar al final del str1 el str2
             -> str1 -> Maria
             -> str2 -> Marta
              strcat(str1,str2) -> MariaMarta

    **/

    ///USO DE STRCPY

    char palabra3[10];
    char palabra4[10];

//    printf("Ingrese palabra3\n");
//    fflush(stdin);
//    gets(palabra3); ///perro

    printf("Ingrese palabra4\n");
    fflush(stdin);
    gets(palabra4); ///pastor aleman

   // palabra4 = palabra3; ///NO SE PUEDE
    //strcpy(palabra4,palabra3); ///copia hacia palabra4 el string que hay en palabra3
    puts(palabra4); //printf("%s", palabra4);


    ///USO DE STRCMP y STRCMPI

    char palabra6[10];
    char palabra7[15];
    printf("Ingrese palabra6\n");
    fflush(stdin);
    gets(palabra6);
    printf("Ingrese palabra7\n");
    fflush(stdin);
    gets(palabra7);

    if (strcmpi(palabra6,palabra7) == 0)
    {
        printf("Los strings son iguales");
    }
    else
        if(strcmpi(palabra6,palabra7) < 0)
        {
          printf("%s es mas grande que %s", palabra7,palabra6);
        }
        else
        {
            printf("%s es mas grande que %s",palabra6,palabra7);
        }


        ///USO DE STRLEN

        char palabra8[30];
        int cantidad;
        printf("Ingrese palabra\n");
        fflush(stdin);
        gets(palabra8);

        cantidad = strlen(palabra8);
        printf("La cantidad de letras que tiene la palabra %s es %i", palabra8,cantidad);

        ///STRCAT

        char palabra9[10];
        char palabra10[10];
        printf("Ingrese palabra 9\n");
        fflush(stdin);
        gets(palabra9);
        printf("Ingrese palabra 10\n");
        fflush(stdin);
        gets(palabra10);

        printf("%s",strcat(palabra9,palabra10));



    return 0;
}
