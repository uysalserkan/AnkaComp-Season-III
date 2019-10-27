#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int data;
};

struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    ptr = start;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = start;
    return start;
}