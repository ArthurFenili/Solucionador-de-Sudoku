#ifndef SUDOKU_H
#define SUDOKU_H

/*----------------------------------------------------------*/
/*FUNÇÕES PARA VERIFICAÇÃO E PREENCHIMENTO DO SUDOKU
/*----------------------------------------------------------*/

#include"stack.h"

#define N 9

int verificaNumeroValido(int sudoku[][N], int numeroAtual, int linha, int coluna);

void adicionaNumero(int sudoku[][N], Stack* stack, int linha, int coluna);

int espacosVazios(int sudoku[][N]);

#endif // SUDOKU_H