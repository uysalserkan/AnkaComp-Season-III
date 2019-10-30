#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int data;
	struct stack *next;
};

struct stack *push(struct stack *top, int val)
{
	struct stack *ptr;
	ptr = (struct stack *)malloc(sizeof(struct stack));
	ptr->data = val;
	if (top == NULL)
	{
		ptr->next = NULL;
		top = ptr;
	}
	else
	{
		ptr->next = top;
		top = ptr;
	}
	return top;
}