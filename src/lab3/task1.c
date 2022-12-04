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
}


int sumOfOdd(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (-arr[i] % 2 == 1) {
            sum += arr[i];
        }
        if (arr[i] % 2 == 1) {
            sum += arr[i];
        }
    }
    printf("Sum of odds - (%d) \n", sum);
}

int sumBetweenNegativeNumbers(int arr[], int size) {
    int firstNegativeInd = 0;
    int lastNegativeInd = 0;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            firstNegativeInd = i;
            for (int j = i; j < size; j++) {
                if(arr[j] < 0){
                    lastNegativeInd = j;
                }
            }
            break;
        }
    }
    if (lastNegativeInd == firstNegativeInd || firstNegativeInd + 1 == lastNegativeInd) {
        printf("There are no sum beetween first and last negative element :(\n");
        return 0;
    }
    printf("first - %d\nlast - %d\n", firstNegativeInd, lastNegativeInd);
    for (int i = firstNegativeInd + 1; i < lastNegativeInd; i++) {
        sum += arr[i];
    }
    printf("Sum beetween first and last negative element - (%d)\n", sum);
}

int main()
{
    srand(time(NULL));

    int arr[100], arrSize, choice;

    printf("Input array length: ");
    input(&arrSize, 1, 100);

    printf("If you want to generate random number in array input 1, else input 2: ");
    input(&choice, 1, 2);
    if (choice == 1) {
        for (int i = 0; i < arrSize; i++) {
            arr[i] = rand() % 200 - 100 ;
        }
        outputArray(arr, arrSize);
    }
    if (choice == 2) {
        for (int i = 0; i < arrSize; i++) {
            int num;
            printf("arr[%d] = ", i);
            arr[i] = input(&num, -100, 100);
        }
        outputArray(arr, arrSize);
    }
    sumOfOdd(arr, arrSize);
    printf("\n");
    sumBetweenNegativeNumbers(arr, arrSize);

}