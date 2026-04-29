#include "slistu.h"

SList slist_crear(){
    SList lista;
    lista.primero = NULL;
    lista.ultimo = NULL;

    return lista;
}


SList slist_agregar_inicio(SList lista, int dato){
    SNodo *nuevoNodo = malloc(sizeof(SNodo));
    nuevoNodo->dato = dato;

    if(lista.primero == NULL){
        lista.primero = nuevoNodo;
        lista.ultimo = nuevoNodo;
        nuevoNodo->sig = NULL;
        return lista;
    }

    nuevoNodo->sig = lista.primero;
    lista.primero = nuevoNodo;

    return lista;
}


SList slist_agregar_final(SList lista, int dato){
    SNodo *nuevoNodo = malloc(sizeof(SNodo));
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;

    if(lista.primero == NULL){
        lista.primero = nuevoNodo;
        lista.ultimo = nuevoNodo;
        return lista;
    }

    lista.ultimo->sig = nuevoNodo;
    lista.ultimo = nuevoNodo;

    return lista;
}

void slist_recorrer(SList lista){
    for(SNodo *it = lista.primero ; it != NULL ; it = it->sig)
        printf("%i ",it->dato);
    printf("\n");
}