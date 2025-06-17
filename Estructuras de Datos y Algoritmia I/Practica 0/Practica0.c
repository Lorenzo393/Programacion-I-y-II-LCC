#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void mostrar_array_int(int arr[], int len){
    for(int i = 0 ; i < len ; i++){
        printf("%i\n",arr[i]);
    }
}

void mostrar_array_char(char arr[], int len){
    for(int i = 0 ; i < len ; i++){
        printf("%c\n",arr[i]);
    }
}

void set_five_int(int arr[]){
    arr[0] = 9;
    arr[1] = 567;
    arr[2] = 23;
    arr[3] = 145;
    arr[4] = 51;
}

// EJ 1
void imprimir_direccion_memoria_1(){
    char arrc[5];
    int arri[5];

    printf("Array char:\n");
    mostrar_array_char(arrc,5);

    printf("Array int:\n");
    mostrar_array_int(arri,5);
    
}

// EJ 2
void set_first_2(int arr[]){
    arr[0] = 0;
}

// EJ 3
void set_in(int *n){
    if (*n != 0){
        *n = 1;
    }
}

// EJ 4
void swap(int *a, int *b){
    int *aux = malloc(sizeof(int));
    aux = a;
    a = b;
    b = aux;
}

int main(){
    // EJ 1
    //imprimir_direccion_memoria_1();

    // EJ 2
    //int arr[5] = {1,2,3,4,5};
    //set_first_2(arr);
    //mostrar_array_int(arr,5);

    // EJ 3
    //int *n = malloc(sizeof(int));
    //*n = 9;
    //set_in(n);
    //printf("%i",*n);
    //free(n);

    // EJ 4
    //int *a = malloc(sizeof(int));
    //int *b = malloc(sizeof(int));
    //*a = 9;
    //*b = 5;
    //swap(a,b);
    //printf("%i %i",*a,*b);
    //free(a);
    //free(b);

    return 0;
}