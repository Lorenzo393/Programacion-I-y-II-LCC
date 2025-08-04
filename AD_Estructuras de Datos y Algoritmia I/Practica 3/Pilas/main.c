#include "pilasgenerales.h"
// #include "pilaenteros.h"
#include "glist.h"

#include <stdlib.h>
#include <stdio.h>

void imprimir_entero(void *dato){
    printf("%i ", *(int *)dato);
}

void destruir_dato(void *dato){
    free(dato);
}

int *copiar_entero(void *dato){
    int *copia = malloc(sizeof(int));
    *copia = *(int *)dato;
    return copia;
}

// EJ 3 Creo que no es correcto retornar la pila
GList glist_invertir_lista(GList lista, FuncionCopia copy, FuncionDestructora destroy){
    Pila pila = pila_crear();
    while(lista != NULL){
        GNode *nodoADestruir = lista;
        lista = lista->next;

        pila = pila_apilar(pila, nodoADestruir->data, copy);
        destroy(nodoADestruir->data);
        free(nodoADestruir);
    }

    return pila;
}

int main(){
    // EJ 1
    // Pila pila = pila_crear(10);
    
    // pila_apilar(pila,1);
    // pila_apilar(pila,2);
    // pila_apilar(pila,3);
    // pila_apilar(pila,4);
    // pila_apilar(pila,5);

    // pila_imprimir(pila);

    // pila_desapilar(pila);
    // pila_desapilar(pila);
    // pila_apilar(pila,9);

    // pila_imprimir(pila);

    // printf("%i\n",pila_tope(pila));


    // if(pila_es_vacia(pila)) printf("La pila esta vacia");
    // else printf("La pila no esta vacia");

    // pila_destruir(pila);

    // EJ 2
    int *arr = malloc(sizeof(int) * 5);
    arr[0] = 5;
    arr[1] = 4;
    arr[2] = 3;
    arr[3] = 2;
    arr[4] = 1;
    Pila pila = pila_crear();
    pila = pila_apilar(pila, &arr[0], (FuncionCopia)copiar_entero);
    pila = pila_apilar(pila, &arr[1], (FuncionCopia)copiar_entero);
    pila = pila_apilar(pila, &arr[2], (FuncionCopia)copiar_entero);
    pila = pila_apilar(pila, &arr[3], (FuncionCopia)copiar_entero);
    pila = pila_apilar(pila, &arr[4], (FuncionCopia)copiar_entero);

    pila_imprimir(pila, (FuncionVisitante)imprimir_entero);

    printf("%i\n",*(int *) pila_tope(pila));
    pila = pila_desapilar(pila, (FuncionDestructora)destruir_dato);
    printf("%i\n",*(int *) pila_tope(pila));
    pila = pila_desapilar(pila, (FuncionDestructora)destruir_dato);
    printf("%i\n",*(int *) pila_tope(pila));

    pila_imprimir(pila, (FuncionVisitante)imprimir_entero);

    if(pila_es_vacia(pila)) printf("La pila esta vacia\n");
    else printf("La pila no esta vacia\n");

    GList lista = NULL;
    lista = glist_agregar_inicio(lista, &arr[0], (FuncionCopia)copiar_entero);
    lista = glist_agregar_inicio(lista, &arr[1], (FuncionCopia)copiar_entero);
    lista = glist_agregar_inicio(lista, &arr[2], (FuncionCopia)copiar_entero);
    lista = glist_agregar_inicio(lista, &arr[3], (FuncionCopia)copiar_entero);
    lista = glist_agregar_inicio(lista, &arr[4], (FuncionCopia)copiar_entero);

    printf("Lista normal:\n");
    glist_recorrer(lista, (FuncionVisitante)imprimir_entero);
    printf("\n");
    
    lista = glist_invertir_lista(lista, (FuncionCopia)copiar_entero, (FuncionDestructora)destruir_dato);
    
    printf("Lista invertida:\n");
    glist_recorrer(lista, (FuncionVisitante)imprimir_entero);
    printf("\n");

    pila_destruir(pila, (FuncionDestructora)destruir_dato);

    return 0;
}