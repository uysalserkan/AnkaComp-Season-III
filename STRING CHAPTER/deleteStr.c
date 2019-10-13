#include <stdio.h>
int strlength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void deleteStr(char *str, int index, int lengt)
{
    int strSize = strlength(str);
    for (size_t i = index; i < strSize - lengt; i++)
    {
        str[i] = str[i + lengt];
    }
    str[strSize - lengt] = '\0';
}

int main()
{
    char str[] = "AhmetHamdiTanpınar";
    printf("Before the deleting operation stirng is: %s\n", str);
    deleteStr(str, 5, 5);
    printf("After the deleting operation stirng is: %s\n", str);
}