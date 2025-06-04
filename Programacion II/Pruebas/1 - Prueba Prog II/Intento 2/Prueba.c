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

void mostrar_ListaArticulos(ListaArticulos listaArticulos){
    for(int i = 0 ; i < listaArticulos.cantArticulos ; i++){
        printf("\n%i %i | %s %i",listaArticulos.articulos[i].nArticulo,(listaArticulos.articulos[i].nArticulo)+1,listaArticulos.articulos[i].nombre,listaArticulos.articulos[i].precio);
    }
    printf("\nCant: %i",listaArticulos.cantArticulos);
    printf("\nCap: %i",listaArticulos.capacidad);
}

void mostrar_ListaPromociones(ListaPromociones listaPromociones){
    printf("Cantidad de Promociones: %i",listaPromociones.cantPromociones);
    for(int i = 0 ; i < listaPromociones.cantPromociones ; i++){
        printf("\nPromocion %i",i+1);
        printf("\nArticulo 1:");
        printf("%s %i",listaPromociones.articulosPromo[i].nombre1, listaPromociones.articulosPromo[i].cant1);
        printf("\nArticulo 2:");
        printf("%s %i",listaPromociones.articulosPromo[i].nombre2,listaPromociones.articulosPromo[i].cant2);
        printf("\nPrecio Final: %i\n",listaPromociones.articulosPromo[i].precio);
    }
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

Articulo cargar_Articulo(char buffer[]){
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
            listaArticulos.articulos[listaArticulos.cantArticulos] = cargar_Articulo(buffer);
            listaArticulos.articulos[listaArticulos.cantArticulos].nArticulo = listaArticulos.cantArticulos;
            listaArticulos.cantArticulos++;
        }
        else{
            listaArticulos.articulos = realloc(listaArticulos.articulos,(sizeof(Articulo) * (listaArticulos.capacidad*2)));
            listaArticulos.capacidad = listaArticulos.capacidad * 2;
            
            listaArticulos.articulos[listaArticulos.cantArticulos] = cargar_Articulo(buffer);
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

int cant_articulos_random(){
    return (rand() % CANT_MAX_ARTICULOS_PROMO) + 1;
}

int precio_rebajado(int precio1, int precio2, int cant1, int cant2){
    int precioMax = (precio1 * cant1) + (precio2 * cant2);
    int precioDescuento = rand() % precioMax;
    if(precioDescuento == 0) precioDescuento += 100;
    if(precioDescuento == (precioMax - 1)) precioDescuento -= 100;
    return precioDescuento;
}

ArticuloPromo cargar_ArticuloPromo(Articulo articulo1, Articulo articulo2, int cant1, int cant2){
    ArticuloPromo articuloPromo;
    articuloPromo.nombre1 = articulo1.nombre;
    articuloPromo.nombre2 = articulo2.nombre;
    articuloPromo.cant1 = cant1;
    articuloPromo.cant2 = cant2;
    articuloPromo.precio = precio_rebajado(articulo1.precio,articulo2.precio,cant1,cant2);

    return articuloPromo;
}

ListaPromociones cargar_ListaPromociones(ListaArticulos listaArticulos, ListaPromociones listaPromociones){
    listaPromociones.articulosPromo = malloc(sizeof(ArticuloPromo) * listaPromociones.cantPromociones);
    for(int i = 0 ; i < listaPromociones.cantPromociones ; i++){
        Articulo articulo1 = articulo_random(listaArticulos,NULL);
        Articulo articulo2 = articulo_random(listaArticulos,&articulo1);
        int cant1 = cant_articulos_random();
        int cant2 = cant_articulos_random();

        listaPromociones.articulosPromo[i] = cargar_ArticuloPromo(articulo1,articulo2,cant1,cant2);        
    }
    return listaPromociones;
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
    mostrar_ListaArticulos(listaArticulos);
    fclose(fileArticulos);

    ListaPromociones listaPromociones = inicializar_ListaPromociones();
    printf("\n\nIngrese la cantidad de promociones: ");
    scanf("%i",&listaPromociones.cantPromociones);
    printf("\n");
    listaPromociones = cargar_ListaPromociones(listaArticulos,listaPromociones);
    
    mostrar_ListaPromociones(listaPromociones);

    //CARGAR DATOS EN EL ARCHIVO
    
    
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