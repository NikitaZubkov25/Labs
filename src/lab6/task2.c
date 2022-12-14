#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "lab-lib.h"


int main() {
    srand(time(NULL));
    int rows,cols,k;
    input(&rows,1,50,"Input count of rows:");
    input(&cols,1,50,"Input count of cols:");
    input(&k,1,10,"Input multiple:");

    int **arr = memoryAllocation(rows, cols);
    choiceInput(arr, rows, cols, 100);

    printMatrix(arr, rows, cols);
    sortMatrix(arr,cols,rows,k);
    printMatrix(arr, rows, cols);

    clearRows(arr,rows);
    free(arr);

}