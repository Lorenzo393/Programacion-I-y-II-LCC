#ifndef __BTREE_H__
#define __BTREE_H__

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef void (*FuncionDestructora) (void *dato);
typedef void (*FuncionVisitante) (void *dato);
typedef void *(*FuncionCopia) (void *dato);


typedef enum {
    BTREE_RECORRIDO_IN,
    BTREE_RECORRIDO_PRE,
    BTREE_RECORRIDO_POST
} BTreeOrdenDeRecorrido;

struct _BTNodo {
    void *dato;
    struct _BTNodo *left;
    struct _BTNodo *right;
};

typedef struct _BTNodo *BTree;

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear();

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo, FuncionDestructora destroy);

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo);

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(void *dato, BTree left, BTree right, FuncionCopia copy);

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitante visit);

#endif /* __BTREE_H__ */
