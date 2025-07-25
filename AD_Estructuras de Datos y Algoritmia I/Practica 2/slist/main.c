#include "cdlist.h"
#include "slist.h"
#include "dlist.h"

 void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int comparar_enteros_descendiente(int a, int b){
  return a < b;
}


int main(int argc, char *argv[]) {

  // EJ 2
  // a
  // SList lista = slist_crear();
  // lista = slist_agregar_inicio(lista, 3);
  // lista = slist_agregar_inicio(lista, 2);
  // lista = slist_agregar_inicio(lista, 1);
  // lista = slist_agregar_final(lista, 4);
  // slist_recorrer(lista, imprimir_entero);
  // printf("\n%i\n",slist_longitud(lista));
  // slist_recorrer(lista, imprimir_entero);
  // slist_destruir(lista);

  // b
  // SList lista1 = slist_crear();
  // SList lista2 = slist_crear();
  // lista1 = slist_agregar_inicio(lista1, 3);
  // lista1 = slist_agregar_inicio(lista1, 2);
  // lista1 = slist_agregar_inicio(lista1, 1);
  // lista2 = slist_agregar_inicio(lista2, 4);
  // lista2 = slist_agregar_inicio(lista2, 5);
  // slist_concatenar(lista1,lista2);
  // slist_recorrer(lista1, imprimir_entero);
  // printf("\n");
  // slist_recorrer(lista2, imprimir_entero);
  // printf("\n");
  // slist_destruir(lista1);
  // slist_destruir(lista2);

  // c
  // SList lista = slist_crear();
  // lista = slist_agregar_inicio(lista,3);
  // lista = slist_agregar_inicio(lista,2);
  // lista = slist_agregar_inicio(lista,1);
  // slist_recorrer(lista,imprimir_entero);
  // printf("\n");
  // lista = slist_insertar(lista,9,4);
  // slist_recorrer(lista,imprimir_entero);
  // slist_destruir(lista);

  // d
  // SList lista = slist_crear();
  // lista = slist_agregar_inicio(lista,4);
  // lista = slist_agregar_inicio(lista,3);
  // lista = slist_agregar_inicio(lista,2);
  // lista = slist_agregar_inicio(lista,1);
  // slist_recorrer(lista,imprimir_entero);
  // printf("\n");
  // lista = slist_elimina(lista,3);
  // slist_recorrer(lista,imprimir_entero);
  // slist_destruir(lista);

  // e
  // SList lista = slist_crear();
  // lista = slist_agregar_inicio(lista,4);
  // lista = slist_agregar_inicio(lista,3);
  // lista = slist_agregar_inicio(lista,2);
  // lista = slist_agregar_inicio(lista,1);
  // slist_recorrer(lista,imprimir_entero);
  // printf("\n");
  // printf("%i",slist_contiene(lista,7));


  // f
  // SList lista = slist_crear();
  // lista = slist_agregar_inicio(lista,4);
  // lista = slist_agregar_inicio(lista,3);
  // lista = slist_agregar_inicio(lista,2);
  // lista = slist_agregar_inicio(lista,1);
  // slist_recorrer(lista,imprimir_entero);
  // printf("\n");
  // printf("%i",slist_indice(lista,4));
  // slist_destruir(lista);

  // g
  // SList lista1 = slist_crear();
  // SList lista2 = slist_crear();
  // lista1 = slist_agregar_inicio(lista1,7);
  // lista1 = slist_agregar_inicio(lista1,5);
  // lista1 = slist_agregar_inicio(lista1,3);
  // lista1 = slist_agregar_inicio(lista1,1);
  // lista2 = slist_agregar_inicio(lista2,8);
  // lista2 = slist_agregar_inicio(lista2,6);
  // lista2 = slist_agregar_inicio(lista2,1);
  // lista2 = slist_agregar_inicio(lista2,7);
  // slist_recorrer(lista1,imprimir_entero);
  // printf("\n");
  // slist_recorrer(lista2,imprimir_entero);
  // printf("\n");
  // SList listaIntersecada = slist_intersecar(lista1,lista2);
  // slist_recorrer(listaIntersecada,imprimir_entero);

  // h
  // SList lista = slist_crear();
  // lista = slist_agregar_inicio(lista,7);
  // lista = slist_agregar_inicio(lista,5);
  // lista = slist_agregar_inicio(lista,3);
  // lista = slist_agregar_inicio(lista,1);
  // lista = slist_agregar_inicio(lista,9);
  // lista = slist_agregar_inicio(lista,14);
  // lista = slist_agregar_inicio(lista,1);
  // lista = slist_agregar_inicio(lista,2);
  // lista = slist_agregar_inicio(lista,4);
  // lista = slist_agregar_inicio(lista,10);
  // slist_recorrer(lista,imprimir_entero);
  // printf("\n");
  // lista = slist_ordenar(lista,comparar_enteros_descendiente);
  // slist_recorrer(lista,imprimir_entero);
  // printf("\n");

  // i
  // SList lista = slist_crear();
  // lista = slist_agregar_inicio(lista,7);
  // lista = slist_agregar_inicio(lista,5);
  // lista = slist_agregar_inicio(lista,3);
  // lista = slist_agregar_inicio(lista,1);
  // lista = slist_agregar_inicio(lista,9);
  // lista = slist_agregar_inicio(lista,6);
  // lista = slist_agregar_inicio(lista,4);
  // lista = slist_agregar_inicio(lista,2);
  // lista = slist_agregar_inicio(lista,0);
  // slist_recorrer(lista,imprimir_entero);
  // printf("\n");
  // lista = slist_reverso(lista);
  // slist_recorrer(lista,imprimir_entero);
  // printf("\n");

  // j
  // SList lista1 = slist_crear();
  // SList lista2 = slist_crear();
  // lista1 = slist_agregar_inicio(lista1,7);
  // lista1 = slist_agregar_inicio(lista1,5);
  // lista1 = slist_agregar_inicio(lista1,3);
  // lista1 = slist_agregar_inicio(lista1,1);
  // lista2 = slist_agregar_inicio(lista2,8);
  // lista2 = slist_agregar_inicio(lista2,6);
  // lista2 = slist_agregar_inicio(lista2,4);
  // lista2 = slist_agregar_inicio(lista2,2);
  // slist_recorrer(lista1,imprimir_entero);
  // printf("\n");
  // slist_recorrer(lista2,imprimir_entero);
  // printf("\n");
  // SList listaIntercalada = slist_intercalar(lista1,lista2);
  // slist_recorrer(listaIntercalada,imprimir_entero);

  // k
  // SList lista = slist_crear();
  // lista = slist_agregar_inicio(lista,7);
  // lista = slist_agregar_inicio(lista,5);
  // lista = slist_agregar_inicio(lista,3);
  // lista = slist_agregar_inicio(lista,1);
  // lista = slist_agregar_inicio(lista,9);
  // lista = slist_agregar_inicio(lista,6);
  // lista = slist_agregar_inicio(lista,4);
  // lista = slist_agregar_inicio(lista,2);
  // lista = slist_agregar_inicio(lista,0);
  // lista = slist_agregar_inicio(lista,8);
  // slist_recorrer(lista,imprimir_entero);
  // printf("\n");
  // SList listaMitadFinal = slist_partir(lista);
  // slist_recorrer(lista,imprimir_entero);
  // printf("\n");
  // slist_recorrer(listaMitadFinal,imprimir_entero);
  // printf("\n");

  // EJ 3
  // a, b, c y d
  // SListF *listaF = slistf_crear();
  // slistf_agregar_inicio(listaF,2);
  // slistf_agregar_final(listaF,5);
  // slistf_agregar_inicio(listaF,6);
  // slistf_agregar_final(listaF,7);
  // slistf_agregar_inicio(listaF,8);
  // slistf_agregar_inicio(listaF,9);
  // slistf_agregar_final(listaF,1);
  // slistf_recorrer(listaF,imprimir_entero);

  // EJ 4
  // a, b, c y d
  // DList *listaD = dlist_crear();
  // dlist_agregar_inicio(listaD,2);
  // dlist_agregar_final(listaD,5);
  // dlist_agregar_inicio(listaD,6);
  // dlist_agregar_final(listaD,7);
  // dlist_agregar_inicio(listaD,8);
  // dlist_agregar_inicio(listaD,9);
  // dlist_agregar_final(listaD,1);
  // dlist_recorrer(listaD,imprimir_entero,DLIST_RECORRIDO_HACIA_ADELANTE);
  // printf("\n");
  // dlist_recorrer(listaD,imprimir_entero,DLIST_RECORRIDO_HACIA_ATRAS);
  // dlist_recorrer(listaD,imprimir_entero,PINDONGA);

  // EJ 5
  // a, b, c y d
  // CDList lista = cdlist_crear();
  // lista = cdlist_agregar_inicio(lista,2);
  // lista = cdlist_agregar_final(lista,5);
  // lista = cdlist_agregar_inicio(lista,6);
  // lista = cdlist_agregar_final(lista,7);
  // lista = cdlist_agregar_inicio(lista,8);
  // lista = cdlist_agregar_inicio(lista,9);
  // lista = cdlist_agregar_final(lista,1);
  // cdlist_recorrer(lista,imprimir_entero,CDLIST_RECORRIDO_HACIA_ADELANTE);
  // printf("\n");
  // cdlist_recorrer(lista,imprimir_entero,CDLIST_RECORRIDO_HACIA_ATRAS);
  // cdlist_recorrer(lista,imprimir_entero,HOMERO);

  // FUNCIONES RECURSIVAS PARTE 1
  SList lista = slist_crear();
  lista = slist_agregar_final(lista,5);
  lista = slist_agregar_final(lista,4);
  lista = slist_agregar_final(lista,3);
  lista = slist_agregar_final(lista,2);
  slist_recorrer_recursivo(lista,imprimir_entero);
  printf("\n");
  lista = slist_agregar_final_recursivo(lista,1);
  slist_recorrer_recursivo(lista,imprimir_entero);
  printf("\n");
  printf("%i",slist_longitud_recursivo(lista));
  printf("\n");

  SList lista2 = slist_crear();
  lista2 = slist_agregar_final(lista2,9);
  lista2 = slist_agregar_final(lista2,8);
  lista2 = slist_agregar_final(lista2,7);
  lista2 = slist_agregar_final(lista2,6);
  slist_recorrer_recursivo(lista2,imprimir_entero);
  printf("\n");
  slist_concatenar(lista,lista2);
  printf("\n");
  slist_recorrer_recursivo(lista,imprimir_entero);
  printf("\n");
  slist_recorrer_recursivo(lista2,imprimir_entero);


  return 0;
}
