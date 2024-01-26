#include <stdio.h>
#include <stdlib.h>
typedef struct tree *tl;
struct tree
{
    int val;
    tl lchild, rchild;
};
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
int balance_factor(tl root)
{
    return height(root->lchild) - height(root->rchild);
}
tl leftrotate(tl root)
{
    tl right = root->rchild;
    tl right_left = right->lchild;
    right->lchild = root;
    root->rchild = right_left;
    return right;
}
tl rightrotate(tl root)
{
    tl left = root->lchild;
    tl left_right = left->rchild;
    left->rchild = root;
    root->lchild = left_right;
    return left;
}
tl avl(tl root, int key)
{
    tl temp = root;
    if (!root)
    {
        tl ob = (tl)malloc(sizeof(struct tree));
        ob->lchild = ob->rchild = NULL;
        ob->val = key;
        return ob;
    }
    else if (root->val > key)
    {
        root->lchild = avl(root->lchild, key);
    }
    else if (root->val < key)
    {
        root->rchild = avl(root->rchild, key);
    }
    else
    {
        return root;
    }

    int balance_root = balance_factor(root);
    if (balance_root > 1 && root->lchild->val > key)
    {
        return rightrotate(root);
    }
    if (balance_root > 1 && root->lchild->val < key)
    {
        root->lchild = leftrotate(root->lchild);
        return rightrotate(root);
    }
    if (balance_root < -1 && root->rchild->val < key)
    {
        return leftrotate(root);
    }
    if (balance_root < -1 && root->rchild->val > key)
    {
        root->rchild = rightrotate(root->rchild);
        return leftrotate(root);
    }
    return root;
}
void preorder(tl root)
{
    if (!root)
    {
        return;
    }
    printf("%d ", root->val);
    preorder(root->lchild);
    preorder(root->rchild);
}
void main()
{
    tl root = NULL;
    root = avl(root, 10);
    root = avl(root, 20);
    root = avl(root, 30);
    root = avl(root, 40);
    root = avl(root, 50);
    root = avl(root, 25);
    preorder(root);
}