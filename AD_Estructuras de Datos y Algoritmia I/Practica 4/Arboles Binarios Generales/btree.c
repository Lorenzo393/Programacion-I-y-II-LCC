#include "btree.h"

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear() { return NULL; }

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo, FuncionDestructora destroy) {
    if (nodo != NULL) {
        btree_destruir(nodo->left, destroy);
        btree_destruir(nodo->right, destroy);
        destroy(nodo->dato);
        free(nodo);
    }
}

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo) { return nodo == NULL; }

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(void *dato, BTree left, BTree right, FuncionCopia copy) {
    BTree nuevoNodo = malloc(sizeof(struct _BTNodo));
    assert(nuevoNodo != NULL);
    nuevoNodo->dato = copy(dato);
    nuevoNodo->left = left;
    nuevoNodo->right = right;
    return nuevoNodo;
}

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void recorrido_pre(BTree arbol, FuncionVisitante visit){
    if(arbol != NULL)
        visit(arbol->dato);
    if(arbol->left)
        recorrido_pre(arbol->left, visit);
    if(arbol->right)
        recorrido_pre(arbol->right, visit);
}
void recorrido_in(BTree arbol, FuncionVisitante visit){
    if(arbol->left)
        recorrido_in(arbol->left, visit);
    if(arbol != NULL)
        visit(arbol->dato);
    if(arbol->right)
        recorrido_in(arbol->right, visit);
}
void recorrido_post(BTree arbol, FuncionVisitante visit){
    if(arbol->left)
        recorrido_post(arbol->left, visit);
    if(arbol->right)
        recorrido_post(arbol->right, visit);
    if(arbol != NULL)
        visit(arbol->dato);
}

void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitante visit) {
    if(arbol == NULL)
        return ;
    switch(orden){
        case BTREE_RECORRIDO_PRE:
            recorrido_pre(arbol, visit);
            break;
        case BTREE_RECORRIDO_IN:
            recorrido_in(arbol, visit);
            break;
        case BTREE_RECORRIDO_POST:
            recorrido_post(arbol, visit);
            break;
        default:

            break;
    }
}