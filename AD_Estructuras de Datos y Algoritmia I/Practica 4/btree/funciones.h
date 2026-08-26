#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__

typedef void (*FuncionVisitanteExtra) (int dato, void *extra);
typedef void (*FuncionVisitante)(int dato);
typedef void (*FuncionDestructora) (void *dato);
typedef void (*FuncionVisitante2) (void *dato);
typedef void *(*FuncionCopia) (void *dato);

typedef struct _GNode{
    void *dato;
    struct _GNode *sig;
} GNode;

#endif