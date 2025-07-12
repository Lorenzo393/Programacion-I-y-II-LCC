#include <stdlib.h>
#include <stdio.h>


//Variable static dentro de una funcion
void incrementar_contador(){
    static int contador = 0;    // Se inicia una sola vez
    contador++;
    printf("%i\n",contador);
}



int main(){
    // Variable static dentro de una funcion
    incrementar_contador(); //1
    incrementar_contador(); //2
    incrementar_contador(); //3
    incrementar_contador(); //4






    return 0;
}