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
        if(i % matriz_num_columnas(matriz) == 0) printf("\n");
        printf("%.2lf ",matriz->direccion[i]);
    }
    printf("\n");
}

void matriz_intercambiar_filas(Matriz *matriz, size_t fil1, size_t fil2){
    for(int i = 0 ; i < matriz_num_columnas(matriz) ; i++){
        double aux1 = matriz_leer(matriz,fil1,i);
        matriz_escribir(matriz,fil1,i,matriz_leer(matriz,fil2,i));
        matriz_escribir(matriz,fil2,i,aux1);
    }
}

void matriz_insertar_fila(Matriz *matriz, size_t fil, double fila[]){
  for(int i = 0 ; i < matriz_num_columnas(matriz) ; i++){
    matriz_escribir(matriz,fil,i,fila[i]);
  }
}