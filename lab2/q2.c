#include <stdio.h>
#include <stdlib.h>
int *sieve(int a)
{
    int *arr = (int *)calloc(sizeof(int), a + 1);
    arr[0] = arr[1] = -1;
    for (int i = 2; i < a + 1; ++i)
    {
        if (arr[i] == 0)
        {
            for (int j = i * 2; j < a + 1; j += i)
            {
                arr[j] = -1;
            }
        }
    }
    return arr;
}
int power(int a, int b)
{
    int ans = 1;
    for (; b > 0; --b)
    {
        ans *= a;
    }
    return ans;
}
int count(int prime, int num)
{
    int ans = 0;
    while (num > 0 && num % prime == 0)
    {
        ans += 1;
        num = num / prime;
    }
    return ans;
}
int gcd(int a, int b)
{
    int *a_arr = sieve(a);
    int ans = 1;
    for (int i = 2; i < a + 1; ++i)
    {
        if (a_arr[i] == 0 && a % i == 0 && b % i == 0)
        {
            ans *= power(i, count(i, a));
        }
    }
    return ans;
}
void main()
{
    printf("enter a and b\n");
    int a, b;
    scanf("%d %d", &a, &b);
    int x = a > b ? b : a;
    int y = a > b ? a : b;
    printf("%d", gcd(x, y));
}