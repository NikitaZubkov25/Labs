//
// Created by movie on 11/26/2022.
//

#ifndef LAB5_SORTS_C
#define LAB5_SORTS_C

#include "arrays.h"
#include "sorts.h"
#include "stdio.h"
#include "time.h"

void HoareMethod(int* arr,int first,int last){
    int i, j, pivot;
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        while(i<j){
            while(arr[i]<=arr[pivot]&&i<last)
                i++;
            while(arr[j]>arr[pivot])
                j--;
            if(i<j){
                swap(arr,i,j);
            }
        }
        swap(arr,pivot,j);
        HoareMethod(arr,first,j-1);
        HoareMethod(arr,j+1,last);
    }
}

void SelectionSort(int* arr, int size){
    for(int i = 0; i < size;i++){
        for(int j = 0; j < size; j++){
            if(arr[i] < arr[j]){
               swap(arr,i, j);
            }
        }
    }
}

int compare(const void* x1, const void* x2)
{
    return (*(int*)x2 - *(int*)x1);
}

void calculateSort(int* arr, int size, char* sortName, int sort){
    clock_t start = clock();
    if(sort == 1){
        HoareMethod(arr,0,size - 1);
    } else{
        SelectionSort(arr,size);
    }

    printf("%s time is - %1.30lf\n", sortName, (double) (clock() - start)/CLOCKS_PER_SEC );
}

void sortMatrix(int** arr, int cols, int rows, int k){
    for (int i = 0; i < rows; i++) {
        if ((i+1) % k == 0) {
            printf("row - %d\n", i+1);
            int sum1 = 0;
            int sum2 = 0;
            for (int j = 0; j < cols; j++) {
                if (i + k < rows) {
                    if (arr[i][j] > 0) {
                        sum1 += arr[i][j];
                    }
                    if (arr[i + k][j] > 0) {
                        sum2 += arr[i + k][j];
                    }

                }
            }
            if (sum1 < sum2) {
                int *temp = arr[i];
                arr[i] = arr[i + k];
                arr[i + k] = temp;
            }
        }

    }
}
#endif //LAB5_SORTS_C
