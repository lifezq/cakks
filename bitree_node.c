#include <stdio.h>
#include <stdlib.h>
#include "sq_common.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  CreateBiTree
 *  Description:  
 * =====================================================================================
 */
    Status
CreateBiTree ( BiTree *T )
{
    TElemType e;
    scanf("%d", &e);

    if (e == 0)
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTree) malloc(sizeof(BiTNode));
        if (!T)
        {
            exit(OVERFLOW);
        }
        (*T)->data = e;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);

    }
    return OK;
}		/* -----  end of function CreateBiTree  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  visit
 *  Description:  
 * =====================================================================================
 */
    void
visit ( TElemType e )
{
    printf("%d \n", e);
}		/* -----  end of function visit  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  PreOrderTraverse
 *  Description:  
 * =====================================================================================
 */
    Status
PreOrderTraverse ( BiTree T, void (*visit )(TElemType))
{
    if (T)
    {
        visit(T->data);
        PreOrderTraverse(T->lchild, visit);
        PreOrderTraverse(T->rchild, visit);
    }
    return OK;
}		/* -----  end of function PreOrderTraverse  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  InOrderTraverse
 *  Description:  
 * =====================================================================================
 */
    Status
InOrderTraverse ( BiTree T, void (*visit)(TElemType) )
{
    if(T)
    {
        InOrderTraverse(T->lchild, visit);
        visit(T->data);
        InOrderTraverse(T->rchild, visit);
    }
    return OK;
}		/* -----  end of function InOrderTraverse  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  PostOrderTraverse
 *  Description:  
 * =====================================================================================
 */
    Status
PostOrderTraverse ( BiTree T, void (*visit)(TElemType) )
{
    if(T)
    {
        PostOrderTraverse(T->lchild, visit);
        PostOrderTraverse(T->lchild, visit);
        visit(T->data);
    }
    return OK;
}		/* -----  end of function PostOrderTraverse  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( )
{
    BiTree T;
    printf("Build Tree, input 0 to be an empty tree:\n");
    CreateBiTree(&T);
    printf("\nPrevious to traverse:\n");
    PreOrderTraverse(T, *visit);
    printf("\nIn order to traverse:\n");
    InOrderTraverse(T, *visit);
    printf("\nPost to traverse:\n");
    PostOrderTraverse(T, *visit);
    printf("\n");
    return OK;
}		/* -----  end of function main  ----- */
