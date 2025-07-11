#include "matriz/matriz.h"

//EJ 1
void mostrar_arreglo(float arreglo[], int len){
    for(int i = 0 ; i < len ; i++){
        printf("%.2f - ",arreglo[i]);
    }
}

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

int even(int n){
    return (n % 2 == 0);
}

void copia_arreglo(float arr1[],float arr2[],int len){
    for(int i = 0 ; i < len ; i++){
        arr1[i] = arr2[i];
    }
}

float mediana(float arreglo[], int len){
    float aux[len];
    copia_arreglo(aux,arreglo,len);
    bubble_sort(aux,len);
    if(!even(len)) return aux[(len/2)];
    else return (aux[(len/2) - 1] + aux[(len/2)]) / 2;
}

//EJ 2
#define MAX_SIZE 100

int string_len(char *str){
    int len = 0;
    while(str[len] != '\0') len++;
    return len;
}

void string_reverse(char *str){
    for(int i = 0 , j = string_len(str) - 1; i < j ; i++ , j--){
        char aux = str[i];
        str[i] = str[j];
        str[j] = aux;
    }
}

int string_concat(char *str1, char *str2, int max){
    int lenStr1 = string_len(str1);
    int lenStr2 = string_len(str2);
    int cantCopiados = 0;
    //printf("%i - %i - %i\n",lenStr1,lenStr2,lenStr1Str2);
    if((lenStr1 + lenStr2) < max){
        //str1 = realloc(str1,sizeof(char) * (lenStr1Str2 + 1)); NO SE QUE HACER ACA SI LO REALOCO FALLA
        for(int i = lenStr1, j = 0 ; j < lenStr2 ; i++, j++){
            str1[i] = str2[j];
            cantCopiados++;
        }
        str1[(lenStr1 + lenStr2)] = '\0';
    }
    return cantCopiados;
}

int string_compare(char *str1, char *str2){
    int lenStr1 = string_len(str1);
    int lenStr2 = string_len(str2);
    if(lenStr1 > lenStr2) return 1;
    else if(lenStr1 < lenStr2) return -1;
    else if (lenStr1 == lenStr2){
        int valorStr1 = 0, valorStr2 = 0;
        int flag = 1;
        for(int i = 0 ; i < lenStr1 ; i++){
            if(str1[i] != str2[i]){
                flag = 0;
                valorStr1 += str1[i];
                valorStr2 += str2[i];
            }
        }
        if(flag) return 0;
        else if(valorStr1 > valorStr2) return 1;
        else if(valorStr1 < valorStr2) return -1;
    }
    return -2;
}

int string_subcadena(char *str1, char *str2){
    int ocurrencia = -1;
    int flag = 1;
    int i = 0;
    while(flag && i < string_len(str1)){
        if(str1[i] == str2[0]){
            char *aux = malloc(sizeof(char) * (string_len(str2) + 1));
            strncpy(aux,&(str1[i]),string_len(str2));
            aux[string_len(str2)] = '\0';
            printf("%s - %s - %s\n",str1,str2,aux);
            if(string_compare(aux,str2) == 0){
                ocurrencia = i;
                flag = 0;
            }
            free(aux);
        }
        i++;
    }
    return (ocurrencia + 1);
}

int largo_cadenas(char *arregloStrings[],int n, char sep[]){
    int lenCadenas = 0;
    for(int i = 0 ; i < n ; i++){
        lenCadenas += string_len(arregloStrings[i]);
    }
    lenCadenas += string_len(sep) * (n - 1);
    return lenCadenas;
}

void string_unir(char *arregloStrings[], int n, char *sep, char *res){
    int lenRes = largo_cadenas(arregloStrings,n,sep);
    res = realloc(res,sizeof(char) * (lenRes + 1));
    for(int i = 0 ; i < n ; i++){
        string_concat(res,arregloStrings[i],MAX_SIZE);
        string_concat(res,sep,MAX_SIZE);
    }
    res[lenRes] = '\0';
}

//EJ 3
#define MIN_POS 0

typedef struct {
    int* direccion;
    int capacidad;
} ArregloEnteros;

ArregloEnteros *arreglo_enteros_crear(int capacidad){
    ArregloEnteros *arreglo = malloc(sizeof(ArregloEnteros));
    arreglo->direccion = malloc(sizeof(int) * capacidad);
    arreglo->capacidad = capacidad;
    return arreglo;
}

void arreglo_enteros_destruir(ArregloEnteros *arreglo){
    free(arreglo->direccion);
    free(arreglo);
}

int arreglo_enteros_capacidad(ArregloEnteros *arreglo){
    return arreglo->capacidad;
}

int arreglo_enteros_leer(ArregloEnteros *arreglo, int pos){
    return arreglo->direccion[pos];
}

void arreglo_enteros_escribir(ArregloEnteros *arreglo, int pos, int dato){
    arreglo->direccion[pos] = dato;
}

void arreglo_enteros_imprimir(ArregloEnteros *arreglo){
    for(int i = 0 ; i < arreglo_enteros_capacidad(arreglo) ; i++){
        printf("%i\n",arreglo_enteros_leer(arreglo,i));
    }
}

