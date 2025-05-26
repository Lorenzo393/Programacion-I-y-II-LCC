#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define MAX_CATEGORIAS 7

typedef enum {
    Nombres,
    Colores,
    Animales,
    Comidas,
    FloresyPlantas,
    Frutas,
    NombresDePaises
}Categorias;

int numero_categoria(){
    int cantCateg;
    printf("Ingrese el numero de categorias(max %d): ",MAX_CATEGORIAS);
    scanf("%d",&cantCateg);
    while(cantCateg < 1 || cantCateg > 7){
        printf("Error: Ingrese nuevamente el numero de categorias(max %d): ",MAX_CATEGORIAS);
        scanf("%d",&cantCateg);
    }
    return cantCateg;
}


int main(){
    srand(time(NULL));

    int cantCateg = numero_categoria();
    

    return 0;
}