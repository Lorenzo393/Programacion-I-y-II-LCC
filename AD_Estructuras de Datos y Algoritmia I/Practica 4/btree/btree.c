#include "btree.h"


BTree btree_crear() { return NULL; }

void btree_destruir(BTree nodo) {
  if (nodo != NULL) {
    btree_destruir(nodo->left);
    btree_destruir(nodo->right);
    free(nodo);
  }
}
int btree_empty(BTree nodo) { return nodo == NULL; }

BTree btree_unir(int dato, BTree left, BTree right) {
    BTree nuevoNodo = malloc(sizeof(struct _BTNodo));
    assert(nuevoNodo != NULL);
    nuevoNodo->dato = dato;
    nuevoNodo->left = left;
    nuevoNodo->right = right;
    return nuevoNodo;
}

void recorrido_pre(BTree arbol, FuncionVisitante visit){
    if(arbol == NULL)
        return ;
    visit(arbol->dato);
    recorrido_pre(arbol->left, visit);
    recorrido_pre(arbol->right, visit);
}

void recorrido_in(BTree arbol, FuncionVisitante visit){
    if(arbol == NULL)
        return ;
    recorrido_in(arbol->left, visit);
    visit(arbol->dato);
    recorrido_in(arbol->right, visit);
}

void recorrido_post(BTree arbol, FuncionVisitante visit){
    if(arbol == NULL)
        return ;
    recorrido_post(arbol->left, visit);
    recorrido_post(arbol->right, visit);
    visit(arbol->dato);
}

void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitante visit) {
    if(arbol != NULL){
        switch(orden){
            case BTREE_RECORRIDO_IN:
                recorrido_in(arbol, visit);
                break;
            case BTREE_RECORRIDO_PRE:
                recorrido_pre(arbol, visit);
                break;
            case BTREE_RECORRIDO_POST:
                recorrido_post(arbol, visit);
                break;
        }
    }
    printf("\n");
}

void btree_recorrido_itPre(BTree arbol, FuncionVisitante visit, FuncionCopia copy, FuncionDestructora destroy){
    Pila pila = pila_crear();
    pila = pila_apilar(pila, arbol, copy);
    while(pila != NULL){
        BTNodo *nodo = pila_tope(pila);
        visit(nodo->dato);

        BTNodo *nodoIzq = nodo->left;
        BTNodo *nodoDer = nodo->right;

        pila = pila_desapilar(pila, destroy);
        if(nodoDer != NULL)
            pila = pila_apilar(pila, nodoDer, copy);
        if(nodoIzq != NULL)
            pila = pila_apilar(pila, nodoIzq, copy);
    }
    printf("\n");
}

void btree_recorrido_itIn(BTree arbol, FuncionVisitante visit, FuncionCopia copy, FuncionDestructora destroy){
    Pila pila = pila_crear();
    pila = pila_apilar(pila, arbol, copy);
    while(pila != NULL){
        BTNodo *nodo = pila_tope(pila);
        visit(nodo->dato);

        BTNodo *nodoIzq = nodo->left;
        BTNodo *nodoDer = nodo->right;

        pila = pila_desapilar(pila, destroy);
        if(nodoIzq != NULL)
            pila = pila_apilar(pila, nodoIzq, copy);
        if(nodoDer != NULL)
            pila = pila_apilar(pila, nodoDer, copy);
    }
    printf("\n");
}

