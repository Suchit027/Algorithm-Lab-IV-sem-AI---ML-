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
// passing address of int variable which is to be modified
int diameter(tl root, int *ans)
{
    static int dia = 0;
    if (!root)
    {
        return 0;
    }
    int left = diameter(root->lchild, ans);
    int right = diameter(root->rchild, ans);
    if (left + right > dia)
    {
        dia = left + right;
    }
    *ans = dia;
    if (left >= right)
    {
        return left + 1;
    }
    else
    {
        return right + 1;
    }
}
void main()
{
    tl root = create();
    // note this way of passing addresses to the functions
    int x = 0;
    int *ans = &x;
    diameter(root, ans);
    printf("%d", x);
}