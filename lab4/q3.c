#include <stdio.h>
#include <stdlib.h>
typedef struct queue *ql;
struct queue
{
    int vertice;
    ql link;
};
typedef struct adlist *al;
struct adlist
{
    int d;
    al link;
};
ql queue_create()
{
    ql ob = (ql)malloc(sizeof(struct queue));
    ob->link = NULL;
    return ob;
}
void enqueue(ql queue, int ver)
{
    ql ob = queue_create();
    ob->vertice = ver;
    while (queue->link != NULL)
    {
        queue = queue->link;
    }
    queue->link = ob->link;
    ob->link = NULL;
}
int dequeue(ql queue)
{
    if (queue->link == NULL)
    {
        return -1;
    }
    int ans = queue->link->vertice;
    queue->link = queue->link->link;
    return ans;
}
void bfs(al *list, int vertices)
{
    ql queue = queue_create();
    int *visit = (int *)calloc(sizeof(int), vertices);
    for (int i = 0; i < vertices; ++i)
    {
        if (visit[i] == 0)
        {
            enqueue(queue, i);
        }
        while (queue->link != NULL)
        {
            int curr = dequeue(queue);
            if (visit[curr] == 0)
            {
                visit[curr] = 1;
                printf("%d", curr);
            }
            for (al t = list[curr]; t != NULL; t = t->link)
            {
                if (visit[t->d] == 0)
                {
                    enqueue(queue, t->d);
                }
            }
        }
    }
}
void main()
{
    printf("enter no. of vertices\n");
    int v;
    scanf("%d", &v);
    al *list = (al *)malloc(sizeof(struct adlist) * v);
    for (int i = 0; i < v; ++i)
    {
        list[i] = (al)malloc(sizeof(struct adlist));
        list[i]->link = NULL;
    }
    int a;
    do
    {
        printf("enter 1 - edge, 2 - break\n");
        scanf("%d", &a);
        if (a == 1)
        {
            printf("enter source, destination\n");
            int s, d;
            scanf("%d %d", &s, &d);
            al ob = (al)malloc(sizeof(struct adlist));
            ob->d = d;
            ob->link = list[s]->link;
            list[s]->link = ob->link;
        }
    } while (a != 2);
    bfs(list, v);
}