#include "matriz.h"

/*
** Implmentacion utilizando un unico arreglo unidimensional
*/

struct Matriz_ {
    double *direccion;
    int numFilas;
    int numColumnas;
};


Matriz* matriz_crear(size_t numFilas, size_t numColumnas) {
    Matriz *matriz = malloc(sizeof(matriz));
    matriz->direccion = malloc(sizeof(double) * numFilas * numColumnas);
    matriz->numFilas = numFilas;
    matriz->numColumnas = numColumnas;
    return matriz;
}

void matriz_destruir(Matriz* matriz) {
    free(matriz->direccion);
    free(matriz);
}

double matriz_leer(Matriz* matriz, size_t fil, size_t col) {
    return matriz->direccion[fil * matriz->numFilas + col];
}

void matriz_escribir(Matriz* matriz, size_t fil, size_t col, double val) {
    matriz->direccion[fil * matriz->numFilas + col] = val;
}

size_t matriz_num_filas(Matriz* matriz) {
    return matriz->numFilas;
}

size_t matriz_num_columnas(Matriz* matriz) {
    return matriz->numColumnas;
}

void mostrar_matriz(Matriz *matriz){
    for(int i = 0 ; i < matriz->numFilas ; i++){
        for(int j = 0 ; j < matriz->numColumnas ; j++){
            printf("%.2lf ",matriz_leer(matriz,i,j));
        }
    }
    printf("\n");
}

void matriz_intercambiar_filas(Matriz *matriz, int fila1, int fila2){
    if(fila1 > matriz->numFilas) fila1 = matriz->numFilas;
    if(fila2 > matriz->numFilas) fila2 = matriz->numFilas;
    if(fila1 < 0) fila1 = 0;
    if(fila2 < 0) fila2 = 0;

    for(int i = 0 ; i < matriz->numColumnas ; i++){
        int aux = matriz_leer(matriz,fila1,i);
        matriz_escribir(matriz,fila1,i,matriz_leer(matriz,fila2,i));
        matriz_escribir(matriz,fila2,i,aux);
    }
}

void matriz_insertar_fila(Matriz *matriz, int posFila){
    if(posFila > matriz->numFilas) posFila = matriz->numFilas;
    if(posFila < 0) posFila = 0;
    
    //matriz->numFilas++;
    //matriz->direccion = realloc(matriz->direccion, (sizeof(double) * matriz->numFilas * matriz->numColumnas));
    
    for(int i = 0 ; i < matriz->numColumnas ; i++){
        matriz_escribir(matriz,matriz->numFilas,i,-1);
    }
    for(int i = matriz->numFilas ; i > posFila ; i--){
        matriz_intercambiar_filas(matriz, i, i-1);
    }
    matriz->numFilas++;

}