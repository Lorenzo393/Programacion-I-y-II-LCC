#ifndef __PILAENTEROS_H__
#define __PILAENTEROS_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct _ArregloEnteros{
    int *arreglo;
    int capacidad;
} ArregloEnteros;

struct _Pila {
    ArregloEnteros *arr;
    int ultimo;
};

typedef struct _Pila *Pila;

/**
 * Crea una pila con una capacidad dada
 */
Pila pila_crear(int capacidad);

/**
 * Libera la memoria requerida para la pila
 */
void pila_destruir(Pila pila);

/**
 * Retorna 1 si la pila esta vacia 0 en caso contrario
 */
int pila_es_vacia(Pila pila);

/**
 * Retorna el elemento topa de la pila, sin eliminarlo
 */
int pila_tope(Pila pila);

/**
 * Inserta un elemento en el tope de la pila, si se encuentra
 *  lleno aumenta su capacidad el doble, usando la funcion arreglo enteros ajustar
 */
void pila_apilar(Pila pila, int dato);

/**
 * Elimina el elemento que se encuentra en el tope de la pila
 */
void pila_desapilar(Pila pila);

/**
 * Imprime en orden los elementos de la pila
 */
void pila_imprimir(Pila pila);


#endif