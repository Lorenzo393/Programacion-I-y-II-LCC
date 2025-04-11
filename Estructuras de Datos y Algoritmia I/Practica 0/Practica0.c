#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

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

//EJ 9
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
    }//IMPRIME [1,9,7,11,5]

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
    }//IMPRIME 5 15 15

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
    }//SEGMENTATION FAULT

    g) # include <stdio.h>
    int main() {
        char textoA [30] = "Agarrate Catalina";
        char textoB [30] = "El Cuarteto de Nos";
        char *p = textoA;
        char *q = textoB;
        printf ("textoA: %s\n textoB: %s\n", textoA , textoB);
        while(*p++ = *q++);
        printf("while (*p++ = *q++) ;\n");
        printf("textoA: %s\n textoB: %s\n", textoA , textoB);

        return 0;
    }// IMPRIME textoA Y textoB Y DESPUES while(*p++ = *q++); textoB y textoB
*/

//EJ 10
/*
#include <stdlib.h>
#include <stdio.h>

char *copiar_cadena(char *cad, int longitud){
    char *a = malloc(sizeof(char)*longitud);
    a = cad;

    return a;
}

int main(){
    char a[10] = "hola";
    char *b = copiar_cadena(a,10);
    printf("%s %s\n",a,b);
    b[0] = 's';
    printf("%s %s\n",a,b);

    return 0;
}//PERDIDA DE MEMORIA EN a=cad TAMBIEN NO SE COPIA LA CADENA REAL SOLO SE APUNTA A ELLA
 //SI HAY MODIFICACIONES EN LA CADENA SE MODIFICARIA EN LOS DOS
*/

//EJ 11
/*
a) #include <stdio.h>
void nullify (int* a ){
    a = NULL;

}
int main () {
    int a[67];
    a[0] = 123;
    printf("%d\n", a [0]);
    nullify(a);
    printf("%d\n", a [0]);
    return 0;
}//IMPRIME 123 123

b) #include <stdio.h>
int main () {
    char *ptr = "hola mundo";
    ptr[0] = 's';
    printf ("%s\n", ptr);
    return 0;
}//NO IMPRIME NADA
*/

//EJ 12
typedef struct{
    float x;
    float y;
}Punto;

void medio(Punto a , Punto b){
    printf("El medio es: %f %f",(a.x+b.x)/2,(a.y+b.y)/2);
}

//EJ 13
#define SIZE_MAZO 48

typedef enum{
    ESPADA,
    BASTO,
    COPA,
    ORO
}Palo;

typedef struct{
    int nCarta;
    Palo palo;
}Carta;

typedef Carta Mazo[SIZE_MAZO];

void mostrar_mazo(Mazo mazo){
    for(int i = 0 ; i < SIZE_MAZO ; i++){
        printf("%i-",mazo[i].nCarta);
        if(mazo[i].palo == ESPADA) printf("ESPADA");
        else if(mazo[i].palo == BASTO) printf("BASTO");
        else if(mazo[i].palo == COPA) printf("COPA");
        else if(mazo[i].palo == ORO) printf("ORO");
        printf("\n");
    }
}

void mostrar_carta(Carta carta){
    printf("\n\n");
    printf("%i-",carta.nCarta);
    if(carta.palo == ESPADA) printf("ESPADA");
    else if(carta.palo == BASTO) printf("BASTO");
    else if(carta.palo == COPA) printf("COPA");
    else if(carta.palo == ORO) printf("ORO");
}

void llenar(Mazo mazo){
    for(int i = 0 , n = 1, p = 0; i < SIZE_MAZO ; i++){
        if(n % 13 == 0){
            n = 1;
            p++;
        }
        mazo[i].nCarta = n;
        if(p == 0) mazo[i].palo = ESPADA;
        if(p == 1) mazo[i].palo = BASTO;
        if(p == 2) mazo[i].palo = COPA;
        if(p == 3) mazo[i].palo = ORO;
        n++;
    }
    mostrar_mazo(mazo);
}

Carta azar(Mazo mazo){
    int random = rand() % 48;
    return mazo[random];
}

//EJ 14
#define CANT_CONTACTOS 10

typedef struct _contacto{
    char *nombre, *telefono;
    unsigned int edad;
}Contacto;

typedef struct _agenda{
    Contacto contacto[CANT_CONTACTOS];
    int cantContactos; //Poner inta cantContactos = 0 da error. Ver porque
}Agenda;

void imprimir_contacto(Contacto *contacto){
    printf("%s-",contacto->nombre);
    printf("%s-",contacto->telefono);
    printf("%i\n",contacto->edad);
}

void imprimir_agenda(Agenda *agenda){
    for(int i = 0 ; i < agenda->cantContactos ; i++){
        Contacto contacto = agenda->contacto[i];
        imprimir_contacto(&contacto);
    }
}

Contacto crear_contacto(){
    Contacto contacto;

    printf("\nIngrese el nombre: ");
    contacto.nombre = get_new_line();
    getchar();

    printf("Ingrese el telefono:");
    contacto.telefono = get_new_line();
    getchar();

    printf("Ingrese la edad: ");
    scanf("%i",&contacto.edad);
    getchar();

    return contacto;
}

void actualiza_edad(Contacto *contacto){//Si, sino no se actualizara el dato
    printf("Actualize la edad: ");
    scanf("%i",&contacto->edad);
}

void alta_contacto(Agenda *agenda){
    Contacto contacto = crear_contacto();
    agenda->contacto[agenda->cantContactos] = contacto;
    agenda->cantContactos++;
}

void modificar_edad(Agenda *agenda){
    if(agenda->cantContactos != 0){
        char nombre[100];
        printf("Ingrese el nombre: ");
        scanf("%s",nombre);
        int bandera = 1;
        int i = 0;

        while(i < agenda->cantContactos && bandera){
            Contacto contacto = agenda->contacto[i];
            if(strcmp(nombre,contacto.nombre) == 0) bandera = 0;
            else i++;
        }
        if(bandera == 0) actualiza_edad(&(agenda->contacto[i]));
        else printf("El nombre ingresado no existe\n");
    }
    else printf("No existen contactos");
}

double prom(Agenda *agenda); //Promedio de edad de las personas de la agenda



int main(){
    srand(time(NULL));
    //imprimir_direcciones_memoria();
    //set_first(arr);
    //set_in(p);
    //swap(a,b);
    //char *linea = get_new_line();
    //reservar_memoria_error();
    //a = apply(sucesor,a);
    //apply_in(sucesor,a);
    //recorre(imprimir,arr,len);
    //medio(a,b);
    
    //llenar(mazo);
    //carta = azar(mazo);
    Agenda agenda;
    agenda.cantContactos = 0;

    alta_contacto(&agenda);
    alta_contacto(&agenda);
    modificar_edad(&agenda);
    imprimir_agenda(&agenda);
    printf("Cant: %i",agenda.cantContactos);
    
    

    return 0;
}
