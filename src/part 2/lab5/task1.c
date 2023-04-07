//
// Created by Katerina on 07.04.2023.
//
#include "stack.h"

int main() {
    stack first;
    stack second;

    createStack(&first);
    createStack(&second);

    inputStack(&first);
    inputStack(&second);

    printf("first -");
    printStack(&first);
    printf("\nsecond -");
    printStack(&second);

    printf("\nthird - ");
    printNotInStack(&first,&second);
    freeStack(&first);
    freeStack(&second);


    return 0;
}