#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


Pila pila_crear(){
    return NULL;
}
int pila_es_vacia(Pila pila){
    return pila == NULL;
}
void pila_destruir(Pila pila, FuncionDestructora destroy){
    while(pila != NULL){
        GNode *nodoADestruir = pila;
        pila = pila->sig;
        destroy(nodoADestruir->dato);
        free(nodoADestruir);
    }
}
void *pila_tope(Pila pila){
    return pila->dato;
}
Pila pila_apilar(Pila pila, void *dato, FuncionCopia copy){
    GNode *nuevoNodo = malloc(sizeof(GNode));
    nuevoNodo->dato = copy(dato);
    nuevoNodo->sig = pila;
    return nuevoNodo;
}
Pila pila_desapilar(Pila pila, FuncionDestructora destroy){
    GNode *nodoADestruir = pila;
    pila = pila->sig;
    destroy(nodoADestruir->dato);
    free(nodoADestruir);
    return pila;
}
void pila_imprimir(Pila pila, FuncionVisitante2 visit){
    for(GNode *it = pila ; it != NULL ; it = it->sig){
        visit(it->dato);
    }
    printf("\n");
}