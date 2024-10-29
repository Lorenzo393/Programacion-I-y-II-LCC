#include <stdlib.h>
#include <stdio.h>

/*
 Ej 1: ¿Cuál es la salida del siguiente programa?
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


 Ej 2: ¿Cuál es la salida del siguiente programa?
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

// Ej 4:
void temperatura(){
    float temperatura;
    printf("Ingrese la temperatura del agua: ");
    scanf("%f", &temperatura);
    if (temperatura <= 0) printf("Estado: solido");
    else if (temperatura >= 100) printf("Estado: gaseoso");
    else printf("Estado: liquido");
}



int main(){

    temperatura();

return 0;
}
