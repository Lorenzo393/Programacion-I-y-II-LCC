#ifndef __DLIST_H__
#define __DLIST_H__

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

typedef void (*FuncionVisitante)(int dato);

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
    DLIST_RECORRIDO_HACIA_ATRAS,
    PINDONGA
} DListOrdenDeRecorrido;

/**
 * Devuelve una lista vacía.
 */
DList *dlist_crear();

/**
 * Agrega un elemento al final de la lista.
 */
void dlist_agregar_final(DList *lista, int dato);

/**
 * Agrega un elemento al inicio de la lista.
 */
void dlist_agregar_inicio(DList *lista, int dato);

/**
 * Recorre la lista en un orden indicado en los argumentos
 */
void dlist_recorrer(DList *lista, FuncionVisitante f, DListOrdenDeRecorrido ordenRecorrido);







#endif