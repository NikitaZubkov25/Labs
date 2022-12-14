#include "sorts.c"


int main(){
    int size = 1;
    input(&size,1,INT_MAX,"Input size of array for sorting:");
    int* arr = malloc(sizeof(int) * size);
    int* worstCase = malloc(sizeof(int) * size);
    int* selection = malloc(sizeof(int) * size);
    fillRand(arr, size, 10, 1);
    fillRand(worstCase, size, 10, 1);
    fillRand(selection, size, 10, 1);

    // Worst case sorting
    qsort(worstCase,size,sizeof(int),compare);

    calculateSort(arr,size,"Hoare sort", 1);
    calculateSort(worstCase,size,"Hoare sort(worst case)", 1);
    calculateSort(selection,size,"Selection sort", 0);




    free(arr);
    free(worstCase);
    free(selection);
    return 0;
}