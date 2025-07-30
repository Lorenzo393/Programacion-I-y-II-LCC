#include "contacto.h"
#include "glist.h"
#include <stdio.h>
#include <stdlib.h>

int *funcion(void *dato){
  int *copia = malloc(sizeof(int));
  *copia = *(int*)dato;
  return copia;
}

void imprimir_entero(void *dato){
  printf("%i ",*(int *)dato);
}


int main() {
  // GList lista = glist_crear();
  // int *arr = malloc(sizeof(int) * 5);
  // arr[0] = 1;
  // arr[1] = 2;
  // arr[2] = 3;
  // arr[3] = 4;
  // arr[4] = 5;

  // for (int i = 0 ; i < 5 ; ++i) {
  //   lista = glist_agregar_inicio(lista, &arr[i], (FuncionCopia)funcion);
  // }
  // free(arr);
  // glist_recorrer(lista,(FuncionVisitante)imprimir_entero);

  GList lista = glist_crear();
  Contacto *contactos[6];
  contactos[0] = contacto_crear("Pepe Argento", "3412695452", 61);
  contactos[1] = contacto_crear("Moni Argento", "3412684759", 60);
  contactos[2] = contacto_crear("Coqui Argento", "3415694286", 32);
  contactos[3] = contacto_crear("Paola Argento", "3416259862", 29);
  contactos[4] = contacto_crear("Maria Elena Fuseneco", "3416874594", 59);
  contactos[5] = contacto_crear("Dardo Fuseneco", "3416894526", 64);

  for (int i = 0 ; i < 6 ; ++i) {
    lista = glist_agregar_inicio(lista, contactos[i], (FuncionCopia)contacto_copia);
    contacto_destruir(contactos[i]);
  }

  printf("Lista:\n");
  glist_recorrer(lista, (FuncionVisitante)contacto_imprimir);

  glist_destruir(lista, (FuncionDestructora)contacto_destruir);
  
  

  return 0;
}