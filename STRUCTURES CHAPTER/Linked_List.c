#include <stdio.h>
#include <stdlib.h>
struct Linked_List
{
    int data;
    struct Linked_List *next;
};

int main()
{
    struct Linked_List *first;
    struct Linked_List *second;
    struct Linked_List *third;
    struct Linked_List *forth;
    first = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    second = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    third = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    forth = (struct Linked_List *)malloc(sizeof(struct Linked_List));

    first->data = 2;
    first->next = second;
    second->data = 5;
    second->next = third;
    third->data = 0;
    third->next = forth;
    forth->data = 8;
    forth->next = NULL;
    // printf("we are here");

    struct Linked_List *printingData = first;
    printf("Data is: %d\n", printingData->data);
    while (printingData->next != NULL)
    {
        printingData = printingData->next;
        printf("Data is: %d\n", printingData->data);
    }
    free(first);
    free(second);
    free(third);
    free(forth);
}