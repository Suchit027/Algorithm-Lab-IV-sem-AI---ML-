#include <stdio.h>
#include <stdlib.h>
typedef struct adlist *al;
struct adlist
{
    int vertice;
    al link;
};
typedef struct stack *sl;
struct stack
{
    int vertice;
    sl link;
};
sl stack_create()
{
    sl ob = (sl)malloc(sizeof(struct stack));
    ob->link = NULL;
    ob->vertice = 0;
    return ob;
}
void push(sl stack, int vertice)
{
    sl new = stack_create();
    new->vertice = vertice;
    new->link = stack->link;
    stack->link = new;
    return;
}
int pop(sl stack)
{
    if (stack->link == NULL)
    {
        return -1;
    }
    int ans = stack->link->vertice;
    stack->link = stack->link->link;
    return ans;
}
void dfs(al *list, int vertices)
{
    int *visit = (int *)calloc(sizeof(int), vertices);
    sl stack = stack_create();
    for (int i = 0; i < vertices; ++i)
    {
        if (visit[i] == 0)
        {
            push(stack, i);
        }
        while (stack->link != NULL)
        {
            int curr = pop(stack);
            if (visit[curr] == 0)
            {
                visit[curr] = 1;
                printf("%d ", curr);
            }

            for (al x = list[curr]; x != NULL; x = x->link)
            {
                if (visit[x->vertice] == 0)
                {
                    push(stack, x->vertice);
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
            ob->vertice = d;
            ob->link = list[s]->link;
            list[s]->link = ob->link;
        }
    } while (a != 2);
    dfs(list, v);
}