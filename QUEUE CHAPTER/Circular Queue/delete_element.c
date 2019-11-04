#include <stdio.h>
int delete_element()
{
    int val;
    if (front == -1 && rear == -1)
    {
        printf("underflow");
        return -1;
    }
    val = queue[front];
    if (front == rear)
        front = rear = -1;
    else
    {
        if (front == MAX - 1)
            front = 0;
        else
            front++;
    }
    return val;
}