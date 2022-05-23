#include <stdio.h>
#include <stdlib.h>


/**
FILE* fp -> puntero a file -> manejador de nuestro archivo
FILE* fopen(RUTA,MODO); -> si se abrio exitosamente nos devuelve un puntero a FILE, de lo contrario NULL
int fclose(FILE*) -> si se cerro exitosamente nos devuelve 0, de lo contrario -1.

///operaciones lectura y escritura
int fwrite(direccion de variable a escribir, tamano del tipo de dato de esa variable, (cantidad de variables), FILE*);
int fread(direccion de variable para leer, tamano del tipo de dato que vamos a leer, cantidad de datos, FILE*);


MODOS DE ESCRITURA
El modo wb abre el archivo, si no existe lo crea, posiciona el puntero al inciio del archivo - sobreescribe todo el archivo
El modo ab (APPEND) abre el archivo, si no existe lo crea, posiciona el puntero al final del arhivo, listo para anadir informacion

MODOS DE LECTURA

rb -> read-binary - si no existe el archivo NO LO CREA

**/
//4
//Juan
//4
//Juan
//4
//Juan

int main()
{
    FILE* fp;  /// Manejador de archivo
    int numerito;
    char nombre[6];
    fp = fopen("MiPrimerArchivo.bin", "rb"); /// si no se puede abrir por X motivo -> retorna NULL
    ///deberiamos verificar de que no sea NULL para decir que se abrio exitosamente
    if (fp != NULL)
    {
        printf("El archivo se abrio exitosamente\n");
//        fwrite(&numerito,sizeof(int),1,fp);
//        fwrite(&nombre,sizeof(char),6,fp);
        fread(&numerito,sizeof(int),1,fp);
        fread(&nombre,sizeof(char),6,fp);
        printf("numerito : %i\n", numerito);
        printf("nombre: %s", nombre);

        fclose(fp); ///cerramos el archivo

    }
    else
        printf("Hubo un error");

    return 0;
}
