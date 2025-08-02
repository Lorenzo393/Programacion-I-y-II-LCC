#include "pilaenteros.h"

#include <stdlib.h>
#include <stdio.h>

// EJ 1 - c
// i
Pila pila_crear(int len){
    Pila pila = malloc(sizeof(Pila));
    pila->arr = arreglo_enteros_crear(len);
    pila->ultimo = TOPE_INFERIOR_PILAS;

    return pila;
}

// ii
void pila_destruir(Pila pila){
    arreglo_enteros_destruir(pila->arr);
    free(pila);
}

// iii
int pila_es_vacia(Pila pila) { return (pila->ultimo < 0); }

// iv
int pila_tope(Pila pila){
    return (arreglo_enteros_devolver_posicion(pila->arr, pila->ultimo));
}

// v
void pila_apilar(Pila pila, int dato){
    if(arreglo_enteros_capacidad_excedida(pila->arr, pila->ultimo)){
        pila->arr = arreglo_enteros_ajustar(pila->arr);
    }
    pila->ultimo = pila->ultimo + 1;
    pila->arr = arreglo_enteros_insertar_elemento(pila->arr, dato, pila->ultimo);
}

// vi
void pila_desapilar(Pila pila){
    pila->ultimo = pila->ultimo - 1;
}

// vii
void pila_imprimir(Pila pila){
    for(int i = pila->ultimo ; i > TOPE_INFERIOR_PILAS ; i--){
        arreglo_enteros_imprimir_posicion(pila->arr, i);
    }
    printf("\n");
}