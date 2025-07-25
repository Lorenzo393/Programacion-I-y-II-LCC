#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE_BUFFER 20
#define STR(s) STR2(s)
#define STR2(s) #s


void mostrar_array_int(int arr[], int len){
    for(int i = 0 ; i < len ; i++){
        printf("%i\n",arr[i]);
    }
}

void mostrar_array_char(char arr[], int len){
    for(int i = 0 ; i < len ; i++){
        printf("%c\n",arr[i]);
    }
}

void set_five_int(int arr[]){
    arr[0] = 9;
    arr[1] = 567;
    arr[2] = 23;
    arr[3] = 145;
    arr[4] = 51;
}

// EJ 1
void imprimir_direccion_memoria_1(){
    char arrc[5];
    int arri[5];

    printf("Array char:\n");
    mostrar_array_char(arrc,5);

    printf("Array int:\n");
    mostrar_array_int(arri,5);
    
}

// EJ 2
void set_first_2(int arr[]){
    arr[0] = 0;
}

// EJ 3
void set_in(int *n){
    if (*n != 0){
        *n = 1;
    }
}

// EJ 4
void swap(int *a, int *b){
    int *aux = malloc(sizeof(int));
    aux = a;
    a = b;
    b = aux;
}

// EJ 6
char *get_new_line_1(){
    char buffer[SIZE_BUFFER + 1];
    scanf("%"STR(SIZE_BUFFER)"[^\n]",buffer);
    char *line = malloc(sizeof(char) * strlen(buffer) + 1);
    strcpy(line,buffer);
    line[strlen(line)] = '\0';
    return line;
}

char *get_new_line_2(){ //Guarda el salto de linea en la cadena
    char buffer[SIZE_BUFFER + 1];
    int i = 0;

    do {
        buffer[i] = getchar();
        i++;
    }
    while(buffer[i-1] != '\n' && i < SIZE_BUFFER);
    buffer[i] = '\0';
    char *line = malloc(sizeof(char) * strlen(buffer) + 1);
    strcpy(line,buffer);
    line[strlen(line)] = '\0';
    return line;
}

char *get_new_line_3(){
    char buffer[SIZE_BUFFER + 1];

    fgets(buffer , SIZE_BUFFER + 1 , stdin);

    char *ptr = strchr(buffer,'\n');
    if(ptr != NULL) *ptr = '\0';

    char *line = malloc(sizeof(char) * strlen(buffer) + 1);
    strcpy(line,buffer);
    line[strlen(line)] = '\0';
    return line;
}

/*
char *get_new_line_4(){ //%m no es parte del estandar de c, y no me anda encima
    char *line;
    printf("Ingrese texto: ");
    scanf("%m[^\n]",&line);
    return line;
}
*/

// EJ 8
int suma_5(int n){
    return n + 5;
}

int apply(int (*func)(int),int n){
    return suma_5(n);
}

void apply_n(int (*func)(int),int *n){
    *n = func(*n);
}

typedef void (*VisitorFunc)(int);

void imprimir(int n){
    printf("%i\n",n);
}

void recorre(VisitorFunc f, int array[],int len){
    for(int i = 0 ; i < len ; i++){
        f(array[i]);
    }
}

// EJ 12
typedef struct _Punto{
    float x;
    float y;
} Punto;

Punto punto_medio(Punto punto1,Punto punto2){
    Punto puntoMedio;
    puntoMedio.x = (punto1.x + punto2.x) / 2;
    puntoMedio.y = (punto1.y + punto2.y) / 2;
    return puntoMedio;
}

// EJ 13
#define SIZE_BARAJA 48
#define CANT_PALOS 4

typedef enum _Palo{
    Copa,
    Oro,
    Basto,
    Espada
} Palo;

typedef struct _Carta{
    int numero;
    Palo palo;
} Carta;

typedef struct _Baraja{
    Carta carta[SIZE_BARAJA];
} Baraja;

Palo devolver_palo(int nPalo){
    Palo palo;
    switch(nPalo){
        case 0:
            palo = Copa;
            break;
        case 1:
            palo = Oro;
            break;
        case 2:
            palo = Basto;
            break;
        case 3:
            palo = Espada;
            break;
    }
    return palo;
}

void llenar(Baraja *baraja){
    int nCarta = 1, nPalo = 0;
    for(int i = 0 ; i < SIZE_BARAJA ; i++){
        baraja->carta[i].palo = devolver_palo(nPalo);
        baraja->carta[i].numero = nCarta;
        if(((i + 1) % (SIZE_BARAJA / CANT_PALOS))== 0){
            nPalo++;
            nCarta = 1;
        }
        else{
            nCarta++;
        }
    }
}

void char_palo(char textPalo[], Palo palo){
    switch(palo){
        case Copa:
            strcpy(textPalo,"Copa");
            textPalo[strlen("Copa")] = '\0';
            break;
        case Oro:
            strcpy(textPalo,"Oro");
            textPalo[strlen("Oro")] = '\0';
            break;
        case Basto:
            strcpy(textPalo,"Baston");
            textPalo[strlen("Baston")] = '\0';
            break;
        case Espada:
            strcpy(textPalo,"Espada");
            textPalo[strlen("Espada")] = '\0';
            break;
    }
}

