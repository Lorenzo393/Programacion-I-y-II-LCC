#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define CANT_PERSONAS_BASE 10
#define CANT_LOCALIDADES_BASE 10
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

typedef struct _listaLocalidades{
    char *localidades;
    int cantLocalidades;
    int capacidad;
}ListaLocalidades;

void mostrar_ListaPersonas_limited(ListaPersonas listaPersonas){
    for(int i = 0 ; i < listaPersonas.cantPersonas ; i++){
        printf("%s - %s - %c - %i - %s\n",listaPersonas.persona[i].nombre,listaPersonas.persona[i].apellido,listaPersonas.persona[i].genero,listaPersonas.persona[i].edad,listaPersonas.persona[i].generoInt);
    }
}

char *leer_linea(char buffer[], FILE* file){
    return fgets(buffer,SIZE_BUFFER_BASE,file);
}

void quitar_terminador(char buffer[]){
    buffer[strlen(buffer)-1] = '\0';
}

char *cargar_cadena(int indiceBuffer, char buffer[]){
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

Persona cargar_Personas(char buffer[]){
    Persona persona;
    int indiceBuffer = 0;

    persona.nombre = cargar_cadena(indiceBuffer,buffer);
    indiceBuffer = strlen(persona.nombre) + 1;

    persona.apellido = cargar_cadena(indiceBuffer,buffer);
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
    return listaPersonas;
}
/*
ListaPersonas cargar_EntradaLocalidades(FILE *fileLocalidades, ListaPersonas listaPersonas){
    char buffer[SIZE_BUFFER_BASE];
    //char **localidades = malloc((char **)  CANT_LOCALIDADES_BASE);

    while(leer_linea(buffer,fileLocalidades) != NULL){
        quitar_terminador(buffer);
        printf("%s",buffer);
    }
    
    return listaPersonas;
}
*/
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

ListaPersonas cargar_datos_aleatorios(ListaPersonas listaPersonas){
    for(int i = 0 ; i < listaPersonas.cantPersonas ; i++){
        listaPersonas.persona[i].edad = rand() % EDAD_MAXIMA;
        listaPersonas.persona[i].generoInt = asignar_generoInt();
    }

    return listaPersonas;
}

ListaPersonas inicializar_ListaPersonas(){
    ListaPersonas listaPersonas;
    listaPersonas.persona = malloc(sizeof(Persona) * CANT_PERSONAS_BASE);
    listaPersonas.capacidad = CANT_PERSONAS_BASE;
    listaPersonas.cantPersonas = 0;
    return listaPersonas;
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

    /*
    FILE *fileLocalidades = fopen("entrada_localidades.txt","r");
    if(fileLocalidades == NULL){
        printf("Error al abrir \"entrada_personas.txt\" "); 
        return 1;
    }
    listaPersonas = cargar_EntradaLocalidades(fileLocalidades,listaPersonas);
    fclose(fileLocalidades);
    */

    listaPersonas = cargar_datos_aleatorios(listaPersonas);

    mostrar_ListaPersonas_limited(listaPersonas);

    //imprimir_datos_archivo(fileDatosPersonas,listaPersonas);
    return 0;
}