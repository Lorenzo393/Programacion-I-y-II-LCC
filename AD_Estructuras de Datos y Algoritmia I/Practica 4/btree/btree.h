#ifndef __BTREE_H__
#define __BTREE_H__

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"
#include "pila.h"
#include "cola.h"

typedef enum {
    BTREE_RECORRIDO_IN,
    BTREE_RECORRIDO_PRE,
    BTREE_RECORRIDO_POST
} BTreeOrdenDeRecorrido;

typedef struct _BTNodo {
    int dato;
    struct _BTNodo *left;
    struct _BTNodo *right;
} BTNodo;

typedef BTNodo *BTree;

typedef struct _GBTNodo{
    void *dato;
    struct _GBTNodo *left;
    struct _GBTNodo *right;
} GBTNodo;

typedef GBTNodo *GBTree;

BTree btree_crear();
void btree_destruir(BTree nodo);
int btree_empty(BTree nodo);
BTree btree_unir(int dato, BTree left, BTree right);
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitante visit);
void btree_recorrido_itPre(BTree arbol, FuncionVisitante visit, FuncionCopia copy, FuncionDestructora destroy);
void btree_recorrido_itIn(BTree arbol, FuncionVisitante visit, FuncionCopia copy, FuncionDestructora destroy);

int btree_nnodos_R(BTree arbol);
int btree_buscar_R(BTree arbol, int dato);
BTree btree_copiar_R(BTree arbol);
int btree_altura_R(BTree arbol);
int btree_nnodos_profundidad_R(BTree arbol, int profundidad);
int btree_profundidad_R(BTree arbol, int dato);
int btree_sumar_R(BTree arbol);

void btree_recorrer_extra(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitanteExtra visit, void *extra);
void btree_recorrer_inorden_e(BTree arbol, FuncionVisitanteExtra visit, void *extra);
void btree_recorrer_preorden_e(BTree arbol, FuncionVisitanteExtra visit, void *extra);
void btree_recorrer_postorden_e(BTree arbol, FuncionVisitanteExtra visit, void *extra);

void btree_recorrer_bfs_r(BTree arbol, FuncionVisitante visit);
void btree_recorrer_bfs_i(BTree arbol, FuncionVisitante2 visit, FuncionCopia copy, FuncionDestructora destroy);

#endif /* __BTREE_H__ */
