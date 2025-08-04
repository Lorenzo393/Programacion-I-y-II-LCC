#include "colasgenerales.h"

#include <stdlib.h>
#include <stdio.h>

void destruir_elemento(void *dato){
    free(dato);
}

void *copiar_entero(void *dato){
    int *copia = malloc(sizeof(int));
    *copia = *(int*)dato;

    return copia;
}

void imprimir_entero(void *dato){
    printf("%i ", *(int*)dato);
}

int main(){

    Cola cola = cola_crear();
    int *arr = malloc(sizeof(int) * 8);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    arr[5] = 6;
    arr[6] = 7;
    arr[7] = 8;

    for(int i = 0 ; i < 8 ; i++){
        cola = cola_encolar(cola, &arr[i], (FuncionCopia)copiar_entero);
    }

    cola_recorrer(cola, (FuncionVisitante)imprimir_entero);

    if(cola_es_vacia(cola)) printf("La cola esta vacia\n");
    else printf("La cola no esta vacia\n");

    printf("%i\n",*(int*)cola_final(cola));
    cola_desencolar(cola, (FuncionDestructora)destruir_elemento);
    cola_recorrer(cola, (FuncionVisitante)imprimir_entero);

    printf("%i\n",*(int*)cola_final(cola));
    cola_desencolar(cola, (FuncionDestructora)destruir_elemento);
    cola_recorrer(cola, (FuncionVisitante)imprimir_entero);

    printf("%i\n",*(int*)cola_final(cola));
    cola_desencolar(cola, (FuncionDestructora)destruir_elemento);
    cola_recorrer(cola, (FuncionVisitante)imprimir_entero);

    cola_destruir(cola, (FuncionDestructora)destruir_elemento);

    return 0;
}