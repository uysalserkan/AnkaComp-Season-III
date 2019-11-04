#include <stdio.h>
void display()
{
    int i;
    if (fornt == -1 || front > rear)
    {
        printf("queue is empty")
    }
    else
    {
        for (i = front; i <= rear; i++)
            printf("\t%d", queue[i]);
    }
}