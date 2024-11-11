#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define numeroSecreto 250

// SWITCH
//Ej 1
void caraOpuesta(){
    int dado;
    printf("Ingrese el n del dado: ");
    scanf("%d",&dado);

    switch(dado){
        case 1:
            printf("El numero opuesto es: 6");
            break;
        case 2:
            printf("El numero opuesto es: 5");
            break;
        case 3:
            printf("El numero opuesto es: 4");
            break;
        case 4:
            printf("El numero opuesto es: 3");
            break;
        case 5:
            printf("El numero opuesto es: 2");
            break;
        case 6:
            printf("El numero opuesto es: 1");
            break;
        default:
            printf("Numero ingresado incorrecto");
    }
}

//Ej 2
void habitaciones(){
    int numeroH;
    printf("Habitaciones:\n");
    printf("1.Azul\n2.Roja\n3.Verde\n4.Rosa\n5.Gris\n");
    printf("Ingrese el numero de la habitacion: ");
    scanf("%d",&numeroH);
    printf("\n");
    switch(numeroH){
        case 1:
            printf("Camas: 2 - Planta: primera");
            break;
        case 2:
            printf("Camas: 1 - Planta: primera");
            break;
        case 3:
            printf("Camas: 3 - Planta: segunda");
            break;
        case 4:
            printf("Camas: 2 - Planta: segunda");
            break;
        case 5:
            printf("Camas: 1 - Planta: tercera");
            break;
        default:
            printf("Numero no asociado a habitacion");
    }
}

// FOR
//Ej 3
void bucle1(){
    float suma = 0;
    for(int i = 1 ; i <= 100 ; i++){
        float division = (float) 1/i;
        suma = suma + division;
        printf(" %0.2f ",suma);
    }
    printf("\nLa suma total es: %0.2f",suma);
}

void bucle2(){
    float suma = 0;
    for(int i = 1 ; i <= 30 ; i++){
        float division = (float) 1/(pow(i,2));
        suma = suma + division;
        printf(" %0.2f ",suma);
    }
    printf("\nLa suma total es: %0.2f",suma);
}

void bucle3(){
    float suma = 0;
    for(int i = 1 ; i <= 25 ; i++){
        float division = (float) 1/(pow(i,i));
        suma = suma + division;
        printf(" %0.2f ",suma);
    }
    printf("\nLa suma total es: %0.2f",suma);
}

void bucle4(){
    float suma = 0;
    for(int i = 2 ; i <= 10 ; i++){
        float division = (float) 1/((i+1)*i);
        suma = suma + division;
        printf(" %0.2f ",suma);
    }
    printf("\nLa suma total es: %0.2f",suma);
}

//Ej 4
void ternasPit(){
    for(int b = 1; b <= 30 ; b++){
        for(int a = 1 ; a <= 20; a++){
            float c = (float) sqrt(pow(a,2) + pow(b,2));
            printf("%d^2 + %d^2 = %0.2f^2",a,b,c);
            printf("\n");
        }
    }
}

/*
Ej 5: ¿Que hace el siguiente programa?

int main () {
    int x , y;
    printf ("Ingrese dos enteros dentro del rango [1 ,20]:\ n") ;
    scanf ("%d %d",&x,&y);
    if ( x >= 1 && y >= 1 && x <= 20 && y <= 20){
        for (int i = 1; i <= y ; i ++){
            for (int j = 1; j <= x ; j ++){
                printf ("@");
            }
        printf ("\n");
        }
    } 
    else printf("Los enteros no se encuentran en el rango pedido ");
    return 0;
}

 Primero te pide ingresar dos enteros x e y en un rango de [1,20] si tienen ese rango
entran a un bucle for anidado que basicamente imprime "x" arrobas y luego un salto de
linea y hace esto "y" veces. Si no estan en el rango [1,20] imprime un mensaje de error
*/

//Ej 6
void adivinarNumero(){
    int n = -1;
    for(int intentos = 15; intentos > 0 && n != numeroSecreto ; intentos--){
        printf("Ingrese el numero secreto: ");
        scanf("%d",&n);
        if(n > numeroSecreto) printf("El numero secreto es menor\n");
        if(n < numeroSecreto) printf("El numero secreto es mayor\n");
    }
}

//Ej 7
char convLetra(int p){
    char letra;
    if(p == 5) letra = 'T';
    if(p == 4) letra = 's';
    if(p == 3) letra = 'R';
    if(p == 2) letra = 'q';
    if(p == 1) letra = 'P';
    return letra;
}

// Solucionar ejercicio, bucle tiene que aparecer progresivamente
void texto(){
    char bucle[] = {'b','u','c','l','e','\0'};
    char letra;
    for(int i = 5 ; i > 0 ; i--){
        letra = convLetra(i);
        printf("%s %d %c\n",bucle,i,letra);
    }
}

//Ej 8
void collatz(){
    int valor,pasos = 0;
    printf("Ingrese el valor inicial: ");
    scanf("%d",&valor);
    printf("El valor inicial es %d\n",valor);
    for(; valor != 1 ; pasos++){
        if(valor % 2 == 0) valor = valor/2;
        else valor = ((valor*3) + 1);
        printf("El siguiente valor es %d\n",valor); 
    }
    if(pasos == 0) printf("\nERROR");
    else printf("\nValor final %d, numero de pasos %d",valor,pasos);

}

// ARRAYS
//Ej 9





int main(){
    //caraOpuesta();
    //habitaciones();
    //bucle1();
    //bucle2();
    //bucle3();
    //bucle4();
    //ternasPit();
    //adivinarNumero();
    //texto(); -----------------
    //collatz();


    return 0;
}