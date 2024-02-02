#include <stdio.h>
#include <stdlib.h>
typedef struct tree *tl;
struct tree
{
    char val;
    float fre;
    tl lchild, rchild;
};
typedef struct stack *sl;
struct stack
{
    tl val;
    sl link;
};
// adds nodes to stack in ascending order
void push(sl stack, tl val)
{
    sl ob = (sl)malloc(sizeof(struct stack));
    ob->val = val;
    // if stack empty
    if (!stack->link)
    {
        stack->link = ob;
        return;
    }
    sl x = stack;
    for (; x->link != NULL; x = x->link)
    {
        if (ob->val->fre < x->link->val->fre)
        {
            ob->link = x->link;
            x->link = ob;
            return;
        }
    }
    // the ob frequency is largest
    x->link = ob;
    ob->link = NULL;
    return;
}
tl pop(sl stack)
{
    tl ans = NULL;
    if (stack->link)
    {
        ans = stack->link->val;
        stack->link = stack->link->link;
    }
    return ans;
}
tl huffman(sl stack)
{
    // stack only has one element
    if (stack->link->link == NULL)
    {
        return stack->link->val;
    }
    // stack has more than one element
    // if second pop is null then first pop is ans
    for (;;)
    {
        tl curr1 = pop(stack);
        tl curr2 = pop(stack);
        if (!curr2)
        {
            return curr1;
        }
        tl ob = (tl)malloc(sizeof(struct tree));
        ob->fre = curr1->fre + curr2->fre;
        ob->lchild = curr1->fre >= curr2->fre ? curr2 : curr1;
        ob->rchild = curr1->fre >= curr2->fre ? curr1 : curr2;
        push(stack, ob);
    }
}
void inorder(tl node)
{
    if (!node)
    {
        return;
    }
    inorder(node->lchild);
    printf("%f ", node->fre);
    inorder(node->rchild);
}
void main()
{
    printf("enter no. of letters in alphabet\n");
    int n;
    scanf("%d", &n);
    printf("enter the alphabet\n");
    char al[n];
    scanf("%s", al);
    tl *list = (tl *)malloc(sizeof(tl) * n);
    // creating tree nodes for alphabets
    for (int i = 0; i < n; ++i)
    {
        list[i] = (tl)malloc(sizeof(struct tree));
        list[i]->val = al[i];
        list[i]->fre = 0.0;
    }
    printf("enter string and its length\n");
    char str[20];
    int l;
    scanf("%s %d", str, &l);
    // counting the frequency of each alphabet in the string
    for (int i = 0; i < l; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (al[j] == str[i])
            {
                list[j]->fre += 1;
            }
        }
    }
    // allocating the frequency
    for (int i = 0; i < n; ++i)
    {
        list[i]->fre /= l;
    }
    sl stack = (sl)malloc(sizeof(struct stack));
    stack->link = NULL;
    for (int i = 0; i < n; ++i)
    {
        push(stack, list[i]);
    }
    tl node = huffman(stack);
    inorder(node);
}
