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
void LeftRotate(RBTreeNode **HeadOfTree, RBTreeNode *temp);
void RightRotate(RBTreeNode **HeadOfTree, RBTreeNode *temp);
void fixInIter(RBTreeNode **HeadOfMaster, RBTreeNode *temp);

// * Main functions

int main()
{
	LLNode *LinkedList;
	RBTreeNode *RootNode = (RBTreeNode *)malloc(sizeof(RBTreeNode));
	// takeDataLL(&LinkedList);
	// printLL(LinkedList);
	int data;
	scanf("%d", &data);
	while (data != -1)
	{
		RBTreeInsert(&RootNode, data);
		scanf("%d", &data);
	}
	printf("Head->left: %d and color->left: %c\n", RootNode->right->data, RootNode->right->Color);
	printf("Head->left: %d and color->left: %c\n", RootNode->right->right->data, RootNode->right->right->Color);
	printf("Head->left: %d and color->left: %c\n", RootNode->right->right->right->data, RootNode->right->right->right->Color);
	printf("Head->left: %d and color->left: %c\n", RootNode->right->left->right->data, RootNode->right->left->right->Color);
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
		temp->left = NULL;
		temp->right = NULL;
		temp->parent == NULL;
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
		fixInIter(RootOfTree, temp);
	}
}

void LeftRotate(RBTreeNode **HeadOfTree, RBTreeNode *temp)
{
	if (!temp || !temp->right)
		return;
	RBTreeNode *tempRight = temp->right;
	temp->right = tempRight->left;

	if (temp->right != NULL)
		temp->right->parent = temp;

	tempRight->parent = temp->parent;

	if (temp->parent == NULL)
		(*HeadOfTree) = tempRight;

	else if (temp == temp->parent->left)
		temp->parent->left = tempRight;
	else
	{
		temp->parent->right = tempRight;
	}
	tempRight->left = temp;

	temp->parent = tempRight;
}

void RightRotate(RBTreeNode **HeadOfTree, RBTreeNode *temp)
{
	if (!temp || !temp->left)
		return;
	RBTreeNode *tempLeft = temp->left;
	temp->left = tempLeft->right;
	if (tempLeft->right != NULL)
		tempLeft->right->parent = temp;
	tempLeft->parent = temp->parent;

	if (tempLeft->parent == NULL)
		(*HeadOfTree) = tempLeft;

	else if (temp == temp->parent->left)
		temp->parent->left = tempLeft;

	else
	{
		temp->parent->right = tempLeft;
	}
	tempLeft->right = temp;
	temp->parent = tempLeft;
}

void fixInIter(RBTreeNode **HeadOfMaster, RBTreeNode *temp)
{
	while (temp != *HeadOfMaster && temp != (*HeadOfMaster)->left && temp != (*HeadOfMaster)->right && temp->parent->Color == 'R')
	{
		RBTreeNode *gecici;

		if (temp->parent && temp->parent->parent && temp->parent == temp->parent->parent->left)
			gecici = temp->parent->parent->right;
		else
			gecici = temp->parent->parent->left;

		if (!gecici)
			temp = temp->parent->parent;
		else if (gecici->Color == 'R')
		{
			gecici->Color = 'B';
			temp->parent->Color = 'B';
			temp->parent->parent->Color = 'R';
			temp = temp->parent->parent;
		}

		else
		{
			if (temp->parent == temp->parent->parent->left && temp == temp->parent->left)
			{
				char tempParentColor = temp->parent->Color;
				temp->parent->Color = temp->parent->parent->Color;
				temp->parent->parent->Color = tempParentColor;
				RightRotate(HeadOfMaster, temp->parent->parent);
			}

			if (temp->parent && temp->parent->parent && temp->parent == temp->parent->parent->left && temp == temp->parent->left)
			{
				char tempColor = temp->Color;
				temp->Color = temp->parent->parent->Color;
				temp->parent->parent->Color = tempColor;
				LeftRotate(HeadOfMaster, temp->parent);
				RightRotate(HeadOfMaster, temp->parent->parent);
			}

			if (temp->parent && temp->parent->parent && temp->parent == temp->parent->parent->right && temp == temp->parent->right)
			{
				char tempParColor = temp->parent->Color;
				temp->parent->Color = temp->parent->parent->Color;
				temp->parent->parent->Color = tempParColor;
				LeftRotate(HeadOfMaster, temp->parent->parent);
			}

			if (temp->parent && temp->parent->parent && temp->parent == temp->parent->parent->right && temp == temp->parent->left)
			{
				char tempColor = temp->Color;
				temp->Color = temp->parent->parent->Color;
				temp->parent->parent->Color = tempColor;
				RightRotate(HeadOfMaster, temp->parent);
				LeftRotate(HeadOfMaster, temp->parent->parent);
			}
		}
	}

	(*HeadOfMaster)->Color = 'B';
}

// ! https://gist.github.com/VictorGarritano/5f894be162d39e9bdd5c