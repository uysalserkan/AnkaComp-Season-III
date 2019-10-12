#include <stdio.h>

void arrayPrint(int *arr)
{
    for (size_t i = 0; arr[i] != -1; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void secondMergeFirst(int *firstArray, int const secondArray[])
{
    int secondSize = 0, firstSize = 0;
    while (secondArray[secondSize] != -1)
        secondSize++;
    while (firstArray[firstSize] != -1)
        firstSize++;
    for (int i = firstSize; i < firstSize + secondSize; i++)
    {
        firstArray[i] = secondArray[i - firstSize];
    }
    firstArray[firstSize + secondSize] = -1;
}

int main()
{
    // end of the array is -1;
    int theFirstArr[15] = {21, 53, 28, 41, 99, 81, -1};
    int theSecondArr[15] = {254, 793, 982, 165, 783, -1};
    printf("first array: ");
    arrayPrint(theFirstArr);
    printf("second array: ");
    arrayPrint(theSecondArr);
    secondMergeFirst(theFirstArr, theSecondArr);
    printf("after merging first array: ");
    arrayPrint(theFirstArr);
}