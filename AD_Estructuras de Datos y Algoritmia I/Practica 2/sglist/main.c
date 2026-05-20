#include "sglist.h"

void visitar_entero(void *dato){
    printf("%i ", (*(int *)dato));
}
void destruir_entero(int *dato){
    free(dato);
}
void *copiar_entero(void *dato){
    int *entero = malloc(sizeof(int));
    *entero = (*(int *) dato);
    return entero;
}
int mayor_entero(void *dato1, void* dato2){
    int orden = -2;
    if((*(int *)dato1) > (*(int *)dato2))
        orden = 1;
    else if ((*(int *)dato1) < (*(int *)dato2))
        orden = -1;
    else
        orden = 0;
    return orden;
}


int main(){
    int *arr = malloc(sizeof(int) * 7);
    arr[0] = 9;
    arr[1] = 10;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    arr[5] = 1;
    arr[6] = 2;

    void **array = malloc(sizeof(int*) * 7);
    for(int i = 0 ; i < 7 ; i++)
        array[i] = &arr[i];

    // SGList lista = sglist_crear();
    // lista = sglist_insertar(lista, &arr[0], (FuncionCopia)copiar_entero, (FuncionComparadora)mayor_entero);
    // lista = sglist_insertar(lista, &arr[1], (FuncionCopia)copiar_entero, (FuncionComparadora)mayor_entero);
    // lista = sglist_insertar(lista, &arr[2], (FuncionCopia)copiar_entero, (FuncionComparadora)mayor_entero);
    // lista = sglist_insertar(lista, &arr[3], (FuncionCopia)copiar_entero, (FuncionComparadora)mayor_entero);
    // lista = sglist_insertar(lista, &arr[4], (FuncionCopia)copiar_entero, (FuncionComparadora)mayor_entero);
    // lista = sglist_insertar(lista, &arr[5], (FuncionCopia)copiar_entero, (FuncionComparadora)mayor_entero);
    SGList lista = sglist_arr(array, 6, (FuncionCopia)copiar_entero, (FuncionComparadora)mayor_entero);

    sglist_recorrer(lista, (FuncionVisitante)visitar_entero);
    printf("Esta: %i",sglist_buscar(lista, &arr[6], (FuncionComparadora)mayor_entero));

    sglist_destruir(lista, (FuncionDestructora)destruir_entero);
    return 0;
}