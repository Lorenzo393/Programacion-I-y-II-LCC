#include "pilaenteros.h"

#include <stdlib.h>
#include <stdio.h>





int main(){

    Pila pila = pila_crear(10);
    
    pila_apilar(pila,1);
    pila_apilar(pila,2);
    pila_apilar(pila,3);
    pila_apilar(pila,4);
    pila_apilar(pila,5);

    pila_imprimir(pila);

    pila_desapilar(pila);
    pila_desapilar(pila);
    pila_apilar(pila,9);

    pila_imprimir(pila);

    printf("%i\n",pila_tope(pila));


    if(pila_es_vacia(pila)) printf("La pila esta vacia");
    else printf("La pila no esta vacia");

    pila_destruir(pila);

    return 0;
}