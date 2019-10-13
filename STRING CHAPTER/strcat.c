#include <stdio.h>
int strlength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}
//STR1'in sonuna STR2 eklenir.
void strCat(char *str1, char *str2)
{
    int str1Size = strlength(str1);
    int str2Size = strlength(str2);
    str1[str1Size++] = ' ';
    for (size_t i = 0; i < str2Size; i++)
    {
        str1[str1Size + i] = str2[i];
    }
    str1[str1Size + str2Size] = '\0';
}

int main()
{
    char str1[] = "Hello,";
    char str2[] = "World!";
    printf("str1: %s\n", str1);
    strCat(str1, str2);
    printf("str1: %s\n", str1);
}