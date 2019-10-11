/*
*  ____________________________________
* |			Comiler: GCC 7.4.0        |
* |		Enviroment: Ubuntu 18.04.1    |
* | Before versionns can find multiple|
* | words in the pattern but this not.|
* |___________________________________|
*/


#include <stdio.h>
#include <stdbool.h>
#define THESIZE 15

//Global Changeable Variables
int horizontalStartIndexRow;
int horizontalStartIndexColumn;
int verticalStartIndexRow;
int verticalStartIndexColumn;

//Prototypes Of The Functions
int theSize(char *incoming);
void printHorizontal(char theArray[THESIZE][THESIZE], int size);
bool findedHorizontal(char theArray[THESIZE][THESIZE], char *coming);

void printVertical(char theArray[THESIZE][THESIZE], int size);
bool findedVertical(char theArray[THESIZE][THESIZE], char *coming);

//The Main Function
int main()
{
	char ARRAY[THESIZE][THESIZE] = {
		{'G', 'S', 'L', 'N', 'F', 'R', 'N', 'P', 'R', 'E', 'N', 'D', 'P', 'O', 'R'},
		{'N', 'A', 'N', 'F', 'D', 'K', 'U', 'O', 'L', 'M', 'K', 'I', 'A', 'C', 'N'},
		{'I', 'F', 'V', 'A', 'C', 'S', 'F', 'P', 'T', 'A', 'A', 'S', 'R', 'O', 'H'},
		{'L', 'E', 'P', 'I', 'I', 'S', 'I', 'N', 'R', 'S', 'T', 'N', 'T', 'A', 'A'},
		{'I', 'S', 'R', 'L', 'I', 'R', 'L', 'N', 'M', 'I', 'Y', 'I', 'D', 'Y', 'D'},
		{'A', 'B', 'T', 'L', 'A', 'I', 'D', 'G', 'S', 'O', 'S', 'R', 'T', 'E', 'R'},
		{'W', 'U', 'E', 'N', 'G', 'T', 'N', 'A', 'F', 'I', 'S', 'I', 'D', 'G', 'R'},
		{'G', 'N', 'A', 'H', 'E', 'I', 'N', 'S', 'H', 'S', 'V', 'S', 'M', 'O', 'O'},
		{'C', 'H', 'T', 'O', 'N', 'V', 'I', 'E', 'C', 'A', 'P', 'S', 'S', 'T', 'B'},
		{'L', 'O', 'A', 'I', 'U', 'B', 'R', 'A', 'C', 'K', 'E', 'T', 'E', 'O', 'R'},
		{'W', 'I', 'A', 'D', 'E', 'T', 'N', 'U', 'O', 'M', 'R', 'R', 'L', 'T', 'O'},
		{'R', 'T', 'G', 'E', 'R', 'M', 'S', 'E', 'U', 'E', 'I', 'E', 'I', 'H', 'W'},
		{'E', 'F', 'S', 'H', 'A', 'D', 'R', 'I', 'E', 'F', 'E', 'P', 'T', 'E', 'N'},
		{'A', 'S', 'W', 'I', 'T', 'C', 'H', 'T', 'D', 'P', 'L', 'A', 'Q', 'U', 'E'},
		{'D', 'N', 'E', 'R', 'G', 'S', 'H', 'E', 'L', 'E', 'S', 'P', 'A', 'C', 'N'},
	};

	char input[THESIZE];
	scanf("%s", input);

	if (findedHorizontal(ARRAY, input))
	{
		printHorizontal(ARRAY, theSize(input));
	}
	else if (findedVertical(ARRAY, input))
	{
		printVertical(ARRAY, theSize(input));
	}
}

//Perfect Function
int theSize(char *incoming)
{
	int size;
	while (incoming[size] != '\0')
		size++;

	return size;
}

void printHorizontal(char theArray[THESIZE][THESIZE], int size)
{
	for (size_t i = 0; i < THESIZE; i++)
	{
		for (size_t j = 0; j < THESIZE; j++)
		{
			if (i == horizontalStartIndexRow && j >= horizontalStartIndexColumn && j < horizontalStartIndexColumn + size )
			{
				printf("%c", theArray[i][j]);
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
}

bool findedHorizontal(char theArray[THESIZE][THESIZE], char *coming)
{
	int lenght = theSize(coming);
	for (size_t i = 0; i < THESIZE; i++)
	{
		for (size_t j = 0; j < THESIZE; j++)
		{
			if (theArray[i][j] == coming[0])
			{
				int theRepeater = 0;
				for (size_t s = 0; s < lenght; s++)
				{
					if (theArray[i][j + s] == coming[s])
					{
						theRepeater++;
					}
					if (theRepeater == lenght)
					{
						horizontalStartIndexRow = i;
						horizontalStartIndexColumn = j;
						return true;
					}
				}
			}
		}
	}
	return false;
}

void printVertical(char theArray[THESIZE][THESIZE], int size)
{
	for (size_t i = 0; i < THESIZE; i++)
	{
		for (size_t j = 0; j < THESIZE; j++)
		{
			if (j == verticalStartIndexColumn && i >= verticalStartIndexRow && i < verticalStartIndexRow + size)
			{
				printf("%c", theArray[i][j]);
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
}
bool findedVertical(char theArray[THESIZE][THESIZE], char *coming)
{
	int length = theSize(coming);
	for (size_t i = 0; i < THESIZE; i++)
	{
		for (size_t j = 0; j < THESIZE; j++)
		{
			if (theArray[i][j] == coming[0])
			{
				int theRepeater = 0;
				for (size_t s = 0; s < length; s++)
				{
					if (theArray[i + s][j] == coming[s])
					{
						theRepeater++;
					}
					if (theRepeater == length)
					{
						verticalStartIndexRow = i;
						verticalStartIndexColumn = j;
						return true;
					}
				}
			}
		}
	}
	return false;
}