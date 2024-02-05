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
int common(tl root, int v1, int v2)
{
    if (!root)
    {
        return 0;
    }
    if (root->val == v1 || root->val == v2)
    {
        int a = common(root->lchild, v1, v2);
        int b = common(root->rchild, v1, v2);
        if (a == 1 || b == 1){
            printf("%d", root->val);
            return -1;
        }
        return 1;
    }
    int a = common(root->lchild, v1, v2);
    int b = common(root->rchild, v1, v2);
    if (a == 1 && b == 1)
    {
        printf("%d\n", root->val);
        return -1;
    }
    if (a == 1 || b == 1)
    {
        return 1;
    }
    if (a == -1 || b == -1)
    {
        return -1;
    }
    return 0;
}
void main()
{
    tl root = create();
    printf("enter val of nodes\n");
    int v1, v2;
    scanf("%d %d", &v1, &v2);
    int a = common(root, v1, v2);
    if (a == 0)
    {
        printf("error");
    }
}