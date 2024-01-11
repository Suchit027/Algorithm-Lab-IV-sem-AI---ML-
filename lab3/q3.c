#include <stdio.h>
#include <stdlib.h>
void partition(int *arr, int n)
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
    partition(arr, n);
}