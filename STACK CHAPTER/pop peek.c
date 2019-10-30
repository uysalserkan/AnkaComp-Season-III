#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

struct stack *pop(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    if (top == NULL)
    {
        printf("\nStack underflow");
    }
    else
    {
        top = top->next;
        printf("\nThe value being deleted is: %d", ptr->data);
        free(ptr);
    }
    return top;
}
struct stack *peek(struct stack *top)
{
    if (top == NULL)
        return -1;
    else
        return top->data;
}