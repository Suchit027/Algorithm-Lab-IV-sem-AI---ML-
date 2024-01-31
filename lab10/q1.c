#include <stdio.h>
#include <stdlib.h>
void warshall(int **arr, int vertices)
{
    for (int k = 0; k < vertices; ++k)
    {
        for (int i = 0; i < vertices; ++i)
        {
            for (int j = 0; j < vertices; ++j)
            {
                arr[i][j] = arr[i][j] || (arr[i][k] && arr[k][j]);
            }
        }
    }
    return;
}
void main()
{
    printf("enter no. of vertices\n");
    int n;
    scanf("%d", &n);
    int **adMat = (int **)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
    {
        adMat[i] = (int *)calloc(sizeof(int), n);
    }
    int a;
    do
    {
        printf("enter 1 for edge 2 to break\n");
        scanf("%d", &a);
        if (a == 1)
        {
            printf("enter source and destination\n");
            int s, d;
            scanf("%d %d", &s, &d);
            adMat[s][d] = 1;
        }
    } while (a != 2);
    warshall(adMat, n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d ", adMat[i][j]);
        }
        printf("\n");
    }
}