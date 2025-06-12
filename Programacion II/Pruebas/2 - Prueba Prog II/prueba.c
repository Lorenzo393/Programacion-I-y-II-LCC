#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MEMORIA_BASE_STRUCT 10
#define SIZE_BUFFER_BASE 100
#define MULT_CAPACIDAD 5
#define EDAD_MAXIMA 100
#define RANGO_GENEROINT 4

typedef struct _persona{
    char *nombre, *apellido, *generoInt, *localidad;
    char genero;
    int edad;
} Persona;

typedef struct _listaPersonas{
    Persona *persona;
    int cantPersonas;
    int capacidad;
} ListaPersonas;

typedef struct _localidades{
    char *nombre;
}Localidad;

typedef struct _listaLocalidades{
    Localidad *localidades;
    int cantLocalidades;
    int capacidad;
}ListaLocalidades;

void mostrar_ListaPersonas(ListaPersonas listaPersonas){
    for(int i = 0 ; i < listaPersonas.cantPersonas ; i++){
        printf("%s - %s - %c - %i - %s - %s\n",listaPersonas.persona[i].nombre,listaPersonas.persona[i].apellido,listaPersonas.persona[i].genero,listaPersonas.persona[i].edad,listaPersonas.persona[i].generoInt,listaPersonas.persona[i].localidad);
    }
}

void mostrar_ListaLocalidades(ListaLocalidades listaLocalidades){
    for(int i = 0 ; i < listaLocalidades.cantLocalidades ; i++){
        printf("%s\n",listaLocalidades.localidades[i].nombre);
    }
}

char *leer_linea(char buffer[], FILE* file){
    return fgets(buffer,SIZE_BUFFER_BASE,file);
}

void quitar_terminador(char buffer[]){
    buffer[strlen(buffer)-1] = '\0';
}

char *cargar_cadena_coma(int indiceBuffer, char buffer[]){
    char aux[SIZE_BUFFER_BASE];
    int indiceAux;
    for(indiceAux = 0 ; buffer[indiceBuffer] != ',' ; indiceAux++, indiceBuffer++){
            aux[indiceAux] = buffer[indiceBuffer];
        }
    aux[indiceAux] = '\0';

    char *cadena = malloc(sizeof(char) * strlen(aux) + 1);
    strcpy(cadena,aux);
    cadena[strlen(cadena)] = '\0';

    return cadena;
}

char *cargar_cadena_saltoLinea(char buffer[]){
    quitar_terminador(buffer);
    char *cadena = malloc(sizeof(char) * strlen(buffer) + 1);
    strcpy(cadena,buffer);
    cadena[strlen(cadena)] = '\0';

    return cadena;
}

Persona cargar_Personas(char buffer[]){
    Persona persona;
    int indiceBuffer = 0;

    persona.nombre = cargar_cadena_coma(indiceBuffer,buffer);
    indiceBuffer = strlen(persona.nombre) + 1;

    persona.apellido = cargar_cadena_coma(indiceBuffer,buffer);
    indiceBuffer += strlen(persona.apellido) + 1;

    persona.genero = buffer[indiceBuffer];

    return persona;
}

ListaPersonas cargar_EntradaPersonas(FILE* filePersonas, ListaPersonas listaPersonas){
    char buffer[SIZE_BUFFER_BASE];
    while(leer_linea(buffer,filePersonas) != NULL){
        if(listaPersonas.cantPersonas < listaPersonas.capacidad){
            listaPersonas.persona[listaPersonas.cantPersonas] = cargar_Personas(buffer);
            listaPersonas.cantPersonas++;
        }
        else{
            int nuevaCapacidad = listaPersonas.capacidad * MULT_CAPACIDAD;
            listaPersonas.persona = realloc(listaPersonas.persona,(sizeof(Persona)*nuevaCapacidad));
            listaPersonas.capacidad = nuevaCapacidad;
            listaPersonas.persona[listaPersonas.cantPersonas] = cargar_Personas(buffer);
            listaPersonas.cantPersonas++;
        }
    }
    if(leer_linea(buffer,filePersonas) == NULL) printf("\nEOF\n");
    return listaPersonas;
}

ListaLocalidades cargar_EntradaLocalidades(FILE *fileLocalidades, ListaLocalidades listaLocalidades){
    char buffer[SIZE_BUFFER_BASE];
    while(leer_linea(buffer,fileLocalidades) != NULL){
        if(listaLocalidades.cantLocalidades < listaLocalidades.capacidad){
            listaLocalidades.localidades[listaLocalidades.cantLocalidades].nombre = cargar_cadena_saltoLinea(buffer);
            listaLocalidades.cantLocalidades++;
        }
        else{
            int nuevaCapacidad = listaLocalidades.capacidad * MULT_CAPACIDAD;
            listaLocalidades.localidades = realloc(listaLocalidades.localidades,(sizeof(Localidad) * nuevaCapacidad));
            listaLocalidades.capacidad = nuevaCapacidad;
            listaLocalidades.localidades[listaLocalidades.cantLocalidades].nombre = cargar_cadena_saltoLinea(buffer);
            listaLocalidades.cantLocalidades++;
        }
    }
    if(leer_linea(buffer,fileLocalidades) == NULL) printf("\nEOF\n");
    return listaLocalidades;
}

