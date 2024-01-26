#include <stdio.h>
#include <stdlib.h>
typedef struct tree *tl;
struct tree
{
    int val;
    tl lchild, rchild;
};
tl create()
{
    printf("enter val or -1 to exit\n");
    int v;
    scanf("%d", &v);
    if (v == -1)
    {
        return NULL;
    }
    tl ob = (tl)malloc(sizeof(struct tree));
    ob->val = v;
    printf("for lchild of %d\n", v);
    ob->lchild = create();
    printf("for rchild of %d\n", v);
    ob->rchild = create();
    return ob;
}
int node_count(tl root)
{
    if (root == NULL)
    {
        return 0;
    }
    return node_count(root->lchild) + node_count(root->rchild) + 1;
}
void main()
{
    tl root = create();
    printf("%d", node_count(root));
}