#include <stdio.h>
#include <stdlib.h>
typedef struct queue *ql;
struct queue
{
    int d;
    ql link;
};
ql queue_create()
{
    ql ob = (ql)malloc(sizeof(struct queue));
    ob->link = NULL;
    return ob;
}
void enqueue(ql queue, int ele)
{
    while (queue->link != NULL)
    {
        queue = queue->link;
    }
    ql ob = queue_create();
    ob->d = ele;
    queue->link = ob;
    ob->link = NULL;
    return;
}
int dequeue(ql queue)
{
    if (queue->link == NULL)
    {
        return -1;
    }
    int ans = queue->link->d;
    queue->link = queue->link->link;
    return ans;
}
typedef struct stack *stl;
struct stack
{
    int tos, *arr;
};
stl stack_create(int vertices)
{
    stl ob = (stl)malloc(sizeof(struct stack));
    ob->arr = (int *)malloc(sizeof(int) * vertices);
    ob->tos = -1;
    return ob;
}
void push(stl stack, int ele)
{
    stack->arr[++stack->tos] = ele;
    return;
}
int pop(stl stack)
{
    return stack->arr[stack->tos--];
}
typedef struct adlist *al;
struct adlist
{
    int d;
    al link;
};
typedef struct set *sl;
struct set
{
    int d;
    sl link;
};
sl set_create()
{
    sl ob = (sl)malloc(sizeof(struct set));
    ob->link = NULL;
    return ob;
}
void add(sl set, int ele)
{
    if (set->link == NULL)
    {
        sl ob = set_create();
        ob->d = ele;
        set->link = ob;
        ob->link = NULL;
        return;
    }
    set = set->link;
    while (set->link != NULL)
    {
        if (set->d == ele)
        {
            return;
        }
        set = set->link;
    }
    sl ob = set_create();
    ob->d = ele;
    ob->link = NULL;
    set->link = ob;
    return;
}
void delete(sl set, int ele)
{
    if (set->link == NULL)
    {
        return;
    }
    sl pre = set;
    set = set->link;
    while (set != NULL)
    {
        if (set->d == ele)
        {
            pre->link = set->link;
            return;
        }
        pre = pre->link;
        set = set->link;
    }
    return;
}
void sort(al *list, int vertices, sl *sets, stl result)
{
    ql queue = queue_create();
    for (int i = 0; i < vertices; ++i)
    {
        if (sets[i]->link == NULL)
        {
            enqueue(queue, i);
        }
    }
    while (queue->link != NULL)
    {
        int curr = dequeue(queue);
        push(result, curr);
        if (result->tos == vertices - 1)
        {
            return;
        }
        for (al t = list[curr]->link; t != NULL; t = t->link)
        {
            delete (sets[t->d], curr);
            if (sets[t->d]->link == NULL)
            {
                enqueue(queue, t->d);
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
    sl *sets = (sl *)malloc(sizeof(struct set) * v);
    for (int i = 0; i < v; ++i)
    {
        list[i] = (al)malloc(sizeof(struct adlist));
        list[i]->link = NULL;
        sets[i] = set_create();
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
            list[s]->link = ob;
            add(sets[d], s);
        }
    } while (a != 2);
    stl stack = stack_create(v);
    sort(list, v, sets, stack);
    for (int i = 0; i < v; ++i)
    {
        printf("%d", stack->arr[i]);
    }
}