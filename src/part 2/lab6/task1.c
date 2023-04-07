#include "queue.h"

int main() {
    FIFO *head = NULL;
    inputQueue(&head);
    printQueue(head);
    addToTailIfEqual(&head);
    deleteQueue(&head);
    return 0;
}