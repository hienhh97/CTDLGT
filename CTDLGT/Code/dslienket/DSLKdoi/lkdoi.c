#include "stdio.h"
#include "stdlib.h"

typedef struct _DNode
{
    int val;
    struct _DNode *prev;
    struct _DNode *next;
} DNode;

DNode *first;
DNode *last;

DNode *makeNode(int v)
{
    DNode *p = (DNode *)malloc(sizeof(DNode));
    if (p == NULL)
    {
        printf("Error\n");
        exit(1);
    }
    p->val = v;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void removeFromDList(DNode *p)
{
    if (p == NULL)
        return;
    if (first == last && p != first)
        return;
    if (first == last && p == first)
    {
        first = NULL;
        last = NULL;
        free(p);
        return;
    }
    if (p == first)
    {
        first = p->next;
        first->prev = NULL;
        free(p);
        return;
    }
    if (p == last)
    {
        last = p->prev;
        last->next = NULL;
        free(p);
        return;
    }

    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
}

void traverseDList(DNode *p)
{
    DNode *tmp = p;
    if (tmp == NULL)
        return;

    while (tmp->prev != NULL)
        tmp = tmp->prev;
    printf("\n");
    while (tmp != NULL)
    {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}

void removeNega(DNode *p)
{
    DNode *tmp = p, *tg;
    if (tmp == NULL)
        return;

    while (tmp->prev != NULL)
        tmp = tmp->prev;

    while (tmp != NULL)
    {
        tg = tmp->next;

        if (tmp->val < 0)
            removeFromDList(tmp);

        tmp = tg;
    }
}

void insertLast(int x)
{
    DNode *tmp = makeNode(x);
    if (first == NULL && last == NULL)
    {
        first = tmp;
        last = tmp;
        return;
    }
    tmp->prev = last;
    last->next = tmp;
    last = tmp;
}

int main()
{
    int i;

    for (i = -10; i < 10; i++)
        insertLast(i);

    removeNega(first);
    traverseDList(first);

    return 1;
}