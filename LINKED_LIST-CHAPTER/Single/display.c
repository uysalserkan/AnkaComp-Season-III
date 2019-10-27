#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int data;
};

struct node *display(struct node *start)
{
    struct node *ptr = start;
    while (ptr != NULL)
    {
        printf("%d \t", ptr->data);
        ptr = ptr->next;
    }
    return start;
}