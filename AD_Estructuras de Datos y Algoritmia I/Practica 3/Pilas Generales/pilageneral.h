#ifndef __PILAGENERAL_H__
#define __PILAGENERAL_H__

#include <stdlib.h>
#include <stdio.h> 

typedef void (*FuncionDestructora) (void *dato);
typedef void (*FuncionVisitante) (void *dato);
typedef void * (*FuncionCopia) (void * dato);


typedef struct _GNode{
    void *data;
    struct _GNode *next;
} GNode;

typedef GNode *GList;
typedef GList Pila;

/**
 * Crea una pila vacia
 */
Pila pila_crear();

/**
 * Libera la memoria requerida para la pila
 */
void pila_destruir(Pila pila, FuncionDestructora destroy);

/**
 * Retorna 1 si la pila esta vacia 0 en caso contrario
 */
int pila_es_vacia(Pila pila);

/**
 * Retorna el elemento topa de la pila, sin eliminarlo
 */
void *pila_tope(Pila pila);

/**
 * Inserta un elemento en el tope de la pila
 */
Pila pila_apilar(Pila pila, void *dato, FuncionCopia copy);

/**
 * Elimina el elemento que se encuentra en el tope de la pila
 */
Pila pila_desapilar(Pila pila, FuncionDestructora destroy);

/**
 * Imprime en orden los elementos de la pila
 */
void pila_imprimir(Pila pila, FuncionVisitante visit);

/**
 * Invierte los elementos de una lista utilizando pilas;
 */
GList lista_invertir(GList lista, FuncionCopia copy, FuncionDestructora destroy);

/**
 * Imprime la lista
 */
void lista_imprimir(GList lista, FuncionVisitante visit);

#endif