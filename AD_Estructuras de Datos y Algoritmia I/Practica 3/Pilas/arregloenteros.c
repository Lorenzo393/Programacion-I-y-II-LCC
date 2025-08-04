#include "arregloenteros.h"

#include <stdlib.h>
#include <stdio.h>

ArregloEnteros *arreglo_enteros_crear(int len){
    ArregloEnteros *arregloEnteros = malloc(sizeof(ArregloEnteros));
    arregloEnteros->enteros = malloc(sizeof(int) * len);
    arregloEnteros->capacidad = len;

    return arregloEnteros;
}

void arreglo_enteros_destruir(ArregloEnteros *arregloEnteros){
    free(arregloEnteros->enteros);
    free(arregloEnteros);
}

int arreglo_enteros_devolver_posicion(ArregloEnteros *arregloEnteros, int pos){
    return (arregloEnteros->enteros[pos]);
}

int arreglo_enteros_capacidad_excedida(ArregloEnteros *arregloEnteros, int ultimaPosInsertar) { return (ultimaPosInsertar > (arregloEnteros->capacidad)); }

ArregloEnteros *arreglo_enteros_ajustar(ArregloEnteros *arregloEnteros){
    arregloEnteros->enteros = realloc(arregloEnteros->enteros, sizeof(int) * (arregloEnteros->capacidad * MULT_CAPACIDAD));
    arregloEnteros->capacidad = arregloEnteros->capacidad * MULT_CAPACIDAD;
    return arregloEnteros;
}

ArregloEnteros *arreglo_enteros_insertar_elemento(ArregloEnteros *arregloEnteros, int dato, int pos){
    arregloEnteros->enteros[pos] = dato;
    return arregloEnteros;
}

void arreglo_enteros_imprimir_posicion(ArregloEnteros *arregloEnteros, int pos){
    printf("%i ",arregloEnteros->enteros[pos]);
}