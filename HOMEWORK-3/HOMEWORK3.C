/*
*  ____________________________________
* |         Comiler: GCC 7.4.0        |
* |     Enviroment: Ubuntu 18.04.1    |
* | Before versionns can find multiple|
* | words in the pattern but this not.|
* |___________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
*Struct definations
*/
struct nodeFB
{
    int id;
    int age;
    struct nodeFB *next;
};

struct nodeGS
{
    int id;
    struct nodeGS *next;
};
struct mergedStructs
{
    int id;
    int age;
    struct mergedStructs *next;
};

/*
* typedef statements.
*/
typedef struct nodeFB FBNODE;
typedef struct nodeGS GSNODE;
typedef struct mergedStructs MERGE;

/*
 * Functions Prototypes
*/

void takeFBtickets(FBNODE *head);
void takeGStickets(GSNODE *head);
void sortFBTickets(FBNODE *head);
void sortGSTickets(GSNODE *head);
void printFBTickets(FBNODE *head);
void printGSTickets(GSNODE *head);
int structSize(GSNODE *gsNode, FBNODE *fbNode);
void mergeIt(MERGE *head, FBNODE *fbHead, GSNODE *gsHead);
void mergePrint(MERGE *head);

int main()
{
    MERGE *mergeHead;
    mergeHead = (MERGE *)malloc(sizeof(MERGE));
    FBNODE *fbhead;
    fbhead = (FBNODE *)malloc(sizeof(FBNODE));
    GSNODE *gshead;
    gshead = (GSNODE *)malloc(sizeof(GSNODE));
    takeFBtickets(fbhead);
    takeGStickets(gshead);
    printFBTickets(fbhead);
    printf("\n");
    printGSTickets(gshead);
    mergeIt(mergeHead, fbhead, gshead);
    printf("\n");
    mergePrint(mergeHead);
}

