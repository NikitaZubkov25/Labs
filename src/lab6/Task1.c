#include "sorts.h"


int main(){
    int size = 10;
    int* arr = malloc(sizeof(int) * size);
    fill_rand(arr,size,10, 1);
    print_array(arr,size);
    clock_t start= clock();
//    HoareMethod(arr,0,size - 1);
    SelectionSort(arr,size);
    printf("%lf\n", (double) (clock() - start)/CLOCKS_PER_SEC );
    print_array(arr,size);

    return 0;
}