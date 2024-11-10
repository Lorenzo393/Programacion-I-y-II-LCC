#include <stdlib.h>
#include <stdio.h>

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

int main(){
    //caraOpuesta();
    //habitaciones();


    return 0;
}