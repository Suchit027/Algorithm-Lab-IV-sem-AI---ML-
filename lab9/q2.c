#include <stdio.h>
#include <stdlib.h>
typedef struct hash *hl;
struct hash
{
    int val;
    hl link;
};
hl *create(int size)
{
    hl *table = (hl *)malloc(sizeof(struct hash) * size);
    for (int i = 0; i < size; ++i)
    {
        table[i] = (hl)malloc(sizeof(struct hash));
    }
    return table;
}
void insertion(hl *table, int size, int ele)
{
    int index = ele % size;
    hl temp = table[index];
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    hl ob = (hl)malloc(sizeof(struct hash));
    ob->val = ele;
    temp->link = ob;
    ob->link = NULL;
    return;
}
void deletion(hl *table, int size, int ele)
{
    int index = ele % size;
    hl temp = table[index];
    while (temp->link != NULL && temp->link->val != ele)
    {
        temp = temp->link;
    }
    if (temp->link != NULL)
    {
        temp->link = temp->link->link;
    }
    return;
}
int search(hl *table, int size, int ele)
{
    int index = ele % size;
    hl temp = table[index];
    temp = temp->link;
    while (temp->link != NULL)
    {
        if (temp->val == ele)
        {
            return 1;
        }
        temp = temp->link;
    }
    return 0;
}
void main()
{
    hl *table = create(10);
    for (int i = 1; i <= 50; ++i)
    {
        insertion(table, 10, i);
    }
    printf("%d ", search(table, 10, 51));
}