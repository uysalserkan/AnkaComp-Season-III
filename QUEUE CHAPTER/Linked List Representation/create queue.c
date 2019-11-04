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
struct queue *q = (struct queue *)malloc(sizeof(struct queue));

void create_queue()
{
    q->front = q->rear = NULL;
}