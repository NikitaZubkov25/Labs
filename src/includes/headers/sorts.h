//
// Created by Katerina on 13.12.2022.
//

#ifndef LAB5_SORTS_H
#define LAB5_SORTS_H

void HoareMethod(int* arr,int first,int last);

void SelectionSort(int* arr, int size);

int compare(const void* x1, const void* x2);

void calculateSort(int* arr, int size, char* sortName, int sort);

void sortMatrix(int** arr, int cols, int rows, int k);

#endif //LAB5_SORTS_H
