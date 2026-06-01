#ifndef __BSTREE_H__
#define __BSTREE_H__

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void *(*FuncionCopiadora)(void *dato);
typedef int (*FuncionComparadora)(void *dato1, void *dato2);
typedef void (*FuncionDestructora)(void *dato);
typedef void (*FuncionVisitanteExtra)(void *dato, void *extra);

typedef enum {
	BTREE_RECORRIDO_IN,  /** Inorden */
	BTREE_RECORRIDO_PRE, /** Preorden */
	BTREE_RECORRIDO_POST /** Postorden */
} BSTreeRecorrido;

/**
 * Estructura del nodo del arbol de busqueda binaria.
 * Tiene un puntero al dato (dato), un puntero al nodo raiz del subarbol izquierdo (izq),
 * y un puntero al nodo raiz del subarbol derecho (der).
 */
struct _BST_Nodo {
    void *dato;
    struct _BST_Nodo *izq, *der;
};

typedef struct _BST_Nodo *BSTree;

/**
 * Retorna un arbol de busqueda binaria vacio.
 */
BSTree bstee_crear();

/**
 * Destruye el arbol y sus datos.
 */
void bstree_destruir(BSTree arbol, FuncionDestructora destroy);

/**
 * Retorna 1 si el dato se encuentra y 0 en caso contrario.
 */
int bstree_buscar(BSTree arbol, void *dato, FuncionComparadora comp);

/**
 * Inserta un dato no repetido en el arbol, manteniendo la propiedad del arbol
 * de busqueda binaria.
 */
BSTree bstree_insertar(BSTree arbol, void *dato, FuncionCopiadora copy, FuncionComparadora comp);

/**
 * Recorrido DSF del arbol
 */
void bstree_recorrer(BSTree arbol, BSTreeRecorrido orden, FuncionVisitanteExtra visit, void *extra);

#endif //__BSTREE_H__