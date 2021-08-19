#include"stack.h"
#include"sudoku.h"

int main() {
    int sudoku[N][N] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
                         {5, 2, 0, 0, 0, 0, 0, 0, 0},
                         {0, 8, 7, 0, 0, 0, 0, 3, 1},
                         {0, 0, 3, 0, 1, 0, 0, 8, 0},
                         {9, 0, 0, 8, 6, 3, 0, 0, 5},
                         {0, 5, 0, 0, 9, 0, 6, 0, 0},
                         {1, 3, 0, 0, 0, 0, 2, 5, 0},
                         {0, 0, 0, 0, 0, 0, 0, 7, 4},
                         {0, 0, 5, 2, 0, 6, 3, 0, 0} };

    
    int i, j, numCelula;
    Stack* stack = createStack(espacosVazios(sudoku)+2);

    /*Printa a base do sudoku a ser resolvido*/
    printf("Tabela de sudoku a ser resolvida: \n\n");
    for (i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(sudoku[i][j] == 0)
                printf("  ");
            else
                printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    /*Inicia a resolução do sudoku*/
    adicionaNumero(sudoku, stack, N, N);

    /*Printa o sudoku resolvido*/
    printf("Tabela de sudoku resolvida: \n\n");
    for (i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }

    return 0;
}