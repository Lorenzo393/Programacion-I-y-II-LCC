#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define MAX_UNIDADES 3 //Maximo de unidades de la promocion

/*
Articulo representa a un articulo con su nombre y precio/cantidad
ListaArticulos representa una lista de articulos
Promocion representa a una promocion mediante dos articulos y un precio de promocion
ListaPromociones representa a una lista de promociones
*/

// ENCONTRE VARIOS ERRORES DEL TIPO malloc(sizeof(articulo)) ->malloc(sizeof(Articulo))



typedef struct _articulo{
    char *articulo;
    int preCant;    //Lo uso tanto como precio en el caso de la lista de articulos como cantidad en el caso
} Articulo;         //de la lista de promociones

typedef struct _listaArticulos{
    Articulo *articulo;
} ListaArticulos;

typedef struct _promocion{
    Articulo *articulo1;
    Articulo *articulo2;
    int precio;
} Promocion;

typedef struct _listaPromociones{
    Promocion *promocion;
} ListaPromociones;


int contarArticulos(FILE *archivo){
    int cant = 0;
    char temp;
    while((temp = fgetc(archivo)) != EOF){
        if(temp == '\n') cant++;
    }
    fseek(archivo,0,SEEK_SET);
return cant;
}


Articulo *cargarArticulo(FILE *archivo, int cantidadArticulos){
    Articulo *articulo = malloc(sizeof(Articulo)); 
    char buffer[128];
    while((fgets(buffer,sizeof(buffer),archivo)) != NULL){
        char temp[32];
        int indice = 0;
        for(int i = 0 ; buffer[indice] != ',' ; i++, indice++){
            temp[i] = buffer[indice];
        }
        temp[indice] = '\0';
        indice++;

        articulo -> articulo = malloc(sizeof(char)*strlen(temp)+1);
        strcpy(articulo -> articulo, temp);
        articulo -> articulo[strlen(temp)] = '\0';

        for(int i = 0 ; buffer[indice] != '\0' ; i++, indice++){
            temp[i] = buffer[indice];
        }
        temp[indice] = '\0';

        articulo -> preCant = atoi(temp);

        return articulo;
    }
    free(articulo);
    return NULL;
}


ListaArticulos *cargarLista(FILE *archivo, int cantArticulos){
    ListaArticulos *listaArticulos = malloc(sizeof(ListaArticulos));
    listaArticulos->articulo = malloc(sizeof(Articulo)*cantArticulos);
    Articulo *articulo = malloc(sizeof(Articulo));

    for(int i = 0 ; i < cantArticulos ; i++){
        articulo = cargarArticulo(archivo,cantArticulos);
        printf("%s %i",articulo->articulo,articulo->preCant);
        printf("\n");
        listaArticulos->articulo[i] = *articulo;
    }
return listaArticulos;
}


Promocion *cargarPromocion(ListaArticulos *listaArticulos, int cantArticulos){
    //srand(time(NULL));
    Promocion *promocion = malloc(sizeof(Promocion));
    promocion->articulo1 = malloc(sizeof(Articulo));
    promocion->articulo2 = malloc(sizeof(Articulo));
    Articulo *articulo = malloc(sizeof(Articulo));
    int precioTotal = 0;
    int prod1 = 0;
    int prod2 = 0;

    prod1 = rand() % cantArticulos;
    articulo = &listaArticulos->articulo[prod1];

    promocion->articulo1->articulo = malloc(sizeof(char)*(strlen(articulo->articulo))+1);
    strcpy(promocion->articulo1->articulo, articulo->articulo);
    promocion->articulo1->articulo[strlen(articulo->articulo)] = '\0';
    promocion->articulo1->preCant = (rand() % MAX_UNIDADES) + 1;
    precioTotal = articulo->preCant * promocion->articulo1->preCant;

    while((prod2 = rand() % cantArticulos) != prod1) //AGREGO ESTA LINEA PARA QUE NO SE PUEDA REPETIR EL PRODUCTO
    articulo = &listaArticulos->articulo[prod2];

    promocion->articulo2->articulo = malloc(sizeof(char)*(strlen(articulo->articulo))+1);
    strcpy(promocion->articulo2->articulo, articulo->articulo);
    promocion->articulo2->articulo[strlen(articulo->articulo)] = '\0';
    promocion->articulo2->preCant = (rand() % MAX_UNIDADES) + 1;

    precioTotal = precioTotal + (articulo->preCant * promocion->articulo2->preCant);
    promocion->precio = precioTotal - (rand() % (precioTotal - 200) + 100);

    printf("%s %i %s %i %i",promocion->articulo1->articulo,promocion->articulo1->preCant,promocion->articulo2->articulo,promocion->articulo2->preCant,promocion->precio);
    printf("\n");

return promocion;
}


