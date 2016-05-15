#include <stdio.h>
#include	<stdlib.h>
#include "sq_common.h"


/**
 * qnode
 */
Status InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q->front)
    {
        exit(OVERFLOW);
    }

    Q->front->next = NULL;
    return OK;
}



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DestroyQueue
 *  Description:  
 * =====================================================================================
 */
    Status
DestroyQueue ( LinkQueue *Q )
{
    while(Q->front)
    {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}		/* -----  end of function DestroyQueue  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ClearQueue
 *  Description:  
 * =====================================================================================
 */
    Status
ClearQueue ( LinkQueue *Q)
{
    DestroyQueue(Q);
    InitQueue(Q);
    return OK;
}		/* -----  end of function ClearQueue  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  IsEmpty
 *  Description:  
 * =====================================================================================
 */
    Status
IsEmpty ( LinkQueue Q )
{
    if(Q.front->next == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}		/* -----  end of function IsEmpty  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  GetLength
 *  Description:  
 * =====================================================================================
 */
    int
GetLength ( LinkQueue Q )
{
    int i = 0;
    QueuePtr p = Q.front;
    while(Q.rear != p)
    {
        i++;
        p = p->next;
    }
    return i;
}		/* -----  end of function GetLength  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  GetHead
 *  Description:  
 * =====================================================================================
 */
    Status
GetHead ( LinkQueue Q, QElemtype *e )
{
    QueuePtr p;
    if(Q.front == Q.rear)
    {
        return ERROR;
    }
    p = Q.front->next;
    *e = p->data;
    return OK;
}		/* -----  end of function GetHead  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  EnQueue
 *  Description:  入队
 * =====================================================================================
 */
    Status
EnQueue ( LinkQueue *Q, QElemtype e )
{
    QueuePtr p = (QueuePtr) malloc(sizeof(QNode));
    if(!p)
    {
        exit(OVERFLOW);
    }

    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}		/* -----  end of function EnQueue  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DeQueue
 *  Description:  出队
 * =====================================================================================
 */
    Status
DeQueue ( LinkQueue *Q, QElemtype *e )
{
    QueuePtr p;
    if(Q->front == Q->rear)
    {
        return ERROR;
    }

    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if(Q->rear == p)
    {
        Q->rear = Q->front;
    }

    free(p);
    return OK;
}		/* -----  end of function DeQueue  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  visit
 *  Description:  
 * =====================================================================================
 */
    void
visit ( QElemtype e )
{
    printf("%d ", e);
}		/* -----  end of function visit  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  TraverseQueue
 *  Description:  
 * =====================================================================================
 */
    Status
TraverseQueue ( LinkQueue Q, void(*visit)(QElemtype) )
{
    QueuePtr p = Q.front->next;
    while(p)
    {
        visit(p->data);
        p = p->next;
    }
    return OK;
}		/* -----  end of function TraverseQueue  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    LinkQueue Q;
    if(InitQueue(&Q))
    {
        QElemtype e;
        int i;

        printf("Init Success\n");

        if(IsEmpty(Q))
        {
            printf("Queue is Empty\n");
        }

        for(i = 0; i < 10; i++)
        {
            EnQueue(&Q, i);
        }

        GetHead(Q, &e);
        printf("The first element is %d\n", e);

        printf("Length is %d\n", GetLength(Q));

        DeQueue(&Q,&e);
        printf("Delete element is %d \n", e);

        TraverseQueue(Q, *visit);

        if(DestroyQueue(&Q))
        {
            printf("\n DestroyQueue Success\n");
        }
    }
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

