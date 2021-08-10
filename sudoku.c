#include"stack.h"

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

    
    int totalVazio = espacosVazios(sudoku);
    int i, j, numCelula;

    printf("%d\n", verificaNumeroValido(sudoku, 7, 0, 1));

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            if(sudoku[i][j] == 0) {
                // função de colocar numero
                for(numCelula = 1; numCelula <= 9; numCelula++) {
                    
                    
                }    
            }
        }
    }


    //Stack* stack = createStack(totalVazio);


    return 0;
}