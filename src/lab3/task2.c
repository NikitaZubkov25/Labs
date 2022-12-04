#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int outputArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i != size - 1) {
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

    return 0;
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

int deleteSequence(int arr[], int size) {
    int maxInd = 0;
    int minInd = 0;
    int resultArr[100];

    for (int i = 0; i < size; i++) {
        if (arr[i] > arr[maxInd]) {
            maxInd = i;
        }
        if (arr[i] <= arr[minInd]) {
            minInd = i;
        }
    }

    printf("minInd - %d \nmaxInd - %d\n", minInd, maxInd);
    printf("[");
    for (int i = 0; i < size; i++) {
        if (minInd < maxInd - 1) {
            if (i > minInd && i < maxInd) {
                while (arr[i] == arr[i + 1] - 1 || arr[i + 1] == arr[i + 2] - 1 && i + 2 <= minInd) {
                    i++;
                }
                if (arr[i] == arr[i - 1] + 1) {
                    i++;
                }
            }
        }
        else if (minInd - 1 > maxInd) {
            if (i > maxInd && i < minInd) {
                while (arr[i] == arr[i + 1] - 1 || arr[i + 1] == arr[i + 2] - 1 && i + 2 <= minInd) {
                    i++;
                }
                if (arr[i] == arr[i - 1] + 1) {
                    i++;
                }
            }
        }
        printf("%d, ", arr[i]);



    }
    printf("] \n");

    return 0;
}
int main()
{	srand(time(NULL));
    int arr[100], arrSize, choice;

    printf("Input array length: ");
    input(&arrSize, 1, 100);
    printf("\n");

    printf("If you want to generate random numbers in array press 1, else 2: ");
    input(&choice, 1, 2);
    printf("\n");

    if (choice == 1) {
        for (int i = 0; i < arrSize; i++) {
            arr[i] = rand() % 100;
        }
        outputArray(arr, arrSize);
        deleteSequence(arr, arrSize);
    }
    if( choice == 2){
        printf("Input array elements");
        for	(int i = 0; i < arrSize; i++) {
            int num = 0;
            printf("\narr[%d] = ", i);
            arr[i] = input(&num, 0, 100);
        }
        outputArray(arr, arrSize);
        deleteSequence(arr, arrSize);
    }
    return 0;
}
