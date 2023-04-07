#include "deck.h"

int main() {
    struct FIFOd *head = NULL;
    struct FIFOd *tail = NULL;

    inputDeck(&head, &tail);
    printDeck(head);
    addIfNotEqual(&head,&tail);

    return 0;
}