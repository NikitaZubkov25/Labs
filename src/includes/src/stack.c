#include "stack.h"

void createStack(stack *s) {
    s->top = NULL;
}

void freeStack(stack *s) {
    stackNode *current_node = s->top;
    while (current_node != NULL) {
        stackNode *temp_node = current_node;
        current_node = current_node->next;
        free(temp_node);
    }
    s->top = NULL;
}

int isEmpty(stack *s) {
    return s->top == NULL;
}

void push(stack *s, int data) {
    stackNode *newNode = (stackNode *) malloc(sizeof(stackNode));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!");
        return -1;
    } else {
        int data = s->top->data;
        stackNode *temp = s->top;
        s->top = s->top->next;
        free(temp);
        return data;
    }
}


void printStack(stack *stack) {
    stackNode *tmp = stack->top;
    while (tmp != NULL) {
        printf(" %d ->", tmp->data);
        tmp = tmp->next;
    }
    printf(" NULL");
}

void inputStack(stack *stack) {
    int size, i = 0;
    printf("Input stack size:");
    scanf("%d", &size);

    while (i < size) {
        int num = 0;
        printf("Enter num to stack:");
        scanf("%d", &num);
        push(stack, num);
        i++;
    }
}

void inputStackAsc(stack *stack) {
    int size, i = 0, prevNum = INT_MAX;
    printf("Input stack size:");
    scanf("%d", &size);

    while (i < size) {
        int num;
        printf("Enter num to stack:");
        scanf("%d", &num);
        if(num > prevNum){
            printf("Wrong input, enter num less than previous!\n");
            continue;
        }
        prevNum = num;
        push(stack, num);
        i++;
    }
}

int isInStack(stack *stack, int num) {
    stackNode *tmp = stack->top;
    while (tmp != NULL) {
        if (num == tmp->data) {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

void printNotInStack(stack *stack1, stack *stack2) {
    stackNode *tmp = stack1->top;
    while (tmp != NULL) {
        if (isInStack(stack2, tmp->data)) {
            tmp = tmp->next;
            continue;
        }
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL");
}

void mergeStacks(stack *s1, stack *s2, stack *result) {
    stack temp_stack;
    temp_stack.top = NULL;

    while (s1->top != NULL && s2->top != NULL) {
        if (s1->top->data < s2->top->data) {
            push(&temp_stack, s1->top->data);
            pop(s1);
        } else {
            push(&temp_stack, s2->top->data);
            pop(s2);
        }
    }

    while (s1->top != NULL) {
        push(&temp_stack, s1->top->data);
        pop(s1);
    }

    while (s2->top != NULL) {
        push(&temp_stack, s2->top->data);
        pop(s2);
    }

    while (temp_stack.top != NULL) {
        int temp_data = temp_stack.top->data;
        push(s1, temp_data);
        push(s2, temp_data);
        push(result, temp_data);
        pop(&temp_stack);
    }
}