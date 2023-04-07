#ifndef LAB5_QUEUE_H
#define LAB5_QUEUE_H

#include "stdlib.h"
#include "stdio.h"

typedef struct {
    int data;
    struct FIFO *next;
} FIFO;

void enqueue(FIFO **head, int data);

int dequeue(FIFO **head);

void printQueue(FIFO *head);

void inputQueue(FIFO** head);

void addToTailIfEqual(FIFO** head);

int compareQueues(FIFO *q1, FIFO *q2);

void deleteQueue(FIFO **head);

#endif //LAB5_QUEUE_H
