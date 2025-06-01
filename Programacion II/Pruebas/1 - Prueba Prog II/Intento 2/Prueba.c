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


char *linea_archivo(char buffer[], FILE *file){
    return fgets(buffer,LARGO_LINEA,file);
}

void quitar_terminador(char buffer[]){
    int largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
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

void leer_archivo(FILE* file, ListaArticulos listaArticulos){
    char buffer[100];
    int i = 0;
    while(linea_archivo(buffer,file) != NULL){
        if(listaArticulos.cantArticulos < listaArticulos.capacidad){
            listaArticulos.articulos[listaArticulos.cantArticulos] = cargar_articulo(buffer);
            listaArticulos.cantArticulos++;
            quitar_terminador(buffer);
            printf("\nfile %i %i %s ---- %s %i",listaArticulos.cantArticulos, listaArticulos.capacidad , buffer , listaArticulos.articulos[i].nombre,listaArticulos.articulos[i].precio);
            i++;
        }
        else{
            //Agregar mas memoria con un realoc
        }
    }
    
    if((fgets(buffer,100,file)) == NULL) printf("EOF");
    else printf("Nai");
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

    leer_archivo(fileArticulos,listaArticulos);
    fclose(fileArticulos);
    


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