#include <stdio.h>
void insert()
{
    int num;
    printf("enter your data: ");
    scanf("%d", &num);
    if (front == 0 && rear == MAX - 1)
        printf("overflow");
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = num;
    }
    else if (rear == MAX - 1 && front != 0)
    {
        rear = 0;
        queue[rear] = num;
    }
    else
    {
        rear++;
        queue[rear] = num;
    }
}