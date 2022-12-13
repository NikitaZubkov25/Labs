#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int input(int* variable, int from, int to) {
    while (!scanf_s("%d", &(*variable)) || getchar() != '\n') {
        printf("Wrong input, please try again! \n");
        rewind(stdin);
    }
    if ((*variable) < from || (*variable) > to) {
        printf("Wrong input, please try again! \n");
        input(variable, from, to);
    }
    return *variable;
}

void outputMatr(int matr[50][50], int row, int col) {
    printf("\n");
    for (int i = 0; i < row; i++) {
        printf("\t[");
        for (int j = 0; j < col; j++) {
            if (j == col - 1) {
                printf("%d", matr[i][j]);
            }
            else {
                printf("%d,\t", matr[i][j]);
            }
        }
        printf("]\n\n");
    }
}

int findHighestNumInMatrix(int matr[50][50], int rows, int cols) {
    if(rows % 2 == 1){
        rows = rows/2 + 1;
    }
    if(rows % 2 == 0){
        rows = rows/2;
    }
    if(cols % 2 == 1){
        cols = cols/2 + 1;
    }
    if(cols % 2 == 0){
        cols = cols/2;
    }
    int highestNum = matr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if(matr[i][j] > highestNum){
                highestNum = matr[i][j];
            }
        }
    }
    return highestNum;
}

int printFirstZone(int matr[50][50], int rows, int cols){

    printf("\n");
    if(rows % 2 == 1){
        rows = rows/2 + 1;
    }
    if(rows % 2 == 0){
        rows = rows/2;
    }
    if(cols % 2 == 1){
        cols = cols/2 + 1;
    }
    if(cols % 2 == 0){
        cols = cols/2;
    }

    for (int i = 0; i < rows; i++) {
        printf("\t[");
        for (int j = 0; j < cols; j++) {
            if (j == cols - 1) {
                printf("%d", matr[i][j]);
            }
            else {
                printf("%d,\t", matr[i][j]);
            }
        }
        printf("]\n\n");
    }
}

int main() {
    srand(time(NULL));
    int arr[50][50];
    int cols, rows;
    int choice;
    printf("Input count of rows: ");
    input(&rows, 1, 50);
    printf("Input count of columns: ");
    input(&cols, 1, 50);
    printf("If you want to generate random number input 1, else 2: ");
    input(&choice, 1, 2);
    if (choice == 1) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = rand() % 200 - 100;
            }
        }
    }
    if (choice == 2) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int num;
                printf("arr[%d][%d] = ", i, j);
                input(&num, -100, 100);
                arr[i][j] = num;
            }
        }
    }
    outputMatr(arr, rows, cols);
    printf("highest num in 1st zone is - %d\n", findHighestNumInMatrix(arr, rows, cols));
    printf("1st zone: \n");
    printFirstZone(arr, rows, cols);

    return 0;
}