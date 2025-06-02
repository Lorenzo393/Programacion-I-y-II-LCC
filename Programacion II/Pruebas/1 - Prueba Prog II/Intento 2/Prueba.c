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




void quitar_terminador(char buffer[]){
    int largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
}

void mostrar_estructura(ListaArticulos listaArticulos){
    printf("\nCant: %i",listaArticulos.cantArticulos);
    printf("\nCap: %i",listaArticulos.capacidad);
    for(int i = 0 ; i < listaArticulos.cantArticulos ; i++){
        printf("\n%i %i | %s %i",i,i+1,listaArticulos.articulos[i].nombre,listaArticulos.articulos[i].precio);
    }
}

char *linea_archivo(char buffer[], FILE *file){
    return fgets(buffer,LARGO_LINEA,file);
}

char *copiar_cadena(char buffer[],int bufferIndex){
    char *cadena;
    cadena = malloc((sizeof(char)*bufferIndex)+1);
    strncpy(cadena,buffer,bufferIndex);
    cadena[bufferIndex] = '\0';
    return cadena;
}

void copiar_cadena_2(char aux[],char buffer[],int bufferIndex){
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
            listaArticulos.cantArticulos++;
        }
        else{
            listaArticulos.articulos = realloc(listaArticulos.articulos,(sizeof(Articulo) * (listaArticulos.capacidad*2)));
            listaArticulos.capacidad = listaArticulos.capacidad * 2;
            
            listaArticulos.articulos[listaArticulos.cantArticulos] = cargar_articulo(buffer);
            listaArticulos.cantArticulos++;
        }
    }
    
    if((fgets(buffer,100,file)) == NULL) printf(" EOF");
    else printf("Nai");
    printf("\ncant: %i cap:%i",listaArticulos.cantArticulos,listaArticulos.capacidad);

    return listaArticulos;
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
        return 1;
    }

    ListaArticulos listaArticulos = inicializar_ListaArticulos();
    listaArticulos = cargar_ListaArticulos(fileArticulos,listaArticulos);
    fclose(fileArticulos);

    mostrar_estructura(listaArticulos);


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