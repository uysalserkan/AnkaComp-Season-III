#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *delete_beg(struct node *start)
{
    struct node *ptr=start;
    start = start->next;
    start->prev=NULL;
    free(ptr);
    return start;
}