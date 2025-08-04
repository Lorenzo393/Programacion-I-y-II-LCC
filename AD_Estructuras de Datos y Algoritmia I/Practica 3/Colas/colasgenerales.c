#include "colasgenerales.h"

#include <stdlib.h>
#include <stdio.h>

// EJ 4
// b
// i
Cola cola_crear(){
    Cola cola = malloc(sizeof(Cola));
    cola->first = NULL;
    cola->last = NULL;

    return cola;
}

// ii
void cola_destruir(Cola cola, FuncionDestructora destroy){
    while(cola->first != NULL){
        GNode *nodoADestruir = cola->first;
        cola->first = cola->first->next;

        destroy(nodoADestruir->data);
        free(nodoADestruir);
    }
    free(cola);
}

// iii
int cola_es_vacia(Cola cola){
    return (cola->first == NULL);
}

// iv
void *cola_final(Cola cola){
    return (cola->last->data);
}

// v
Cola cola_encolar(Cola cola, void *dato, FuncionCopia copy){
    GNode *nuevoNodo = malloc(sizeof(GNode));
    nuevoNodo->data = copy(dato);
    nuevoNodo->next = NULL;

    if(cola->first == NULL){
        cola->first = nuevoNodo;
        cola->last = nuevoNodo;

        return cola;
    }

    nuevoNodo->next = cola->first;
    cola->first = nuevoNodo;

    return cola;
}

// vi
Cola cola_desencolar(Cola cola, FuncionDestructora destroy){
    GNode *nodoADestruir = cola->last;
    GNode *nodoAnterior = cola->first;

    while(nodoAnterior->next != nodoADestruir){
        nodoAnterior = nodoAnterior->next;
    }
    nodoAnterior->next = NULL;
    cola->last = nodoAnterior;
    
    destroy(nodoADestruir->data);
    free(nodoADestruir);

    return cola;
}

// vii
void cola_recorrer(Cola cola, FuncionVisitante visit){
    for(GNode *recorre = cola->first ; recorre != NULL ; recorre = recorre->next){
        visit(recorre->data);
    }
    printf("\n");
}