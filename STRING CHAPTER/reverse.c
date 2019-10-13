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

void strReverse(char str[])
{
    char temp[strlength(str)];
    strCopy(temp, str);
    int strSize = strlength(str);
    for (int i = 0; i < strSize; i++)
    {
        str[strSize - i - 1] = temp[i];
    }
    str[strSize] = '\0';
}

int main()
{
    char str[] = "Serkan";
    printf("Before reverse: %s\n", str);
    strReverse(str);
    printf("After reverse: %s\n", str);
}