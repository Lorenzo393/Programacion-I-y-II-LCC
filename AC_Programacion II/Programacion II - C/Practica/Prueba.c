#include <stdlib.h>
#include <stdio.h>
#include <string.h>




/*
 tipoDeDato* nombre; - puntero
 un puntero guarda la direccion de memoria de alguna variable
 int i = 5
 int* p = &i
 p = x120502305820958
 &p = x98878070707087
 *p = 5










// ARCHIVOS
 FILE *nombre = fopen("archivo.txt","modo") - abre el archivo
 r - w - a - r+ - w+ - a+

 int fputc('c',FILE) - Escribe el caracter c en el archivo
 int fputs("string",FILE) - Escribe el string en el archivo
 int fprintf(FILE,"modo",nombre) - Es el printf pero tiene un argumento mas que es 
el archivo en el que se va a escribir

 int fgetc(FILE) - lee de a un caracter
 char *fgets("buffer",n,FILE) - lee hasta n-1 y copia el string leido agregando el '\0'
al final 
 int fscanf(FILE,"formato",&donde los guarda) - lee hasta encontrar un separador 

 int fclose(FILE); - cierra el archivo
*/








//-------------------------------------------------------------------------------------
// PRACTICA 1
//EJ 4
void temperatura(){
    float temp;
    printf("Ingrese la temperatura: ");
    scanf("%f",&temp);
    if (temp >= 100) printf("\nEstado gaseoso");
    else if (temp <= 0) printf("\nEstado solido");
    else printf("Estado liquido");
}
//EJ 5
void nota(){
    int n;
    printf("Ingrese la nota del alumno: ");
    scanf("%i",&n);
    if(n == 10) printf("\nSobresaliente");
    else if(n == 9) printf("\nDistinguido");
    else if(n == 8) printf("\nMuy bueno");
    else if(n == 7) printf("\nBueno");
    else if(n == 6) printf("\nAprobado");
    else if(n <= 5 && n >= 1) printf("Insuficiente");
    else printf("Nota invalida");
}
// EJ 9
void mostar100(){
    int i = 1;
    while(i <= 100){
        printf("-%i",i);
        i++;
    }
}
//EJ 10
void mostrarImpares100(){
    int i = 1;
    while(i <= 100){
        if(i % 2 != 0) printf("-%i",i);
        i++;
    }
}
//EJ 11
void desdeNaM(){
    int valor1 = 1, valor2 = 0;
    while(valor1 > valor2){
        printf("Ingrese los valores: ");
        scanf("%i %i",&valor1,&valor2);
    }
    while(valor1 <= valor2){
        printf("-%i",valor1);
        valor1++;
    }
}
//EJ 12
void primo(){
    int n,i=2;
    printf("Ingrese un numero: ");
    scanf("%i",&n);
    while(n % i != 0) i++;
    if(i == n) printf("Primo");
    else printf("No primo");
}
//EJ 13
void factorial(){
    double fact;
    printf("Ingrese un numero: ");
    scanf("%lf",&fact);
    int i = (int)fact - 1;
    while(i != 1){
        fact = fact * i;
        i--;
    }
    printf("Factorial: %lf",fact);
}
//EJ 15
int maximo(int n, int m){
    if(n > m) return n;
    return m;
}
int max3(int x,int y,int z){
    return maximo(maximo(x,y),z);
}
void maximos(){
    int p,q,r,s;
    printf("Ingrese cuatro numeros: ");
    scanf("%i %i %i %i",&p,&q,&r,&s);
    p = maximo(p,q);
    r = maximo(r,s);
    printf("El maximo es: %i",maximo(p,r));
}
//EJ 16
int ladosTriangulo(){
    int x,y,z,mayor;
    printf("Ingrese los tres lados del triangulo: ");
    scanf("%i %i %i",&x,&y,&z);
    mayor = max3(x,y,z);
    if (x + y + z - mayor > mayor) return 1;
    return 0;
}
//EJ 17
int esRectangulo(int x,int y,int z){
    int mayor = max3(x,y,z);
    if((x*x + y*y + z*z - mayor*mayor) == (mayor*mayor)) return 1;
    return 0;
}
//EJ 19
int fibonacci(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}





