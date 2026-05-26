#include "colageneral.h"

void entero_imprimir(void *dato){
    printf("%i ",(* (int *) dato));
}
void entero_destruir(void *dato){
    free(dato);
}
void *entero_copiar(void *dato){
    int *entero = malloc(sizeof(int));
    *entero = (* (int *) dato);
    return entero;
}

int main(){

    int *arr = malloc(sizeof(int) * 5);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;


    Cola cola = cola_crear();
    printf("Esta vacia? %i\n", cola_es_vacia(cola));
    cola = cola_encolar(cola, &arr[0], (FuncionCopia)entero_copiar);
    cola = cola_encolar(cola, &arr[1], (FuncionCopia)entero_copiar);
    cola = cola_encolar(cola, &arr[2], (FuncionCopia)entero_copiar);
    cola = cola_encolar(cola, &arr[3], (FuncionCopia)entero_copiar);
    cola = cola_encolar(cola, &arr[4], (FuncionCopia)entero_copiar);

    cola_imprimir(cola, (FuncionVisitante)entero_imprimir);
    printf("\n");

    printf("%i\n",(* (int *) cola_inicio(cola)));
    cola = cola_desencolar(cola, (FuncionDestructora)entero_destruir);
    printf("%i\n",(* (int *) cola_inicio(cola)));
    cola = cola_desencolar(cola, (FuncionDestructora)entero_destruir);
    printf("%i\n",(* (int *) cola_inicio(cola)));

    cola_destruir(cola, (FuncionDestructora)entero_destruir);

    return 0;
}