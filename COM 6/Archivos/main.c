#include <stdio.h>
#include <stdlib.h>
#define RUTA_ARCH "MiArchivo.dat"
#define TAM_MAX 10

/**
Manejador de archivo
   FILE* fp; -> puntero a file

   Las funciones para trabajar con archivos estan en la libreria <stdio.h>

   Existen 2 tipos de archivos
       -Texto
       -Binarios -> En estos nos vamos a enfocar nosotros
   Existen dos modos de acceder a los archivos
       -Secuencialemnte -> para ir a un dato particular realizamos una lectura de los anteriores
       ->directo -> me posiciono sobre un determinado dato (corro una secuencia de bytes)

   operaciones de archivo
     control
       FILE* fopen("Ruta Archivo", "modo de apertura"); -> nos devuelve un puntero a FILE si todo funciono, de lo contrario NULL
    ///si la ruta es directa (carpeta del proyecto) no tengo que asignarle un PATH COMPLETO
       int fclose(FILE*) -> Nos devuelve 0 si se cerro, de lo contrario -1

      operaciones lectura/escritura
       int fwrite(direccion de la variable que queremos escribir en el archivo, tamano de ese tipo de dato, la cantidad de datos, FILE*);
       int fread(direccion de la variable a guardar el dato del archivo, tamano de tipo de dato a leer, cantidad de datos, FILE*) -> nos devuelve la cantidad de bytes leidos

   modos de apertura
   -> en archivos binarios
       rb -> read binary -> nos abre el archivo en modo lectura
       wb -> write binary -> nos abre el archivo en modo escritura, sobreescribe los datos que ya estan, lo crea si no existe
       ab -> append binary -> nos abre el archivo en modo escritura pero situa el puntero al final del archivo para añadir datos, si no existe lo crea

**/

int main()
{
//   FILE* fp; /// Manejador del archivo
//   int numerito = 3;
//   fp = fopen("MiArchivo.dat","wb");
//   if (fp != NULL)
//   {
//      fwrite(&numerito,sizeof(int),1,fp);
//      fclose(fp);
//
//   }
//   else
//   {
//       printf("No se pudo abrir el archivo");
//   }

// FILE* fp;
// int numero;
// fp = fopen(RUTA_ARCH,"rb");
//
// if (fp != NULL)
// {
//     fread(&numero,sizeof(int),1,fp);
//     fclose(fp);
//
//     printf("numero: %i", numero);
//
// }

///insertar una ristra de datos

//    FILE* fp;
//    char arreglo[10] = "Pablo";
//    fp = fopen(RUTA_ARCH,"ab");
//
//    if (fp != NULL)
//    {
//        fwrite(&arreglo, sizeof(char), TAM_MAX, fp);
//        fclose(fp);
//    }

///lectura del archivo -> secuencial
//3
//"Pablo"

    FILE *fp;
    int numero;
    char nombre[10];
    fp = fopen(RUTA_ARCH, "rb");
    if (fp != NULL)
    {
        fread(&numero,sizeof(int),1,fp);
        fread(&nombre,sizeof(char),TAM_MAX,fp);
        fclose(fp);

        printf("numero: %i\n", numero);
        printf("nombre: %s", nombre);
    }



    return 0;
}
