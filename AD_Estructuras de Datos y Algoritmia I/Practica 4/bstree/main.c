#include "bstree.h"
#include <stdlib.h>
#include <stdio.h>

void *copiar_entero(void *entero){
    int *datoInt = malloc(sizeof(int));
    *datoInt = (*(int *)entero);
    return datoInt; 
}
void *copiar_nodo(void *nodo){
    BSTNodo *original = nodo;

    BSTNodo *nuevoNodo = malloc(sizeof(BSTNodo));

    nuevoNodo->dato = malloc(sizeof(int));
    *(int *)nuevoNodo->dato = *(int *)original->dato;

    nuevoNodo->izq = original->izq;
    nuevoNodo->der = original->der;

    return nuevoNodo;
}
int comparar_entero(void *dato1, void *dato2){
    int comp = 0;
    if((*(int *)dato1) > (*(int *)dato2))
        comp = 1;
    else if((*(int *)dato1) < (*(int *)dato2))
        comp = -1;
    return comp;
}
void imprimir_entero(void *dato){
    printf("%i ",(*(int *)dato));
}
void imprimir_nodo(void *nodo){
    BSTNodo *nodoAux = ((BSTNodo *)nodo);
    printf("%i ",(*(int *)nodoAux->dato));
}
void destruir_nodo(void *nodo){
    BSTNodo *nodoADestruir = ((BSTNodo *)nodo);
    free(nodoADestruir->dato);
    free(nodoADestruir);
}
void destruir_entero(void *entero){
    free(entero);
}

int main(){
    int *arr = malloc(sizeof(int) * 10);
    arr[0] = 20;
    arr[1] = 1;
    arr[2] = 15;
    arr[3] = 25;
    arr[4] = 35;
    arr[5] = 24;
    arr[6] = 2;
    arr[7] = 3;
    arr[8] = 19;
    arr[9] = 41;

    int *buscar = malloc(sizeof(int));
    *buscar = 3;
    
    BSTree arbol = bstree_crear();
    
    for(int i = 0 ; i < 10 ; i++)
        arbol = bstree_insertar(arbol, &arr[i], copiar_entero, comparar_entero);
    bstree_recorrer_bfs(arbol, imprimir_nodo, copiar_nodo, destruir_nodo);
    // bstree_eliminar(arbol, buscar,copiar_entero, comparar_entero, destruir_entero);
    // bstree_recorrer_bfs(arbol, imprimir_nodo, copiar_nodo, destruir_nodo);
    bstree_recorrer_inorden(arbol, imprimir_nodo);
    printf("\n");
    imprimir_entero(bstree_k_esimo_menor(arbol, *buscar));
    printf("%i",bstree_es_abb(arbol, comparar_entero));
    return 0;
}