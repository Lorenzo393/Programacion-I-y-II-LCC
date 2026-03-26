#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define AUMENTADOR 10
#define CANT_CARTAS 48

// EJ 2
void set_first(int *arr){
    arr[0] = 0;
}
// EJ 3
void set_in(int *n){
    if(*n != 0) *n = 1;
}
// EJ 4
void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}
// EJ 6
char *get_new_line(){
    int size = 5;
    char *line = malloc(sizeof(char) * size);

    for(int i = 0, flag = 1 ; flag ; i++){
        line[i] = getchar();
        if(i+1 >= size){
            size = size + AUMENTADOR;
            line = realloc(line, sizeof(char) * size);
        }
        if(line[i] == '\n'){
            line = realloc(line, sizeof(char) * (i+1));
            line[i] = '\0';
            flag = 0;
        }
    }
    return line;
}
// EJ 8
int mas_tres(int x){
    return x + 3;
}
void mostrar_entero(int x){
    printf("%i",x);
}
int sucesor (int n) {
    return n+1;
}
void imprimir (int n) {
    printf("%d \n", n);
}
// EJ 8 a
int apply(int (*f)(int), int x){
    return f(x);
}
// EJ 8 b
void apply_in(int (*f)(int), int *x){
    *x = f(*x);
}
// EJ 8 c
typedef void (*VisitorFunc)(int);
void recorre(VisitorFunc f, int arr[], int len){
    for(int i = 0 ; i < len ; i++){
        f(arr[i]);
    }
}
// EJ 12
struct _Cords2D{
    float x;
    float y;
};

struct _Cords2D punto_medio(struct _Cords2D cord1, struct _Cords2D cord2){
    struct _Cords2D cordMedia;
    cordMedia.x = (cord1.x + cord2.x) / 2;
    cordMedia.y = (cord1.y + cord2.y) / 2;
    return cordMedia;
}
void mostrar_cord(struct _Cords2D cord){
    printf("(%f,%f)\n",cord.x, cord.y);
}
// EJ 13
enum Palo{
    basto,
    espada,
    oro,
    copa
};
struct _Carta{
    enum Palo palo;
    int numero;
};
typedef struct _Carta Mazo[CANT_CARTAS];

void llenar_Mazo(Mazo *mazo){
    for(int i = 0 ; i < CANT_CARTAS ; i++){
        struct _Carta carta;
        if(i < 12){
            carta.palo = espada;
            carta.numero = i + 1;
        }
        else if(i < 24){
            carta.palo = basto;
            carta.numero = (i + 1) - 12;
        }
        else if(i < 36){
            carta.palo = copa;
            carta.numero = (i + 1) - 24;
        }
        else{
            carta.palo = oro;
            carta.numero = (i + 1) - 36;
        }

        mazo[0][i] = carta;
        
    }
}
void mostrar_carta(struct _Carta carta){
    switch (carta.palo){
        case basto:
            printf("Basto - ");
            break;
        case espada:
            printf("Espada - ");
            break;
        case oro:
            printf("Oro - ");
            break;
        case copa:
            printf("Copa - ");
            break;
        default:
            break;
    }
    printf("%i",carta.numero);
    printf("\n");
}
void mostrar_mazo(Mazo mazo){
    printf("\n");
    for(int i = 0 ; i < 48 ; i++){
        mostrar_carta(mazo[i]);
    }
}
struct _Carta azar(Mazo mazo){
    return mazo[rand() % CANT_CARTAS];
}
// EJ 14
typedef struct _Contacto{
    char *nombre;
    char *numero;
    int edad;
}Contacto;

typedef struct _Agenda{
    Contacto *contacto;
    int cant;
}Agenda;

Contacto crear_contacto(){
   Contacto contacto;
   printf("Ingrese nombre: ");
   contacto.nombre = get_new_line();
   printf("Ingrese telefono: ");
   contacto.numero = get_new_line();
   printf("Ingrese edad: ");
   scanf("%i",&contacto.edad);
   getchar();

   return contacto;
}
void actualizar_edad_void(Contacto *contacto){
    printf("Modifique la edad: ");
    scanf("%i",&contacto->edad);
    getchar();
}
Contacto actualizar_edad_cont(Contacto contacto){
    Contacto contactoAux;
    contactoAux.nombre = contacto.nombre;
    contactoAux.numero = contacto.numero;

    printf("Modifique la edad: ");
    scanf("%i",&contactoAux.edad);
    getchar();

    return contactoAux;
}
void alta_contacto(Agenda *agenda){
    for(int agregar = 1, flag = 1 ; flag ; ){
        printf("Agregar un contacto: (1-Si)(0.No)\n");
        scanf("%i",&agregar);
        getchar();
        if(agregar){
            agenda->contacto = realloc(agenda->contacto, sizeof(Contacto) * (agenda->cant + 1));
            agenda->contacto[agenda->cant] = crear_contacto();
            agenda->cant = (agenda->cant + 1);
        }
        else flag = 0;
    }
}
void modificar_edad(Agenda *agenda){
    printf("Ingrese el nombre: ");
    char *nombre = get_new_line();
    int flag = 1;

    for(int i = 0 ; flag && i < agenda->cant ; i++){
        if(strcmp(nombre, agenda->contacto[i].nombre) == 0){
            int nuevaEdad;
            printf("Ingrese la nueva edad: ");
            scanf("%i",&nuevaEdad);
            agenda->contacto[i].edad = nuevaEdad;
            flag = 0;
        }
    }
    if(flag) printf("Nombre no encontrado\n");
}
void mostrar_contacto(Contacto contacto){
    printf("%s - %s - %i\n", contacto.nombre, contacto.numero, contacto.edad);
}
void mostrar_agenda(Agenda agenda){
    printf("Cantidad de contactos: %i\n",agenda.cant);
    for(int i = 0 ; i < agenda.cant ; i++){
        mostrar_contacto(agenda.contacto[i]);
    }
}
double prom(Agenda *agenda){
    double promedio = 0;
    for(int i = 0 ; i < agenda->cant ; i++){
        promedio += agenda->contacto[i].edad;
    }
    return (double)(promedio / agenda->cant);
}