//EJ 4
void arreglo_enteros_ajustar(ArregloEnteros *arreglo, int capacidad){
    arreglo->direccion = realloc(arreglo->direccion,sizeof(int) * capacidad);
    arreglo->capacidad = capacidad;
}

void arreglo_enteros_insertar(ArregloEnteros *arreglo, int pos, int dato){
    arreglo_enteros_ajustar(arreglo,(arreglo_enteros_capacidad(arreglo) + 1));
    for(int i = (arreglo_enteros_capacidad(arreglo) - 1) ; i > pos ; i--){
        arreglo_enteros_escribir(arreglo,i,arreglo_enteros_leer(arreglo,i-1));
    }
    arreglo_enteros_escribir(arreglo,pos,dato);
}

void arreglo_enteros_eliminar(ArregloEnteros *arreglo, int pos){
    for(int i = pos ; i < (arreglo_enteros_capacidad(arreglo) - 1) ; i++){
        arreglo_enteros_escribir(arreglo,i,arreglo_enteros_leer(arreglo,i+1));
    }
    arreglo_enteros_ajustar(arreglo,(arreglo_enteros_capacidad(arreglo) - 1));
}


int main(){
    // EJ 1
    //float arreglo[] = {7.4,4,2,1,5,7,4.3};
    //int len = 7;
    //float medio = mediana(arreglo,len);
    //printf("%.2f\n",medio);
    //mostrar_arreglo(arreglo,len);
    
    // EJ 2
    //int len = string_len("hola ----");
    //printf("%i",len);
    // -
    //char cadena[] = {"hola -----"};
    //string_reverse(cadena);
    //printf("%s",cadena);
    // -
    //char *str1 = malloc(sizeof(char)*(strlen("hola")+1));
    //char *str2 = malloc(sizeof(char)*(strlen("obama")+1));
    //strcpy(str1,"hola");
    //strcpy(str2,"obama");
    //int cantCopias = string_concat(str1,str2,20);
    //printf("%s - %s - %i",str1,str2,cantCopias);
    // -
    //char *str1 = malloc(sizeof(char)*(strlen("hola")+1));
    //char *str2 = malloc(sizeof(char)*(strlen("obama")+1));
    //strcpy(str1,"holaa");
    //strcpy(str2,"holaa");
    //int comp = string_compare(str1,str2);
    //printf("%i",comp);
    // -
    //char *str1 = malloc(sizeof(char)*(strlen("pobamaobama")+1));
    //char *str2 = malloc(sizeof(char)*(strlen("obama")+1));
    //strcpy(str1,"pobamaobama");
    //strcpy(str2,"obama");
    //int coincidencia = string_subcadena(str1,str2);
    //printf("%i",coincidencia);
    // -
    //char *res = malloc(sizeof(char));
    //char *arregloCadenas[] = {"hola","weon","como","estay","chuchatumare"};
    //int cantCadenas = 5;
    //char sep[] = {" "};
    //string_unir(arregloCadenas,cantCadenas,sep,res);
    //printf("%s - %i - \"%s\" - %s",arregloCadenas[0],cantCadenas,sep,res);
    // QUEDA EL EJERCICIO 2G

    // EJ 3
    //ArregloEnteros *arreglo = arreglo_enteros_crear(5);
    //arreglo_enteros_escribir(arreglo,0,1);
    //arreglo_enteros_escribir(arreglo,1,2);
    //arreglo_enteros_escribir(arreglo,2,3);
    //arreglo_enteros_escribir(arreglo,3,4);
    //arreglo_enteros_escribir(arreglo,4,5);
    //arreglo_enteros_imprimir(arreglo);
    //arreglo_enteros_destruir(arreglo);

    // EJ 4
    //ArregloEnteros *arreglo = arreglo_enteros_crear(5);
    //arreglo_enteros_escribir(arreglo,0,7);
    //arreglo_enteros_escribir(arreglo,1,9);
    //arreglo_enteros_escribir(arreglo,2,3);
    //arreglo_enteros_escribir(arreglo,3,5);
    //arreglo_enteros_escribir(arreglo,4,2);
    //arreglo_enteros_imprimir(arreglo);
    //printf("\n");
    //arreglo_enteros_insertar(arreglo,1,1);
    //arreglo_enteros_imprimir(arreglo);
    //printf("\n");
    //arreglo_enteros_eliminar(arreglo,2);
    //arreglo_enteros_imprimir(arreglo);
    //arreglo_enteros_destruir(arreglo);

    // EJ 5
    //Matriz *matriz = matriz_crear(2,3);
    //matriz_escribir(matriz,0,0,1);
    //matriz_escribir(matriz,0,1,2);
    //matriz_escribir(matriz,0,2,3);
    //matriz_escribir(matriz,1,0,4);
    //matriz_escribir(matriz,1,1,5);
    //matriz_escribir(matriz,1,2,6);
    //matriz_mostrar(matriz);
    //matriz_intercambiar_filas(matriz,0,1);
    //matriz_mostrar(matriz);
    //double fila[] = {9,8,7};
    //matriz_insertar_fila(matriz,1,fila);
    //matriz_mostrar(matriz);
    //matriz_destruir(matriz);
}