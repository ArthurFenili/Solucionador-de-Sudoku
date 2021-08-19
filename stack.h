#ifndef STACK_H
#define STACK_H

/*--------------------------------------------*/
/*FUNÇÕES PARA A MANIPULAÇÃO DA STACK*/
/*--------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
    int topo;
    int tam;
    int *vetor;
    int *vetorX;
    int *vetorY;
} Stack;

Stack* createStack(int tam);

void push (Stack* p, int elem, int posX, int posY);

void pop (Stack* p);

int empty_stack (Stack* p);

int full_stack (Stack* p);

void destroy_stack (Stack* p);

#endif //STACK_H