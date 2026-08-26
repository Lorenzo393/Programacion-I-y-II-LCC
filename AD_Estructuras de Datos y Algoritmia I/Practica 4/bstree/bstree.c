#include "bstree.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

BSTree bstree_crear(){
    return NULL;
}
void bstree_destruir(BSTree arbol, FuncionDestructora destroy){
    while(arbol != NULL){
        bstree_destruir(arbol->izq, destroy);
        bstree_destruir(arbol->der, destroy);
        destroy(arbol->dato);
        free(arbol);
    }
}
int bstree_buscar_dato(BSTree arbol, void *dato, FuncionComparadora comp){
    if(arbol == NULL)
        return -1;
    else if(comp(dato, arbol->dato) < 0)
        return bstree_buscar_dato(arbol->izq, dato, comp);
    else if(comp(dato, arbol->dato) > 0)
        return bstree_buscar_dato(arbol->der, dato, comp);
    return 1;
}
BSTree bstree_buscar_nodo(BSTree arbol, void *dato, FuncionComparadora comp){
    if(arbol == NULL)
        return NULL;
    else if(comp(dato, arbol->dato) < 0)
        return bstree_buscar_nodo(arbol->izq, dato, comp);
    else if(comp(dato, arbol->dato) > 0)
        return bstree_buscar_nodo(arbol->der, dato, comp);
    return arbol;
}

BSTree bstree_insertar(BSTree arbol, void *dato, FuncionCopiadora copy, FuncionComparadora comp){
    if(arbol == NULL){
        BSTNodo *nuevoNodo = malloc(sizeof(BSTNodo));
        assert(nuevoNodo != NULL);
        nuevoNodo->dato = copy(dato);
        nuevoNodo->izq = nuevoNodo->der = NULL;
        return nuevoNodo;
    }
    else if (comp(dato, arbol->dato) < 0)
        arbol->izq = bstree_insertar(arbol->izq, dato, copy, comp);
    else if(comp(dato, arbol->dato) > 0)
        arbol->der =  bstree_insertar(arbol->der, dato, copy, comp);
    return arbol;
}
void bstree_recorrer_bfs(BSTree arbol, FuncionVisitante visit, FuncionCopiadora copy, FuncionDestructora destroy){
    Cola cola = cola_crear();
    cola = cola_encolar(cola, copy, arbol);
    while(!cola_es_vacia(cola)){
        visit(cola_inicio(cola));

        BSTNodo *nodoAux = cola_inicio(cola);
        if(nodoAux->izq != NULL)
            cola = cola_encolar(cola, copy, nodoAux->izq);
        if(nodoAux->der != NULL)
            cola = cola_encolar(cola, copy, nodoAux->der);
        cola = cola_desencolar(cola, destroy);
    }
    printf("\n");
}

void bstree_recorrer_preorden(BSTree arbol, FuncionVisitante visit){
    if(arbol == NULL)
        return ;
    visit(arbol);
    bstree_recorrer_preorden(arbol->izq, visit);
    bstree_recorrer_preorden(arbol->der, visit);
}
void bstree_recorrer_inorden(BSTree arbol, FuncionVisitante visit){
    if(arbol == NULL)
        return ;
    bstree_recorrer_preorden(arbol->izq, visit);
    visit(arbol);
    bstree_recorrer_preorden(arbol->der, visit);
}
void bstree_recorrer_postorden(BSTree arbol, FuncionVisitante visit){
    if(arbol == NULL)
        return ;
    bstree_recorrer_preorden(arbol->izq, visit);
    bstree_recorrer_preorden(arbol->der, visit);
    visit(arbol);
}

// BSTree bstree_eliminar(BSTree arbol, void *dato, FuncionComparadora comp, FuncionCopiadora copy, FuncionDestructora destroy){
//     BSTNodo *nodoAEliminar = bstree_buscar_nodo(arbol, dato, comp);
//     if(nodoAEliminar == NULL)
//         return arbol;

//     if(nodoAEliminar->izq != NULL){
//         BSTNodo *nodoReemplazo = nodoAEliminar->izq;
//         while(nodoReemplazo->der != NULL)
//             nodoReemplazo = nodoReemplazo->der;
//         *(int *)nodoAEliminar->dato = *(int *)nodoReemplazo->dato;
//         destroy(nodoReemplazo->dato);
//         free(nodoReemplazo);
//         nodoReemplazo = NULL;
//         return arbol;
//     }
//     else if(nodoAEliminar->der != NULL){
//         destroy(nodoAEliminar->dato);
//         nodoAEliminar = nodoAEliminar->der;
//         return arbol;
//     }
//     destroy(nodoAEliminar->dato);
//     free(nodoAEliminar);
//     nodoAEliminar = NULL;
//     return arbol;
// }
int bstree_es_vacio(BSTree arbol){
    return arbol == NULL;
}
BSTree bstree_menor(BSTree arbol){
    if(arbol == NULL)
        return NULL;
    while(arbol->izq != NULL)
        arbol = arbol->izq;
    return arbol;
}

BSTree bstree_eliminar_aux(BSTree arbol, FuncionCopiadora copiar, FuncionComparadora comparar, FuncionDestructora destruir) {
    destruir(arbol->dato);

    if(bstree_es_vacio(arbol->izq) || bstree_es_vacio(arbol->der)) {
        BSTree reemplazo = bstree_es_vacio(arbol->izq) ? arbol->der : arbol->izq;
        free(arbol);
        return reemplazo;
    }

    BSTNodo* candidato = bstree_menor(arbol->der);
    arbol->dato = copiar(candidato->dato);
    arbol->der = bstree_eliminar(arbol->der, candidato->dato, copiar, comparar, destruir);
    return arbol;
}


BSTree bstree_eliminar(BSTree arbol, void *dato, FuncionCopiadora copiar,
    FuncionComparadora comparar, FuncionDestructora destruir) {
    if(bstree_es_vacio(arbol))
        return arbol;

    if(comparar(dato, arbol->dato) == 0)
        return bstree_eliminar_aux(arbol, copiar, comparar, destruir);

    if(comparar(dato, arbol->dato) == 1)
        arbol->der = bstree_eliminar(arbol->der, dato, copiar, comparar, destruir);

    if(comparar(dato, arbol->dato) == -1)
        arbol->izq = bstree_eliminar(arbol->izq, dato, copiar, comparar, destruir);

    return arbol;
}

void *bstree_k_esimo_menor_aux(BSTree arbol, int *k) {
    if (bstree_es_vacio(arbol))
        return NULL;
    void *dato;
    dato = bstree_k_esimo_menor_aux(arbol->izq, k);
    if (dato != NULL)
        return dato;
    if (*k == 0)
        return arbol->dato;
    --(*k);
    return bstree_k_esimo_menor_aux(arbol->der, k);
}

void *bstree_k_esimo_menor(BSTree arbol, int k) {
    return bstree_k_esimo_menor_aux(arbol, &k);
}
// Basicamente la funcion busca el primero, segundo, tercero, etc. menor 
// elemento del arbol

int es_abb_aux(BSTree arbol, void **anterior, FuncionComparadora comp){
    if(arbol == NULL)
        return 1;

    if(!es_abb_aux(arbol->izq, anterior, comp))
        return -1;

    if(*anterior != NULL && comp(*anterior, arbol->dato) >= 0)
        return -1;

    *anterior = arbol->dato;

    return es_abb_aux(arbol->der, anterior, comp);
}

int bstree_es_abb(BSTree arbol, FuncionComparadora comp){
    void *anterior = NULL;
    return es_abb_aux(arbol, &anterior, comp);
}