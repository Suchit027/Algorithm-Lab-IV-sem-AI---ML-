#include <stdio.h>
#include <stdlib.h>
typedef struct heap *hl;
struct heap
{
    int *arr;
    int size, heapsize;
};
hl create(int size)
{
    hl ob = (hl)malloc(sizeof(struct heap));
    ob->arr = (int *)malloc(sizeof(int) * size);
    ob->size = size;
    ob->heapsize = 0;
    return ob;
}
void push(hl ob, int n)
{
    int i = 1;
    ob->arr[++ob->heapsize] = -10000;
    while (i <= ob->heapsize)
    {
        if (n > ob->arr[i])
        {
            int temp = ob->arr[i];
            ob->arr[i] = n;
            n = temp;
        }
        i *= 2;
        if (i < ob->heapsize && ob->arr[i] > ob->arr[i + 1])
        {
            i += 1;
        }
    }
    return;
}
void main()
{
    hl ob = create(6);
    push(ob, 5);
    push(ob, 3);
    push(ob, 6);
    push(ob, 2);
    push(ob, 7);
    for (int i = 1; i <= ob->heapsize; ++i)
    {
        printf("%d ", ob->arr[i]);
    }
}