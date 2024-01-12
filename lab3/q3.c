#include <stdio.h>
#include <stdlib.h>
void partition1(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
    {
        printf("not possible\n");
    }
    int *dp = (int *)calloc(sizeof(int), sum);
    // 0 sum can be obtained from null set
    dp[0] = 1;
    int target = sum / 2;
    for (int i = 0; i < n; ++i)
    {
        int ele = arr[i];
        for (int j = target; j >= ele; --j)
        {
            // j can be obtained from itself
            if (dp[j])
            {
                continue;
            }
            // j can be obtained from j - ele
            if (dp[j - ele])
            {
                dp[j] = 1;
            }
        }
    }
    if (dp[target])
    {
        printf("it exists\n");
    }
    else
    {
        printf("it does not exists\n");
    }
}
int part_until(int *arr, int n, int index, int target)
{
    if (index == n || target < 0)
    {
        return 0;
    }
    if (target == 0)
    {
        return 1;
    }
    if (part_until(arr, n, index + 1, target - arr[index]))
    {
        return 1;
    }
    else if (part_until(arr, n, index + 1, target))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int can_part(int *arr, int n)
{
    if (n <= 1)
    {
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
    {
        return 0;
    }
    int target = sum / 2;
    return part_until(arr, n, 0, target);
}
void main()
{
    printf("enter array size\n");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("enter array elements\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    // partition1(arr, n);
    if (can_part(arr, n))
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
}