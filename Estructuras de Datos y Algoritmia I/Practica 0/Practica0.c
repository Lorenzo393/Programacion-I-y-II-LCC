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
char *get_new_line(){
    char aux[100];
    scanf("%[^\n]",aux);
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

//EJ 8
int sucesor(int n){
    return n+1;
}
void imprimir(int n){
    printf("%d \n",n);
}
//a
int apply(int (*f) (int), int a){
    return f(a);
}
//b
void apply_in(int (*f) (int), int *a){
    *a = f(*a);
}
//c
typedef void (*VisitorFunc) (int);

void recorre(VisitorFunc f,int arr[],int len){
    for(int i = 0 ; i < len ; i++){
        f(arr[i]);
    }
}

//EJ 9 VOLVER A PENSAR EL D
/*
    a)
    # include <stdio.h>
    int main() {
        int* punt;
        int x = 7 , y = 5;
        punt = &x;
        *punt = 4;
        printf ("%d%d", x , y);
        
        return 0;
    } //IMPRIME EN PANTALLA 4 y 5

    b)
    # include <stdio.h>
    int main() {
        int* punt;
        int x = 7 , y = 5;
        punt = &x;
        x = 4;
        punt = &y;
        printf ("%d%d", *punt , x);

        return 0;
    } //IMPRIME 5 y 4

    c)
    # include <stdio.h>
    int main() {
        int *punt , i;
        int x [] = {1 , 2 , 3 , 4 , 5};
        punt = x;
        *punt = 9;
        for (i = 0; i < 5; i ++) printf ("%d,", x [i]);

        return 0;
    }//IMPRIME [9,2,3,4,5]

    d)
    # include <stdio.h>
    int main() {
        int *punt , i;
        int x[5] = {1 , 2 , 3 , 4 , 5};
        punt = &x[0] + 3;
        *(punt - 2) = 9;
        punt --;
        *(punt) = 7;
        punt [1] = 11;
        punt = x;
        for( i = 0; i < 5; i ++) printf ("%d,", punt [i]) ;

        return 0;
    }//IMPRIME [1,9,7,11,5] VOLVER A PENSAR

    e)
    # include <stdio.h>
    void aumentar_punteros (int *x , int *y , int z) {
        *x = *x + 2;
        *y = *y + 5;
        z = z + 4;
    }

    int main() {
        int x , y , z;
        x = 3;
        y = 10;
        z = 15;
        aumentar_punteros (&x , &y , z);
        printf ("%d %d %d", x , y , z);

        return 0;
    }

    f) 
    #include <stdio.h>
    int *direccion_local(int x) {
        return &x;
    }

    int main() {
    int *ptr = NULL;
    ptr = direccion_local(2);
    printf ("%d\n", *ptr);

    return 0;
    }

    g) # include <stdio.h>
    int main() {
        char textoA [30] = "Agarrate Catalina";
        char textoB [30] = "El Cuarteto de Nos";
        char *p = textoA;
        char *q = textoB;
        printf ("textoA: %s\ ntextoB : %s\n", textoA , textoB);
        while(*p ++ = *q ++);
        printf("while (*p++ = *q++) ;\n");
        printf("textoA : %s\ ntextoB : %s\n", textoA , textoB);

        return 0;
    }
*/













int main(){
    //imprimir_direcciones_memoria();
    //set_first(arr);
    //set_in(p);
    //swap(a,b);
    //char *linea = get_new_line();
    //reservar_memoria_error();
    //a = apply(sucesor,a);
    //apply_in(sucesor,a);
    //recorre(imprimir,arr,len);

    return 0;
}
