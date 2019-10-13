#include <stdio.h>
int strlength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

int subStr(char *str, char *pattern)
{
    int strSize = strlength(str);
    int patternSize = strlength(pattern);
    for (size_t i = 0; i < strSize; i++)
    {
        if (str[i] == pattern[0])
        {
            int counter = 0;

            for (size_t j = 0; j < patternSize; j++)
            {
                if (str[i + j] == pattern[j])
                    counter++;
                if (counter == patternSize)
                {
                    // printf("index: %d\n", i);
                    return i;
                }
            }
        }
    }
    return -1;
}

void replaceStr(char *str, char *pat1, char *pat2)
{
    int strSize = strlength(str);
    int pat1Size = strlength(pat1);
    int pat2Size = strlength(pat2);
    int index = subStr(str, pat1);
    if (index == -1)
    {
        printf("We cannot found pattern1 int the string!\n");
        return;
    }
    else
    {
        //This code runs and block switch the patterns if index !=-1
        if (pat1Size == pat2Size)
        {
            for (size_t x = 0; x < pat1Size; x++)
            {
                str[index + x] = pat2[x];
            }
        }
        if (pat1Size > pat2Size)
        {
            int temp = pat1Size;
            for (size_t h = index + (pat1Size - pat2Size); h < strSize - (pat1Size - pat2Size); h++, temp++)
            {
                str[h] = str[index + temp];
            }
            for (size_t x = 0; x < pat2Size; x++)
            {
                str[index + x] = pat2[x];
            }
            str[strSize - (pat1Size - pat2Size)] = '\0';
        }
        if (pat2Size > pat1Size)
        {
            int i = 0;
            for (size_t s = strSize + (pat2Size - pat1Size); s > index; s--, i++)
            {
                str[s] = str[strSize - i];
            }
            for (size_t x = 0; x < pat1Size; x++)
            {
                str[index + x] = pat2[x];
            }
        }
    }
}

int main()
{
    char str1[100] = "Serkan bir the bad boy";
    char str2[100] = "Serkan bir the bad boy";
    char pat[] = "bad";
    char pat2[] = "good";
    char pat1[] = "Serkan";
    char pat3[] = "Ibo";
    char pat4[] = "bir";
    char pat5[] = "iki";
    char pat6[] = "bişilerbişiler";
    printf("Before the replace bir to iki: %s\n", str1);
    replaceStr(str1, pat4, pat5);
    printf("After the replace bir to iki: %s\n", str1);
    printf("\nWhen we cannot found pattern in str\n");
    replaceStr(str1, pat4, pat6);
    printf("\nBefore the replace bad to good: %s\n", str1);
    replaceStr(str1, pat, pat2);
    printf("After the replace bad to good: %s\n", str1);
    printf("\nBefore the replace Serkan to Ibo: %s\n", str1);
    replaceStr(str1, pat1, pat3);
    printf("After the replace Serkan to Ibo: %s\n", str1);
}