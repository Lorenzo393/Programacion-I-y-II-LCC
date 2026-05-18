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
SGList sglist_insertar(SGList lista, void *dato, FuncionCopia copy, FuncionComparadora comp);

// f
int sglist_buscar(GList lista, void *dato, FuncionComparadora comp);

// g
SGList sglist_arr(void **arr, int long, FuncionCopia copy, FuncionComparadora comp); 