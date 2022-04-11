#include <stdio.h>
#include <stdlib.h>

///ambito global

///prototipados
int suma2valoresEnteros(int,int); ///cabecera de la funcion - suma 2 valores enteros

//tipo_de_salida nombre_funcion(Parametros de entrada)
//{
//    ///ambito de la funcion
//
//    return dato;
//}

///no tiene salida: void
///tipos de salida: int,float,char....

//void ej1(){
/////ambito funcion ej1
//Pila a;
//
//mostrar(&a);
//
//}



void main()
{
///ambito main
    int var1=3;
    int var2=5;
    int sum;
    sum = suma2valoresEnteros(var1,var2);
    printf("El resultado de la suma es %i", sum);

}





///funcion que suma dos enteros
///parametros de entrada: int, int
///parametro de salida: int
int suma2valoresEnteros(int a,int b) ///  a=3 , b=5
{
    ///ambito de la funcion,modulo,subprograma
    int suma; ///local a mi ambito

    suma = a + b ;

    return suma;

}




