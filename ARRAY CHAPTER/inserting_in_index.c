#include <stdio.h>
void printArray(int *arr)
{
    for (size_t i = 0; arr[i] != -1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int theArray[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int theValue, theIndex;
    printf("Please enter 5 digit into the array: ");
    for (int i = 0; i < 5; i++)
        scanf("%d", &theArray[i]);
    printArray(theArray);
    printf("Please enter the index of the value( between 1-5 ): ");
    scanf("%d", &theIndex);
    printf("Please enter the value which is inserting the end of the array: ");
    scanf("%d", &theValue);
    // The Inserting...
    for (int i = 5; i > theIndex; i--)
    {
        theArray[i] = theArray[i - 1];
    }
    theArray[theIndex] = theValue;
    printArray(theArray);
}