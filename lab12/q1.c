#include <stdio.h>
#include <stdlib.h>
int issubset(int *array, int len, int *visit, int target)
{
    if (target < 0)
    {
        return -1;
    }
    else if (target == 0)
    {
        return 1;
    }
    for (int i = 0; i < len; ++i)
    {
        if (visit[i] == 0)
        {
            visit[i] = 1;
            if (issubset(array, len, visit, target - array[i]) == 1)
            {
                return 1;
            }
            visit[i] = 0;
        }
    }
    return -1;
}
void main()
{
    printf("enter size\n");
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    printf("enter array\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter val\n");
    int k;
    scanf("%d", &k);
    int *visit = (int *)calloc(sizeof(int), n);
    if (issubset(arr, n, visit, k) == 1)
    {
        for (int i = 0; i < n; ++i)
        {
            if (visit[i] == 1)
            {
                printf("%d ", arr[i]);
            }
        }
    }
    else
    {
        printf("no subset\n");
    }
}