#include <stdio.h>
#include <stdlib.h>
typedef struct tree *tl;
struct tree
{
    int val;
    tl lchild, rchild;
};
typedef struct stack *sl;
struct stack
{
    tl val;
    sl link;
};
void push(sl stack, tl val)
{
    sl ob = (sl)malloc(sizeof(struct stack));
    ob->val = val;
    ob->link = stack->link;
    stack->link = ob;
    return;
}
tl pop(sl stack)
{
    if (stack == NULL)
    {
        return NULL;
    }
    tl ans = stack->link->val;
    stack->link = stack->link->link;
    return ans;
}
tl create()
{
    printf("enter val or -1 to escape\n");
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
sl inorder(tl root, sl stack)
{
    if (root == NULL)
    {
        return stack;
    }
    stack = inorder(root->lchild, stack);
    push(stack, root);
    stack = inorder(root->rchild, stack);
    return stack;
}
tl binaryToList(tl root)
{
    sl stack = (sl)malloc(sizeof(struct stack));
    stack = inorder(root, stack);
    tl top1 = pop(stack);
    top1->rchild = NULL;
    while (stack->link != NULL)
    {
        tl top2 = pop(stack);
        top1->lchild = top2;
        top2->rchild = top1;
        top1 = top2;
    }
    top1->lchild = NULL;
    return top1;
}
tl make(int val)
{
    tl ob = (tl)malloc(sizeof(struct stack));
    ob->val = val;
    ob->lchild = ob->rchild = NULL;
    return ob;
}
void main()
{
    printf("tree creation\n");
    tl root = create();
    printf("tree conversion\n");
    tl head = binaryToList(root);
    if (head->rchild == NULL)
    {
        printf("%d ", head->val);
        return;
    }
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->rchild;
    }
}