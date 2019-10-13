#include <stdio.h>
int strlength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}
void strCopy(char *str1, char *str2)
{
    int str2Size = strlength(str2);
    for (int i = 0; str2[i] != '\0'; i++)
        str1[i] = str2[i];
    str1[str2Size] = '\0';
}

int main()
{
    char str1[] = "Hello";
    char str2[] = "World";
    printf("STR1: %s\nSTR2: %s\n", str1, str2);
    strCopy(str1, str2);
    printf("STR1: %s\nSTR2: %s\n", str1, str2);
}