#ifndef __ARREGLOENTEROS_H__
#define __ARREGLOENTEROS_H__

#define MULT_CAPACIDAD 2

typedef struct {
    int *enteros;
    int capacidad;
}ArregloEnteros;

/**
 * Crea un arreglo de enteros con una capacidad dada.
 */
ArregloEnteros *arreglo_enteros_crear(int len);

/**
 * Libera la memoria de un arreglo de enteros.
 */
void arreglo_enteros_destruir(ArregloEnteros *arregloEnteros);

/**
 * Retorna el elemento de la posicion dada de un arreglo de enteros.
 */
int arreglo_enteros_devolver_posicion(ArregloEnteros *arregloEnteros, int pos);

/**
 * Retorna 1 si la posicion del ultimo elemento es mayor a la capacidad del arreglo
 * y 0 en caso contrario.
 */
int arreglo_enteros_capacidad_excedida(ArregloEnteros *arregloEnteros, int ultimaPosInsertar);

/**
 * Duplica la capacidad de un arreglo de enteros.
 */
ArregloEnteros *arreglo_enteros_ajustar(ArregloEnteros *arregloEnteros);

/**
 * Agrega un elemento al arreglo de enteros en la posicion dada.
 */
ArregloEnteros *arreglo_enteros_insertar_elemento(ArregloEnteros *arregloEnteros, int dato, int pos);

/**
 * Imprime un elemento del arreglo de enteros dada su posicion.
 */
void arreglo_enteros_imprimir_posicion(ArregloEnteros *arregloEnteros, int pos);

#endif /* __ARREGLOENTEROS_H__ */