int btree_nnodos_R(BTree arbol){
    if(arbol == NULL)
        return 0;
    return btree_nnodos_R(arbol->left) + btree_nnodos_R(arbol->right) + 1;
}
int btree_buscar_R(BTree arbol, int dato){
    if(arbol == NULL)
        return 0;
    if(arbol->dato == dato)
        return 1;
    return btree_buscar_R(arbol->left, dato) + btree_buscar_R(arbol->right, dato);
}
BTree btree_copiar_R(BTree arbol){
    if(arbol == NULL)
        return NULL;
    return btree_unir(arbol->dato, arbol->left, arbol->right);
}
int btree_altura_R(BTree arbol){
    if(arbol == NULL)
        return -1;
    int alturaIzq = btree_altura_R(arbol->left);
    int alturaDer = btree_altura_R(arbol->left);

    if (alturaIzq > alturaDer)
        return alturaIzq + 1;
    return alturaDer + 1;
}
int btree_nnodos_profundidad_R(BTree arbol, int profundidad){
    if(arbol == NULL)
        return 0;
    if(profundidad == 0)
        return 1;
    return btree_nnodos_profundidad_R(arbol->left, profundidad - 1) + btree_nnodos_profundidad_R(arbol->right, profundidad - 1);
}
int btree_profundidad_R(BTree arbol, int dato){
    if(arbol == NULL)
        return -1;
    if(arbol->dato == dato)
        return 0;

    int profundidadIzq = btree_profundidad_R(arbol->left, dato);
    if(profundidadIzq != -1)
        return profundidadIzq + 1;

    int profundidadDer = btree_profundidad_R(arbol->right, dato);
    if(profundidadDer != -1)
        return profundidadDer + 1;
    return -1;
}
int btree_sumar_R(BTree arbol){
    if(arbol == NULL)
        return 0;
    return arbol->dato + btree_sumar_R(arbol->left) + btree_sumar_R(arbol->right);
}

void btree_recorrer_extra(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitanteExtra visit, void *extra){
    switch (orden)
    {
    case BTREE_RECORRIDO_IN:
        btree_recorrer_inorden_e(arbol, visit, extra);
        break;

    case BTREE_RECORRIDO_PRE:
        btree_recorrer_preorden_e(arbol, visit, extra);
        break;

    case BTREE_RECORRIDO_POST:
        btree_recorrer_postorden_e(arbol, visit, extra);
        break;
    }
    printf("\n");
}

void btree_recorrer_inorden_e(BTree arbol, FuncionVisitanteExtra visit, void *extra){
    if(arbol == NULL)
        return ;
    btree_recorrer_inorden_e(arbol->left, visit, extra);
    visit(arbol->dato, extra);
    btree_recorrer_inorden_e(arbol->right, visit, extra);
}

void btree_recorrer_preorden_e(BTree arbol, FuncionVisitanteExtra visit, void *extra){
    if(arbol == NULL)
        return ;
    visit(arbol->dato, extra);
    btree_recorrer_preorden_e(arbol->left, visit, extra);
    btree_recorrer_preorden_e(arbol->right, visit, extra);
}

void btree_recorrer_postorden_e(BTree arbol, FuncionVisitanteExtra visit, void *extra){
    if(arbol == NULL)
        return ;
    btree_recorrer_postorden_e(arbol->left, visit, extra);
    btree_recorrer_postorden_e(arbol->right, visit, extra);
    visit(arbol->dato, extra);
}

void btree_visitar_profundidad(BTree arbol, FuncionVisitante visit, int profundidad){
    if(arbol == NULL)
        return ;
    if(profundidad == 0)
        visit(arbol->dato);
    btree_visitar_profundidad(arbol->left, visit, profundidad - 1);
    btree_visitar_profundidad(arbol->right, visit, profundidad - 1);
}

void btree_recorrer_bfs_r(BTree arbol, FuncionVisitante visit){
    for(int i = 0 ; i < (btree_altura_R(arbol) + 1); i++){
        btree_visitar_profundidad(arbol, visit, i);
    }
}
void btree_recorrer_bfs_i(BTree arbol, FuncionVisitante2 visit, FuncionCopia copy, FuncionDestructora destroy){
    Cola cola = cola_crear();
    cola = cola_encolar(cola, copy, arbol);
    while(!cola_es_vacia(cola)){
        visit(cola_inicio(cola));

        BTNodo *arbolAux = cola.primero->dato;

        if(arbolAux->left != NULL)
            cola = cola_encolar(cola, copy, arbolAux->left);
        if(arbolAux->right != NULL)
            cola = cola_encolar(cola, copy, arbolAux->right);

        cola = cola_desencolar(cola, destroy);
    }
    printf("\n");
}