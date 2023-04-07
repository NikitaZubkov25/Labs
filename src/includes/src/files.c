#include "stdio.h"
#include "stdlib.h"
#include <inp_out.h>
#include "files.h"


int fillArrayFile(int *arr) {
    int i = 0;
    while(1){
        arr = realloc(arr ,(i+1) * sizeof(int));
        input(&arr[i], 0, 100, "Input Digit (0 to stop):");
        if(!arr[i]){
            return i;
        }
        i++;
    }
}

int writeFile(char *filename) {
    int *arr = malloc(1);
    int len = fillArrayFile(arr);
    FILE *out = fopen(filename, "wb");
    fwrite(arr, sizeof(int), len, out);
    fclose(out);
    return len;
}

void bubbleSortFile(char *filename, int len) {
    int tmp1, tmp2;
    FILE *out = fopen(filename, "r+b");
    for (int i = 0; i < len; i++) {
        fseek(out, 0, SEEK_SET);
        for (int j = 0; j < len; j++) {
            fread(&tmp1, sizeof(int), 1, out);
            fread(&tmp2, sizeof(int), 1, out);
            if (tmp1 > tmp2) {
                fseek(out, (int) -(2 * sizeof(int)), SEEK_CUR);
                fwrite(&tmp2, sizeof(int), 1, out);
                fwrite(&tmp1, sizeof(int), 1, out);
            }
            fseek(out, (int) -sizeof(int), SEEK_CUR);
        }
    }
}


void readFile(char *filename, int len) {
    FILE *out = fopen(filename, "rb");

    int num;
    printf("\nFile state - [");
    for (int i = 0; i < len; i++) {
        fread(&num, sizeof(int), 1, out);
        if (i != len - 1) {
            printf("%d, ", num);
        } else {
            printf("%d", num);
        }
    }
    printf("]\n\n");
}