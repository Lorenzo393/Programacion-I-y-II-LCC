#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

// fgets toma el /n
// fgets devuelve null cuando es el final del archivo o hay un error

#define LARGO_LINEA 100
#define CANT_ARTICULOS_BASE 10
#define CANT_MAX_ARTICULOS_PROMO 3

typedef struct _Articulo{
    char *nombre;
    int precio, nArticulo;
}Articulo;

typedef struct _ListaArticulos{
    Articulo *articulos;
    int cantArticulos;
    int capacidad;
}ListaArticulos;

typedef struct _ArticuloPromo{
    char *nombre1, *nombre2;
    int cant1,cant2;
    int precio;
}ArticuloPromo;

typedef struct _ListaPromociones{
    ArticuloPromo *articulosPromo;
    int cantPromociones;
}ListaPromociones;


void quitar_terminador(char buffer[]){
    int largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
}

void mostrar_estructura(ListaArticulos listaArticulos){
    for(int i = 0 ; i < listaArticulos.cantArticulos ; i++){
        printf("\n%i %i | %s %i",listaArticulos.articulos[i].nArticulo,(listaArticulos.articulos[i].nArticulo)+1,listaArticulos.articulos[i].nombre,listaArticulos.articulos[i].precio);
    }
    printf("\nCant: %i",listaArticulos.cantArticulos);
    printf("\nCap: %i",listaArticulos.capacidad);
}

char *linea_archivo(char buffer[], FILE *file){
    return fgets(buffer,LARGO_LINEA,file);
}

char *copiar_cadena(char buffer[], int bufferIndex){
    char *cadena;
    cadena = malloc((sizeof(char)*bufferIndex)+1);
    strncpy(cadena,buffer,bufferIndex);
    cadena[bufferIndex] = '\0';
    return cadena;
}

void copiar_cadena_2(char aux[], char buffer[], int bufferIndex){
    int auxIndex = 0;
    for(; buffer[bufferIndex] != '\n' ; auxIndex++, bufferIndex++) aux[auxIndex] = buffer[bufferIndex];
    aux[auxIndex] = '\0';
}

Articulo cargar_articulo(char buffer[]){
    Articulo articulo;
    int bufferIndex = 0;
    while(buffer[bufferIndex] != ',') bufferIndex++;
    articulo.nombre = copiar_cadena(buffer , bufferIndex);
    bufferIndex++;
    char aux[10];
    copiar_cadena_2(aux , buffer , bufferIndex);
    articulo.precio = atoi(aux);

    return articulo;
}

ListaArticulos cargar_ListaArticulos(FILE* file, ListaArticulos listaArticulos){
    char buffer[100];
    while(linea_archivo(buffer,file) != NULL){
        if(listaArticulos.cantArticulos < listaArticulos.capacidad){
            listaArticulos.articulos[listaArticulos.cantArticulos] = cargar_articulo(buffer);
            listaArticulos.articulos[listaArticulos.cantArticulos].nArticulo = listaArticulos.cantArticulos;
            listaArticulos.cantArticulos++;
        }
        else{
            listaArticulos.articulos = realloc(listaArticulos.articulos,(sizeof(Articulo) * (listaArticulos.capacidad*2)));
            listaArticulos.capacidad = listaArticulos.capacidad * 2;
            
            listaArticulos.articulos[listaArticulos.cantArticulos] = cargar_articulo(buffer);
            listaArticulos.articulos[listaArticulos.cantArticulos].nArticulo = listaArticulos.cantArticulos;
            listaArticulos.cantArticulos++;
        }
    }
    
    if((fgets(buffer,100,file)) == NULL) printf("EOF");
    else printf("Nai");

    return listaArticulos;
}

Articulo articulo_random(ListaArticulos listaArticulos , Articulo *articulo){
    Articulo articuloPromo;
    int articuloRandom = 0;
    if(articulo != NULL) while((articuloRandom = rand() % listaArticulos.cantArticulos) == articulo->nArticulo);
    else articuloRandom = rand() % listaArticulos.cantArticulos;
    articuloPromo = listaArticulos.articulos[articuloRandom];

    return articuloPromo;
}

void cargar_ListaPromociones(ListaArticulos listaArticulos, ListaPromociones listaPromociones){
    listaPromociones.articulosPromo = malloc(sizeof(ArticuloPromo) * listaPromociones.cantPromociones);
    printf("Cantidad de Promociones: %i",listaPromociones.cantPromociones);
    for(int i = 0 ; i < listaPromociones.cantPromociones ; i++){
        Articulo articulo1 = articulo_random(listaArticulos,NULL);
        Articulo articulo2 = articulo_random(listaArticulos,&articulo1);
        int precio1 = articulo1.precio;
        int precio2 = articulo2.precio;
        int nArt1 = articulo1.nArticulo;
        int nArt2 = articulo2.nArticulo;
        
        printf("\nPromocion %i: | %i - %s %i | %i - %s %i |",i+1,nArt1,articulo1.nombre,precio1,nArt2,articulo2.nombre,precio2);
    }
}



ListaArticulos inicializar_ListaArticulos(){
    ListaArticulos listaArticulos;
    listaArticulos.articulos = malloc(sizeof(Articulo) * CANT_ARTICULOS_BASE);
    listaArticulos.capacidad = CANT_ARTICULOS_BASE;
    listaArticulos.cantArticulos = 0;
    return listaArticulos;
}

ListaPromociones inicializar_ListaPromociones(){
    ListaPromociones listaPromociones;
    listaPromociones.cantPromociones = 0;
    return listaPromociones;
}

int main(){
    srand(time(NULL));
    FILE* fileArticulos = fopen("articulos.txt","r");
    if(fileArticulos == NULL){
        printf("Error al leer el archivo articulos.txt");
        return 1;
    }

    ListaArticulos listaArticulos = inicializar_ListaArticulos();
    listaArticulos = cargar_ListaArticulos(fileArticulos,listaArticulos);
    mostrar_estructura(listaArticulos);
    fclose(fileArticulos);

    ListaPromociones listaPromociones = inicializar_ListaPromociones();
    printf("\n\nIngrese la cantidad de promociones: ");
    scanf("%i",&listaPromociones.cantPromociones);
    printf("\n");
    cargar_ListaPromociones(listaArticulos,listaPromociones);

    
    
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