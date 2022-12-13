#include "arrays.h"

int main(){
    int size, choice;
    input(&size, 2,100, "Input size of array: ");
    input(&choice, 1, 2, "If you want to generate random number - 1, else - 2: ");

    int* arr = calloc(size,sizeof(int));
    if(choice == 1){
        fillRand(arr, size, 100, 0);
    } else{
        fillArray(arr, size);
    }
    printArray(arr, size);
    removeElements(arr, &size);
    printArray(arr, size);

    free(arr);
    return 0;
}