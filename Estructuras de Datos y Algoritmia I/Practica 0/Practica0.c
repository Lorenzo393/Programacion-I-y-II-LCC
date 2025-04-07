#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//EJ 1
void imprimir_direcciones_memoria(){
    int largoTexto = 25;
    int *a = malloc(sizeof(int));
    double *b = malloc(sizeof(int));
    char *texto = malloc(sizeof(sizeof(char)*largoTexto));

    printf("%p-%p \n\n",&a,&b);
    for(int i = 0 ; i < largoTexto ; i++){
        printf("%p\n",&texto[i]);
    }
    free(a);
    free(b);
    free(texto);
}

//EJ 2
void set_first(int arr[]){
    arr[0] = 0;
}

//EJ 3
void set_in(int *p){
    if(*p != 0) *p = 1;
    else *p = 0;
}

//EJ 4
void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

//EJ 5
// Si el programa no puede reservar el espacio solicitado retornara NULL

//EJ 6
char *get_new_line(){ //SOLUCIONAR NO TOMA LOS ESPACIOS
    char aux[100];
    scanf("%s",aux);
    char *linea = malloc(sizeof(char)*strlen(aux)+1);
    strcpy(linea,aux);
    linea[strlen(aux)+1] = '\0';

    return linea;
}

//EJ 7
void reservar_memoria_error(){
    char *mem = malloc(100);
    free(mem);
    free(mem);
} //En windows nada, en linux daria error




















int main(){
    //char *linea;
    //imprimir_direcciones_memoria();
    //set_first(arr);
    //set_in(p);
    //swap(a,b);
    //linea = get_new_line();
    //printf("%s",linea);
    //reservar_memoria_error();
    


    return 0;
}
