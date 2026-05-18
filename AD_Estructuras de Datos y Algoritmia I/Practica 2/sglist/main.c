#include "sglist.h"

void destruir_entero(int *dato){
    free(dato);
}


int main(){
    SGList lista = sglist_crear();


    sglist_destruir(lista, (FuncionDestructora)destruir_entero);
    return 0;
}