#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int data;
};

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    printf("\t %d", ptr->data);
    return start;
}