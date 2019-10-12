#include <stdio.h>

void arrayPrint(int *arr)
{
    for (size_t i = 0; arr[i] != 0; i++)
        printf("%d\n", arr[i]);
}

int main()
{
    int theArray[10] = {1, 2, 3, 4, 5, 6, 7, 8};
    int usr_index;
    arrayPrint(theArray);
    printf("Please enter the index of the value: ");
    scanf("%d", &usr_index);
    for (usr_index; theArray[usr_index + 1] != 0; usr_index++)
    {
        theArray[usr_index] = theArray[usr_index + 1];
    }
    theArray[usr_index] = 0;
    arrayPrint(theArray);
}