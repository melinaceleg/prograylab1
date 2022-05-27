#include <stdio.h>
#include <stdlib.h>
#define CANT_MAX 20
#define NOM_ARCH "MiPrimerArchivo.bin"


/**
TIPOS DE ARCHIVO
 TEXTO - CON FORMATO - SECUENCIA DE CARACTERES
 BINARIOS - SIN FORMATO - SECUENCIA DE BYTES

MODOS DE ACCESO
 -SECUENCIAL - Para acceder a un dato especifico recorro dato a dato (leo dato a dato)
 -DIRECTO - Accedemos a una posicion determinada del archivo como si fuese un arreglo - avanzamos una secuencia de bytes.


FILE* fp -> puntero a file -> manejador de nuestro archivo

///FUNCIONES DE CONTROL
FILE* fopen(RUTA,MODO); -> si se abrio exitosamente nos devuelve un puntero a FILE, de lo contrario NULL
int fclose(FILE*) -> si se cerro exitosamente nos devuelve 0, de lo contrario -1.


///POSICIONAMIENTO
    int fseek(FILE*, desplazamiento, origen); ---> posiciona el puntero desde un origen determinado y un desplazamiento.
    desplazamiento: cantidad de bytes que se desplaza el puntero hacia el final (>0) ó hacia el inicio (<0) del archivo desde la posición fijada por origen: 0 (SEEK_SET) indica el comienzo del
    archivo archivo; 1 (SEEK_CUR SEEK_CUR) es la posición posición actual y2 (SEEK_END SEEK_END) indica el fin del archivo. En caso de error retorna un valor distinto de 0x0.
    int ftell(FILE*) -> nos retorna donde esta posicionado el puntero en el archivo (en cantidad de bytes)


///operaciones lectura y escritura
int fwrite(direccion de variable a escribir, tamano del tipo de dato de esa variable, (cantidad de datos), FILE*);
int fread(direccion de variable para leer, tamano del tipo de dato que vamos a leer, cantidad de datos, FILE*); -> nos devuelve la cantidad de bytes leidos


MODOS DE ESCRITURA
El modo wb - write binary - abre el archivo, si no existe lo crea, posiciona el puntero al inciio del archivo - sobreescribe todo el archivo
El modo ab - append binary - abre el archivo, si no existe lo crea, posiciona el puntero al final del arhivo, listo para anadir informacion

MODOS DE LECTURA

rb -> read-binary - si no existe el archivo NO LO CREA

**/

///prototipados
void cargaArreglo(int[],int*);
void muestraArreglo(int[],int);


///implementacion
void cargaArreglo(int arreglo[], int* validos)
{
    char continuar;
    int i = 0;
    do
    {
        printf("Ingrese un numero\n");
        scanf("%i", &arreglo[i]);
        i++;
        printf("Desea continuar\n");
        fflush(stdin);
        scanf("%c", &continuar);

    }while ( i < CANT_MAX && continuar == 's');

    *validos = i;

}


void muestraArreglo(int arreglo[],int validos)
{
    for ( int i = 0 ; i < validos ; i++)
    {
        printf("%i ", arreglo[i]);

    }

}




int main()
{
    ///Guardar un string a archivo
    FILE* fp;  /// Manejador de archivo
    int numerito;
    char nombre[20]= "Pepe";
    fp = fopen("MiPrimerArchivo.bin", "wb"); /// si no se puede abrir por X motivo -> retorna NULL
    ///deberiamos verificar de que no sea NULL para decir que se abrio exitosamente
    if (fp != NULL)
    {
       fwrite(&nombre,sizeof(char),CANT_MAX,fp);

        fclose(fp); ///cerramos el archivo

    }
    else
        printf("Hubo un error");

    ///Traer un string desde el archivo
    FILE* fp;
    char nombre[CANT_MAX];
    fp = fopen(NOM_ARCH,"rb");
    if (fp != NULL)
    {
        fread(&nombre,sizeof(char),CANT_MAX,fp);

        printf("%s", nombre);

        fclose(fp);
    }

///ESCRITURA DE UN ARREGLO DE ENTEROS CARGADO POR EL USUARIO
    FILE* fp;
    int arreglo[CANT_MAX];
    int validos;
    cargaArreglo(arreglo,&validos);
    fp = fopen("OtroArchivo.bin", "ab");
    if (fp != NULL)
    {
        fwrite(&arreglo,sizeof(int), validos, fp);
        fclose(fp);

    }

///LECTURA DE UN ARREGLO DE ENTEROS DESDE ARCHIVO
///lectura de tipo secuencial -dato a dato
    FILE* fp;
    int arreglo[CANT_MAX];
    int validos=0;
    fp = fopen("OtroArchivo.bin", "rb");
    if (fp != NULL)
    {
        int i = 0;
        while (fread(&arreglo[i],sizeof(int),1,fp) > 0)
        {
            i++;
        }
        validos = i;
        fclose(fp);
    }

    muestraArreglo(arreglo,validos);



///POSICIONAMIENTO
//fseek(fp,0,SEEK_END);
//fseek(fp,0,SEEK_SET);
//
//
//desplazamiento hacia der -> positivo
//desplazamiento hacia izq -> negativo

///DESDE LA POSICION ACTUAL ME DESPLAZO
//fseek(fp,sizeof(int)*2,SEEK_CUR)


//DESDE El FINAL ME DESPLAZO HACIA LA IZQ
//fseek(fp,(sizeof(int)*2)*(-1), SEEK_END);

///DSDE EL INICIO ME DESPLAZO HACIA LA DER
//fseek(fp,sizeof(int)*5,SEEK_SET);

///cantidad de enteros cargada en el archivo
    FILE* fp;
    fp = fopen("OtroArchivo.bin", "rb");
    int cant_datos;
    if (fp != NULL)
    {
        fseek(fp,0,SEEK_END);
        cant_datos = ftell(fp)/sizeof(int);
        fclose(fp);
        printf("cantidad de datos: %i", cant_datos);
    }


    return 0;
}
