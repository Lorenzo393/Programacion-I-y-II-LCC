#ifndef __CDLIST_H__
#define __CDLIST_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct _CDNodo {
    int dato;
    struct _CDNodo* sig;
    struct _CDNodo* ant;
} CDNodo;

typedef struct {
    CDNodo* primero;
    CDNodo* ultimo;
} CDList;

typedef enum {
    CDLIST_RECORRIDO_HACIA_ADELANTE,
    CDLIST_RECORRIDO_HACIA_ATRAS
} DListOrdenDeRecorrido;


/**
 * 
 */
CDList cdlist_crear();

/**
 * 
 */
CDList cdlist_agregar_primero(CDList lista, int dato);

/**
 * 
 */
CDList cdlist_agregar_ultimo(CDList lista, int dato);

/**
 * 
 */
void cdlist_recorrer(CDList lista, DListOrdenDeRecorrido orden);



#endif