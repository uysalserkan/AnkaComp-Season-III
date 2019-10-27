#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int data;
};
struct node *delete_beg(struct node *start)
{
    struct node *ptr = start;
    start = start->next;
    free(ptr);
    return start;
}