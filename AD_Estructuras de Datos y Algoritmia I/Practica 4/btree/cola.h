#ifndef __COLA_H__
#define __COLA_H__

#include "funciones.h"

typedef struct _Cola{
    GNode *primero;
    GNode *ultimo;
} Cola;

Cola cola_crear();
void cola_destruir(Cola cola, FuncionDestructora destroy);
int cola_es_vacia(Cola cola);
void *cola_inicio(Cola cola);
Cola cola_encolar(Cola cola, FuncionCopia copy, void *dato);
Cola cola_desencolar(Cola cola, FuncionDestructora destroy);
void cola_imprimir(Cola cola, FuncionVisitante2 visit);

#endif