int main(){
    srand(time(NULL));
    // EJ 1
    // char c[] = {'h','o','l','a','\0'};
    // printf("%p - %p - %p - %p - %p",c[0],c[1],c[2],c[3],c[4]);

    // EJ 2
    //int arr[] = {1,2,3,4,5};
    //set_first(arr);
    //printf("%i - %i - %i - %i - %i",arr[0],arr[1],arr[2],arr[3],arr[4]);

    // EJ 3
    //int *n = malloc(sizeof(int));
    //*n = 7;
    //set_in(n);
    //printf("%i",*n);

    // EJ 4
    //int *a = malloc(sizeof(int));
    //int *b = malloc(sizeof(int));
    //*a = 7;
    //*b = 5;
    //swap(a,b);
    //printf("%i - %i",*a,*b);

    // EJ 5
    // El malloc en caso de no poder reservar memoria retorna NULL

    // EJ 6
    //char *line = get_new_line();
    //printf("%s",line);

    // EJ 7
    // char *x = malloc(100);
    // free(x);
    // free(x);
    // No me tira error

    // EJ 8 a
    // int x = 5;
    // x = apply(mas_tres, x);
    // printf("%i",x);

    // EJ 8 b
    //int *x = malloc(sizeof(int));
    //*x = 5;
    //apply_in(mas_tres, x);
    //printf("%i",*x);

    // EJ 8 c
    //int arr[] = {1,2,3,4,5};
    //int len = 5;
    //recorre(mostrar_entero, arr, len);

    // EJ 8 d
    // int x = 5;
    // x = apply(sucesor, x);
    // printf("%i",x);

    // int *y = malloc(sizeof(int));
    // *y = 5;
    // apply_in(sucesor, y);
    // printf("%i",*y);

    // int arr[] = {1,2,3,4,5};
    // int len = 5;
    // recorre(imprimir, arr, len);

    // EJ 9 a
    // 4 5

    // EJ 9 b
    // 5 4

    // EJ 9 c
    // 9 2 3 4 5

    // EJ 9 d
    // 1 9 7 11 5

    // EJ 9 e
    // 5 15 15

    // EJ 9 f
    // Warning: retorna la direccion de una variable local

    // EJ 9 g
    // Copia el texto b en el texto a

    // EJ 10
    // No esta copiando la cadena. Reserva la misma cantidad de memoria y luego hace que otro puntero
    // apunte al primer elemento de la misma cadena. No la esta copiando en un espacio de memoria separado
    // solo esta haciendo que otro puntero apunte a la misma direccion de memoria

    // EJ 11 a
    // 123 123

    // EJ 11 b
    // No llega al printf, falla antes

    // EJ 12
    // struct _Cords2D cord1;
    // cord1.x = 5;
    // cord1.y = 6;

    // struct _Cords2D cord2;
    // cord2.x = 10;
    // cord2.y = 12;

    // struct _Cords2D cordMedia = punto_medio(cord1, cord2);
    // mostrar_cord(cord1);
    // mostrar_cord(cord2);
    // mostrar_cord(cordMedia);

    // EJ 13
    // Mazo mazo;
    // llenar_Mazo(&mazo);
    // mostrar_mazo(mazo);
    // struct _Carta carta = azar(mazo);
    // mostrar_carta(carta);

    // EJ 14
    // Contacto contacto = crear_contacto();
    // mostrar_contacto(contacto);

    // actualizar_edad_void(&contacto);
    // mostrar_contacto(contacto);
    // No es necesario que el argumento sea un puntero ya que podria crear un nuevo contacto igual al
    // anterior y modificarlo para luego retornarlo y pisar el anterior
    // Agenda *agenda = malloc(sizeof(Agenda));
    // agenda->contacto = NULL;
    // agenda->cant = 0;

    // alta_contacto(agenda);
    // mostrar_agenda(*agenda);

    // modificar_edad(agenda);
    // mostrar_agenda(*agenda);

    // double promedio = prom(agenda);
    // printf("Promedio edad: %lf", promedio);

    // EJ 15
    // data1.c - Si - 30
    // dataPtr->c - Si - 30
    // dataPtr.c - No - x
    // data1.next->b - Si - 20
    // dataPtr→next→b - Si - 20
    // dataPtr.next.b - No - x
    // dataPtr→next.b - No - x
    // (*(dataPtr→next)).b - Si - 20
    // data1.next→next→a - Si - 10
    // dataPtr→next→next.a - No - x
    // dataPtr→next→next→a - Si - 10
    // dataPtr→next→a - No - x
    // dataPtr→next→next→b - No - x

return 0;
}