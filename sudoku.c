#include"sudoku.h"

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
  int quadranteColuna = coluna - (coluna % 3);

  for(i = 0; !eh_igual && i<3; i++) {
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
  int i, j, k, voltar = 0;

  /*Percorre toda a matriz procurando posições vazias (0)*/
  for(i = 0; !voltar && i < N; i++) {
    for(j = 0; !voltar && j < N; j++) {
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
          sudoku[stack->vetorX[stack->topo]][stack->vetorY[stack->topo]] = 0;
          pop(stack);
          voltar = 1; /*Flag para saber se precisa voltar uma posição e tentar prosseguir com outro número*/
        }       
      }
    }
  }
}
