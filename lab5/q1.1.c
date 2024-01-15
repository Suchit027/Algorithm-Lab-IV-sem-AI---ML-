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
    int tos, *arr;
};
sl stack_create(int vertices)
{
    sl ob = (sl)malloc(sizeof(struct stack));
    ob->arr = (int *)malloc(sizeof(int) * vertices);
    ob->tos = -1;
    return ob;
}
void push(sl stack, int vertice)
{
    stack->arr[++stack->tos] = vertice;
    return;
}
int pop(sl stack)
{
    if (stack->tos == -1)
    {
        return -1;
    }
    return stack->arr[stack->tos--];
}
void topological(al *list, int curr, sl result, int *visit)
{
    if (visit[curr] == 0)
    {
        visit[curr] = 1;
    }
    for (al t = list[curr]->link; t != NULL; t = t->link)
    {
        if (visit[t->vertice] == 0)
        {
            topological(list, t->vertice, result, visit);
        }
    }
    push(result, curr);
    return;
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
        printf("enter 1 - edge, 2- break\n");
        scanf("%d", &a);
        if (a == 1)
        {
            printf("enter source, destination\n");
            int s, d;
            scanf("%d %d", &s, &d);
            al t = (al)malloc(sizeof(struct adlist));
            t->vertice = d;
            t->link = list[s]->link;
            list[s]->link = t;
        }
    } while (a != 2);
    sl stack = stack_create(v);
    int *visit = (int *)calloc(sizeof(int), v);
    for (int i = 0; i < v; ++i)
    {
        if (visit[i] == 0)
        {
            topological(list, i, stack, visit);
        }
    }
    while (stack->tos != -1)
    {
        printf("%d", pop(stack));
    }
}