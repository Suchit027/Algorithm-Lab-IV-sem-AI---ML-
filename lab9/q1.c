#include <stdio.h>
#include <stdlib.h>
int *shift_table(char *pattern, int n)
{
    int *table = (int *)malloc(sizeof(int) * 26);
    for (int i = 0; i < 26; ++i)
    {
        table[i] = n;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        table[(int)pattern[i] - 97] = n - 1 - i;
    }
    return table;
}
int horspool(char *string, int n1, char *pattern, int n2)
{
    int *table = shift_table(pattern, n2);
    int i = n2 - 1;
    while (i <= n1 - 1)
    {
        int k = 0;
        while (k < n2 && pattern[n2 - 1 - k] == string[i - k])
        {
            ++k;
        }
        if (k == n2)
        {
            return i - n2 + 1;
        }
        else
        {
            if ((int)string[i] < 97)
            {
                i += table[(int)string[i] - 65];
            }
            else
            {
                i += table[(int)string[i] - 97];
            }
        }
    }
    return -1;
}
void main()
{
    char string[] = "Hello";
    char pattern[] = "lo";
    printf("%d", horspool(string, 5, pattern, 2));
}