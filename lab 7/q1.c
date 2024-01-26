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
int height(tl root)
{
    if (!root)
    {
        return 0;
    }
    int left = height(root->lchild);
    int right = height(root->rchild);
    int h = left >= right ? left : right;
    return h + 1;
}
void balance_factor(tl root)
{
    if (root)
    {
        printf("balance factor of %d = %d\n", root->val, height(root->lchild) - height(root->rchild));
        balance_factor(root->lchild);
        balance_factor(root->rchild);
    }
    return;
}
void main()
{
    tl root = create();
    balance_factor(root);
}