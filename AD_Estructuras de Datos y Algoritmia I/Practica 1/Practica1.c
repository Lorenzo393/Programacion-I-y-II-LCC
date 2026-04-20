#include "matriz/matriz.h"

int string_len(char *str);

// EJ 1
void bubble_sort(float arreglo[], int longitud) {
    for (int iter = 0 ; iter < longitud - 1 ; iter++) {
        for (int i = 0 ; i < longitud - iter - 1; i++) {
            if (arreglo[i] > arreglo[i + 1]) {
            float aux = arreglo[i];
            arreglo[i] = arreglo[i + 1];
            arreglo[i + 1] = aux;
            }
        }
    }
}
void mostrar_arreglo(float arreglo[], int longitud){
    for(int i = 0 ; i < longitud ; i++){
        printf("%f - ",arreglo[i]);
    }
}
void copia_arreglo(float arreglo1[], float arreglo2[], int longitud){
    for(int i = 0 ; i < longitud ; i++){
        arreglo1[i] = arreglo2[i];
    }
}
float mediana(float arreglo[], int longitud){
    float arregloAux[longitud];
    copia_arreglo(arregloAux, arreglo, longitud);
    bubble_sort(arregloAux,longitud);

    float valorMedio = -1;
    if((longitud % 2) == 0){
        valorMedio = (arregloAux[longitud/2] + arregloAux[(longitud/2)+1]) / 2;
    }
    else{
        valorMedio = arregloAux[longitud/2];
    }
    return valorMedio;
}

// EJ 2
char *copy_str(char copy[]){
    int copyLen = string_len(copy);
    char *str = malloc(sizeof(char) * (copyLen + 1));

    for(int i = 0 ; i < string_len(copy) ; i++){
        str[i] = copy[i];
    }
    str[copyLen] = '\0';

    return str;
}

// EJ 2a
int string_len(char *str){
    int largo = 0;
    while(str[largo] != '\0') largo++;
    return largo;
}
//EJ 2b
void string_reverse(char* str){
    for(int i = string_len(str) - 1, j = 0 ; i+1 != j ; j++, i--){
        char aux = str[i];
        str[i] = str[j];
        str[j] = aux;
    }
}
// EJ 2c
int string_concat(char* str1, char* str2, int max){
    int str1Len = string_len(str1), str2Len = string_len(str2);
    if(max > str2Len) max = str2Len;

    //str1 = realloc(str1, sizeof(char) * (str1Len + max + 1));
    //if(!str1) printf("\nError al guardar memoria"); //EXPLOTA SI TRATO DE REALLOCAR MEMORIA

    for(int i = str1Len, j = 0 ; i < (str1Len + max) ; i++, j++){
        str1[i] = str2[j];
    }
    str1[str1Len + max] = '\0';

    return max;
}
// EJ 2d
int string_compare(char* str1, char* str2){
    int flag = 1, result = 0;
    if(string_len(str1) > string_len(str2)) result = 1;
    if(string_len(str1) < string_len(str2)) result = -1;
    else{
        for(int i = 0 ; str1[i] != '\0' && str2[i] != '\0' && flag ; i++){
            if(str1[i] > str2[i]){
                flag = 0;
                result = 1;
            }
            if(str1[i] < str2[i]){
                flag = 0;
                result = -1;
            }
        }
    }
    return result;
}
// EJ 2e
int string_subcadena(char* str1, char* str2){
    int subcadena = -1;
    for(int i = 0 , j = 0, indice = 1 , flag = 1 ; str1[i] != '\0' && str2[j] != '\0' && flag ; i++){
        if(str1[i] == str2[j]){
            if(indice){
                subcadena = i;
                indice = 0;
            }
            if(str2[j+1] == '\0') flag = 0;
            j++;
        }
        else{
            indice = 1;
            subcadena = -1;
            j = 0;
        }
    }
    return subcadena;
}
// EJ 2f
#define MAX_SIZE 100
int string_arregloStringsLen(char *arregloStrings[], int n){
    int largoTotal = 0;
    for(int i = 0 ; i < n ; i++){
        largoTotal += string_len(arregloStrings[i]);
    }
    return largoTotal;
}
void string_concatenar(char str1[], char str2[]){
    int str1Len = string_len(str1), str2Len = string_len(str2);
    for(int i = str1Len, j = 0 ; j < str2Len ; i++, j++){
        str1[i] = str2[j];
    }
    str1[str1Len+str2Len] = '\0';
}
void string_unir(char *arregloStrings[], int n, char *sep, char *res){
    int largoTotal = string_arregloStringsLen(arregloStrings, n) + (string_len(sep) * (n-1)) + 1;
    res = realloc(res, sizeof(char) * largoTotal);
    res[0] = '\0';
    for(int i = 0 ; i < n ; i++){
        string_concatenar(res, arregloStrings[i]);
        if(i < (n-1)) string_concatenar(res, sep);
    }
    res[largoTotal] = '\0';
}

