#include <stdio.h>
#include <stdlib.h>
/**
Hacer un algoritmo que calcule el total a pagar por la compra de camisas.
Si se compran tres camisas o más se aplica un descuento del 20% sobre el total de la compra y
si son menos de tres camisas un descuento del 10%
 **/

///uso de constantes  -- valores que NO PUEDEN ALTERARSE EN TIEMPO DE EJECUCION
/// es una ubicacion que almacena un valor que no puede alterarse en tiempo de ejecucion
///constantes por convencion sus nombres van en mayuscula
///las constantes se declaran fuera del main
///ambito global

#define PRECIOXCAMISA 30.4
#define DESCUENTO20 0.2




int main()
{
    ///ambito del main
    int cantCamisas;
    float total;
    float descuento;
    printf("Ingrese cantidad de camisas\n");
    scanf("%i", &cantCamisas);
    total = cantCamisas * PRECIOXCAMISA;

    if (cantCamisas >= 3)
    {
        printf("Se aplica un descuento del 20%% sobre la compra de %.2f\n", total);
        descuento =  total * DESCUENTO20;
        ///total = total * 0.8;
    }
    else
    {
        printf("Se aplica un descuento del 10%% sobre la compra de %.2f\n", total);
        descuento = total * 0.10;

    }

    total = total - descuento;
    printf("El total a pagar por la compra es %.2f", total);

    return 0;
}
