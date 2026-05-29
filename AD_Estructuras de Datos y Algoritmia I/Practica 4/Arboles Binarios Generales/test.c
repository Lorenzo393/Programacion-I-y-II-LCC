#include "btree.h"

static void imprimir_entero(void *data) {
  printf("%i ", (* (int *) data));
}
void *copiar_entero(void *dato){
    int *entero = malloc(sizeof(int));
    *entero = (* (int *) dato);
    return entero;
}
void destruir_entero(void *dato){
    free(dato);
}

int main() {
    int *arr = malloc(sizeof(int) * 4);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;

    BTree ll = btree_unir(&arr[0], btree_crear(), btree_crear(), (FuncionCopia)copiar_entero);
    BTree l = btree_unir(&arr[1], ll, btree_crear(), (FuncionCopia)copiar_entero);
    BTree r = btree_unir(&arr[2], btree_crear(), btree_crear(), (FuncionCopia)copiar_entero);
    BTree raiz = btree_unir(&arr[3], l, r, (FuncionCopia)copiar_entero);
    
    btree_recorrer(raiz, BTREE_RECORRIDO_POST, imprimir_entero);
    btree_destruir(raiz, (FuncionDestructora) destruir_entero);

    return 0;
}
