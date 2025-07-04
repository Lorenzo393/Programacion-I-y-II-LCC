#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define MAX_CATEGORIAS 7

typedef struct _Tuti{
    int cantCategorias;
    char **categorias;      //cantCategorias * lenCategoria
}Tuti;

Tuti inicializar_Tuti(int cantCategorias){
    Tuti tuti;
    tuti.cantCategorias = cantCategorias;
    tuti.categorias = malloc(sizeof(char*) * cantCategorias);
    return tuti;
}

int ingresar_categorias(){
    int cantCategorias = 0;
    printf("Ingrese la cantidad de categorias: ");
    scanf("%i",&cantCategorias);
    return cantCategorias;
}

int main(){
    srand(time(NULL));
    Tuti tuti = inicializar_Tuti(ingresar_categorias());

    printf("CantCategorias: %i",tuti.cantCategorias);
    
    

    return 0;
}