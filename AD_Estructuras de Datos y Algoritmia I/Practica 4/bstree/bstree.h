#ifndef __BSTREE_H__
#define __BSTREE_H__

#include "funciones.h"
#include "cola.h"

typedef struct _BSTNodo{
    void *dato;
    struct _BSTNodo *izq;
    struct _BSTNodo *der;
} BSTNodo;

typedef BSTNodo *BSTree;

BSTree bstree_crear();
void bstree_destruir(BSTree arbol, FuncionDestructora destroy);
int bstree_buscar_dato(BSTree arbol, void *dato, FuncionComparadora comp);
BSTree bstree_buscar_nodo(BSTree arbol, void *dato, FuncionComparadora comp);
BSTree bstree_insertar(BSTree arbol, void *dato, FuncionCopiadora copy, FuncionComparadora comp);
void bstree_recorrer_bfs(BSTree arbol, FuncionVisitante visit, FuncionCopiadora copy, FuncionDestructora destroy);
void bstree_recorrer_preorden(BSTree arbol, FuncionVisitante visit);
void bstree_recorrer_inorden(BSTree arbol, FuncionVisitante visit);
void bstree_recorrer_postorden(BSTree arbol, FuncionVisitante visit);
// BSTree bstree_eliminar(BSTree arbol, void *dato, FuncionComparadora comp, FuncionDestructora destroy);
int bstree_es_vacio(BSTree arbol);
BSTree bstree_menor(BSTree arbol);
BSTree bstree_eliminar_aux(BSTree arbol, FuncionCopiadora copiar,FuncionComparadora comparar, FuncionDestructora destruir);
BSTree bstree_eliminar(BSTree arbol, void *dato, FuncionCopiadora copiar,FuncionComparadora comparar, FuncionDestructora destruir);
void *bstree_k_esimo_menor(BSTree arbol, int k);
int bstree_es_abb(BSTree arbol, FuncionComparadora comp);

#endif