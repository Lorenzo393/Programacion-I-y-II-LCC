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

/*
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
*/


Articulo cargar_articulo(char buffer[]){
    Articulo articulo;
    int bufferIndex = 0;

    printf("1-");
    while(buffer[bufferIndex] != ',') bufferIndex++;
    printf("%s %i-", buffer , bufferIndex);
    articulo.nombre = malloc((sizeof(char) * bufferIndex) + 1); // ACA ESTA EL ERROR, NO SE PORQUE
    printf("2.1-");
    strcpy(articulo.nombre,buffer);
    printf("2.2-");
    articulo.nombre[bufferIndex] = '\0';
    printf("2.3-");
    bufferIndex++;
    printf("3-");
    
    char aux[10];
    int auxIndex;
    for(auxIndex = 0 ; buffer[bufferIndex] != '\n' ; auxIndex++, bufferIndex++){
        aux[auxIndex] = buffer[bufferIndex];
    }
    printf("4-");
    aux[auxIndex] = '\0';

    int precio = atoi(aux);
    articulo.precio = precio;
    printf("5-");
    return articulo;
}

void leer_archivo(FILE* file, ListaArticulos listaArticulos){
    char buffer[100];
    int i = 0;
    printf("Gola");
    printf("\n");
    while(linea_archivo(buffer,file) != NULL){
        if(listaArticulos.cantArticulos < listaArticulos.capacidad){
            printf("putola");
            listaArticulos.articulos[listaArticulos.cantArticulos] = cargar_articulo(buffer);
            listaArticulos.cantArticulos++;
            quitar_terminador(buffer);
            printf("\nfile %i %i %s ---- %s %i",listaArticulos.cantArticulos, listaArticulos.capacidad , buffer , listaArticulos.articulos[i].nombre,listaArticulos.articulos[i].precio);
            i++;
        }
        else{
            //Agregar mas memoria con un realoc
        }
        printf("\nzi\n");
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
        fclose(fileArticulos);
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