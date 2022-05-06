#include <stdio.h>
#include <stdlib.h>
#define CANT_MAX 10

///Hacer una función que inserte los datos de cada depto ordenados por ‘id_depto’ de menor a mayor.

void insertarOrdenado(int ids_deptos[],float costos_diarios[],char vistas[],int cant_ambientes[], char disponibilidades[], int validos, int id, float costo_diario, char vista, int cant_ambiente, char disponibilidad)
{
    int i = validos - 1;
    while (i>=0 && ids_deptos[i] > id )
    {
        ids_deptos[i+1] = ids_deptos[i];
        costos_diarios[i+1] = costos_diarios[i];
        vistas[i+1] = vistas[i];
        cant_ambientes[i+1] = cant_ambientes[i];
        disponibilidades[i+1] = disponibilidades[i];
        i--;
    }
    ids_deptos[i+1] = id;
    costos_diarios[i+1] = costo_diario;
    vistas[i+1] = vista;
    cant_ambientes[i+1] = cant_ambiente;
    disponibilidades[i+1] = disponibilidad;
}


void insertarDeptos(int ids_deptos[],float costos_diarios[],int cant_ambientes[],char vistas[], char disponibilidades[], int* validos)
{
    char continuar;
    int id_depto;
    float costo_diario;
    int cant_ambiente;
    char vista;
    char disponibilidad;
    do
    {

        printf("Ingrese id depto: ");
        scanf("%i", &id_depto);
        printf("Ingrese costo: ");
        scanf("%f", &costo_diario);
        printf("Ingrese cantidad de ambientes: ");
        scanf("%i", &cant_ambiente);
        printf("Ingrese vista: ");
        scanf("%c", &vista);
        printf("Ingrese disponibilidad: ");
        scanf("%c", &disponibilidad);
        insertarOrdenado(ids_deptos,costos_diarios,cant_ambientes,vistas, disponibilidades,*validos,id_depto,costo_diario,vista,cant_ambiente,disponibilidad);
        (*validos)++;
        printf("Desea ingresar otro depto?");
        fflush(stdin);
        scanf("%c",&continuar);
    }
    while(continuar=='s' && *validos < CANT_MAX);

}

///Hacer una función que pase a una pila ‘ids_disponibles’ los ids de los departamentos ‘disponibles’.

void pasarIdsDisponibles(Pila* ids_disponibles, int ids_deptos[], int disponibilidades[], int validos)
{
    for (int i = 0 ; i < validos ; i++)
    {
        if (disponibilidades[i] == 'd')
        {
            apilar(ids_disponibles, ids_deptos[i]);
        }
    }
}

///Hacer una función que informe el costo total promedio de los deptos de 2 ambientes disponibles por 15 días.

void informarCostoPromedio(int cant_ambientes[], float costos_diarios[], int validos, int cantambiente)
{
    float costo = 0;
    int cantidad=0;
    for (int i = 0 ; i < validos; i++)
    {
        if (cant_ambientes[i] == cantambiente)
        {
            costo = costo + costos_diarios[i];
            cantidad++;
        }
    }

    printf("El costo promedio a pagar por 15 dias un depto de 2 ambientes es de %.2f\n", costo/cantidad);

}


///Realizar una función que reciba una ‘cantidad de ambientes’ e informe en detalle
///(id,costo_diario,vista,cant_ambientes,disponibilidad) del depto menos costoso que cumpla con ese requisito.
void informarDeptoMenosCostoso(int ids_deptos[], float costos_diarios[], char vistas[], int cant_ambientes[], char disponibilidades[], int validos, int cantAmbiente)
{
    int indiceMenosCostoso=-1; ///no puedo inicializarlo con uin indice invalido
    for (int i = 0; i < validos; i++)
    {
        ///si esta en -1 es que no fue inicializado aun, y no puedo elegir el primer indice porque podria no ser un depto de esa cantidad de ambientes
        if ((indiceMenosCostoso == -1) || (cant_ambientes[i] == cantAmbiente && costos_diarios[indiceMenosCostoso] > costos_diarios[i]))
        {
            indiceMenosCostoso = i;
        }
    }
    if (indiceMenosCostoso != -1)
    {
        mostrarUnDepto(ids_deptos[indiceMenosCostoso],costos_diarios[indiceMenosCostoso],vistas[indiceMenosCostoso],cant_ambientes[indiceMenosCostoso],disponibilidades[indiceMenosCostoso]);

    }
}

///Realizar una función que reciba la pila de ‘ids_disponibles’ e informe en detalle cada depto que posee la pila (id,costo_diario,vista,cant_ambientes,disponibilidad)
///que cumpla con el requisito de poseer un costo diario menor a uno recibido por parámetro.

int busquedaxIdDepto(int ids_deptos[], int validos, int id)
{
    int i=0;
    int indice = -1; //por defecto uno invalido
    while (i < validos && ids_deptos[i] < id)
    {
        i++;
    }
    if ( i < validos && ids_deptos[i] == id)
    {
        indice = i;
    }
    return indice;
}

void mostrarUnDepto(int id_depto, float costo_diario, char vista, int cant_ambiente, char disponibilidad)
{
    printf("ID DEPTO: %i\n", ids_depto);
    printf("COSTO DIARIO: %.2f\n", costos_diario);
    printf("VISTA: %c\n", vista);
    printf("CANT AMBIENTES: %i\n", cant_ambiente);
    printf("DISPONIBILIDAD: %c\n", disponibilidad);
}

void informarDeptosPila(Pila ids_disponibles, int ids_deptos[], float costos_diarios[], char vistas[], int cant_ambientes[], char disponibilidades[], int validos, float costo)
{
    int indice;
    while (!pilavacia(&ids_disponibles))
    {
        indice=busquedaxIdDepto(ids_deptos,validos,desapilar(&ids_disponibles));
        if (costos_diarios[indice] < costo)
        {
            mostrarUnDepto(ids_deptos[indice],costos_diarios[indice],vistas[indice],cant_ambientes[indice],disponibilidades[indice]);
        }
    }


}


int main()
{
    int ids_deptos[CANT_MAX];
    float costo_diario[CANT_MAX];
    char vista[CANT_MAX]; ///siendo 'f' frente y 'c' contrafrente
    int cant_ambientes[CANT_MAX];
    char disponibilidad[CANT_MAX];  /// ‘d’ disponible ‘o’ ocupado
    int validos=0;
    Pila ids_disponibles;
    inicpila(&ids_disponibles);
    insertarDeptos(ids_deptos,costo_diario,cant_ambientes,vista,disponibilidad,&validos);
    pasarIdsDisponibles(&ids_disponibles,ids_deptos,disponibilidad,validos);
    informarCostoPromedio(cant_ambientes,costo_diario,validos,2);
    informarDeptoMenosCostoso(ids_deptos,costo_diario,vista,cant_ambientes,disponibilidad,validos,2);
    informarDeptosPila(ids_disponibles,ids_deptos,costo_diario,vista,cant_ambientes,disponibilidad,validos,2300.0);


    return 0;
}
