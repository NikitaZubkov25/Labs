//
// Created by movie on 11/21/2022.
//

#ifndef LAB5_ARRAYS_C
#define LAB5_ARRAYS_C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arrays.h"
#include "inp_out.h"


void fillArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        input(&arr[i], -100, 100, "Input arr element: ");
    }

}

void printArray(int *arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            printf("%d", arr[i]);
        } else {
            printf("%d, ", arr[i]);
        }

    }
    printf("]\n");
    printf("size: %d", size);
    printf("\n");
}

int isSimple(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void removeElements(int *arr, int *size) {
    for (int i = (*size) - 1; i >= 0; i--) {
        if (isSimple(arr[i])) {
            printf("%d - is simple\n", arr[i]);
            for (int j = i; j < *size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*size)--;
        }
    }
    realloc(arr, sizeof(int) * (*size));
}

void fillRand(int *arr, int size, int max, int isNegative) {
    srand(time(NULL));
    if (isNegative == 1) {
        for (int i = 0; i < size; i++) {
            arr[i] = (rand() % (max * 2)) - max;
        }
    } else if (isNegative == 0) {
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % max;
        }
    }

}

void fillMatrix(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        fillArray(arr[i], cols);
    }
}

int **memoryAllocation(int row, int col) {
    int **arr = (int **) malloc(row * sizeof(int **));
    for (int i = 0; i < row; i++) {
        arr[i] = (int *) calloc(col, sizeof(int));

    }
    return arr;
}


void fillRandMatrix(int **arr, int rows, int cols, int max) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = (rand() % (max * 2)) - max;
        }
    }
}

void fillLength(int *length, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        length[i] = cols;
    }
}

void choiceInput(int **arr, int rows, int cols, int max) {
    int choice;
    input(&choice, 1, 2, "if you want random number - 1, else - 2:  ");
    if (choice == 1) {
        fillRandMatrix(arr, rows, cols, max);
    } else if (choice == 2) {
        fillMatrix(arr, rows, cols);
    }
}

void printMatrix(int **arr, int rows, int cols) {
    printf("[ \n");
    for (int i = 0; i < rows; i++) {
        printf("\t[");
        for (int j = 0; j < cols; j++) {
            if (j == cols - 1)
                printf("%d", arr[i][j]);
            else
                printf("%d,\t", arr[i][j]);
        }
        printf("],\n\n");
    }
    printf("]\n\n");
}

int findLowestInCol(int **arr, int rows, int col) {
    int lowestInCol = arr[0][col];
    for (int i = 0; i < rows; i++) {
        if (arr[i][col] < lowestInCol) {
            lowestInCol = arr[i][col];
        }
    }
    return lowestInCol;
}


void deleteRow(int **arr, int *rows, int ind) {
    for (int i = ind; i < *rows - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*rows)--;
    realloc(arr, sizeof(int) * (*rows));
}

void deleteRowWithSaddle(int **arr, int *rows, int cols) {
    for (int i = 0; i < *rows; i++) {
        int indHighestRow = 0;
        int indHighestCol = 0;
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > arr[indHighestRow][indHighestCol]) {
                indHighestRow = i;
                indHighestCol = j;
            }
        }
        if (findLowestInCol(arr, *rows, indHighestCol) == arr[indHighestRow][indHighestCol]) {
            printf("\nSaddle point in row %d, and its value is - %d \n\n", indHighestRow,
                   arr[indHighestRow][indHighestCol]);
            deleteRow(arr, (int *) rows, indHighestRow);
            return;
        }

    }
    printf("There's now saddle point\n\n");
}


void clearRows(int **arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
}

void deleteElementInRow(int *length, int **arr, int size, int row, int element) {
    for (int i = element; i < size - 1; i++) {
        arr[row][i] = arr[row][i + 1];
    }
}

void printMatrixWithLength(const int *length, int **arr, const int *rows) {
    printf("[ \n");
    for (int i = 0; i < (*rows); i++) {
        printf("\t[");
        for (int j = 0; j < length[i]; j++) {
            if (j == length[i] - 1)
                printf("%d", arr[i][j]);
            else
                printf("%d,\t", arr[i][j]);
        }
        printf("],\n\n");
    }
    printf("]\n\n");
}

void deleteGreaterElements(int *length, int **arr, int rows, int greater) {
    int count;
    for (int i = 0; i < rows; i++) {
        count = 0;
        for (int j = 0; j < length[i]; j++) {
            if (arr[i][j] == 0) {
                break;
            }
            if (arr[i][j] > greater) {
                count++;
                deleteElementInRow(length, arr, length[i], i, j);
                j--;
            }
        }
        length[i] -= count;
        realloc(arr[i], sizeof(int) * length[i]);
    }
}

void deleteBlankRows(int **arr, int *rows, int *length) {
   for(int i = (*rows) - 1; i >= 0; i--){
       if(length[i] == 0){
           for(int j = i; j < (*rows) - 1;j++){
               arr[j] = arr[j + 1];
           }
           (*rows)--;
           realloc(arr, (*rows) * sizeof(int));
           for(int k = i; k < (*rows); k++){
               length[k] = length[k+1];
           }
           realloc(length, (*rows) * sizeof(int));
       }
   }
}



void swap(int *arr, int first, int second) {
    int tmp;
    tmp = arr[first];
    arr[first] = arr[second];
    arr[second] = tmp;
}


#endif //LAB5_ARRAYS_C
