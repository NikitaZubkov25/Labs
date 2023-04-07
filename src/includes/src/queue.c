//
// Created by Katerina on 07.04.2023.
//
#include "queue.h"

void enqueue(FIFO **head, int data) {
    FIFO *new_node = (FIFO *) malloc(sizeof(FIFO));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        FIFO *last_node = *head;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }
}

int dequeue(FIFO **head) {
    int data = 0;
    if (*head == NULL) {
        printf("Queue is empty.\n");
    } else {
        FIFO *temp_node = *head;
        data = (*head)->data;
        *head = (*head)->next;
        free(temp_node);
    }
    return data;
}

void printQueue(FIFO *head) {
    FIFO *current_node = head;
    printf("Queue: ");
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

void inputQueue(FIFO** head){
    int size, i = 0;
    printf("Input size:");
    scanf("%d", &size);
    while(i < size){
        int num;
        printf("Input queue element:");
        scanf("%d", &num);
        enqueue(head, num);
        i++;
    }
}

void addToTailIfEqual(FIFO** head){
    while(*head != NULL){
        int num;
        printf("Input num to add:");
        scanf("%d", &num);
        int data = dequeue(head);
        if(data == num){
            enqueue(head, num);
        }
        printQueue(*head);
    }
    printf("Queue is empty!");
}

int compareQueues(FIFO *q1, FIFO *q2) {
    while (q1 != NULL && q2 != NULL) {
        if (q1->data != q2->data) {
            return 0;
        }
        q1 = q1->next;
        q2 = q2->next;
    }
    if (q1 == NULL && q2 == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void deleteQueue(FIFO **head) {
    FIFO *current_node = *head;
    while (current_node != NULL) {
        FIFO *temp_node = current_node;
        current_node = current_node->next;
        free(temp_node);
    }
    *head = NULL;
}