Carta azar(Baraja baraja){
    return baraja.carta[rand() % SIZE_BARAJA];
}

void mostrar_baraja(Baraja baraja){
    for(int i = 0 ; i < SIZE_BARAJA ; i++){
        char textPalo[SIZE_BUFFER + 1];
        char_palo(textPalo, baraja.carta[i].palo);
        printf("|%i %s|\n",baraja.carta[i].numero,textPalo);
    }
}

// EJ 14
typedef struct _Contacto{
    char *nombre, *telefono;
    unsigned int edad;
} Contacto;

typedef struct _Agenda{
    Contacto *contactos;
    int cantContactos;
} Agenda;

Contacto crear_contacto(){
    Contacto contacto;
    printf("Ingrese el nombre: ");
    contacto.nombre = get_new_line_3();
    
    printf("Ingrese el numero de telefono: ");
    contacto.telefono = get_new_line_3();
    
    printf("Ingrese la edad: ");
    scanf("%u",&contacto.edad);
    getchar();

    return contacto;
}

Agenda crear_agenda(){
    Agenda agenda;
    agenda.cantContactos = 0;
    agenda.contactos = NULL;
    return agenda;
}

void mostrar_contacto(Contacto contacto){
    printf("|%s - %s - %i|\n",contacto.nombre,contacto.telefono,contacto.edad);
}

void mostrar_agenda(Agenda agenda){
    for(int i = 0 ; i < agenda.cantContactos ; i++){
        mostrar_contacto(agenda.contactos[i]);
    }
}

void actualizar_edad(Contacto *contacto){
    printf("Ingrese la nueva edad: ");
    scanf("%u",&contacto->edad);
}

void alta_contacto(Agenda *agenda){
    agenda->cantContactos++;
    agenda->contactos = realloc(agenda->contactos,(sizeof(Contacto) * (agenda->cantContactos)));
    agenda->contactos[(agenda->cantContactos) - 1] = crear_contacto();
}

void modificar_agenda(Agenda *agenda){
    int i = 0, flag = 1;

    printf("Ingrese el nombre a buscar: ");
    char *nombre = get_new_line_3();

    while(flag && i < agenda->cantContactos){
        if(strcmp(agenda->contactos[i].nombre, nombre) == 0) flag = 0;
        else i++;
    }
    
    if(!flag) actualizar_edad(&(agenda->contactos[i]));
    else printf("\nEl nombre ingresado no esta en los contactos\n");
}

double prom(Agenda agenda){
    double promedio = 0;
    for(int i = 0 ; i < agenda.cantContactos ; i++){
        promedio += agenda.contactos[i].edad;
    }
    return promedio / agenda.cantContactos;
}

int main(){
    srand(time(NULL));
    // EJ 1
    //imprimir_direccion_memoria_1();

    // EJ 2
    //int arr[5] = {1,2,3,4,5};
    //set_first_2(arr);
    //mostrar_array_int(arr,5);

    // EJ 3
    //int *n = malloc(sizeof(int));
    //*n = 9;
    //set_in(n);
    //printf("%i",*n);
    //free(n);

    // EJ 4
    //int *a = malloc(sizeof(int));
    //int *b = malloc(sizeof(int));
    //*a = 9;
    //*b = 5;
    //swap(a,b);
    //printf("%i %i",*a,*b);
    //free(a);
    //free(b);

    // EJ 6
    //char *line = get_new_line_3();
    //printf("%s",line);
    //free(line);

    // EJ 8
    //int x = 5;
    //x = apply(suma_5,x);
    //printf("%i",x);
    // -
    //int *y = malloc(sizeof(int));
    //*y = 5;
    //apply_n(suma_5,y);
    //printf("%i",*y);
    //free(y);
    // -
    //int array[] = {1,2,3,4,5};
    //int len = 5;
    //recorre(imprimir,array,len);

    // EJ 12
    //Punto punto1,punto2,puntoMedio;
    //punto1.x = 1;
    //punto1.y = 3;
    //punto2.x = 4;
    //punto2.y = 6;
    //puntoMedio = punto_medio(punto1,punto2);
    //printf("%f %f",puntoMedio.x,puntoMedio.y);

    // EJ 13
    //Baraja *baraja = malloc(sizeof(Baraja));
    //llenar(baraja);
    //mostrar_baraja(*baraja);
    // -
    //Carta carta = azar(*baraja);
    //char textPalo[SIZE_BUFFER];
    //char_palo(textPalo,carta.palo);
    //printf("\n%i %s",carta.numero,textPalo);
    //free(baraja);

    // EJ 14
    //Agenda agenda = crear_agenda();
    //alta_contacto(&agenda);
    //alta_contacto(&agenda);
    //alta_contacto(&agenda);
    // -
    //modificar_agenda(&agenda);
    //mostrar_agenda(agenda);
    //printf("%lf",prom(agenda));
    
    return 0;
}