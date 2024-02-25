#include <stdio.h>
#include <stdlib.h>
typedef struct heap *hl;
struct heap
{
    int *arr, size, heapsize;
};
hl create(int size)
{
    hl ob = (hl)malloc(sizeof(struct heap));
    ob->size = size + 1;
    ob->arr = (int *)malloc(sizeof(int) * size + 1);
    ob->heapsize = 0;
    return ob;
}
void heap_push(hl heap, int ele)
{
    int i = 1;
    while (i <= heap->heapsize)
    {
        if (heap->arr[i] > ele)
        {
            int temp = heap->arr[i];
            heap->arr[i] = ele;
            ele = temp;
        }
        i *= 2;
        if (i < heap->heapsize && heap->arr[i] > heap->arr[i + 1])
        {
            i += 1;
        }
    }
    heap->arr[++heap->heapsize] = ele;
    return;
}
int pop(hl ob)
{
    if (ob->heapsize == 0)
    {
        return -1;
    }
    int val = ob->arr[1];
    int temp = ob->arr[ob->heapsize--];
    int parent = 1, child = 2;
    while (child <= ob->heapsize) // note the <=
    {
        if ((ob->arr[child] > ob->arr[child + 1]) && (child < ob->heapsize))
        {
            child += 1;
        }
        if (temp <= ob->arr[child])
        {
            break;
        }
        ob->arr[parent] = ob->arr[child];
        parent = child;
        child *= 2;
    }
    ob->arr[parent] = temp;
    return val;
}
void main()
{
    hl heap = create(6);
    heap_push(heap, 3);
    heap_push(heap, 10);
    heap_push(heap, 12);
    heap_push(heap, 8);
    heap_push(heap, 2);
    heap_push(heap, 14);
    for (int i = 0; i < 6; ++i)
    {
        printf("%d ", pop(heap));
    }
}