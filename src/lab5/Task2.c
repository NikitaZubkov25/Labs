//
// Created by movie on 11/23/2022.
//

#include "arrays.h"



int main(){
    srand(time(NULL));
    int rows, cols;

    input(&rows, 1,50);
    input(&cols, 1, 50);

    int** matrix = memory_allocation(rows, cols);
    fill_rand_matrix(matrix,rows,cols, 100);
//    fill_matrix(matrix, rows,cols);

    print_matrix(matrix,rows,cols);
    delete_row_with_saddle(matrix,&rows,cols);
    print_matrix(matrix,rows,cols);

    clear_rows(matrix,rows);
    free(matrix);


    return 0;
}