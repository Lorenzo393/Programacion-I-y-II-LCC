#include "dlist.h"

// EJ 4
// a
DList *dlist_crear(){
    DList *lista = malloc(sizeof(DList));
    lista->primero = NULL;
    lista->ultimo = NULL;
    return lista;
}

// b
void dlist_agregar_final(DList *lista, int dato){
    DNodo *nuevoNodo = malloc(sizeof(DNodo));
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;
    if(lista->primero == NULL){
        nuevoNodo->ant = NULL;
        lista->primero = nuevoNodo;
        lista->ultimo = nuevoNodo;
    }
    else{
        nuevoNodo->ant = lista->ultimo;
        lista->ultimo->sig = nuevoNodo;
        lista->ultimo = nuevoNodo;
    }
}

// c
void dlist_agregar_inicio(DList *lista, int dato){
    DNodo *nuevoNodo = malloc(sizeof(DNodo));
    nuevoNodo->dato = dato;
    nuevoNodo->ant = NULL;
    if(lista->primero == NULL){
        nuevoNodo->sig = NULL;
        lista->primero = nuevoNodo;
        lista->ultimo = nuevoNodo;
    }
    else{
        nuevoNodo->sig = lista->primero;
        lista->primero->ant = nuevoNodo;
        lista->primero = nuevoNodo;
    }
}

// d
void dlist_recorrer(DList *lista, FuncionVisitante f, DListOrdenDeRecorrido ordenRecorrido){
    switch(ordenRecorrido){
        case DLIST_RECORRIDO_HACIA_ADELANTE:
            for(DNodo *recorrer = lista->primero ; recorrer != NULL ; recorrer = recorrer->sig){
                f(recorrer->dato);
            }
            break;
        case DLIST_RECORRIDO_HACIA_ATRAS:
            for(DNodo *recorrer = lista->ultimo ; recorrer != NULL ; recorrer = recorrer->ant){
                f(recorrer->dato);
            }
            break;
        default:
            printf("\nOrden de recorrido ingresado invalido!");
    }
}



