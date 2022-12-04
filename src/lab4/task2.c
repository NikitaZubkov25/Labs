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

int findFirstPositiveCol(int arr[50][50], int col, int row) {
    int ind = -1;
    for (int j = 0; j < col; j++) {
        for (int i = 0; i < row; i++) {
            if (arr[i][j] < 0) {
                break;
            }
            if(i == row - 1 && arr[i][j] > 0) {
                ind = j;
                return ind;
            }
        }
    }
    return ind;
}

int switchPreviousColumnSignToOpposite(int arr[50][50], int row, int indOfColumn) {
    if (indOfColumn > 0) {
        for (int i = 0; i < row; i++) {
            arr[i][indOfColumn - 1] = -arr[i][indOfColumn - 1];
        }
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
    int index = findFirstPositiveCol(arr, cols, rows);
    switchPreviousColumnSignToOpposite(arr, rows,index);
    printf("%d\n", index );
    printf("RESULT : \n");
    output_matr(arr, rows, cols);
    return 0;
}
