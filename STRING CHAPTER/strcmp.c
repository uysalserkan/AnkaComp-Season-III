#include <stdio.h>
#include <stdbool.h>
int strlength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

//1 is same, 0 is not..

bool strCmp(char *str1, char *str2)
{
    int str1Size = strlength(str1);
    for (size_t i = 0; i < str1Size; i++)
        if (str1[i] != str2[i])
            return false;
    return true;
}

int main()
{
    char str1[] = "Serkan";
    char str2[] = "serkan";
    char str3[] = "Serkan";
    printf("STR1 Comparasion STR2: %d\n", strCmp(str1, str2));
    printf("STR1 Comparasion STR3: %d\n", strCmp(str1, str3));
}