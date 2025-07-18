#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

typedef void (*FuncionVisitante) (int dato);
typedef int (*FuncionComparadora) (int a, int b);

typedef struct _SNodo {
  int dato;
  struct _SNodo *sig;
} SNodo;

typedef SNodo *SList;

/**
 * Devuelve una lista vacía.
 */
SList slist_crear();

/**
 * Destruccion de la lista.
 */
void slist_destruir(SList lista);

/**
 * Determina si la lista es vacía.
 */
int slist_vacia(SList lista);

/**
 * Agrega un elemento al final de la lista.
 */
SList slist_agregar_final(SList lista, int dato);

/**
 * Agrega un elemento al inicio de la lista.
 */
SList slist_agregar_inicio(SList lista, int dato);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void slist_recorrer(SList lista, FuncionVisitante visit);

/**
 * Devuelve la longitud de una lista
 */
int slist_longitud(SList lista);

/**
 * Devuelve la concatenacion de dos listas, modificando la primera
 */
void slist_concatenar(SList lista1, SList lista2);

/**
 * Inserta un dato en una lista en una posicion arbitraria
 */
SList slist_insertar(SList lista, int pos, int dato);

/**
 * Borra de una lista un dato apuntado en una posicion arbitraria
 */
SList slist_elimina(SList lista, int pos);

/**
 * Determina si un elemento esta o no en la lista
 */
int slist_contiene(SList lista, int dato);

/**
 * Devuelve la posicion de la primera ocurrencia de un elemento. 
 * Si no esta devuelve -1
 */
int slist_indice(SList lista, int dato);

/**
 * Devuelve una lista con los elementos comunes de dos listas, 
 * no se modifican las originales
 */
SList slist_intersecar(SList lista1, SList lista2);

/**
 * Ordena una lista de acuerdo a al criterio dado por una funcion de comparacion,
 * que usa los mismos valores de retorno que strcmp()
 */
SList slist_ordenar(SList lista, FuncionComparadora f);

/**
 * Devuelve el reverso de la lista
 */
SList slist_reverso(SList lista);

/**
 * Dadas dos listas intercala sus elementos en la lista resultante
 */
SList slist_intercalar(SList lista1, SList lista2);

/**
 * Divide una lista a la mitad
 */
SList slist_partir(SList lista);
#endif /* __SLIST_H__ */
