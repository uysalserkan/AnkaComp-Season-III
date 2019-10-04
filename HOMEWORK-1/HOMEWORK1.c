/*
* Comiler: GCC 7.4.0
* Enviroment: Ubuntu 18.04.1
*/

#include <stdio.h>
#include <stdbool.h>
#define SIZE 15
// Prototype of the functions.
int strSize(char usr_Inputs[SIZE])
{
	int size = 0;
	int i = 0;
	while (usr_Inputs[i++] != '\0')
		size++;
	return size;
}
void checkHorizontal(char *usrValue, char rawPattern[SIZE][SIZE]);
void checkVertical(char *usrValue, char rawPattern[SIZE][SIZE]);

// Main Function
int main()
{
	char usr_input[15] = "CN";
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
	// scanf("%s",&usr_input);
	checkHorizontal(usr_input, theList);
	// printf("%p\n%s",&theList,usr_input);
}

//SOME ERROR LAST BODY ACN etc.
void checkHorizontal(char *usrValue, char rawPattern[SIZE][SIZE])
{
	int string_size = strSize(usrValue);

	for (size_t i = 0; i < SIZE; i++)
	{

		for (size_t j = 0; j < SIZE; j++)
		{
			if (rawPattern[i][j] == usrValue[0])
			{
				//Baş harfi sağdan sola kontrol edilecek.
				int index = 0;

				while (index < string_size)
				{

					if (rawPattern[i][j + index] == usrValue[index])
					{
						// printf("%c",rawPattern[i][j + index]);
						index++;
						if (index == string_size)
						{
							for (size_t f = 0; f < string_size; f++)
							{
								printf("%c", usrValue[f]);
							}
						}
					}

					else
					{
						break;
					}
				}
				while (index != string_size && index > 0)
				{
					printf("*");
					index--;
				}
				if (index == string_size)
				{
					j += string_size - 1;
				}
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
}

//FIELD PART 
void checkVertical(char *usrValue, char rawPattern[SIZE][SIZE])
{
	bool status = false;
	int string_size = strSize(usrValue);
	int active_column = -1;
	int active_row = -1;
	int index = 0;

	for (size_t i = 0; i < SIZE; i++)
	{

		for (size_t j = 0; j < SIZE; j++)
		{
			if (rawPattern[i][j] == usrValue[0])
			{

				// printf("X");
				//Baş harfi sağdan sola kontrol edilecek.

				while ((index < string_size) && (index + i < 15))
				{

					if (rawPattern[i + index][j] == usrValue[index])
					{
						// printf("X");
						index++;
						if (index == string_size)
						{
							//Confirmed Area..
							active_column = j;
							active_row = i;
							status = true;
							// printf("%d", status);
						}
					}

					else
					{

						break;
					}
				}
			}
			 if ((status == true) && (i - active_row < string_size) && (j == active_column))
			{
				// printf("were here.");
				printf("%c", rawPattern[i][j]);
				if (i - active_row >= string_size)
					status = NULL;
			}
			else if ((active_column == -1 || active_row == -1) && index > 0)
			{
				printf("*");
			}
			else
			{
				printf("*");
			}
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