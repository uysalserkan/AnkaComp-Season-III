#include <stdio.h>
int delete_element() {
    int val;
    if(front==-1&&rear==-1)
    {
        printf("\nOVERFLOW\n");
        return -1;
    }
    else
    {
        val = queue[front];
        front++;
        if(front > rear)
        front = rear -1;
        return val;
    }
    
}