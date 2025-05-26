#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

typedef struct _Articulo{
    char *nombre;
    int precio;
}Articulo;

int main(){
    
    FILE* fileArticulos = fopen("articulos.txt","r");
    
    //int cantPromociones = 0;
    //printf("Ingrese la cantidad de promociones: ");
    //scanf("%d",&cantPromociones);

    char buffer[100];
    int largoLinea = 0;
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    
    fgets(buffer,100,fileArticulos);
    largoLinea = strlen(buffer) - 1;
    buffer[largoLinea] = '\0';
    printf("\nline: %s",buffer);
    //EOF
    fgets(buffer,100,fileArticulos);
    printf("\n");
    if(buffer[1] == EOF) printf("EOF");
    else printf("Nai");
    //largoLinea = strlen(buffer) - 1;
    //buffer[largoLinea] = '\0';
    //printf("\nline: %s",buffer);

    //YA HICE LA SUPUESTA RECURSION AHORA LO QUE ME FALTA ES DETERMINAR EL METODO PARA TERMINARLA Y LUEGO METER TODO EN UN BUCLE
    
    
    

return 0;
}
