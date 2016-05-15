#include <stdio.h>
#include <stdlib.h>
#include "./sq_common.h"

/*
 * Init Stack
 */
Status InitStack(SqStack *S)
{
    S->base = (SElemType*) malloc(INIT_SIZE*sizeof(SElemType));
    if(!S->base)
    {
        exit(OVERFLOW);
    }

    S->top = S->base;
    S->size = INIT_SIZE;
    return OK;
}

/**
 * Destroy Stack
 */
Status DestroyStack(SqStack *S)
{
    free(S->base);
    S->base = NULL;
    S->top = NULL;
    S->size = 0;
    return OK;
}

/**
 * Clear Stack
 */
Status ClearStack(SqStack *S)
{
    S->top = S->base;
    return OK;
}

/**
 * Is Empty
 */
Status IsEmpty(SqStack S)
{
    if(S.top == S.base)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/**
 * Get Length
 */
int GetLength(SqStack S)
{
    return (S.top - S.base)/sizeof(SElemType);
}


/* *
 * Get Top
 */
Status GetTop(SqStack S, SElemType *e)
{
    if(S.top > S.base)
    {
        *e = *(S.top - sizeof(SElemType));
        return OK;
    }
    else
    {
        return ERROR;
    }
}

/**
 * Push
 */
Status Push(SqStack *S, SElemType e)
{
    if((S->top - S->base)/sizeof(SElemType)>=S->size)
    {
        S->base = (SElemType*)realloc(S->base, (S->size + INCREMENT_SIZE)*sizeof(SElemType));
        if(!S->base )
        {
            exit(OVERFLOW);
        }

        S->top = S->base+S->size*sizeof(SElemType);
        S->size += INCREMENT_SIZE;
    }

    *S->top = e;
    S->top += sizeof(SElemType);
    return OK;
}

/**
 * Pop
 */
Status Pop(SqStack *S, SElemType *e)
{
    if(S->top == S->base)
    {
        return ERROR;
    }

    S->top -= sizeof(SElemType);
    *e = *S->top;
    return OK;
}

/**
 * Visit
 */
void visit(SElemType e)
{
    printf("%d ",e);
}

/**
 * Traverse Stack
 */
Status TraverseStack(SqStack S, void(*visit)(SElemType))
{
    while(S.top > S.base)
    {
        visit(*S.base);
        S.base += sizeof(SElemType);
    }

    return OK;
}

int main()
{
   SqStack S;
   if(InitStack(&S))
   {
       SElemType e;
       int i;

       printf("Init Success\n");

       if(IsEmpty(S))
       {
           printf("Stack is empty\n");
       }

       for(i = 0; i<10; i++)
       {
           Push(&S, i);
       }


       GetTop(S, &e);
       printf("The first element is %d\n",e);

       printf("Length is %d\n", GetLength(S));

       Pop(&S, &e);
       printf("Pop element is %d\n",e);

       TraverseStack(S, *visit);

       if(DestroyStack(&S))
       {
           printf("\nDestroy Stack Success\n");
       }
   }
}
