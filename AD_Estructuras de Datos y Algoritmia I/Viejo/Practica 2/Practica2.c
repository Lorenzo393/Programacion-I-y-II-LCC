#include "slist/slist.h"
#include <string.h>
#include <stdio.h>
#include <time.h>

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int main(){
    SList list = slist_crear();
    list = slist_agregar_inicio(list,3);
    list = slist_agregar_inicio(list,2);
    list = slist_agregar_inicio(list,1);

    slist_recorrer(list,imprimir_entero);

    return 0;
}