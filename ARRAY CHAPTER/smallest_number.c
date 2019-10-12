#include <stdio.h>

int main()
{
    int arraySize, position = 0;
    printf("Please enter numner of the elements: ");
    scanf("%d", &arraySize);
    int theArray[arraySize];
    printf("The Elements: ");
    for (size_t i = 0; i < arraySize; i++)
    {
        scanf("%d", &theArray[i]);
    }
    int smallest = theArray[0];
    for (size_t i = 0; i < arraySize; i++)
    {
        if (smallest > theArray[i])
        {
            smallest = theArray[i];
            position = i;
        }
    }
    printf("The smallest element is: %d\nThe index is: %d\n", smallest, position);
}