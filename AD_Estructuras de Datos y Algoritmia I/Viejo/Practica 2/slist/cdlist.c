#include "cdlist.h"

// Ej 5
// a
CDList cdlist_crear(){
    return NULL;
}

// b
CDList cdlist_agregar_final(CDList lista, int dato){
    CDNodo *nuevoNodo = malloc(sizeof(CDNodo));
    nuevoNodo->dato = dato;

    if(lista == NULL){
        nuevoNodo->sig = nuevoNodo;
        nuevoNodo->ant = nuevoNodo;
        return nuevoNodo;
    }

    nuevoNodo->sig = lista;
    nuevoNodo->ant = lista->ant;
    lista->ant->sig = nuevoNodo;
    lista->ant = nuevoNodo;

    return lista;
}

// c
CDList cdlist_agregar_inicio(CDList lista, int dato){
    CDNodo *nuevoNodo = malloc(sizeof(CDNodo));
    nuevoNodo->dato = dato;

    if(lista == NULL){
        nuevoNodo->sig = nuevoNodo;
        nuevoNodo->ant = nuevoNodo;
        return nuevoNodo;
    }

    nuevoNodo->sig = lista;
    nuevoNodo->ant = lista->ant;
    lista->ant->sig = nuevoNodo;
    lista->ant = nuevoNodo;

    return nuevoNodo;
}

// d
void cdlist_recorrer(CDList lista, FuncionVisitante f, CDListOrdenDeRecorrido ordenRecorrido){
    CDNodo *ultimoNodo;
    int flag = 1;
    switch(ordenRecorrido){
        case CDLIST_RECORRIDO_HACIA_ADELANTE:
            ultimoNodo = lista->ant;
            for(CDNodo *recorre = lista ; recorre != NULL && flag ; recorre = recorre->sig){
                if(recorre == ultimoNodo){
                    f(recorre->dato);
                    flag = 0;
                }
                else{
                    f(recorre->dato);
                }
            }
            break;
        case CDLIST_RECORRIDO_HACIA_ATRAS:
            ultimoNodo = lista->sig;
            for(CDNodo *recorre = lista ; recorre != NULL && flag ; recorre = recorre->ant){
                if(recorre == ultimoNodo){
                    f(recorre->dato);
                    flag = 0;
                }
                else{
                f(recorre->dato);
                }
            }
            break;
        default:
            printf("\nOrden de recorrido ingresado invalido!");
            break;
    }
}





