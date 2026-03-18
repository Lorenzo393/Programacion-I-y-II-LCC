#include <stdlib.h>
#include <stdio.h>

#include "sglist.h"

// EJ 8
// a
SGList sglist_crear() { return NULL; }

// b
void sglist_destruir(SGList lista, FuncionDestructora destroy){
    while(lista != NULL){
        GNode *nodoADestruir = lista;
        lista = lista->next;

        destroy(nodoADestruir->data);
        free(nodoADestruir);
    }
}

// c
int sglist_vacia(SGList lista) { return (lista == NULL); }

// d
void sglist_recorrer(SGList lista, FuncionVisitante visit){
    while(lista != NULL){
        visit(lista->data);
        lista = lista->next;
    }
}

// e
SGList sglist_insertar(SGList lista, void *data, FuncionCopia copy, FuncionComparadora compare){
    GNode *nuevoNodo = malloc(sizeof(GNode));
    nuevoNodo->data = copy(data);
    nuevoNodo->next = NULL;

    if(lista == NULL || compare(lista->data, data)){
        nuevoNodo->next = lista;
        return nuevoNodo;
    }

    GNode *recorrer = lista;
    for(; recorrer->next != NULL && !compare(recorrer->next->data, data) ; recorrer = recorrer->next);

    nuevoNodo->next = recorrer->next;
    recorrer->next = nuevoNodo;

    return lista;
}

// f
int sglist_buscar(GList lista, void *data, FuncionComparadora compare){
    int flag = 1;
    while(lista != NULL && flag){
        if(compare(lista->data, data)){
            flag = 0;
        }
        else
            lista = lista->next;
    }
    return (flag == 0);
}

// g
SGList sglist_arr(void **arr, int len, FuncionCopia copy, FuncionComparadora compare){
    SGList lista = sglist_crear();

    for(int i = 0 ; i < len ; i++){
        lista = sglist_insertar(lista, arr[i], copy, compare);
    }
    
    return lista;
}