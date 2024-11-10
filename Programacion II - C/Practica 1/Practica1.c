#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
// ENTRADA/SALIDA
 
 Ej 1: ¿Cual es la salida del siguiente programa?
int main () {
    int a , b , c , d =6 , e ;
    a = b = 3;
    c = a * b+ d ;
    e = ( c + 5) / 4 -3;
    e +=5;
    printf ("Los resultados son %d y %d ", c , e ) ;
return 0;
}
//LA SALIDA ES: retorna 0 y printea el resultado de c y e: 15 y 7


 Ej 2: ¿Cual es la salida del siguiente programa?
int main () {
    int a , b , c , d =6 , e ;
    a = 3;
    b = a - d / 3;
    a *= b ;
    c = a + d / a - 3 / a * b ;
    e = c + 8 / 4 - b ;
    e +=5;
    printf ("Los resultados son %d y %d ", c , e ) ;
return 0;
}
LA SALIDA ES: retorna 0 y printea los resultados de c y e: 4 y 10


 Ej 3: Determine la salida del siguiente programa:
int main () {
    float x , y ;
    printf (" Introduzca 2 numeros :\n") ;
    scanf (" %f %f", &x , & y ) ;
    printf ("La suma de %f y %f vale %f\n", x , y , x + y ) ;
    printf ("La suma de %4f y %4.2f vale %10.3f\n", x , y , x + y ) ;
    printf ("La suma de %e y %e vale %e\n", x , y , x + y ) ;
return 0;
}
LA SALIDA ES: retorna 0 y printea de distintas maneras los 2 numeros solicitados y su suma
*/

// SELECCION
//Ej 4:
void temperatura(){
    float temperatura;
    printf("Ingrese la temperatura del agua: ");
    scanf("%f",&temperatura);
    if (temperatura <= 0) printf("Estado: solido");
    else if (temperatura >= 100) printf("Estado: gaseoso");
    else printf("Estado: liquido");
}

//Ej 5
void notasAlumnos(){
    int nota;
    printf("Ingrese la nota del alumno: ");
    scanf("%d",&nota);
    if (nota == 10) printf("Sobresaliente");
    else if (nota == 9) printf("Distinguido");
    else if (nota == 8) printf("Muy bueno");
    else if (nota == 7) printf("Bueno");
    else if (nota == 6) printf("Aprobado");
    else if(nota >= 0 && nota <= 5) printf("Insuficiente");
    else printf("Nota Ingresada no valida");
}

//Ej 6
void singoZodiacal(){
    int dia, mes;
    printf("Ingrese el dia y mes de nacimiento: ");
    scanf("%d%d",&dia,&mes);

    if ((dia >= 21 && mes == 1) || (dia <= 19 && mes == 2)) printf("Acuario");
    else if ((dia >= 20 && mes == 2) || (dia <= 20 && mes == 3)) printf("Piscis");
    else if ((dia >= 21 && mes == 3) || (dia <= 21 && mes == 4)) printf("Aries");
    else if ((dia >= 22 && mes == 4) || (dia <= 21 && mes == 5)) printf("Tauro");
    else if ((dia >= 22 && mes == 5) || (dia <= 21 && mes == 6)) printf("Geminis");
    else if ((dia >= 22 && mes == 6) || (dia <= 22 && mes == 7)) printf("Cancer");
    else if ((dia >= 23 && mes == 7) || (dia <= 22 && mes == 8)) printf("Leo");
    else if ((dia >= 23 && mes == 8) || (dia <= 21 && mes == 9)) printf("Virgo");
    else if ((dia >= 22 && mes == 9) || (dia <= 21 && mes == 10)) printf("Libra");
    else if ((dia >= 22 && mes == 10) || (dia <= 20 && mes == 11)) printf("Escorpio");
    else if ((dia >= 21 && mes == 11) || (dia <= 19 && mes == 12)) printf("Sagitario");
    else if ((dia >= 20 && mes == 12) || (dia <= 20 && mes == 1)) printf("Capricornio");
    else printf("Datos ingresador erroneos");
}

//Ej 7
void esBisiesto(){
    int year;
    printf("Ingrese el year: ");
    scanf("%d",&year);

    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) printf("Year bisiesto");
    else printf("No es year bisiesto");
}

/*
Ej 8: Simplifique el siguiente codigo de forma que sean necesarias menos 
comparaciones.

if (Edad > 64) printf ("Seguridad Social") ;
if (Edad < 18) printf ("Exento") ;
if ((Edad >= 18) && (Edad < 65) ) printf ("Imposible") ;

if (Edad > 64) printf ("Seguridad Social");
else if (Edad < 18) printf ("Exento");
else printf("Imposible");
-- 2 comparaciones menos
*/

// BUCLE WHILE
//Ej 9
void numeros100(){
    int i = 1;
    while (i <= 100){
        printf("%d\n",i);
        i++;
    }
}

