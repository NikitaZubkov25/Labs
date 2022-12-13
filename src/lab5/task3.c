#include "arrays.h"

int main(){
    srand(time(NULL));
    int cols = 0, rows = 0, greater = 0;
    input(&greater, -100,100, "Input greater number: ");
    input(&rows, 1, 50, "Input rows: ");
    input(&cols, 1, 50, "Input columns: ");
    int** arr = memoryAllocation(rows, cols);
    int* length = malloc(sizeof(int) * cols );
    fillLength(length, rows, cols);

    choiceInput(arr, rows, cols, 100);
    printMatrix(arr, rows, cols);

    deleteGreaterElements(length, arr, rows, greater);
    deleteBlankRows(arr,&rows,length);
    printMatrixWithLength(length, arr, &rows);

    clearRows(arr, rows);
    free(arr);

}