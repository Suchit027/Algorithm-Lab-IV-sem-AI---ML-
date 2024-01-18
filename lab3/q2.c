#include <stdio.h>
int match(char *str1, char *str2)
{
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; ++i)
    {
        if (str1[i] > str2[i])
        {
            return 1;
        }
        else if (str1[i] < str2[i])
        {
            return -1;
        }
    }
    return 0;
}
void main()
{
    printf("enter strings\n");
    char str1[20], str2[20];
    scanf("%s %s", str1, str2);
    match(str1, str2);
}