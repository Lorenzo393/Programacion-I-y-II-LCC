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

// EJ 2
// a
int slist_longitud(SList lista){
  int len = 0;
  while(lista != NULL){
    lista = lista->sig;
    len++;
  }
  return len; 
}

// b
void slist_concatenar(SList lista1, SList lista2){
  while(lista2 != NULL){
    lista1 = slist_agregar_final(lista1, lista2->dato);
    lista2 = lista2->sig;
  }
}

// c
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

// d
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

// e
int slist_contiene(SList lista, int dato){
  for(;lista != NULL && lista->dato != dato ; lista = lista->sig);
  return lista != NULL;
}

// f
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
 
// g
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

// h
SList slist_ordenar(SList lista, FuncionComparadora f){
  for(SNodo *nodoBase = lista ; nodoBase != NULL ; nodoBase = nodoBase->sig){
    for(SNodo *nodoComp = nodoBase->sig ; nodoComp != NULL; nodoComp = nodoComp->sig){
      if(f(nodoBase->dato,nodoComp->dato)){
        int aux = nodoBase->dato;
        nodoBase->dato = nodoComp->dato;
        nodoComp->dato = aux;
      }
    }
  }
  return lista;
}

// i
SList slist_reverso(SList lista){
  SNodo *nodoUltimo = NULL;
  int flagPrincipal = 1;
  for(SNodo *nodoBase = lista ; flagPrincipal ; nodoBase = nodoBase->sig){
    int flagSecundaria = 1;
    for(SNodo * recorrer = nodoBase ; flagSecundaria && recorrer != NULL ; recorrer = recorrer->sig){
      if(recorrer->sig == nodoUltimo){
        nodoUltimo = recorrer;
        flagSecundaria = 0;
      }
    }
    if(nodoBase == nodoUltimo){
      flagPrincipal = 0;
    }
    else{
      int aux = nodoBase->dato;
      nodoBase->dato = nodoUltimo->dato;
      nodoUltimo->dato = aux;
    }
  }
  return lista;
}

// j
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

// k
SList slist_partir(SList lista){
  int lenLista1 = slist_longitud(lista);
  if(lenLista1 <= 1) return NULL;
  if(lenLista1 % 2 == 0) lenLista1 = (lenLista1 / 2) - 1;
  else lenLista1 = (lenLista1 / 2);

  SNodo *listaPartida = lista;
  for(int i = 0 ; i < lenLista1 ; i++ , listaPartida = listaPartida->sig);

  SNodo *aux = listaPartida;
  listaPartida = listaPartida->sig;
  aux->sig = NULL;

  return listaPartida;
}

// EJ 3
// a
SListF *slistf_crear(){
    SListF *lista = malloc(sizeof(SListF));
    lista->primero = NULL;
    lista->ultimo = NULL;
    return lista;
}

// b
void slistf_agregar_final(SListF *lista, int dato){
    SNodo *nuevoNodo = malloc(sizeof(SNodo));
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;

    if(lista->primero == NULL){
        lista->primero = nuevoNodo;
        lista->ultimo = nuevoNodo;
    }
    else {
        lista->ultimo->sig = nuevoNodo;
        lista->ultimo = nuevoNodo;
    }
}

// c
void slistf_agregar_inicio(SListF *lista, int dato){
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  
  if(lista->primero == NULL){
    nuevoNodo->sig = NULL;
    lista->primero = nuevoNodo;
    lista->ultimo = nuevoNodo;
  }
  else{
    nuevoNodo->sig = lista->primero;
    lista->primero = nuevoNodo;
  }
}

// d
void slistf_recorrer(SListF *lista, FuncionVisitante f){
  for(SNodo *recorrer = lista->primero ; recorrer != NULL ; recorrer = recorrer->sig){
    f(recorrer->dato);
  }
}