#include "arrays.h"

int main(){
    int size;
    input(&size, 2,100);

    int* arr = calloc(size,sizeof(int));
    fill_rand(arr, size, 100, 0);

    print_array(arr,size);
    remove_elements(arr, &size);
    print_array(arr,size);

    free(arr);
    return 0;
}