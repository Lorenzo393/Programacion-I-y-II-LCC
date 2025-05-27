#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

// fgets toma el /n
// fgets devuelve null cuando es el final del archivo o hay un error

#define LARGO_LINEA 100
#define CANT_ARTICULOS_BASE 10

typedef struct _Articulo{
    char *nombre;
    int precio;
}Articulo;

typedef struct _ListaArticulos{
    Articulo *articulos;
    int cantArticulos;
    int capacidad;
}ListaArticulos;

void leer_archivo_legacy(FILE* file){
    char buffer[100];
    
    for(int i = 0 , largoLinea = 0; fgets(buffer,100,file) != NULL ; i++){
        largoLinea = strlen(buffer) - 1;
        buffer[largoLinea] = '\0';
        printf("\nline %i: %s", i+1 ,buffer);
    }
    
    if((fgets(buffer,100,file)) == NULL) printf("EOF");
    else printf("Nai");
}

void leer_archivo(FILE* file, ListaArticulos listaArticulos){
    char buffer[100];
    int i = 1;
    
    while(fgets(buffer,100,file) != NULL){
        int largoLinea = strlen(buffer) - 1;
        buffer[largoLinea] = '\0';
        printf("\nline %i: %s", i+1 ,buffer);
        i++;
        //cargar_articulo();
        //if(listaArticulos.cantArticulos == listaArticulos.capacidad) realoc
    }
    
    if((fgets(buffer,100,file)) == NULL) printf("EOF");
    else printf("Nai");
}

Articulo cargar_articulo(Articulo articulo){

}

ListaArticulos inicializar_ListaArticulos(){
    ListaArticulos listaArticulos;
    listaArticulos.articulos = malloc(sizeof(Articulo) * CANT_ARTICULOS_BASE);
    listaArticulos.capacidad = CANT_ARTICULOS_BASE;
    listaArticulos.cantArticulos = 0;
    return listaArticulos;
}

int main(){
    FILE* fileArticulos = fopen("articulos.txt","r");
    if(fileArticulos == NULL){
        printf("Error al leer el archivo articulos.txt");
        fclose(fileArticulos);
    }
    ListaArticulos listaArticulos = inicializar_ListaArticulos();

    leer_archivo(fileArticulos,listaArticulos);

    //int cantPromociones = 0;
    //printf("Ingrese la cantidad de promociones: ");
    //scanf("%d",&cantPromociones);

    
    
return 0;
}



/* FUNCIONA
    ListaArticulos listaArticulos = inicializar_ListaArticulos();
    Articulo articulo;
    articulo.nombre = "obama";
    articulo.precio = 1200;
    listaArticulos.articulos[0] = articulo;
    printf("cantArticulos: %i",listaArticulos.cantArticulos);
    printf("\narticulo 1: %s %i",listaArticulos.articulos[0].nombre,listaArticulos.articulos[0].precio);
    */