//------------------------------------------------------------------------------------#
// PRACTICA 2
//EJ 1
void caraOpuesta(){
    int n;
    printf("Ingrese el numero: ");
    scanf("%i",&n);
    switch(n){
        case 6:
            printf("1");
            break;
        case 5:
            printf("2");
            break;
        case 4:
            printf("3");
            break;
        case 3:
            printf("4");
            break;
        case 2:
            printf("5");
            break;
        case 1:
            printf("6");
            break;
        default:  
        printf("Numero incorrecto");
    }
}
//EJ 3
void for1(){
    float suma = 0;
    for (float i = 1 ; i <= 100 ; i++) suma +=1/i;
    printf("%f",suma);
}
void for2(){
    float suma = 0;
    for(float i = 1 ; i <= 30 ; i++) suma += 1/(i*i);
    printf("%f",suma);
}
void for3(){
    float suma = 0;
    for(float i = 1 ; i <= 25 ; i++) suma += 1/(i*i);
    printf("%f",suma);
}
void for4(){
    float suma = 0;
    for(float i = 1 ; i <= 10 ; i++){
        float potencia = i;
        for(float j = i ; j >= 1 ; j--){
            potencia = potencia * i;
        }
        suma += 1/potencia;
    }
    printf("%f",suma);
}
//EJ 4
void ternasPitagoricas(){
    for(int a = 1; a <= 20 ; a++){
        for(int b = 1; b <= 30 ; b++){
            printf("%i(^2) + %i(^2) = %i",a,b,a*a+b*b);
            printf("\n");
        }
    }
}
//EJ 7 HACER - ESTA BUGUEADA ESTA MIERDA
void salidaJusta(){
    char texto[7] = "bucle";
    char letra = 'T';
    for(int i = 0; i < 5 ; i++){
        texto[7] = texto[i+1];
        texto[i+1] = '\0';
        printf("%s %i %c\n",texto,5-i,letra);
        texto[i+1] = texto[7];
        texto[6] = '\0';
    }
}
//EJ 8
void collatz(int n){
    int contador = 0;
    if(n == 1) printf("ERROR");
    else{
        while(n != 1){
            printf("%i\n",n);
            if(n % 2 == 0) n = n / 2;
            else n = (n * 3) + 1;
            contador++;
        }
    }
    printf("Valor final: %i - Pasos: %i",n,contador);
}
//EJ 9
void primeros100(){
    int enteros[101];
    for(int i = 0 ; i <= 100 ; i++){
        enteros[i] = i;
        printf("%i",enteros[i]);
        printf("\n");
    }
}
//EJ 10
void paresEntre100y200(){
    int pares[100];
    for(int i = 200 , j = 0; i >= 100 ; i--){
        if(i % 2 == 0){
            pares[j] = i;
            printf("%i",pares[j]);
            printf("\n");
            j++;
        }
    }
}
//EJ 11
void prim50mult3(){
    int multiplos[50];
    for(int i = 0 ; i <= 49 ; i++){
        multiplos[i] = 3*(i+1);
        printf("%i",multiplos[i]);
        printf("\n");
    }
}
//EJ 12
int busquedaLineal(int n){
    int arreglo[] = {1,2,3,4,5,6,7,8,9,10};
    int i = 0;
    while(arreglo[i] != n && i < 10) i++;
    if(i != 10) return i+1;
    return -1; 
}
//EJ 13
void sumaMas30(int n){
    int array[100],suma = 0;
    if (n >= 5 && n <= 100){
        for(int i = 0 ; i < n ; i++){
            printf("Ingrese el %i valor: ",i+1);
            scanf("%i",&array[i]);
            suma += array[i];
        }
        if(suma >= 30) printf("La suma es mayor que 30");
        else printf("La suma es menor que 30");
    }
    else printf("ERROR");
}
//EJ 14
void hastaNegativo(){
    int array[100] = {0}, n = 0,cant = 0 , maximo = 0;

    while(n >= 0){
        printf("Ingrese un numero: ");
        scanf("%i",&n);
        if(n >= 0) array[n]++;
    }
    for(int i = 0 ; i < 100 ; i++){
        if(cant < array[i]){
            cant = array[i];
            maximo = i;
        }
    }
    printf("El valor mas repetido es %i con %i veces",maximo,cant);
}
//EJ 15
int sumaArray(int array[100],int n){
    int suma = 0;
    for(int i = 0 ; i < n ; i++){
        suma += array[i];
    }
    return suma;
}
//EJ 16
int prodAlt(int array[100],int n){
    int prod = 1;
    for(int i = 0 ; i < n ; i++){
        if(i % 2 == 0) prod = prod * array[i];
    }
    return prod;
}
//EJ 18
int busquedaLinealChar(char texto[100],char letra){
    int bandera = 0;
    for(int i = 0 ; texto[i] != '\0' ; i++){
        if(letra == texto[i]) bandera = 1;
    }
    return bandera;
}
//EJ 19
int aparicionesChar(char texto[100],char letra){
    int contador = 0;
    for(int i = 0 ; texto[i] != '\0'; i++){
        if(texto[i] == letra) contador++;
    }
    return contador;
}
//EJ 20
int largoCadena(char texto[100]){
    int final;
    for(final = 0; texto[final] != '\0';final++);
    return final;
}