ListaPromociones *cargarPromociones(ListaArticulos *listaArticulos, int cantPromociones, int cantArticulos){
    ListaPromociones *listaPromociones = malloc(sizeof(ListaPromociones));
    listaPromociones->promocion = malloc(sizeof(Promocion)*cantPromociones);
    Promocion *promocion = malloc(sizeof(Promocion));

    for(int i = 0 ; i < cantPromociones ; i++){
        promocion = cargarPromocion(listaArticulos,cantArticulos);
        listaPromociones->promocion[i] = *promocion; // EL ERROR ERA QUE ME OLVIDE DE PONER EL [i]
    }
return listaPromociones;
}


void guardarPromociones(FILE *promociones, ListaPromociones *listaPromociones, int cantPromociones){
    Promocion *promocion = malloc(sizeof(Promocion));
    promocion->articulo1 = malloc(sizeof(Articulo));
    promocion->articulo2 = malloc(sizeof(Articulo));

    // SOLUCIONADA CORRIGIENDO EL ERROR EN LA FUNCION CARGARPROMOCIONES
    for(int i = 0 ; i < cantPromociones ; i++){
        promocion = &listaPromociones->promocion[i];
        fprintf(promociones, "%s,", promocion->articulo1->articulo);
        fprintf(promociones, "%i,", promocion->articulo1->preCant);
        fprintf(promociones, "%s,", promocion->articulo2->articulo);
        fprintf(promociones, "%i,", promocion->articulo2->preCant);
        fprintf(promociones, "%i", promocion->precio);
        fprintf(promociones, "\n");
    }
}

//LIBERO LA MEMORIA
void liberarMemoria(ListaArticulos *listaArticulos, ListaPromociones *listaPromociones, int cantArticulos, int cantPromociones){
    for(int i = 0 ; i < cantArticulos ; i++){
        free(listaArticulos->articulo[i].articulo);
    }
    free(listaArticulos->articulo);
    free(listaArticulos);
    for(int i = 0 ; i < cantPromociones ; i++){
        free(listaPromociones->promocion[i].articulo1);
        free(listaPromociones->promocion[i].articulo2);
    }
    free(listaPromociones->promocion);
    free(listaPromociones);
}



int main(){
    srand(time(NULL)); //SOLUCIONO EL PROBLEMA DE LAS PROMOCIONE CAMBIANDO LA UBICACION DE SRAND
    FILE *articulos = fopen("articulos.txt","r");
    FILE *promociones = fopen("promociones.txt","w");
    ListaPromociones *listaPromociones = malloc(sizeof(ListaPromociones));
    ListaArticulos *listaArticulos = malloc(sizeof(ListaArticulos));

    int cantArticulos = contarArticulos(articulos);
    listaArticulos->articulo = malloc(sizeof(Articulo)*cantArticulos);
    listaArticulos = cargarLista(articulos,cantArticulos);
    fclose(articulos);

    printf("\n");
    int cantPromociones;
    printf("Ingrese el numero de promociones: ");
    scanf("%d",&cantPromociones);
    printf("\n");

    listaPromociones->promocion = malloc(sizeof(Promocion)*cantPromociones); //ERROR ANTES ASIGNABA ESPACIO DE MEMORIA CORRESPONDIENTE A PROMOCION EN listaPromociones
    listaPromociones = cargarPromociones(listaArticulos, cantPromociones, cantArticulos);
    
    guardarPromociones(promociones,listaPromociones,cantPromociones);
    fclose(promociones);

    liberarMemoria(listaArticulos,listaPromociones,cantArticulos,cantPromociones);

return 1;
}