#include"stack.h"

/*Função para criar uma pilha!*/
Stack* createStack (int tam) {
  Stack* p = (Stack*)malloc(sizeof(Stack));
  p->topo = 0;
  p->tam = tam;
  p->vetor = (int *)malloc(tam * sizeof(int));
  p->vetorX = (int *)malloc(tam * sizeof(int));
  p->vetorY = (int *)malloc(tam * sizeof(int));
  return p;
}

/*Função para empilhar um elemento!*/
void push (Stack* p, int elem, int posX, int posY) {
  if (full_stack(p)) {
    printf ("Pilha cheia\n");
    exit(1);
  }
  p->vetor[p->topo] = elem;
  // Guarda as posições de cada celula vazia que foi preenchida
  p->vetorX[p->topo] = posX;
  p->vetorY[p->topo] = posY;
  p->topo++;
}

/*Função para desempilhar um elemento!*/
void pop (Stack* p) {
  if (empty_stack(p)) {
    printf ("Pilha vazia\n");
    exit(1);
  }
  p->topo--;
}

/*Função para liberar a memória alocada.*/
int empty_stack (Stack* p) {
  return (p->topo ==  0);
}

/*Funão para testar se a pilha está cheia!*/
int full_stack (Stack* p) {
  return (p->topo == p->tam);
}

/*Função para testar se a pilha está vazia!*/
void destroy_stack (Stack* p) {
  free(p->vetor);
  free(p);
}

