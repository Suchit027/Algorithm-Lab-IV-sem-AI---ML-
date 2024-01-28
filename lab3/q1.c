#include <stdio.h>
void bubblesort(int *arr, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void main()
{
    printf("enter array size\n");
    int n;
    scanf("%d", &n);
    printf("enter array\n");
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    bubblesort(arr, n);
    printf("array - \n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d", arr[i]);
    }
}