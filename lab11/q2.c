#include <stdio.h>
#include <stdlib.h>
typedef struct element *el;
struct element
{
    int vertice, distance;
};
typedef struct edge *ed;
struct edge
{
    int s, d, w;
    ed link;
};
typedef struct heap *hl;
struct heap
{
    el *array;
    int heapsize, size;
};
hl heap_create(int size)
{
    hl ob = (hl)malloc(sizeof(struct heap));
    ob->array = (el *)malloc(sizeof(el) * size);
    for (int i = 0; i < size; ++i)
    {
        ob->array[i] = (el)malloc(sizeof(struct element));
    }
    ob->heapsize = 0;
    ob->size = size;
    return ob;
}
void heap_push(hl ob, el ele)
{
    int i = ++ob->heapsize;
    while (i > 1 && ob->array[i / 2]->distance > ele->distance)
    {
        ob->array[i] = ob->array[i / 2];
        i /= 2;
    }
    ob->array[i] = ele;
    return;
}
el heap_pop(hl ob)
{
    el ans = ob->array[1];
    el temp = ob->array[ob->heapsize--];
    int child = 2, parent = 1;
    while (child <= ob->heapsize)
    {
        if (child <
         ob->heapsize && ob->array[child]->distance > ob->array[child + 1]->distance)
        {
            child += 1;
        }
        if (temp->distance < ob->array[child]->distance)
        {
            break;
        }
        ob->array[parent] = ob->array[child];
        parent = child;
        child *= 2;
    }
    ob->array[parent] = temp;
    return ans;
}
void dijkstra(ed *list, int source, int vertices)
{
    int *dis = (int *)malloc(sizeof(int) * vertices);
    for (int i = 0; i < vertices; ++i)
    {
        dis[i] = 10000000;
    }
    dis[source] = 0;
    int *visit = (int *)calloc(sizeof(int), vertices);
    hl heap = heap_create(vertices + 1);
    el src = (el)malloc(sizeof(struct element));
    src->distance = 0;
    src->vertice = source;
    heap_push(heap, src);
    while (heap->heapsize > 0)
    {
        el curr = heap_pop(heap);
        if (visit[curr->vertice] == 0)
        {
            visit[curr->vertice] = 1;
            for (ed x = list[curr->vertice]->link; x != NULL; x = x->link)
            {
                if (x->w + dis[x->s] < dis[x->d])
                {
                    dis[x->d] = dis[x->s] + x->w;
                    el ele = (el)malloc(sizeof(struct element));
                    ele->distance = dis[x->d];
                    ele->vertice = x->d;
                    heap_push(heap, ele);
                }
            }
        }
    }
    for (int i = 0; i < vertices; ++i)
    {
        printf("%d ", dis[i]);
    }
}
void main()
{
    printf("enter no. of vertices\n");
    int v;
    scanf("%d", &v);
    ed *list = (ed *)malloc(sizeof(ed) * v);
    for (int i = 0; i < v; ++i)
    {
        list[i] = (ed)malloc(sizeof(struct edge));
        list[i]->link = NULL;
    }
    int a = 0;
    do
    {
        printf("enter 1 for edge, 2 to break\n");
        scanf("%d", &a);
        if (a == 1)
        {
            printf("enter source, destination, weight\n");
            int s, d, w;
            scanf("%d %d %d", &s, &d, &w);
            ed ob1 = (ed)malloc(sizeof(struct edge));
            ob1->s = s;
            ob1->d = d;
            ob1->w = w;
            ob1->link = list[s]->link;
            list[s]->link = ob1;
            ed ob2 = (ed)malloc(sizeof(struct edge));
            ob2->s = d;
            ob2->d = s;
            ob2->w = w;
            ob2->link = list[d]->link;
            list[d]->link = ob2;
        }
    } while (a != 2);
    printf("enter source\n");
    int s;
    scanf("%d", &s);
    dijkstra(list, s, v);
}