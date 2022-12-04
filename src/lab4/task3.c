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

void output_matr(int matr[50][50], int row, int col) {
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
    int highestNum = matr[0][0];
    for (int i = 0; i < rows / 2; i++) {
        for (int j = 0; j < cols / 2; j++) {
            if(matr[i][j] > highestNum){
                highestNum = matr[i][j];
            }
        }
    }
    return highestNum;
}

int print_1zone(int matr[50][50], int rows, int cols){

    printf("\n");
    for (int i = 0; i < rows/2; i++) {
        printf("\t[");
        for (int j = 0; j < cols/2; j++) {
            if (j == cols/2 - 1) {
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
    output_matr(arr, rows, cols);
    printf("highest num in 1st zone is - %d\n", findHighestNumInMatrix(arr, rows, cols));
    printf("1st zone: \n");
    print_1zone(arr, rows, cols);

    return 0;
}