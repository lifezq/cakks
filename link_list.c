#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;

/*
 * Storage struct
 */
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

/*
 * Initialize LinkList
 */
void InitList(LinkList *L)
{
    *L = (LinkList) malloc(sizeof(LNode));
    if (!L)
    {
        exit(OVERFLOW);
    }

    (*L)->next = NULL;
}

/*
 * Destroy list
 */
void DestroyList(LinkList *L)
{
    LinkList temp;
    while(*L)
    {
        temp = (*L)->next;
        free(*L);
        *L = temp;
    }
}

/**
 * Clear list
 */
void ClearList(LinkList L)
{
    LinkList p = L->next;
    L->next = NULL;
    DestroyList(&p);
}

/**
 * Isempty
 */
Status isEmpty(LinkList L)
{
    if(L->next)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

/**
 * Get Length
 */
int GetLength(LinkList L)
{
    int i = 0;
    LinkList p = L->next;
    while(p)
    {
        i++;
        p = p->next;
    }
    return i;
}

/**
 * Get Item
 */
 int GetItem(LinkList L, int i, ElemType *e)
{
    int j = 1;
    LinkList p = L->next;
    while(p && j<i)
    {
        j++;
        p = p->next;
    }

    if(!p || j>i)
    {
        return ERROR;
    }

    *e = p->data;
    return OK;
}

/**
 * Compare
 */
Status compare(ElemType e1,ElemType e2)
{
    if(e1 == e2)
    {
        return 0;
    }
    else if(e1 < e2)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

/**
 * Find Item
 */
int FindItem(LinkList L, ElemType e , Status(*compare)(ElemType,ElemType))
{
    int i = 0;
    LinkList p = L->next;
    while(p)
    {
        i++;
        if(!compare(p->data,e))
        {
            return i;
        }
        p = p->next;
    }

    return 0;
}

/**
 * Previous Item
 */
Status PreItem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
    LinkList q,p = L->next;
    while(p->next)
    {
        q = p->next;
        if(q->data == cur_e)
        {
            *pre_e = p->data;
            return OK;
        }

        p = q;
    }

    return ERROR;
}

/*
 * Next Item
 */
Status NextItem(LinkList L,ElemType cur_e,ElemType *next_e)
{
   LinkList q,p = L;
   while(p->next)
   {
       if(p->data == cur_e){
           *next_e = p->next->data;
           return OK;
       }

       p = p->next;
   }

   return ERROR;
}

/**
 * Insert Item
 */
Status InsertItem(LinkList L, int i, ElemType e)
{
    int j = 0;
    LinkList s,p = L;
    while(p && j < i - 1)
    {
        j++;
        p = p->next;
    }

    if(!p || j > i-1)
    {
        return ERROR;
    }

    s = (LinkList) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

/**
 * Delete Item
 */
Status DeleteItem(LinkList L, int i, ElemType *e)
{
    int j = 0;
    LinkList q,p = L;
    while(p->next && j < i - 1)
    {
        j++;
        p = p->next;
    }

    if (!p->next || j > i - 1)
    {
        return ERROR;
    }

    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

/**
 * Visit Item
 */
void visit(ElemType e)
{
    printf("%d ", e);
}

/**
 * Traverse List
 */
void TraverseList(LinkList L, void(*visit)(ElemType))
{
    LinkList p = L->next;
    while(p)
    {
        visit(p->data);
        p = p->next;
    }
}

int main()
{
    LinkList L;
    InitList(&L);
    ElemType e;
    int i;
    if(L)
    {
        printf("Init Success\n");
    }

    if(isEmpty(L))
    {
        printf("List is empty\n");
    }

    for(i = 0; i <10; i++)
    {
        InsertItem(L, i+1, i);
    }

    if(GetItem(L, 1, &e))
    {
        printf("The first element is %d\n", e);
    }

    printf("Length is %d\n", GetLength(L));

    printf("The 5 at %d\n", FindItem(L, 5, *compare));

    PreItem(L, 6, &e);
    printf("The 6'th previous element is %d\n",e);

    NextItem(L, 6, &e);
    printf("The 6'th next element is %d\n",e);

    DeleteItem(L, 1, &e);
    printf("Delete first element is %d\n",e);

    printf("List:");
        TraverseList(L, visit);

    DestroyList(&L);
    if(!L)
    {
        printf("\nDestroy Success\n");
    }
}
