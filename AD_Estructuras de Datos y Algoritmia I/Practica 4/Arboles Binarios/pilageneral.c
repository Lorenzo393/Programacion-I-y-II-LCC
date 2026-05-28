#include "pilageneral.h"

// EJ 2
// i
Pila pila_crear(){ return NULL; }

// ii
void pila_destruir(Pila pila, FuncionDestructora destroy){
    while(pila != NULL){
        destroy(pila->data);
        pila = pila->next;
    }
    free(pila);
}

// iii
int pila_es_vacia(Pila pila){ return pila == NULL; }

// iv
void *pila_tope(Pila pila){ return pila->data; }

// v
Pila pila_apilar(Pila pila, void *dato, FuncionCopia copy){
    GNode *nuevoNodo = malloc(sizeof(GNode));
    nuevoNodo->data = copy(dato);
    nuevoNodo->next = pila;

    return nuevoNodo;
}

// vi
Pila pila_desapilar(Pila pila, FuncionDestructora destroy){
    GNode *sigNodo = pila->next;
    destroy(pila->data);
    free(pila);
    return sigNodo;
}

// vii
void pila_imprimir(Pila pila, FuncionVisitante visit){
    for(GNode *it = pila ; it != NULL ; it = it->next)
        visit(it->data);
    printf("\n");
}

// EJ 3
GList lista_invertir(GList lista, FuncionCopia copy, FuncionDestructora destroy){
    Pila pila = pila_crear();
    for(GNode *it = lista ; it != NULL ; it = it->next)
        pila = pila_apilar(pila, it->data, copy);

    for(GNode *it = lista ; pila != NULL && it != NULL ; it = it->next){
        free(it->data);
        it->data = copy(pila_tope(pila));
        pila = pila_desapilar(pila, destroy);
    }
    return lista;
}

void lista_imprimir(GList lista, FuncionVisitante visit){
    for(GNode *it = lista ; it != NULL ; it = it->next)
        visit(it->data);
    printf("\n");
}