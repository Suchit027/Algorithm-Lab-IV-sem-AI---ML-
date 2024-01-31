#include <stdio.h>
#include <stdlib.h>
int **knapsack(int **value, int capacity, int weights)
{
    int **matrix = (int **)malloc(sizeof(int *) * (weights + 1));
    for (int i = 0; i < weights + 1; ++i)
    {
        matrix[i] = (int *)calloc(sizeof(int), (capacity + 1));
    }
    for (int i = 1; i < capacity + 1; ++i)
    {
        for (int j = 1; j < weights + 1; ++j)
        {
            if (i - value[j][0] >= 0)
            {
                matrix[j][i] = value[j][1] + matrix[j - 1][i - value[j][0]] >= matrix[j - 1][i] ? value[j][1] + matrix[j - 1][i - value[j][0]] : matrix[j - 1][i];
            }
            else
            {
                matrix[j][i] = matrix[j - 1][i];
            }
        }
    }
    return matrix;
}
void main()
{
    printf("enter the no. of weights and the knapsack capacity\n");
    int k, n;
    scanf("%d %d", &n, &k);
    int **value = (int **)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n + 1; ++i)
    {
        value[i] = (int *)calloc(sizeof(int), 2);
        if (i == 0)
        {
            continue;
        }
        printf("enter weight and its value\n");
        scanf("%d %d", &value[i][0], &value[i][1]);
    }
    int **ans = knapsack(value, k, n);
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < k + 1; ++j)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}