#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define CANT_PERSONAS_BASE 10
#define SIZE_BUFFER_BASE 100

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

char *leer_linea(char buffer[], FILE* file){
    return fgets(buffer,SIZE_BUFFER_BASE,file);
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

Persona cargar_Persona(char buffer[]){
    Persona persona;
    int indiceBuffer = 0;

    persona.nombre = cargar_cadena(indiceBuffer,buffer);
    indiceBuffer = strlen(persona.nombre) + 1;

    persona.apellido = cargar_cadena(indiceBuffer,buffer);
    indiceBuffer += strlen(persona.apellido) + 1;

    persona.genero = buffer[indiceBuffer];

    return persona;
}

void cargar_ListaPersonas_EntradaPersonas(FILE* filePersonas, ListaPersonas listaPersonas){
    char buffer[SIZE_BUFFER_BASE];
    while(leer_linea(buffer,filePersonas) != NULL){
        Persona persona = cargar_Persona(buffer);

        
        printf("%s - %s - %c\n",persona.nombre,persona.apellido,persona.genero);
    }
    
}




ListaPersonas inicializar_ListaPersonas(){
    ListaPersonas listaPersonas;
    listaPersonas.persona = malloc(sizeof(Persona) * CANT_PERSONAS_BASE);
    listaPersonas.capacidad = CANT_PERSONAS_BASE;
    listaPersonas.cantPersonas = 0;
    return listaPersonas;
}

int main(){
    FILE *filePersonas = fopen("entrada_personas.txt","r");
    if(filePersonas == NULL){
        printf("Error al abrir \"entrada_personas.txt\" ");
        return 1;
    }
    ListaPersonas listaPersonas = inicializar_ListaPersonas();
    cargar_ListaPersonas_EntradaPersonas(filePersonas,listaPersonas);
    fclose(filePersonas);

    

    return 0;
}