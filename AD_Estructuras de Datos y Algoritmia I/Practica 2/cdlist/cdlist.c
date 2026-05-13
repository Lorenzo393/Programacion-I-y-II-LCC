#include "cdlist.h"


CDList cdlist_crear(){
    CDList lista;
    lista.primero = NULL;
    lista.ultimo = NULL;
    return lista;
}

CDList cdlist_agregar_primero(CDList lista, int dato){
    CDNodo *nuevoNodo = malloc(sizeof(CDNodo));
    nuevoNodo->dato = dato;

    if(lista.primero == NULL){
        nuevoNodo->sig = lista.ultimo;
        nuevoNodo->ant = lista.ultimo;
        lista.primero = nuevoNodo;
        lista.ultimo = nuevoNodo;
        return lista;
    }
    
    nuevoNodo->sig = lista.primero;
    nuevoNodo->ant = lista.ultimo;
    lista.primero->ant = nuevoNodo;
    lista.ultimo->sig = nuevoNodo;
    lista.primero = nuevoNodo;
    return lista;
}


CDList cdlist_agregar_ultimo(CDList lista, int dato){
    CDNodo *nuevoNodo = malloc(sizeof(CDNodo));
    nuevoNodo->dato = dato;
    
    if(lista.primero == NULL){
        nuevoNodo->sig = lista.ultimo;
        nuevoNodo->ant = lista.ultimo;
        lista.primero = nuevoNodo;
        lista.ultimo = nuevoNodo;
        return lista;
    }

    nuevoNodo->ant = lista.ultimo;
    nuevoNodo->sig = lista.primero;
    lista.ultimo->sig = nuevoNodo;
    lista.primero->ant = nuevoNodo;
    lista.ultimo = nuevoNodo;
    return lista;
}


void recorrer_adelante(CDList lista){
    if(lista.primero != NULL){
        printf("%i ", lista.primero->dato);
        
        for(CDNodo *it = lista.primero->sig ; it != lista.primero ; it = it->sig)
            printf("%i ", it->dato);
    }
}

void recorrer_atras(CDList lista){
    if(lista.primero != NULL){
        printf("%i ", lista.ultimo->dato);
        
        for(CDNodo *it = lista.ultimo->ant ; it != lista.ultimo ; it = it->ant)
            printf("%i ", it->dato);
    }
}

void cdlist_recorrer(CDList lista, DListOrdenDeRecorrido orden){
    switch(orden){
        case CDLIST_RECORRIDO_HACIA_ADELANTE:
            recorrer_adelante(lista);
            break;
        case CDLIST_RECORRIDO_HACIA_ATRAS:
            recorrer_atras(lista);
            break;
        
        default:
            printf("error");
            break;
    }
    printf("\n");
}