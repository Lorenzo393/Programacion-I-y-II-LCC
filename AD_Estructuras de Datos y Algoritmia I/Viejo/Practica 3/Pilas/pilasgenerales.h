#ifndef __PILASGENERALES_H__
#define __PILASGENERALES_H__

#include "glist.h"

typedef GList Pila;

/**
 * Crea una nueva pila vacia.
 */
Pila pila_crear();

/**
 * Libera la memoria de la pila y sus datos.
 */
void pila_destruir(Pila pila, FuncionDestructora destroy);

/**
 * Retorna 1 si la pila esta vacia y 0 en caso contrario.
 */
int pila_es_vacia(Pila pila);

/**
 * Retorna el elemento que se encuentra en el tope de la pila, pero sin eliminarlo.
 */
void *pila_tope(Pila pila);

/**
 * Inserta un elemento en el tope de la pila.
 */
Pila pila_apilar(Pila pila, void *dato, FuncionCopia copy);

/**
 * Elimina el elemento que se encuentra en el tope de la pila.
 */
Pila pila_desapilar(Pila pila, FuncionDestructora destroy);

/**
 * Imprime en orden los elementos de la pila.
 */
void pila_imprimir(Pila pila, FuncionVisitante visit);


#endif /* __PILASGENERALES_H__ */