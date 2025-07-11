#include "matriz.h"

/*
** Implementacion utilizando un arreglo bidimensional (arreglo de punteros a arreglo)
*/

struct Matriz_ {
    unsigned int nFilas, nColumnas;
    double **direccion;
};


Matriz* matriz_crear(size_t numFilas, size_t numColumnas) {
  Matriz *matriz = malloc(sizeof(Matriz));
  matriz->direccion = malloc(sizeof(double*) * numFilas);
  for(int i = 0 ; i < numFilas ; i++){
    matriz->direccion[i] = malloc(sizeof(double) * numColumnas);
  }
  matriz->nColumnas = numColumnas;
  matriz->nFilas = numFilas;
  return matriz;
}

void matriz_destruir(Matriz* matriz) {
  for(int i = 0 ; i < matriz_num_filas(matriz) ; i++){
    free(matriz->direccion[i]);
  }
  free(matriz->direccion);
  free(matriz);
}

double matriz_leer(Matriz* matriz, size_t fil, size_t col) {
  return matriz->direccion[fil][col];
}

void matriz_escribir(Matriz* matriz, size_t fil, size_t col, double val) {
  matriz->direccion[fil][col] = val;
}

size_t matriz_num_filas(Matriz* matriz) {
  return matriz->nFilas;
}

size_t matriz_num_columnas(Matriz* matriz) {
  return matriz->nColumnas;
}

void matriz_mostrar(Matriz *matriz){
  printf("Matriz BI: ");
  for(int i = 0 ; i < matriz_num_filas(matriz) ; i++){
    for(int j = 0 ; j < matriz_num_columnas(matriz) ; j++){
      printf("%.2lf ",matriz->direccion[i][j]);
    }
  }
}