#ifndef LAB5_DECK_H
#define LAB5_DECK_H

#include <stdio.h>
#include <stdlib.h>

struct FIFOd {
    int data;
    struct FIFOd *next;
    struct FIFOd *prev;
};

void enqueue(struct FIFOd **head, struct FIFOd **tail, int data);

int dequeue(struct FIFOd **head, struct FIFOd **tail);

void printDeck(struct FIFOd *head);

void addIfNotEqual(struct FIFOd** head, struct FIFOd** tail);

void inputDeck(struct FIFOd** head, struct FIFOd** tail);

#endif //LAB5_DECK_H
