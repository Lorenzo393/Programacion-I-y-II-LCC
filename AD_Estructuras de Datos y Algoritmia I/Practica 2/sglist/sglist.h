#ifndef __SGLIST_H__
#define _SGLIST_H__

#include <stdlib.h>
#include <stdio.h>

typedef int (*FuncionComparadora) (void *dato1, void *dato2);
typedef void (*FuncionDestructora) (void *dato);
typedef void (*FuncionVisitante) (void *dato);
typedef void *(*FuncionCopia) (void *dato);


typedef struct _GNode{
    void *data;
    struct _GNode *next;
} GNode;

typedef GNode *GList;

typedef GList SGList;

/**
 * retorna una lista ordenada vacia.
 */
SGList sglist_crear();

/**
 * Destruye una lista ordenada.
 */
void sglist_destruir(SGList lista, FuncionDestructora destroy);

/**
 * determina si una lista ordenada es vac´ıa.
 */
int sglist_vacia(SGList lista);

/**
 * Aplica la funcion visitante a cada elemento de la lista ordenada.
 */
void sglist_recorrer(GList lista, FuncionVisitante visit);

/**
 * Inserta un nuevo dato en la lista ordenada. La funcion de comparacion es la que determina el 
 * criterio de ordenacion, su tipo esta declarado como typedef int (*FuncionComparadora)
 * (void *, void *), y retorna un entero negativo si el primer argumento es menor que el segundo,
 * 0 si son iguales, y un entero positivo en caso contrario.
 */
SGList sglist_insertar(SGList lista, void *dato, FuncionCopia copy, FuncionComparadora comp); 

/**
 * Busca un dato en la lista ordenada, retornando 1 si lo encuentra y 0 en caso contrario
 * (aprovechar que la lista esta ordenada para hacer esta busqueda mas eficiente).
 */
int sglist_buscar(GList lista, void *dato, FuncionComparadora comp);

/**
 * Construye una lista ordenada a partir de un arreglo de elementos y su longitud.
 */
SGList sglist_arr(void **arr, int long, FuncionCopia copy, FuncionComparadora comp); 

#endif