char *copiar_cadena(char cadena[]){  
    char *generoInt = malloc(sizeof(char) * strlen(cadena)+1);
    strcpy(generoInt,cadena);
    generoInt[strlen(generoInt)] = '\0';
    return generoInt;
}

char *asignar_generoInt(){
    int generoIntRand = rand() % RANGO_GENEROINT;
    char *generoInt;
    switch(generoIntRand){
        case 0:
            generoInt = copiar_cadena("F");
            break;
        case 1:
            generoInt = copiar_cadena("M");
            break;
        case 2:
            generoInt = copiar_cadena("Ninguno");
            break;
        case 3:
            generoInt = copiar_cadena("Ambos");
            break;
    }
    return generoInt;
}

char *asignar_Localidad(ListaLocalidades listaLocalidades){
    int nLocalidad = rand() % listaLocalidades.cantLocalidades;
    char *cadena = malloc(sizeof(char) * (strlen(listaLocalidades.localidades[nLocalidad].nombre)+1));
    strcpy(cadena,listaLocalidades.localidades[nLocalidad].nombre);
    cadena[strlen(listaLocalidades.localidades[nLocalidad].nombre)] = '\0';
    return cadena;
}

void imprimir_datos_archivo(FILE *file, ListaPersonas listaPersonas){
    for(int i = 0 ; i < listaPersonas.cantPersonas ; i++){
        fprintf(file,"%s,%s,%c,%i,%s,%s\n",listaPersonas.persona[i].nombre,listaPersonas.persona[i].apellido,listaPersonas.persona[i].genero,listaPersonas.persona[i].edad,listaPersonas.persona[i].generoInt,listaPersonas.persona[i].localidad);
    }
}

ListaPersonas cargar_datos_aleatorios(ListaPersonas listaPersonas, ListaLocalidades listaLocalidades){
    for(int i = 0 ; i < listaPersonas.cantPersonas ; i++){
        listaPersonas.persona[i].edad = rand() % EDAD_MAXIMA;
        listaPersonas.persona[i].generoInt = asignar_generoInt();
        listaPersonas.persona[i].localidad = asignar_Localidad(listaLocalidades);
    }
    return listaPersonas;
}

void free_ListaLocalidades(ListaLocalidades *listaLocalidades){
    for(int i = 0 ; i < listaLocalidades->cantLocalidades ; i++){
        free(listaLocalidades->localidades[i].nombre);
    }
    listaLocalidades->cantLocalidades = 0;
}

void free_ListaPersonas(ListaPersonas *listaPersonas){
    for(int i = 0 ; i < listaPersonas->cantPersonas ; i++){
        free(listaPersonas->persona[i].nombre);
        free(listaPersonas->persona[i].apellido);
        free(listaPersonas->persona[i].generoInt);
        free(listaPersonas->persona[i].localidad);
    }
    listaPersonas->cantPersonas = 0;
}

ListaPersonas inicializar_ListaPersonas(){
    ListaPersonas listaPersonas;
    listaPersonas.persona = malloc(sizeof(Persona) * MEMORIA_BASE_STRUCT);
    listaPersonas.capacidad = MEMORIA_BASE_STRUCT;
    listaPersonas.cantPersonas = 0;
    return listaPersonas;
}

ListaLocalidades inicializar_ListaLocalidades(){
    ListaLocalidades listaLocalidades;
    listaLocalidades.localidades = malloc(sizeof(Localidad) * MEMORIA_BASE_STRUCT);
    listaLocalidades.capacidad = MEMORIA_BASE_STRUCT;
    listaLocalidades.cantLocalidades = 0;
    return listaLocalidades;
}

int main(){
    srand(time(NULL));

    FILE *filePersonas = fopen("entrada_personas.txt","r");
    if(filePersonas == NULL){
        printf("Error al abrir \"entrada_personas.txt\" ");
        return 1;
    }
    ListaPersonas listaPersonas = inicializar_ListaPersonas();
    listaPersonas = cargar_EntradaPersonas(filePersonas,listaPersonas);
    fclose(filePersonas);

    
    FILE *fileLocalidades = fopen("entrada_localidades.txt","r");
    if(fileLocalidades == NULL){
        printf("Error al abrir \"entrada_localidades.txt\" "); 
        return 1;
    }
    ListaLocalidades listaLocalidades = inicializar_ListaLocalidades();
    listaLocalidades = cargar_EntradaLocalidades(fileLocalidades,listaLocalidades);
    fclose(fileLocalidades);
    
    listaPersonas = cargar_datos_aleatorios(listaPersonas,listaLocalidades);
    free_ListaLocalidades(&listaLocalidades);
    
    FILE *fileSalida = fopen("salida.txt","w");
    if(fileSalida == NULL){
        printf("Error al escribir en archivo \"salida.txt\" ");
        return 1;
    }
    imprimir_datos_archivo(fileSalida,listaPersonas);
    free_ListaPersonas(&listaPersonas);
    fclose(fileSalida);

    return 0;
}