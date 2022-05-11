#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
string -> arreglo de letras/caracteres
  -> tratamiento especial que se le da a los arreglos de caracteres
  -> <string.h>
  -> tratamos al arreglo como un bloque entero que conforma una palabra (texto)
  -> para saber donde termina un string tengo que agregarle un caracter especial que se denomina:
      -nulo o terminator '\0'
  ->tenemos que tener en cuenta que al declarar un arreglo para tratarlo como string, debemos pensar que la longitud
  va a ser de esa palabra + esa celda que se usa para el caracter nulo
      char palabra[10]  -> un string de longitud 9 maximo + \0

**/



int main()
{
    char palabra[10] = {'h','o','l','a','\0','a','a','\0','a','a'};
    char palabra2[10] = "hola como"; ////automaticamnete le agrega el terminator \0 al final
  printf("%s", palabra2); /// %s indica que es un string

    char palabra3[10];

    ///cargo el arreglo mediante el ingreso por teclado
  printf("Ingrese una palabra\n");
  fflush(stdin);
    scanf("%s", palabra3); /// le decimos que vamos a ingresar un string
    ///el problema del scanf es que no nos agrega el caracter nulo al final \0

    ///existe una funcion de lectura de strings que nos agrega el caracter nulo:
  gets(palabra3);  ///mejor opcion!
    ///existe una funcion de impresion de strings
  puts(palabra3);
    printf("%s", palabra3);


    /** funciones de <string.h>
      -> strcpy(destino,origen); --> esta funcion copia lo de origen hacia destino
      -> strcmp(str1,str2) --> nos retorna:
                                        0 - > str1 = str2 si los strings son iguales
                                        > 0 -> str1 > str2 si el primer caracter distinto que se encuentre en el str1 sea mayor al del str2
                                        < 0 -> str1 < str2 en caso contrario
            str1 : Maria
            str2 : Marta
            strcmp(str1,str2) --> devuelve un valor < 0

     ->strcmpi(str1,str2) HACE LO MISMO QUE STRCMP pero no le hace caso a las mayusculas o minusculas
     ->strlen(str1); -> nos devuelve la LONGITUD de nuestro string
                     -> cuenta la cantidad de caracteres hasta alcanzar el nulo o terminator \0
    ->char *strcat(char *dest, const char *src) -> concatena a la punta del string "src" el string "dest"
       str1: Maria
       str2: Marta
       strcat(str1,str2); Me devuelve -> MariaMarta
    **/

    ///USO DE STRCPY
    char palabra4[16];
    char palabra5[16];
    printf("Ingrese una palabra\n");
    fflush(stdin);
    gets(palabra4);

    //palabra5 = palabra4; ///ESTO NO SE PUEDE!!
    strcpy(palabra5,palabra4); //podriamos interpretarlo como una asignacion
    strcpy(palabra5,"pepe");
    int i =0 ;
    while (i < 16 && palabra5[i] != '\0')
    {
        printf("%c", palabra5[i]);
        i++;
    }
    printf("%s",palabra5);

    /USO DEL STRCMP y STRCMPI

    char palabra6[10];
    char palabra7[10];
    int ret;
    printf("Ingrese una palabra para palabra6\n");
    fflush(stdin);
    gets(palabra6);
    printf("Ingrese una palabra para palabra7\n");
    fflush(stdin);
    gets(palabra7);

    ret=strcmpi(palabra6,palabra7); /// >0 palabra6 es mas grande q palabra7, = 0 si son iguales, <0 palabra7 es mas grande
    if (ret > 0)
        printf("%s es mas grande q %s\n",palabra6,palabra7);
    else if (ret < 0)
        printf("%s es mas grande que %s\n",palabra7,palabra6);
    else
        printf("son iguales");


    ///USO DE STRLEN
    char palabra8[25];
    int cantidad;
    int cantVocales=0;
    printf("Ingrese un texto\n");
    fflush(stdin);
    gets(palabra8);
    //gets(palabra8);
    //printf("la cantidad de caracteres del string: %i", strlen(palabra8));

    cantidad = strlen(palabra8);

    ///contar la cantidad de vocales
    for (int i = 0 ; i < cantidad; i++ )
    {
        if (palabra8[i] == 'a' || palabra8[i] == 'e' || palabra8[i] == 'i' || palabra8[i] == 'o' || palabra8[i] == 'u')
        {
            cantVocales++;
        }
    }
    printf("La cantidad de vocales en el string es de: %i", cantVocales);



    return 0;
}
