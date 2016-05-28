#include <stdio.h>
#include <stdlib.h>
#include "sq_common.h"


/*-----------------------------------------------------------------------------
 *  图的遍历
 *-----------------------------------------------------------------------------*/

int visited[MAX_NUM];

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  InitQueue
 *  Description:  
 * =====================================================================================
 */
    Status
InitQueue ( LinkQueue *Q )
{
    Q->front = Q->rear = (QueuePtr) malloc(sizeof(QNode));
    if(!Q->front){
        exit(OVERFLOW);
    }

    Q->front->next = NULL;
    return OK;
}		/* -----  end of function InitQueue  ----- */



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
    return FALSE;
}		/* -----  end of function IsEmpty  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  EnQueue
 *  Description:  
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
 *  Description:  
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
 *         Name:  CreateGraph
 *  Description:  
 * =====================================================================================
 */
    Status
CreateGraph ( AlGraph *G )
{
    int i,j,k;
    EdgeLink e;
    printf("请输入顶点数目和边缘：\n");
    scanf("%d", &G->vexNum);
    scanf("%d", &G->edgeNum);

    getchar();
    printf("请输入各顶点的数据：\n");
    for (i = 0; i < G->vexNum; i++)
    {
        scanf("%c", &G->adjList[i].data);

        if(G->adjList[i].data == '\n')
        {
            i--;
            continue;
        }

        G->adjList[i].firstEdge = NULL;
    }

    printf("请依次输入边(Vi,Vj)的顶点序号:\n");
    for(k = 0; k < G->edgeNum; k++)
    {
        scanf("%d", &i);
        scanf("%d", &j);
        e = (EdgeLink)malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->next = G->adjList[i].firstEdge;
        G->adjList[i].firstEdge = e;
        e = (EdgeLink) malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->next = G->adjList[i].firstEdge;
        G->adjList[i].firstEdge = e;
    }
    return OK;
}		/* -----  end of function CreateGraph  ----- */




/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DFS
 *  Description:  递归从第i个结点深度优先遍历图 
 * =====================================================================================
 */
    Status
DFS ( AlGraph G, int i )
{

    EdgeLink p;
    visited[i] = TRUE;
    printf("%c ", G.adjList[i].data);
    p = G.adjList[i].firstEdge;
    while(p)
    {
        if(!visited[p->adjvex])
        {
            DFS(G, p->adjvex);
        }

        p = p->next;
    }

    return OK;
}		/* -----  end of function DFS  ----- */




/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DFSTraverse
 *  Description:  深度优先遍历
 * =====================================================================================
 */
    Status
DFSTraverse ( AlGraph G )
{
    int i;
    for( i = 0; i < MAX_NUM; i++ )
    {
        visited[i] = FALSE;
    }

    for ( i = 0; i < G.vexNum; i++ )
    {
        if(!visited[i])
        {
            DFS(G, i);
        }
    }
    return OK;
}		/* -----  end of function DFSTraverse  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  BFSTraverse
 *  Description:  广度优先遍历
 * =====================================================================================
 */
    Status
BFSTraverse ( AlGraph G )
{
    int i;
    EdgeLink p;
    LinkQueue Q;
    InitQueue(&Q);
    for( i = 0; i < MAX_NUM; i++ )
    {
        visited[i] = FALSE;
    }

    for ( i = 0; i < G.vexNum; i++ )
    {
        if(!visited[i])
        {
            visited[i] = TRUE;
            printf("%c ", G.adjList[i].data);
            EnQueue(&Q,i);
            while(!IsEmpty(Q))
            {
                DeQueue(&Q, &i);
                p = G.adjList[i].firstEdge;
                while(p)
                {
                    if(!visited[p->adjvex])
                    {
                        visited[p->adjvex] = TRUE;
                        printf("%c ", G.adjList[p->adjvex].data);
                        EnQueue(&Q,p->adjvex);
                    }

                    p = p->next;
                }
            }
        }
    }
    return OK;
}		/* -----  end of function BFSTraverse  ----- */




/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 *  请输入顶点数目和边缘：
 *  5
 *  6
 *  请输入各顶点的数据：
 *  1
 *  2
 *  3
 *  4
 *  5
 *  请依次输入边(Vi,Vj)的顶点序号:
 *  0
 *  1
 *  0
 *  3
 *  1
 *  2
 *  1
 *  4
 *  2
 *  3
 *  2
 *  4
 *  深度优先遍历：1 4 2 5 3 
 *  广度优先遍历：1 4 2 5 3
 * =====================================================================================
 */
    int
main ( )
{
    AlGraph G;
    CreateGraph(&G);
    printf("深度优先遍历：");
    DFSTraverse(G);
    printf("\n广度优先遍历：");
    BFSTraverse(G);
    printf("\n");
}		/* -----  end of function main  ----- */
