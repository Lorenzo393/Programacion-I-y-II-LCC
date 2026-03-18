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
    printf("\n");
    for(int j = 0 ; j < matriz_num_columnas(matriz) ; j++){
      printf("%.2lf ",matriz->direccion[i][j]);
    }
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