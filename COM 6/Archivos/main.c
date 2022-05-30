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
    CONTROL
       FILE* fopen("Ruta Archivo", "modo de apertura"); -> nos devuelve un puntero a FILE si todo funciono, de lo contrario NULL
    ///si la ruta es directa (carpeta del proyecto) no tengo que asignarle un PATH COMPLETO

        modos de apertura
        -> en archivos binarios
            rb -> read binary -> nos abre el archivo en modo lectura
            wb -> write binary -> nos abre el archivo en modo escritura, sobreescribe los datos que ya estan, lo crea si no existe
            ab -> append binary -> nos abre el archivo en modo escritura pero situa el puntero al final del archivo para añadir datos, si no existe lo crea


       int fclose(FILE*) -> Nos devuelve 0 si se cerro, de lo contrario -1
      POSICIONAMIENTO
       int fseek(FILE*,desplazamiento,desde donde);
            ///desde el inicio me desplazo hacia la derecha 2 enteros
                fseek(fp,sizeof(int)*2,SEEK_SET)
            ///desde la posicion en la cual estoy quiero avanzar un entero mas
                fseek(fp,sizeof(int)*1,SEEK_CUR);
            ///deseo leer el ultimo dato almacenado en el archivo
                fseek(fp,sizeof(int)*(-1) ,SEEK_END);

            desplazo hacia la der -> positivo
            desplazamiento hacia la izq -> negativo
      int ftell(FILE*) -> nos retorna la posicion del puntero en bytes
                        (nos dice la cantidad de bytes que hay desde el inicio hasta el puntero)


    operaciones lectura/escritura
       int fwrite(direccion de la variable que queremos escribir en el archivo, tamano de ese tipo de dato, la cantidad de datos, FILE*);
       int fread(direccion de la variable a guardar el dato del archivo, tamano de tipo de dato a leer, cantidad de datos, FILE*) -> nos devuelve la cantidad de datos leidos



**/

///prototipado
void cargaArreglo(int[],int*);
void muestraArreglo(int[],int);
void persistirArreglo(int[],int); /// guardar los datos en el archivo
void despersistirArreglo(int[],int*); /// traer los datos desde el archivo
int cantDatosArchivo();
void despersistirArregloDirecto(int[],int*);


void cargaArreglo(int arreglo[], int* validos)
{
    char continuar;
    int i= 0;
    do
    {
        printf("Ingrese un valor entero: ");
        scanf("%i", &arreglo[i]);
        i++;
        printf("Desea ingresar otro valor\n");
        fflush(stdin);
        scanf("%c", &continuar);
    }
    while(i < TAM_MAX && continuar == 's');

    *validos = i;


}

void muestraArreglo(int arreglo[], int validos)
{

    for ( int i = 0 ; i < validos ; i++)
    {
        printf("%i ", arreglo[i]);

    }
}

///escribo los datos sobre el archivo
void persistirArreglo(int arreglo[],int validos)
{
    FILE* fp;
    fp = fopen("MiArchivoDeEnteros.bin","wb"); ///si no existe, lo crea. Si existen datos se sobreescriben
    if (fp != NULL)
    {
        fwrite(arreglo,sizeof(int),validos,fp);
        fclose(fp);
    }
}


///traer los datos desde el archivo hacia el arreglo
///los traigo secuencialmente, dato a dato
void despersistirArreglo(int arreglo[], int* validos)
{
    FILE* fp;
    int i=0;
    fp = fopen("MiArchivoDeEnteros.bin", "rb");
    if (fp != NULL)
    {
        while (fread(&arreglo[i],sizeof(int),1,fp) > 0)
        {
            i++;
        }

        *validos = i;

        fclose(fp);

    }
}

///se desea saber cuantos enteros posee este archivo
///mediante posicionamiento


