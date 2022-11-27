//
// Created by movie on 11/21/2022.
//

#ifndef LAB5_ARRAYS_H
#define LAB5_ARRAYS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inp_out.h>


void fill_array(int* arr, int size){
    for(int i = 0; i < size; i++){
        printf("Input arr[%d]: ", i);
        input(&arr[i], -100, 100);
    }

}

void print_array(int* arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d, ", arr[i]);
    }
    printf("\n");
    printf("size: %d", size);
    printf("\n");
}

int is_simple(int num){
    if(num <= 1){
        return 0;
    }
    for(int i = 2; i < num; i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}

void remove_elements(int* arr, int *size){
    for(int i = (*size) - 1; i >= 0; i--){
        if(is_simple(arr[i])){
            printf("%d - is simple\n",arr[i]);
            for(int j = i; j < *size; j++ ){
                arr[j] = arr[j+1];
            }
            (*size)--;
        }
    }
    realloc(arr, sizeof(int) * (*size));
}

void fill_rand(int* arr, int size, int max, int isNegative){
    srand(time(NULL));
    if(isNegative == 1){
        for(int i = 0; i < size; i++){
        arr[i] = (rand() % (max * 2)) - max;
        }
    } else if(isNegative == 0){
        for(int i = 0; i < size; i++){
        arr[i] = rand() % max;
        }
    }

}

void fill_matrix(int** arr,int rows, int cols){
    for(int i = 0; i < rows;i++){
        fill_array(arr[i], cols);
    }
}

int **memory_allocation(int row, int col) {
    int **arr = (int **) malloc(row * sizeof(int **));
    for (int i = 0; i < row; i++) {
        arr[i] = (int *) calloc(col, sizeof(int));

    }
    return arr;
}


void fill_rand_matrix(int** arr,int rows, int cols, int max){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            arr[i][j] = (rand() % (max*2)) - max;
        }
    }
}

void print_matrix(int **arr, int rows, int cols){
    printf("[ \n");
    for(int i = 0; i < rows; i++){
        printf("\t[");
        for(int j = 0; j < cols; j++){
            if(j == cols - 1)
                printf("%d",arr[i][j]);
            else
                printf("%d,\t",arr[i][j]);
        }
        printf("],\n\n");
    }
    printf("]\n\n");
}

int find_lowest_in_col(int **arr,int rows, int col){
    int lowestInCol = arr[0][col];
    for(int i = 0; i < rows; i++){
        if(arr[i][col] < lowestInCol){
            lowestInCol = arr[i][col];
        }
    }
    return lowestInCol;
}



void delete_row(int **arr, int* rows, int ind){
    for(int i = ind; i < *rows - 1; i++){
        arr[i] = arr[i + 1];
    }
    (*rows)--;
    realloc(arr, sizeof(int) * (*rows));
}

void delete_row_with_saddle(int **arr, int* rows, int cols){
    for(int i = 0; i < *rows; i++){
        int indHighestRow = 0;
        int indHighestCol = 0;
        for(int j = 0; j < cols; j++){
           if(arr[i][j] > arr[indHighestRow][indHighestCol]){
               indHighestRow = i;
               indHighestCol = j;
           }
        }
       if(find_lowest_in_col(arr,*rows,indHighestCol) == arr[indHighestRow][indHighestCol]){
           delete_row(arr,(int*)rows,indHighestRow);
           printf("\nSaddle point in row %d, and its value is - %d \n", indHighestRow, arr[indHighestRow][indHighestCol]);
       }
    }

}

void clear_rows(int **arr, int rows){
    for(int i = 0; i < rows;i++){
        free(arr[i]);
    }
}

void delete_element_in_row(int* length, int** arr, int size, int row, int element){
    for(int i = element; i < size; i++){
        arr[row][i] = arr[row][i + 1];
    }
}

void print_matrix_with_length(int* length, int** arr, int rows){
    printf("[ \n");
    for(int i = 0; i < rows; i++){
        printf("\t[");
        for(int j = 0; j < length[i]; j++){
            if(j == length[i] - 1)
                printf("%d",arr[i][j]);
            else
                printf("%d,\t",arr[i][j]);
        }
        printf("],\n\n");
    }
    printf("]\n\n");
}

void delete_greater_elements(int* length, int** arr, int rows, int greater){
    int count;
    for(int i = 0; i < rows; i++){
        count = 0;
        for(int j = 0; j < length[i]; j++){
            if(arr[i][j] == 0){
                break;
            }
            if(arr[i][j] > greater ){
                count++;
                delete_element_in_row(length,arr,length[i],i,j);
                j--;
            }
        }
        length[i] -= count;
        realloc(arr[i], sizeof(int) * length[i]);
    }
}

void swap(int* arr,int first, int second ){
    int tmp;
    tmp = arr[first];
    arr[first] = arr[second];
    arr[second] = tmp;
}


#endif //LAB5_ARRAYS_H
