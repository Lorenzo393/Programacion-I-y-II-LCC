#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define CANT_MATERIAS_BASE 5
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
} Aulas;

// 1 - 3 dias maximo por materia
// Lunes - Viernes Que dias esta la materia
// 8 - 19 horario de clases 
// 1 - 4 horas duracion de materias
void quitar_terminador(char buffer[]){
    buffer[strlen(buffer)-1] = '\0';
}

int cargar_cantAulas(char buffer[]){
    int cant_aulas = 0;
    quitar_terminador(buffer);
    cant_aulas = atoi(buffer);
    return cant_aulas;
}

void cargar_materias(FILE *materias, Aulas aulas){
    char buffer[BUFFER_SIZE];
    fgets(buffer,sizeof(buffer),materias);
    aulas.cantAulas = cargar_cantAulas(buffer);
    
    
    

}

Aulas inicializar_aulas(){
    Aulas aulas;
    aulas.cantAulas = 0;
    aulas.cantMaterias = 0;
    aulas.materias = malloc(sizeof(Materia) * CANT_MATERIAS_BASE);
    aulas.capacidad = CANT_MATERIAS_BASE;
    return aulas;
}

int main(){
    Aulas aulas = inicializar_aulas();
    FILE *materias = fopen("materias.txt","r");
    cargar_materias(materias,aulas);
    fclose(materias);

    return 0;
}