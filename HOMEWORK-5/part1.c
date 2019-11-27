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
#include <math.h>

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
// BTNode *createBTree(LLNode *head, int treeSize);
// void printLLNode(LLNode *head);
// int BTNodeHeight(int BTSize);

int main()
{
	LLNode *LLhead = (LLNode *)malloc(sizeof(LLNode));
	LLhead = takeDataUnsortedLL(LLhead);
	BTNode *master = (BTNode *)malloc(sizeof(BTNode));
	master = GiveTheTree(master, LLhead);
	// printf("%d-%d-%d\n", master->value, master->left->value, master->right->value);
	sortTheLL(LLhead);
	printLLNode(LLhead);
	printf("\n");
	int masterHeight = btHeight(totalNode);
	// printf("Total Node: %d\nHeight is: %d\n", totalNode, masterHeight);
	// printf(
	// 	"Root: %d %d\tLeft: %d %d\tRight: %d %d\n",
	// 	master->value, master->identity, master->left->value, master->left->identity, master->right->value, master->right->identity);

	// for (int i = 1;; i++)
	// {
	// 	printBT(master, i, false, -1);
	// 	printf("\n");
	// }
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
	// while (i < 2)
	// {
	// 	printBT(master, 1);
	// 	// printf("%d-%d\n", master->identity, master->value);
	// 	i++;
	// }
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
	// BTNode *masterNode = (BTNode *)malloc(sizeof(BTNode));
	// BTHead->left = (BTNode *)malloc(sizeof(BTNode));
	// BTHead->right = (BTNode *)malloc(sizeof(BTNode));
	// printf("now value is: %d\n", BTHead->value);
	for (; LLHead != NULL; LLHead = LLHead->next)
	{
		// BTNode *ptr = BTHead;
		// if (BTHead->value == 0)
		// {
		// 	BTHead = (BTNode *)malloc(sizeof(BTNode));
		// 	BTHead->identity = LLHead->identity;
		// 	BTHead->value = LLHead->value;
		// 	// // LLHead = LLHead->next;
		// 	// continue;
		// }
		BTHead = addNode2Tree(BTHead, *LLHead);
		// while (ptr->left != NULL && ptr->right == NULL)
		// {
		// 	if (ptr->value > LLHead->value)
		// 		ptr = ptr->left;
		// 	else
		// 		ptr = ptr->right;
		// }

		// if (BTHead->value > LLHead->value)
		// {
		// 	BTHead->left = addNode2Tree(BTHead->left, *LLHead);
		// 	printf("small datas val: %d\n", BTHead->left->value);
		// }
		// else
		// {
		// 	BTHead->right = addNode2Tree(BTHead->right, *LLHead);
		// 	printf("big datas val: %d\n", BTHead->right->value);
		// }
	}
	// printf("Main Value is %d\n", masterNode->value);
	// if (LLHead->next->value < masterNode->value && LLHead->next != NULL)
	// {
	// 	printf("\nLeft: ");
	// 	masterNode->left = (BTNode *)malloc(sizeof(BTNode));
	// 	masterNode->left = GiveTheTree(masterNode->left, LLHead->next);
	// }
	// if (LLHead->next->value > masterNode->value && LLHead->next != NULL)
	// {
	// 	printf("\nRigth: ");
	// 	masterNode->right = (BTNode *)malloc(sizeof(BTNode));
	// 	masterNode->right = GiveTheTree(masterNode->right, LLHead->next);
	// }
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

int btHeight(int size)
{
	// for (int n = 0;; n++)
	// 	if (size <= (int)pow(2, n))
	// 		return n;
	if(size<=2)
	return 1;
	if(size>2 && size<=4)
	return 2;
	if(size>4 && size<=8)
	return 3;
	if(size>8 && size<=16)
	return 4;
	if(size>16 && size<=32)
	return 5;
	if(size>32 && size<=64)
	return 6;
	if(size>64 && size<=128)
	return 7;
	if(size>128 && size<=256)
	return 8;

	return 0;
}

void printBT(BTNode *BTHead, int activeHeight, int leftIs, int rootData)
{
	if (activeHeight > btHeight(totalNode))
		return;
	if (BTHead == NULL)
		return;
	else if (activeHeight == 1)
	{
		printf("%d %d ", BTHead->identity, BTHead->value);
		if (leftIs == 1 && rootData != -1)
			printf("(%d %s) ", rootData, leftIs == 1 ? "L" : "R");
		else if (rootData != -1)
			printf("(%d %s) ", rootData, leftIs == 1 ? "L" : "R");
	}
	else
	{
		printBT(BTHead->left, activeHeight - 1, 1, BTHead->value);
		printBT(BTHead->right, activeHeight - 1, 0, BTHead->value);
	}
}