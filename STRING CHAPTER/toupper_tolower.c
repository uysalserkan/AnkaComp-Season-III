#include <stdio.h>
int strlength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void toUpper(char *str)
{
    int size = strlength(str);

    for (int i = 0; i < size; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] += 'A' - 'a';
        }
    }
}
void toLower(char *str)
{
    int size = strlength(str);

    for (int i = 0; i < size; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] -= 'A' - 'a';
        }
    }
}

int main()
{
    char str1[] = "Hello World! Whats uP?";
    printf("Before toUpper(): %s\n", str1);
    toUpper(str1);
    printf("After toUpper(): %s\n", str1);
    toLower(str1);
    printf("After toLower(): %s\n", str1);
}