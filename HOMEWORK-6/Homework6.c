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

struct node
{
   int data;
   struct node *next;
};

struct binaryTree
{
   int data;
   struct binaryTree *left;
   struct binaryTree *right;
};

typedef struct binaryTree BTree;
typedef struct node Node;

void TakeDataInNode(Node **head);
int TreeHeight(BTree *head);
int AVLHeight(BTree *head);
void printInorderNotation(BTree *head);
BTree *InsertBTree(BTree *head, int data);
BTree *LLNotation(BTree *head);
BTree *RRNotation(BTree *head);
BTree *InsertData(BTree *head, int data);
void printBT(BTree *BTComing, int activeHeight, int leftIs, int rootData);

int main()
{
   BTree *BTreeHead = (BTree *)malloc(sizeof(BTree));
   Node *nodeHead = (Node *)malloc(sizeof(Node));
   TakeDataInNode(&nodeHead);
   while (nodeHead->next != NULL)
   {
      BTreeHead = InsertBTree(BTreeHead, nodeHead->data);
      nodeHead = nodeHead->next;
   }

   printInorderNotation(BTreeHead);
   printBT(BTreeHead, 1, -1, -1);
   printf("\n");
   printBT(BTreeHead, 2, -1, -1);
   printf("\n");
   printBT(BTreeHead, 3, -1, -1);
   printf("\n");
   printBT(BTreeHead, 4, -1, -1);
   printf("\n");
}

void TakeDataInNode(Node **head)
{
   Node *firstNodeAdress = *head;
   int data;
   scanf("%d", &data);
   while (data != -1)
   {
      (*head)->data = data;
      (*head)->next = (Node *)malloc(sizeof(Node));
      *head = (*head)->next;
      scanf("%d", &data);
   }
   *head = firstNodeAdress;
}

int TreeHeight(BTree *head)
{
   BTree *BTPtr = head;
   if (BTPtr == NULL)
   {
      return 0;
   }
   else
   {
      int leftHeight = TreeHeight(BTPtr->left);
      int rightHeight = TreeHeight(BTPtr->right);

      if (leftHeight > rightHeight)
         return leftHeight + 1;
      else
         return rightHeight + 1;
   }
}

int AVLHeight(BTree *head)
{
   if (head == NULL)
   {
      return 0;
   }
   return (TreeHeight(head->left) - TreeHeight(head->right));
}

void printInorderNotation(BTree *head)
{
   if (head->left != NULL)
      printInorderNotation(head->left);
   if (head->right != NULL)
      printInorderNotation(head->right);
}

BTree *InsertBTree(BTree *head, int data)
{
   if (head == NULL)
   {
      head = (BTree *)malloc(sizeof(BTree));
      head->data = data;
      return head;
   }
   else
   {
      if (head->data == 0)
      {
         head = (BTree *)malloc(sizeof(BTree));
         head->data = data;
         return head;
      }
      if (head->data > data)
         head->left = InsertBTree(head->left, data);
      else if (head->data < data)
         head->right = InsertBTree(head->right, data);
      else
         return head;
   }
   int activeNodeHeightBalance = AVLHeight(head);

   if (activeNodeHeightBalance > 1 && (head->left->data > data))
   {
      return RRNotation(head);
   }
   if (activeNodeHeightBalance < -1 && head->right->data < data)
   {
      return LLNotation(head);
   }
   if (activeNodeHeightBalance > 1 && head->left->data < data)
   {
      head->left = LLNotation(head->left);
      return RRNotation(head);
   }
   if (activeNodeHeightBalance < -1 && head->right->data > data)
   {
      head->right = RRNotation(head->right);
      return LLNotation(head);
   }

   return head;
}

BTree *LLNotation(BTree *head)
{
   BTree *BTmain = head->right;
   BTree *bePushed = BTmain->left;

   BTmain->left = head;
   head->right = bePushed;

   return BTmain;
}
BTree *RRNotation(BTree *head)
{
   BTree *BTmain = head->left;
   BTree *bePushed = head->right;

   BTmain->right = head;
   head->left = bePushed;

   return BTmain;
}

void printBT(BTree *BTComing, int activeHeight, int leftIs, int rootData)
{
   if (activeHeight > TreeHeight(BTComing))
      return;
   if (BTComing == NULL)
      return;
   else if (activeHeight == 1)
   {
      printf("%d", BTComing->data);
      if (leftIs == 1 && rootData != -1)
         printf(" (%d %s)", rootData, "L");
      else if (rootData != -1)
         printf(" (%d %s)", rootData, "R");
      printf(" (%d B) ", AVLHeight(BTComing));
   }
   else
   {
      printBT(BTComing->left, activeHeight - 1, 1, BTComing->data);
      printBT(BTComing->right, activeHeight - 1, 0, BTComing->data);
   }
}
