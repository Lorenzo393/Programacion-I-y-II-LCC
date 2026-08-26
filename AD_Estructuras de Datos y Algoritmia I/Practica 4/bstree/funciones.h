#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__
typedef void *(*FuncionCopiadora)(void *dato);
typedef int (*FuncionComparadora)(void *dato1, void *dato2);
typedef void (*FuncionDestructora)(void *dato);
typedef void (*FuncionVisitanteExtra)(void *dato, void *extra);
typedef void (*FuncionVisitante)(void *dato);
typedef struct _GNode{
    void *dato;
    struct _GNode *sig;
} GNode;
#endif