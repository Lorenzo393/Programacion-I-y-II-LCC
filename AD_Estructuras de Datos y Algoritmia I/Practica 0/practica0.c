#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define AUMENTADOR 10

// EJ 2
void set_first(int *arr){
    arr[0] = 0;
}
// EJ 3
void set_in(int *n){
    if(*n != 0) *n = 1;
}
// EJ 4
void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}
// EJ 6
char *get_new_line(){
    int size = 5;
    char *line = malloc(sizeof(char) * size);

    for(int i = 0, flag = 1 ; flag ; i++){
        line[i] = getchar();
        if(i+1 >= size){
            size = size + AUMENTADOR;
            line = realloc(line, sizeof(char) * size);
        }
        if(line[i] == '\n'){
            line = realloc(line, sizeof(char) * i+1);
            line[i] = '\0';
            flag = 0;
        }
    }
    return line;
}
// EJ 8
int mas_tres(int x){
    return x + 3;
}
void mostrar_entero(int x){
    printf("%i",x);
}
int sucesor (int n) {
    return n+1;
}
void imprimir (int n) {
    printf("%d \n", n);
}
// EJ 8 a
int apply(int (*f)(int), int x){
    return f(x);
}
// EJ 8 b
void apply_in(int (*f)(int), int *x){
    *x = f(*x);
}
// EJ 8 c
typedef void (*VisitorFunc)(int);
void recorre(VisitorFunc f, int arr[], int len){
    for(int i = 0 ; i < len ; i++){
        f(arr[i]);
    }
}

int main(){
    // EJ 1
    // char c[] = {'h','o','l','a','\0'};
    // printf("%p - %p - %p - %p - %p",c[0],c[1],c[2],c[3],c[4]);

    // EJ 2
    //int arr[] = {1,2,3,4,5};
    //set_first(arr);
    //printf("%i - %i - %i - %i - %i",arr[0],arr[1],arr[2],arr[3],arr[4]);

    // EJ 3
    //int *n = malloc(sizeof(int));
    //*n = 7;
    //set_in(n);
    //printf("%i",*n);

    // EJ 4
    //int *a = malloc(sizeof(int));
    //int *b = malloc(sizeof(int));
    //*a = 7;
    //*b = 5;
    //swap(a,b);
    //printf("%i - %i",*a,*b);

    // EJ 5
    // El malloc en caso de no poder reservar memoria retorna NULL

    // EJ 6
    //char *line = get_new_line();
    //printf("%s",line);

    // EJ 7
    // char *x = malloc(100);
    // free(x);
    // free(x);
    // No me tira error

    // EJ 8 a
    // int x = 5;
    // x = apply(mas_tres, x);
    // printf("%i",x);

    // EJ 8 b
    //int *x = malloc(sizeof(int));
    //*x = 5;
    //apply_in(mas_tres, x);
    //printf("%i",*x);

    // EJ 8 c
    //int arr[] = {1,2,3,4,5};
    //int len = 5;
    //recorre(mostrar_entero, arr, len);

    // EJ 8 d
    // int x = 5;
    // x = apply(sucesor, x);
    // printf("%i",x);

    // int *y = malloc(sizeof(int));
    // *y = 5;
    // apply_in(sucesor, y);
    // printf("%i",*y);

    // int arr[] = {1,2,3,4,5};
    // int len = 5;
    // recorre(imprimir, arr, len);

    return 0;
}