//Ej 10
void numerosImpares100(){
    int i = 1;
    while (i <= 100){
        if(i % 2 != 0) printf("%d\n", i);
        i++;
    }
}

//Ej 11
void entre(){
    int v1, v2;
    printf("Ingrese los valores: ");
    scanf("%d%d",&v1,&v2);
    while (v1 > v2){
        printf("Error: el primer valor debe ser menor al segundo\n");
        printf("Ingrese nuevamente los valores: ");
        scanf("%d%d",&v1,&v2);
    }
    int i = v1;
    while (i <= v2){
        printf("%d\n",i);
        i++;
    }
}

//Ej 12
void primo(){
    int numero,divisores = 0 ,i = 1;
    printf("Ingrese el numero: ");
    scanf("%d",&numero);
    while(numero > 1 && i <= numero){
        if (numero % i == 0){
            divisores++;
        }
        i++;
    }
    if(divisores == 2){
        printf("El numero es primo");
    }
    else{
        printf("El numero no es primo");
    }
}

//Ej 13
void factorial(){
    double numero;
    printf("Ingrese el numero: ");
    scanf("%lf",&numero);
    int i = numero - 1;
    while(i > 0){
        numero = numero * i;
        i--;
    }
    printf("Su factorial es %0.1lf",numero);
}

//Ej 14
void pacientes(){
    int nPacientes,nIngresados,nOperados;
    int edad,edadIngresados,edadOperados;
    nPacientes = nIngresados = nOperados = 0;
    edad = edadIngresados = edadOperados = 0;
    float indice;

    printf("Ingrese el numero de pacientes: ");
    scanf("%d",&nPacientes);
    int i = nPacientes;

    while(i > 0){
        int aux;
        printf("Ingrese la edad y el indice del paciente: ");
        scanf("%d%f",&aux,&indice);
        edad = edad + aux;
        if(indice > 0.9){
            edadOperados = edadOperados + aux;
            nIngresados++;
        }
        else if (indice > 0.6){
            edadIngresados = edadIngresados + aux;
            nOperados++;
        }
        i--;
    }
    if(nPacientes == 0) nPacientes = 1;
    if(nIngresados == 0) nIngresados = 1;
    if(nOperados == 0) nOperados = 1;

    printf("\nLa cantidad de pacientes: %d",nPacientes);
    printf("\nEl promedio de edad general: %0.1f",(float) edad/nPacientes);
    printf("\nEl promedio de la edad ingresados: %0.1f",(float) edadIngresados/nIngresados);
    printf("\nEl promedio de la edad operados: %0.1f",(float) edadOperados/nOperados);
}

//Ej 15
int maximo(int x,int y){
    if (x >= y){
        return x;
    }
    return y;
}

int maximo4(){
    int v1,v2,v3,v4;
    printf("Ingrese los 4 numeros: ");
    scanf("%d%d%d%d",&v1,&v2,&v3,&v4); 
    v1 = maximo(v1,v2);
    v2 = maximo(v3,v4);
    v3 = maximo(v1,v2);
    return v3;
}

//Ej 16
int esTriangulo(int l1,int l2,int l3){
    if(l1 > l2+l3) return 0;
    if(l2 > l1+l3) return 0;
    if(l3 > l1+l2) return 0;
    return 1;
}

//Ej 17
int max3(int v1,int v2,int v3){
    int max = 0;
    if(v1 > v2){
        if(v1 > v3) max = 1;
    }
    else if(v2 > v3) max = 2;
    else max = 3;
    return max;
}

int esTriRectangulo(int l1,int l2,int l3){
    int max = max3(l1,l2,l3);
    
    if(max == 1){
        if(pow(l1,2) == pow(l2,2) + pow(l3,2)) return 1;
    }
    if(max == 2){
        if(pow(l2,2) == pow(l1,2) + pow(l3,2)) return 1;
    }
    if(max == 3){
        if(pow(l3,2) == pow(l1,2) + pow(l2,2)) return 1;
    }
    return 0;
}

//Ej 18
int pascuas(int year){
    int a = year % 19;
    int b = year % 4;
    int c = year % 7;
    int d =  (19 * a + 24) % 30;
    int e = (2 * b + 4 * c + 6 * d + 5) % 7;
    int n = (22 + d + e);
    if(n > 31) n = n - 31;
    return n;
}

//Ej 19
int fibonacci(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    //temperatura();
    //notasAlumnos();
    //singoZodiacal();
    //esBisiesto();
    //numeros100();
    //numerosImpares100();
    //entre();
    //primo();
    //factorial();
    //pacientes();
    //int x = maximo4();
    //int x = esTriangulo(l1,l2,l3);
    //int x = esTriRectangulo(l1,l2,l3);
    //int x = pascuas(year);
    //int x = fibonacci(n);
    return 0;
}