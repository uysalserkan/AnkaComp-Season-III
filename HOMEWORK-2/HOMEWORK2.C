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

struct nodeClass
{
    int classID;
    int studentNumber;
    double classMidtermAverage;
    struct nodeClass *next;
    struct nodeStudent *studentPtr;
};

struct nodeStudent
{
    int studentID;
    int midterm;
    struct nodeStudent *next;
};

typedef struct nodeClass strctClass;
typedef struct nodeStudent strctStudent;

void createClasses(strctClass *head);
void printClasses(strctClass *head);
void addStudentToClass(strctStudent *head, int stID, int stMidterm);
void takeStudents(strctClass *head);
void sortStudentMidterms(strctClass *head);
void printStudentInfo(strctClass *head);
int getMinStudentClass(strctClass *head);
double getClassAveradge(strctStudent *head, int stNumber);

int main()
{
    strctClass *head;
    head = (strctClass *)malloc(sizeof(strctClass));
    createClasses(head);
    // Created class..

    takeStudents(head);
    int minStudent = getMinStudentClass(head);
    while (head->next != NULL)
    {
        sortStudentMidterms(head);
        double av = getClassAveradge(head->studentPtr, minStudent);
        printf("%d %.1f\n", head->classID, av);
        printStudentInfo(head);
        head = head->next;
    }
}

/*
*[Midterm scores sorting] [DONE]
*[Take average of the midterm scores] && [Don't take lower scores untill the class student equal each other..]
*[PrintStudent'e direkt class pointeri gönderip class'ın hangi class olduğunu da görebiliriz.] [DONE]
*        [Print] [DONE]
* ClassID AveradgeMidtermScore
* StudentID MidtermScore
* StudentID MidtermScore
* StudentID MidtermScore
*/

void createClasses(strctClass *head)
{

    strctClass *ptr, *body;
    int i = 0;
    while (i < 4)
    {
        /*
        *Bunun sayesinde body değişkeni her defasında farklı address alıyor.
        *Yani oluşturulan her body bir öncekinde farklı bir body oluyor. 
        */

        body = (strctClass *)malloc(sizeof(strctClass));
        if (head->next == NULL)
        {
            strctStudent *temp;
            temp = (strctStudent *)malloc(sizeof(strctStudent));
            head->classID = i + 1;
            head->next = body;
            head->studentPtr = temp;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            strctStudent *temp;
            temp = (strctStudent *)malloc(sizeof(strctStudent));
            ptr->next = body;
            ptr->studentPtr = temp;
            ptr->classID = i + 1;
        }
        i++;
    }
}

void addStudentToClass(strctStudent *head, int stID, int stMidterm)
{
    strctStudent *ptr, *body;
    body = (strctStudent *)malloc(sizeof(strctStudent));

    if (head->next == NULL)
    {
        head->midterm = stMidterm;
        head->studentID = stID;
        head->next = body;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = body;
        ptr->midterm = stMidterm;
        ptr->studentID = stID;
    }
}

void printClasses(strctClass *head)
{
    /*
    * ptr değişkeni sayesinde head'ın tuttulu adres üzerinden geçerek 
    * değişkenleri sıralı bir şekilde bastırıyoruz..
    */
    strctClass *ptr;
    ptr = head;
    while (ptr->next != NULL)
    {
        printf("%d\n", ptr->classID);
        ptr = ptr->next;
    }
}

void takeStudents(strctClass *head)
{
    //If the stID equals -1 then break the iteration.
    int stID;
    int stMidterm;

    while (1)
    {
        scanf("%d", &stID);
        if (stID == -1)
            break;
        scanf("%d", &stMidterm);
        strctClass *ptr = head;
        switch (stID / 10000)
        {
        case 6:
            addStudentToClass(ptr->studentPtr, stID, stMidterm);
            ptr->studentNumber++;
            break;

        case 7:
            ptr = ptr->next;
            addStudentToClass(ptr->studentPtr, stID, stMidterm);
            ptr->studentNumber++;
            break;

        case 8:
            ptr = ptr->next->next;
            addStudentToClass(ptr->studentPtr, stID, stMidterm);
            ptr->studentNumber++;
            break;

        case 9:
            ptr = ptr->next->next->next;
            addStudentToClass(ptr->studentPtr, stID, stMidterm);
            ptr->studentNumber++;
            break;
        }
    }
}
void printStudentInfo(strctClass *head)
{
    strctStudent *ptr = head->studentPtr;
    // printf("\n\nThe Class is: %d\t\tTOTAL STUDENT: %d\n", head->classID, head->studentNumber);
    while (ptr->next != NULL)
    {
        printf("%d   %d\n", ptr->studentID, ptr->midterm);
        ptr = ptr->next;
    }
}

void sortStudentMidterms(strctClass *head)
{
    strctStudent *theRealptr = head->studentPtr;
    while (theRealptr->next != NULL)
    {
        strctStudent *ptr = theRealptr;
        while (ptr->next != NULL)
        {
            // strctStudent *highest = ptr;

            if (theRealptr->midterm < ptr->midterm)
            {
                //Blok değiştirmek yerine id ve midtermleri değiştirmek???
                int idtemp1 = ptr->studentID;
                int mditemp1 = ptr->midterm;
                ptr->midterm = theRealptr->midterm;
                ptr->studentID = theRealptr->studentID;
                theRealptr->studentID = idtemp1;
                theRealptr->midterm = mditemp1;
            }
            ptr = ptr->next;
        }
        theRealptr = theRealptr->next;
    }
}

int getMinStudentClass(strctClass *head)
{
    int minSt = head->studentNumber;
    strctClass *ptr = head->next;
    for (int i = 0; i < 3; i++)
    {
        if (ptr->studentNumber < minSt)
        {
            minSt = ptr->studentNumber;
        }
        ptr = ptr->next;
    }
    return minSt;
}

double getClassAveradge(strctStudent *head, int stNumber)
{
    strctStudent *ptr = head;
    double total = 0;
    for (int i = 0; i < stNumber; i++)
    {
        total += head->midterm;
        head = head->next;
    }
    return total / stNumber;
}