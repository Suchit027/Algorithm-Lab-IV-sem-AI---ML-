#include <stdio.h>
#include <stdlib.h>
typedef struct tree *tl;
struct tree
{
    int weight, value, level, upper_bound;
    tl lchild, rchild;
};
// maxheap for sorting tree nodes as they come in the queue
typedef struct heap *hl;
struct heap
{
    tl *array;
    int heapsize;
};
hl heap_create()
{
    hl ob = (hl)malloc(sizeof(struct heap));
    ob->array = (tl *)malloc(sizeof(tl) * 30);
    ob->heapsize = 0;
    return ob;
}
void hpush(hl ob, tl ele)
{
    int i = ++ob->heapsize;
    while (i > 1 && ob->array[i / 2]->upper_bound < ele->upper_bound)
    {
        ob->array[i] = ob->array[i / 2];
        i /= 2;
    }
    ob->array[i] = ele;
    return;
}
tl hpop(hl ob)
{
    tl ans = ob->array[1];
    tl temp = ob->array[ob->heapsize--];
    int parent = 1, child = 2;
    while (child <= ob->heapsize)
    {
        if (child < ob->heapsize && ob->array[child]->upper_bound < ob->array[child + 1]->upper_bound)
        {
            child += 1;
        }
        if (temp->upper_bound >= ob->array[child]->upper_bound)
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
tl knapsack(int **table, int weight, int values, tl parent)
{
    hl queue = heap_create();
    hpush(queue, parent);
    while (queue->heapsize > 0)
    {
        tl curr = hpop(queue);
        // All weights have been seen. No more options are now available
        if (curr->level == values)
        {
            return curr;
        }
        // left node represents - weight (with index as level - 1) is selected.
        tl ob_left = (tl)malloc(sizeof(struct tree));
        ob_left->level = curr->level + 1;
        // new weight and value are summation of previous selections and current selection
        ob_left->weight = curr->weight + table[ob_left->level - 1][0];
        ob_left->value = curr->value + table[ob_left->level - 1][1];
        // up = v + (W - w)(v(i + 1)/w(i + 1)) ; i + 1 is subscript
        ob_left->upper_bound = ob_left->value + ((weight - ob_left->weight) * (table[ob_left->level][2]));
        // right node represents - weight (with index as level - 1) is not selected
        tl ob_right = (tl)malloc(sizeof(struct tree));
        ob_right->level = curr->level + 1;
        // weight and value of current selection not included
        ob_right->weight = curr->weight;
        ob_right->value = curr->value;
        // up = v + (W - w)(v(i + 1)/w(i + 1)) ; i + 1 is subscript
        ob_right->upper_bound = ob_right->value + ((weight - ob_right->weight) * (table[ob_right->level][2]));
        // creating the tree
        curr->lchild = ob_left;
        curr->rchild = ob_right;
        // assinging null to create a proper tree
        ob_left->lchild = ob_left->rchild = ob_right->lchild = ob_right->rchild = NULL;
        // checking if total weight of selections made is allowed by knapsack capacity
        if (ob_left->weight < weight)
        {
            hpush(queue, ob_left);
        }
        if (ob_right->weight < weight)
        {
            hpush(queue, ob_right);
        }
    }
    return NULL;
}
// finding ancestors of goal
int setfind(tl node, tl goal, int *visit)
{
    if (!node)
    {
        return -1;
    }
    if (node == goal)
    {
        return 1;
    }
    if (setfind(node->lchild, goal, visit) == 1)
    {
        visit[node->level + 1] = 1;
        return 1;
    }
    if (setfind(node->rchild, goal, visit) == 1)
    {
        return 1;
    }
    return -1;
}
void main()
{
    printf("enter no. of items\n");
    int n;
    scanf("%d", &n);
    // table for branch and bound
    int **table = (int **)malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i < n; ++i)
    {
        table[i] = (int *)malloc(sizeof(int) * 3);
        printf("enter weight and value of %d ", (i + 1));
        scanf("%d %d", &table[i][0], &table[i][1]);
        // allocating value per unit weight for each item
        table[i][2] = table[i][1] / table[i][0];
    }
    table[n] = (int *)calloc(sizeof(int), 3);
    printf("enter knapsack weight\n");
    int k;
    scanf("%d", &k);
    // creating the first node of branch and bound
    // doing this here so that we can use it for finding ancestors of ans node
    tl root = (tl)malloc(sizeof(struct tree));
    root->level = 0;
    root->upper_bound = k * table[0][2];
    root->value = 0;
    root->weight = 0;
    // ans node
    tl node = knapsack(table, k, n, root);
    int *visit = (int *)calloc(sizeof(int), (n + 1));
    // finding ancestors
    setfind(root, node, visit);
    for (int i = 1; i <= n; ++i)
    {
        if (visit[i] == 1)
        {
            printf("%d ", table[i - 1][0]);
        }
    }
}