#include "btree.h"

static void imprimir_entero(int data) {
  	printf("%d ", data);
}

int main() {
	BTree ll = btree_unir(1, btree_crear(), btree_crear());
	BTree l = btree_unir(2, ll, btree_crear());
	BTree r = btree_unir(3, btree_crear(), btree_crear());
	BTree arbol = btree_unir(4, l, r);

  	btree_recorrer(arbol, BTREE_RECORRIDO_POST, imprimir_entero);
  	
	printf("Cantidad de nodos: %i\n", btree_nnodos(arbol));
	printf("El dato esta en el arbol: %i\n", btree_buscar(arbol, 2));

	BTree copia = btree_copiar(arbol);
	printf("\n");
	btree_recorrer(copia, BTREE_RECORRIDO_POST, imprimir_entero);
	printf("La altura del arbol: %i\n", btree_altura(copia));
	printf("Cantidad de nodos a la altura: %i \n", btree_nnodos_profundidad(copia, 1));
	printf("El nodo se encuentra en la profundidad: %i\n", btree_profundidad(copia, 1));
	printf("La suma de los datos: %i\n", btree_sumar(copia));

	
	btree_destruir(arbol);

  	return 0;
}
