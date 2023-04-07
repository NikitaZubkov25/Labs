#include "stack.h"

int main() {
    stack first;
    stack second;
    stack third;

    createStack(&first);
    createStack(&second);
    createStack(&third);

    inputStackAsc(&first);
    inputStackAsc(&second);

    printf("first -");
    printStack(&first);
    printf("\nsecond -");
    printStack(&second);
    mergeStacks(&first, &second, &third);

    printf("\nthird - ");
    printStack(&third);
    freeStack(&first);
    freeStack(&second);
    freeStack(&third);

    return 0;
}