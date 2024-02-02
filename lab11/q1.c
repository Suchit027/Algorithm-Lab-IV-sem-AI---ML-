#include <stdio.h>
#include <stdlib.h>
typedef struct edge *el;
struct edge
{
    int s, d, w;
    el link;
};
int dfs(el *list, int vertices, int *visit, int curr, int parent)
{
    if (visit[curr] == 1)
    {
        return -1;
    }
    visit[curr] = 1;
    for (el x = list[curr]->link; x != NULL; x = x->link)
    {
        if (x->d == parent)
        {
            continue;
        }
        if (dfs(list, vertices, visit, x->d, x->s) == -1)
        {
            return -1;
        }
    }
    return 0;
}
el *kruskal(el edges, int vertices)
{
    el *list = (el *)malloc(sizeof(el) * vertices);
    // creating the adjacency list for dfs
    for (int i = 0; i < vertices; ++i)
    {
        list[i] = (el)malloc(sizeof(struct edge));
        list[i]->link = NULL;
    }
    for (; edges->link != NULL;)
    {
        // since edges are undirected, there are two instances of same edge
        // first instance
        el curr1 = edges->link;
        edges->link = edges->link->link;
        curr1->link = list[curr1->s]->link;
        list[curr1->s]->link = curr1;
        // second instance
        el curr2 = edges->link;
        edges->link = edges->link->link;
        curr2->link = list[curr2->s]->link;
        list[curr2->s]->link = curr2;
        int *visit = (int *)malloc(sizeof(int) * vertices);
        for (int i = 0; i < vertices; ++i)
        {
            if (visit[i] == 0)
            {
                if (dfs(list, vertices, visit, i, -1) == -1)
                {
                    // deleting both directions of this undirected edge
                    list[curr1->s]->link = list[curr1->s]->link->link;
                    list[curr2->s]->link = list[curr2->s]->link->link;
                    break;
                }
            }
        }
    }
    return list;
}
void main()
{
    printf("enter no. of vertices\n");
    int v;
    scanf("%d", &v);
    int a;
    el edges = (el)malloc(sizeof(struct edge));
    edges->link = NULL;
    do
    {
        printf("enter 1 for edge, 2 to break\n");
        scanf("%d", &a);
        if (a == 1)
        {
            printf("enter v1, v2, weight\n");
            int v1, v2, w;
            scanf("%d %d %d", &v1, &v2, &w);
            // creating first direction of the undirected edge
            el ob1 = (el)malloc(sizeof(struct edge));
            ob1->s = v1;
            ob1->d = v2;
            ob1->w = w;
            ob1->link = edges->link;
            edges->link = ob1;
            // creating second direction of undirected edge
            el ob2 = (el)malloc(sizeof(struct edge));
            ob2->s = v2;
            ob2->d = v1;
            ob2->w = w;
            ob2->link = edges->link;
            edges->link = ob2;
        }
    } while (a != 2);
    // sorting edges based on weights
    for (el x = edges->link; x->link != NULL; x = x->link)
    {
        for (el j = x->link; j != NULL; j = j->link)
        {
            if (j->w < x->w)
            {
                int s, d, w;
                s = x->s;
                d = x->d;
                w = x->w;
                x->s = j->s;
                x->d = j->d;
                x->w = j->w;
                j->s = s;
                j->d = d;
                j->w = w;
            }
        }
    }
    el *list = kruskal(edges, v);
    for (int i = 0; i < v; ++i)
    {
        el x = list[i]->link;
        while (x != NULL)
        {
            printf("%d - %d,%d ", x->s, x->d, x->w);
            x = x->link;
        }
        printf("\n");
    }
}