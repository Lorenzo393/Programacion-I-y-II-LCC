#ifndef __BTREE_H__
#define __BTREE_H__

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef void (*FuncionVisitante)(int dato);

typedef enum {
    BTREE_RECORRIDO_IN,
    BTREE_RECORRIDO_PRE,
    BTREE_RECORRIDO_POST
} BTreeOrdenDeRecorrido;

typedef struct _BTNodo *BTree;

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear();

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo);

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo);

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(int dato, BTree left, BTree right);

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitante visit);

/**
 * Retorna el numero de nodos del arbol
 */
int btree_nnodos(BTree arbol);

/**
 * Retorna 1 si el dato esta en el arbol y 0 en caso contrario
 */
int btree_buscar(BTree arbol, int dato);

/**
 * Retorna un nuevo arbol que es una copia del dado
 */
BTree btree_copiar(BTree arbol);

/**
 * Retorna la altura del arbol
 */
int btree_altura(BTree arbol);

/**
 * Retorna el numero de nodos que se encuentran en la profundidad dada
 */
int btree_nnodos_profundidad(BTree arbol, int profundidad);

/**
 * Retorna la profundidad del nodo que contiene el numero dado y -1 si el numero no se encuentra
 */
int btree_profundidad(BTree arbol, int dato);

/**
 * Retorna la suma total de los datos del arbol
 */
int btree_sumar(BTree arbol);

#endif