// EJ 3
typedef struct _ArregloEnteros{
    int* direccion;
    int capacidad;
}ArregloEnteros;
// EJ 3a
ArregloEnteros* arreglo_enteros_crear(int capacidad){
    ArregloEnteros *arreglo = malloc(sizeof(ArregloEnteros));
    arreglo->capacidad = capacidad;
    arreglo->direccion = malloc(sizeof(int) * capacidad);
    return arreglo;
}
// EJ 3b
void arreglo_enteros_destruir(ArregloEnteros* arreglo){
    free(arreglo->direccion);
    free(arreglo);
}
// EJ 3c
int arreglo_enteros_leer(ArregloEnteros* arreglo, int pos){
    return arreglo->direccion[pos];
}
// EJ 3d
void arreglo_enteros_escribir(ArregloEnteros* arreglo, int pos, int dato){
    if(pos >= arreglo->capacidad) pos = arreglo->capacidad - 1;
    if(pos < 0) pos = 0;
    arreglo->direccion[pos] = dato;
}
// EJ 3e
int arreglo_enteros_capacidad(ArregloEnteros* arreglo){
    return arreglo->capacidad;
}
// EJ 3f
void arreglo_enteros_imprimir(ArregloEnteros* arreglo){
    for(int i = 0 ; i < arreglo->capacidad ; i++){
        printf("%i ",arreglo->direccion[i]);
    }
    printf("\n");
}
// EJ 4
// EJ 4a
void arreglo_enteros_ajustar(ArregloEnteros* arreglo, int capacidad){
    arreglo = realloc(arreglo, sizeof(char) * capacidad);
}
// EJ 4b
void arreglo_enteros_insertar(ArregloEnteros* arreglo, int pos, int dato){
    arreglo->capacidad++;
    arreglo_enteros_ajustar(arreglo, arreglo->capacidad);

    if(pos > arreglo->capacidad) pos = arreglo->capacidad - 1;
    if(pos < 0) pos = 0;

    for(int i = arreglo->capacidad -1 ; i > pos ; i--){
        arreglo->direccion[i] = arreglo->direccion[i-1];
    }
    arreglo->direccion[pos] = dato;
}
// EJ 4c
void arreglo_enteros_eliminar(ArregloEnteros* arreglo, int pos){
    if(pos > arreglo->capacidad) pos = arreglo->capacidad - 1;
    if(pos < 0) pos = 0;

    for(int i = pos ; i < arreglo->capacidad ; i++){
        arreglo->direccion[i] = arreglo->direccion[i+1];
    }

    arreglo->capacidad--;
    arreglo_enteros_ajustar(arreglo, arreglo->capacidad);
}



int main(){
    // float arreglo[10] = {9,4,5,7,8,0,1,3,2,6};
    // float medianas = mediana(arreglo, 9);
    // mostrar_arreglo(arreglo,9);
    // printf("\nmedio: %f",medianas);

    //char str1[] = "Cuando patrullas por el mojave casi te dan ganas de que llegue un invierno nuclear";
    //printf("%i",string_len(str1));
    //string_reverse(str1);
    //printf("%s",str1);
    // char *str1 = copy_str("Cuando patrullas por el mojave");
    // char *str2 = copy_str("mojave");
    // printf("%s\n%s\n",str1,str2);
    // int cantConcat = string_concat(str1, str2, 7);
    // printf("%i - %s", cantConcat, str1);
    // printf("%i",string_compare(str1,str2));
    // printf("%i", string_subcadena(str1,str2));
    // char *arregloStrings[] = {"Cuando","patrullas","por","el","mojave"};
    // char sep[] = " ";
    // char *res = malloc(sizeof(char));
    // string_unir(arregloStrings, 5, sep, res);
    // printf("%s",res);

    // ArregloEnteros *arreglo = arreglo_enteros_crear(5);
    // arreglo_enteros_escribir(arreglo,-1,1);
    // arreglo_enteros_escribir(arreglo,1,2);
    // arreglo_enteros_escribir(arreglo,2,3);
    // arreglo_enteros_escribir(arreglo,3,4);
    // arreglo_enteros_escribir(arreglo,6,5);
    // arreglo_enteros_insertar(arreglo,3,6);
    // arreglo_enteros_imprimir(arreglo);
    // arreglo_enteros_eliminar(arreglo,1);
    // arreglo_enteros_eliminar(arreglo,99);
    // arreglo_enteros_imprimir(arreglo);
    // arreglo_enteros_destruir(arreglo);

    Matriz *matriz = matriz_crear(3,3);
    matriz_escribir(matriz,0,0,1);
    matriz_escribir(matriz,0,1,2);
    matriz_escribir(matriz,0,2,3);
    matriz_escribir(matriz,1,0,4);
    matriz_escribir(matriz,1,1,5);
    matriz_escribir(matriz,1,2,6);
    matriz_escribir(matriz,2,0,7);
    matriz_escribir(matriz,2,1,8);
    matriz_escribir(matriz,2,2,9);
    mostrar_matriz(matriz);
    matriz_intercambiar_filas(matriz,1,0);
    mostrar_matriz(matriz);
    matriz_insertar_fila(matriz,3);
    mostrar_matriz(matriz);
    printf("%i %i\n",matriz_num_filas(matriz),matriz_num_columnas(matriz));
    
    



    return 0;
}