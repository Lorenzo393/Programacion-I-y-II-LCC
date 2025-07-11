#include "matriz.h"

/*
** Implmentacion utilizando un unico arreglo unidimensional
*/

struct Matriz_ {
    unsigned int nFilas, nColumnas;
    double *direccion;
};


Matriz* matriz_crear(size_t numFilas, size_t numColumnas) {
    Matriz *matriz = malloc(sizeof(Matriz));
    matriz->direccion = malloc(sizeof(double) * (numFilas * numColumnas));
    matriz->nColumnas = numColumnas;
    matriz->nFilas = numFilas;
    return matriz;
}

void matriz_destruir(Matriz* matriz) {
    free(matriz->direccion);
    free(matriz);
}

double matriz_leer(Matriz* matriz, size_t fil, size_t col) {
    return matriz->direccion[(fil * matriz_num_columnas(matriz)) + col];
}

void matriz_escribir(Matriz* matriz, size_t fil, size_t col, double val) {
    matriz->direccion[(fil * matriz_num_columnas(matriz)) + col] = val;
}

size_t matriz_num_filas(Matriz* matriz) {
    return matriz->nFilas;
}

size_t matriz_num_columnas(Matriz* matriz) {
    return matriz->nColumnas;
}

void matriz_mostrar(Matriz *matriz){
    printf("Matriz UNI: ");
    for(int i = 0 ; i < matriz_num_filas(matriz) * matriz_num_columnas(matriz) ; i++){
    printf("%.2lf ",matriz->direccion[i]);
    }
}