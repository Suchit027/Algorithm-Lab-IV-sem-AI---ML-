#include <stdio.h>
int partition(int *arr, int low, int high)
{
    int p = arr[low];
    int i = low + 1;
    int j = high;
    while (1)
    {
        while (arr[i] < p && i < high)
        {
            ++i;
        }
        while (arr[j] > p && j > low)
        {
            --j;
        }
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        if(i >= j){
            break;
        }
    }
    // undoing last swap of i <= j
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
    // swapping pivot with j
    temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;
    return j;
}
void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int j = partition(arr, low, high);
        quicksort(arr, low, j - 1);
        quicksort(arr, j + 1, high);
    }
}
void main()
{
    printf("enter array of 10 elements\n");
    int arr[10];
    for (int i = 0; i < 10; ++i)
    {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, 9);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
}