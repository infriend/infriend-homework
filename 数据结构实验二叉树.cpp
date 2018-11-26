/*实验内容：二叉树的遍历。
实验目的和要求：理解二叉树的性质，懂得递归和非递归创建二叉树的方法及先序遍历、中序遍历、后序遍历、层次遍历的算法与实现。
（附加题：实现求二叉树深度、叶子数、结点数、交换二叉树中所有结点的左、右子树）。
*/
#include <cstdio>
#include <cstdlib>
#include <stack>

typedef struct bitree
{
    struct bitree *lc;
    struct bitree *rc;
    int data;
} bitree;

typedef struct qnode
{
    bitree data;
    struct qnode *next;
} qnode;
typedef struct
{
    qnode *front;
    qnode *rear;
} queue;

void *initque(queue *q)
{
    q->front = q->rear = (qnode*) malloc(sizeof(qnode));
    q->front->next = NULL;//head node
}

void enqueue(queue *q, bitree *e)
{
    qnode *p;
    p = (qnode*) malloc(sizeof(qnode));
    p->data = *e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}

int emptyque(queue *q)
{
    if (q->rear == q->front)
    {
        return 0;
    }
    else return 1;
}

bitree dequeue(queue *q)
{
    qnode *p;
    bitree e;
    p = q->front->next;
    e = p->data;
    q->front->next = p->next;
    if (q->rear == p) q->rear = q->front;
    free(p);

    return e;
}

bitree *inittree01()
{
    int n;
    bitree *t;
    scanf("%d", &n);
    if (n) t = NULL;
    else
    {
        t = (bitree*) malloc(sizeof(bitree));
        t->data = n;
        t->lc = inittree01();
        t->rc = inittree01();
    }

    return t;
}

void preordtra(bitree *t)
{
    static int n = 0;
    if (t==NULL) ;
    else
    {
        if (n==6)
        {
            printf("\n");
            n = 0;
        }
        printf("%4d", t->data);
        ++n;
        preordtra(t->lc);
        preordtra(t->rc);
    }
}

void midordtra(bitree *t)
{
    static int n = 0;
    if (t==NULL) ;
    else
    {
        if (n==6)
        {
            printf("\n");
            n = 0;
        }
        midordtra(t->lc);
        printf("%4d", t->data);
        ++n;
        midordtra(t->rc);
    }
}

void posordtra(bitree *t)
{
    static int n = 0;
    if (t==NULL) ;
    else
    {
        if (n==6)
        {
            printf("\n");
            n = 0;
        }
        posordtra(t->lc);
        posordtra(t->rc);
        printf("%4d", t->data);
        ++n;
    }
}

void lvtra(bitree *t)
{
    queue q;
    bitree e;
    initque(&q);
    enqueue(&q, t);
    while (!emptyque(&q))
    {
        e = dequeue(&q);

        if (t->lc!=NULL) enqueue(&q, t->lc);
        if (t->rc!=NULL) enqueue(&q, t->rc);
        printf("%4d", e.data);
    }
}

int main()
{

}
