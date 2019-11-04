#include <stdio.h>

void insert()
{
    int num;
    printf("\nEnter the number to be inserted in the queue: ");
    scanf("%d", &num);
    if (rear == MAX - 1)
    {
        printf("\n\tOverflow\n");
    }
    else if (front == -1 && rear == -1)
        front = rear = 0;
    else
    {
        rear++;
    }
    queue[rear]=num;
}