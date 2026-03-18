#ifndef __CDLIST_H__
#define __CDLIST_H__

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

typedef void (* FuncionVisitante)(int);

typedef struct _CDNodo{
    int dato;
    struct _CDNodo *sig;
    struct _CDNodo *ant;
} CDNodo;

typedef CDNodo *CDList;

typedef enum{
    CDLIST_RECORRIDO_HACIA_ADELANTE,
    CDLIST_RECORRIDO_HACIA_ATRAS,
    HOMERO
} CDListOrdenDeRecorrido;

/**
 * Crea una lista vacia
 */
CDList cdlist_crear();

/**
 * Agrega un elemento al final de la lista
 */
CDList cdlist_agregar_final(CDList lista, int dato);

/**
 * Agrega un elemento al inicio de la lista
 */
CDList cdlist_agregar_inicio(CDList lista, int dato);

/**
 * Recorre la lista aplicando una funcion visitante a cada elemento
 */
void cdlist_recorrer(CDList lista, FuncionVisitante f, CDListOrdenDeRecorrido ordenRecorrido);

#endif