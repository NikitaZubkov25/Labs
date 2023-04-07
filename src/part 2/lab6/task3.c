#include "queue.h"

int main(){
    FIFO* head1 = NULL;
    FIFO* head2 = NULL;
    inputQueue(&head1);
    inputQueue(&head2);
    if(compareQueues(head1, head2)){
        printf("Equal");
    } else{
        printf("Not equal");
    }
    deleteQueue(&head1);
    deleteQueue(&head2);

}