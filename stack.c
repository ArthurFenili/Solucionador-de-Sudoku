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
  int i, j, eh_igual = 0;

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

  int quadranteLinha = linha - (linha % 3);
  int quadranteColuna = coluna = (coluna % 3);

  for(i = 0; !eh_igual && i<3; i++) {  //// ARRUMAR ISSO AQUI
    for(j = 0; j<3; j++) {
      if(sudoku[i + quadranteLinha][j + quadranteColuna] == numeroAtual) {
        eh_igual = 1;
        break;
      }
    }
  }

  if (!eh_igual)
    return 1;
  else
    return 0;

}

void adicionaNumero(int sudoku[][N], Stack* stack, int linha, int coluna) {
  int i, j, k;

  /*Percorre toda a matriz procurando posições vazias (0)*/
  for(i = 0; i < N; i++) {
    for(j = 0; j < N; j++) {
      if(sudoku[i][j] == 0) {
        /*Tenta adicionar os números de 1 a 9 nas posições vazias*/
        for(k = 1; k<=9; k++) {
          if(verificaNumeroValido(sudoku, k, i, j)) {
            /*Se o número for válido, adiciona ele na stack e chama a função recursivamente*/
            sudoku[i][j] = k;
            push(stack, k, i, j);
            adicionaNumero(sudoku, stack, linha, coluna);
          }
        }
        /*Se os números de 1 a 9 acabaram e ainda existem espaços vazios, desempilha o valor anterior e procura novo número válido*/
        if(espacosVazios(sudoku)) {
          pop(stack);
          sudoku[stack->vetorX[stack->topo]][stack->vetorY[stack->topo]] = 0;
        }       
        
      }
    }
  }
    

}

/*--------------------------------------------*/
/*FUNÇÕES STACK*/

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

/*Funão para testar se a pilha está vazia!*/
void destroy_stack (Stack* p) {
  free(p->vetor);
  free(p);
}

