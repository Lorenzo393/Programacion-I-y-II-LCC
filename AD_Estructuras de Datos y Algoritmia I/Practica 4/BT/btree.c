#include "btree.h"

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear() { return NULL; }

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo) {
	if (nodo != NULL) {
		btree_destruir(nodo->left);
		btree_destruir(nodo->right);
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
BTree btree_unir(int dato, BTree left, BTree right) {
	BTree nuevoNodo = malloc(sizeof(struct _BTNodo));
	assert(nuevoNodo != NULL);
	nuevoNodo->dato = dato;
	nuevoNodo->left = left;
	nuevoNodo->right = right;
	return nuevoNodo;
}


void btree_recorrer_pre(BTree arbol, FuncionVisitante visit){
	if(arbol != NULL)
		visit(arbol->dato);
	if(arbol->left != NULL)
		btree_recorrer_pre(arbol->left, visit);
	if(arbol->right != NULL)
		btree_recorrer_pre(arbol->right, visit);
}

void btree_recorrer_in(BTree arbol, FuncionVisitante visit){
	if(arbol->left != NULL)
		btree_recorrer_in(arbol->left, visit);
	if(arbol != NULL)
		visit(arbol->dato);
	if(arbol->right != NULL)
		btree_recorrer_in(arbol->right, visit);
}

void btree_recorrer_post(BTree arbol, FuncionVisitante visit){
	if(arbol->left != NULL)
		btree_recorrer_post(arbol->left, visit);
	if(arbol->right != NULL)
		btree_recorrer_post(arbol->right, visit);
	if(arbol != NULL)
		visit(arbol->dato);
}

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitante visit){
	if(btree_empty(arbol))
		return ;
	switch (orden){
		case BTREE_RECORRIDO_PRE:
			btree_recorrer_pre(arbol, visit);
			break;
		case BTREE_RECORRIDO_IN:
			btree_recorrer_in(arbol, visit);
			break;
		case BTREE_RECORRIDO_POST:
			btree_recorrer_post(arbol, visit);
			break;
  
		default:
    		printf("error");
			break;
	}
}