/*
【课程设计题目十二】
二叉排序树
【问题描述】
输入一个数列创建一棵二叉排序树T，对二叉排序树T按递增、递减两种序列输出，计算该
二叉排序树T的平均查找长度并输出，在二叉排序树T上删除指定结点，
并输出二叉排序树T中指定结点的平衡因子。
【基本要求】
1．输入一个数列L，生成一棵二叉排序树T　finish
2．对二叉排序树T作递增、递减输出 finish
3. 计算二叉排序树T的平均查找长度，输出结果 finish
4．在二叉排序树T上删除指定结点 finish
5．输出二叉排序树T中指定结点的平衡因子 finish
6．写出课程设计报告
【测试数据】
分别对选定两组测试数据进行测试，验证程序的正确性。
*/

#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef struct bitree
{
    bitree *lc, *rc;
    int data;
} btnode, *bst;

typedef struct qnode
{
    bitree data;
    struct qnode *next;
} qnode;
typedef struct myqueue
{
    qnode *front,*rear;
} myqueue;

void initque(myqueue *q)
{
    q->front = q->rear = (qnode*) malloc(sizeof(qnode));
    q->front->next = NULL;//head node
}

void enqueue(myqueue *q, bst e)
{
    qnode *p;
    p = (qnode*) malloc(sizeof(qnode));
    p->data = *e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}

int emptyque(myqueue *q)
{
    if (q->rear == q->front)
    {
        return 1;
    }
    else return 0;
}

bitree dequeue(myqueue *q)
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

int searchBST(bst tree, int e, bst &f, bst &p)
{

    if (!tree)
    {
        p = f;
        return 0;
    }
    else
    {
        if (e == tree->data)
        {
            p = tree;
            return 1;
        }
        else
        {
            if (e > tree->data)
            {
                return searchBST(tree->rc, e, f = tree, p);
            }
            else
            {
                return searchBST(tree->lc, e, f = tree, p);
            }
        }
    }
}

void insertBST(bst &tree, int e)
{
    bst p = NULL, f = NULL;
    if (!searchBST(tree, e, f, p))
    {
        bst s = (bst) malloc(sizeof(btnode));
        s->data = e;
        s->lc = s->rc = NULL;
        if (!p) tree = s;
        else
        {
            if (e > p->data) p->rc = s;
            else p->lc = s;
        }
    }
}

void inctra(bst tree)
{
    if (tree==NULL) ;
    else
    {
        inctra(tree->lc);
        printf("%4d", tree->data);
        inctra(tree->rc);
    }
}

void dectra(bst tree)
{
    if (tree==NULL) ;
    else
    {
        dectra(tree->rc);
        printf("%4d", tree->data);
        dectra(tree->lc);
    }
}

double slcount(bst t)
{
    btnode p;
    vector<int> v1;
    myqueue q;
    initque(&q);
    int n = 1, sym = 0, res = 0, num = 0;

    enqueue(&q, t);
    while (!emptyque(&q))
    {
        if (sym == 0)
        {
            v1.push_back(n);
            sym = v1.back();
            n = 0;
        }
        p = dequeue(&q);
        if (p.lc != NULL)
        {
            enqueue(&q, p.lc);
            n++;
        }
        if (p.rc != NULL)
        {
            enqueue(&q, p.rc);
            n++;
        }
        sym--;
    }
    v1.push_back(n);
    n = v1.size();
    for (int i=0; i<n; i++)
    {
        res += v1[i] * (i+1);
        num += v1[i];
    }

    return (double) res/(double) num;
}

bst delnode(bst tree, int e)
{
    bst p, f = NULL, q, s;
    if (!searchBST(tree, e, f, p))
    {
        printf("NOT FOUND\n");
        return tree;
    }
    if (tree == p)
    {
        if ((!p->lc) && (!p->rc))
        {
            free(p);
            tree = NULL;
        }
        else
        {
            if (p->lc && (!p->rc))
            {
                tree = p->lc;
                free(p);
            }
            else
            {
                if (p->rc && (!p->lc))
                {
                    tree = p->rc;
                    free(p);
                }
                else
                {
                    q = p;
                    s = p->lc;
                    while (s->rc)
                    {
                        q = s;
                        s = s->rc;
                    }
                    p->data = s->data;
                    printf("p=%d\n", p->data);
                    if (q != p) q->rc = s->lc;
                    else q->lc = s->lc;
                    free(s);
                }
            }
        }
        tree = p;
    }
    else
    {
        if ((!p->lc) && (!p->rc))
        {

                if (f->lc == p) f->lc = NULL;
                if (f->rc == p) f->rc = NULL;
                free(p);//leaf node
        }
        else
        {
            if (p->lc == NULL && p->rc)
            {
                if (f->lc == p) f->lc = p->rc;
                if (f->rc == p) f->rc = p->rc;
                free(p);
            }
            else
            {
                if (p->rc == NULL && p->lc)
                {
                    if (f->lc == p) f->lc = p->lc;
                    if (f->rc == p) f->rc = p->lc;
                    free(p);
                }//node with only one child
                else
                {
                    q = p;
                    s = p->lc;
                    while (s->rc)
                    {
                        q = s;
                        s = s->rc;
                    }
                    p->data = s->data;
                    if (q != p) q->rc = s->lc;
                    else q->lc = s->lc;
                    free(s);
                }
            }
        }
    }
    return tree;
}

int depthcount(bst t)
{
    int max = 0, ld = 0, rd = 0;
    if (t!=NULL)
    {
        ld = depthcount(t->lc);
        rd = depthcount(t->rc);
        max = ld > rd ? ld : rd;
        return max + 1;
    }
    else
    {
        return 0;
    }
}

int bfcount(bst tree, int e)
{
    bst f, p;
    int bf;
    searchBST(tree, e, f, p);
    bf = depthcount(p->lc) - depthcount(p->rc);

    return bf;
}

int main()
{
    vector<int> v;
    bst tree = NULL,f = tree,p = NULL;
    int a;
    printf("Enter the number list(0 means the end)\n");
    scanf("%d", &a);
    while (a>0)
    {
        v.push_back(a);
        scanf("%d", &a);
    }
    for (int i=0; i<(int) v.size(); ++i)
    {
        insertBST(tree, v[i]);
    }
    printf("Enter the number you'd like to search:");
    scanf("%d", &a);
    searchBST(tree, a, f, p);
    if (p == tree) f = p;
    printf("p=%d,f=%d", p->data, f->data);
    printf("\nINC list:\n");
    inctra(tree);
    printf("\n");
    printf("DEC list:\n");
    dectra(tree);
    printf("\nAverage search length: %f", slcount(tree));
    printf("\nEnter the del number:");
    scanf("%d", &a);
    tree = delnode(tree, a);
    inctra(tree);
    printf("\nOutput the balance factor:\n");
    printf("Enter the number:");
    scanf("%d", &a);
    printf("bf of %d is %d\n", a, bfcount(tree, a));

    return 0;
}
