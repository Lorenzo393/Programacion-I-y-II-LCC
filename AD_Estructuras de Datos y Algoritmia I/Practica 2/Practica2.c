#include "slist/slist.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void funcion_visitante(int dato){
    printf("%i ", dato);
}
int funcion_comparadora(int dato1, int dato2){
    return (dato1 == dato2);
}
int funcion_comparadora2(int dato1, int dato2){
    if(dato1 > dato2)
        return 1;
    if(dato1 < dato2)
        return -1;
    else
        return 0;
}


int main(){
    // SList lista1 = slist_crear();
    // lista1 = slist_agregar_final(lista1,0);
    // lista1 = slist_agregar_final(lista1,1);
    // lista1 = slist_agregar_final(lista1,2);
    // lista1 = slist_agregar_final(lista1,3);
    // lista1 = slist_agregar_final(lista1,4);
    // SList lista2 = slist_crear();
    // lista2 = slist_agregar_final(lista2,5);
    // lista2 = slist_agregar_final(lista2,6);
    // lista2 = slist_agregar_final(lista2,7);
    // lista2 = slist_agregar_final(lista2,8);
    // lista2 = slist_agregar_final(lista2,9);

    // slist_recorrer(lista1, funcion_visitante);
    // slist_recorrer(lista2, funcion_visitante);
    // printf("%i %i",slist_longitud(lista1),slist_longitud(lista2));
    // slist_concatenar(lista1, lista2);
    // slist_insertar(lista1,0,-1);
    // slist_insertar(lista2,0,-1);
    // lista1 = slist_eliminar(lista1,0);
    // lista2 = slist_eliminar(lista2,0);
    // slist_recorrer(lista1, funcion_visitante);
    // slist_recorrer(lista2, funcion_visitante);
    // printf("%i",slist_contiene(lista2,5));
    // printf("%i",slist_indice(lista2,1));

    // SList lista3 = slist_crear();
    // lista3 = slist_agregar_final(lista3,0);
    // lista3 = slist_agregar_final(lista3,1);
    // lista3 = slist_agregar_final(lista3,3);
    // lista3 = slist_agregar_final(lista3,5);
    // lista3 = slist_agregar_final(lista3,6);
    // SList lista4 = slist_crear();
    // lista4 = slist_agregar_final(lista4,9);
    // lista4 = slist_agregar_final(lista4,0);
    // lista4 = slist_agregar_final(lista4,6);
    // lista4 = slist_agregar_final(lista4,2);
    // lista4 = slist_agregar_final(lista4,4);

    // SList listaIntersecada = slist_intersecar(lista3,lista4);
    // SList listaIntersecada = slist_intersecar_custom(lista3,lista4,funcion_comparadora);
    // slist_recorrer(listaIntersecada, funcion_visitante);
    // lista3 = slist_ordenar(lista3, funcion_comparadora2);
    // lista4 = slist_ordenar(lista4, funcion_comparadora2);
    // slist_recorrer(lista3, funcion_visitante);
    // slist_recorrer(lista4, funcion_visitante);
    // lista3 = slist_reverso(lista3);
    // lista4 = slist_reverso(lista4);
    // slist_recorrer(lista3, funcion_visitante);
    // slist_recorrer(lista4, funcion_visitante);
    // SList listaIntercalada = slist_intercalar(lista3, lista4);
    // slist_recorrer(listaIntercalada, funcion_visitante);
    // SList listaPartida = slist_partir(lista3);
    // slist_recorrer(lista3, funcion_visitante);
    // slist_recorrer(listaPartida, funcion_visitante);
}