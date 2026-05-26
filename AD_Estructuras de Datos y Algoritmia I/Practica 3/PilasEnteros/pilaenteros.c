#include "pilaenteros.h"

// 1c
// i
Pila pila_crear(int capacidad){
    Pila pila = malloc(sizeof(Pila));
    pila->arr = malloc(sizeof(ArregloEnteros));
    pila->arr->arreglo = malloc(sizeof(int) * capacidad);
    pila->arr->capacidad = capacidad;
    pila->ultimo = 0;

    return pila;
}

// ii
void pila_destruir(Pila pila){
    free(pila->arr->arreglo);
    free(pila->arr);
    free(pila);
}

// iii
int pila_es_vacia(Pila pila){ return (pila->ultimo == 0); }

// iv
int pila_tope(Pila pila){ return pila->arr->arreglo[pila->ultimo - 1]; }

// v
void pila_apilar(Pila pila, int dato){
    if(pila->ultimo > pila->arr->capacidad){
        pila->arr->arreglo = realloc(pila->arr->arreglo, sizeof(int) * (pila->arr->capacidad * 2));
        pila->arr->capacidad = pila->arr->capacidad * 2;
    }
    pila->arr->arreglo[pila->ultimo] = dato;
    pila->ultimo++;
}

// vi
void pila_desapilar(Pila pila){ pila->ultimo--; }

// vii
void pila_imprimir(Pila pila){
    for(int i = pila->ultimo - 1 ; i >= 0 ; i--)
        printf("%i ", pila->arr->arreglo[i]);
    printf("\n");
}