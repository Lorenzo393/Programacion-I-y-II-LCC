#ifndef __SGLIST_H__
#define __SGLIST_H__

#include "glist.h"

/**
 * SGList es una lista ordenada general simplemente enlazada.
 */
typedef GList SGList;
/**
 * La funcion comparadora determina el criterio de ordenamiento de la lista.
 * Retorna un entero negativo si el primer argumento es menor que el segundo, 0
 * si son iguales y un entero positivo en caso contrario
 */
typedef int (*FuncionComparadora)(void *, void *);

/**
 * Retorna una lista ordenada vacia.
 */
SGList sglist_crear();

/**
 * Destruye una lista ordenada.
 */
void sglist_destruir(SGList lista, FuncionDestructora destroy);

/**
 * Determina si una lista ordenada esta vacia.
 */
int sglist_vacia(SGList lista);

/**
 * Aplica la funcion visitante a cada elemento de la lista ordenada.
 */
void sglist_recorrer(SGList lista, FuncionVisitante visit);

/**
 * Inserta un nuevo dato en la lista ordenada.
 */
SGList sglist_insertar(SGList lista, void *data, FuncionCopia copy, FuncionComparadora comp);

/**
 * Busca un entero en la lista ordenada y retorna 1 si lo encuentra y 0 en caso contrario.
 */
int sglist_buscar(SGList lista, void *data, FuncionComparadora comp);

/**
 * Contruye una lista ordenada a partir de un arreglo de elementos y su longitud.
 */
SGList sglist_arr(void **arr, int len, FuncionCopia copy);

#endif /* __SGLIST_H__ */