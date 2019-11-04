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

struct queue *display(struct queue *q)
{
    struct node *ptr;
    ptr = q->front;
    if (ptr == NULL)
        print("\nQueue is empty\n");
    else
    {
        printf("\n");
        while (ptr != q->rear)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\t", ptr->data);
    }
    return q;
}