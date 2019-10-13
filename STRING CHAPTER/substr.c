#include <stdio.h>
#include <stdbool.h>

int strlength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

bool strSub(char *str, char *pattern, int start, int end)
{
    // int strSize = strlength(str);
    int patternSize = strlength(pattern);
    for (size_t i = start; i < end; i++)
    {
        if (str[i] == pattern[0])
        {
            int counter = 0;
            for (size_t j = i; j < i + patternSize; j++)
            {
                if (str[j] == pattern[j - i])
                    counter++;
                if (counter == patternSize)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    char str1[] = "Serkan UYSAL";
    char str2[] = "er";
    char str3[] = "SAL";
    char str4[] = "nak";
    printf("is STR2 subStr STR1(0,6): %d\n", strSub(str1, str2, 0, 6));
    printf("is STR3 subStr STR1(0,6): %d\n", strSub(str1, str3, 0, 6));
    printf("is STR3 subStr STR1(0,12): %d\n", strSub(str1, str3, 0, 12));
    printf("is STR4 subStr STR1(0,12): %d\n", strSub(str1, str4, 0, 12));
}