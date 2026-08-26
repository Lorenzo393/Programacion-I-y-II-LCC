#include <stdlib.h>
#include <stdio.h>
#include "cola.h"


Cola cola_crear(){
    Cola cola;
    cola.primero = NULL;
    cola.ultimo = NULL;
    return cola;
}
void cola_destruir(Cola cola, FuncionDestructora destroy){
    while(cola.primero != NULL){
        GNode *nodoADestruir = cola.primero;
        cola.primero = cola.primero->sig;
        destroy(nodoADestruir->dato);
        free(nodoADestruir);
    }
}
int cola_es_vacia(Cola cola){
    return cola.primero == NULL;
}
void *cola_inicio(Cola cola){
    return cola.primero->dato;
}
Cola cola_encolar(Cola cola, FuncionCopia copy, void *dato){
    GNode *nuevoNodo = malloc(sizeof(GNode));
    nuevoNodo->dato = copy(dato);
    nuevoNodo->sig = NULL;

    if(cola.primero == NULL){
        cola.primero = nuevoNodo;
        cola.ultimo = nuevoNodo;
    }
    else{
        cola.ultimo->sig = nuevoNodo;
        cola.ultimo = nuevoNodo;
    }
    return cola;
}
Cola cola_desencolar(Cola cola, FuncionDestructora destroy){
    GNode *nodoADestruir = cola.primero;
    cola.primero = cola.primero->sig;
    destroy(nodoADestruir->dato);
    free(nodoADestruir);
    return cola;
}
void cola_imprimir(Cola cola, FuncionVisitante2 visit){
    for(GNode *it = cola.primero ; it != NULL ; it = it->sig)
        visit(it->dato);
    printf("\n");
}