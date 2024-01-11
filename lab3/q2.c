#include <stdio.h>
void match(char *str1, char *str2)
{
    int check = 1;
    int i, j;
    for (i = 0, j = 0; str1[i] != '\0' && str2[j] != '\0'; ++i, ++j)
    {
        if (str1[i] != str2[j])
        {
            check = 0;
            break;
        }
    }
    if (i != j || check == 0)
    {
        printf("not equal\n");
    }
    else
    {
        printf("equal\n");
    }
}
void main()
{
    printf("enter strings\n");
    char str1[20], str2[20];
    scanf("%s %s", str1, str2);
    match(str1, str2);
}