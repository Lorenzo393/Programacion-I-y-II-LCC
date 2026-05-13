#include "cdlist.h"




int main(){

    CDList lista = cdlist_crear();
    lista = cdlist_agregar_ultimo(lista, 1);
    lista = cdlist_agregar_primero(lista, 2);
    lista = cdlist_agregar_ultimo(lista, 3);
    lista = cdlist_agregar_primero(lista, 4);
    lista = cdlist_agregar_ultimo(lista, 5);

    cdlist_recorrer(lista, CDLIST_RECORRIDO_HACIA_ADELANTE);
    cdlist_recorrer(lista, CDLIST_RECORRIDO_HACIA_ATRAS);

    return 0;
}