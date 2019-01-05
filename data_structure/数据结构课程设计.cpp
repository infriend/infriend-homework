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
5．输出二叉排序树T中指定结点的平衡因子
6．写出课程设计报告
【测试数据】
分别对选定两组测试数据进行测试，验证程序的正确性。
*/

#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

typedef struct bitree
{
    bitree *lc, *rc;
    int data;
} btnode, *bst;

int searchBST(bst tree, int e, bst &f, bst &p)//引用变量p
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
    static int n = 0;
    if (tree==NULL) ;
    else
    {
        if (n==6)
        {
            printf("\n");
            n = 0;
        }
        inctra(tree->lc);
        printf("%4d", tree->data);
        ++n;
        inctra(tree->rc);
    }
}

void dectra(bst tree)
{
    static int n = 0;
    if (tree==NULL) ;
    else
    {
        if (n==6)
        {
            printf("\n");
            n = 0;
        }
        dectra(tree->rc);
        printf("%4d", tree->data);
        ++n;
        dectra(tree->lc);
    }
}

int lvcount(bst t)
{
    queue<bst> q1;
    vector<int> v1;
    int n = 1, sym = 0, res = 0, num = 0;

    q1.push(t);
    while (!q1.empty())
    {
        if (sym == 0)
        {
            v1.push_back(n);
            sym = v1.back();
            n = 0;
        }
        if (q1.front()->lc != NULL)
        {
            q1.push(q1.front()->lc);
            n++;
        }
        if (q1.front()->rc != NULL)
        {
            q1.push(q1.front()->rc);
            n++;
        }
        q1.pop();
        sym--;
    }
    v1.push_back(n);
    n = v1.size();
    for (int i=0; i<n; i++)
    {
        res += v1[i] * (i+1);
        num += v1[i];
    }

    return res/num;
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
                    s->data = p->data;
                    if (q != p) q->rc = s->lc;
                    else q->lc = s->lc;
                    free(s);
                }
            }
        }

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
                    p = p->lc;
                    while (s->rc)
                    {
                        q = s;
                        s = s->rc;
                    }
                    s->data = p->data;
                    if (q != p) q->rc = s->lc;
                    else q->lc = s->lc;
                    free(s);
                }
            }
        }
    }
    return tree;
}
/*
若为叶子节点，直接删，注意改parent的child为NULL
*/
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
    int a[10] = {5,7,9,8,6,4,1,3,2,10};
    bst tree = NULL,f = NULL,p = NULL;
    for (int i=0; i<10; ++i)
    {
        insertBST(tree, a[i]);
    }
    searchBST(tree, 3, f, p);
    inctra(tree);
    printf("\n");
    dectra(tree);
    printf("\nbf of %d is %d", 1, bfcount(tree, 1));

    return 0;
}
