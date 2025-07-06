#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define CANT_MATERIAS_BASE 5
#define HORA_INICIO_HORA_FIN 2
#define HORA_MIN 8
#define HORA_MAX 19
#define CANT_HORAS_CLASES 11
#define MAX_HORAS 4
#define MIN_HORAS 1
#define MULT_MATERIAS 2
#define BUFFER_SIZE 100

// 0 false - !0 true

typedef struct _materia{
    char *nombre;
    char **dias;
    int **horas;
    int cantDias;
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
    printf("\n%i\n",aula.cantAulas);
    for(int i = 0 ; i < *(aula.cantMaterias) ; i++){
        printf("%s-%i\n",aula.materias[i].nombre,aula.materias[i].cantDias);
        for(int j = 0 ; j < aula.materias[i].cantDias ; j++){
            printf("%s %i a %i\n",aula.materias[i].dias[j],aula.materias[i].horas[j][0],aula.materias[i].horas[j][1]);
        }
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
                printf("Materia repetida: %i-%s | %i-%s\n",(cadenaBase+1),materias[cadenaBase].nombre,(cadenaComp+1),materias[cadenaComp].nombre);
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

Materia *cant_dias_materias(Materia *materias, int cantMaterias){
    for(int i = 0 ; i < cantMaterias ; i++){
        materias[i].cantDias = ((rand() % 3) + 1);
    }
    return materias;
}

char *fijo_dias(int diaRandom){ // 0 - lunes | 1 - martes | 2 - miercoles | 3 - jueves | 4 - viernes
    char *dia;
    switch(diaRandom){
        case 0:
            dia = malloc(sizeof(char) * strlen("Lunes") + 1);
            strcpy(dia,"Lunes");
            dia[strlen(dia)] = '\0';
            break;
        case 1:
            dia = malloc(sizeof(char) * strlen("Martes") + 1);
            strcpy(dia,"Martes");
            dia[strlen(dia)] = '\0';
            break;
        case 2:
            dia = malloc(sizeof(char) * strlen("Miercoles") + 1);
            strcpy(dia,"Miercoles");
            dia[strlen(dia)] = '\0';
            break;
        case 3:
            dia = malloc(sizeof(char) * strlen("Jueves") + 1);
            strcpy(dia,"Jueves");
            dia[strlen(dia)] = '\0';
            break;
        case 4:
            dia = malloc(sizeof(char) * strlen("Viernes") + 1);
            strcpy(dia,"Viernes");
            dia[strlen(dia)] = '\0';
            break;
    }
    return dia;
}

char **random_dias(int cantDias){
    char **dias = malloc(sizeof(char *) * cantDias);
    for(int i = 0 ; i < cantDias ; i++){
        dias[i] = fijo_dias(rand() % 5);
    }
    return dias;
}

Materia *asignar_dias_materias(Materia *materias, int cantMaterias){
    for(int i = 0 ; i < cantMaterias ; i++){
        materias[i].dias = random_dias(materias[i].cantDias);  
    }
    return materias;
}

int *calcular_horas(){
    int *horas = malloc(sizeof(int) * HORA_INICIO_HORA_FIN);    // Hora Inicio - Hora Fin - Hora inicio != 19 ya que minimo tienen que durar 1 hora
    horas[0] = HORA_MIN + rand() % CANT_HORAS_CLASES;           // horario de clases 8 - 19
    horas[1] = horas[0] + (MIN_HORAS + rand() % MAX_HORAS);     // 4 horas max duracion de clase
    if(horas[1] > HORA_MAX) horas[1] = HORA_MAX;
    return horas;
}

int **random_horas(int cantDias){
    int **horas = malloc(sizeof(int *) * cantDias);
    for(int i = 0 ; i < cantDias ; i++){
        horas[i] = calcular_horas();
    }
    return horas;
}

Materia *asignar_hora_materias(Materia *materias, int cantMaterias){
    for(int i = 0 ; i < cantMaterias ; i++){
        materias[i].horas = random_horas(materias[i].cantDias);
    }
    return materias;
}

void imprimir_salida(FILE *salida, Aula aula){
    fprintf(salida, "%i\n",aula.cantAulas);
    for(int i = 0 ; i < *(aula.cantMaterias) ; i++){
        fprintf(salida, "%s\n",aula.materias[i].nombre);
        for(int j = 0 ; j < aula.materias[i].cantDias ; j++){
            fprintf(salida, "%s %i a %i\n",aula.materias[i].dias[j],aula.materias[i].horas[j][0],aula.materias[i].horas[j][1]);
        }
    }
}

void free_aula(Aula *aula){
    for(int i = 0 ; i < *(aula->cantMaterias) ; i++){
        free(aula->materias[i].nombre);
        free(aula->materias[i].horas[0]);
        free(aula->materias[i].horas[1]);
        for(int j = 0 ; j < aula->materias[i].cantDias ; j++){
            free(aula->materias[j].dias);
            free(aula->materias[j].horas[0]);
            free(aula->materias[j].horas[1]);
        }
    }
    free(aula->materias);
    free(aula->cantMaterias);
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
    srand(time(NULL));
    Aula aula = inicializar_aulas();
    FILE *materias = fopen("materias.txt","r");
    aula = cargar_datos(materias,aula);
    fclose(materias);

    borrar_copias(aula.materias, aula.cantMaterias);
    aula.materias = cant_dias_materias(aula.materias, *(aula.cantMaterias));
    aula.materias = asignar_dias_materias(aula.materias, *(aula.cantMaterias));
    aula.materias = asignar_hora_materias(aula.materias, *(aula.cantMaterias));

    FILE *salida = fopen("salida.txt","w");
    imprimir_salida(salida,aula);
    fclose(salida);

    mostrar_aula(aula);
    free_aula(&aula);

    return 0;
}