int cantDatosArchivo()
{
    FILE* fp;
    int cant=0;
    fp = fopen("MiArchivoDeEnteros.bin", "rb");
    if (fp != NULL)
    {
        fseek(fp,0,SEEK_END); ///me paro al final del archivo
        cant = ftell(fp) / sizeof(int);
        fclose(fp);
    }

    return cant;
}
///de una tirada me leo todos los datos sobre el arreglo
void despersistirArregloDirecto(int arreglo[], int* validos)
{
    *validos = cantDatosArchivo();
    FILE* fp;
    fp = fopen("MiArchivoDeEnteros.bin", "rb");
    if (fp != NULL)
    {
        fread(arreglo,sizeof(int),*validos,fp);
        fclose(fp);
    }

}



int main()
{
///escritura de un entero en el archivo
   FILE* fp; /// Manejador del archivo
   int numerito = 3;
   fp = fopen("MiArchivo.dat","wb");
   if (fp != NULL)
   {
      fwrite(&numerito,sizeof(int),1,fp);
      fclose(fp);

   }
   else
   {
       printf("No se pudo abrir el archivo");
   }
///lectura de un entero desde el archivo
    FILE* fp;
    int numero;
    fp = fopen(RUTA_ARCH,"rb");

    if (fp != NULL)
    {
     fread(&numero,sizeof(int),1,fp);
     fclose(fp);

     printf("numero: %i", numero);

    }

//3
//"Pablo"
///insertar una ristra de datos (STRING)

    FILE* fp;
    char arreglo[10] = "Pablo";
    fp = fopen(RUTA_ARCH,"ab");

    if (fp != NULL)
    {
        fwrite(arreglo, sizeof(char), TAM_MAX, fp);
        fclose(fp);
    }

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
        fread(nombre,sizeof(char),TAM_MAX,fp);
        fclose(fp);

        printf("numero: %i\n", numero);
        printf("nombre: %s", nombre);
    }


///trabajo con arreglo de enteros
///escritura de los datos
    int arreglo[TAM_MAX];
    int validos;
    //cargaArreglo(arreglo,&validos);
   // persistirArreglo(arreglo,validos);
   //despersistirArreglo(arreglo,&validos);
   despersistirArregloDirecto(arreglo,&validos);
   muestraArreglo(arreglo,validos);


///cargar una matriz y guardarla de una sola tirada en un archivo
  int matriz[2][2] = {{2,4},
                      {7,9}};
  int N = 2;
  int M = 2;
  FILE* fp;
  fp = fopen("ArchivoMatriz.bin", "wb");
  if (fp != NULL)
  {
      fwrite(matriz,sizeof(int),N*M,fp);
      fclose(fp);
  }

///escribo dato a dato en el archivo
    int matriz[2][2] ={{2,4},{7,9}};
    int N = 2;
    int M = 2;
    FILE* fp = fopen("ArchivoMatriz.bin", "wb");
    if (fp != NULL)
    {
        for (int i = 0; i < N ; i++)
        {
            for (int j = 0 ; j < M ; j++)
            {
                fwrite(&matriz[i][j],sizeof(int),1,fp);
            }
        }

        fclose(fp);
    }

  ///se de antemano que tipo de matriz debo crear (dimension)
  ///lectura de la matriz completa de un solo tiron
  int matriz[2][2];
  int N = 2;
  int M = 2;
  FILE* fp;
  fp = fopen("ArchivoMatriz.bin", "rb");
  if (fp != NULL)
  {
      fread(matriz,sizeof(int),N*M,fp);
      fclose(fp);

      for (int i = 0 ; i < N ; i++)
      {
          for (int j = 0; j < M ; j++)
          {
              printf("%i ", matriz[i][j]);
          }
          printf("\n");
      }
  }


    ///lectura secuencial - dato a dato
    int matriz[2][2];
    int N = 2;
    int M = 2;
    FILE* fp;
    fp = fopen("ArchivoMatriz.bin", "rb");
    if (fp != NULL)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M ; j++)
            {
                fread(&matriz[i][j],sizeof(int),1,fp);
            }
        }

        fclose(fp);
        for (int i = 0 ; i < N ; i++)
        {
            for (int j = 0; j < M ; j++)
            {
                printf("%i ", matriz[i][j]);
            }
            printf("\n");
        }

    }


    return 0;
}
