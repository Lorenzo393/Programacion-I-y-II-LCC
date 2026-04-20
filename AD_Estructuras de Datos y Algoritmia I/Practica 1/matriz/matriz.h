#ifndef __MATRIZ_H__
#define __MATRIZ_H__

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Matriz_ Matriz;

/*
** Crea una nueva matriz
*/
Matriz* matriz_crear(size_t numFilas, size_t numColumnas);

/*
** Destruye una matriz
*/
void matriz_destruir(Matriz* matriz);

/*
** Obtiene el dato guardado en la posición dada de la matriz
*/
double matriz_leer(Matriz* matriz, size_t fil, size_t col);

/*
** Modifica el dato guardado en la posición dada de la matriz
*/
void matriz_escribir(Matriz* matriz, size_t fil, size_t col, double val);

/*
** Obtiene número de filas de la matriz
*/
size_t matriz_num_filas(Matriz* matriz);

/*
** Obtiene número de columnas de la matriz
*/
size_t matriz_num_columnas(Matriz* matriz);

/*
** Muestra la matriz completa
*/
void mostrar_matriz(Matriz *matriz);

/*
** Intercambia filas de la matriz
*/
void matriz_intercambiar_filas(Matriz *matriz, int fila1, int fila2);

/*
** Agrega una nueva fila en la posicion dada
*/
void matriz_insertar_fila(Matriz *matriz, int posFila);

#endif /* __MATRIZ_H__ */
