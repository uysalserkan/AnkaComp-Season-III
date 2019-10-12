#include <stdio.h>
#include <math.h>

int main()
{
    int theSize = 0, theNumber = 0;
    printf("Please enter the number of digit: ");
    scanf("%d", &theSize);
    int theArray[theSize];
    for (int i = 0; i < theSize; i++)
    {
        scanf("%d", &theArray[i]);
        printf("The %d. position is: %d\n", i + 1, theArray[i]);
    }
    for (size_t i = 0; i < theSize; i++)
    {
        theNumber += theArray[i] * pow(10, i);
    }
    printf("The number1 is: %d\n", theNumber);
    theNumber = 0;
    for (int i = theSize - 1; i >= 0; i--)
    {
        theNumber += theArray[i] * pow(10, theSize - i - 1);
    }
    printf("The number2 is: %d\n", theNumber);
}