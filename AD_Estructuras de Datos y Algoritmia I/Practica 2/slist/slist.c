#include "slist.h"


SList slist_crear() {
  return NULL;
}

void slist_destruir(SList lista) {
  SNodo *nodoAEliminar;
  while (lista != NULL) {
    nodoAEliminar = lista;
    lista = lista->sig;
    free(nodoAEliminar);
  }
}

int slist_vacia(SList lista) {
  return lista == NULL;
}

SList slist_agregar_final(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;

  if (lista == NULL)
    return nuevoNodo;

  SList nodo = lista;
  for (;nodo->sig != NULL;nodo = nodo->sig);
  /* ahora 'nodo' apunta al ultimo elemento en la lista */

  nodo->sig = nuevoNodo;
  return lista;
}

SList slist_agregar_inicio(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = lista;
  return nuevoNodo;
}

void slist_recorrer(SList lista, FuncionVisitante visit) {
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
    visit(nodo->dato);
}

int slist_longitud(SList lista){
  int len = 0;
  while(lista != NULL){
    lista = lista->sig;
    len++;
  }
  return len; 
}

void slist_concatenar(SList lista1, SList lista2){
  while(lista2 != NULL){
    lista1 = slist_agregar_final(lista1, lista2->dato);
    lista2 = lista2->sig;
  }
}

SList slist_insertar(SList lista, int pos, int dato){
  if(pos < 1) return slist_agregar_inicio(lista,dato);

  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;
  
  if(lista == NULL) return nuevoNodo;

  SNodo *nodoAnterior = lista;
  for(int i = 0 ; i < (pos - 1) && nodoAnterior->sig != NULL ; nodoAnterior = nodoAnterior->sig , i++);

  SNodo *aux = nodoAnterior->sig;
  nodoAnterior->sig = nuevoNodo;
  nuevoNodo->sig = aux;

  return lista;
}

SList slist_elimina(SList lista, int pos){
  if(lista == NULL) return NULL;
  if(pos < 1) {
    SNodo *nodoSegundo = lista->sig;
    free(lista);
    return nodoSegundo;
  }

  SNodo *nodoAnterior = lista;
  for(int i = 0 ; i < (pos - 1) && nodoAnterior->sig != NULL ; i++, nodoAnterior = nodoAnterior->sig);
  
  if(nodoAnterior->sig == NULL) return lista;
  SNodo *nodoEliminar = nodoAnterior->sig;
  nodoAnterior->sig = nodoEliminar->sig;
  free(nodoEliminar);
  
  return lista;
}

int slist_contiene(SList lista, int dato){
  for(;lista != NULL && lista->dato != dato ; lista = lista->sig);
  return lista != NULL;
}


int slist_indice(SList lista, int dato){
  int pos = -1;
  if(lista == NULL) return pos;
  
  int flag = 1;
  for(int i = 0; lista != NULL && flag; lista = lista->sig, i++){
    if(lista->dato == dato){
      flag = 0;
      pos = i;
    }
  }
  return pos;
}
 
SList slist_intersecar(SList lista1, SList lista2){
  SList listaIntersecada = NULL;
  while(lista1 != NULL){
    if(!slist_contiene(lista2,lista1->dato)){
      listaIntersecada = slist_agregar_inicio(listaIntersecada,lista1->dato);
    }
    lista1 = lista1->sig;
  }
  while(lista2 != NULL){
    if(!slist_contiene(lista1,lista2->dato)){
      listaIntersecada = slist_agregar_inicio(listaIntersecada,lista2->dato);
    }
    lista2 = lista2->sig;
  }  
  return listaIntersecada;
}







SList slist_intercalar(SList lista1, SList lista2){
  SList listaIntercalada = NULL;
  while(lista1 != NULL || lista2 != NULL){
    if(lista1 != NULL){
      listaIntercalada = slist_agregar_final(listaIntercalada,lista1->dato);
      lista1 = lista1->sig;
    }
    if(lista2 != NULL){
      listaIntercalada = slist_agregar_final(listaIntercalada,lista2->dato);
      lista2 = lista2->sig;
    }
  }
  return listaIntercalada;
}