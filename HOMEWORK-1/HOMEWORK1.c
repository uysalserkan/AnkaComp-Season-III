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
#define SIZE 15
bool gotIt = false;
int active_column = -1;
int active_row = -1;

// Prototype and Implementation of the functions.
int strSize(char usr_Inputs[SIZE])
{
	int size = 0;
	int i = 0;
	while (usr_Inputs[i++] != '\0')
		size++;
	return size;
}
bool checkHorizontal(char *usrValue, char rawPattern[SIZE][SIZE]);
bool checkVertical(char *usrValue, char rawPattern[SIZE][SIZE]);
void printThePattern(char rawPatter[SIZE][SIZE], bool isFinded, bool isHorizontal, int stringSize);

// Main Function
int main()
{
	char usr_input[15];
	char theList[SIZE][SIZE] = {
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
	scanf("%s", usr_input);
	checkHorizontal(usr_input, theList) ? printThePattern(theList, true, true, strSize(usr_input))
										: "NOT FOUND!";
	checkVertical(usr_input, theList) ? printThePattern(theList, true, false, strSize(usr_input))
									  : "NOT FOUND!";
}

bool checkHorizontal(char *usrValue, char rawPattern[SIZE][SIZE])
{
	int string_size = strSize(usrValue);

	for (size_t i = 0; i < SIZE; i++) //Row
	{
		//int temp_str_size = 0;
		for (size_t j = 0; j < SIZE; j++) //Column
		{
			if (rawPattern[i][j] == usrValue[0])
			{
				int index = 0;
				for (size_t f = 0; f < string_size; f++)
				{
					if (rawPattern[i][j + index] == usrValue[index])
						index++;
					if (index == string_size)
					{
						active_row = i;
						active_column = j;
						return true;
					}
				}
			}
			// if ((status == true) && (temp_str_size > 0))
			// {
			// 	printf("%c", rawPattern[i][j]);
			// 	temp_str_size--;
			// }
			// else
			// {
			// 	printf("*");
			// }
		}
		// printf("\n");
	}
	return false;
}

//FIELD PART
bool checkVertical(char *usrValue, char rawPattern[SIZE][SIZE])
{

	int string_size = strSize(usrValue);
	int index = 0;

	for (size_t i = 0; i < SIZE; i++)
	{

		for (size_t j = 0; j < SIZE; j++)
		{
			if (rawPattern[i][j] == usrValue[0])
			{

				while ((index < string_size) && (index + i < 15))
				{

					if (rawPattern[i + index][j] == usrValue[index])
					{

						index++;
						if (index == string_size)
						{
							//Confirmed Area..
							active_column = j;
							active_row = i;
							return true;
						}
					}

					else

						break;
				}
			}
			// if ((status == true) && (i - active_row < string_size) && (j == active_column))
			// {
			// 	// printf("were here.");
			// 	printf("%c", rawPattern[i][j]);
			// 	if (i - active_row >= string_size)
			// 		status = NULL;
			// }
			// else if ((active_column == -1 || active_row == -1) && index > 0)
			// {
			// 	printf("*");
			// }
			// else
			// {
			// 	printf("*");
			// }
		}
		// printf("\n");
	}
	return false;
}

void printThePattern(char rawPatter[SIZE][SIZE], bool isFinded, bool isHorizontal, int stringSize)
{
//	int trap = stringSize;
	// int temp_str_size = stringSize;
	//using active_row and active_column.
	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE; j++)
		{
			if (isFinded == true && isHorizontal == true && i == active_row && j == active_column)
			{
				for (int f = 0; f < stringSize; f++)
					printf("%c", rawPatter[i][j + f]);
				j += stringSize;
			}
			if (isFinded == true && isHorizontal == false && j == active_column && i - active_row < stringSize)
				printf("%c", rawPatter[i][j]);
			else
				printf("*");
		}
		printf("\n");
	}
}

/*
* Read a word from user and search that word in the two-dimensional array.  
* If your program finds the word in the array, it prints all the elements 
* of the array with the following rule. The word will be printed as it is.  
* The other characters will be printed as ‘*’. If your word is not in the array,
* all the characters will be printed with ‘*’ character. The words should 
* be searched from left to right and from top to bottom.
*/