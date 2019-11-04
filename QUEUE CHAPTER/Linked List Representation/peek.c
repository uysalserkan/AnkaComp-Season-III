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

int peek(struct queue *q)
{
    if (q->front == NULL)
    {
        printf("queue is empty");
        return -1;
    }
    else
    {
        return q->front->data;
    }
}