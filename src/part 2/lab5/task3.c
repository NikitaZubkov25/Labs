#include "stack.h"
#include <ctype.h>

typedef struct stackNodeC {
    char data;
    struct stackNodeC *next;
} stackNodeC;

typedef struct stackC {
    struct stackNodeC *head;
} stackC;

typedef struct stackNodeD {
    double data;
    struct stackNodeD *next;
} stackNodeD;

typedef struct stackD {
    stackNodeD *head;
} stackD;


void pushD(struct stackD *s, char data) {
    stackNodeD *newNode = (stackNodeD *) malloc(sizeof(stackNodeD));
    newNode->data = data;
    newNode->next = s->head;
    s->head = newNode;
}

int isEmptyD(stackD *s) {
    return s->head == NULL;
}

double popD(stackD *s) {
    if (isEmptyD(s)) {
        printf("Stack is empty!");
        return 0;
    } else {
        double data = s->head->data;
        stackNodeD *temp = s->head;
        s->head = s->head->next;
        free(temp);
        return data;
    }
}


void printStackD(stackD *stack) {
    stackNodeD *tmp = stack->head;
    while (tmp != NULL) {
        printf(" %lf ->", tmp->data);
        tmp = tmp->next;
    }
    printf(" NULL");
}


int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}


void pushC(struct stackC *s, char data) {
    stackNodeC *newNode = (stackNodeC *) malloc(sizeof(stackNodeC));
    newNode->data = data;
    newNode->next = s->head;
    s->head = newNode;
}

int isEmptyC(stackC *s) {
    return s->head == NULL;
}

char popC(stackC *s) {
    if (isEmptyC(s)) {
        printf("Stack is empty!");
        return 'z';
    } else {
        char data = s->head->data;
        stackNodeC *temp = s->head;
        s->head = s->head->next;
        free(temp);
        return data;
    }
}


void printStackC(stackC *stack) {
    stackNodeC *tmp = stack->head;
    while (tmp != NULL) {
        printf(" %c ->", tmp->data);
        tmp = tmp->next;
    }
    printf(" NULL");
}

int priority(char c) {
    switch (c) {
        case '(':
            return 1;
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
            return 2;
        default:
            return 0;
    }
}

int operate(int num1, int num2, char c) {
    switch (c) {
        case '+':
            return num2 + num1;
        case '-':
            return num2 - num1;
        case '*':
            return num2 * num1;
        case '/':
            return num2 / num1;
        default:
            return 0;
    }
}


int main() {
    char exp[] = "10+6*4/3+4";
    struct stackC charS = {NULL};
    stack stackN = {NULL};
    int result = 0;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(&stackN, num);
            i--;
        } else if (isOperator(exp[i])) {
            if (isEmptyC(&charS)) {
                pushC(&charS, exp[i]);
            } else if(exp[i] == '('){
                pushC(&charS, exp[i]);
            }
            else if (exp[i] == ')') {
                char c;
                while ((c = popC(&charS)) != '(') {
                    int num1 = pop(&stackN);
                    int num2 = pop(&stackN);
                    push(&stackN, operate(num1, num2, c));
                }
            } else if (priority(exp[i]) >= priority(charS.head->data)) {
                pushC(&charS, exp[i]);
            } else {
                char sign;
                while (!isEmptyC(&charS) && (sign = popC(&charS)) != '(') {
                    int num1 = pop(&stackN);
                    int num2 = pop(&stackN);
                    push(&stackN, operate(num1, num2, sign));
                }
                if(sign == '('){
                    pushC(&charS, sign);
                }
                i--;
            }
        }
    }
    if (!isEmptyC(&charS)) {
        while (charS.head != NULL) {
            char sign = popC(&charS);
            int num1 = pop(&stackN);
            int num2 = pop(&stackN);
            push(&stackN, operate(num1, num2, sign));
        }
    }


    printStack(&stackN);
    printf("\n");
    printStackC(&charS);
}