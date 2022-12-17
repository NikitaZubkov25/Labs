

#ifndef LAB5_ARRAYS_H
#define LAB5_ARRAYS_H

void fillArray(int *arr, int size);

void printArray(int *arr, int size);

int isSimple(int num);

void removeElements(int *arr, int *size);

void fillRand(int *arr, int size, int max, int isNegative);

void fillMatrix(int **arr, int rows, int cols);

int **memoryAllocation(int row, int col);

void fillRandMatrix(int **arr, int rows, int cols, int max);

void fillLength(int *length, int rows, int cols);

void fillMatrixWithZero(int** arr, int rows, int* length);

void choiceInput(int **arr, int rows, int cols, int max);

void inputWithZero(int** arr, int* length, int rows);

void printMatrix(int **arr, int rows, int cols);

int findLowestInCol(int **arr, int rows, int col);

void deleteRow(int **arr, int *rows, int ind);

void deleteRowWithSaddle(int **arr, int *rows, int cols);

void clearRows(int **arr, int rows);

void deleteElementInRow(int *length, int **arr, int size, int row, int element);

void printMatrixWithLength(const int *length, int **arr, const int *rows);

void deleteGreaterElem(int** arr,int rows, int* length, int greater);

void deleteBlankRows(int **arr, int *rows, int *length);

void swap(int *arr, int first, int second);








#endif //LAB5_ARRAYS_H
