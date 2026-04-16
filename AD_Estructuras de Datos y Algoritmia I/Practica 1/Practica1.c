#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int string_len(char *str);

// EJ 1
void bubble_sort(float arreglo[], int longitud) {
    for (int iter = 0 ; iter < longitud - 1 ; iter++) {
        for (int i = 0 ; i < longitud - iter - 1; i++) {
            if (arreglo[i] > arreglo[i + 1]) {
            float aux = arreglo[i];
            arreglo[i] = arreglo[i + 1];
            arreglo[i + 1] = aux;
            }
        }
    }
}
void mostrar_arreglo(float arreglo[], int longitud){
    for(int i = 0 ; i < longitud ; i++){
        printf("%f - ",arreglo[i]);
    }
}
void copia_arreglo(float arreglo1[], float arreglo2[], int longitud){
    for(int i = 0 ; i < longitud ; i++){
        arreglo1[i] = arreglo2[i];
    }
}
float mediana(float arreglo[], int longitud){
    float arregloAux[longitud];
    copia_arreglo(arregloAux, arreglo, longitud);
    bubble_sort(arregloAux,longitud);

    float valorMedio = -1;
    if((longitud % 2) == 0){
        valorMedio = (arregloAux[longitud/2] + arregloAux[(longitud/2)+1]) / 2;
    }
    else{
        valorMedio = arregloAux[longitud/2];
    }
    return valorMedio;
}
// EJ 2
char *copy_str(char copy[]){
    int copyLen = string_len(copy);
    char *str = malloc(sizeof(char) * (copyLen + 1));

    for(int i = 0 ; i < string_len(copy) ; i++){
        str[i] = copy[i];
    }
    str[copyLen] = '\0';

    return str;
}

// EJ 2a
int string_len(char *str){
    int largo = 0;
    while(str[largo] != '\0'){
        largo++;
    }
    return largo;
}
//EJ 2b
void string_reverse(char* str){
    for(int i = string_len(str) - 1, j = 0 ; i+1 != j ; j++, i--){
        char aux = str[i];
        str[i] = str[j];
        str[j] = aux;
    }
}
// EJ 2c
int string_concat(char* str1, char* str2, int max){
    int str1Len = string_len(str1), str2Len = string_len(str2);
    if(max > str2Len) max = str2Len;

    //str1 = realloc(str1, sizeof(char) * (str1Len + max + 1));
    //if(!str1) printf("\nError al guardar memoria"); //EXPLOTA SI TRATO DE REALLOCAR MEMORIA

    for(int i = str1Len, j = 0 ; i < (str1Len + max) ; i++, j++){
        printf("%i %i -",i,j);
        str1[i] = str2[j];
    }
    str1[str1Len + max] = '\0';

    return max;
}
// EJ 2d
int string_compare(char* str1, char* str2);




int main(){
    // float arreglo[10] = {9,4,5,7,8,0,1,3,2,6};
    // float medianas = mediana(arreglo, 9);
    // mostrar_arreglo(arreglo,9);
    // printf("\nmedio: %f",medianas);

    //char str1[] = "Cuando patrullas por el mojave casi te dan ganas de que llegue un invierno nuclear";
    //printf("%i",string_len(str1));
    //string_reverse(str1);
    //printf("%s",str1);
    char *str1 = copy_str("Cuando patrullas por el mojave");
    char *str2 = copy_str(" casi te dan ganas de que llegue un invierno nuclear");
    printf("%s\n%s\n",str1,str2);

    int cantConcat = string_concat(str1, str2, 7);
    printf("%i - %s", cantConcat, str1);


    return 0;
}