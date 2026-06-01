#include "pilageneral.h"
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

// EJ 2
// a
/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrido_inorder(BTree arbol, FuncionVisitante visit){
	if(arbol->left != NULL)
		btree_recorrido_inorder(arbol->left, visit);
	
	if(arbol != NULL)
		visit(arbol->dato);

	if(arbol->right != NULL)
		btree_recorrido_inorder(arbol->right, visit);
}
void btree_recorrido_preorder(BTree arbol, FuncionVisitante visit){
	if(arbol != NULL)
		visit(arbol->dato);

	if(arbol->left != NULL)
		btree_recorrido_preorder(arbol->left, visit);

	if(arbol->right != NULL)
		btree_recorrido_preorder(arbol->right, visit);

	
}
void btree_recorrido_postorder(BTree arbol, FuncionVisitante visit){
	if(arbol->left != NULL)
		btree_recorrido_postorder(arbol->left, visit);

	if(arbol->right != NULL)
		btree_recorrido_postorder(arbol->right, visit);

	if(arbol != NULL)
		visit(arbol->dato);
}
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitante visit){
	if(arbol == NULL)
		return;

	switch(orden){
		case BTREE_RECORRIDO_IN:
			btree_recorrido_inorder(arbol, visit);
			break;
		case BTREE_RECORRIDO_PRE:
			btree_recorrido_preorder(arbol, visit);
			break;
		case BTREE_RECORRIDO_POST:
			btree_recorrido_postorder(arbol, visit);
			break;
		default:
			printf("error");
			break;
	}
	printf("\n");
}
// c
void btree_recorrer_pre_it(BTree arbol, FuncionVisitante visit, FuncionCopia no_copia, FuncionDestructora no_destruir) {
	Pila pilaNodos = pila_crear();
	pilaNodos = pila_apilar(pilaNodos, arbol, no_copia);

  	while(!pila_es_vacia(pilaNodos)) {
		BTree nodo_actual = pila_tope(pilaNodos);
		
		visit(nodo_actual->dato);

		pilaNodos = pila_desapilar(pilaNodos, no_destruir);

		if (!btree_empty(nodo_actual->right))
		pilaNodos = pila_apilar(pilaNodos, nodo_actual->right, no_copia);

		if (!btree_empty(nodo_actual->left))
		pilaNodos = pila_apilar(pilaNodos, nodo_actual->left, no_copia);
  	}

  	pila_destruir(pilaNodos, no_destruir);
}

void btree_recorrer_post_it(BTree arbol, FuncionVisitante visit, FuncionCopia no_copia, FuncionDestructora no_destruir) {
	Pila pilaNodos = pila_crear();
	pilaNodos = pila_apilar(pilaNodos, arbol, no_copia);

  	while(!pila_es_vacia(pilaNodos)) {
		BTree nodo_actual = pila_tope(pilaNodos);
		visit(nodo_actual->dato);
		pilaNodos = pila_desapilar(pilaNodos, no_destruir);

		if (!btree_empty(nodo_actual->right))
		pilaNodos = pila_apilar(pilaNodos, nodo_actual->right, no_copia);

		if (!btree_empty(nodo_actual->left))
		pilaNodos = pila_apilar(pilaNodos, nodo_actual->left, no_copia);

			
		
  	}

  	pila_destruir(pilaNodos, no_destruir);
}

void btree_recorrer_it(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitante visit, FuncionCopia no_copia, FuncionDestructora no_destruir){
	if(arbol == NULL)
		return;

	switch(orden){
		case BTREE_RECORRIDO_IN:
			//btree_recorrer_in_it(arbol, visit, no_copia, no_destruir);
			break;
		case BTREE_RECORRIDO_PRE:
			btree_recorrer_pre_it(arbol, visit, no_copia, no_destruir);
			break;
		case BTREE_RECORRIDO_POST:
			btree_recorrer_post_it(arbol, visit, no_copia, no_destruir);
			break;
		default:
			printf("error");
			break;
	}
	printf("\n");
}


// EJ 3
// a
int btree_nnodos(BTree arbol){
	if(arbol == NULL)
		return 0;
	return btree_nnodos(arbol->left) + btree_nnodos(arbol->right) + 1;
}

int btree_nnodos_it(BTree arbol, FuncionCopia no_copy, FuncionDestructora no_destroy){
	Pila pila = pila_crear();
	pila = pila_apilar(pila, arbol, no_copy);
	int cant = 0;

	while(!pila_es_vacia(pila)){
		BTNodo *nodo = pila_tope(pila);
		pila = pila_desapilar(pila, no_destroy);

		cant++;

		if(nodo->right != NULL)
			pila = pila_apilar(pila, nodo->right, no_copy);
		if(nodo->left != NULL)
			pila = pila_apilar(pila, nodo->left, no_copy);
	}

	pila_destruir(pila, no_destroy);
	return cant;
}

