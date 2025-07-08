#include "matriz.h"

/*
** Implmentacion utilizando un unico arreglo unidimensional
*/

struct Matriz_ {
    int nFilas,nColumnas;
    double **elementos;
};


Matriz* matriz_crear(size_t numFilas, size_t numColumnas) {
    Matriz *matriz = malloc(sizeof(Matriz));
    matriz->nFilas = numFilas;
    matriz->nColumnas = numColumnas;
    matriz->elementos = malloc(sizeof(double*)*numFilas);
    for(int i = 0 ; i < numFilas ; i++){
        matriz->elementos[i] = malloc(sizeof(double) * numColumnas);
    }
    return matriz;
}

void matriz_destruir(Matriz* matriz) {
    for(int i = 0 ; i < matriz->nFilas ; i++){
        free(matriz->elementos[i]);
    }
    free(matriz->elementos);
}

double matriz_leer(Matriz* matriz, size_t fil, size_t col) {
    return matriz->elementos[fil][col];
}

void matriz_escribir(Matriz* matriz, size_t fil, size_t col, double val) {
    matriz->elementos[fil][col] = val;
}

size_t matriz_num_filas(Matriz* matriz) {
    return matriz->nFilas;
}

size_t matriz_num_columnas(Matriz* matriz) {
    return matriz->nColumnas;
}
