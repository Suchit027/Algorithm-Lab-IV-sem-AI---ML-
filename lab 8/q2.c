#include <stdio.h>
#include <stdlib.h>
typedef struct element *ele;
struct element
{
    int key;
    int val;
};
typedef struct heap *heapl;
struct heap
{
    ele *arr;
    int size, heapsize;
};
heapl create(int size)
{
    heapl ob = (heapl)malloc(sizeof(struct heap));
    ob->arr = (ele *)malloc(sizeof(ele) * size);
    ob->size = size;
    ob->heapsize = 0;
    return ob;
}
void push(heapl ob, ele n)
{
    if (ob->heapsize == ob->size - 1)
    {
        ob->arr = (ele *)realloc(ob->arr, ob->size * 2);
        ob->size *= 2;
    }
    int i = ++ob->heapsize;
    while (i > 1 && (n->key > ob->arr[i / 2]->key))
    {
        ob->arr[i] = ob->arr[i / 2];
        i /= 2;
    }
    ob->arr[i] = n;
}
int pop(heapl ob)
{
    if (ob->heapsize == 0)
    {
        return -1;
    }
    int val = ob->arr[1]->val;
    ele temp = ob->arr[ob->heapsize--];
    int parent = 1, child = 2;
    while (child <= ob->heapsize) // note the <=
    {
        if ((ob->arr[child]->key < ob->arr[child + 1]->key) && (child < ob->heapsize))
        {
            child += 1;
        }
        if (temp->key >= ob->arr[child]->key)
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
    heapl ob = create(10);
    ele e1 = (ele)malloc(sizeof(struct element));
    ele e2 = (ele)malloc(sizeof(struct element));
    ele e3 = (ele)malloc(sizeof(struct element));
    ele e4 = (ele)malloc(sizeof(struct element));
    ele e5 = (ele)malloc(sizeof(struct element));
    ele e6 = (ele)malloc(sizeof(struct element));
    ele e7 = (ele)malloc(sizeof(struct element));
    ele e8 = (ele)malloc(sizeof(struct element));
    e1->val = e1->key = 3;
    e2->val = e2->key = 10;
    e3->val = e3->key = 12;
    e4->val = e4->key = 8;
    e5->val = e5->key = 2;
    e6->val = e6->key = 14;
    push(ob, e1);
    push(ob, e2);
    push(ob, e3);
    push(ob, e4);
    push(ob, e5);
    push(ob, e6);
    while (ob->heapsize != 0)
    {
        printf("%d ", pop(ob));
    }
}