// b
int btree_buscar(BTree arbol, int dato){
	if(arbol == NULL)
		return 0;
	if(arbol->dato == dato)
		return 1;
	return btree_buscar(arbol->left, dato) + btree_buscar(arbol->right, dato);
}

int btree_buscar_it(BTree arbol, int dato, FuncionCopia no_copy, FuncionDestructora no_destroy){
	Pila pila = pila_crear();
	pila = pila_apilar(pila, arbol, no_copy);
	int flag = 1;

	while(!pila_es_vacia(pila) && flag){
		BTNodo *nodo = pila_tope(pila);
		pila = pila_desapilar(pila, no_destroy);

		if(nodo->dato == dato)
			flag = 0;
		if(nodo->right != NULL)
			pila = pila_apilar(pila, nodo->right, no_copy);
		if(nodo->left != NULL)
			pila = pila_apilar(pila, nodo->left, no_copy);
	}

	pila_destruir(pila, no_destroy);
	return flag == 0? 1 : 0;
}

// c
BTree btree_copiar(BTree arbol){
	if(arbol == NULL)
		return NULL;
	return btree_unir(arbol->dato, btree_copiar(arbol->left), btree_copiar(arbol->right));
}

BTree btree_copiar_it(BTree arbol, FuncionCopia copy, FuncionCopia no_copy, FuncionDestructora no_destroy);

// d
int btree_altura(BTree arbol){
	if(arbol == NULL)
		return -1;
	int altura_izq = btree_altura(arbol->left);
	int altura_der = btree_altura(arbol->right);
	int max = (altura_der > altura_izq) ? altura_der : altura_izq;
	return max + 1;
}

// e
int btree_nnodos_profundidad(BTree arbol, int profundidad){
	if(arbol == NULL)
		return 0;
	if(profundidad == 0)
		return 1;
	return btree_nnodos_profundidad(arbol->left, profundidad - 1) + btree_nnodos_profundidad(arbol->right, profundidad - 1);
}

// f
int btree_profundidad(BTree arbol, int dato){
	if (arbol == NULL)
        return -1;

    if (arbol->dato == dato)
        return 0;

    int profIzq = btree_profundidad(arbol->left, dato);

    if (profIzq != -1)
        return profIzq + 1;

    int profDer = btree_profundidad(arbol->right, dato);

    if (profDer != -1)
        return profDer + 1;

    return -1;
}

// g
int btree_sumar(BTree arbol){
	if(arbol == NULL)
		return 0;
	return arbol->dato + btree_sumar(arbol->left) + btree_sumar(arbol->right);
}

// EJ 4
void btree_recorrido_inorder_extra(BTree arbol, FuncionVisitanteExtra visit, void *extra){
	if(arbol->left != NULL)
		btree_recorrido_inorder_extra(arbol->left, visit, extra);
	if(arbol != NULL)
		visit(arbol->dato, extra);
	if(arbol->right != NULL)
		btree_recorrido_inorder_extra(arbol->right, visit, extra);
}
void btree_recorrido_preorder_extra(BTree arbol, FuncionVisitanteExtra visit, void *extra){
	if(arbol != NULL)
		visit(arbol->dato, extra);
	if(arbol->left != NULL)
		btree_recorrido_preorder_extra(arbol->left, visit, extra);
	if(arbol->right != NULL)
		btree_recorrido_preorder_extra(arbol->right, visit, extra);
}
void btree_recorrido_postorder_extra(BTree arbol, FuncionVisitanteExtra visit, void *extra){
	if(arbol->left != NULL)
		btree_recorrido_postorder_extra(arbol->left, visit, extra);
	if(arbol->right != NULL)
		btree_recorrido_postorder_extra(arbol->right, visit, extra);
	if(arbol != NULL)
		visit(arbol->dato, extra);
}

void btree_recorrer_extra(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitanteExtra visit, void *extra){
	if(arbol == NULL)
		return ;

	switch(orden){
		case BTREE_RECORRIDO_IN:
			btree_recorrido_inorder_extra(arbol, visit, extra);
			break;
		case BTREE_RECORRIDO_PRE:
			btree_recorrido_preorder_extra(arbol, visit, extra);
			break;
		case BTREE_RECORRIDO_POST:
			btree_recorrido_postorder_extra(arbol, visit, extra);
			break;
		default:
			printf("error");
			break;
	}
	printf("\n");
}