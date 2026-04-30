#include "dlist.h"

DList dlist_crear(){
    DList lista;
    lista.primero = NULL;
    lista.ultimo = NULL;
    return lista;
}


DList dlist_agregar_inicio(DList lista, int dato){
    DNodo *nuevoNodo = malloc(sizeof(DNodo));
    nuevoNodo->dato = dato;
    nuevoNodo->ant = NULL;

    if(lista.primero == NULL){
        nuevoNodo->sig = NULL;
        lista.primero = nuevoNodo;
        lista.ultimo = nuevoNodo;

        return lista;
    }

    lista.primero->ant = nuevoNodo;
    nuevoNodo->sig = lista.primero;
    lista.primero = nuevoNodo;

    return lista;
}


DList dlist_agregar_final(DList lista, int dato){
    DNodo *nuevoNodo = malloc(sizeof(DNodo));
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;

    if(lista.primero == NULL){
        nuevoNodo->ant = NULL;
        lista.primero = nuevoNodo;
        lista.ultimo = nuevoNodo;

        return lista;
    }

    lista.ultimo->sig = nuevoNodo;
    nuevoNodo->ant = lista.ultimo;
    lista.ultimo = nuevoNodo;

    return lista;
}


void dlist_recorrer(DList lista, DListOrdenDeRecorrido orden){
    switch (orden){
    case DLIST_RECORRIDO_HACIA_ADELANTE:
        while(lista.primero != NULL){
            printf("%i ", lista.primero->dato);
            lista.primero = lista.primero->sig;
        }
        break;
    
    case DLIST_RECORRIDO_HACIA_ATRAS:
        while(lista.ultimo != NULL){
            printf("%i ", lista.ultimo->dato);
            lista.ultimo = lista.ultimo->ant;
        }
        break;
    
    default:
        printf("Error");
        break;
    }
    printf("\n");
}