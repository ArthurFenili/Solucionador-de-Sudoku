#include"stack.h"

/*--------------------------------------------*/
/*FUNÇÕES GERAIS*/

/*Verifica quantas celulas estão vazias*/
int espacosVazios(int sudoku[][N]) {
    int i, j, totalVazio = 0;

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            if(sudoku[i][j] == 0)
                totalVazio++;
        }
    }

    return totalVazio;
}

int verificaNumeroValido(int sudoku[][N], int numeroAtual, int linha, int coluna) {
  int i, eh_igual = 0;

  for(i = 0; i<N; i++) {
    if(i != coluna && sudoku[linha][i] == numeroAtual) { // verifica na linha
      eh_igual = 1;
      break;
    }
    if(i != linha && sudoku[i][coluna] == numeroAtual) { // verifica na coluna
      eh_igual = 1;
      break;
    }
  }

  // fazer função pra verificar no 3x3

  if (!eh_igual)
    return 1;
  else
    return 0;

}


/*--------------------------------------------*/
/*FUNÇÕES STACK*/

/*Função para criar uma pilha!*/
Stack* createStack (int tam) {
  Stack* p = (Stack*)malloc(sizeof(Stack));
  p->topo = 0;
  p->tam = tam;
  p->vetor = (int *)malloc(tam * sizeof(int));
  return p;
}

/*Função para empilhar um elemento!*/
void push (Stack* p, int elem) {
  if (full_stack(p)) {
    printf ("Pilha cheia\n");
    exit(1);
  }
  p->vetor[p->topo] = elem;
  p->topo++;
}

/*Função para desempilhar um elemento!*/
int pop (Stack* p) {
  if (empty_stack(p)) {
    printf ("Pilha vazia\n");
    exit(1);
  }
  p->topo--;
  return p->vetor[p->topo];
}

/*Função para liberar a memória alocada.*/
int empty_stack (Stack* p) {
  return (p->topo ==  0);
}

/*Funão para testar se a pilha está cheia!*/
int full_stack (Stack* p) {
  return (p->topo == p->tam);
}

/*Funão para testar se a pilha está vazia!*/
void destroy_stack (Stack* p) {
  free(p->vetor);
  free(p);
}

