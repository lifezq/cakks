#include <stdio.h>
#include <stdlib.h>
#include "./sq_common.h"

/*
 * init sqlist
 */
Status InitList(Sqlist *L)
{
    L->elem = (Elemtype *)malloc(INIT_SIZE *sizeof(Elemtype));
    if(!L->elem)
    {
        return ERROR;
    }
    L->length = 0;
    L->size = INIT_SIZE;
    return OK;
}

/*
 * destroy
 */
Status DestroyList(Sqlist *L)
{
    free(L->elem);
    L->length = 0;
    L->size = 0;

    return OK;
}

/*
 * clear sqlist
 */
Status ClearList(Sqlist *L)
{
    L->length = 0;
    return OK;
}

/*
 * is empty list
 */
Status isEmpty(const Sqlist L)
{
    if (0 == L.length)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*
 * get list length
 */
Status getLength(const Sqlist L)
{
    return L.length;
}

/*
 * get item
 */
Status GetItem(const Sqlist L, int i, Elemtype *e)
{
    if(i <1 || i > L.length)
    {
        return ERROR;
    }

    *e = L.elem[i-1];
    return OK;
}

/*
 * compare items
 */
Status compare(Elemtype e1, Elemtype e2)
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

/*
 * find item
 */
Status FindElem(const Sqlist L, Elemtype e, Status (*compare)(Elemtype, Elemtype))
{
    int i;
    for(i = 0; i < L.length; i++)
    {
        if(!(*compare)(L.elem[i], e))
        {
            return i + 1;
        }
    }

    if(i >= L.length)
    {
        return ERROR;
    }
}

/*
 * find pre item 
 */
Status PreElem(const Sqlist L, Elemtype cur_e, Elemtype *pre_e)
{
    int i;
    for ( i = 0; i < L.length; i++)
    {
        if( cur_e == L.elem[i])
        {
            if(i != 0)
            {
                *pre_e = L.elem[i-1];
                return OK;
            }
            else
            {
                return ERROR;
            }
        }
    }

    if(i >= L.length)
    {
        return ERROR;
    }
}

/*
 * find next item
 */
Status NextItem(const Sqlist L, Elemtype cur_e, Elemtype *next_e)
{
    int i;
    for(i=0; i < L.length; i++)
    {
        if(cur_e == L.elem[i])
        {
            if(i < L.length)
            {
                *next_e = L.elem[i+1];
                return OK;
            }
            else
            {
                return ERROR;
            }
        }
    }

    if(i>=L.length)
    {
        return ERROR;
    }
}

/*
 * insert item
 */
Status InsertItem(Sqlist *L, int i, Elemtype e)
{
   Elemtype *new;
   if(i < 1 || i > L->length + 1)
   {
       return ERROR;
   }

   if(L->length >= L->size)
   {
        new = (Elemtype*)realloc(L->elem, (L->size + INCREMENT_SIZE) * sizeof(Elemtype));
        if(!new)
        {
            return ERROR;
        }
        L->elem = new;
        L->size += INCREMENT_SIZE;
   }

   Elemtype *p = &L->elem[i-1];
   Elemtype *q = &L->elem[L->length - 1];
   for (; q >= p; q--)
   {
       *(q + 1) = *q;
   }
   *p = e;
   ++L->length;
   return OK;
}

/*
 * delete item
 */
Status DeleteItem(Sqlist *L, int i, Elemtype *e)
{
    if(i < 1 || i > L->length)
    {
        return ERROR;
    }
    Elemtype *p = &L->elem[i-1];
    *e = *p;
    for (; p < &L->elem[L->length]; p++)
    {
        *(p) = *(p+1);
    }

    --L->length;
    return OK;
}

/*
 * access item
 */
void visit(Elemtype e)
{
    printf("%d ", e);
}

/*
 * traverse list
 */
Status TraverseList(const Sqlist L, void(*visit)(Elemtype))
{
    int i;
    for(i = 0; i < L.length; i++)
    {
        visit(L.elem[i]);
    }

    return OK;
}

/*
 * main func
 */
int main()
{
    Sqlist L;
    if(InitList(&L))
    {
        Elemtype e;
        printf("init_success\n");
        int i;
        for(i=0;i<10;i++)
        {
            InsertItem(&L, i + 1, i);
        }
        printf("length is %d\n", getLength(L));
        if(GetItem(L, 1 , &e))
        {
            printf("The first element is %d\n", e);
        }
        else
        {
            printf("Element is not exists\n");
        }
        if(isEmpty(L))
        {
            printf("List is empty\n");
        }
        else
        {
            printf("List is not empty\n");
        }

        printf("The 5 at %d\n", FindElem(L, 5, *compare));
        PreElem(L, 6, &e);
        printf("The 6's previous element is %d\n", e);
        NextItem(L, 6, &e);
        printf("The 6's next element is %d\n", e);
        DeleteItem(&L, 1, &e);
        printf("Delete first element is %d\n", e);
        printf("List:");
        TraverseList(L, visit);
        if(DestroyList(&L))
        {
            printf("\nDestroy_success\n");
        }
    }
}
