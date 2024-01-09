#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b)
{
    int min;
    min = a < b ? a : b;
    while (b % min != 0 && a % min == 0)
    {
        min -= 1;
    }
    return min;
}
void main()
{
    printf("enter a and b\n");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", gcd(a, b));
}