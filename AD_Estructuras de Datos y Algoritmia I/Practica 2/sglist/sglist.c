#include "sglist.h"

// EJ 8
// a
SGList sglist_crear(){ return NULL; }

// b
void sglist_destruir(SGList lista, FuncionDestructora destroy){
    while(lista != NULL){
        GNode *aux = lista;
        lista = lista->next;
        destroy(aux->data);
        free(aux);
    }
}

// c
int sglist_vacia(SGList lista){ return lista != NULL; }

// d
void sglist_recorrer(GList lista, FuncionVisitante visit){
    for(GNode *it = lista ; it != NULL ; it = it->next)
        visit(it->data);
    printf("\n");
}

// e
SGList sglist_insertar(SGList lista, void *dato, FuncionCopia copy, FuncionComparadora comp){
    GNode *nuevoNodo = malloc(sizeof(GNode));
    nuevoNodo->data = copy(dato);
    nuevoNodo->next = NULL;

    if(lista == NULL)
        return nuevoNodo;
    
    if(comp(nuevoNodo->data, lista->data) > 0){
        nuevoNodo->next = lista;
        return nuevoNodo;
    }

    GNode *it = lista;
    while(it->next != NULL && comp(nuevoNodo->data, it->next->data) < 0)
        it = it->next;
    
    nuevoNodo->next = it->next;
    it->next = nuevoNodo;
    return lista;
}

// f
int sglist_buscar(GList lista, void *dato, FuncionComparadora comp){
    int esta = 0, flag = 1;
    for(GNode *it = lista ; it != NULL && flag ; it = it->next){
        if(comp(it->data, dato) == 0){
            flag = 0;
            esta = 1;
        }
    }
    return esta;
}

// g
SGList sglist_arr(void **arr, int len, FuncionCopia copy, FuncionComparadora comp){
    SGList lista = sglist_crear();
    for(int i = 0 ; i < len ; i++){
        lista = sglist_insertar(lista, arr[i], (FuncionCopia)copy, (FuncionComparadora)comp);
    }
    return lista;
}