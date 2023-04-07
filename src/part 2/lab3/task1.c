#include <stdio.h>
#include "helpers.h"

typedef struct {
    unsigned int x: 9;
} number;

typedef struct {
    unsigned a0: 1;
    unsigned a1: 1;
    unsigned a2: 1;
    unsigned a3: 1;
    unsigned a4: 1;
    unsigned a5: 1;
    unsigned a6: 1;
    unsigned a7: 1;
    unsigned a8: 1;
} byte;

typedef union {
    number number;
    byte byte;
} code;

int main() {
    int num;
    input(&num, 1, 511, "Enter num to divide by 8:");
    number numForConvert = { num };
    code c;
    c.number = numForConvert;
    printf("Initial binary num - %d %d %d %d %d %d %d %d %d \n", c.byte.a8, c.byte.a7, c.byte.a6, c.byte.a5, c.byte.a4, c.byte.a3, c.byte.a2, c.byte.a1, c.byte.a0);

    c.byte.a0 = c.byte.a3;
    c.byte.a1 = c.byte.a4;
    c.byte.a2 = c.byte.a5;
    c.byte.a3 = c.byte.a6;
    c.byte.a4 = c.byte.a7;
    c.byte.a5 = c.byte.a8;
    c.byte.a6 = 0;
    c.byte.a7 = 0;
    c.byte.a8 = 0;

    printf("Result binary num - %d %d %d %d %d %d %d %d %d \n", c.byte.a8, c.byte.a7, c.byte.a6, c.byte.a5, c.byte.a4, c.byte.a3, c.byte.a2, c.byte.a1, c.byte.a0);
    printf("Result - %d", c.number.x);
}