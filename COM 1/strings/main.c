#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
    String -> arreglo de letras/caracteres
    ->tratamiendo especial que se le da a los arreglos de caracteres
    -> vamos a tratarlo como TEXTO
    -> tenemos que agregarle un caracter denominado terminator o nulo que indica el fin de la cadena o string. '\0'
    -> al declarar un string debo tener en cuenta que la longitud de mi string esta dada por la cantidad de caracteres que yo
    quiero ingresar + '\0'
    char palabra[10] -> tengo espacio para 9 caracteres + '\0'

**/



int main()
{
    char palabra[10] = {'h','o','l','a','a','a','\0'}; ///como aca agrego letra por letra, debo agregar el terminator
    //printf("%s", palabra);
    char palabra2[20] = "hola como estas"; ///como estoy indicando que ingreso TEXTO, el terminator '\0' se agrega automaticamente
    //printf("%s",palabra2);
    char palabra3[20];
    printf("Ingrese un TEXTO\n");
    fflush(stdin);
    //scanf("%s", palabra3); ///solo lee palabras, porque toma los caracteres especiales como fin del string
    //printf("%s",palabra3);
    ///existe una funcion especial PARA STRINGS la cual reconoce todos los caracters y nos agrega el caracter nulo al final
    gets(palabra3);
    //printf("%s",palabra3);
    ///existe una funcion especial para IMPRIMIR STRINGS llamada puts,  de igual manera el printf con %s funciona perfectamente
    puts(palabra3);

    /**
        <string.h>
        funcionalidades para el manejo de strings

      -->  void strcpy(dest,origen); ///copia todos los caracteres de origen a destino hasta un nulo, y agrega el nulo al final.
      -->  int strcmp(str1,str2); ---> devuelve 0 si los strings son iguales str1 = str2
                               ---> devuelve > 0 si el str1 > str2
                               ---> devuelve < 0 si el str1 < str2

        str1 = Maria
        str2 = Marta
                      strcmp(str1,str2) -->  retorna < 0

        str1 = Maria
        str2 = MariaMarta
                     strcmp(str1,str2) -->  retorna < 0

        //compara caracter a caracter hasta que encuentre uno distinto (y retornara segun el valor que tiene en la tabla ascii) o un nulo
        //es sensible a las mayusculas y minusculas

     --> int strcmpi(str1,str2); --> funciona exactamente igual que strcmp pero no distingue mayusculas de minusculas

     --> int strlen(str1) --> nos devuelve la longitud de nuestro string (sin contar el caracter nulo)
          basicamente itera sobre el string contando caracter a caracter hasta alcanzar el nulo.

    --> char *strcat(dest, origen) --> concatena al string dest el string origen, uniendo a la punta del string dest, el principo del string origen

        origen = "Marta"
        dest = "Maria"

        strcat(dest,origen) -> me retorna un string "MariaMarta"

**/
    ///USO DE STRCPY
    char palabra4[11];
    char palabra5[20];
    printf("Ingrese texto para palabra4\n");
    fflush(stdin);
    gets(palabra4);

    //palabra5 = palabra4; ///!!! NO SE PUEDE

    strcpy(palabra5,palabra4);
    puts(palabra5);


    ///USO DE STRCMP y STRCMPI
    char palabra6[10];
    char palabra7[15];

    printf("Ingrese un texto para palabra6\n");
    fflush(stdin);
    gets(palabra6);

    printf("Ingrese un texto para palabra7\n");
    fflush(stdin);
    gets(palabra7);

    if (strcmpi(palabra6,palabra7) == 0)
    {
        printf("Los strings son iguales");
    }
    else
    {
        if (strcmpi(palabra6,palabra7) < 0)
        {
            printf("palabra6 viene antes en el diccionario que palabra7");
        }
        else
        {
            printf("Palabra6 es mas grande (viene despues en el diccionario) que palabra7");
        }
    }

        ///USO DE STRLEN

        char palabra8[15];
        int longitud;

        printf("Ingrese un texto para palabra8\n");
        fflush(stdin);
        gets(palabra8);

        longitud = strlen(palabra8);

        printf("La longitud del texto %s es %i\n", palabra8, longitud);

        ///USO DE STRCAT (esta funcion raramente la vamos a usar nosotros)

        char palabra9[10];
        char palabra10[12];
        //char* palabraNueva;

        printf("Ingrese un texto para palabra9\n");
        fflush(stdin);
        gets(palabra9);

        printf("Ingrese un texto para palabra10\n");
        fflush(stdin);
        gets(palabra10);

       // palabraNueva = strcat(palabra9,palabra10); /// a palabra9 le concatenamos palabra10

        printf("%s", strcat(palabra9,palabra10));


    return 0;
}
