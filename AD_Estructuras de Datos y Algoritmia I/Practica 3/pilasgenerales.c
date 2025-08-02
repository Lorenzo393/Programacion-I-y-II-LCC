#include "pilasgenerales.h"

#include <stdlib.h>
#include <stdio.h>

// EJ 2
// i
Pila pila_crear() { return NULL; }

// ii
void pila_destruir(Pila pila, FuncionDestructora destroy){
    while(pila != NULL){
        GNode *nodoADestruir = pila;
        pila = pila->next;

        destroy(nodoADestruir->data);
        free(nodoADestruir);
    }
}

// iii
int pila_es_vacia(Pila pila) { return (pila == NULL); }

// iv
void *pila_tope(Pila pila) { return (pila->data); }

// v
Pila pila_apilar(Pila pila, void *dato, FuncionCopia copy){
    GNode *nuevoNodo = malloc(sizeof(GNode));
    nuevoNodo->data = copy(dato);
    nuevoNodo->next = pila;

    return nuevoNodo;
}

// vi
Pila pila_desapilar(Pila pila, FuncionDestructora destroy){
    if(pila == NULL)
        return NULL;

    GNode *nodoADestruir = pila;
    pila = pila->next;

    destroy(nodoADestruir->data);
    free(nodoADestruir);

    return pila;
}

// vii
void pila_imprimir(Pila pila, FuncionVisitante visit){
    for(GNode *recorrer = pila ; recorrer != NULL ; recorrer = recorrer->next){
        visit(recorrer->data);
    }
    printf("\n");
}