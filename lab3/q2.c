#include <stdio.h>
// baisically substring finding
int match(char *str1, int n1, char *str2, int n2)
{
    for (int i = 0; i < n1 - n2 + 1; ++i)
    {
        int j = i;
        int k = 0;
        for (; k < n2; ++j, ++k)
        {
            if (str1[j] != str2[k])
            {
                break;
            }
        }
        if (k == n2)
        {
            return i;
        }
    }
    return -1;
}
void main()
{
    char str1[20], str2[20];
    int n1, n2;
    printf("enter string1 and length\n");
    scanf("%s %d", str1, &n1);
    printf("enter string2 and length\n");
    scanf("%s %d", str2, &n2);
    printf("%d", match(str1, n1, str2, n2));
}