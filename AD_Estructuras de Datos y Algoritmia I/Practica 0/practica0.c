#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define AUMENTADOR 10
#define CANT_CARTAS 48

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
// EJ 12
struct _Cords2D{
    float x;
    float y;
};

struct _Cords2D punto_medio(struct _Cords2D cord1, struct _Cords2D cord2){
    struct _Cords2D cordMedia;
    cordMedia.x = (cord1.x + cord2.x) / 2;
    cordMedia.y = (cord1.y + cord2.y) / 2;
    return cordMedia;
}
void mostrar_cord(struct _Cords2D cord){
    printf("(%f,%f)\n",cord.x, cord.y);
}
// EJ 13
enum Palo{
    basto,
    espada,
    oro,
    copa
};
struct _Carta{
    enum Palo palo;
    int numero;
};
typedef struct _Carta Mazo[CANT_CARTAS];

void llenar_Mazo(Mazo *mazo){
    for(int i = 0 ; i < CANT_CARTAS ; i++){
        struct _Carta carta;
        if(i < 12){
            carta.palo = espada;
            carta.numero = i + 1;
        }
        else if(i < 24){
            carta.palo = basto;
            carta.numero = (i + 1) - 12;
        }
        else if(i < 36){
            carta.palo = copa;
            carta.numero = (i + 1) - 24;
        }
        else{
            carta.palo = oro;
            carta.numero = (i + 1) - 36;
        }

        mazo[0][i] = carta;
        
    }
}
void mostrar_carta(struct _Carta carta){
    switch (carta.palo){
        case basto:
            printf("Basto - ");
            break;
        case espada:
            printf("Espada - ");
            break;
        case oro:
            printf("Oro - ");
            break;
        case copa:
            printf("Copa - ");
            break;
        default:
            break;
    }
    printf("%i",carta.numero);
    printf("\n");
}
void mostrar_mazo(Mazo mazo){
    printf("\n");
    for(int i = 0 ; i < 48 ; i++){
        mostrar_carta(mazo[i]);
    }
}
struct _Carta azar(Mazo mazo){
    return mazo[rand() % CANT_CARTAS];
}


int main(){
    srand(time(NULL));
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

    // EJ 9 a
    // 4 5

    // EJ 9 b
    // 5 4

    // EJ 9 c
    // 9 2 3 4 5

    // EJ 9 d
    // 1 9 7 11 5

    // EJ 9 e
    // 5 15 15

    // EJ 9 f
    // Warning: retorna la direccion de una variable local

    // EJ 9 g
    // Copia el texto b en el texto a

    // EJ 10
    // No esta copiando la cadena. Reserva la misma cantidad de memoria y luego hace que otro puntero
    // apunte al primer elemento de la misma cadena. No la esta copiando en un espacio de memoria separado
    // solo esta haciendo que otro puntero apunte a la misma direccion de memoria

    // EJ 11 a
    // 123 123

    // EJ 11 b
    // No llega al printf, falla antes

    // EJ 12
    // struct _Cords2D cord1;
    // cord1.x = 5;
    // cord1.y = 6;

    // struct _Cords2D cord2;
    // cord2.x = 10;
    // cord2.y = 12;

    // struct _Cords2D cordMedia = punto_medio(cord1, cord2);
    // mostrar_cord(cord1);
    // mostrar_cord(cord2);
    // mostrar_cord(cordMedia);

    // EJ 13
    // Mazo mazo;
    // llenar_Mazo(&mazo);
    // mostrar_mazo(mazo);
    // struct _Carta carta = azar(mazo);
    // mostrar_carta(carta);

    // EJ 14











    return 0;
}