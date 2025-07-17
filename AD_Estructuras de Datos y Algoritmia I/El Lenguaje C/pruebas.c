#include <stdlib.h>
#include <stdio.h>


//Variable static dentro de una funcion
void incrementar_contador(){
    static int contador = 0;    // Se inicia una sola vez
    contador++;
    printf("%i\n",contador);
}

// Aritmetica de punteros
int strleng(char *s){
    char *p = s;
    while(*p != '\0'){
        p++;
    }
    return p - s; // Resta la pos en memoria de p con la de s para sacar la longitud
}

int main(){
    // Variable static dentro de una funcion
    // incrementar_contador(); //1
    // incrementar_contador(); //2
    // incrementar_contador(); //3
    // incrementar_contador(); //4

    // Aritmetica de punteros
    char texto[] = {"cadena de texto"}; //len = 15
    printf("%i",strleng(texto));





    return 0;
}