#ifndef __SLISTU_H__
#define __SLISTU_H__

#include <stdlib.h>
#include <stdio.h>


typedef struct _SNodo {
    int dato;
    struct _SNodo *sig;
} SNodo;

typedef struct SList {
    SNodo *primero;
    SNodo *ultimo;
} SList;

/*
*   Crea una lista
*/
SList slist_crear();

/*
*   Agrega un elemento al inicio de la lista
*/
SList slist_agregar_inicio(SList lista, int dato);

/*
*   Agrega un elemento al final de la lista
*/
SList slist_agregar_final(SList lista, int dato);

/*
*   Recorre la lista
*/
void slist_recorrer(SList lista);

#endif