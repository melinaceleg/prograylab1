#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/// Sacar comentarios para utilizarlos

int main()
{
    ///9-Verificar si una pila DADA es capicúa.
/*Pila dada, copiaDada, auxDada, auxCopia;
inicpila(&dada);
inicpila(&copiaDada);
inicpila(&auxDada);
inicpila(&auxCopia);

apilar(&dada,1);
apilar(&dada,7);
apilar(&dada,7);
apilar(&dada,1);


printf("\nDada");
mostrar(&dada);

while(!pilavacia(&dada)){
    apilar(&copiaDada, tope(&dada));
    apilar(&auxDada, desapilar(&dada));
}

while(!pilavacia(&auxDada)){
    apilar(&dada,desapilar(&auxDada));
}

    while(!pilavacia(&dada) && !pilavacia(&copiaDada) && tope(&dada) == tope(&copiaDada)){
        apilar(&auxDada,desapilar(&dada));
        apilar(&auxCopia,desapilar(&copiaDada));
    }

    if(pilavacia(&dada) && pilavacia(&copiaDada)){
        printf("\nLa pila es capicua");
    }
    else{
        printf("\nLa pila No es capicua");
    }*/

///10 -Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos repetidos sobre sí mismo), realizar un programa que calcule en la pila C la operación de unión.
///A : base 1 2 3 tope
///B: base 2 3 5 7 tope
///Pila AUB = base 3 2 1 7 5 tope
/*Pila a, b, basura, auxA, auxB,c;
inicpila(&a);
inicpila(&b);
inicpila(&c);
inicpila(&basura);
inicpila(&auxA);
inicpila(&auxB);

apilar(&a,1);
apilar(&a,2);
apilar(&a,3);

apilar(&b,2);
apilar(&b,3);
apilar(&b,5);
apilar(&b,7);

printf("\na");
mostrar(&a);
printf("\nb");
mostrar(&b);


  while(!pilavacia(&b)){
    while(!pilavacia(&a)){
        if(tope(&a) == tope(&b)){
            apilar(&basura, desapilar(&a));
        }
        else{
            apilar(&auxA,desapilar(&a));
        }
    }
    apilar(&auxB,desapilar(&b));

    while(!pilavacia(&auxA)){
        apilar(&a,desapilar(&auxA));
    }
  }

  while(!pilavacia(&a)){
    apilar(&c,desapilar(&a));
  }

  while(!pilavacia(&auxB)){
    apilar(&c,desapilar(&auxB));
  }

  printf("\nLa union de los conjuntos no da la pila C");
  mostrar(&c);*/

///11-Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y ORDENADA2) dejando el
///resultado en una pila también ordenada en forma creciente (ORDENADAFINAL).
/*Pila ord1, ord2, destino, ordFinal;
inicpila(&ord1);
inicpila(&ord2);
inicpila(&destino);
inicpila(&ordFinal);

apilar(&ord1,1);
apilar(&ord1,3);
apilar(&ord1,7);

apilar(&ord2,2);
apilar(&ord2,4);
apilar(&ord2,6);

printf("\nOrdena 1");
mostrar(&ord1);
printf("\nOrdena 2");
mostrar(&ord2);



while(!pilavacia(&ord1) && !pilavacia(&ord2)){
    if(tope(&ord1)>tope(&ord2)){
        apilar(&destino,desapilar(&ord1));
    }else{
        apilar(&destino,desapilar(&ord2));
    }
}

if(!pilavacia(&ord1)){
    while(!pilavacia(&ord1)){
        apilar(&destino, desapilar(&ord1));
    }
}
else{
    while(!pilavacia(&ord2)){
        apilar(&destino, desapilar(&ord2));
    }
}

while(!pilavacia(&destino)){
    apilar(&ordFinal, desapilar(&destino));
}

printf("\nOrdena final queda con las pilas intercalas");
mostrar(&ordFinal);*/

    return 0;
}
