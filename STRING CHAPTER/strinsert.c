#include <stdio.h>
int strlength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void strInsert(char *str1, char *str2)
{
    int str2Size = strlength(str2);
    int str1Size = strlength(str1);
    for (size_t i = 0; i < str2Size; i++)
        str1[i + str1Size] = str2[i];

    str1[str1Size + str2Size] = '\0';
}

int main()
{
    char str1[100] = "Serkan ";
    char str2[] = "UYSAL";
    printf("before the inserting str1: %s\n", str1);
    strInsert(str1, str2);
    printf("after the inserting str1: %s\n", str1);
}