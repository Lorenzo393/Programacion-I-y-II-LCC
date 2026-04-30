#include "dlist.h"
#include <stdlib.h>
#include <stdio.h>




int main(){

    DList lista = dlist_crear();
    
    lista = dlist_agregar_final(lista, 2);
    lista = dlist_agregar_final(lista, 3);
    lista = dlist_agregar_final(lista, 4);
    lista = dlist_agregar_final(lista, 5);
    lista = dlist_agregar_inicio(lista, 1);

    dlist_recorrer(lista, DLIST_RECORRIDO_HACIA_ADELANTE);
    dlist_recorrer(lista, DLIST_RECORRIDO_HACIA_ATRAS);

    return 0;
}