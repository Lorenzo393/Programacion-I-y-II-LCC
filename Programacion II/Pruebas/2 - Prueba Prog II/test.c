#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int recorre(char buffer[]){
    int largo = strlen(buffer) - 1;
    while((buffer[largo] == '\n' || buffer[largo] == ' ') && largo > 0) largo--;
    return largo + 1;
}

int main (){
    FILE *test = fopen("entrada_localidades.txt","r");
    char buffer[100];
    int largo = 0;
    /*
    while(buffer[largo] >= 32 && buffer[largo] <= 126) {
        printf("1");
        largo++;
    }
    printf("\n%s",buffer);
    if(buffer[20] == ' ') printf("yey");
    else printf("Nai");
    printf("\nlargo: %i",largo);
    */
    for(int i = 0 ; i < 100 ; i++){
        fgets(buffer,100,test);
        printf("\n1: %i",strlen(buffer));
        largo = recorre(buffer);
        printf("\n2: %i",largo);
    }
    

    


    return 0;
}