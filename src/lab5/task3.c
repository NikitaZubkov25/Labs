#include <stdlib.h>
#include <time.h>
#include "arrays.h"
#include "inp_out.h"

int main() {
    srand(time(NULL));
    int rows = 1, cols = 1, choice = 0, greater = 0;
    input(&rows, 1, 50, "Input count of rows:");
    input(&cols, 1, 50, "Input count of cols:");
    input(&greater, -100, 100, "Input greater element:");
    int **arr = memoryAllocation(rows, cols);
    int *length = malloc(sizeof(int) * rows);
    fillLength(length,rows,cols);
    input(&choice, 1,2, "1.Self input with stop element 0\n2.Other types of input\nYour choice:");
    if(choice == 1){
        inputWithZero(arr,length, rows);
    } else{
        choiceInput(arr,rows,cols,100);
    }
    printMatrixWithLength(length,arr,&rows);
    printArray(length,rows);
    deleteGreaterElem(arr,rows,length,greater);
    deleteBlankRows(arr,&rows,length);
    printMatrixWithLength(length,arr,&rows);
    printArray(length,rows);
}