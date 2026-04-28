#include "slist.h"
#include <stdlib.h>
#include <stdio.h>

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

int slist_vacia(SList lista) { return lista == NULL;}

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
    printf("\n");
}

int slist_longitud(SList lista){
    int longitud = 0;
    for(SNodo *it = lista ; it != NULL ; it = it->sig){
        longitud++;
    }
    return longitud;
}

void slist_concatenar(SList lista1, SList lista2){
    SNodo *nodoFinal = lista1;
    while(nodoFinal->sig != NULL){
        nodoFinal = nodoFinal->sig;
    }

    while(lista2 != NULL){
        SNodo *nuevoNodo = malloc(sizeof(SNodo));
        nuevoNodo->dato = lista2->dato;
        nuevoNodo->sig = NULL;

        nodoFinal->sig = nuevoNodo;
        nodoFinal = nodoFinal->sig;
        lista2 = lista2->sig;
    }
}

void slist_insertar(SList lista, int pos, int dato){
    for(SNodo *it = lista ; it != NULL ; it = it->sig, pos--){
        if(pos == 0) it->dato = dato;
    }
}

SList slist_eliminar(SList lista, int pos){
    if(lista == NULL)
        return NULL;
    if(pos <= 0){
        SNodo *nodoSiguiente = lista->sig;
        free(lista);
        return nodoSiguiente;
    }
    
    SNodo *nodoAnterior = lista;
    for(int i = 0 ; i < (pos - 1) && nodoAnterior->sig != NULL ; nodoAnterior = nodoAnterior->sig, i++);

    if(nodoAnterior->sig == NULL) return lista;
    SNodo *nodoAEliminar = nodoAnterior->sig;
    nodoAnterior->sig = nodoAEliminar->sig;
    free(nodoAEliminar);

    return lista;
}

int slist_contiene(SList lista, int dato){
    int contiene = -1;
    for(int flag = 1; lista != NULL && flag ; lista = lista->sig){
        if(lista->dato == dato) {
            flag = 0;
            contiene = 1;
        }
    }
    return contiene;
}

int slist_indice(SList lista, int dato){
    int indice = -1;
    for(int i = 0, flag = 1 ; lista != NULL && flag ; lista = lista->sig, i++){
        if(lista->dato == dato){
            flag = 0;
            indice = i;
        }
    }
    return indice;
}

SList slist_intersecar(SList lista1, SList lista2){
    SList nuevaLista = slist_crear();
    for(SNodo *it1 = lista1, *it2 = lista2 ; it1 != NULL ;){
        if(it2 == NULL){
            it1 = it1->sig;
            it2 = lista2;
        }
        else if(it1->dato == it2->dato){
            nuevaLista = slist_agregar_final(nuevaLista, it1->dato);
            it1 = it1->sig;
            it2 = lista2;
        }
        else{
            it2 = it2->sig;
        }
    }
    return nuevaLista;
}

SList slist_intersecar_custom(SList lista1, SList lista2, FuncionComparadora f){
    SList nuevaLista = slist_crear();
    for(SNodo *it1 = lista1, *it2 = lista2 ; it1 != NULL ;){
        if(it2 == NULL){
            it1 = it1->sig;
            it2 = lista2;
        }
        else if(f(it1->dato, it2->dato)){
            nuevaLista = slist_agregar_final(nuevaLista, it1->dato);
            it1 = it1->sig;
            it2 = lista2;
        }
        else{
            it2 = it2->sig;
        }
    }
    return nuevaLista;
}

SList slist_ordenar(SList lista, FuncionComparadora f){
    if(lista == NULL)
        return lista;
    
    for(SNodo *base = lista ; base != NULL ; base = base->sig){
        for(SNodo *comp = base->sig ; comp != NULL ; comp = comp->sig){
            if(f(base->dato,comp->dato) < 0){
                int aux = base->dato;
                base->dato = comp->dato;
                comp->dato = aux;
            }
        }
    }
    return lista;
}

SList slist_reverso(SList lista){
    int largoLista = slist_longitud(lista);

    SNodo *it = lista;
    for(int i = 0 ; i+1 < largoLista ; i++){
        int aux = it->dato;
        SNodo *ultimoNodo = it;
        for(int j = i ; j+1 < largoLista ; j++){
            ultimoNodo = ultimoNodo->sig;
        }
        it->dato = ultimoNodo->dato;
        ultimoNodo->dato = aux;
        it = it->sig;
        largoLista --;
    }
    return lista;
}

SList slist_intercalar(SList lista1, SList lista2){
    SList listaInter = slist_crear();
    int intercalar = 0;

    if(lista1 != NULL){
        SNodo *nuevoNodo = malloc(sizeof(SNodo));
        nuevoNodo->dato = lista1->dato;
        nuevoNodo->sig = NULL;

        listaInter = nuevoNodo;
        lista1 = lista1->sig;
        if(lista2 != NULL)
            intercalar = !intercalar;
    }
    else if(lista2 != NULL){
        SNodo *nuevoNodo = malloc(sizeof(SNodo));
        nuevoNodo->dato = lista2->dato;
        nuevoNodo->sig = NULL;

        lista2 = lista2->sig;
        listaInter = nuevoNodo;
        intercalar = !intercalar;
    }

    for(SNodo *itInter = listaInter ; lista1 != NULL || lista2 != NULL ; itInter = itInter->sig){
        SNodo *nuevoNodo = malloc(sizeof(SNodo));
        nuevoNodo->sig = NULL;
        if(!intercalar && lista1 != NULL){
            nuevoNodo->dato = lista1->dato;

            itInter->sig = nuevoNodo;
            lista1 = lista1->sig;
            if(lista2 != NULL)
                intercalar = !intercalar;
        }
        else if(intercalar && lista2 != NULL){
            nuevoNodo->dato = lista2->dato;

            itInter->sig = nuevoNodo;
            lista2 = lista2->sig;
            if(lista1 != NULL)
                intercalar = !intercalar;
        }
    }
    return listaInter;
}


SList slist_partir(SList lista){
    int lenLista = slist_longitud(lista);
    if(lenLista % 2 == 0)
        lenLista = lenLista / 2;
    
    else if(lenLista % 2 != 0)
        lenLista = (lenLista / 2) + 1;
    
    SNodo *nodoMitad = lista;
    for(int i = 0 ; i < (lenLista-1) ; i++)
        nodoMitad = nodoMitad->sig;

    SNodo *aux = nodoMitad;
    nodoMitad = nodoMitad->sig;
    aux->sig = NULL;

    return nodoMitad;
}
