#include "deck.h"

void enqueue(struct FIFOd **head, struct FIFOd **tail, int data) {
    struct FIFOd *new_node = (struct FIFOd*) malloc(sizeof(struct FIFOd));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = *tail;

    if (*tail != NULL) {
        (*tail)->next = new_node;
    }

    if (*head == NULL) {
        *head = new_node;
    }

    *tail = new_node;
}

int dequeue(struct FIFOd **head, struct FIFOd **tail) {
    struct FIFOd *node_to_remove = *head;
    int data = node_to_remove->data;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    if (*head == NULL) {
        *tail = NULL;
    }

    free(node_to_remove);
    return data;
}

void printDeck(struct FIFOd *head) {
    printf("Deck:");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void addIfNotEqual(struct FIFOd** head, struct FIFOd** tail){
    while(*head != NULL){
        int num;
        printf("Input num to add:");
        scanf("%d", &num);
        int data = dequeue(head, tail);
        if(data != num){
            enqueue(head, tail,  num);
        }
        printDeck(*head);
    }
    printf("Deck is empty!");
}

void inputDeck(struct FIFOd** head, struct FIFOd** tail){
    int size, i = 0;
    printf("Input size:");
    scanf("%d", &size);
    while(i < size){
        int num;
        printf("Input queue element:");
        scanf("%d", &num);
        enqueue(head,tail, num);
        i++;
    }
}