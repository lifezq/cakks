#ifndef _SQ_COMMON_H
#define _SQ_COMMON_H
#endif

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INIT_SIZE 10
#define INCREMENT_SIZE 5
#define OVERFLOW -2

// sqlist common def
typedef int Status;
typedef int Elemtype;

typedef struct
{
    Elemtype *elem;
    int length;
    int size;
}Sqlist;

// link_list common def
typedef int ElemType;
typedef int Status;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

// sqstack common def
typedef int SElemType;

typedef struct
{
    SElemType *base;
    SElemType *top;
    int size;
}SqStack;

// qnode common def
typedef int QElemtype;

typedef struct QNode 
{
    QElemtype data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct 
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;


/*-----------------------------------------------------------------------------
 *  BiTreeNode common def
 *-----------------------------------------------------------------------------*/
typedef int TElemType;

struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
};				/* ----------  end of struct BiTNode  ---------- */

typedef struct BiTNode BiTNode, *BiTree;

                                                
/*-----------------------------------------------------------------------------
 *  EdgeNode common def  
 *-----------------------------------------------------------------------------*/

#define	MAX_NUM 20			/*  */

typedef char VexType;

struct EdgeNode {
    int adjvex;
    struct EdgeNode *next;
};				/* ----------  end of struct EdgeNode  ---------- */

typedef struct EdgeNode EdgeNode,*EdgeLink;

struct VexNode {
    VexType data;
    EdgeNode *firstEdge;
};				/* ----------  end of struct VexNode  ---------- */

typedef struct VexNode VexNode, AdjList[MAX_NUM];


struct AlGraph {
    AdjList adjList;
    int vexNum,edgeNum;
};				/* ----------  end of struct AlGraph  ---------- */

typedef struct AlGraph AlGraph;







