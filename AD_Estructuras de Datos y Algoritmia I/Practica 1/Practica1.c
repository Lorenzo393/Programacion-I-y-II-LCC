#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

//EJ 1
void mostrar_arreglo(float arreglo[], int len){
    for(int i = 0 ; i < len ; i++){
        printf("%.2f - ",arreglo[i]);
    }
}

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

int even(int n){
    return (n % 2 == 0);
}

void copia_arreglo(float arr1[],float arr2[],int len){
    for(int i = 0 ; i < len ; i++){
        arr1[i] = arr2[i];
    }
}

float mediana(float arreglo[], int len){
    float aux[len];
    copia_arreglo(aux,arreglo,len);
    bubble_sort(aux,len);
    if(!even(len)) return aux[(len/2)];
    else return (aux[(len/2) - 1] + aux[(len/2)]) / 2;
}

//EJ 2
int string_len(char *str){
    int len = 0;
    while(str[len] != '\0') len++;
    return len;
}

void string_reverse(char *str){
    for(int i = 0 , j = string_len(str) - 1; i < j ; i++ , j--){
        char aux = str[i];
        str[i] = str[j];
        str[j] = aux;
    }
}

int main(){
    // EJ 1
    //float arreglo[] = {7.4,4,2,1,5,7,4.3};
    //int len = 7;
    //float medio = mediana(arreglo,len);
    //printf("%.2f\n",medio);
    //mostrar_arreglo(arreglo,len);
    
    // EJ 2
    //int len = string_len("hola puta");
    //printf("%i",len);
    // -
    //char cadena[] = {"hola perra"};
    //string_reverse(cadena);
    //printf("%s",cadena);
    // -




}