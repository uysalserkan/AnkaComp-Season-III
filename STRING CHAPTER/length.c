#include <stdio.h>
int strlength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

int main(){
    char str1[]="Hello World!";
    char str2[]="What's up!";
    printf("STR1: %d\nSTR': %d\n",strlength(str1),strlength(str2));

}