void reverse(char texto[100]){
    int final = largoCadena(texto);
    for(int i = final -1 ; i >= 0 ; i--){
        printf("%c",texto[i]);
    }
}
//EJ 21
void esCapicua(char texto[100]){
    int final = largoCadena(texto) - 1,bandera = 1;
    for(int i = 0 ; final >= 0 && i <= final; final-- , i++) if(texto[i] != texto[final]) bandera = 0;
    if(bandera) printf("La palabra es capicua");
    else printf("La palabra no es capicua");
}
//EJ 22
void esPangrama(char texto[100]){
    int letras[26] = {0}, cantLetras = 0;
    for(int i = 0 ; texto[i] != '\0'; i++){
        int idx = texto[i] % 26;
        if(letras[idx] == 0){
            letras[idx] = 1;
            cantLetras++;
        }
    }
    if(cantLetras == 26) printf("Es pangrama");
    else printf("No es pangrama");
}
//EJ 23
/*
int contenida(char contenido[100],char texto[100]){
    int suma = 0 , bandera = 1;
    for(int i = 0 , j = 0; texto[i] != '\0'; i++){
        if(texto[i] == contenido[j]){
            for
        }
    } 
    return bandera;
}


void estaContenida(char cad1[100],char cad2[100]){

}
*/

//------------------------------------------------------------------------------------#
// PRACTICA 3
//EJ 1
typedef struct _Complejo{
    double imaginaria;
    double real;
} Complejo;

typedef int om;





int main(){
    //------------------------------------------------------------------------------------#
    // PRACTICA 1
    //int x;
    //temperatura();
    //nota();
    //mostar100();
    //mostrarImpares100();
    //desdeNaM();
    //primo();
    //factorial();
    //maximos();
    //x = ladosTriangulo();
    //printf("%i",x);
    //x = esRectangulo(x,y,z);
    //printf("%i",x);
    //x = fibonacci(n);
    //printf("%i",x);

    //------------------------------------------------------------------------------------#
    // PRACTICA 2
    //caraOpuesta();
    //for1();
    //for2();
    //for3();
    //for4();
    //ternasPitagoricas();
    //salidaJusta();
    //collatz(n);
    //primeros100();
    //paresEntre100y200();
    //prim50mult3();
    //x = busquedaLineal(11);
    //printf("%i",x);
    //sumaMas30(n);
    //hastaNegativo();
    //int array[] = {1,1,1,1,1,1,1};
    //x = sumaArray(array,n);
    //printf("%i",x);
    //int array[] = {1,2,3,4,5,6,7};
    //x = prodAlt(array,n);
    //printf("%i",x);
    //char array[] = "asodnasoidnaosndoansdkansñdnañdnajond";
    //x = busquedaLinealChar(array,'char');
    //printf("%i",x);
    //char array[] = "hoamsaipnpianbfnanfouabbak dabdabobnabfahfahpfafb";
    //x = aparicionesChar(array,'h');
    //printf("%i",x);
    //char array[] = "El que quiera perder su tiempo que entre a mi perfil";
    //reverse(array);
    //char array[] = "ana";
    //esCapicua(array);
    //char array[] = "oabsdobasobdababdibqgwiygdqbdioqbdibqwidbabcdefghijklmnopqrstuvwxyz";
    //esPangrama(array);

    //------------------------------------------------------------------------------------#
    // PRACTICA 3
    char *ptr = " hola mundo ";
    ptr[0] = 's';
    printf(" %s", *ptr) ;

return 0;
}