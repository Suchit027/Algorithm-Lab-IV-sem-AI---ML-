#include <stdio.h>
#include <stdlib.h>
int *sieve(int a)
{
    int *arr = (int *)calloc(sizeof(int), a + 1);
    arr[0] = arr[1] = -1;
    for (int i = 2; i < a + 1; ++i)
    {
        for (int j = i * 2; j < a + 1; j += i)
        {
            arr[j] = -1;
        }
    }
    return arr;
}
int gcd(int a, int b)
{
    int *a_arr = sieve(a);
    int ans = 1;
    for (int i = 2; i < a + 1; ++i)
    {
        if (a_arr[i] == 0 && a % i == 0 && b % i == 0)
        {
            ans *= i;
        }
    }
    return ans;
}
void main()
{
    printf("enter a and b\n");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", gcd(a, b));
}