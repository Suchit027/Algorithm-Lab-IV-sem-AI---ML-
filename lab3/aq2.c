#include <stdio.h>
#include <stdlib.h>
typedef struct element *el;
struct element
{
    int e;
    int size;
    el link;
};
typedef struct stack *sl;
struct stack
{
    el arr;
    sl link;
};
el ele_create()
{
    el ob = (el)malloc(sizeof(struct element));
    ob->link = NULL;
    return ob;
}
void ele_push(el st, int a)
{
    el ob = ele_create();
    st->size += 1;
    ob->e = a;
    ob->link = st->link;
    st->link = ob;
    return;
}
sl stack_create()
{
    sl ob = (sl)malloc(sizeof(struct stack));
    ob->link = NULL;
    return ob;
}
void stack_push(sl st, el ele)
{
    sl ob = stack_create();
    ob->arr = ele;
    ob->link = st->link;
    st->link = ob;
    return;
}
int isclique(int **admat, int *visit, int vertices)
{
    for (int i = 0; i < vertices; ++i)
    {
        if (visit[i] == 0)
        {
            continue;
        }
        for (int j = i + 1; j < vertices; ++j)
        {
            if (visit[j] == 1)
            {
                if (admat[i][j] == 0)
                {
                    return -1;
                }
            }
        }
    }
    return 1;
}
void maxsub(int **admat, int vertices, int curr, sl st, int *visit)
{
    if (curr == vertices)
    {
        el sub = ele_create();
        for (int i = 0; i < vertices; ++i)
        {
            if (visit[i] == 1)
            {
                ele_push(sub, i);
            }
        }
        stack_push(st, sub);
        return;
    }
    visit[curr] = 1;
    if (isclique(admat, visit, vertices) == 1)
    {
        maxsub(admat, vertices, curr + 1, st, visit);
    }
    visit[curr] = 0;
    maxsub(admat, vertices, curr + 1, st, visit);
    return;
}
void main()
{
    printf("enter no. of graph vertices\n");
    int v;
    scanf("%d", &v);
    int **admat = (int **)malloc(sizeof(int *) * v);
    for (int i = 0; i < v; ++i)
    {
        admat[i] = (int *)calloc(sizeof(int), v);
    }
    int a;
    do
    {
        printf("enter 1 for edge, 2 to break\n");
        scanf("%d", &a);
        if (a == 1)
        {
            printf("enter s, d\n");
            int s, d;
            scanf("%d %d", &s, &d);
            admat[s][d] = 1;
            admat[d][s] = 1;
        }
    } while (a != 2);
    sl stack = stack_create();
    int *visit = (int *)calloc(sizeof(int), v);
    maxsub(admat, v, 0, stack, visit);
    sl temp = stack->link;
    int lar = 0;
    sl ans = NULL;
    for (; temp != NULL; temp = temp->link)
    {
        if (temp->arr->size > lar)
        {
            lar = temp->arr->size;
            ans = temp;
        }
    }
    el sub = ans->arr->link;
    for (; sub != NULL; sub = sub->link)
    {
        printf("%d ", sub->e);
    }
}