#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

struct queue *delete_element(struct queue *q)
{
    struct node *ptr;
    ptr = q->front;
    if(q->front==NULL)
    printf("\nUNDERFLOW");
    else{
        q->front=q->front->next;
        printf("the deleted data is: %d",ptr->data);
        free(ptr);
    }
    return q;
}