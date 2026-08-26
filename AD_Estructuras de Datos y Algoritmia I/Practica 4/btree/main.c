#include "btree.h"

void imprimir_entero(int data) {
    printf("%d ", data);
}

void imprimir_nodo(void *data){
    BTNodo *nodo = ((BTNodo *) data);
    printf("%i ",nodo->dato);
}

void *copiar_nodo(void *dato){
    BTNodo *nodo = malloc(sizeof(BTNodo));
    *nodo = (*(BTNodo *)dato);
    return nodo;
}

void visitar_extra(int dato, void *extra){
    printf("%i,%i ", dato, (*(int *)extra));
}

void destruir_nodo(void *dato){
    free(dato);
}

int main() {
    BTree ll = btree_unir(1, btree_crear(), btree_crear());
    BTree l = btree_unir(2, ll, btree_crear());
    BTree r = btree_unir(3, btree_crear(), btree_crear());
    BTree arbol = btree_unir(4, l, r);

    // btree_recorrer(arbol, BTREE_RECORRIDO_PRE, imprimir_entero);
    // btree_recorrer(arbol, BTREE_RECORRIDO_IN, imprimir_entero);
    // btree_recorrer(arbol, BTREE_RECORRIDO_POST, imprimir_entero);
    // btree_recorrido_itPre(arbol, imprimir_entero, copiar_nodo, destruir_nodo);
    // btree_recorrido_itIn(arbol, imprimir_entero, copiar_nodo, destruir_nodo);

    // printf("%i",btree_nnodos_R(arbol));
    // printf("%i",btree_buscar_R(arbol,0));
    // BTree arbol2 = btree_copiar_R(arbol);
    // btree_recorrer(arbol2, BTREE_RECORRIDO_POST, imprimir_entero);
    // printf("%i",btree_altura_R(arbol));
    // printf("%i",btree_nnodos_profundidad_R(arbol, 3));
    // printf("%i", btree_profundidad_R(arbol,5));
    // printf("%i",btree_sumar_R(arbol));
    // int *extra = malloc(sizeof(int));
    // *extra = 0;
    // btree_recorrer_extra(arbol, BTREE_RECORRIDO_IN, visitar_extra, extra);
    //btree_recorrer_bfs_r(arbol, imprimir_entero);
    btree_recorrer_bfs_i(arbol, imprimir_nodo, copiar_nodo, destruir_nodo);

    btree_destruir(arbol);
    return 0;
}
