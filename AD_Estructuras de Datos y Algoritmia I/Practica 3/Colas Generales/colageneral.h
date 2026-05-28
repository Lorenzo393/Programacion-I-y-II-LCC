#ifndef __COLAGENERAL_H__
#define __COLAGENERAL_H__

#include <stdlib.h>
#include <stdio.h>

typedef void (*FuncionDestructora) (void *dato);
typedef void (*FuncionVisitante) (void *dato);
typedef void *(*FuncionCopia)(void *dato);


typedef struct _GNode{
    void *data;
    struct _GNode *next;
} GNode;

typedef struct _SGList{
    GNode *primero;
    GNode *ultimo;
} SGList;

typedef SGList Cola;

/**
 * Crea una cola vacia
 */
Cola cola_crear();

/**
 * Destruye la cola
 */
void cola_destruir(Cola cola, FuncionDestructora destroy);

/**
 * Retorna 1 si la cola es vacia y 0 en caso contrario
 */
int cola_es_vacia(Cola cola);

/**
 * Retorna el elemento que se encuentra al inicio de la cola sin eliminarlo
 */
void *cola_inicio(Cola cola);

/**
 * Agrega un elemento al final de la cola
 */
Cola cola_encolar(Cola cola, void *dato, FuncionCopia copy);

/**
 * Elimina un elemento del principio de la cola
 */
Cola cola_desencolar(Cola cola, FuncionDestructora destroy);

/**
 * Imprime los elementos de la cola en orden de salida
 */
void cola_imprimir(Cola cola, FuncionVisitante visit);



#endif