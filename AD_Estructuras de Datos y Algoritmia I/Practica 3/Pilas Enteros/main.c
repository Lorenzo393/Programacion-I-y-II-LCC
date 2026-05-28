#include "pilaenteros.h"

int main(){

    Pila pila = pila_crear(3);
    printf("Esta vacia? %i\n", pila_es_vacia(pila));
    pila_apilar(pila, 5);
    pila_apilar(pila, 4);
    pila_apilar(pila, 3);
    pila_apilar(pila, 2);
    pila_apilar(pila, 1);
    
    pila_imprimir(pila);

    pila_desapilar(pila);
    pila_desapilar(pila);
    pila_imprimir(pila);
    printf("%i",pila_tope(pila));

    return 0;
}