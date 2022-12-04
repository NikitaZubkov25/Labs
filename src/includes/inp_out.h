//
// Created by movie on 11/23/2022.
//

#ifndef LAB5_INP_OUT_H
#define LAB5_INP_OUT_H

#include <stdio.h>
#include <stdlib.h>

void input(int *var, int min, int max) {
    while (!scanf("%d", var) || (*var > max && max != INT_MAX) ||
           (*var < min && min != INT_MIN) || getchar() != '\n') {
        printf("Wrong input! Enter again:");
        rewind(stdin);
    }
}

#endif //LAB5_INP_OUT_H
