#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define CANT_MATERIAS_BASE 5
#define MULT_MATERIAS 2
#define BUFFER_SIZE 100

typedef struct _materia{
    char *nombre;
    int diasMateria;
}Materia;

typedef struct _aulas{
    int cantAulas;
    int cantMaterias;
    int capacidad;
    Materia *materias;
} Aula;

// 1 - 3 dias maximo por materia
// Lunes - Viernes Que dias esta la materia
// 8 - 19 horario de clases 
// 1 - 4 horas duracion de materias

void mostrar_aula(Aula aula){
    printf("%i\n",aula.cantAulas);
    for(int i = 0 ; i < aula.cantMaterias ; i++){
        printf("%s\n",aula.materias[i].nombre);
    }
}

void quitar_terminador(char buffer[]){
    buffer[strlen(buffer)-1] = '\0';
}

int cargar_cantAulas(FILE *materias){
    char buffer[BUFFER_SIZE];
    fgets(buffer,sizeof(buffer),materias);

    int cant_aulas = 0;
    quitar_terminador(buffer);
    cant_aulas = atoi(buffer);

    return cant_aulas;
}

char *cargar_cadena(char buffer[]){
    quitar_terminador(buffer);
    char *cadena = malloc(sizeof(char) * strlen(buffer)+ 1);
    strcpy(cadena,buffer);
    cadena[strlen(cadena)] = '\0';
    return cadena;
}

Materia *borrar_copias(Aula aula){
    /*
    for(int i = 0 ; i < aula.cantMaterias ; i++){
        int flag = 1;
        for(int idx1 = 0, idx2 = 0; flag ;){
            if
        }
    }
    */
    return aula.materias;
}

Aula cargar_materias(FILE * materias, Aula aula){
    char buffer[BUFFER_SIZE];
    while(fgets(buffer,sizeof(buffer),materias) != NULL){
        if(aula.cantMaterias < aula.capacidad){
            aula.materias[aula.cantMaterias].nombre = cargar_cadena(buffer);
            aula.cantMaterias++;
        }
        else{
            aula.materias = realloc(aula.materias,sizeof(Materia) * (aula.capacidad * MULT_MATERIAS));
            aula.materias[aula.cantMaterias].nombre = cargar_cadena(buffer);
            aula.cantMaterias++;
        }
    }
    aula.materias = borrar_copias(aula);
    return aula;
}


void cargar_datos(FILE *materias, Aula aula){
    aula.cantAulas = cargar_cantAulas(materias);
    aula = cargar_materias(materias, aula);
    mostrar_aula(aula);
    
    
    
    
    

}

Aula inicializar_aulas(){
    Aula aulas;
    aulas.cantAulas = 0;
    aulas.cantMaterias = 0;
    aulas.materias = malloc(sizeof(Materia) * CANT_MATERIAS_BASE);
    aulas.capacidad = CANT_MATERIAS_BASE;
    return aulas;
}

int main(){
    Aula aula = inicializar_aulas();
    FILE *materias = fopen("materias.txt","r");
    cargar_datos(materias,aula);
    fclose(materias);

    return 0;
}