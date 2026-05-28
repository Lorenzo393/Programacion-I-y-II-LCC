#include "colageneral.h"

// EJ 4
// b

// i
Cola cola_crear(){
    Cola cola;
    cola.primero = NULL;
    cola.ultimo = NULL;
    return cola;
}

// ii
void cola_destruir(Cola cola, FuncionDestructora destroy){
    while(cola.primero != NULL){
        GNode *nodoAEliminar = cola.primero;
        cola.primero = cola.primero->next;
        destroy(nodoAEliminar->data);
        free(nodoAEliminar);
    }
}

// iii
int cola_es_vacia(Cola cola){ return cola.primero == NULL; }

// iv
void *cola_inicio(Cola cola){ return cola.primero->data; }

// v
Cola cola_encolar(Cola cola, void *dato, FuncionCopia copy){
    GNode *nuevoNodo = malloc(sizeof(GNode));
    nuevoNodo->data = copy(dato);
    nuevoNodo->next = NULL;

    if(cola.primero == NULL){
        cola.primero = nuevoNodo;
        cola.ultimo = nuevoNodo;
        return cola;
    }

    cola.ultimo->next = nuevoNodo;
    cola.ultimo = nuevoNodo;
    return cola;
}

// vi
Cola cola_desencolar(Cola cola, FuncionDestructora destroy){
    GNode *nodoAEliminar = cola.primero;
    cola.primero = cola.primero->next;
    destroy(nodoAEliminar->data);
    free(nodoAEliminar);
    return cola;
}

// vii
void cola_imprimir(Cola cola, FuncionVisitante visit){
    for(GNode *it = cola.primero ; it != NULL ; it = it->next)
        visit(it->data);
    printf("\n");
}