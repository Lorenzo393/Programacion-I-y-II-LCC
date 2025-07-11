#ifndef __MATRIZ_H__
#define __MATRIZ_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

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
** Imprime la matriz completa en pantalla
*/
void matriz_mostrar(Matriz *matriz);

/*
** Intercambia dos filas dadas
*/
Matriz *matriz_intercambiar_filas(Matriz *matriz, size_t fil1, size_t fil2);

/*
** Agrega una nueva fila en una posicion dada
*/
Matriz *matriz_insertar_fila(Matriz *matriz, size_t fil); 
// Falta el argumento de agregar una nueva fila

#endif /* __MATRIZ_H__ */
