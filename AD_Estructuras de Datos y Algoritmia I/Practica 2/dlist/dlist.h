#ifndef __DLIST_H__
#define __DLIST_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct _DNodo {
    int dato;
    struct _DNodo* sig;
    struct _DNodo* ant;
} DNodo;

typedef struct {
    DNodo* primero;
    DNodo* ultimo;
} DList;

typedef enum {
    DLIST_RECORRIDO_HACIA_ADELANTE,
    DLIST_RECORRIDO_HACIA_ATRAS
} DListOrdenDeRecorrido;


/**
 * Crea una DList vacia
 */
DList dlist_crear();

/**
 * Agrega un elemento al principio de la lista
 */
DList dlist_agregar_inicio(DList lista, int dato);

/**
 * Agrega un elemento al final de la lista
 */
DList dlist_agregar_final(DList lista, int dato);

/**
 * Recorre la lista con un orden especifico
 */
void dlist_recorrer(DList lista, DListOrdenDeRecorrido orden);


#endif