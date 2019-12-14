/*
*  ____________________________________
* |         Comiler: GCC 5.4.0        |
* |     Enviroment:  Ubuntu 5.4.0     |
* |                                   |
* |    SERKAN                UYSAL    |
* |      uysalserkan08@gmail.com      |
* |___________________________________|
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct LLNode
{
	int data;
	struct LLNode *next;
};

struct RBTreeNode
{
	int data;
	char Color;
	struct RBTreeNode *left;
	struct RBTreeNode *right;
	struct RBTreeNode *parent;
};

// ? Typedef notations
typedef struct RBTreeNode RBTreeNode;
typedef struct LLNode LLNode;

// ? Function prototypes
void takeDataLL(LLNode **head);
void printLL(LLNode *head);
RBTreeNode *grandParent(RBTreeNode *head);
void RBTreeInsert(RBTreeNode **RootOfTree, int data);

// * Main functions

int main()
{
	LLNode *LinkedList;
	takeDataLL(&LinkedList);
	printLL(LinkedList);
}

void takeDataLL(LLNode **head)
{
	LLNode *firstNodeAdress = *head;
	int data;
	scanf("%d", &data);
	while (data != -1)
	{
		(*head)->data = data;
		(*head)->next = (LLNode *)malloc(sizeof(LLNode));
		*head = (*head)->next;
		scanf("%d", &data);
	}
	*head = firstNodeAdress;
}

void printLL(LLNode *head)
{
	while (head->next != NULL)
	{
		printf("Data: %d\n", head->data);
		head = head->next;
	}
}

RBTreeNode *grandParent(RBTreeNode *head)
{
	if (head != NULL && head->parent != NULL)
		return head->parent->parent;
	else
		return NULL;
}

void RBTreeInsert(RBTreeNode **RootOfTree, int data)
{
	if (RootOfTree == NULL)
	{
		(*RootOfTree)->Color = 'B';
		(*RootOfTree)->data = data;
		(*RootOfTree)->left = (*RootOfTree)->right = (*RootOfTree)->parent = NULL;
	}
	else
	{
		RBTreeNode *usefullNode = NULL;
		RBTreeNode *temp = (RBTreeNode *)malloc(sizeof(RBTreeNode));
		temp->data = data;
		temp->left = temp->right = temp->parent == NULL;
		RBTreeNode *ptr = (*RootOfTree);
		for (; ptr != NULL;)
		{
			usefullNode = ptr;
			if (temp->data < ptr->data)
			{
				ptr = ptr->left;
			}
			else
			{
				ptr = ptr->right;
			}
		}
		temp->parent = usefullNode;
		if (temp->data > usefullNode->data)
		{
			usefullNode->right = temp;
		}
		else
		{
			usefullNode->left = temp;
		}
		temp->Color = 'R';

		//FixNode
	}
}

// ! https://gist.github.com/VictorGarritano/5f894be162d39e9bdd5c