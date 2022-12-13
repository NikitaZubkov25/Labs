//
// Created by movie on 11/23/2022.
//

#include "arrays.h"



int main(){
    srand(time(NULL));
    int rows, cols;
    input(&rows, 1,50,"Input rows: ");
    input(&cols, 1, 50, "Input columns: ");

    int** matrix = memoryAllocation(rows, cols);
    choiceInput(matrix, rows, cols, 100);

    printMatrix(matrix, rows, cols);
    deleteRowWithSaddle(matrix, &rows, cols);

    printf("Result: ");
    printMatrix(matrix, rows, cols);

    clearRows(matrix, rows);
    free(matrix);


    return 0;
}