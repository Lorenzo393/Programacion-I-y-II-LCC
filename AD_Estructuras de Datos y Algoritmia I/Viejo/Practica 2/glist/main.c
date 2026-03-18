#include <stdlib.h>
#include <stdio.h>


#include "contacto.h"
#include "sglist.h"
#include "glist.h"

int *copia_entero(void *dato){
  int *copia = malloc(sizeof(int));
  *copia = *(int*)dato;
  return copia;
}

void imprimir_entero(int *dato){
  printf("%i ",*dato);
}

int predicado_mas_de_60(void *dato) { return ((*(int *)dato) > 5); }

int comp_x_mayor_y(int *x, int *y) { return ((*x) > (*y)); }

int comp_x_menor_y(int *x, int *y) { return ((*x) < (*y)); }

int comp_x_igual_y(int *x, int *y) { return ((*x) == (*y)); }


int main() {
  // GList lista = glist_crear();
  // int *arr = malloc(sizeof(int) * 5);
  // arr[0] = 1;
  // arr[1] = 2;
  // arr[2] = 3;
  // arr[3] = 4;
  // arr[4] = 5;

  // for (int i = 0 ; i < 5 ; ++i) {
  //   lista = glist_agregar_inicio(lista, &arr[i], (FuncionCopia)copia_entero);
  // }
  // free(arr);
  // glist_recorrer(lista,(FuncionVisitante)imprimir_entero);

  // EJ 7
  // GList lista = glist_crear();
  // Contacto *contactos[6];
  // contactos[0] = contacto_crear("Pepe Argento", "3412695452", 61);
  // contactos[1] = contacto_crear("Moni Argento", "3412684759", 60);
  // contactos[2] = contacto_crear("Coqui Argento", "3415694286", 32);
  // contactos[3] = contacto_crear("Paola Argento", "3416259862", 29);
  // contactos[4] = contacto_crear("Maria Elena Fuseneco", "3416874594", 59);
  // contactos[5] = contacto_crear("Dardo Fuseneco", "3416894526", 64);

  // for (int i = 0 ; i < 6 ; ++i) {
  //   lista = glist_agregar_inicio(lista, contactos[i], (FuncionCopia)contacto_copia);
  //   contacto_destruir(contactos[i]);
  // }

  // printf("Lista:\n");
  // glist_recorrer(lista, (FuncionVisitante)contacto_imprimir);

  // lista = glist_filtrar(lista, (FuncionCopia)contacto_copia, (Predicado)contacto_edad_mayor_60);

  // printf("\nLista mayores de 60:\n");
  // glist_recorrer(lista, (FuncionVisitante)contacto_imprimir);

  // glist_destruir(lista, (FuncionDestructora)contacto_destruir);
  
  // EJ 8
  SGList lista = sglist_crear();

  //printf("%i ",sglist_vacia(lista));

  int *arr = malloc(sizeof(int) * 8);
  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 3;
  arr[3] = 9;
  arr[4] = 5;
  arr[5] = 4;
  arr[6] = 0;
  arr[7] = 14;

  void **array = malloc(sizeof(void *) * 8);
  for(int i = 0 ; i < 8 ; i++){
    array[i] = &arr[i];
  }

  // for (int i = 0 ; i < 8 ; ++i) {
  //   lista = sglist_insertar(lista, array[i], (FuncionCopia)copia_entero, (FuncionComparadora)comp_x_menor_y);
  // }

  // sglist_recorrer(lista, (FuncionVisitante)imprimir_entero);

  // int *x = malloc(sizeof(int));
  // *x = -1;
  // printf("\n");
  // if (sglist_buscar(lista, x, (FuncionComparadora)comp_x_igual_y)){
  //   printf("El valor %i esta en la lista",*x);
  // } 
  // else {
  //   printf("El valor %i no esta en la lista",*x);
  // }

  lista = sglist_arr(array, 8, (FuncionCopia)copia_entero, (FuncionComparadora)comp_x_menor_y);

  sglist_recorrer(lista, (FuncionVisitante)imprimir_entero);

  //sglist_destruir(lista, (FuncionDestructora)contacto_destruir);

  return 0;
}