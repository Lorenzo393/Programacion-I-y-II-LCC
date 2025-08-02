#ifndef __PILAENTEROS_H__
#define __PILAENTEROS_H__

#include "arregloenteros.h"

#define TOPE_INFERIOR_PILAS -1

struct _Pila {
ArregloEnteros *arr;
int ultimo;
};

typedef struct _Pila *Pila;

/**
 * Crea una nueva pila vacia con la capacidad dada.
 */
Pila pila_crear(int len);

/**
 * Libera la memoria requerida para la pila.
 */
void pila_destruir(Pila pila);

/**
 * Retorna 1 si la pila esta vacia y 0 en caso contrario.
 */
int pila_es_vacia(Pila pila);

/**
 * Retorna el elemento que se encuentra en el tope de la pila, pero sin eliminarlo.
 */
int pila_tope(Pila pila);

/**
 * Inserta un elemento en el tope de la pila, si esta se encuentra llena su capacidad
 * aumenta al doble. (arreglo_enteros_ajustar).
 */
void pila_apilar(Pila pila, int dato);

/**
 * Elimina el elemento que se encuentra en el tope de la pila.
 */
void pila_desapilar(Pila pila);

/**
 * Imprime en orden los elementos de la pila.
 */
void pila_imprimir(Pila pila);

#endif