void takeFBtickets(FBNODE *head)
{
    int usr_id = 0;
    int usr_age = 0;
    FBNODE *ptr = head;
    FBNODE *body;

    scanf("%d %d", &usr_id, &usr_age);
    while ((usr_id != -1) && (usr_age != -1))
    {
        body = (FBNODE *)malloc(sizeof(FBNODE));
        if (ptr->next == NULL)
        {
            ptr->age = usr_age;
            ptr->id = usr_id;
            ptr->next = body;
        }
        else
        {
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->age = usr_age;
            ptr->id = usr_id;
            ptr->next = body;
        }
        scanf("%d %d", &usr_id, &usr_age);
    }
    sortFBTickets(head);
}
void takeGStickets(GSNODE *head)
{
    int usr_id = 0;
    GSNODE *ptr = head;
    GSNODE *body;
    scanf("%d", &usr_id);
    while (usr_id != -1)
    {
        body = (GSNODE *)malloc(sizeof(GSNODE));
        if (ptr->next == NULL)
        {
            ptr->id = usr_id;
            ptr->next = body;
        }
        else
        {
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->id = usr_id;
            ptr->next = body;
        }
        scanf("%d", &usr_id);
    }
    sortGSTickets(head);
}
void sortFBTickets(FBNODE *head)
{
    FBNODE *ptr1 = head;
    for (; ptr1->next != NULL; ptr1 = ptr1->next)
    {
        FBNODE *ptr2 = head;
        for (; ptr2->next != NULL; ptr2 = ptr2->next)
        {
            if (ptr1->id < ptr2->id)
            {
                int temp_id;
                int temp_age;
                temp_id = ptr1->id;
                temp_age = ptr1->age;
                // printf("Now id: %d\nNow age: %d\n", temp_id, temp_age);
                ptr1->id = ptr2->id;
                ptr1->age = ptr2->age;
                ptr2->id = temp_id;
                ptr2->age = temp_age;
            }
        }
    }
}
void sortGSTickets(GSNODE *head)
{
    int temp_id;
    GSNODE *ptr1 = head;
    for (; ptr1->next != NULL;)
    {
        GSNODE *ptr2 = head;
        for (; ptr2->next != NULL;)
        {
            if (ptr2->id < ptr2->next->id)
            {
                temp_id = ptr2->id;
                ptr2->id = ptr2->next->id;
                ptr2->next->id = temp_id;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
void printFBTickets(FBNODE *head)
{
    FBNODE *ptr = head;
    while (ptr->next != NULL)
    {
        printf("Id:%d\tAge:%d\n", ptr->id, ptr->age);
        ptr = ptr->next;
    }
}
void printGSTickets(GSNODE *head)
{
    GSNODE *ptr = head;
    while (ptr->next != NULL)
    {
        printf("Id:%d\n", ptr->id);
        ptr = ptr->next;
    }
}

int structSize(GSNODE *gsNode, FBNODE *fbNode)
{
    int size = 0;
    if (gsNode != NULL)
    {
        GSNODE *ptr = gsNode;
        while (ptr->next != NULL)
        {
            size++;
            ptr = ptr->next;
        }
        return size;
    }
    if (fbNode != NULL)
    {
        FBNODE *ptr = fbNode;
        while (ptr->next != NULL)
        {
            size++;
            ptr = ptr->next;
        }
        return size;
    }
}

void mergeIt(MERGE *head, FBNODE *fbHead, GSNODE *gsHead)
{
    int fbSize = structSize(NULL, fbHead);
    int gsSize = structSize(gsHead, NULL);
    FBNODE *ptrFB = fbHead;
    GSNODE *ptrGS = gsHead;
    bool lastGS = true;
    MERGE *body;
    MERGE *ptr = head;
    //First fb after gs repeat it untill finite..
    //Equal size, FB MOST, GS MOST..

    //EQUAL
    if (fbSize == gsSize)
    {
        for (; ptrGS->next != NULL; ptr = ptr->next)
        {
            if (lastGS == true)
            {
                body = (MERGE *)malloc(sizeof(MERGE));
                lastGS = false;
                ptr->age = ptrFB->age;
                ptr->id = ptrFB->id;
                ptrFB = ptrFB->next;
                ptr->next = body;
                continue;
            }
            else if (lastGS == false)
            {
                body = (MERGE *)malloc(sizeof(MERGE));
                lastGS = true;
                ptr->age = 0;
                ptr->id = ptrGS->id;
                ptrGS = ptrGS->next;
                ptr->next = body;
                continue;
            }
        }
    }
    //FB MOST
    if (fbSize > gsSize)
    {
        //[WILL BE HERE]
    }
    //GS MOST
    if (gsSize > fbSize)
    {
        //[WILL BE HERE]
    }
}

void mergePrint(MERGE *head)
{
    MERGE *ptr = head;
    while (ptr->next != NULL)
    {
        if (ptr->age == 0)
            printf("Id:%d\n", ptr->id);
        else if (ptr->age != 0)
            printf("Id:%d\tAge:%d\n", ptr->id, ptr->age);
        ptr = ptr->next;
    }
}

/*
 * Fenerbahce and Galatasaray fans are in separate 
 * lines to get tickets. For each group of fans, 
 * get the related information (id and age for 
 * FB fans, id for GS fans) from the user and 
 * create the following link lists. FB fans will 
 * be inserted to link list in increasing order of 
 * ids, GS fans in decreasing order. The number of 
 * fans in both link lists will be the same. The node 
 * structures to be used in the link list are given below. 
 * Then merge these two link lists so that the fans of FB 
 * and GS will be in the same link list as shown in the figure. 
 * Make the necessary changes to the given node structures when 
 * you are doing this placement. Write three print methods, 
 * void printFB(struct nodeFB *), void printGS(struct nodeGS *), 
 * void printAll(struct nodeFB *)  that prints FB link list, 
 * GS link list and the merged link list respectively.
*/

/*
*[the inputs]
456756   45
561232   41
821273   20
193215   25
882342   37
-1   -1
872456
272487
345123
892185
764523
-1
*/

/*
*[RESULT]
Id:193215	Age:25
Id:456756	Age:45
Id:561232	Age:41
Id:821273	Age:20
Id:882342	Age:37

Id:892185
Id:872456
Id:764523
Id:345123
Id:272487

Id:193215	Age:25
Id:892185
Id:456756	Age:45
Id:872456
Id:561232	Age:41
Id:764523
Id:821273	Age:20
Id:345123
Id:882342	Age:37
Id:272487
*/

/*
* //TODO
* END
*/