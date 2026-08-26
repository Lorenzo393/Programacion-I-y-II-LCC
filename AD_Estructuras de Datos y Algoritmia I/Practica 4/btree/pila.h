#ifndef __PILA_H__
#define __PILA_H__

#include "funciones.h"

typedef GNode *Pila;

Pila pila_crear();
void pila_destruir(Pila pila, FuncionDestructora destroy);
int pila_es_vacia(Pila pila);
void *pila_tope(Pila pila);
Pila pila_apilar(Pila pila, void *dato, FuncionCopia copy);
Pila pila_desapilar(Pila pila, FuncionDestructora destroy);
void pila_imprimir(Pila pila, FuncionVisitante2 visit);

#endif