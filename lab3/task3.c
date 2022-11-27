#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int compare(const void* x1, const void* x2)
{
    return (*(int*)x2 - *(int*)x1);
}

int outputArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i != size - 1){
            printf("%d, ", arr[i]);
            if (i % 20 == 0 && i != 0) {
                printf("\n");
            }
        }
        else {
            printf("%d", arr[i]);
        }
    }
    printf("] \n \n");
}

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


int concat(int arr1[], int arr2[], int size1, int size2) {
    int size = size1 + size2,resultArr[200], j = 0, k = 0;
    for (int i = 0; i < size; i++) {
        if (j >= size1) {
            resultArr[i] = arr2[k];
            k++;
        }
        else if (k >= size2) {
            resultArr[i] = arr1[j];
            j++;
        }
        else if (arr1[j] > arr2[k]) {
            resultArr[i] = arr1[j];
            j++;
        }
        else {
            resultArr[i] = arr2[k];
            k++;
        }
    }
    outputArray(resultArr, size);
    return 0;
}

int main() {
    srand(time(NULL));
    int arr1[100], arr2[100], choice, arr2Size = 0, arr1Size;

    printf("Input first array length \n");
    input(&arr1Size, 1, 100);

    printf("Input second array length \n");
    input(&arr2Size, 1, 100);

    printf("If you want random number in array input 1, else input 2 \n");
    input(&choice, 1,2);

    if (choice == 1) {
        for (int i = 0; i < arr1Size; i++) {
            arr1[i] = rand() % 100;
        }
        for (int i = 0; i < arr2Size; i++) {
            arr2[i] = rand() % 100;
        }

        qsort(arr1, 100, sizeof(int), compare);
        qsort(arr2, 100, sizeof(int), compare);

        outputArray(arr1, arr1Size);
        outputArray(arr2, arr2Size);

        concat(arr1, arr2, arr1Size, arr2Size);
    }

    if (choice == 2) {
        printf("Input first array elements");
        for (int i = 0; i < arr1Size; i++) {
            int num = 0;
            printf("\narr1[%d] = ", i);
            arr1[i] = input( &num, 0, 100);
        }
        printf("Input second array elements");
        for (int i = 0; i < arr2Size; i++) {
            int num = 0;
            printf("\narr2[%d] = ", i);
            arr2[i] = input(&num, 0, 100);
        }
        printf("\n");
        outputArray(arr1, arr1Size);
        outputArray(arr2, arr2Size);
        concat(arr1, arr2, arr1Size, arr2Size);
    }

    return 0;
}