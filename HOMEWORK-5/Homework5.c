/*
*  ____________________________________
* |         Comiler: GCC 7.4.0        |
* |     Enviroment: Ubuntu 18.04.1    |
* |                                   |
* |    SERKAN                UYSAL    |
* |      uysalserkan08@gmail.com      |
* |___________________________________|
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
// TODO | The commentline function will make correct.

/*
 ? Binary level = ((2^(n+1))-1) <= Total Entry < ((2^n)-1)
 ? n = Binary level.
 ? Take the data as linkedlist with sorted.
*/
int nodeSize = 0;

struct node
{
    struct node *left;
    struct node *right;
    int value;
    int identity;
};

struct linkedListNode
{
    int value;
    int identity;
    struct linkedListNode *next;
};

struct binary_tree
{
    struct node *root;
};

typedef struct binary_tree BinaryTree;
typedef struct node Node;
typedef struct linkedListNode LLNode;

// LLNode *takeDataWithLinkedList(LLNode *head);
LLNode *takeDataUnsortedLL(LLNode *head);
void sortTheLL(LLNode *head);
BinaryTree *createBTree(LLNode *head);
void printLLNode(LLNode *head);
int binaryTreeHeight(int BTSize);

int main()
{
    LLNode *head;
    BinaryTree *BTHead;
    // head = (LLNode *)malloc(sizeof(LLNode));
    head = takeDataUnsortedLL(head);
    sortTheLL(head);
    // head = takeDataWithLinkedList(head);
    printLLNode(head);
    printf("Nodesize: %d BinaryHeight: %d\n", nodeSize, binaryTreeHeight(nodeSize));
    // BTHead = createBTree(head);
}
/*
// !Error (Segmentation fault)
LLNode *takeDataWithLinkedList(LLNode *head)
{
    int usr_id, usr_val;
    LLNode *main = (LLNode *)malloc(sizeof(LLNode));
    main->identity = usr_id;
    main->value = usr_val;
    head = main;
    scanf("%d %d", &usr_id, &usr_val);
    while (usr_id != -1 && usr_val != -1)
    {
        LLNode *ptr = head;
        LLNode *ptr_prev = (LLNode *)malloc(sizeof(LLNode));
        LLNode *body = (LLNode *)malloc(sizeof(LLNode));
        body->value = usr_val;
        body->identity = usr_id;

        if (usr_val > ptr->value)
        {
            while (ptr->value < usr_val)
            {
                ptr_prev = ptr;
                ptr = ptr->next;
                printf("\nsa");
            }
            ptr_prev->next = body;
            body->next = ptr;
        }
        else
        {
            body->next = main;
            main = body;
        }
        // ? value yi alacak eğer değer ptr'ın tuttuğu değerden küçükse ptr_prev ve ptr arasına yerleştirecek.
        scanf("%d %d", &usr_id, &usr_val);
    }
    return head;
}
*/

// *Works correct.
LLNode *takeDataUnsortedLL(LLNode *head)
{
    int usr_id, usr_val;
    scanf("%d %d", &usr_id, &usr_val);
    LLNode *main = (LLNode *)malloc(sizeof(LLNode));
    main->identity = usr_id;
    main->value = usr_val;
    head = main;
    scanf("%d %d", &usr_id, &usr_val);
    while (usr_id != -1 && usr_val != -1)
    {
        LLNode *body = (LLNode *)malloc(sizeof(LLNode));
        body->identity = usr_id;
        body->value = usr_val;
        main->next = body;
        main = main->next;
        scanf("%d %d", &usr_id, &usr_val);
    }
    return head;
}

// *Works correct.
void printLLNode(LLNode *head)
{
    LLNode *ptr = head;
    while (ptr != NULL)
    {
        nodeSize++;
        printf("%d %d\n", ptr->identity, ptr->value);
        ptr = ptr->next;
    }
}
// *Works correct.
int binaryTreeHeight(int BTSize)
{
    int n = 0;
    while (pow(2, n)-1 < BTSize)
        n++;
    return n;
}

//* Works correnct
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

BinaryTree *createBTree(LLNode *head)
{
    BinaryTree *masterNode = (BinaryTree *)malloc(sizeof(BinaryTree));

    LLNode BTArray[nodeSize];
    for (size_t i = 0; i < nodeSize; i++)
    {
        BTArray[i] = *head;
        head = head->next;
    }

    return masterNode;
}