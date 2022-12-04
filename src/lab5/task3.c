#include "arrays.h"

int main(){
    srand(time(NULL));
    int rows = 2;
    int cols = 2;
    int* length = malloc(sizeof(int) * cols );
    for(int i = 0; i < rows; i++){
        length[i] = cols;
    }
    int** arr = memory_allocation(rows,cols);
    fill_rand_matrix(arr,rows,cols,100);
    print_matrix(arr,rows,cols);
    print_array(length,cols);

    delete_greater_elements(length,arr,rows,3);
    print_matrix_with_length(length,arr,rows);
    print_array(length,cols);

}