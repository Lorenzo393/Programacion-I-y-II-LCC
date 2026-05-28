#include "pilageneral.h"

void *copiar_entero(void *dato){
    int *entero = malloc(sizeof(int));
    *entero = (*(int *)dato);
    return entero;
}

void mostrar_entero(void *dato){
    printf("%i ",(*(int *) dato));
}

void destruir_entero(void *dato){
    free(dato);
}

int main(){
    int *arr = malloc(sizeof(int) * 5);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    Pila pila = pila_crear();
    printf("Esta vacia? %i\n", pila_es_vacia(pila));
    pila = pila_apilar(pila, &arr[0], (FuncionCopia)copiar_entero);
    pila = pila_apilar(pila, &arr[1], (FuncionCopia)copiar_entero);
    pila = pila_apilar(pila, &arr[2], (FuncionCopia)copiar_entero);
    pila = pila_apilar(pila, &arr[3], (FuncionCopia)copiar_entero);
    pila = pila_apilar(pila, &arr[4], (FuncionCopia)copiar_entero);

    pila_imprimir(pila, (FuncionVisitante)mostrar_entero);

    printf("\n");
    printf("%i\n",(* (int *)pila_tope(pila)));
    pila = pila_desapilar(pila, (FuncionDestructora)destruir_entero);
    printf("%i\n",(* (int *)pila_tope(pila)));
    pila = pila_desapilar(pila, (FuncionDestructora)destruir_entero);
    printf("%i\n",(* (int *)pila_tope(pila)));
    printf("\n");

    pila_destruir(pila, (FuncionDestructora)destruir_entero);

    GList lista = malloc(sizeof(GList));
    lista->data = copiar_entero(&arr[0]);
    lista->next = malloc(sizeof(GList));
    lista->next->data = copiar_entero(&arr[1]);
    lista->next->next = malloc(sizeof(GList));
    lista->next->next->data = copiar_entero(&arr[2]);
    lista->next->next->next = NULL;

    lista_imprimir(lista, (FuncionVisitante)mostrar_entero);
    lista = lista_invertir(lista, (FuncionCopia)copiar_entero, (FuncionDestructora)destruir_entero);
    lista_imprimir(lista, (FuncionVisitante)mostrar_entero);

    return 0;
}