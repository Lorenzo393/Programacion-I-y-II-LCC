#ifndef __COLASGENERALES_H__
#define __COLASGENERALES_H__

typedef struct _GNode{
    void *data;
    struct _GNode *next;
} GNode ;

typedef GNode *GList;

typedef struct{
    GList first;
    GList last;
} LFGList;

typedef LFGList *Cola;

typedef void (*FuncionDestructora) (void *data);
typedef void (*FuncionVisitante) (void *data);
typedef void *(*FuncionCopia) (void *data);

/**
 * Crea una cola vacia.
 */
Cola cola_crear();

/**
 * Libera la memoria de una cola.
 */
void cola_destruir(Cola cola, FuncionDestructora destroy);

/**
 * Retorna 1 si la cola esta vacia y 0 en caso contrario.
 */
int cola_es_vacia(Cola cola);

/**
 * Retorna el elemento que se encuentra en el final de la cola sin eliminarlo.
 */
void *cola_final(Cola cola);

/**
 * Inserta un elemento en el principio de la cola.
 */
Cola cola_encolar(Cola cola, void *data, FuncionCopia copy);

/**
 * Libera un elemento del final de la cola.
 */
Cola cola_desencolar(Cola cola, FuncionDestructora destroy);

/**
 * Recorre la cola aplicando a cada elemento de ella la funcion visit.
 */
void cola_recorrer(Cola cola, FuncionVisitante visit);

#endif