#include "slistu.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

    SList lista = slist_crear();
    lista = slist_agregar_final(lista, 5);
    lista = slist_agregar_final(lista, 4);
    lista = slist_agregar_final(lista, 3);
    lista = slist_agregar_final(lista, 2);
    lista = slist_agregar_inicio(lista, 1);

    slist_recorrer(lista);


    return 0;
}