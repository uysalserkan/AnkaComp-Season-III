/*
*  ____________________________________
* |         Comiler: GCC 7.4.0        |
* |     Enviroment:  Debian 9.2.1-19  |
* |                                   |
* |    SERKAN                UYSAL    |
* |      uysalserkan08@gmail.com      |
* |___________________________________|
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct treeNode
{
	struct treeNode *left;
	struct treeNode *right;
	int value;
	int identity;
};

struct linkedListNode
{
	int value;
	int identity;
	struct linkedListNode *next;
};

typedef struct treeNode BTNode;
typedef struct linkedListNode LLNode;

int totalNode = 0;
LLNode *takeDataUnsortedLL(LLNode *head);
BTNode *GiveTheTree(BTNode *BTHead, LLNode *LLHead);
BTNode *addNode2Tree(BTNode *head, LLNode data);
void sortTheLL(LLNode *head);
void printLLNode(LLNode *head);
void printBT(BTNode *BTHead, int activeHeight, int leftIs, int rootData);
int btHeight(int);
int realBTHeight(BTNode *);

int main()
{
	LLNode *LLhead = (LLNode *)malloc(sizeof(LLNode));
	LLhead = takeDataUnsortedLL(LLhead);
	BTNode *master = (BTNode *)malloc(sizeof(BTNode));
	master = GiveTheTree(master, LLhead);
	sortTheLL(LLhead);
	printLLNode(LLhead);
	printf("\n");
	int masterHeight = realBTHeight(master);
	if (masterHeight >= 1)
	{
		printBT(master, 1, -1, -1);
		printf("\n");
	}
	if (masterHeight >= 2)
	{
		printBT(master, 2, -1, -1);
		printf("\n");
	}
	if (masterHeight >= 3)
	{
		printBT(master, 3, -1, -1);
		printf("\n");
	}
	if (masterHeight >= 4)
	{
		printBT(master, 4, -1, -1);
		printf("\n");
	}
	if (masterHeight >= 5)
	{
		printBT(master, 5, -1, -1);
		printf("\n");
	}
	if (masterHeight >= 6)
	{
		printBT(master, 6, -1, 0);
		printf("\n");
	}
	if (masterHeight >= 7)
	{
		printBT(master, 7, -1, 0);
		printf("\n");
	}
	if (masterHeight >= 8)
	{
		printBT(master, 8, -1, 0);
		printf("\n");
	}
}

LLNode *takeDataUnsortedLL(LLNode *head)
{
	int usr_id, usr_val;
	scanf("%d %d", &usr_id, &usr_val);
	LLNode *polEli = (LLNode *)malloc(sizeof(LLNode));
	polEli->identity = usr_id;
	polEli->value = usr_val;
	head = polEli;
	scanf("%d %d", &usr_id, &usr_val);
	while (usr_id != -1 && usr_val != -1)
	{
		LLNode *body = (LLNode *)malloc(sizeof(LLNode));
		body->identity = usr_id;
		body->value = usr_val;
		polEli->next = body;
		polEli = polEli->next;
		scanf("%d %d", &usr_id, &usr_val);
	}
	return head;
}

BTNode *GiveTheTree(BTNode *BTHead, LLNode *LLHead)
{
	for (; LLHead != NULL; LLHead = LLHead->next)
		BTHead = addNode2Tree(BTHead, *LLHead);

	return BTHead;
}

BTNode *addNode2Tree(BTNode *head, LLNode data)
{
	if (head == NULL || head->value == 0)
	{
		head = (BTNode *)malloc(sizeof(BTNode));
		head->identity = data.identity;
		head->value = data.value;
	}
	else if (head->value > data.value)

		head->left = addNode2Tree(head->left, data);

	else
		head->right = addNode2Tree(head->right, data);

	return head;
}

void sortTheLL(LLNode *head)
{
	int val, id;
	LLNode *ptr1 = head;
	while (ptr1 != NULL)
	{
		LLNode *ptr2 = head;
		while (ptr2 != NULL)
		{
			if (ptr1->value < ptr2->value)
			{
				val = ptr1->value;
				id = ptr1->identity;
				ptr1->value = ptr2->value;
				ptr1->identity = ptr2->identity;
				ptr2->value = val;
				ptr2->identity = id;
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

void printLLNode(LLNode *head)
{
	LLNode *ptr = head;
	while (ptr != NULL)
	{
		totalNode++;
		printf("%d %d\n", ptr->identity, ptr->value);
		ptr = ptr->next;
	}
}

void printBT(BTNode *BTComing, int activeHeight, int leftIs, int rootData)
{
	if (activeHeight > realBTHeight(BTComing))
		return;
	if (BTComing == NULL)
		return;
	else if (activeHeight == 1)
	{
		printf("%d %d ", BTComing->identity, BTComing->value);
		if (leftIs == 1 && rootData != -1)
			printf("(%d %s) ", rootData, "L");
		else if (rootData != -1)
			printf("(%d %s) ", rootData, "R");
	}
	else
	{
		printBT(BTComing->left, activeHeight - 1, 1, BTComing->value);
		printBT(BTComing->right, activeHeight - 1, 0, BTComing->value);
	}
}

int realBTHeight(BTNode *masterHead)
{
	BTNode *BTPtr = masterHead;
	if (BTPtr == NULL)
	{
		return 0;
	}
	else
	{
		int leftHeight = realBTHeight(BTPtr->left);
		int rightHeight = realBTHeight(BTPtr->right);

		if (leftHeight > rightHeight)
			return leftHeight + 1;
		else
			return rightHeight + 1;
	}
}