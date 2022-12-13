//
// Created by movie on 11/23/2022.
//

#ifndef LAB5_INP_OUT_H
#define LAB5_INP_OUT_H

#include <stdio.h>
#include <stdlib.h>

void input(int *var, int min, int max, char *string) {
    printf("%s", string);
    while (!scanf("%d", var) || (*var > max && max != INT_MAX) ||
           (*var < min && min != INT_MIN) || getchar() != '\n') {
        printf("Wrong input! Enter again:");
        rewind(stdin);
    }
}

void input_string(char **str) {
    char c;
    int size = 1;
    *str = calloc(1, 1);
    while ((c = getchar()) != '\n') {
        (*str) = realloc(*str, size * sizeof(char));
        (*str)[size - 1] = c;
        size++;
    }
    (*str)[size - 1] = '\0';

};


#endif //LAB5_INP_OUT_H
