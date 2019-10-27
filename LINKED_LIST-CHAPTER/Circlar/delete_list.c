#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int data;
};

struct node *delete_list(struct node *start)
{
    struct node *ptr = start;
    while (ptr->next != start)
    {
        start = delete_end(start);
    }
    free(start);
    return start;
}