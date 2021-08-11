#include<stdio.h>
#include<stdlib.h>

#define N 9

typedef struct stack {
    int topo;
    int tam;
    int *vetor;
} Stack;

int verificaNumeroValido(int sudoku[][N], int numeroAtual, int linha, int coluna);

void adicionaNumero(int sudoku[][N], int linha, int coluna, int ultimaLinha, int ultimaColuna);

int espacosVazios(int sudoku[][N]);

Stack* createStack(int tam);

void push (Stack* p, int elem);

void pop (Stack* p);

int empty_stack (Stack* p);

int full_stack (Stack* p);

void destroy_stack (Stack* p);