#include <stdio.h>

#define INICIO {
#define FIN }
#define porsiempre for(;;)
#define paste(front,back) front ## back
#define hola 1
#define DIV(x,y) x/y

#ifdef hola
#endif


int main()INICIO

    float x = 1, y = 2;
    printf("%f",DIV((x+y),(y+y)));

    


    return 0;
FIN