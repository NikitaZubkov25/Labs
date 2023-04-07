#ifndef LAB5_STACK_H
#define LAB5_STACK_H

#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode *next;
};
typedef struct StackNode stackNode;

struct Stack {
    stackNode *top;
};
typedef struct Stack stack;

enum bool {
    false, true
};

void createStack(stack *s);

void freeStack(stack *s);


int isEmpty(stack *s);

void push(stack *s, int data);

int pop(stack *s);


void printStack(stack *stack);

void inputStack(stack *stack);

int isInStack(stack *stack, int num);

void printNotInStack(stack *stack1, stack *stack2);

void mergeStacks(stack* s1, stack* s2, stack* result);

void inputStackAsc(stack *stack);

#endif //LAB5_STACK_H
