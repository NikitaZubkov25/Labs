//
// Created by movie on 11/26/2022.
//

#ifndef LAB5_SORTS_H
#define LAB5_SORTS_H

#include "arrays.h"

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

#endif //LAB5_SORTS_H
