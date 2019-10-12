#include <stdio.h>

void arrayPrint(int *arr)
{
    for (size_t i = 0; arr[i] != 0; i++)
        printf("%d\n", arr[i]);
}

int main()
{
    int theArray[10] = {0}, theValue;
    printf("Please enter 5 digit into the array: ");
    for (int i = 0; i < 5; i++)
        scanf("%d", &theArray[i]);
    arrayPrint(theArray);
    printf("Please enter the value which is inserting the end of the array: ");
    scanf("%d", &theValue);
    for (size_t i = 0;; i++)
    {
        if (theArray[i] == 0)
        {
            theArray[i] = theValue;
            break;
        }
    }
    arrayPrint(theArray);
}