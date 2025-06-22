#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define CANT_MATERIAS_BASE 5
#define MULT_MATERIAS 2
#define BUFFER_SIZE 100

// 0 false - !0 true

typedef struct _materia{
    char *nombre;
    int diasMateria;
}Materia;

typedef struct _aulas{
    int *cantMaterias;
    int cantAulas;
    int capacidad;
    Materia *materias;
} Aula;

// 1 - 3 dias maximo por materia
// Lunes - Viernes Que dias esta la materia
// 8 - 19 horario de clases 
// 1 - 4 horas duracion de materias

void mostrar_aula(Aula aula){
    printf("%i\n",aula.cantAulas);
    for(int i = 0 ; i < *(aula.cantMaterias) ; i++){
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

Materia *reordenar_cadena(int cadenaComp, int cantMaterias, Materia *materias){
    if(!(cadenaComp == cantMaterias)){
        while(cadenaComp < (cantMaterias - 1)){
                materias[cadenaComp] = materias[cadenaComp + 1];
                cadenaComp++;
            }
    }
    return materias;
}

void borrar_copias(Materia *materias, int *cantMaterias){
    for(int cadenaBase = 0 ; cadenaBase < (*cantMaterias) ; cadenaBase++){ 
        for(int cadenaComp = (cadenaBase + 1); cadenaComp < (*cantMaterias) ;){
            if(!strcmpi(materias[cadenaBase].nombre,materias[cadenaComp].nombre)){
                materias = reordenar_cadena(cadenaComp, (*cantMaterias), materias);
                (*cantMaterias) -= 1;
            }
            else{
                cadenaComp++;
            }
        }
    }
}

Aula cargar_materias(FILE *materias, Aula aula){
    char buffer[BUFFER_SIZE];
    while(fgets(buffer,sizeof(buffer),materias) != NULL){
        if(*(aula.cantMaterias) < aula.capacidad){
            aula.materias[*(aula.cantMaterias)].nombre = cargar_cadena(buffer);
            *(aula.cantMaterias) += 1;
        }
        else{
            aula.materias = realloc(aula.materias,sizeof(Materia) * (aula.capacidad * MULT_MATERIAS));
            aula.materias[*(aula.cantMaterias)].nombre = cargar_cadena(buffer);
            *(aula.cantMaterias) += 1;
        }
    }
    return aula;
}

Aula cargar_datos(FILE *materias, Aula aula){
    aula.cantAulas = cargar_cantAulas(materias);
    aula = cargar_materias(materias, aula);
    return aula;
}

Aula inicializar_aulas(){
    Aula aulas;
    aulas.cantAulas = 0;
    aulas.cantMaterias = malloc(sizeof(int));
    *(aulas.cantMaterias) = 0;
    aulas.materias = malloc(sizeof(Materia) * CANT_MATERIAS_BASE);
    aulas.capacidad = CANT_MATERIAS_BASE;
    return aulas;
}

int main(){
    Aula aula = inicializar_aulas();
    FILE *materias = fopen("materias.txt","r");
    aula = cargar_datos(materias,aula);
    fclose(materias);

    borrar_copias(aula.materias, aula.cantMaterias);
    
    mostrar_aula(aula);

    

    return 0;
}